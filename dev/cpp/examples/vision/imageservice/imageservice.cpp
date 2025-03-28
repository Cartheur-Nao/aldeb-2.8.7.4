#include "imageservice.h"
#include "cameradefs.h"

#include <qi/anyobject.hpp>
#include <qi/log.hpp>

#include <fstream>

qiLogCategory("imageService");


ImageService::ImageService(qi::SessionPtr session)
  :_session(session)
{
  _alvideodevice = session->service("ALVideoDevice");
  _camera = _alvideodevice.call<std::string>("subscribe", "CameraTop", qi::camera::kVGA, qi::camera::kRGBColorSpace, 5);
}

ImageService::~ImageService() {
  try {
    _alvideodevice.call<std::string>("unsubscribe", _camera);
  }
  catch (...) {
    qiLogError() << "Error while unsubscribing";
  }
}

void ImageService::imageProcessing() {
  /** Retrieve a pointer to the image. */
  qi::AnyValue imageData = _alvideodevice.call<qi::AnyValue>("getImageRemote",
                                                              _camera);

  /** Parse the AnyValue **/

  int width = imageData.at(0).to<int>();
  int height = imageData.at(1).to<int>();
  int colorspace = imageData.at(3).to<int>();

  qiLogInfo() << "Got an image: width=" << width << ", height=" <<
          height << ", colorspace=" << colorspace;

  long long timestamp =
      (imageData.at(4).to<long long>() * 1000000LL + imageData.at(5).to<long long>()) * 1000LL;

  qiLogInfo() << "Image timestamp: " << timestamp << " ns";

  float leftAngle = imageData.at(8).to<float>();
  float topAngle = imageData.at(9).to<float>();
  float rightAngle = imageData.at(10).to<float>();
  float bottomAngle = imageData.at(11).to<float>();

  qiLogInfo() << "Image angles: " << leftAngle << ", " << topAngle << ", "
                                  << rightAngle << ", " << bottomAngle;

  /** Get the image buffer **/
  std::pair<char*, size_t> imageBuffer = imageData.at(6).content().asRaw();

  qiLogInfo() << "Image size: " << imageBuffer.second << " bytes";

  /** Do whatever processing you want...    **/
  /** Here, writing raw image into a ppm file **/

  std::ofstream outfile("/tmp/testimage.ppm",std::ofstream::binary);

  outfile << "P6\n"
      << width << " " << height << "\n"
      << "255\n";

  outfile.write(imageBuffer.first, imageBuffer.second);
  outfile.close();

}

QI_REGISTER_MT_OBJECT(ImageService, imageProcessing);


