/* Copyright (C) 2007 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING.  If not, write to
   the Free Software Foundation, 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, if you include this header file into source
   files compiled by GCC, this header file does not by itself cause
   the resulting executable to be covered by the GNU General Public
   License.  This exception does not however invalidate any other
   reasons why the executable file might be covered by the GNU General
   Public License.  */

/* Implemented from the specification included in the Intel C++ Compiler
   User Guide and Reference, version 10.0.  */

#ifndef _SMMINTRIN_H_INCLUDED
#define _SMMINTRIN_H_INCLUDED

#ifndef __SSE4_1__
# error "SSE4.1 instruction set not enabled"
#else

/* We need definitions from the SSSE3, SSE3, SSE2 and SSE header
   files.  */
#include <tmmintrin.h>
#include <mmintrin-common.h>

/* SSE4.1 */

/* Integer blend instructions - select data from 2 sources using
   constant/variable mask.  */

#ifdef __OPTIMIZE__
static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_blend_epi16 (__m128i __X, __m128i __Y, const int __M)
{
  return (__m128i) __builtin_ia32_pblendw128 ((__v8hi)__X,
					      (__v8hi)__Y,
					      __M);
}
#else
#define _mm_blend_epi16(X, Y, M) \
  ((__m128i) __builtin_ia32_pblendw128 ((__v8hi)(X), (__v8hi)(Y), (M)))
#endif

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_blendv_epi8 (__m128i __X, __m128i __Y, __m128i __M)
{
  return (__m128i) __builtin_ia32_pblendvb128 ((__v16qi)__X,
					       (__v16qi)__Y,
					       (__v16qi)__M);
}

/* Single precision floating point blend instructions - select data
   from 2 sources using constant/variable mask.  */

#ifdef __OPTIMIZE__
static __inline __m128 __attribute__((__always_inline__, __artificial__))
_mm_blend_ps (__m128 __X, __m128 __Y, const int __M)
{
  return (__m128) __builtin_ia32_blendps ((__v4sf)__X,
					  (__v4sf)__Y,
					  __M);
}
#else
#define _mm_blend_ps(X, Y, M) \
  ((__m128) __builtin_ia32_blendps ((__v4sf)(X), (__v4sf)(Y), (M)))
#endif

static __inline __m128 __attribute__((__always_inline__, __artificial__))
_mm_blendv_ps (__m128 __X, __m128 __Y, __m128 __M)
{
  return (__m128) __builtin_ia32_blendvps ((__v4sf)__X,
					   (__v4sf)__Y,
					   (__v4sf)__M);
}

/* Double precision floating point blend instructions - select data
   from 2 sources using constant/variable mask.  */

#ifdef __OPTIMIZE__
static __inline __m128d __attribute__((__always_inline__, __artificial__))
_mm_blend_pd (__m128d __X, __m128d __Y, const int __M)
{
  return (__m128d) __builtin_ia32_blendpd ((__v2df)__X,
					   (__v2df)__Y,
					   __M);
}
#else
#define _mm_blend_pd(X, Y, M) \
  ((__m128d) __builtin_ia32_blendpd ((__v2df)(X), (__v2df)(Y), (M)))
#endif

static __inline __m128d __attribute__((__always_inline__, __artificial__))
_mm_blendv_pd (__m128d __X, __m128d __Y, __m128d __M)
{
  return (__m128d) __builtin_ia32_blendvpd ((__v2df)__X,
					    (__v2df)__Y,
					    (__v2df)__M);
}

/* Dot product instructions with mask-defined summing and zeroing parts
   of result.  */

#ifdef __OPTIMIZE__
static __inline __m128 __attribute__((__always_inline__, __artificial__))
_mm_dp_ps (__m128 __X, __m128 __Y, const int __M)
{
  return (__m128) __builtin_ia32_dpps ((__v4sf)__X,
				       (__v4sf)__Y,
				       __M);
}

