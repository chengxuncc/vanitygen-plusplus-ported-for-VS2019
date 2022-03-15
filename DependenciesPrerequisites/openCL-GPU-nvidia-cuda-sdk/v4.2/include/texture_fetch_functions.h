/*
 * Copyright 1993-2012 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO LICENSEE:
 *
 * This source code and/or documentation ("Licensed Deliverables") are
 * subject to NVIDIA intellectual property rights under U.S. and
 * international Copyright laws.
 *
 * These Licensed Deliverables contained herein is PROPRIETARY and
 * CONFIDENTIAL to NVIDIA and is being provided under the terms and
 * conditions of a form of NVIDIA software license agreement by and
 * between NVIDIA and Licensee ("License Agreement") or electronically
 * accepted by Licensee.  Notwithstanding any terms or conditions to
 * the contrary in the License Agreement, reproduction or disclosure
 * of the Licensed Deliverables to any third party without the express
 * written consent of NVIDIA is prohibited.
 *
 * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE
 * LICENSE AGREEMENT, NVIDIA MAKES NO REPRESENTATION ABOUT THE
 * SUITABILITY OF THESE LICENSED DELIVERABLES FOR ANY PURPOSE.  IT IS
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
 * C.F.R. 12.212 (SEPT 1995) and is provided to the U.S. Government
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

#if !defined(__TEXTURE_FETCH_FUNCTIONS_H__)
#define __TEXTURE_FETCH_FUNCTIONS_H__

#if defined(__cplusplus) && defined(__CUDACC__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include "builtin_types.h"
#include "cuda_texture_types.h"
#include "host_defines.h"
#include "texture_types.h"
#include "vector_functions.h"
#include "vector_types.h"

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

template<class T, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__  uint4 __utexfetchi(texture<T, cudaTextureType1D, readMode> t, int4 i);
template<class T, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__   int4 __itexfetchi(texture<T, cudaTextureType1D, readMode> t, int4 i);
template<class T, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__ float4 __ftexfetchi(texture<T, cudaTextureType1D, readMode> t, int4 i);
template<class T, int texType, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__  uint4 __utexfetch(texture<T, texType, readMode> t, float4 i, int d = texType);
template<class T, int texType, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__   int4 __itexfetch(texture<T, texType, readMode> t, float4 i, int d = texType);
template<class T, int texType, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__ float4 __ftexfetch(texture<T, texType, readMode> t, float4 i, int d = texType);
template<class T, int texType, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__  uint4 __utexfetchc(texture<T, texType, readMode> t, float4 i);
template<class T, int texType, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__   int4 __itexfetchc(texture<T, texType, readMode> t, float4 i);
template<class T, int texType, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__ float4 __ftexfetchc(texture<T, texType, readMode> t, float4 i);
template<class T, int texType, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__  uint4 __utexfetchl(texture<T, texType, readMode> t, float4 i, int l, int d = (texType & 0xF));
template<class T, int texType, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__   int4 __itexfetchl(texture<T, texType, readMode> t, float4 i, int l, int d = (texType & 0xF));
template<class T, int texType, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__ float4 __ftexfetchl(texture<T, texType, readMode> t, float4 i, int l, int d = (texType & 0xF));
template<class T, int texType, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__  uint4 __utexfetchlc(texture<T, texType, readMode> t, float4 i, int l);
template<class T, int texType, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__   int4 __itexfetchlc(texture<T, texType, readMode> t, float4 i, int l);
template<class T, int texType, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__ float4 __ftexfetchlc(texture<T, texType, readMode> t, float4 i, int l);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ char tex1Dfetch(texture<char, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v  = __itexfetchi(t, make_int4(x, 0, 0, 0));
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */

  return (char)v.x;
}

static __inline__ __device__ signed char tex1Dfetch(texture<signed char, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return (signed char)v.x;
}

static __inline__ __device__ unsigned char tex1Dfetch(texture<unsigned char, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return (unsigned char)v.x;
}

static __inline__ __device__ char1 tex1Dfetch(texture<char1, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_char1(v.x);
}

static __inline__ __device__ uchar1 tex1Dfetch(texture<uchar1, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_uchar1(v.x);
}

static __inline__ __device__ char2 tex1Dfetch(texture<char2, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_char2(v.x, v.y);
}

static __inline__ __device__ uchar2 tex1Dfetch(texture<uchar2, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_uchar2(v.x, v.y);
}

