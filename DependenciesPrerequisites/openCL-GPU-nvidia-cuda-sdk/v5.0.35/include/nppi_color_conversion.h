 /* Copyright 2009-2012 NVIDIA Corporation.  All rights reserved. 
  * 
  * NOTICE TO LICENSEE: 
  * 
  * The source code and/or documentation ("Licensed Deliverables") are 
  * subject to NVIDIA intellectual property rights under U.S. and 
  * international Copyright laws. 
  * 
  * The Licensed Deliverables contained herein are PROPRIETARY and 
  * CONFIDENTIAL to NVIDIA and are being provided under the terms and 
  * conditions of a form of NVIDIA software license agreement by and 
  * between NVIDIA and Licensee ("License Agreement") or electronically 
  * accepted by Licensee.  Notwithstanding any terms or conditions to 
  * the contrary in the License Agreement, reproduction or disclosure 
  * of the Licensed Deliverables to any third party without the express 
  * written consent of NVIDIA is prohibited. 
  * 
  * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE 
  * LICENSE AGREEMENT, NVIDIA MAKES NO REPRESENTATION ABOUT THE 
  * SUITABILITY OF THESE LICENSED DELIVERABLES FOR ANY PURPOSE.  THEY ARE 
  * PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY OF ANY KIND. 
  * NVIDIA DISCLAIMS ALL WARRANTIES WITH REGARD TO THESE LICENSED 
  * DELIVERABLES, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY, 
  * NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE. 
  * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE 
  * LICENSE AGREEMENT, IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY 
  * SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY 
  * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, 
  * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS 
  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE 
  * OF THESE LICENSED DELIVERABLES. 
  * 
  * U.S. Government End Users.  These Licensed Deliverables are a 
  * "commercial item" as that term is defined at 48 C.F.R. 2.101 (OCT 
  * 1995), consisting of "commercial computer software" and "commercial 
  * computer software documentation" as such terms are used in 48 
  * C.F.R. 12.212 (SEPT 1995) and are provided to the U.S. Government 
  * only as a commercial end item.  Consistent with 48 C.F.R.12.212 and 
  * 48 C.F.R. 227.7202-1 through 227.7202-4 (JUNE 1995), all 
  * U.S. Government End Users acquire the Licensed Deliverables with 
  * only those rights set forth herein. 
  * 
  * Any use of the Licensed Deliverables in individual and commercial 
  * software must include, in the user documentation and internal 
  * comments to the code, the above Disclaimer and U.S. Government End 
  * Users Notice. 
  */ 
#ifndef NV_NPPI_COLOR_CONVERSION_H
#define NV_NPPI_COLOR_CONVERSION_H
 
/**
 * \file nppi_color_conversion.h
 * NPP Image Processing Functionality.
 */
 
#include "nppdefs.h"


