cmake_minimum_required(VERSION 2.8)
project(alvisualcompass_example)
find_package(qibuild)

qi_create_bin(alvisualcompass_example alvisualcompass_example.cpp)
qi_use_lib(alvisualcompass_example OPENCV3_CORE OPENCV3_HIGHGUI OPENCV3_IMGPROC ALCOMMON ALPROXIES ALVISION)
