cmake_minimum_required(VERSION 2.8)
project(imageservice)
find_package(qibuild)

set(_srcs
  main.cpp
  cameradefs.h
  imageservice.h
  imageservice.cpp
)

qi_create_bin(imageservice SRC ${_srcs} DEPENDS QI)