static __inline__ __device__ char4 tex1Dfetch(texture<char4, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_char4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uchar4 tex1Dfetch(texture<uchar4, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_uchar4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ short tex1Dfetch(texture<short, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return (short)v.x;
}

static __inline__ __device__ unsigned short tex1Dfetch(texture<unsigned short, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return (unsigned short)v.x;
}

static __inline__ __device__ short1 tex1Dfetch(texture<short1, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_short1(v.x);
}

static __inline__ __device__ ushort1 tex1Dfetch(texture<ushort1, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_ushort1(v.x);
}

static __inline__ __device__ short2 tex1Dfetch(texture<short2, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_short2(v.x, v.y);
}

static __inline__ __device__ ushort2 tex1Dfetch(texture<ushort2, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_ushort2(v.x, v.y);
}

static __inline__ __device__ short4 tex1Dfetch(texture<short4, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_short4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ushort4 tex1Dfetch(texture<ushort4, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_ushort4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int tex1Dfetch(texture<int, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return (int)v.x;
}

static __inline__ __device__ unsigned int tex1Dfetch(texture<unsigned int, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return (unsigned int)v.x;
}

static __inline__ __device__ int1 tex1Dfetch(texture<int1, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_int1(v.x);
}

static __inline__ __device__ uint1 tex1Dfetch(texture<uint1, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_uint1(v.x);
}

static __inline__ __device__ int2 tex1Dfetch(texture<int2, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_int2(v.x, v.y);
}

static __inline__ __device__ uint2 tex1Dfetch(texture<uint2, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_uint2(v.x, v.y);
}

static __inline__ __device__ int4 tex1Dfetch(texture<int4, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_int4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uint4 tex1Dfetch(texture<uint4, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_uint4(v.x, v.y, v.z, v.w);
}

#if !defined(__LP64__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ long tex1Dfetch(texture<long, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return (long)v.x;
}

static __inline__ __device__ unsigned long tex1Dfetch(texture<unsigned long, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return (unsigned long)v.x;
}

static __inline__ __device__ long1 tex1Dfetch(texture<long1, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_long1(v.x);
}

static __inline__ __device__ ulong1 tex1Dfetch(texture<ulong1, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_ulong1(v.x);
}

static __inline__ __device__ long2 tex1Dfetch(texture<long2, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_long2(v.x, v.y);
}

static __inline__ __device__ ulong2 tex1Dfetch(texture<ulong2, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_ulong2(v.x, v.y);
}

static __inline__ __device__ long4 tex1Dfetch(texture<long4, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_long4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ulong4 tex1Dfetch(texture<ulong4, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_ulong4(v.x, v.y, v.z, v.w);
}

#endif /* !__LP64__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1Dfetch(texture<float, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  float4 v = __ftexfetchi(t, make_int4(x, 0, 0, 0));

  return v.x;
}

static __inline__ __device__ float1 tex1Dfetch(texture<float1, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  float4 v = __ftexfetchi(t, make_int4(x, 0, 0, 0));

  return make_float1(v.x);
}

static __inline__ __device__ float2 tex1Dfetch(texture<float2, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  float4 v = __ftexfetchi(t, make_int4(x, 0, 0, 0));

  return make_float2(v.x, v.y);
}

static __inline__ __device__ float4 tex1Dfetch(texture<float4, cudaTextureType1D, cudaReadModeElementType> t, int x)
{
  float4 v = __ftexfetchi(t, make_int4(x, 0, 0, 0));

  return make_float4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1Dfetch(texture<char, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1Dfetch(texture<signed char, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1Dfetch(texture<unsigned char, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex1Dfetch(texture<char1, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex1Dfetch(texture<uchar1, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex1Dfetch(texture<char2, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex1Dfetch(texture<uchar2, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex1Dfetch(texture<char4, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex1Dfetch(texture<uchar4, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1Dfetch(texture<short, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1Dfetch(texture<unsigned short, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex1Dfetch(texture<short1, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex1Dfetch(texture<ushort1, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex1Dfetch(texture<short2, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex1Dfetch(texture<ushort2, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex1Dfetch(texture<short4, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex1Dfetch(texture<ushort4, cudaTextureType1D, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v   = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ char tex1D(texture<char, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v  = __itexfetch(t, make_float4(x, 0, 0, 0));
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */

  return (char)v.x;
}

static __inline__ __device__ signed char tex1D(texture<signed char, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return (signed char)v.x;
}

static __inline__ __device__ unsigned char tex1D(texture<unsigned char, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return (unsigned char)v.x;
}

static __inline__ __device__ char1 tex1D(texture<char1, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_char1(v.x);
}

static __inline__ __device__ uchar1 tex1D(texture<uchar1, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_uchar1(v.x);
}

static __inline__ __device__ char2 tex1D(texture<char2, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_char2(v.x, v.y);
}

static __inline__ __device__ uchar2 tex1D(texture<uchar2, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_uchar2(v.x, v.y);
}

static __inline__ __device__ char4 tex1D(texture<char4, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_char4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uchar4 tex1D(texture<uchar4, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_uchar4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ short tex1D(texture<short, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return (short)v.x;
}

static __inline__ __device__ unsigned short tex1D(texture<unsigned short, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return (unsigned short)v.x;
}

static __inline__ __device__ short1 tex1D(texture<short1, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_short1(v.x);
}

static __inline__ __device__ ushort1 tex1D(texture<ushort1, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_ushort1(v.x);
}

static __inline__ __device__ short2 tex1D(texture<short2, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_short2(v.x, v.y);
}

static __inline__ __device__ ushort2 tex1D(texture<ushort2, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_ushort2(v.x, v.y);
}

static __inline__ __device__ short4 tex1D(texture<short4, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_short4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ushort4 tex1D(texture<ushort4, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_ushort4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int tex1D(texture<int, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return (int)v.x;
}

static __inline__ __device__ unsigned int tex1D(texture<unsigned int, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return (unsigned int)v.x;
}

static __inline__ __device__ int1 tex1D(texture<int1, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_int1(v.x);
}

static __inline__ __device__ uint1 tex1D(texture<uint1, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_uint1(v.x);
}

static __inline__ __device__ int2 tex1D(texture<int2, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_int2(v.x, v.y);
}

static __inline__ __device__ uint2 tex1D(texture<uint2, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_uint2(v.x, v.y);
}

static __inline__ __device__ int4 tex1D(texture<int4, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_int4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uint4 tex1D(texture<uint4, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_uint4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#if !defined(__LP64__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ long tex1D(texture<long, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return (long)v.x;
}

static __inline__ __device__ unsigned long tex1D(texture<unsigned long, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return (unsigned long)v.x;
}

static __inline__ __device__ long1 tex1D(texture<long1, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_long1(v.x);
}

static __inline__ __device__ ulong1 tex1D(texture<ulong1, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_ulong1(v.x);
}

static __inline__ __device__ long2 tex1D(texture<long2, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_long2(v.x, v.y);
}

static __inline__ __device__ ulong2 tex1D(texture<ulong2, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_ulong2(v.x, v.y);
}

static __inline__ __device__ long4 tex1D(texture<long4, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_long4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ulong4 tex1D(texture<ulong4, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_ulong4(v.x, v.y, v.z, v.w);
}

#endif /* !__LP64__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1D(texture<float, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  float4 v = __ftexfetch(t, make_float4(x, 0, 0, 0));

  return v.x;
}

static __inline__ __device__ float1 tex1D(texture<float1, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  float4 v = __ftexfetch(t, make_float4(x, 0, 0, 0));

  return make_float1(v.x);
}

static __inline__ __device__ float2 tex1D(texture<float2, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  float4 v = __ftexfetch(t, make_float4(x, 0, 0, 0));

  return make_float2(v.x, v.y);
}

static __inline__ __device__ float4 tex1D(texture<float4, cudaTextureType1D, cudaReadModeElementType> t, float x)
{
  float4 v = __ftexfetch(t, make_float4(x, 0, 0, 0));

  return make_float4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1D(texture<char, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1D(texture<signed char, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1D(texture<unsigned char, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex1D(texture<char1, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex1D(texture<uchar1, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex1D(texture<char2, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex1D(texture<uchar2, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex1D(texture<char4, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex1D(texture<uchar4, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1D(texture<short, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1D(texture<unsigned short, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex1D(texture<short1, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex1D(texture<ushort1, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex1D(texture<short2, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex1D(texture<ushort2, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex1D(texture<short4, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex1D(texture<ushort4, cudaTextureType1D, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v   = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
* 2D Texture functions                                                         *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ char tex2D(texture<char, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v  = __itexfetch(t, make_float4(x, y, 0, 0));
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */

  return (char)v.x;
}

static __inline__ __device__ signed char tex2D(texture<signed char, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return (signed char)v.x;
}

static __inline__ __device__ unsigned char tex2D(texture<unsigned char, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return (unsigned char)v.x;
}

static __inline__ __device__ char1 tex2D(texture<char1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_char1(v.x);
}

static __inline__ __device__ uchar1 tex2D(texture<uchar1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_uchar1(v.x);
}

static __inline__ __device__ char2 tex2D(texture<char2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_char2(v.x, v.y);
}

static __inline__ __device__ uchar2 tex2D(texture<uchar2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_uchar2(v.x, v.y);
}

static __inline__ __device__ char4 tex2D(texture<char4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_char4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uchar4 tex2D(texture<uchar4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_uchar4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ short tex2D(texture<short, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return (short)v.x;
}

static __inline__ __device__ unsigned short tex2D(texture<unsigned short, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return (unsigned short)v.x;
}

static __inline__ __device__ short1 tex2D(texture<short1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_short1(v.x);
}

static __inline__ __device__ ushort1 tex2D(texture<ushort1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_ushort1(v.x);
}

static __inline__ __device__ short2 tex2D(texture<short2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_short2(v.x, v.y);
}

static __inline__ __device__ ushort2 tex2D(texture<ushort2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_ushort2(v.x, v.y);
}

static __inline__ __device__ short4 tex2D(texture<short4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_short4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ushort4 tex2D(texture<ushort4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_ushort4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int tex2D(texture<int, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return (int)v.x;
}

static __inline__ __device__ unsigned int tex2D(texture<unsigned int, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return (unsigned int)v.x;
}

static __inline__ __device__ int1 tex2D(texture<int1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_int1(v.x);
}

static __inline__ __device__ uint1 tex2D(texture<uint1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_uint1(v.x);
}

static __inline__ __device__ int2 tex2D(texture<int2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_int2(v.x, v.y);
}

static __inline__ __device__ uint2 tex2D(texture<uint2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_uint2(v.x, v.y);
}

static __inline__ __device__ int4 tex2D(texture<int4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_int4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uint4 tex2D(texture<uint4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_uint4(v.x, v.y, v.z, v.w);
}

#if !defined(__LP64__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ long tex2D(texture<long, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return (long)v.x;
}

static __inline__ __device__ unsigned long tex2D(texture<unsigned long, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return (unsigned long)v.x;
}

static __inline__ __device__ long1 tex2D(texture<long1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_long1(v.x);
}

static __inline__ __device__ ulong1 tex2D(texture<ulong1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_ulong1(v.x);
}

static __inline__ __device__ long2 tex2D(texture<long2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_long2(v.x, v.y);
}

static __inline__ __device__ ulong2 tex2D(texture<ulong2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_ulong2(v.x, v.y);
}

static __inline__ __device__ long4 tex2D(texture<long4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_long4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ulong4 tex2D(texture<ulong4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_ulong4(v.x, v.y, v.z, v.w);
}

#endif /* !__LP64__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex2D(texture<float, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  float4 v = __ftexfetch(t, make_float4(x, y, 0, 0));

  return v.x;
}

static __inline__ __device__ float1 tex2D(texture<float1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  float4 v = __ftexfetch(t, make_float4(x, y, 0, 0));

  return make_float1(v.x);
}

static __inline__ __device__ float2 tex2D(texture<float2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  float4 v = __ftexfetch(t, make_float4(x, y, 0, 0));

  return make_float2(v.x, v.y);
}

static __inline__ __device__ float4 tex2D(texture<float4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y)
{
  float4 v = __ftexfetch(t, make_float4(x, y, 0, 0));

  return make_float4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex2D(texture<char, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex2D(texture<signed char, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex2D(texture<unsigned char, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex2D(texture<char1, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex2D(texture<uchar1, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex2D(texture<char2, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex2D(texture<uchar2, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex2D(texture<char4, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex2D(texture<uchar4, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex2D(texture<short, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex2D(texture<unsigned short, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex2D(texture<short1, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex2D(texture<ushort1, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex2D(texture<short2, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex2D(texture<ushort2, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex2D(texture<short4, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex2D(texture<ushort4, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v   = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
* 1D Layered Texture functions                                                 *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ char tex1DLayered(texture<char, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v  = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */

  return (char)v.x;
}

static __inline__ __device__ signed char tex1DLayered(texture<signed char, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return (signed char)v.x;
}

static __inline__ __device__ unsigned char tex1DLayered(texture<unsigned char, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return (unsigned char)v.x;
}

static __inline__ __device__ char1 tex1DLayered(texture<char1, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_char1(v.x);
}

static __inline__ __device__ uchar1 tex1DLayered(texture<uchar1, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_uchar1(v.x);
}

static __inline__ __device__ char2 tex1DLayered(texture<char2, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_char2(v.x, v.y);
}

static __inline__ __device__ uchar2 tex1DLayered(texture<uchar2, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_uchar2(v.x, v.y);
}

static __inline__ __device__ char4 tex1DLayered(texture<char4, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_char4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uchar4 tex1DLayered(texture<uchar4, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_uchar4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ short tex1DLayered(texture<short, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return (short)v.x;
}

static __inline__ __device__ unsigned short tex1DLayered(texture<unsigned short, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return (unsigned short)v.x;
}

static __inline__ __device__ short1 tex1DLayered(texture<short1, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_short1(v.x);
}

static __inline__ __device__ ushort1 tex1DLayered(texture<ushort1, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_ushort1(v.x);
}

static __inline__ __device__ short2 tex1DLayered(texture<short2, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_short2(v.x, v.y);
}

static __inline__ __device__ ushort2 tex1DLayered(texture<ushort2, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_ushort2(v.x, v.y);
}

static __inline__ __device__ short4 tex1DLayered(texture<short4, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_short4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ushort4 tex1DLayered(texture<ushort4, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_ushort4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int tex1DLayered(texture<int, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return (int)v.x;
}

static __inline__ __device__ unsigned int tex1DLayered(texture<unsigned int, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return (unsigned int)v.x;
}

static __inline__ __device__ int1 tex1DLayered(texture<int1, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_int1(v.x);
}

static __inline__ __device__ uint1 tex1DLayered(texture<uint1, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_uint1(v.x);
}

static __inline__ __device__ int2 tex1DLayered(texture<int2, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_int2(v.x, v.y);
}

static __inline__ __device__ uint2 tex1DLayered(texture<uint2, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_uint2(v.x, v.y);
}

static __inline__ __device__ int4 tex1DLayered(texture<int4, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_int4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uint4 tex1DLayered(texture<uint4, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_uint4(v.x, v.y, v.z, v.w);
}

#if !defined(__LP64__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ long tex1DLayered(texture<long, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return (long)v.x;
}

static __inline__ __device__ unsigned long tex1DLayered(texture<unsigned long, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return (unsigned long)v.x;
}

static __inline__ __device__ long1 tex1DLayered(texture<long1, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_long1(v.x);
}

static __inline__ __device__ ulong1 tex1DLayered(texture<ulong1, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_ulong1(v.x);
}

static __inline__ __device__ long2 tex1DLayered(texture<long2, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_long2(v.x, v.y);
}

static __inline__ __device__ ulong2 tex1DLayered(texture<ulong2, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_ulong2(v.x, v.y);
}

static __inline__ __device__ long4 tex1DLayered(texture<long4, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_long4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ulong4 tex1DLayered(texture<ulong4, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_ulong4(v.x, v.y, v.z, v.w);
}

#endif /* !__LP64__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1DLayered(texture<float, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  float4 v = __ftexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return v.x;
}

static __inline__ __device__ float1 tex1DLayered(texture<float1, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  float4 v = __ftexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_float1(v.x);
}

static __inline__ __device__ float2 tex1DLayered(texture<float2, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  float4 v = __ftexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_float2(v.x, v.y);
}

static __inline__ __device__ float4 tex1DLayered(texture<float4, cudaTextureType1DLayered, cudaReadModeElementType> t, float x, int layer)
{
  float4 v = __ftexfetchl(t, make_float4(x, 0, 0, 0), layer);

  return make_float4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1DLayered(texture<char, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v  = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v   = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1DLayered(texture<signed char, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1DLayered(texture<unsigned char, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex1DLayered(texture<char1, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex1DLayered(texture<uchar1, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex1DLayered(texture<char2, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex1DLayered(texture<uchar2, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex1DLayered(texture<char4, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex1DLayered(texture<uchar4, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1DLayered(texture<short, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1DLayered(texture<unsigned short, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex1DLayered(texture<short1, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex1DLayered(texture<ushort1, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex1DLayered(texture<short2, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex1DLayered(texture<ushort2, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex1DLayered(texture<short4, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex1DLayered(texture<ushort4, cudaTextureType1DLayered, cudaReadModeNormalizedFloat> t, float x, int layer)
{
  uint4 v   = __utexfetchl(t, make_float4(x, 0, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
* 2D Layered Texture functions                                                 *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ char tex2DLayered(texture<char, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v  = __itexfetchl(t, make_float4(x, y, 0, 0), layer);
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */

  return (char)v.x;
}

static __inline__ __device__ signed char tex2DLayered(texture<signed char, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return (signed char)v.x;
}

static __inline__ __device__ unsigned char tex2DLayered(texture<unsigned char, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return (unsigned char)v.x;
}

static __inline__ __device__ char1 tex2DLayered(texture<char1, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_char1(v.x);
}

static __inline__ __device__ uchar1 tex2DLayered(texture<uchar1, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_uchar1(v.x);
}

static __inline__ __device__ char2 tex2DLayered(texture<char2, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_char2(v.x, v.y);
}

static __inline__ __device__ uchar2 tex2DLayered(texture<uchar2, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_uchar2(v.x, v.y);
}

static __inline__ __device__ char4 tex2DLayered(texture<char4, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_char4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uchar4 tex2DLayered(texture<uchar4, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_uchar4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ short tex2DLayered(texture<short, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return (short)v.x;
}

static __inline__ __device__ unsigned short tex2DLayered(texture<unsigned short, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return (unsigned short)v.x;
}

static __inline__ __device__ short1 tex2DLayered(texture<short1, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_short1(v.x);
}

static __inline__ __device__ ushort1 tex2DLayered(texture<ushort1, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_ushort1(v.x);
}

static __inline__ __device__ short2 tex2DLayered(texture<short2, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_short2(v.x, v.y);
}

static __inline__ __device__ ushort2 tex2DLayered(texture<ushort2, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_ushort2(v.x, v.y);
}

static __inline__ __device__ short4 tex2DLayered(texture<short4, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_short4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ushort4 tex2DLayered(texture<ushort4, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_ushort4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int tex2DLayered(texture<int, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return (int)v.x;
}

static __inline__ __device__ unsigned int tex2DLayered(texture<unsigned int, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return (unsigned int)v.x;
}

static __inline__ __device__ int1 tex2DLayered(texture<int1, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_int1(v.x);
}

static __inline__ __device__ uint1 tex2DLayered(texture<uint1, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_uint1(v.x);
}

static __inline__ __device__ int2 tex2DLayered(texture<int2, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_int2(v.x, v.y);
}

static __inline__ __device__ uint2 tex2DLayered(texture<uint2, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_uint2(v.x, v.y);
}

static __inline__ __device__ int4 tex2DLayered(texture<int4, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_int4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uint4 tex2DLayered(texture<uint4, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_uint4(v.x, v.y, v.z, v.w);
}

#if !defined(__LP64__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ long tex2DLayered(texture<long, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return (long)v.x;
}

static __inline__ __device__ unsigned long tex2DLayered(texture<unsigned long, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return (unsigned long)v.x;
}

static __inline__ __device__ long1 tex2DLayered(texture<long1, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_long1(v.x);
}

static __inline__ __device__ ulong1 tex2DLayered(texture<ulong1, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_ulong1(v.x);
}

static __inline__ __device__ long2 tex2DLayered(texture<long2, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_long2(v.x, v.y);
}

static __inline__ __device__ ulong2 tex2DLayered(texture<ulong2, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_ulong2(v.x, v.y);
}

static __inline__ __device__ long4 tex2DLayered(texture<long4, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  int4 v = __itexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_long4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ulong4 tex2DLayered(texture<ulong4, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  uint4 v = __utexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_ulong4(v.x, v.y, v.z, v.w);
}

#endif /* !__LP64__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex2DLayered(texture<float, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  float4 v = __ftexfetchl(t, make_float4(x, y, 0, 0), layer);

  return v.x;
}

static __inline__ __device__ float1 tex2DLayered(texture<float1, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  float4 v = __ftexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_float1(v.x);
}

static __inline__ __device__ float2 tex2DLayered(texture<float2, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  float4 v = __ftexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_float2(v.x, v.y);
}

static __inline__ __device__ float4 tex2DLayered(texture<float4, cudaTextureType2DLayered, cudaReadModeElementType> t, float x, float y, int layer)
{
  float4 v = __ftexfetchl(t, make_float4(x, y, 0, 0), layer);

  return make_float4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex2DLayered(texture<char, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v  = __utexfetchl(t, make_float4(x, y, 0, 0), layer);
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v   = __itexfetchl(t, make_float4(x, y, 0, 0), layer);
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex2DLayered(texture<signed char, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex2DLayered(texture<unsigned char, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex2DLayered(texture<char1, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex2DLayered(texture<uchar1, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex2DLayered(texture<char2, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex2DLayered(texture<uchar2, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex2DLayered(texture<char4, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex2DLayered(texture<uchar4, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex2DLayered(texture<short, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex2DLayered(texture<unsigned short, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex2DLayered(texture<short1, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex2DLayered(texture<ushort1, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex2DLayered(texture<short2, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex2DLayered(texture<ushort2, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  uint4 v  = __utexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex2DLayered(texture<short4, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  int4 v   = __itexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex2DLayered(texture<ushort4, cudaTextureType2DLayered, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
{
  uint4 v   = __utexfetchl(t, make_float4(x, y, 0, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
* 3D Texture functions                                                         *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ char tex3D(texture<char, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v  = __itexfetch(t, make_float4(x, y, z, 0));
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */

  return (char)v.x;
}

static __inline__ __device__ signed char tex3D(texture<signed char, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return (signed char)v.x;
}

static __inline__ __device__ unsigned char tex3D(texture<unsigned char, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return (unsigned char)v.x;
}

static __inline__ __device__ char1 tex3D(texture<char1, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_char1(v.x);
}

static __inline__ __device__ uchar1 tex3D(texture<uchar1, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_uchar1(v.x);
}

static __inline__ __device__ char2 tex3D(texture<char2, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_char2(v.x, v.y);
}

static __inline__ __device__ uchar2 tex3D(texture<uchar2, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_uchar2(v.x, v.y);
}

static __inline__ __device__ char4 tex3D(texture<char4, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_char4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uchar4 tex3D(texture<uchar4, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_uchar4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ short tex3D(texture<short, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return (short)v.x;
}

static __inline__ __device__ unsigned short tex3D(texture<unsigned short, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return (unsigned short)v.x;
}

static __inline__ __device__ short1 tex3D(texture<short1, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_short1(v.x);
}

static __inline__ __device__ ushort1 tex3D(texture<ushort1, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_ushort1(v.x);
}

static __inline__ __device__ short2 tex3D(texture<short2, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_short2(v.x, v.y);
}

static __inline__ __device__ ushort2 tex3D(texture<ushort2, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_ushort2(v.x, v.y);
}

static __inline__ __device__ short4 tex3D(texture<short4, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_short4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ushort4 tex3D(texture<ushort4, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_ushort4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int tex3D(texture<int, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return (int)v.x;
}

static __inline__ __device__ unsigned int tex3D(texture<unsigned int, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return (unsigned int)v.x;
}

static __inline__ __device__ int1 tex3D(texture<int1, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_int1(v.x);
}

static __inline__ __device__ uint1 tex3D(texture<uint1, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_uint1(v.x);
}

static __inline__ __device__ int2 tex3D(texture<int2, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_int2(v.x, v.y);
}

static __inline__ __device__ uint2 tex3D(texture<uint2, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_uint2(v.x, v.y);
}

static __inline__ __device__ int4 tex3D(texture<int4, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_int4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uint4 tex3D(texture<uint4, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_uint4(v.x, v.y, v.z, v.w);
}

#if !defined(__LP64__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ long tex3D(texture<long, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return (long)v.x;
}

static __inline__ __device__ unsigned long tex3D(texture<unsigned long, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return (unsigned long)v.x;
}

static __inline__ __device__ long1 tex3D(texture<long1, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_long1(v.x);
}

static __inline__ __device__ ulong1 tex3D(texture<ulong1, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_ulong1(v.x);
}

static __inline__ __device__ long2 tex3D(texture<long2, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_long2(v.x, v.y);
}

static __inline__ __device__ ulong2 tex3D(texture<ulong2, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_ulong2(v.x, v.y);
}

static __inline__ __device__ long4 tex3D(texture<long4, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_long4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ulong4 tex3D(texture<ulong4, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_ulong4(v.x, v.y, v.z, v.w);
}

#endif /* !__LP64__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex3D(texture<float, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  float4 v = __ftexfetch(t, make_float4(x, y, z, 0));

  return v.x;
}

static __inline__ __device__ float1 tex3D(texture<float1, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  float4 v = __ftexfetch(t, make_float4(x, y, z, 0));

  return make_float1(v.x);
}

static __inline__ __device__ float2 tex3D(texture<float2, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  float4 v = __ftexfetch(t, make_float4(x, y, z, 0));

  return make_float2(v.x, v.y);
}

static __inline__ __device__ float4 tex3D(texture<float4, cudaTextureType3D, cudaReadModeElementType> t, float x, float y, float z)
{
  float4 v = __ftexfetch(t, make_float4(x, y, z, 0));

  return make_float4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex3D(texture<char, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex3D(texture<signed char, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex3D(texture<unsigned char, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex3D(texture<char1, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex3D(texture<uchar1, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex3D(texture<char2, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex3D(texture<uchar2, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex3D(texture<char4, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex3D(texture<uchar4, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex3D(texture<short, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex3D(texture<unsigned short, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex3D(texture<short1, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex3D(texture<ushort1, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex3D(texture<short2, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex3D(texture<ushort2, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex3D(texture<short4, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex3D(texture<ushort4, cudaTextureType3D, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v   = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
* Cubemap Texture functions                                                    *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ char texCubemap(texture<char, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v  = __itexfetchc(t, make_float4(x, y, z, 0));
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */

  return (char)v.x;
}

static __inline__ __device__ signed char texCubemap(texture<signed char, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return (signed char)v.x;
}

static __inline__ __device__ unsigned char texCubemap(texture<unsigned char, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return (unsigned char)v.x;
}

static __inline__ __device__ char1 texCubemap(texture<char1, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return make_char1(v.x);
}

static __inline__ __device__ uchar1 texCubemap(texture<uchar1, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return make_uchar1(v.x);
}

static __inline__ __device__ char2 texCubemap(texture<char2, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return make_char2(v.x, v.y);
}

static __inline__ __device__ uchar2 texCubemap(texture<uchar2, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return make_uchar2(v.x, v.y);
}

static __inline__ __device__ char4 texCubemap(texture<char4, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return make_char4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uchar4 texCubemap(texture<uchar4, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return make_uchar4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ short texCubemap(texture<short, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return (short)v.x;
}

static __inline__ __device__ unsigned short texCubemap(texture<unsigned short, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return (unsigned short)v.x;
}

static __inline__ __device__ short1 texCubemap(texture<short1, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return make_short1(v.x);
}

static __inline__ __device__ ushort1 texCubemap(texture<ushort1, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return make_ushort1(v.x);
}

static __inline__ __device__ short2 texCubemap(texture<short2, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return make_short2(v.x, v.y);
}

static __inline__ __device__ ushort2 texCubemap(texture<ushort2, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return make_ushort2(v.x, v.y);
}

static __inline__ __device__ short4 texCubemap(texture<short4, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return make_short4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ushort4 texCubemap(texture<ushort4, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return make_ushort4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int texCubemap(texture<int, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return (int)v.x;
}

static __inline__ __device__ unsigned int texCubemap(texture<unsigned int, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return (unsigned int)v.x;
}

static __inline__ __device__ int1 texCubemap(texture<int1, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return make_int1(v.x);
}

static __inline__ __device__ uint1 texCubemap(texture<uint1, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return make_uint1(v.x);
}

static __inline__ __device__ int2 texCubemap(texture<int2, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return make_int2(v.x, v.y);
}

static __inline__ __device__ uint2 texCubemap(texture<uint2, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return make_uint2(v.x, v.y);
}

static __inline__ __device__ int4 texCubemap(texture<int4, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return make_int4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uint4 texCubemap(texture<uint4, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return make_uint4(v.x, v.y, v.z, v.w);
}

#if !defined(__LP64__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ long texCubemap(texture<long, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return (long)v.x;
}

static __inline__ __device__ unsigned long texCubemap(texture<unsigned long, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return (unsigned long)v.x;
}

static __inline__ __device__ long1 texCubemap(texture<long1, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return make_long1(v.x);
}

static __inline__ __device__ ulong1 texCubemap(texture<ulong1, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return make_ulong1(v.x);
}

static __inline__ __device__ long2 texCubemap(texture<long2, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return make_long2(v.x, v.y);
}

static __inline__ __device__ ulong2 texCubemap(texture<ulong2, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return make_ulong2(v.x, v.y);
}

static __inline__ __device__ long4 texCubemap(texture<long4, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetchc(t, make_float4(x, y, z, 0));

  return make_long4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ulong4 texCubemap(texture<ulong4, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetchc(t, make_float4(x, y, z, 0));

  return make_ulong4(v.x, v.y, v.z, v.w);
}

#endif /* !__LP64__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float texCubemap(texture<float, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  float4 v = __ftexfetchc(t, make_float4(x, y, z, 0));

  return v.x;
}

static __inline__ __device__ float1 texCubemap(texture<float1, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  float4 v = __ftexfetchc(t, make_float4(x, y, z, 0));

  return make_float1(v.x);
}

static __inline__ __device__ float2 texCubemap(texture<float2, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  float4 v = __ftexfetchc(t, make_float4(x, y, z, 0));

  return make_float2(v.x, v.y);
}

static __inline__ __device__ float4 texCubemap(texture<float4, cudaTextureTypeCubemap, cudaReadModeElementType> t, float x, float y, float z)
{
  float4 v = __ftexfetchc(t, make_float4(x, y, z, 0));

  return make_float4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float texCubemap(texture<char, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v  = __utexfetchc(t, make_float4(x, y, z, 0));
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v   = __itexfetchc(t, make_float4(x, y, z, 0));
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float texCubemap(texture<signed char, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float texCubemap(texture<unsigned char, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 texCubemap(texture<char1, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 texCubemap(texture<uchar1, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 texCubemap(texture<char2, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 texCubemap(texture<uchar2, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 texCubemap(texture<char4, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 texCubemap(texture<uchar4, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float texCubemap(texture<short, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float texCubemap(texture<unsigned short, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 texCubemap(texture<short1, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 texCubemap(texture<ushort1, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 texCubemap(texture<short2, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 texCubemap(texture<ushort2, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 texCubemap(texture<short4, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 texCubemap(texture<ushort4, cudaTextureTypeCubemap, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v   = __utexfetchc(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
* Cubemap Layered Texture functions                                            *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ char texCubemapLayered(texture<char, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v  = __itexfetchlc(t, make_float4(x, y, z, 0), layer);
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */

  return (char)v.x;
}

static __inline__ __device__ signed char texCubemapLayered(texture<signed char, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return (signed char)v.x;
}

static __inline__ __device__ unsigned char texCubemapLayered(texture<unsigned char, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return (unsigned char)v.x;
}

static __inline__ __device__ char1 texCubemapLayered(texture<char1, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_char1(v.x);
}

static __inline__ __device__ uchar1 texCubemapLayered(texture<uchar1, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_uchar1(v.x);
}

static __inline__ __device__ char2 texCubemapLayered(texture<char2, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_char2(v.x, v.y);
}

static __inline__ __device__ uchar2 texCubemapLayered(texture<uchar2, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_uchar2(v.x, v.y);
}

static __inline__ __device__ char4 texCubemapLayered(texture<char4, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_char4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uchar4 texCubemapLayered(texture<uchar4, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_uchar4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ short texCubemapLayered(texture<short, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return (short)v.x;
}

static __inline__ __device__ unsigned short texCubemapLayered(texture<unsigned short, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return (unsigned short)v.x;
}

static __inline__ __device__ short1 texCubemapLayered(texture<short1, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_short1(v.x);
}

static __inline__ __device__ ushort1 texCubemapLayered(texture<ushort1, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_ushort1(v.x);
}

static __inline__ __device__ short2 texCubemapLayered(texture<short2, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_short2(v.x, v.y);
}

static __inline__ __device__ ushort2 texCubemapLayered(texture<ushort2, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_ushort2(v.x, v.y);
}

static __inline__ __device__ short4 texCubemapLayered(texture<short4, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_short4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ushort4 texCubemapLayered(texture<ushort4, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_ushort4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int texCubemapLayered(texture<int, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return (int)v.x;
}

static __inline__ __device__ unsigned int texCubemapLayered(texture<unsigned int, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return (unsigned int)v.x;
}

static __inline__ __device__ int1 texCubemapLayered(texture<int1, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_int1(v.x);
}

static __inline__ __device__ uint1 texCubemapLayered(texture<uint1, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_uint1(v.x);
}

static __inline__ __device__ int2 texCubemapLayered(texture<int2, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_int2(v.x, v.y);
}

static __inline__ __device__ uint2 texCubemapLayered(texture<uint2, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_uint2(v.x, v.y);
}

static __inline__ __device__ int4 texCubemapLayered(texture<int4, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_int4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uint4 texCubemapLayered(texture<uint4, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_uint4(v.x, v.y, v.z, v.w);
}

#if !defined(__LP64__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ long texCubemapLayered(texture<long, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return (long)v.x;
}

static __inline__ __device__ unsigned long texCubemapLayered(texture<unsigned long, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return (unsigned long)v.x;
}

static __inline__ __device__ long1 texCubemapLayered(texture<long1, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_long1(v.x);
}

static __inline__ __device__ ulong1 texCubemapLayered(texture<ulong1, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_ulong1(v.x);
}

static __inline__ __device__ long2 texCubemapLayered(texture<long2, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_long2(v.x, v.y);
}

static __inline__ __device__ ulong2 texCubemapLayered(texture<ulong2, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_ulong2(v.x, v.y);
}

static __inline__ __device__ long4 texCubemapLayered(texture<long4, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  int4 v = __itexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_long4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ulong4 texCubemapLayered(texture<ulong4, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  uint4 v = __utexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_ulong4(v.x, v.y, v.z, v.w);
}

#endif /* !__LP64__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float texCubemapLayered(texture<float, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  float4 v = __ftexfetchlc(t, make_float4(x, y, z, 0), layer);

  return v.x;
}

static __inline__ __device__ float1 texCubemapLayered(texture<float1, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  float4 v = __ftexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_float1(v.x);
}

static __inline__ __device__ float2 texCubemapLayered(texture<float2, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  float4 v = __ftexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_float2(v.x, v.y);
}

static __inline__ __device__ float4 texCubemapLayered(texture<float4, cudaTextureTypeCubemapLayered, cudaReadModeElementType> t, float x, float y, float z, int layer)
{
  float4 v = __ftexfetchlc(t, make_float4(x, y, z, 0), layer);

  return make_float4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float texCubemapLayered(texture<char, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
#if defined(_CHAR_UNSIGNED) || defined(__CHAR_UNSIGNED__)
  uint4 v  = __utexfetchlc(t, make_float4(x, y, z, 0), layer);
#else /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  int4 v   = __itexfetchlc(t, make_float4(x, y, z, 0), layer);
#endif /* _CHAR_UNSIGNED || __CHAR_UNSIGNED__ */
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float texCubemapLayered(texture<signed char, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  int4 v   = __itexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float texCubemapLayered(texture<unsigned char, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  uint4 v  = __utexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 texCubemapLayered(texture<char1, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  int4 v   = __itexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 texCubemapLayered(texture<uchar1, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  uint4 v  = __utexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 texCubemapLayered(texture<char2, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  int4 v   = __itexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 texCubemapLayered(texture<uchar2, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  uint4 v  = __utexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 texCubemapLayered(texture<char4, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  int4 v   = __itexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 texCubemapLayered(texture<uchar4, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  uint4 v  = __utexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float texCubemapLayered(texture<short, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  int4 v   = __itexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float texCubemapLayered(texture<unsigned short, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  uint4 v  = __utexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 texCubemapLayered(texture<short1, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  int4 v   = __itexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 texCubemapLayered(texture<ushort1, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  uint4 v  = __utexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 texCubemapLayered(texture<short2, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  int4 v   = __itexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 texCubemapLayered(texture<ushort2, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  uint4 v  = __utexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 texCubemapLayered(texture<short4, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  int4 v   = __itexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 texCubemapLayered(texture<ushort4, cudaTextureTypeCubemapLayered, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
{
  uint4 v   = __utexfetchlc(t, make_float4(x, y, z, 0), layer);
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

#elif defined(__CUDABE__)

extern  uint4 __utexfetchi1D(const void*, int4);
extern   int4 __itexfetchi1D(const void*, int4);
extern float4 __ftexfetchi1D(const void*, int4);
extern  uint4 __utexfetch1D(const void*, float4);
extern   int4 __itexfetch1D(const void*, float4);
extern float4 __ftexfetch1D(const void*, float4);
extern  uint4 __utexfetch2D(const void*, float4);
extern   int4 __itexfetch2D(const void*, float4);
extern float4 __ftexfetch2D(const void*, float4);
extern  uint4 __utexfetch3D(const void*, float4);
extern   int4 __itexfetch3D(const void*, float4);
extern float4 __ftexfetch3D(const void*, float4);
extern  uint4 __utexfetchcube(const void*, float4);
extern   int4 __itexfetchcube(const void*, float4);
extern float4 __ftexfetchcube(const void*, float4);
extern  uint4 __utexfetchl1D(const void*, float4, int);
extern   int4 __itexfetchl1D(const void*, float4, int);
extern float4 __ftexfetchl1D(const void*, float4, int);
extern  uint4 __utexfetchl2D(const void*, float4, int);
extern   int4 __itexfetchl2D(const void*, float4, int);
extern float4 __ftexfetchl2D(const void*, float4, int);
extern  uint4 __utexfetchlcube(const void*, float4, int);
extern   int4 __itexfetchlcube(const void*, float4, int);
extern float4 __ftexfetchlcube(const void*, float4, int);

#define __utexfetchi(t, i) \
        __utexfetchi1D(t, i)
#define __itexfetchi(t, i) \
        __itexfetchi1D(t, i)
#define __ftexfetchi(t, i) \
        __ftexfetchi1D(t, i)
#define __utexfetch(t, i, d) \
        __utexfetch##d##D(t, i)
#define __itexfetch(t, i, d) \
        __itexfetch##d##D(t, i)
#define __ftexfetch(t, i, d) \
        __ftexfetch##d##D(t, i)
#define __utexfetchc(t, i) \
        __utexfetchcube(t, i)
#define __itexfetchc(t, i) \
        __itexfetchcube(t, i)
#define __ftexfetchc(t, i) \
        __ftexfetchcube(t, i)
#define __utexfetchl(t, i, l, d) \
        __utexfetchl##d##D(t, i, l)
#define __itexfetchl(t, i, l, d) \
        __itexfetchl##d##D(t, i, l)
#define __ftexfetchl(t, i, l, d) \
        __ftexfetchl##d##D(t, i, l)
#define __utexfetchlc(t, i, l) \
        __utexfetchlcube(t, i, l)
#define __itexfetchlc(t, i, l) \
        __itexfetchlcube(t, i, l)
#define __ftexfetchlc(t, i, l) \
        __ftexfetchlcube(t, i, l)

#endif /* __cplusplus && __CUDACC__ */

#if defined(__cplusplus) && defined(__CUDACC__)

#if !defined(__CUDA_ARCH__) || __CUDA_ARCH__ >= 200

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

template<int comp, class T, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__   int4 __itex2Dgather(texture<T, cudaTextureType2D, readMode> t, float2 i, int c = comp);
template<int comp, class T, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__  uint4 __utex2Dgather(texture<T, cudaTextureType2D, readMode> t, float2 i, int c = comp);
template<int comp, class T, enum cudaTextureReadMode readMode> extern __device__ __device_builtin__ float4 __ftex2Dgather(texture<T, cudaTextureType2D, readMode> t, float2 i, int c = comp);

#define __tex2DgatherUtil(T, f, r, c) \
        { T v = f<c>(t, make_float2(x, y)); return r; }

#define __tex2DgatherUtil1(T, f, r) \
        __tex2DgatherUtil(T, f, r, 0)

#define __tex2DgatherUtil2(T, f, r)                  \
        if (comp == 1) __tex2DgatherUtil(T, f, r, 1) \
        else __tex2DgatherUtil1(T, f, r)

#define __tex2DgatherUtil3(T, f, r)                  \
        if (comp == 2) __tex2DgatherUtil(T, f, r, 2) \
        else __tex2DgatherUtil2(T, f, r)

#define __tex2DgatherUtil4(T, f, r)                  \
        if (comp == 3) __tex2DgatherUtil(T, f, r, 3) \
        else __tex2DgatherUtil3(T, f, r)

static __inline__ __device__ char4 tex2Dgather(texture<char, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_char4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ char4 tex2Dgather(texture<signed char, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_char4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ uchar4 tex2Dgather(texture<unsigned char, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, make_uchar4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ char4 tex2Dgather(texture<char1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_char4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ uchar4 tex2Dgather(texture<uchar1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, make_uchar4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ char4 tex2Dgather(texture<char2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(int4, __itex2Dgather, make_char4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ uchar4 tex2Dgather(texture<uchar2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(uint4, __utex2Dgather, make_uchar4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ char4 tex2Dgather(texture<char3, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(int4, __itex2Dgather, make_char4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ uchar4 tex2Dgather(texture<uchar3, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(uint4, __utex2Dgather, make_uchar4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ char4 tex2Dgather(texture<char4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(int4, __itex2Dgather, make_char4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ uchar4 tex2Dgather(texture<uchar4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(uint4, __utex2Dgather, make_uchar4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ short4 tex2Dgather(texture<signed short, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_short4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ ushort4 tex2Dgather(texture<unsigned short, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, make_ushort4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ short4 tex2Dgather(texture<short1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_short4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ ushort4 tex2Dgather(texture<ushort1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, make_ushort4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ short4 tex2Dgather(texture<short2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(int4, __itex2Dgather, make_short4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ ushort4 tex2Dgather(texture<ushort2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(uint4, __utex2Dgather, make_ushort4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ short4 tex2Dgather(texture<short3, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(int4, __itex2Dgather, make_short4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ ushort4 tex2Dgather(texture<ushort3, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(uint4, __utex2Dgather, make_ushort4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ short4 tex2Dgather(texture<short4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(int4, __itex2Dgather, make_short4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ ushort4 tex2Dgather(texture<ushort4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(uint4, __utex2Dgather, make_ushort4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ int4 tex2Dgather(texture<signed int, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, v);
}

static __inline__ __device__ uint4 tex2Dgather(texture<unsigned int, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, v);
}

static __inline__ __device__ int4 tex2Dgather(texture<int1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, v);
}

static __inline__ __device__ uint4 tex2Dgather(texture<uint1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, v);
}

static __inline__ __device__ int4 tex2Dgather(texture<int2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(int4, __itex2Dgather, v);
}

static __inline__ __device__ uint4 tex2Dgather(texture<uint2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(uint4, __utex2Dgather, v);
}

static __inline__ __device__ int4 tex2Dgather(texture<int3, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(int4, __itex2Dgather, v);
}

static __inline__ __device__ uint4 tex2Dgather(texture<uint3, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(uint4, __utex2Dgather, v);
}

static __inline__ __device__ int4 tex2Dgather(texture<int4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(int4, __itex2Dgather, v);
}

static __inline__ __device__ uint4 tex2Dgather(texture<uint4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(uint4, __utex2Dgather, v);
}

static __inline__ __device__ float4 tex2Dgather(texture<float, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(float4, __ftex2Dgather, v);
}

static __inline__ __device__ float4 tex2Dgather(texture<float1, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(float4, __ftex2Dgather, v);
}

static __inline__ __device__ float4 tex2Dgather(texture<float2, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(float4, __ftex2Dgather, v);
}

static __inline__ __device__ float4 tex2Dgather(texture<float3, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(float4, __ftex2Dgather, v);
}

static __inline__ __device__ float4 tex2Dgather(texture<float4, cudaTextureType2D, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(float4, __ftex2Dgather, v);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/


static __inline__ __device__ float4 tex2Dgather(texture<char, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<signed char, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<unsigned char, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<char1, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<uchar1, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<char2, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(int4, __itex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<uchar2, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(uint4, __utex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<char3, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(int4, __itex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<uchar3, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(uint4, __utex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<char4, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(int4, __itex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<uchar4, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(uint4, __utex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<signed short, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<unsigned short, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<short1, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<ushort1, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<short2, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(int4, __itex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<ushort2, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(uint4, __utex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<short3, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(int4, __itex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<ushort3, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(uint4, __utex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<short4, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(int4, __itex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

static __inline__ __device__ float4 tex2Dgather(texture<ushort4, cudaTextureType2D, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(uint4, __utex2Dgather, make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)));
}

#undef __tex2DgatherUtil
#undef __tex2DgatherUtil1
#undef __tex2DgatherUtil2
#undef __tex2DgatherUtil3
#undef __tex2DgatherUtil4

#endif /* !__CUDA_ARCH__ || __CUDA_ARCH__ >= 200 */

#elif defined(__CUDABE__)

extern  uint4 __utex2Dgather0(const void*, float2);
extern  uint4 __utex2Dgather1(const void*, float2);
extern  uint4 __utex2Dgather2(const void*, float2);
extern  uint4 __utex2Dgather3(const void*, float2);
extern   int4 __itex2Dgather0(const void*, float2);
extern   int4 __itex2Dgather1(const void*, float2);
extern   int4 __itex2Dgather2(const void*, float2);
extern   int4 __itex2Dgather3(const void*, float2);
extern float4 __ftex2Dgather0(const void*, float2);
extern float4 __ftex2Dgather1(const void*, float2);
extern float4 __ftex2Dgather2(const void*, float2);
extern float4 __ftex2Dgather3(const void*, float2);

#define __utex2Dgather(t, i, c) \
        __utex2Dgather##c(t, i)
#define __itex2Dgather(t, i, c) \
        __itex2Dgather##c(t, i)
#define __ftex2Dgather(t, i, c) \
        __ftex2Dgather##c(t, i)

#endif /* __cplusplus && __CUDACC__ */

#endif /* !__TEXTURE_FETCH_FUNCTIONS_H__ */

