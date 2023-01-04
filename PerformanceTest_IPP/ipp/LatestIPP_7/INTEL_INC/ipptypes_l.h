/*
// Copyright 2015 Intel Corporation All Rights Reserved.
//
//
// This software and the related documents are Intel copyrighted materials, and your use of them is governed by
// the express license under which they were provided to you ('License'). Unless the License provides otherwise,
// you may not use, modify, copy, publish, distribute, disclose or transmit this software or the related
// documents without Intel's prior written permission.
// This software and the related documents are provided as is, with no express or implied warranties, other than
// those that are expressly stated in the License.
//
*/

/*
//              Intel(R) Integrated Performance Primitives (Intel(R) IPP)
//              Derivative Types and Macro Definitions
//
//              The main purpose of this header file is
//              to support compatibility with the legacy
//              domains until their end of life.
//
*/


#if !defined( IPPTYPES_L_H__ )
#define IPPTYPES_L_H__

#if !defined( _OWN_BLDPCS )

#ifdef __cplusplus
extern "C" {
#endif

#if defined (_M_AMD64) || defined (__x86_64__)
  typedef Ipp64s IppSizeL;
#else
  typedef int IppSizeL;
#endif

/*****************************************************************************/
/*                   Below are ippIP domain specific definitions             */
/*****************************************************************************/

typedef struct {
    IppSizeL x;
    IppSizeL y;
    IppSizeL width;
    IppSizeL height;
} IppiRectL;

typedef struct {
    IppSizeL x;
    IppSizeL y;
} IppiPointL;

typedef struct {
    IppSizeL width;
    IppSizeL height;
} IppiSizeL;

typedef struct {
    IppSizeL width;
    IppSizeL height;
    IppSizeL depth;
} IpprVolumeL;

typedef struct {
    IppSizeL x;
    IppSizeL y;
    IppSizeL z;
} IpprPointL;

typedef enum _IpprBorderType {
    ipprBorderRepl        = ippBorderRepl,
    ipprBorderConst       = ippBorderConst,

    /* Flags to use source image memory pixels from outside of the border in particular directions */
    ipprBorderInMemTop     =  0x0010,
    ipprBorderInMemBottom  =  0x0020,
    ipprBorderInMemLeft    =  0x0040,
    ipprBorderInMemRight   =  0x0080,
    ipprBorderInMemFront   =  0x1000,
    ipprBorderInMemBack    =  0x2000,

    ipprBorderInMem        =  ipprBorderInMemLeft|ipprBorderInMemTop|ipprBorderInMemRight|ipprBorderInMemBottom|ipprBorderInMemFront|ipprBorderInMemBack
} IpprBorderType;


typedef enum {
    IPP_MORPH_DEFAULT          = 0x0000, /* Default, flip before second operation(erode,dilate), threshold above zero in Black/TopHat */
    IPP_MORPH_MASK_NO_FLIP     = 0x0001, /* Never flip mask */
    IPP_MORPH_NO_THRESHOLD     = 0x0004  /* No threshold in Black/TopHat */
} IppiMorphMode;


typedef struct ResizeSpec IppiResizeSpec;

/* threading wrappers types */
typedef struct FilterBilateralType_T   IppiFilterBilateralSpec_T;
typedef struct FilterBilateralType_LT  IppiFilterBilateralSpec_LT;
typedef struct ResizeSpec_LT           IppiResizeSpec_LT;
typedef struct FilterSobelType_T       IppiFilterSobelSpec_T;
typedef struct FilterBorderSpecV       IpprFilterBorderSpec;
typedef struct FilterMedianSpecV       IpprFilterMedianSpec;
typedef struct IpprFilterBorderType_T  IpprFilterBorderSpec_T;
typedef struct IpprFilterBorderType_LT IpprFilterBorderSpec_LT;
typedef struct IpprFilterMedianType_T  IpprFilterMedianSpec_T;
typedef struct FilterSeparableType_T   IppiFilterSeparableSpec_T;
typedef struct FilterSeparableType_LT  IppiFilterSeparableSpec_LT;
#ifdef __cplusplus
}
#endif

/*****************************************************************************/
/*                   Below are ippCV domain specific definitions             */
/*****************************************************************************/

typedef struct PyramidStateL IppiPyramidStateL;
typedef IppiPyramidStateL IppiPyramidUpState_32f_C1R_L;
typedef IppiPyramidStateL IppiPyramidDownState_32f_C1R_L;

typedef struct _IppiPyramidL {
    Ipp8u        **pImage;
    IppiSizeL     *pRoi;
    Ipp64f        *pRate;
    IppSizeL      *pStep;
    Ipp8u         *pState;
    int            level;
} IppiPyramidL;


#endif /* _OWN_BLDPCS */

#endif /* IPPTYPES_L_H__ */