static __inline __m128d __attribute__((__always_inline__, __artificial__))
_mm_dp_pd (__m128d __X, __m128d __Y, const int __M)
{
  return (__m128d) __builtin_ia32_dppd ((__v2df)__X,
					(__v2df)__Y,
					__M);
}
#else
#define _mm_dp_ps(X, Y, M) \
  ((__m128) __builtin_ia32_dpps ((__v4sf)(X), (__v4sf)(Y), (M)))

#define _mm_dp_pd(X, Y, M) \
  ((__m128d) __builtin_ia32_dppd ((__v2df)(X), (__v2df)(Y), (M)))
#endif

/* Packed integer 64-bit comparison, zeroing or filling with ones
   corresponding parts of result.  */
static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cmpeq_epi64 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_pcmpeqq ((__v2di)__X, (__v2di)__Y);
}

/*  Min/max packed integer instructions.  */

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_min_epi8 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_pminsb128 ((__v16qi)__X, (__v16qi)__Y);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_max_epi8 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_pmaxsb128 ((__v16qi)__X, (__v16qi)__Y);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_min_epu16 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_pminuw128 ((__v8hi)__X, (__v8hi)__Y);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_max_epu16 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_pmaxuw128 ((__v8hi)__X, (__v8hi)__Y);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_min_epi32 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_pminsd128 ((__v4si)__X, (__v4si)__Y);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_max_epi32 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_pmaxsd128 ((__v4si)__X, (__v4si)__Y);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_min_epu32 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_pminud128 ((__v4si)__X, (__v4si)__Y);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_max_epu32 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_pmaxud128 ((__v4si)__X, (__v4si)__Y);
}

/* Packed integer 32-bit multiplication with truncation of upper
   halves of results.  */
static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_mullo_epi32 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_pmulld128 ((__v4si)__X, (__v4si)__Y);
}

/* Packed integer 32-bit multiplication of 2 pairs of operands
   with two 64-bit results.  */
static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_mul_epi32 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_pmuldq128 ((__v4si)__X, (__v4si)__Y);
}

/* Insert single precision float into packed single precision array
   element selected by index N.  The bits [7-6] of N define S
   index, the bits [5-4] define D index, and bits [3-0] define
   zeroing mask for D.  */

#ifdef __OPTIMIZE__
static __inline __m128 __attribute__((__always_inline__, __artificial__))
_mm_insert_ps (__m128 __D, __m128 __S, const int __N)
{
  return (__m128) __builtin_ia32_insertps128 ((__v4sf)__D,
					      (__v4sf)__S,
					      __N);
}
#else
#define _mm_insert_ps(D, S, N) \
  ((__m128) __builtin_ia32_insertps128 ((__v4sf)(D), (__v4sf)(S), (N)))
#endif

/* Helper macro to create the N value for _mm_insert_ps.  */
#define _MM_MK_INSERTPS_NDX(S, D, M) (((S) << 6) | ((D) << 4) | (M))

/* Extract binary representation of single precision float from packed
   single precision array element of X selected by index N.  */

#ifdef __OPTIMIZE__
static __inline int __attribute__((__always_inline__, __artificial__))
_mm_extract_ps (__m128 __X, const int __N)
{
  union { int i; float f; } __tmp;
  __tmp.f = __builtin_ia32_vec_ext_v4sf ((__v4sf)__X, __N);
  return __tmp.i;
}
#else
#define _mm_extract_ps(X, N) \
  (__extension__ 						\
   ({								\
      union { int i; float f; } __tmp;				\
      __tmp.f = __builtin_ia32_vec_ext_v4sf ((__v4sf)(X), (N));	\
      __tmp.i;							\
    })								\
   )
#endif

/* Extract binary representation of single precision float into
   D from packed single precision array element of S selected
   by index N.  */
#define _MM_EXTRACT_FLOAT(D, S, N) \
  { (D) = __builtin_ia32_vec_ext_v4sf ((__v4sf)(S), (N)); }
  
/* Extract specified single precision float element into the lower
   part of __m128.  */
#define _MM_PICK_OUT_PS(X, N)				\
  _mm_insert_ps (_mm_setzero_ps (), (X), 		\
		 _MM_MK_INSERTPS_NDX ((N), 0, 0x0e))

