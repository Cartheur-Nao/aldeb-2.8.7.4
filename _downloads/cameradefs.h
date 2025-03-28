#pragma once

/** \file cameradefs.hpp
 *  \brief vision defines
 */

namespace qi
{
  namespace camera
    {
    /**
    *Camera Model ID
    */
    const int kOV5640  = 3;

    /**
    *Camera Index
    */
    const int kTopCamera = 0;
    const int kBottomCamera = 1;

    /**
    *Format of the image
    */
    const int k16VGA = 4; // 2560*1920
    const int k4VGA  = 3; // 1280* 960
    const int kVGA   = 2;  // 640* 480
    const int kQVGA  = 1;  // 320* 240

    /**
    *ColorSpace
    */
    const int kYuvColorSpace = 0;
    const int kyUvColorSpace = 1;
    const int kyuVColorSpace = 2;
    const int kRgbColorSpace = 3;
    const int krGbColorSpace = 4;
    const int krgBColorSpace = 5;
    const int kHsyColorSpace = 6;
    const int khSyColorSpace = 7;
    const int khsYColorSpace = 8;
    const int kYUV422ColorSpace = 9;
    const int kYUVColorSpace = 10;
    const int kRGBColorSpace = 11;
    const int kHSYColorSpace = 12;
    const int kBGRColorSpace = 13;     // for opencv ease of use
    const int kYYCbCrColorSpace = 14;  // for tiff io implementation
    const int kH2RGBColorSpace = 15;   // H from HSY to RGB in fake colors
    const int kHSMixedColorSpace = 16; // HS and (H +S)/2

    /**
     * Parameter Id (used for camera registers configuration)
     */
    const int kCameraBrightnessID             = 0;
    const int kCameraContrastID               = 1;
    const int kCameraSaturationID             = 2;
    const int kCameraHueID                    = 3;
    const int kCameraGainID                   = 6;
    const int kCameraHFlipID                  = 7;
    const int kCameraVFlipID                  = 8;
    const int kCameraAutoExpositionID         = 11;
    const int kCameraAutoWhiteBalanceID       = 12;
    const int kCameraExposureID               = 17;
    const int kCameraSharpnessID              = 24;
    const int kCameraBacklightCompensationID  = 34;
    const int kCameraAverageLuminanceID       = 39;
    const int kCameraAutoFocusID              = 40;
    const int kCameraFocusID                  = 43;

  } //namespace camera
} // namespace qi