#ifdef __cplusplus
extern "C" {
#endif


/** @defgroup image_color_conversion Color and Sampling Conversion
 *  @ingroup nppi
 *
 * Routines manipulating an image's color model and sampling format.
 *
 */
///@{

/** @defgroup image_color_model_conversion Color Model Conversion
 *
 * Routines for converting between various image color models.
 *
 *
 */
///@{                                         

/** @name RGBToYUV 
 *  RGB to YUV color conversion.
 *
 *  Here is how NPP converts gamma corrected RGB or BGR to YUV. For digital RGB values in the range [0..255], 
 *  Y has the range [0..255], U varies in the range [-112..+112], 
 *  and V in the range [-157..+157]. To fit in the range of [0..255], a constant value
 *  of 128 is added to computed U and V values, and V is then saturated.
 *
 *  \code   
 *  Npp32f nY =  0.299F * R + 0.587F * G + 0.114F * B; 
 *  Npp32f nU = (0.492F * ((Npp32f)nB - nY)) + 128.0F;
 *  Npp32f nV = (0.877F * ((Npp32f)nR - nY)) + 128.0F;
 *  if (nV > 255.0F) 
 *      nV = 255.0F;
 *  \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel 8-bit unsigned packed YUV color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYUV_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed RGB with alpha to 4 channel 8-bit unsigned packed YUV color conversion with alpha, not affecting alpha.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYUV_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar RGB to 3 channel 8-bit unsigned planar YUV color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYUV_8u_P3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel 8-bit unsigned planar YUV color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYUV_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed RGB with alpha to 4 channel 8-bit unsigned planar YUV color conversion with alpha.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYUV_8u_AC4P4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[4], int nDstStep, NppiSize oSizeROI);

///@}

/** @name YUVToRGB 
 *  YUV to RGB color conversion.
 *
 *  Here is how NPP converts YUV to gamma corrected RGB or BGR.
 *
 *  \code
 *  Npp32f nY = (Npp32f)Y;
 *  Npp32f nU = (Npp32f)U - 128.0F;
 *  Npp32f nV = (Npp32f)V - 128.0F;
 *  Npp32f nR = nY + 1.140F * nV; 
 *  if (nR < 0.0F)
 *      nR = 0.0F;
 *  if (nR > 255.0F)
 *      nR = 255.0F;    
 *  Npp32f nG = nY - 0.394F * nU - 0.581F * nV;
 *  if (nG < 0.0F)
 *      nG = 0.0F;
 *  if (nG > 255.0F)
 *      nG = 255.0F;    
 *  Npp32f nB = nY + 2.032F * nU;
 *  if (nB < 0.0F)
 *      nB = 0.0F;
 *  if (nB > 255.0F)
 *      nB = 255.0F;    
 *  \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed YUV to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYUVToRGB_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit packed YUV with alpha to 4 channel 8-bit unsigned packed RGB color conversion with alpha, not affecting alpha.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYUVToRGB_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YUV to 3 channel 8-bit unsigned planar RGB color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYUVToRGB_8u_P3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YUV to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYUVToRGB_8u_P3C3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name RGBToYUV422 
 *  RGB to YUV422 color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed RGB to 2 channel 8-bit unsigned packed YUV422 color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYUV422_8u_C3C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar RGB to 3 channel 8-bit unsigned planar YUV422 color conversion.
 * images.
 *                         
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYUV422_8u_P3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel 8-bit unsigned planar YUV422 color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYUV422_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YUV422ToRGB 
 *  YUV422 to RGB color conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed YUV422 to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYUV422ToRGB_8u_C2C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YUV422 to 3 channel 8-bit unsigned planar RGB color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYUV422ToRGB_8u_P3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YUV422 to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYUV422ToRGB_8u_P3C3R(const Npp8u* const pSrc[3], int rSrcStep[3], Npp8u* pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YUV422 to 4 channel 8-bit unsigned packed RGB color conversion with alpha.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYUV422ToRGB_8u_P3AC4R(const Npp8u* const pSrc[3], int rSrcStep[3], Npp8u* pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name RGBToYUV420 
 *  RGB to YUV420 color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar RGB to 3 channel 8-bit unsigned planar YUV420 color conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYUV420_8u_P3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel 8-bit unsigned planar YUV420 color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYUV420_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YUV420ToRGB 
 *  YUV420 to RGB color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YUV420 to 3 channel 8-bit unsigned planar RGB color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYUV420ToRGB_8u_P3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YUV420 to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYUV420ToRGB_8u_P3C3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YUV420 to 4 channel 8-bit unsigned packed RGB color conversion with alpha.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYUV420ToRGB_8u_P3AC4R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name BGRToYUV420 
 *  BGR to YUV420 color conversion.
 */
///@{
/**
 * 4 channel 8-bit unsigned pacmed BGR with alpha to 3 channel 8-bit unsigned planar YUV420 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYUV420_8u_AC4P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);
 
///@}

/** @name YUV420ToBGR 
 *  YUV420 to BGR color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YUV420 to 3 channel 8-bit unsigned packed BGR color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYUV420ToBGR_8u_P3C3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name RGBToYCbCr 
 *  RGB to YCbCr color conversion.
 *
 *  Here is how NPP converts gamma corrected RGB or BGR to YCbCr.  In the YCbCr model, 
 *  Y is defined to have a nominal range [16..235], while Cb and Cr are defined
 *  to have a range [16..240], with the value of 128 as corresponding to zero.
 *
 *  \code
 *  Npp32f nY  =  0.257F * R + 0.504F * G + 0.098F * B + 16.0F; 
 *  Npp32f nCb = -0.148F * R - 0.291F * G + 0.439F * B + 128.0F;
 *  Npp32f nCr =  0.439F * R - 0.368F * G - 0.071F * B + 128.0F;
 *  \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel unsigned 8-bit packed YCbCr color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiRGBToYCbCr_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed RGB with alpha to 4 channel unsigned 8-bit packed YCbCr with alpha color conversion, not affecting alpha.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYCbCr_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel planar 8-bit unsigned RGB to 3 channel planar 8-bit YCbCr color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYCbCr_8u_P3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel unsigned 8-bit planar YCbCr color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYCbCr_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed RGB with alpha to 3 channel 8-bit unsigned planar YCbCr color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYCbCr_8u_AC4P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCbCrToRGB 
 *  YCbCr to RGB color conversion.
 *
 *  Here is how NPP converts YCbCr to gamma corrected RGB or BGR.  The output RGB values are saturated to the range [0..255].
 *
 *  \code
 *  Npp32f nY = 1.164F * ((Npp32f)Y - 16.0F);
 *  Npp32f nR = ((Npp32f)Cr - 128.0F);
 *  Npp32f nB = ((Npp32f)Cb - 128.0F);
 *  Npp32f nG = nY - 0.813F * nR - 0.392F * nB;
 *  if (nG > 255.0F)
 *      nG = 255.0F;
 *  nR = nY + 1.596F * nR; 
 *  if (nR > 255.0F)
 *      nR = 255.0F;
 *  nB = nY + 2.017F * nB;
 *  if (nB > 255.0F)
 *      nB = 255.0F;
 *  \endcode
 *
 */
///@{

/**
 * 3 channel 8-bit unsigned packed YCbCr to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCrToRGB_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed YCbCr with alpha to 4 channel 8-bit unsigned packed RGB with alpha color conversion, not affecting alpha.
 * Alpha channel is the last channel and is not processed.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCrToRGB_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr to 3 channel 8-bit unsigned planar RGB color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCrToRGB_8u_P3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCrToRGB_8u_P3C3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr to 4 channel 8-bit unsigned packed RGB color conversion with constant alpha.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nAval 8-bit unsigned alpha constant.                                         
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCrToRGB_8u_P3C4R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst , int nDstStep, NppiSize oSizeROI, Npp8u nAval);

///@}

/** @name YCbCrToBGR 
 *  YCbCr to BGR color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr to 3 channel 8-bit unsigned packed BGR color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCrToBGR_8u_P3C3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr to 4 channel 8-bit unsigned packed BGR color conversion with constant alpha.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nAval 8-bit unsigned alpha constant.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCrToBGR_8u_P3C4R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nAval);

///@}

/** @name YCbCrToBGR_709CSC 
 *  YCbCr to BGR_709CSC color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr to 3 channel 8-bit unsigned packed BGR_709CSC color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCrToBGR_709CSC_8u_P3C3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr to 4 channel 8-bit unsigned packed BGR_709CSC color conversion with constant alpha.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nAval 8-bit unsigned alpha constant.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCrToBGR_709CSC_8u_P3C4R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nAval);

///@}

/** @name RGBToYCbCr422 
 *  RGB to YCbCr422 color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed RGB to 2 channel 8-bit unsigned packed YCbCr422 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiRGBToYCbCr422_8u_C3C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel 8-bit unsigned planar YCbCr422 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYCbCr422_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar RGB to 2 channel 8-bit unsigned packed YCbCr422 color conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYCbCr422_8u_P3C2R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCbCr422ToRGB 
 *  YCbCr422 to RGB color conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed YCbCr422 to 3 channel 8-bit unsigned packed RGB color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToRGB_8u_C2C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI); 

/**
 * 2 channel 8-bit unsigned packed YCbCr422 to 3 channel 8-bit unsigned planar RGB color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToRGB_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr422 to 3 channel 8-bit unsigned packed RGB color conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToRGB_8u_P3C3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name RGBToYCrCb422 
 *  RGB to YCrCb422 color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed RGB to 2 channel 8-bit unsigned packed YCrCb422 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYCrCb422_8u_C3C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar RGB to 2 channel 8-bit unsigned packed YCrCb422 color conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYCrCb422_8u_P3C2R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCrCb422ToRGB 
 *  YCrCb422 to RGB color conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed YCrCb422 to 3 channel 8-bit unsigned packed RGB color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCrCb422ToRGB_8u_C2C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI); 

/**
 * 2 channel 8-bit unsigned packed YCrCb422 to 3 channel 8-bit unsigned planar RGB color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCrCb422ToRGB_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

///@}

/** @name BGRToYCbCr422 
 *  BGR to YCbCr422 color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed BGR to 2 channel 8-bit unsigned packed YCrCb422 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCbCr422_8u_C3C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed BGR with alpha to 2 channel 8-bit unsigned packed YCrCb422 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCbCr422_8u_AC4C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned packed BGR to 3 channel 8-bit unsigned planar YCbCr422 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCbCr422_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed BGR with alpha to 3 channel 8-bit unsigned planar YCbCr422 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCbCr422_8u_AC4P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCbCr422ToBGR 
 *  YCbCr422 to BGR color conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed YCrCb422 to 3 channel 8-bit unsigned packed BGR color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToBGR_8u_C2C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned packed YCrCb422 to 4 channel 8-bit unsigned packed BGR color conversion with constant alpha.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nAval 8-bit unsigned alpha constant.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToBGR_8u_C2C4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nAval);

/**
 * 3 channel 8-bit unsigned planar YCbCr422 to 3 channel 8-bit unsigned packed BGR color conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToBGR_8u_P3C3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name RGBToCbYCr422 
 *  RGB to CbYCr422 color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed RGB to 2 channel 8-bit unsigned packed CbYCr422 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToCbYCr422_8u_C3C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned packed RGB first gets forward gamma corrected then converted to 2 channel 8-bit unsigned packed CbYCr422 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToCbYCr422Gamma_8u_C3C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name CbYCr422ToRGB 
 *  CbYCr422 to RGB color conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed CbYCrC22 to 3 channel 8-bit unsigned packed RGB color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCbYCr422ToRGB_8u_C2C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name BGRToCbYCr422 
 *  BGR to CbYCr422 color conversion.
 */
///@{
/**
 * 4 channel 8-bit unsigned packed BGR with alpha to 2 channel 8-bit unsigned packed CbYCr422 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToCbYCr422_8u_AC4C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name BGRToCbYCr422_709HDTV 
 *  BGR to CbYCr422_709HDTV color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed BGR to 2 channel 8-bit unsigned packed CbYCr422_709HDTV color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToCbYCr422_709HDTV_8u_C3C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed BGR with alpha to 2 channel 8-bit unsigned packed CbYCr422_709HDTV color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToCbYCr422_709HDTV_8u_AC4C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name CbYCr422ToBGR 
 *  CbYCr422 to BGR color conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed CbYCr422 to 4 channel 8-bit unsigned packed BGR color conversion with alpha.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nAval 8-bit unsigned alpha constant.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCbYCr422ToBGR_8u_C2C4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nAval);

///@}

/** @name CbYCr422ToBGR_709HDTV 
 *  CbYCr422 to BGR_709HDTV color conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed CbYCr422 to 3 channel 8-bit unsigned packed BGR_709HDTV color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCbYCr422ToBGR_709HDTV_8u_C2C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned packed CbYCr422 to 4 channel 8-bit unsigned packed BGR_709HDTV color conversion with constant alpha.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nAval 8-bit unsigned alpha constant.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCbYCr422ToBGR_709HDTV_8u_C2C4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nAval);

///@}

/** @name RGBToYCbCr420 
 *  RGB to YCbCr420 color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel 8-bit unsigned planar YCbCr420 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYCbCr420_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCbCr420ToRGB 
 *  YCbCr420 to RGB color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr420 to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420ToRGB_8u_P3C3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name RGBToYCrCb420 
 *  RGB to YCrCb420 color conversion.
 */
///@{
/**
 * 4 channel 8-bit unsigned packed RGB with alpha to 3 channel 8-bit unsigned planar YCrCb420 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYCrCb420_8u_AC4P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCrCb420ToRGB 
 *  YCrCb420 to RGB color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCrCb420 to 4 channel 8-bit unsigned packed RGB color conversion with constant alpha.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nAval 8-bit unsigned alpha constant.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCrCb420ToRGB_8u_P3C4R(const Npp8u * const pSrc[3],int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nAval);

///@}

/** @name BGRToYCbCr420 
 *  BGR to YCbCr420 color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed BGR to 3 channel 8-bit unsigned planar YCbCr420 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCbCr420_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed BGR with alpha to 3 channel 8-bit unsigned planar YCbCr420 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCbCr420_8u_AC4P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name BGRToYCbCr420_709CSC 
 *  BGR to YCbCr420_709CSC color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed BGR to 3 channel 8-bit unsigned planar YCbCr420_709CSC color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCbCr420_709CSC_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed BGR with alpha to 3 channel 8-bit unsigned planar YCbCr420_709CSC color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCbCr420_709CSC_8u_AC4P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name BGRToYCbCr420_709HDTV 
 *  BGR to YCbCr420_709HDTV color conversion.
 */
///@{
/**
 * 4 channel 8-bit unsigned packed BGR with alpha to 3 channel 8-bit unsigned planar YCbCr420_709HDTV color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCbCr420_709HDTV_8u_AC4P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name BGRToYCrCb420_709CSC 
 *  BGR to YCrCb420_709CSC color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed BGR to 3 channel 8-bit unsigned planar YCrCb420_709CSC color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCrCb420_709CSC_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed BGR with alpha to 3 channel 8-bit unsigned planar YCrCb420_709CSC color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCrCb420_709CSC_8u_AC4P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCbCr420ToBGR 
 *  YCbCr420 to BGR color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr420 to 3 channel 8-bit unsigned packed BGR color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420ToBGR_8u_P3C3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr420 to 4 channel 8-bit unsigned packed BGR color conversion with constant alpha.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nAval 8-bit unsigned alpha constant.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420ToBGR_8u_P3C4R(const Npp8u * const pSrc[3], int rSrcStep[3],Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nAval);

///@}

/** @name YCbCr420ToBGR_709CSC 
 *  YCbCr420_709CSC to BGR color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr420 to 3 channel 8-bit unsigned packed BGR_709CSC color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420ToBGR_709CSC_8u_P3C3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCbCr420ToBGR_709HDTV 
 *  YCbCr420_709HDTV to BGR color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr420 to 4 channel 8-bit unsigned packed BGR_709HDTV color conversion with constant alpha.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nAval 8-bit unsigned alpha constant.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420ToBGR_709HDTV_8u_P3C4R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nAval);

///@}

/** @name BGRToYCrCb420 
 *  BGR to YCrCb420 color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed BGR to 3 channel 8-bit unsigned planar YCrCb420 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCrCb420_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed BGR with alpha to 3 channel 8-bit unsigned planar YCrCb420 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCrCb420_8u_AC4P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name BGRToYCbCr411 
 *  BGR to YCbCr411 color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed BGR to 3 channel 8-bit unsigned planar YCbCr411 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCbCr411_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed BGR with alpha to 3 channel 8-bit unsigned planar YCbCr411 color conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToYCbCr411_8u_AC4P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCbCr411ToBGR 
 *  YCbCr411 to BGR color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr411 to 3 channel 8-bit unsigned packed BGR color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411ToBGR_8u_P3C3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr411 to 4 channel 8-bit unsigned packed BGR color conversion with constant alpha.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nAval 8-bit unsigned alpha constant.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411ToBGR_8u_P3C4R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nAval);

///@}

/** @name RGBToXYZ 
 *  RGB to XYZ color conversion.
 *
 *  Here is how NPP converts gamma corrected RGB or BGR to XYZ.
 *
 *  \code
 *  Npp32f nNormalizedR = (Npp32f)R * 0.003921569F; // / 255.0F
 *  Npp32f nNormalizedG = (Npp32f)G * 0.003921569F;
 *  Npp32f nNormalizedB = (Npp32f)B * 0.003921569F;
 *  Npp32f nX = 0.412453F * nNormalizedR + 0.35758F  * nNormalizedG + 0.180423F * nNormalizedB; 
 *  if (nX > 1.0F)
 *      nX = 1.0F;
 *  Npp32f nY = 0.212671F * nNormalizedR + 0.71516F  * nNormalizedG + 0.072169F * nNormalizedB;
 *  if (nY > 1.0F)
 *      nY = 1.0F;
 *  Npp32f nZ = 0.019334F * nNormalizedR + 0.119193F * nNormalizedG + 0.950227F * nNormalizedB;
 *  if (nZ > 1.0F)
 *      nZ = 1.0F;
 *  X = (Npp8u)(nX * 255.0F);
 *  Y = (Npp8u)(nY * 255.0F);
 *  Z = (Npp8u)(nZ * 255.0F);
 *  \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel 8-bit unsigned packed XYZ color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToXYZ_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed RGB with alpha to 4 channel 8-bit unsigned packed XYZ with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToXYZ_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name XYZToRGB 
 *  XYZ to RGB color conversion.
 *
 *  Here is how NPP converts XYZ to gamma corrected RGB or BGR.  The code assumes that X,Y, and Z values are in the range [0..1].
 *
 *  \code
 *  Npp32f nNormalizedX = (Npp32f)X * 0.003921569F; // / 255.0F
 *  Npp32f nNormalizedY = (Npp32f)Y * 0.003921569F;
 *  Npp32f nNormalizedZ = (Npp32f)Z * 0.003921569F;
 *  Npp32f nR = 3.240479F * nNormalizedX - 1.53715F  * nNormalizedY - 0.498535F * nNormalizedZ; 
 *  if (nR > 1.0F)
 *      nR = 1.0F;
 *  Npp32f nG = -0.969256F * nNormalizedX + 1.875991F  * nNormalizedY + 0.041556F * nNormalizedZ;
 *  if (nG > 1.0F)
 *      nG = 1.0F;
 *  Npp32f nB = 0.055648F * nNormalizedX - 0.204043F * nNormalizedY + 1.057311F * nNormalizedZ;
 *  if (nB > 1.0F)
 *      nB = 1.0F;
 *  R = (Npp8u)(nR * 255.0F);
 *  G = (Npp8u)(nG * 255.0F);
 *  B = (Npp8u)(nB * 255.0F);
 *  \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed XYZ to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiXYZToRGB_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed XYZ with alpha to 4 channel 8-bit unsigned packed RGB with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiXYZToRGB_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name RGBToLUV 
 *  RGB to LUV color conversion.
 *
 *  Here is how NPP converts gamma corrected RGB or BGR to CIE LUV using the CIE XYZ D65 white point with a Y luminance of 1.0.
 *  The computed values of the L component are in the range [0..100], U component in the range [-134..220], 
 *  and V component in the range [-140..122]. The code uses cbrtf() the 32 bit floating point cube root math function.
 *
 *  \code
 *  // use CIE D65 chromaticity coordinates
 *  #define nCIE_XYZ_D65_xn 0.312713F
 *  #define nCIE_XYZ_D65_yn 0.329016F
 *  #define nn_DIVISOR (-2.0F * nCIE_XYZ_D65_xn + 12.0F * nCIE_XYZ_D65_yn + 3.0F)
 *  #define nun (4.0F * nCIE_XYZ_D65_xn / nn_DIVISOR)
 *  #define nvn (9.0F * nCIE_XYZ_D65_yn / nn_DIVISOR)
 *    
 *  // First convert to XYZ
 *  Npp32f nNormalizedR = (Npp32f)R * 0.003921569F; // / 255.0F
 *  Npp32f nNormalizedG = (Npp32f)G * 0.003921569F;
 *  Npp32f nNormalizedB = (Npp32f)B * 0.003921569F;
 *  Npp32f nX = 0.412453F * nNormalizedR + 0.35758F  * nNormalizedG + 0.180423F * nNormalizedB; 
 *  Npp32f nY = 0.212671F * nNormalizedR + 0.71516F  * nNormalizedG + 0.072169F * nNormalizedB;
 *  Npp32f nZ = 0.019334F * nNormalizedR + 0.119193F * nNormalizedG + 0.950227F * nNormalizedB;
 *  // Now calculate LUV from the XYZ value
 *  Npp32f nTemp = nX + 15.0F * nY + 3.0F * nZ;
 *  Npp32f nu = 4.0F * nX / nTemp;
 *  Npp32f nv = 9.0F * nY / nTemp;
 *  Npp32f nL = 116.0F * cbrtf(nY) - 16.0F;
 *  if (nL < 0.0F)
 *      nL = 0.0F;
 *  if (nL > 100.0F)
 *      nL = 100.0F;
 *  nTemp = 13.0F * nL;
 *  Npp32f nU = nTemp * (nu - nun);
 *  if (nU < -134.0F)
 *      nU = -134.0F;
 *  if (nU > 220.0F)
 *      nU = 220.0F;
 *  Npp32f nV = nTemp * (nv - nvn);
 *  if (nV < -140.0F)
 *      nV = -140.0F;
 *  if (nV > 122.0F)
 *      nV = 122.0F;
 *  L = (Npp8u)(nL * 255.0F * 0.01F); // / 100.0F
 *  U = (Npp8u)((nU + 134.0F) * 255.0F * 0.0028249F); // / 354.0F
 *  V = (Npp8u)((nV + 140.0F) * 255.0F * 0.0038168F); // / 262.0F
 *  \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel 8-bit unsigned packed LUV color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToLUV_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed RGB with alpha to 4 channel 8-bit unsigned packed LUV with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToLUV_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name LUVToRGB 
 *  LUV to RGB color conversion.
 *
 *  Here is how NPP converts CIE LUV to gamma corrected RGB or BGR using the CIE XYZ D65 white point with a Y luminance of 1.0.
 *  The code uses powf() the 32 bit floating point power math function. 
 *
 *  \code
 *  // use CIE D65 chromaticity coordinates
 *  #define nCIE_XYZ_D65_xn 0.312713F
 *  #define nCIE_XYZ_D65_yn 0.329016F
 *  #define nn_DIVISOR (-2.0F * nCIE_XYZ_D65_xn + 12.0F * nCIE_XYZ_D65_yn + 3.0F)
 *  #define nun (4.0F * nCIE_XYZ_D65_xn / nn_DIVISOR)
 *  #define nvn (9.0F * nCIE_XYZ_D65_yn / nn_DIVISOR)
 *    
 *  // First convert normalized LUV back to original CIE LUV range
 *  Npp32f nL = (Npp32f)L * 100.0F * 0.003921569F;  // / 255.0F
 *  Npp32f nU = ((Npp32f)U * 354.0F * 0.003921569F) - 134.0F;
 *  Npp32f nV = ((Npp32f)V * 262.0F * 0.003921569F) - 140.0F;
 *  // Now convert LUV to CIE XYZ
 *  Npp32f nTemp = 13.0F * nL;
 *  Npp32f nu = nU / nTemp + nun;
 *  Npp32f nv = nV / nTemp + nvn;
 *  Npp32f nNormalizedY;
 *  if (nL > 7.9996248F)
 *  {
 *      nNormalizedY = (nL + 16.0F) * 0.008621F; // / 116.0F
 *      nNormalizedY = powf(nNormalizedY, 3.0F);
 *  }
 *  else
 *  {    
 *      nNormalizedY = nL * 0.001107F; // / 903.3F
 *  }    
 *  Npp32f nNormalizedX = (-9.0F * nNormalizedY * nu) / ((nu - 4.0F) * nv - nu * nv);
 *  Npp32f nNormalizedZ = (9.0F * nNormalizedY - 15.0F * nv * nNormalizedY - nv * nNormalizedX) / (3.0F * nv);
 *  Npp32f nR = 3.240479F * nNormalizedX - 1.53715F  * nNormalizedY - 0.498535F * nNormalizedZ; 
 *  if (nR > 1.0F)
 *      nR = 1.0F;
 *  if (nR < 0.0F)
 *      nR = 0.0F;
 *  Npp32f nG = -0.969256F * nNormalizedX + 1.875991F  * nNormalizedY + 0.041556F * nNormalizedZ;
 *  if (nG > 1.0F)
 *      nG = 1.0F;
 *  if (nG < 0.0F)
 *      nG = 0.0F;
 *  Npp32f nB = 0.055648F * nNormalizedX - 0.204043F * nNormalizedY + 1.057311F * nNormalizedZ;
 *  if (nB > 1.0F)
 *      nB = 1.0F;
 *  if (nB < 0.0F)
 *      nB = 0.0F;
 *  R = (Npp8u)(nR * 255.0F);
 *  G = (Npp8u)(nG * 255.0F);
 *  B = (Npp8u)(nB * 255.0F);
 *  \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed LUV to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiLUVToRGB_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed LUV with alpha to 4 channel 8-bit unsigned packed RGB with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiLUVToRGB_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name BGRToLab 
 *  BGR to Lab color conversion.
 *
 *  This is how NPP converts gamma corrected BGR or RGB to Lab using the CIE Lab D65 white point with a Y luminance of 1.0.
 *  The computed values of the L component are in the range [0..100], a and b component values are in the range [-128..127].
 *  The code uses cbrtf() the 32 bit floating point cube root math function.
 *
 *  \code
 *  // use CIE Lab chromaticity coordinates
 *  #define nCIE_LAB_D65_xn 0.950455F
 *  #define nCIE_LAB_D65_yn 1.0F
 *  #define nCIE_LAB_D65_zn 1.088753F
 *  // First convert to XYZ
 *  Npp32f nNormalizedR = (Npp32f)R * 0.003921569F; // / 255.0F
 *  Npp32f nNormalizedG = (Npp32f)G * 0.003921569F;
 *  Npp32f nNormalizedB = (Npp32f)B * 0.003921569F;
 *  Npp32f nX = 0.412453F * nNormalizedR + 0.35758F  * nNormalizedG + 0.180423F * nNormalizedB; 
 *  Npp32f nY = 0.212671F * nNormalizedR + 0.71516F  * nNormalizedG + 0.072169F * nNormalizedB;
 *  Npp32f nZ = 0.019334F * nNormalizedR + 0.119193F * nNormalizedG + 0.950227F * nNormalizedB;
 *  Npp32f nL = cbrtf(nY);
 *  Npp32f nA;
 *  Npp32f nB;
 *  Npp32f nfX = nX * 1.052128F; // / nCIE_LAB_D65_xn; 
 *  Npp32f nfY = nY;
 *  Npp32f nfZ = nZ * 0.918482F; // / nCIE_LAB_D65_zn;
 *  if (nfY > 0.008856F)
 *  {
 *      nfY = nL - 16.0F;
 *      nL = 116.0F * nL - 16.0F;
 *  }
 *  else
 *  {
 *      nfY = 7.787F * nY + 16.0F * 0.008621F; // / 116.0F
 *  }
 *  if (nfX > 0.008856F)
 *  {
 *      nA = cbrtf(nfX) - 16.0F;
 *  }
 *  else
 *  {
 *      nA = 7.787F * nfX + 16.0F * 0.008621F; // / 116.0F
 *  }
 *  nA = 500.0F * (nA - nfY);
 *  if (nfZ > 0.008856F)
 *  {
 *      nB = cbrtf(nfZ) - 16.0F;
 *  }
 *  else
 *  {
 *      nB = 7.787F * nfZ + 16.0F * 0.008621F; // / 116.0F
 *  }
 *  nB = 200.0F * (nfY - nB);
 *  // Now scale Lab range
 *  nL = nL * 255.0F * 0.01F; // / 100.0F
 *  nA = nA + 128.0F;
 *  nB = nB + 128.0F;
 *  L = (Npp8u)nL;
 *  a = (Npp8u)nA;
 *  b = (Npp8u)nB;
 *  \endcode
 * 
 */
///@{
/**
 * 3 channel 8-bit unsigned packed BGR to 3 channel 8-bit unsigned packed Lab color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToLab_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name LabToBGR 
 *  Lab to BGR color conversion.
 *
 *  This is how NPP converts Lab to gamma corrected BGR or RGB using the CIE Lab D65 white point with a Y luminance of 1.0.
 *  The code uses powf() the 32 bit floating point power math function. 
 *
 *  \code
 *  // use CIE Lab chromaticity coordinates
 *  #define nCIE_LAB_D65_xn 0.950455F
 *  #define nCIE_LAB_D65_yn 1.0F
 *  #define nCIE_LAB_D65_zn 1.088753F
 *  // First convert Lab back to original range then to CIE XYZ
 *  Npp32f nL = (Npp32f)L * 100.0F * 0.003921569F;  // / 255.0F
 *  Npp32f nA = (Npp32f)a - 128.0F;
 *  Npp32f nB = (Npp32f)b - 128.0F;
 *  Npp32f nP = (nL + 16.0F) * 0.008621F; // / 116.0F
 *  Npp32f nNormalizedY = nP * nP * nP; // powf(nP, 3.0F);
 *  Npp32f nNormalizedX = nCIE_LAB_D65_xn * powf((nP + nA * 0.002F), 3.0F); // / 500.0F
 *  Npp32f nNormalizedZ = nCIE_LAB_D65_zn * powf((nP - nB * 0.005F), 3.0F); // / 200.0F
 *  Npp32f nR = 3.240479F * nNormalizedX - 1.53715F  * nNormalizedY - 0.498535F * nNormalizedZ; 
 *  if (nR > 1.0F)
 *      nR = 1.0F;
 *  Npp32f nG = -0.969256F * nNormalizedX + 1.875991F  * nNormalizedY + 0.041556F * nNormalizedZ;
 *  if (nG > 1.0F)
 *      nG = 1.0F;
 *  nB = 0.055648F * nNormalizedX - 0.204043F * nNormalizedY + 1.057311F * nNormalizedZ;
 *  if (nB > 1.0F)
 *      nB = 1.0F;
 *  R = (Npp8u)(nR * 255.0F);
 *  G = (Npp8u)(nG * 255.0F);
 *  B = (Npp8u)(nB * 255.0F);
 *  \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed Lab to 3 channel 8-bit unsigned packed BGR color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiLabToBGR_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name RGBToYCC 
 *  RGB to PhotoYCC color conversion.
 *
 *  This is how NPP converts gamma corrected BGR or RGB to PhotoYCC.
 *  The computed Y, C1, C2 values are then quantized and converted to fit in the range [0..1] before expanding to 8 bits.
 *
 *  \code
 *  Npp32f nNormalizedR = (Npp32f)R * 0.003921569F; // / 255.0F
 *  Npp32f nNormalizedG = (Npp32f)G * 0.003921569F;
 *  Npp32f nNormalizedB = (Npp32f)B * 0.003921569F;
 *  Npp32f nY = 0.299F * nNormalizedR + 0.587F  * nNormalizedG + 0.114F * nNormalizedB; 
 *  Npp32f nC1 = nNormalizedB - nY;
 *  nC1 = 111.4F * 0.003921569F * nC1 + 156.0F * 0.003921569F;
 *  Npp32f nC2 = nNormalizedR - nY;
 *  nC2 = 135.64F * 0.003921569F * nC2 + 137.0F * 0.003921569F;
 *  nY = 1.0F * 0.713267F * nY; // / 1.402F
 *  Y = (Npp8u)(nY  * 255.0F);
 *  C1 = (Npp8u)(nC1 * 255.0F);
 *  C2 = (Npp8u)(nC2 * 255.0F);
 *  \endcode
 * 
 */
///@{
/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel 8-bit unsigned packed YCC color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYCC_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed RGB with alpha to 4 channel 8-bit unsigned packed YCC with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToYCC_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCCToRGB 
 *  PhotoYCC to RGB color conversion.
 *
 *  This is how NPP converts PhotoYCC to gamma corrected RGB or BGR.
 *
 *  \code
 *  Npp32f nNormalizedY  = ((Npp32f)Y * 0.003921569F) * 1.3584F;  // / 255.0F
 *  Npp32f nNormalizedC1 = (((Npp32f)C1 * 0.003921569F) - 156.0F * 0.003921569F) * 2.2179F;
 *  Npp32f nNormalizedC2 = (((Npp32f)C2 * 0.003921569F) - 137.0F * 0.003921569F) * 1.8215F;
 *  Npp32f nR = nNormalizedY + nNormalizedC2;
 *  if (nR > 1.0F)
 *      nR = 1.0F;
 *  Npp32f nG = nNormalizedY - 0.194F  * nNormalizedC1 - 0.509F * nNormalizedC2;
 *  if (nG > 1.0F)
 *      nG = 1.0F;
 *  Npp32f nB = nNormalizedY + nNormalizedC1;
 *  if (nB > 1.0F)
 *      nB = 1.0F;
 *  R = (Npp8u)(nR * 255.0F);
 *  G = (Npp8u)(nG * 255.0F);
 *  B = (Npp8u)(nB * 255.0F);
 *  \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed YCC to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCCToRGB_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed YCC with alpha to 4 channel 8-bit unsigned packed RGB with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCCToRGB_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name RGBToHLS 
 *  RGB to HLS color conversion.
 *
 *  This is how NPP converts gamma corrected RGB or BGR to HLS.
 *  This code uses the fmaxf() and fminf() 32 bit floating point math functions.
 *
 *  \code
 *  Npp32f nNormalizedR = (Npp32f)R * 0.003921569F;  // / 255.0F
 *  Npp32f nNormalizedG = (Npp32f)G * 0.003921569F;
 *  Npp32f nNormalizedB = (Npp32f)B * 0.003921569F;
 *  Npp32f nS;
 *  Npp32f nH;
 *  // Lightness
 *  Npp32f nMax = fmaxf(nNormalizedR, nNormalizedG);
 *         nMax = fmaxf(nMax, nNormalizedB);
 *  Npp32f nMin = fminf(nNormalizedR, nNormalizedG);
 *         nMin = fminf(nMin, nNormalizedB);
 *  Npp32f nL = (nMax + nMin) * 0.5F;
 *  Npp32f nDivisor = nMax - nMin;
 *  // Saturation
 *  if (nDivisor == 0.0F) // achromatics case
 *  {
 *      nS = 0.0F;
 *      nH = 0.0F;
 *  }
 *  else // chromatics case
 *  {
 *      if (nL > 0.5F)
 *          nS = nDivisor / (1.0F - (nMax + nMin - 1.0F));
 *      else
 *          nS = nDivisor / (nMax + nMin);
 *  }
 *  // Hue
 *  Npp32f nCr = (nMax - nNormalizedR) / nDivisor;
 *  Npp32f nCg = (nMax - nNormalizedG) / nDivisor;
 *  Npp32f nCb = (nMax - nNormalizedB) / nDivisor;
 *  if (nNormalizedR == nMax)
 *      nH = nCb - nCg;
 *  else if (nNormalizedG == nMax)
 *      nH = 2.0F + nCr - nCb;
 *  else if (nNormalizedB == nMax)
 *      nH = 4.0F + nCg - nCr;
 *  nH = nH * 0.166667F; // / 6.0F       
 *  if (nH < 0.0F)
 *      nH = nH + 1.0F;
 *  H = (Npp8u)(nH * 255.0F);
 *  L = (Npp8u)(nL * 255.0F);
 *  S = (Npp8u)(nS * 255.0F);
 *  \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel 8-bit unsigned packed HLS color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToHLS_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed RGB with alpha to 4 channel 8-bit unsigned packed HLS with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToHLS_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name HLSToRGB 
 *  HLS to RGB color conversion.
 *
 *  This is how NPP converts HLS to gamma corrected RGB or BGR.
 *
 *  \code
 *  Npp32f nNormalizedH = (Npp32f)H * 0.003921569F;  // / 255.0F
 *  Npp32f nNormalizedL = (Npp32f)L * 0.003921569F;
 *  Npp32f nNormalizedS = (Npp32f)S * 0.003921569F;
 *  Npp32f nM1;
 *  Npp32f nM2;
 *  Npp32f nR;
 *  Npp32f nG;
 *  Npp32f nB;
 *  Npp32f nh = 0.0F;
 *  if (nNormalizedL <= 0.5F)
 *      nM2 = nNormalizedL * (1.0F + nNormalizedS);
 *  else
 *      nM2 = nNormalizedL + nNormalizedS - nNormalizedL * nNormalizedS;
 *  nM1 = 2.0F * nNormalizedL - nM2;
 *  if (nNormalizedS == 0.0F)
 *      nR = nG = nB = nNormalizedL;
 *  else
 *  {
 *      nh = nNormalizedH + 0.3333F;
 *      if (nh > 1.0F)
 *          nh -= 1.0F;
 *  }
 *  Npp32f nMDiff = nM2 - nM1;
 *  if (0.6667F < nh)
 *      nR = nM1;
 *  else
 *  {    
 *      if (nh < 0.1667F)
 *          nR = (nM1 + nMDiff * nh * 6.0F); // / 0.1667F
 *      else if (nh < 0.5F)
 *          nR = nM2;
 *      else
 *          nR = nM1 + nMDiff * ( 0.6667F - nh ) * 6.0F; // / 0.1667F
 *  }
 *  if (nR > 1.0F)
 *      nR = 1.0F;     
 *  nh = nNormalizedH;
 *  if (0.6667F < nh)
 *      nG = nM1;
 *  else
 *  {
 *      if (nh < 0.1667F)
 *          nG = (nM1 + nMDiff * nh * 6.0F); // / 0.1667F
 *      else if (nh < 0.5F)
 *          nG = nM2;
 *      else
 *          nG = nM1 + nMDiff * (0.6667F - nh ) * 6.0F; // / 0.1667F
 *  }
 *  if (nG > 1.0F)
 *      nG = 1.0F;     
 *  nh = nNormalizedH - 0.3333F;
 *  if (nh < 0.0F)
 *      nh += 1.0F;
 *  if (0.6667F < nh)
 *      nB = nM1;
 *  else
 *  {
 *      if (nh < 0.1667F)
 *          nB = (nM1 + nMDiff * nh * 6.0F); // / 0.1667F
 *      else if (nh < 0.5F)
 *          nB = nM2;
 *      else
 *          nB = nM1 + nMDiff * (0.6667F - nh ) * 6.0F; // / 0.1667F
 *  }        
 *  if (nB > 1.0F)
 *      nB = 1.0F;     
 *  R = (Npp8u)(nR * 255.0F);
 *  G = (Npp8u)(nG * 255.0F);
 *  B = (Npp8u)(nB * 255.0F);
 *  \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed HLS to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiHLSToRGB_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed HLS with alpha to 4 channel 8-bit unsigned packed RGB with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiHLSToRGB_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name BGRToHLS 
 *  BGR to HLS color conversion.
 */
///@{
/**
 * 4 channel 8-bit unsigned packed BGR with alpha to 4 channel 8-bit unsigned packed HLS with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToHLS_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned packed BGR to 3 channel 8-bit unsigned planar HLS color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToHLS_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed BGR with alpha to 4 channel 8-bit unsigned planar HLS with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToHLS_8u_AC4P4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[4], int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar BGR to 3 channel 8-bit unsigned packed HLS color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToHLS_8u_P3C3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned planar BGR with alpha to 4 channel 8-bit unsigned packed HLS with alpha color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToHLS_8u_AP4C4R(const Npp8u * const pSrc[4], int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar BGR to 3 channel 8-bit unsigned planar HLS color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToHLS_8u_P3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned planar BGR with alpha to 4 channel 8-bit unsigned planar HLS with alpha color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiBGRToHLS_8u_AP4R(const Npp8u * const pSrc[4], int nSrcStep, Npp8u * pDst[4], int nDstStep, NppiSize oSizeROI);

///@}

/** @name HLSToBGR 
 *  HLS to BGR color conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed HLS to 3 channel 8-bit unsigned planar BGR color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiHLSToBGR_8u_C3P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed HLS with alpha to 4 channel 8-bit unsigned planar BGR with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiHLSToBGR_8u_AC4P4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[4], int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar HLS to 3 channel 8-bit unsigned planar BGR color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiHLSToBGR_8u_P3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned planar HLS with alpha to 4 channel 8-bit unsigned planar BGR with alpha color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiHLSToBGR_8u_AP4R(const Npp8u * const pSrc[4], int nSrcStep, Npp8u * pDst[4], int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed HLS with alpha to 4 channel 8-bit unsigned packed BGR with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiHLSToBGR_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar HLS to 3 channel 8-bit unsigned packed BGR color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiHLSToBGR_8u_P3C3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned planar HLS with alpha to 4 channel 8-bit unsigned packed BGR with alpha color conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiHLSToBGR_8u_AP4C4R(const Npp8u * const pSrc[4], int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name RGBToHSV 
 *  RGB to HSV color conversion.
 *
 *  This is how NPP converts gamma corrected RGB or BGR to HSV.
 *  This code uses the fmaxf() and fminf() 32 bit floating point math functions.
 *
 * \code
 *  Npp32f nNormalizedR = (Npp32f)R * 0.003921569F; // / 255.0F
 *  Npp32f nNormalizedG = (Npp32f)G * 0.003921569F;
 *  Npp32f nNormalizedB = (Npp32f)B * 0.003921569F;
 *  Npp32f nS;
 *  Npp32f nH;
 *  // Value
 *  Npp32f nV = fmaxf(nNormalizedR, nNormalizedG);
 *         nV = fmaxf(nV, nNormalizedB);
 *  // Saturation
 *  Npp32f nTemp = fminf(nNormalizedR, nNormalizedG);
 *         nTemp = fminf(nTemp, nNormalizedB);
 *  Npp32f nDivisor = nV - nTemp;
 *  if (nV == 0.0F) // achromatics case
 *  {
 *      nS = 0.0F;
 *      nH = 0.0F;
 *  }    
 *  else // chromatics case
 *      nS = nDivisor / nV;
 *  // Hue:
 *  Npp32f nCr = (nV - nNormalizedR) / nDivisor;
 *  Npp32f nCg = (nV - nNormalizedG) / nDivisor;
 *  Npp32f nCb = (nV - nNormalizedB) / nDivisor;
 *  if (nNormalizedR == nV)
 *      nH = nCb - nCg;
 *  else if (nNormalizedG == nV)
 *      nH = 2.0F + nCr - nCb;
 *  else if (nNormalizedB == nV)
 *      nH = 4.0F + nCg - nCr;
 *  nH = nH * 0.166667F; // / 6.0F       
 *  if (nH < 0.0F)
 *      nH = nH + 1.0F;
 *  H = (Npp8u)(nH * 255.0F);
 *  S = (Npp8u)(nS * 255.0F);
 *  V = (Npp8u)(nV * 255.0F);
 * \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed RGB to 3 channel 8-bit unsigned packed HSV color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToHSV_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed RGB with alpha to 4 channel 8-bit unsigned packed HSV with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiRGBToHSV_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name HSVToRGB 
 *  HSV to RGB color conversion.
 *
 *  This is how NPP converts HSV to gamma corrected RGB or BGR.
 *  This code uses the floorf() 32 bit floating point math function.
 *
 *  \code
 *  Npp32f nNormalizedH = (Npp32f)H * 0.003921569F; // / 255.0F
 *  Npp32f nNormalizedS = (Npp32f)S * 0.003921569F;
 *  Npp32f nNormalizedV = (Npp32f)V * 0.003921569F;
 *  Npp32f nR;
 *  Npp32f nG;
 *  Npp32f nB;
 *  if (nNormalizedS == 0.0F)
 *  {
 *      nR = nG = nB = nNormalizedV;
 *  }
 *  else
 *  {
 *      if (nNormalizedH == 1.0F)
 *          nNormalizedH = 0.0F;
 *      else
 *          nNormalizedH = nNormalizedH * 6.0F; // / 0.1667F
 *  }
 *  Npp32f nI = floorf(nNormalizedH);
 *  Npp32f nF = nNormalizedH - nI;
 *  Npp32f nM = nNormalizedV * (1.0F - nNormalizedS);
 *  Npp32f nN = nNormalizedV * (1.0F - nNormalizedS * nF);
 *  Npp32f nK = nNormalizedV * (1.0F - nNormalizedS * (1.0F - nF));
 *  if (nI == 0.0F)
 *      { nR = nNormalizedV; nG = nK; nB = nM; }
 *  else if (nI == 1.0F)
 *      { nR = nN; nG = nNormalizedV; nB = nM; }
 *  else if (nI == 2.0F)
 *      { nR = nM; nG = nNormalizedV; nB = nK; }
 *  else if (nI == 3.0F)
 *      { nR = nM; nG = nN; nB = nNormalizedV; }
 *  else if (nI == 4.0F)
 *      { nR = nK; nG = nM; nB = nNormalizedV; }
 *  else if (nI == 5.0F)
 *      { nR = nNormalizedV; nG = nM; nB = nN; }
 *  R = (Npp8u)(nR * 255.0F);
 *  G = (Npp8u)(nG * 255.0F);
 *  B = (Npp8u)(nB * 255.0F);
 *  \endcode
 *
 */
///@{
/**
 * 3 channel 8-bit unsigned packed HSV to 3 channel 8-bit unsigned packed RGB color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiHSVToRGB_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed HSV with alpha to 4 channel 8-bit unsigned packed RGB with alpha color conversion.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiHSVToRGB_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

///@} image_color_model_conversion

/** @defgroup image_color_sampling_format_conversion Color Sampling Format Conversion
 *
 * Routines for converting between various image color sampling formats.
 *
 *
 */
///@{                                         

/** @name YCbCr420ToYCbCr411 
 *  YCbCr420 to YCbCr411 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr420 to 2 channel 8-bit unsigned planar YCbCr411 sampling format conversion.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDstY \ref destination_planar_image_pointer.
 * \param nDstYStep \ref destination_planar_image_line_step.
 * \param pDstCbCr \ref destination_planar_image_pointer.
 * \param nDstCbCrStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420ToYCbCr411_8u_P3P2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u* pDstY, int nDstYStep, Npp8u* pDstCbCr, int nDstCbCrStep, NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned planar YCbCr420 to 3 channel 8-bit unsigned planar YCbCr411 sampling format conversion.
 *
 * \param pSrcY \ref source_planar_image_pointer.
 * \param nSrcYStep \ref source_planar_image_line_step.
 * \param pSrcCbCr \ref source_planar_image_pointer.
 * \param nSrcCbCrStep \ref source_planar_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420ToYCbCr411_8u_P2P3R(const Npp8u * pSrcY, int nSrcYStep, const Npp8u* pSrcCbCr, int nSrcCbCrStep, Npp8u* pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCbCr422ToYCbCr422 
 *  YCbCr422 to YCbCr422 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed YCbCr422 to 3 channel 8-bit unsigned planar YCbCr422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr422 to 2 channel 8-bit unsigned packed YCbCr422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422_8u_P3C2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCbCr422ToYCrCb422 
 *  YCbCr422 to YCrCb422 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed YCbCr422 to 2 channel 8-bit unsigned packed YCrCb422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToYCrCb422_8u_C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr422 to 2 channel 8-bit unsigned packed YCrCb422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToYCrCb422_8u_P3C2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCbCr422ToCbYCr422 
 *  YCbCr422 to CbYCr422 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed YCbCr422 to 2 channel 8-bit unsigned packed CbYCr422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToCbYCr422_8u_C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name CbYCr422ToYCbCr411 
 *  CbYCr422 to YCbCr411 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed CbYCr422 to 3 channel 8-bit unsigned planar YCbCr411 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCbYCr422ToYCbCr411_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCbCr422ToYCbCr420 
 *  YCbCr422 to YCbCr420 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr422 to 3 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToYCbCr420_8u_P3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst[3], int nDstStep[3], NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr422 to 2 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDstY \ref destination_planar_image_pointer.
 * \param nDstYStep \ref destination_planar_image_line_step.
 * \param pDstCbCr \ref destination_planar_image_pointer.
 * \param nDstCbCrStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToYCbCr420_8u_P3P2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDstY, int nDstYStep, Npp8u * pDstCbCr, int nDstCbCrStep, NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned packed YCbCr422 to 3 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToYCbCr420_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned packed YCbCr422 to 2 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDstY \ref destination_planar_image_pointer.
 * \param nDstYStep \ref destination_planar_image_line_step.
 * \param pDstCbCr \ref destination_planar_image_pointer.
 * \param nDstCbCrStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToYCbCr420_8u_C2P2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDstY, int nDstYStep, Npp8u * pDstCbCr, int nDstCbCrStep, NppiSize oSizeROI);

///@}

/** @name YCrCb420ToYCbCr422 
 *  YCrCb420 to YCbCr422 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCrCb420 to 3 channel 8-bit unsigned planar YCbCr422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCrCb420ToYCbCr422_8u_P3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCrCb420 to 2 channel 8-bit unsigned packed YCbCr422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCrCb420ToYCbCr422_8u_P3C2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCbCr422ToYCrCb420 
 *  YCbCr422 to YCrCb420 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed YCbCr422 to 3 channel 8-bit unsigned planar YCrCb420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToYCrCb420_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCbCr422ToYCbCr411 
 *  YCbCr422 to YCbCr411 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr422 to 3 channel 8-bit unsigned planar YCbCr411 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToYCbCr411_8u_P3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr422 to 2 channel 8-bit unsigned planar YCbCr411 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDstY \ref destination_planar_image_pointer.
 * \param nDstYStep \ref destination_planar_image_line_step.
 * \param pDstCbCr \ref destination_planar_image_pointer.
 * \param nDstCbCrStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToYCbCr411_8u_P3P2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDstY, int nDstYStep, Npp8u * pDstCbCr, int nDstCbCrStep, NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned packed YCbCr422 to 3 channel 8-bit unsigned planar YCbCr411 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToYCbCr411_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned packed YCbCr422 to 2 channel 8-bit unsigned planar YCbCr411 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDstY \ref destination_planar_image_pointer.
 * \param nDstYStep \ref destination_planar_image_line_step.
 * \param pDstCbCr \ref destination_planar_image_pointer.
 * \param nDstCbCrStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr422ToYCbCr411_8u_C2P2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDstY, int nDstYStep, Npp8u * pDstCbCr, int nDstCbCrStep, NppiSize oSizeROI);

///@}

/** @name YCrCb422ToYCbCr422 
 *  YCrCb422 to YCbCr422 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed YCrCb422 to 3 channel 8-bit unsigned planar YCbCr422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCrCb422ToYCbCr422_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCrCb422ToYCbCr420 
 *  YCrCb422 to YCbCr420 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed YCrCb422 to 3 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCrCb422ToYCbCr420_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCrCb422ToYCbCr411 
 *  YCrCb422 to YCbCr411 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed YCrCb422 to 3 channel 8-bit unsigned planar YCbCr411 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCrCb422ToYCbCr411_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name CbYCr422ToYCbCr422 
 *  CbYCr422 to YCbCr422 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed CbYCr422 to 2 channel 8-bit unsigned packed YCbCr422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCbYCr422ToYCbCr422_8u_C2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned packed CbYCr422 to 3 channel 8-bit unsigned planar YCbCr422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCbYCr422ToYCbCr422_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name CbYCr422ToYCbCr420 
 *  CbYCr422 to YCbCr420 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed CbYCr422 to 3 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCbYCr422ToYCbCr420_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned packed CbYCr422 to 2 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDstY \ref destination_planar_image_pointer.
 * \param nDstYStep \ref destination_planar_image_line_step.
 * \param pDstCbCr \ref destination_planar_image_pointer.
 * \param nDstCbCrStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCbYCr422ToYCbCr420_8u_C2P2R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDstY, int nDstYStep, Npp8u * pDstCbCr, int nDstCbCrStep, NppiSize oSizeROI);

///@}

/** @name CbYCr422ToYCrCb420 
 *  CbYCr422 to YCrCb420 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned packed CbYCr422 to 3 channel 8-bit unsigned planar YCrCb420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCbYCr422ToYCrCb420_8u_C2P3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCbCr420ToYCbCr420 
 *  YCbCr420 to YCbCr420 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr420 to 2 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDstY \ref destination_planar_image_pointer.
 * \param nDstYStep \ref destination_planar_image_line_step.
 * \param pDstCbCr \ref destination_planar_image_pointer.
 * \param nDstCbCrStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420_8u_P3P2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDstY, int nDstYStep, Npp8u * pDstCbCr, int nDstCbCrStep, NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned planar YCbCr420 to 3 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 *
 * \param pSrcY \ref source_planar_image_pointer.
 * \param nSrcYStep \ref source_planar_image_line_step.
 * \param pSrcCbCr \ref source_planar_image_pointer.
 * \param nSrcCbCrStep \ref source_planar_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420_8u_P2P3R(const Npp8u * const pSrcY, int nSrcYStep, const Npp8u * pSrcCbCr, int nSrcCbCrStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);
 
///@}

/** @name YCbCr420ToYCbCr422 
 *  YCbCr420 to YCbCr422 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr420 to 3 channel 8-bit unsigned planar YCbCr422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420ToYCbCr422_8u_P3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst[3], int nDstStep[3], NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned planar YCbCr420 to 3 channel 8-bit unsigned planar YCbCr422 sampling format conversion.
 *
 * \param pSrcY \ref source_planar_image_pointer.
 * \param nSrcYStep \ref source_planar_image_line_step.
 * \param pSrcCbCr \ref source_planar_image_pointer.
 * \param nSrcCbCrStep \ref source_planar_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420ToYCbCr422_8u_P2P3R(const Npp8u * pSrcY, int nSrcYStep, const Npp8u * pSrcCbCr, int nSrcCbCrStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned planar YCbCr420 to 2 channel 8-bit unsigned packed YCbCr422 sampling format conversion.
 *
 * \param pSrcY \ref source_planar_image_pointer.
 * \param nSrcYStep \ref source_planar_image_line_step.
 * \param pSrcCbCr \ref source_planar_image_pointer.
 * \param nSrcCbCrStep \ref source_planar_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420ToYCbCr422_8u_P2C2R(const Npp8u * pSrcY, int nSrcYStep, const Npp8u * pSrcCbCr, int nSrcCbCrStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCbCr420ToCbYCr422 
 *  YCbCr420 to CbYCr422 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned planar YCbCr420 to 2 channel 8-bit unsigned packed CbYCr422 sampling format conversion.
 *
 * \param pSrcY \ref source_planar_image_pointer.
 * \param nSrcYStep \ref source_planar_image_line_step.
 * \param pSrcCbCr \ref source_planar_image_pointer.
 * \param nSrcCbCrStep \ref source_planar_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420ToCbYCr422_8u_P2C2R(const Npp8u * pSrcY, int nSrcYStep, const Npp8u * pSrcCbCr, int nSrcCbCrStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCbCr420ToYCrCb420 
 *  YCbCr420 to YCrCb420 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned planar YCbCr420 to 3 channel 8-bit unsigned planar YCrCb420 sampling format conversion.
 *
 * \param pSrcY \ref source_planar_image_pointer.
 * \param nSrcYStep \ref source_planar_image_line_step.
 * \param pSrcCbCr \ref source_planar_image_pointer.
 * \param nSrcCbCrStep \ref source_planar_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr420ToYCrCb420_8u_P2P3R(const Npp8u * pSrcY, int nSrcYStep, const Npp8u * pSrcCbCr, int nSrcCbCrStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCrCb420ToCbYCr422 
 *  YCrCb420 to CbYCr422 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCrCb420 to 2 channel 8-bit unsigned packed CbYCr422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCrCb420ToCbYCr422_8u_P3C2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCrCb420ToYCbCr420 
 *  YCrCb420 to YCbCr420 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCrCb420 to 2 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDstY \ref destination_planar_image_pointer.
 * \param nDstYStep \ref destination_planar_image_line_step.
 * \param pDstCbCr \ref destination_planar_image_pointer.
 * \param nDstCbCrStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCrCb420ToYCbCr420_8u_P3P2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDstY, int nDstYStep, Npp8u * pDstCbCr, int nDstCbCrStep, NppiSize oSizeROI);

///@}

/** @name YCrCb420ToYCbCr411 
 *  YCrCb420 to YCbCr411 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCrCb420 to 2 channel 8-bit unsigned planar YCbCr411 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDstY \ref destination_planar_image_pointer.
 * \param nDstYStep \ref destination_planar_image_line_step.
 * \param pDstCbCr \ref destination_planar_image_pointer.
 * \param nDstCbCrStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCrCb420ToYCbCr411_8u_P3P2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDstY, int nDstYStep, Npp8u * pDstCbCr, int nDstCbCrStep, NppiSize oSizeROI);

///@}

/** @name YCbCr411ToYCbCr411 
 *  YCbCr411 to YCbCr411 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr411 to 2 channel 8-bit unsigned planar YCbCr411 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDstY \ref destination_planar_image_pointer.
 * \param nDstYStep \ref destination_planar_image_line_step.
 * \param pDstCbCr \ref destination_planar_image_pointer.
 * \param nDstCbCrStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411_8u_P3P2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDstY, int nDstYStep, Npp8u * pDstCbCr, int nDstCbCrStep, NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned planar YCbCr411 to 3 channel 8-bit unsigned planar YCbCr411 sampling format conversion.
 *
 * \param pSrcY \ref source_planar_image_pointer.
 * \param nSrcYStep \ref source_planar_image_line_step.
 * \param pSrcCbCr \ref source_planar_image_pointer.
 * \param nSrcCbCrStep \ref source_planar_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411_8u_P2P3R(const Npp8u * pSrcY, int nSrcYStep, const Npp8u * pSrcCbCr, int nSrcCbCrStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCbCr411ToYCbCr422 
 *  YCbCr411 to YCbCr422 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr411 to 3 channel 8-bit unsigned planar YCbCr422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411ToYCbCr422_8u_P3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst[3], int nDstStep[3], NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr411 to 2 channel 8-bit unsigned packed YCbCr422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411ToYCbCr422_8u_P3C2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned planar YCbCr411 to 3 channel 8-bit unsigned planar YCbCr422 sampling format conversion.
 *
 * \param pSrcY \ref source_planar_image_pointer.
 * \param nSrcYStep \ref source_planar_image_line_step.
 * \param pSrcCbCr \ref source_planar_image_pointer.
 * \param nSrcCbCrStep \ref source_planar_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411ToYCbCr422_8u_P2P3R(const Npp8u * const pSrcY, int nSrcYStep, const Npp8u * pSrcCbCr, int nSrcCbCrStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned planar YCbCr411 to 2 channel 8-bit unsigned packed YCbCr422 sampling format conversion.
 *
 * \param pSrcY \ref source_planar_image_pointer.
 * \param nSrcYStep \ref source_planar_image_line_step.
 * \param pSrcCbCr \ref source_planar_image_pointer.
 * \param nSrcCbCrStep \ref source_planar_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411ToYCbCr422_8u_P2C2R(const Npp8u * pSrcY, int nSrcYStep, const Npp8u * pSrcCbCr, int nSrcCbCrStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCbCr411ToYCrCb422 
 *  YCbCr411 to YCrCb422 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr411 to 3 channel 8-bit unsigned planar YCrCb422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411ToYCrCb422_8u_P3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst[3], int nDstStep[3], NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr411 to 2 channel 8-bit unsigned packed YCrCb422 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411ToYCrCb422_8u_P3C2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

///@}

/** @name YCbCr411ToYCbCr420 
 *  YCbCr411 to YCbCr420 sampling format conversion.
 */
///@{
/**
 * 3 channel 8-bit unsigned planar YCbCr411 to 3 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param nDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411ToYCbCr420_8u_P3R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDst[3], int nDstStep[3], NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar YCbCr411 to 2 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 * images.
 *
 * \param pSrc \ref source_planar_image_pointer_array.
 * \param rSrcStep \ref source_planar_image_line_step_array.
 * \param pDstY \ref destination_planar_image_pointer.
 * \param nDstYStep \ref destination_planar_image_line_step.
 * \param pDstCbCr \ref destination_planar_image_pointer.
 * \param nDstCbCrStep \ref destination_planar_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411ToYCbCr420_8u_P3P2R(const Npp8u * const pSrc[3], int rSrcStep[3], Npp8u * pDstY, int nDstYStep, Npp8u * pDstCbCr, int nDstCbCrStep, NppiSize oSizeROI);

/**
 * 2 channel 8-bit unsigned planar YCbCr411 to 3 channel 8-bit unsigned planar YCbCr420 sampling format conversion.
 *
 * \param pSrcY \ref source_planar_image_pointer.
 * \param nSrcYStep \ref source_planar_image_line_step.
 * \param pSrcCbCr \ref source_planar_image_pointer.
 * \param nSrcCbCrStep \ref source_planar_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411ToYCbCr420_8u_P2P3R(const Npp8u * pSrcY, int nSrcYStep, const Npp8u * pSrcCbCr, int nSrcCbCrStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

/** @name YCbCr411ToYCrCb420 
 *  YCbCr411 to YCrCb420 sampling format conversion.
 */
///@{
/**
 * 2 channel 8-bit unsigned planar YCbCr411 to 3 channel 8-bit unsigned planar YCrCb420 sampling format conversion.
 *
 * \param pSrcY \ref source_planar_image_pointer.
 * \param nSrcYStep \ref source_planar_image_line_step.
 * \param pSrcCbCr \ref source_planar_image_pointer.
 * \param nSrcCbCrStep \ref source_planar_image_line_step.
 * \param pDst \ref destination_planar_image_pointer_array.
 * \param rDstStep \ref destination_planar_image_line_step_array.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiYCbCr411ToYCrCb420_8u_P2P3R(const Npp8u * pSrcY, int nSrcYStep, const Npp8u * pSrcCbCr, int nSrcCbCrStep, Npp8u * pDst[3], int rDstStep[3], NppiSize oSizeROI);

///@}

///@} image_color_sampling_format_conversion

/** @defgroup image_color_gamma_correction Color Gamma Correction
 *
 * Routines for correcting image color gamma.
 *
 *
 */
///@{                                         

/** @name GammaFwd 
 *  Forward gamma correction.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed color not in place forward gamma correction.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiGammaFwd_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned packed color in place forward gamma correction.
 *
 * \param pSrcDst in place packed pixel image pointer.
 * \param nSrcDstStep in place packed pixel format image line step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiGammaFwd_8u_C3IR(Npp8u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed color with alpha not in place forward gamma correction.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiGammaFwd_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed color with alpha in place forward gamma correction.
 *
 * \param pSrcDst in place packed pixel format image pointer.
 * \param nSrcDstStep in place packed pixel format image line step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiGammaFwd_8u_AC4IR(Npp8u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar color not in place forward gamma correction.
 *
 * \param pSrc source planar pixel format image pointer array.
 * \param nSrcStep source planar pixel format image line step.
 * \param pDst destination planar pixel format image pointer array.
 * \param nDstStep destination planar pixel format image line step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiGammaFwd_8u_P3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar color in place forward gamma correction.
 *
 * \param pSrcDst in place planar pixel format image pointer array.
 * \param nSrcDstStep in place planar pixel format image line step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiGammaFwd_8u_IP3R(Npp8u * const pSrcDst[3], int nSrcDstStep, NppiSize oSizeROI);

///@}

/** @name GammaInv 
 *  Inverse gamma correction.
 */
///@{
/**
 * 3 channel 8-bit unsigned packed color not in place inverse gamma correction.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiGammaInv_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned packed color in place inverse gamma correction.
 *
 * \param pSrcDst in place packed pixel format image pointer.
 * \param nSrcDstStep in place packed pixel format image line step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiGammaInv_8u_C3IR(Npp8u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed color with alpha not in place inverse gamma correction.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiGammaInv_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI);

/**
 * 4 channel 8-bit unsigned packed color with alpha in place inverse gamma correction.
 *
 * \param pSrcDst in place packed pixel format image pointer.
 * \param nSrcDstStep in place packed pixel format image line step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiGammaInv_8u_AC4IR(Npp8u * pSrcDst, int nSrcDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar color not in place inverse gamma correction.
 *
 * \param pSrc source planar pixel format image pointer array.
 * \param nSrcStep source planar pixel format image line step.
 * \param pDst destination planar pixel format image pointer array.
 * \param nDstStep destination planar pixel format image line step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiGammaInv_8u_P3R(const Npp8u * const pSrc[3], int nSrcStep, Npp8u * pDst[3], int nDstStep, NppiSize oSizeROI);

/**
 * 3 channel 8-bit unsigned planar color in place inverse gamma correction.
 *
 * \param pSrcDst in place planar pixel format image pointer array.
 * \param nSrcDstStep in place planar pixel format image line step.
 * \param oSizeROI \ref roi_specification.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiGammaInv_8u_IP3R(Npp8u * const pSrcDst[3], int nSrcDstStep, NppiSize oSizeROI);

///@}

///@} image_color_gamma_correction

/** @defgroup image_complement_color_key Complement Color Key
 *
 * Routines for performing complement color key replacement.
 *
 *
 */
///@{                                         

/** @name CompColorKey 
 *  Complement color key replacement.
 */
///@{
/**
 * 1 channel 8-bit unsigned packed color complement color key replacement of source image 1 by source image 2.
 *
 * \param pSrc1 source1 packed pixel format image pointer.
 * \param nSrc1Step source1 packed pixel format image line step.
 * \param pSrc2 source2 packed pixel format image pointer.
 * \param nSrc2Step source2 packed pixel format image line step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nColorKeyConst color key constant
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCompColorKey_8u_C1R(const Npp8u * pSrc1, int nSrc1Step, const Npp8u * pSrc2, int nSrc2Step, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nColorKeyConst);

/**
 * 3 channel 8-bit unsigned packed color complement color key replacement of source image 1 by source image 2.
 *
 * \param pSrc1 source1 packed pixel format image pointer.
 * \param nSrc1Step source1 packed pixel format image line step.
 * \param pSrc2 source2 packed pixel format image pointer.
 * \param nSrc2Step source2 packed pixel format image line step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nColorKeyConst color key constant array
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCompColorKey_8u_C3R(const Npp8u * pSrc1, int nSrc1Step, const Npp8u * pSrc2, int nSrc2Step, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nColorKeyConst[3]);

/**
 * 4 channel 8-bit unsigned packed color complement color key replacement of source image 1 by source image 2.
 *
 * \param pSrc1 source1 packed pixel format image pointer.
 * \param nSrc1Step source1 packed pixel format image line step.
 * \param pSrc2 source2 packed pixel format image pointer.
 * \param nSrc2Step source2 packed pixel format image line step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nColorKeyConst color key constant array
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiCompColorKey_8u_C4R(const Npp8u * pSrc1, int nSrc1Step, const Npp8u * pSrc2, int nSrc2Step, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nColorKeyConst[4]);

/**
 * 4 channel 8-bit unsigned packed color complement color key replacement of source image 1 by source image 2 with alpha blending.
 *
 * \param pSrc1 source1 packed pixel format image pointer.
 * \param nSrc1Step source1 packed pixel format image line step.
 * \param nAlpha1 source1 image alpha opacity (0 - max channel pixel value).
 * \param pSrc2 source2 packed pixel format image pointer.
 * \param nSrc2Step source2 packed pixel format image line step.
 * \param nAlpha2 source2 image alpha opacity (0 - max channel pixel value).
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param nColorKeyConst color key constant array
 * \param nppAlphaOp NppiAlphaOp alpha compositing operation selector  (excluding premul ops).
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus nppiAlphaCompColorKey_8u_AC4R(const Npp8u * pSrc1, int nSrc1Step, Npp8u nAlpha1, const Npp8u * pSrc2, int nSrc2Step, Npp8u nAlpha2, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, Npp8u nColorKeyConst[4], NppiAlphaOp nppAlphaOp);

///@}

///@} image_complement_color_key

/** @defgroup image_color_processing Color Processing
 *
 * Routines for performing image color manipulation.
 *
 *
 */
///@{                                         

/** @name ColorTwist
 * 
 *  Perform color twist pixel processing.
 */
///@{
/**
 * 3 channel 8-bit unsigned color twist.
 * 
 * An input color twist matrix with floating-point pixel values is applied
 * within ROI.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param twist The color twist matrix with floating-point pixel values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiColorTwist32f_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, 
                         NppiSize oSizeROI, const Npp32f twist[3][4]);

/**
 * 3 channel planar 8-bit unsigned color twist.
 *
 * An input color twist matrix with floating-point pixel values is applied
 * within ROI.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param twist The color twist matrix with floating-point pixel values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiColorTwist32f_8u_P3R(const Npp8u * const * pSrc, int nSrcStep, Npp8u ** pDst, int nDstStep, 
                         NppiSize oSizeROI, const Npp32f twist[3][4]);

/**
 * 4 channel 8-bit unsigned color twist, not affecting Alpha.
 *
 * An input color twist matrix with floating-point pixel values is applied with
 * in ROI.
 * Alpha channel is the last channel and is not processed.
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param twist The color twist matrix with floating-point pixel values.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 */
NppStatus 
nppiColorTwist32f_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, 
                          NppiSize oSizeROI, const Npp32f twist[3][4]);
