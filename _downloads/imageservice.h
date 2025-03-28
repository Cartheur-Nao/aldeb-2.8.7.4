#pragma once

#include <qi/anyobject.hpp>
#include <qi/session.hpp>

#include <string>

class ImageService
{
  public:

    ImageService(qi::SessionPtr session);

    ~ImageService();

    void imageProcessing();

  private:
    qi::SessionPtr  _session;
    qi::AnyObject   _alvideodevice;
    std::string     _camera;
};