/* Insert integer, S, into packed integer array element of D
   selected by index N.  */

#ifdef __OPTIMIZE__
static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_insert_epi8 (__m128i __D, int __S, const int __N)
{
  return (__m128i) __builtin_ia32_vec_set_v16qi ((__v16qi)__D,
						 __S, __N);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_insert_epi32 (__m128i __D, int __S, const int __N)
{
  return (__m128i) __builtin_ia32_vec_set_v4si ((__v4si)__D,
						 __S, __N);
}

#ifdef __x86_64__
static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_insert_epi64 (__m128i __D, long long __S, const int __N)
{
  return (__m128i) __builtin_ia32_vec_set_v2di ((__v2di)__D,
						 __S, __N);
}
#endif
#else
#define _mm_insert_epi8(D, S, N) \
  ((__m128i) __builtin_ia32_vec_set_v16qi ((__v16qi)(D), (S), (N)))

#define _mm_insert_epi32(D, S, N) \
  ((__m128i) __builtin_ia32_vec_set_v4si ((__v4si)(D), (S), (N)))

#ifdef __x86_64__
#define _mm_insert_epi64(D, S, N) \
  ((__m128i) __builtin_ia32_vec_set_v2di ((__v2di)(D), (S), (N)))
#endif
#endif

/* Extract integer from packed integer array element of X selected by
   index N.  */

#ifdef __OPTIMIZE__
static __inline int __attribute__((__always_inline__, __artificial__))
_mm_extract_epi8 (__m128i __X, const int __N)
{
   return __builtin_ia32_vec_ext_v16qi ((__v16qi)__X, __N);
}

static __inline int __attribute__((__always_inline__, __artificial__))
_mm_extract_epi32 (__m128i __X, const int __N)
{
   return __builtin_ia32_vec_ext_v4si ((__v4si)__X, __N);
}

#ifdef __x86_64__
static __inline long long  __attribute__((__always_inline__, __artificial__))
_mm_extract_epi64 (__m128i __X, const int __N)
{
  return __builtin_ia32_vec_ext_v2di ((__v2di)__X, __N);
}
#endif
#else
#define _mm_extract_epi8(X, N) \
  __builtin_ia32_vec_ext_v16qi ((__v16qi) X, (N))
#define _mm_extract_epi32(X, N) \
  __builtin_ia32_vec_ext_v4si ((__v4si) X, (N))

#ifdef __x86_64__
#define _mm_extract_epi64(X, N) \
  ((long long) __builtin_ia32_vec_ext_v2di ((__v2di)(X), (N)))
#endif
#endif

/* Return horizontal packed word minimum and its index in bits [15:0]
   and bits [18:16] respectively.  */
static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_minpos_epu16 (__m128i __X)
{
  return (__m128i) __builtin_ia32_phminposuw128 ((__v8hi)__X);
}

/* Packed integer sign-extension.  */

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cvtepi8_epi32 (__m128i __X)
{
  return (__m128i) __builtin_ia32_pmovsxbd128 ((__v16qi)__X);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cvtepi16_epi32 (__m128i __X)
{
  return (__m128i) __builtin_ia32_pmovsxwd128 ((__v8hi)__X);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cvtepi8_epi64 (__m128i __X)
{
  return (__m128i) __builtin_ia32_pmovsxbq128 ((__v16qi)__X);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cvtepi32_epi64 (__m128i __X)
{
  return (__m128i) __builtin_ia32_pmovsxdq128 ((__v4si)__X);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cvtepi16_epi64 (__m128i __X)
{
  return (__m128i) __builtin_ia32_pmovsxwq128 ((__v8hi)__X);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cvtepi8_epi16 (__m128i __X)
{
  return (__m128i) __builtin_ia32_pmovsxbw128 ((__v16qi)__X);
}

/* Packed integer zero-extension. */

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cvtepu8_epi32 (__m128i __X)
{
  return (__m128i) __builtin_ia32_pmovzxbd128 ((__v16qi)__X);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cvtepu16_epi32 (__m128i __X)
{
  return (__m128i) __builtin_ia32_pmovzxwd128 ((__v8hi)__X);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cvtepu8_epi64 (__m128i __X)
{
  return (__m128i) __builtin_ia32_pmovzxbq128 ((__v16qi)__X);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cvtepu32_epi64 (__m128i __X)
{
  return (__m128i) __builtin_ia32_pmovzxdq128 ((__v4si)__X);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cvtepu16_epi64 (__m128i __X)
{
  return (__m128i) __builtin_ia32_pmovzxwq128 ((__v8hi)__X);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cvtepu8_epi16 (__m128i __X)
{
  return (__m128i) __builtin_ia32_pmovzxbw128 ((__v16qi)__X);
}

/* Pack 8 double words from 2 operands into 8 words of result with
   unsigned saturation. */
static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_packus_epi32 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_packusdw128 ((__v4si)__X, (__v4si)__Y);
}

/* Sum absolute 8-bit integer difference of adjacent groups of 4
   byte integers in the first 2 operands.  Starting offsets within
   operands are determined by the 3rd mask operand.  */

#ifdef __OPTIMIZE__
static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_mpsadbw_epu8 (__m128i __X, __m128i __Y, const int __M)
{
  return (__m128i) __builtin_ia32_mpsadbw128 ((__v16qi)__X,
					      (__v16qi)__Y, __M);
}
#else
#define _mm_mpsadbw_epu8(X, Y, M) \
  ((__m128i) __builtin_ia32_mpsadbw128 ((__v16qi)(X), (__v16qi)(Y), (M)))
#endif

/* Load double quadword using non-temporal aligned hint.  */
static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_stream_load_si128 (__m128i *__X)
{
  return (__m128i) __builtin_ia32_movntdqa ((__v2di *) __X);
}

#ifdef __SSE4_2__

/* These macros specify the source data format.  */
#define SIDD_UBYTE_OPS			0x00
#define SIDD_UWORD_OPS			0x01
#define SIDD_SBYTE_OPS			0x02
#define SIDD_SWORD_OPS			0x03

/* These macros specify the comparison operation.  */
#define SIDD_CMP_EQUAL_ANY		0x00
#define SIDD_CMP_RANGES			0x04
#define SIDD_CMP_EQUAL_EACH		0x08
#define SIDD_CMP_EQUAL_ORDERED		0x0c

/* These macros specify the the polarity.  */
#define SIDD_POSITIVE_POLARITY		0x00
#define SIDD_NEGATIVE_POLARITY		0x10
#define SIDD_MASKED_POSITIVE_POLARITY	0x20
#define SIDD_MASKED_NEGATIVE_POLARITY	0x30

/* These macros specify the output selection in _mm_cmpXstri ().  */
#define SIDD_LEAST_SIGNIFICANT		0x00
#define SIDD_MOST_SIGNIFICANT		0x40

/* These macros specify the output selection in _mm_cmpXstrm ().  */
#define SIDD_BIT_MASK			0x00
#define SIDD_UNIT_MASK			0x40

/* Intrinsics for text/string processing.  */

#ifdef __OPTIMIZE__
static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cmpistrm (__m128i __X, __m128i __Y, const int __M)
{
  return (__m128i) __builtin_ia32_pcmpistrm128 ((__v16qi)__X,
						(__v16qi)__Y,
						__M);
}

static __inline int __attribute__((__always_inline__, __artificial__))
_mm_cmpistri (__m128i __X, __m128i __Y, const int __M)
{
  return __builtin_ia32_pcmpistri128 ((__v16qi)__X,
				      (__v16qi)__Y,
				      __M);
}

static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cmpestrm (__m128i __X, int __LX, __m128i __Y, int __LY, const int __M)
{
  return (__m128i) __builtin_ia32_pcmpestrm128 ((__v16qi)__X, __LX,
						(__v16qi)__Y, __LY,
						__M);
}

static __inline int __attribute__((__always_inline__, __artificial__))
_mm_cmpestri (__m128i __X, int __LX, __m128i __Y, int __LY, const int __M)
{
  return __builtin_ia32_pcmpestri128 ((__v16qi)__X, __LX,
				      (__v16qi)__Y, __LY,
				      __M);
}
#else
#define _mm_cmpistrm(X, Y, M) \
  ((__m128i) __builtin_ia32_pcmpistrm128 ((__v16qi)(X), (__v16qi)(Y), (M)))
#define _mm_cmpistri(X, Y, M) \
  __builtin_ia32_pcmpistri128 ((__v16qi)(X), (__v16qi)(Y), (M))

#define _mm_cmpestrm(X, LX, Y, LY, M) \
  ((__m128i) __builtin_ia32_pcmpestrm128 ((__v16qi)(X), (int)(LX), \
					  (__v16qi)(Y), (int)(LY), (M)))
#define _mm_cmpestri(X, LX, Y, LY, M) \
  __builtin_ia32_pcmpestri128 ((__v16qi)(X), (int)(LX), \
			       (__v16qi)(Y), (int)(LY), (M))
#endif

/* Intrinsics for text/string processing and reading values of
   EFlags.  */

#ifdef __OPTIMIZE__
static __inline int __attribute__((__always_inline__, __artificial__))
_mm_cmpistra (__m128i __X, __m128i __Y, const int __M)
{
  return __builtin_ia32_pcmpistria128 ((__v16qi)__X,
				       (__v16qi)__Y,
				       __M);
}

static __inline int __attribute__((__always_inline__, __artificial__))
_mm_cmpistrc (__m128i __X, __m128i __Y, const int __M)
{
  return __builtin_ia32_pcmpistric128 ((__v16qi)__X,
				       (__v16qi)__Y,
				       __M);
}

static __inline int __attribute__((__always_inline__, __artificial__))
_mm_cmpistro (__m128i __X, __m128i __Y, const int __M)
{
  return __builtin_ia32_pcmpistrio128 ((__v16qi)__X,
				       (__v16qi)__Y,
				       __M);
}

static __inline int __attribute__((__always_inline__, __artificial__))
_mm_cmpistrs (__m128i __X, __m128i __Y, const int __M)
{
  return __builtin_ia32_pcmpistris128 ((__v16qi)__X,
				       (__v16qi)__Y,
				       __M);
}

static __inline int __attribute__((__always_inline__, __artificial__))
_mm_cmpistrz (__m128i __X, __m128i __Y, const int __M)
{
  return __builtin_ia32_pcmpistriz128 ((__v16qi)__X,
				       (__v16qi)__Y,
				       __M);
}

static __inline int __attribute__((__always_inline__, __artificial__))
_mm_cmpestra (__m128i __X, int __LX, __m128i __Y, int __LY, const int __M)
{
  return __builtin_ia32_pcmpestria128 ((__v16qi)__X, __LX,
				       (__v16qi)__Y, __LY,
				       __M);
}

static __inline int __attribute__((__always_inline__, __artificial__))
_mm_cmpestrc (__m128i __X, int __LX, __m128i __Y, int __LY, const int __M)
{
  return __builtin_ia32_pcmpestric128 ((__v16qi)__X, __LX,
				       (__v16qi)__Y, __LY,
				       __M);
}

static __inline int __attribute__((__always_inline__, __artificial__))
_mm_cmpestro (__m128i __X, int __LX, __m128i __Y, int __LY, const int __M)
{
  return __builtin_ia32_pcmpestrio128 ((__v16qi)__X, __LX,
				       (__v16qi)__Y, __LY,
				       __M);
}

static __inline int __attribute__((__always_inline__, __artificial__))
_mm_cmpestrs (__m128i __X, int __LX, __m128i __Y, int __LY, const int __M)
{
  return __builtin_ia32_pcmpestris128 ((__v16qi)__X, __LX,
				       (__v16qi)__Y, __LY,
				       __M);
}

static __inline int __attribute__((__always_inline__, __artificial__))
_mm_cmpestrz (__m128i __X, int __LX, __m128i __Y, int __LY, const int __M)
{
  return __builtin_ia32_pcmpestriz128 ((__v16qi)__X, __LX,
				       (__v16qi)__Y, __LY,
				       __M);
}
#else
#define _mm_cmpistra(X, Y, M) \
  __builtin_ia32_pcmpistria128 ((__v16qi)(X), (__v16qi)(Y), (M))
#define _mm_cmpistrc(X, Y, M) \
  __builtin_ia32_pcmpistric128 ((__v16qi)(X), (__v16qi)(Y), (M))
#define _mm_cmpistro(X, Y, M) \
  __builtin_ia32_pcmpistrio128 ((__v16qi)(X), (__v16qi)(Y), (M))
#define _mm_cmpistrs(X, Y, M) \
  __builtin_ia32_pcmpistris128 ((__v16qi)(X), (__v16qi)(Y), (M))
#define _mm_cmpistrz(X, Y, M) \
  __builtin_ia32_pcmpistriz128 ((__v16qi)(X), (__v16qi)(Y), (M))

#define _mm_cmpestra(X, LX, Y, LY, M) \
  __builtin_ia32_pcmpestria128 ((__v16qi)(X), (int)(LX), \
				(__v16qi)(Y), (int)(LY), (M))
#define _mm_cmpestrc(X, LX, Y, LY, M) \
  __builtin_ia32_pcmpestric128 ((__v16qi)(X), (int)(LX), \
				(__v16qi)(Y), (int)(LY), (M))
#define _mm_cmpestro(X, LX, Y, LY, M) \
  __builtin_ia32_pcmpestrio128 ((__v16qi)(X), (int)(LX), \
				(__v16qi)(Y), (int)(LY), (M))
#define _mm_cmpestrs(X, LX, Y, LY, M) \
  __builtin_ia32_pcmpestris128 ((__v16qi)(X), (int)(LX), \
				(__v16qi)(Y), (int)(LY), (M))
#define _mm_cmpestrz(X, LX, Y, LY, M) \
  __builtin_ia32_pcmpestriz128 ((__v16qi)(X), (int)(LX), \
				(__v16qi)(Y), (int)(LY), (M))
#endif

/* Packed integer 64-bit comparison, zeroing or filling with ones
   corresponding parts of result.  */
static __inline __m128i __attribute__((__always_inline__, __artificial__))
_mm_cmpgt_epi64 (__m128i __X, __m128i __Y)
{
  return (__m128i) __builtin_ia32_pcmpgtq ((__v2di)__X, (__v2di)__Y);
}

/* Calculate a number of bits set to 1.  */
static __inline int __attribute__((__always_inline__, __artificial__))
_mm_popcnt_u32 (unsigned int __X)
{
  return __builtin_popcount (__X);
}

#ifdef __x86_64__
static __inline long long  __attribute__((__always_inline__, __artificial__))
_mm_popcnt_u64 (unsigned long long __X)
{
  return __builtin_popcountll (__X);
}
#endif

/* Accumulate CRC32 (polynomial 0x11EDC6F41) value.  */
static __inline unsigned int __attribute__((__always_inline__, __artificial__))
_mm_crc32_u8 (unsigned int __C, unsigned char __V)
{
  return __builtin_ia32_crc32qi (__C, __V);
}

static __inline unsigned int __attribute__((__always_inline__, __artificial__))
_mm_crc32_u16 (unsigned int __C, unsigned short __V)
{
  return __builtin_ia32_crc32hi (__C, __V);
}

static __inline unsigned int __attribute__((__always_inline__, __artificial__))
_mm_crc32_u32 (unsigned int __C, unsigned int __V)
{
  return __builtin_ia32_crc32si (__C, __V);
}

#ifdef __x86_64__
static __inline unsigned long long __attribute__((__always_inline__, __artificial__))
_mm_crc32_u64 (unsigned long long __C, unsigned long long __V)
{
  return __builtin_ia32_crc32di (__C, __V);
}
#endif

#endif /* __SSE4_2__ */

#endif /* __SSE4_1__ */

#endif /* _SMMINTRIN_H_INCLUDED */