///@}

/** @name ColorLUT
 * 
 *  Perform image color processing using various types of color look up tables.
 */
///@{
/**
 * 8-bit unsigned look-up-table color conversion.
 *
 * The LUT is derived from a set of user defined mapping points through linear
 * interpolation. 
 *
 * >>>>>>> ATTENTION ATTENTION <<<<<<<
 *
 * NOTE: As of the 5.0 release of NPP, the pValues and pLevels pointers need to be device memory pointers.
 *
 * >>>>>>>                     <<<<<<<
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pValues Pointer to an array of user defined OUTPUT values (this is now a device memory pointer)
 * \param pLevels Pointer to an array of user defined INPUT values  (this is now a device memory pointer)
 * \param nLevels Number of user defined input/output mapping points (levels)
 * \return \ref image_data_error_codes, \ref roi_error_codes
 *        - #NPP_LUT_NUMBER_OF_LEVELS_ERROR if the number of levels is less than
 *         2.
 */
NppStatus 
nppiLUT_Linear_8u_C1R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, 
                                const Npp32s * pValues, const Npp32s * pLevels, int nLevels);

/**
 * 3 channel 8-bit unsigned look-up-table color conversion.
 * 
 * The LUT is derived from a set of user defined mapping points through linear
 * interpolation. 
 *
 * >>>>>>> ATTENTION ATTENTION <<<<<<<
 *
 * NOTE: As of the 5.0 release of NPP, the pValues and pLevels pointers need to be host memory pointers to arrays of device memory pointers.
 *
 * >>>>>>>                     <<<<<<<
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pValues Host pointer to an array of 3 device memory pointers, one per color CHANNEL, pointing to user defined OUTPUT values.
 * \param pLevels Host pointer to an array of 3 device memory pointers, one per color CHANNEL, pointing to user defined INPUT values.
 * \param nLevels Host pointer to an array of 3 user defined input/output mapping points, one per color CHANNEL.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 *        - #NPP_LUT_NUMBER_OF_LEVELS_ERROR if the number of levels is less than 2.
 */
