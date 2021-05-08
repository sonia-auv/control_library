/* Copyright 2018-2019 The MathWorks, Inc. */

#ifndef _VOXELGRIDFILTER_
#define _VOXELGRIDFILTER_

#ifndef LIBMWVOXELGRIDFILTER_API
#define LIBMWVOXELGRIDFILTER_API
#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

/* VoxelGridFilter */
EXTERN_C LIBMWVOXELGRIDFILTER_API uint32_T populateIndexVector_single(const float* pData,
                                                                      const uint32_T numPoints,
                                                                      const double voxelSize,
                                                                      const float* pRange,
                                                                      void** ptr2ptrIndexVector,
                                                                      double minVoxelPoints);

EXTERN_C LIBMWVOXELGRIDFILTER_API uint32_T populateIndexVector_double(const double* pData,
                                                                      const uint32_T numPoints,
                                                                      const double voxelSize,
                                                                      const double* pRange,
                                                                      void** ptr2ptrIndexVector,
                                                                      double minVoxelPoints);

EXTERN_C LIBMWVOXELGRIDFILTER_API void voxelGridAlgImpl_single(const float* pData,
                                                               const uint32_T numPoints,
                                                               const unsigned char* pColor,
                                                               const float* pNormal,
                                                               const float* pIntensity,
                                                               const float* pRangeData,
                                                               const float* pRange,
                                                               float* pFilteredData,
                                                               unsigned char* pFilteredColorData,
                                                               float* pFilteredNormalData,
                                                               float* pFilteredIntensityData,
                                                               float* pFilteredRangeData,
                                                               float* pCovData,
                                                               void* ptrIndexVector,
                                                               const uint32_T total,
                                                               const bool needColor,
                                                               const bool needNormal,
                                                               const bool needIntensity,
                                                               const bool needRangeData,
                                                               const bool needCovariance);

EXTERN_C LIBMWVOXELGRIDFILTER_API void voxelGridAlgImpl_double(const double* pData,
                                                               const uint32_T numPoints,
                                                               const unsigned char* pColor,
                                                               const double* pNormal,
                                                               const double* pIntensity,
                                                               const double* pRangeData,
                                                               const double* pRange,
                                                               double* pFilteredData,
                                                               unsigned char* pFilteredColorData,
                                                               double* pFilteredNormalData,
                                                               double* pFilteredIntensityData,
                                                               double* pFilteredRangeData,
                                                               double* pCovData,
                                                               void* ptrIndexVector,
                                                               const uint32_T total,
                                                               const bool needColor,
                                                               const bool needNormal,
                                                               const bool needIntensity,
                                                               const bool needRangeData,
                                                               const bool needCovariance);

EXTERN_C LIBMWVOXELGRIDFILTER_API void voxelGridAlgImpl_single_uint8Intensity(
    const float* pData,
    const uint32_T numPoints,
    const unsigned char* pColor,
    const float* pNormal,
    const unsigned char* pIntensity,
    const float* pRangeData,
    const float* pRange,
    float* pFilteredData,
    unsigned char* pFilteredColorData,
    float* pFilteredNormalData,
    unsigned char* pFilteredIntensityData,
    float* pFilteredRangeData,
    float* pCovData,
    void* ptrIndexVector,
    const uint32_T total,
    const bool needColor,
    const bool needNormal,
    const bool needIntensity,
    const bool needRangeData,
    const bool needCovariance);

EXTERN_C LIBMWVOXELGRIDFILTER_API void voxelGridAlgImpl_double_uint8Intensity(
    const double* pData,
    const uint32_T numPoints,
    const unsigned char* pColor,
    const double* pNormal,
    const unsigned char* pIntensity,
    const double* pRangeData,
    const double* pRange,
    double* pFilteredData,
    unsigned char* pFilteredColorData,
    double* pFilteredNormalData,
    unsigned char* pFilteredIntensityData,
    double* pFilteredRangeData,
    double* pCovData,
    void* ptrIndexVector,
    const uint32_T total,
    const bool needColor,
    const bool needNormal,
    const bool needIntensity,
    const bool needRangeData,
    const bool needCovariance);
#endif
