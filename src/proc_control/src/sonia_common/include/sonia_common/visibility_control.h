#ifndef SONIA_COMMON__VISIBILITY_CONTROL_H_
#define SONIA_COMMON__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SONIA_COMMON_EXPORT __attribute__ ((dllexport))
    #define SONIA_COMMON_IMPORT __attribute__ ((dllimport))
  #else
    #define SONIA_COMMON_EXPORT __declspec(dllexport)
    #define SONIA_COMMON_IMPORT __declspec(dllimport)
  #endif
  #ifdef SONIA_COMMON_BUILDING_LIBRARY
    #define SONIA_COMMON_PUBLIC SONIA_COMMON_EXPORT
  #else
    #define SONIA_COMMON_PUBLIC SONIA_COMMON_IMPORT
  #endif
  #define SONIA_COMMON_PUBLIC_TYPE SONIA_COMMON_PUBLIC
  #define SONIA_COMMON_LOCAL
#else
  #define SONIA_COMMON_EXPORT __attribute__ ((visibility("default")))
  #define SONIA_COMMON_IMPORT
  #if __GNUC__ >= 4
    #define SONIA_COMMON_PUBLIC __attribute__ ((visibility("default")))
    #define SONIA_COMMON_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SONIA_COMMON_PUBLIC
    #define SONIA_COMMON_LOCAL
  #endif
  #define SONIA_COMMON_PUBLIC_TYPE
#endif
#endif  // SONIA_COMMON__VISIBILITY_CONTROL_H_
// Generated 16-Jul-2022 14:36:01
// Copyright 2019-2020 The MathWorks, Inc.