NppStatus 
nppiLUT_Linear_8u_C3R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, 
                                  const Npp32s * pValues[3], const Npp32s * pLevels[3], int nLevels[3]);

/**
 * 4 channel 8-bit unsigned look-up-table color conversion.
 * 
 * The LUT is derived from a set of user defined mapping points through linear
 * interpolation. 
 *
 * >>>>>>> ATTENTION ATTENTION <<<<<<<
 *
 * NOTE: As of the 5.0 release of NPP, the pValues and pLevels pointers need to be host memory pointers to arrays of device memory pointers.
 *
 * >>>>>>>                     <<<<<<<
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pValues Host pointer to an array of 4 device memory pointers, one per color CHANNEL, pointing to user defined OUTPUT values.
 * \param pLevels Host pointer to an array of 4 device memory pointers, one per color CHANNEL, pointing to user defined INPUT values.
 * \param nLevels Host pointer to an array of 4 user defined input/output mapping points, one per color CHANNEL.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 *        - #NPP_LUT_NUMBER_OF_LEVELS_ERROR if the number of levels is less than 2.
 */
NppStatus 
nppiLUT_Linear_8u_C4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, 
                                  const Npp32s * pValues[4], const Npp32s * pLevels[4], int nLevels[4]);

/**
 * 4 channel 8-bit unsigned look-up-table color conversion, not affecting Alpha.
 *
 * The LUT is derived from a set of user defined mapping points through linear
 * interpolation. 
 * Alpha channel is the last channel and is not processed.
 *
 * >>>>>>> ATTENTION ATTENTION <<<<<<<
 *
 * NOTE: As of the 5.0 release of NPP, the pValues and pLevels pointers need to be host memory pointers to arrays of device memory pointers.
 *
 * >>>>>>>                     <<<<<<<
 *
 * \param pSrc \ref source_image_pointer.
 * \param nSrcStep \ref source_image_line_step.
 * \param pDst \ref destination_image_pointer.
 * \param nDstStep \ref destination_image_line_step.
 * \param oSizeROI \ref roi_specification.
 * \param pValues Host pointer to an array of 3 device memory pointers, one per color CHANNEL, pointing to user defined OUTPUT values.
 * \param pLevels Host pointer to an array of 3 device memory pointers, one per color CHANNEL, pointing to user defined INPUT values.
 * \param nLevels Host pointer to an array of 3 user defined input/output mapping points, one per color CHANNEL.
 * \return \ref image_data_error_codes, \ref roi_error_codes
 *        - #NPP_LUT_NUMBER_OF_LEVELS_ERROR if the number of levels is less than 2.
 */
NppStatus 
nppiLUT_Linear_8u_AC4R(const Npp8u * pSrc, int nSrcStep, Npp8u * pDst, int nDstStep, NppiSize oSizeROI, 
                                 const Npp32s * pValues[3], const Npp32s * pLevels[3], int nLevels[3]);
///@}

///@} image_color_processing

///@} image_color_conversion

#ifdef __cplusplus
} // extern "C"
#endif

#endif // NV_NPPI_COLOR_CONVERSION_H
