/* { dg-do compile } */
/* { dg-options "-mkl -O2" } */
/* { dg-final { scan-assembler "movdqa\[ \\t\]+\[^\\n\\r\]*, %xmm0" } } */
/* { dg-final { scan-assembler "movl\[ \\t\]+\[^\\n\\r\]*, %eax" } } */
/* { dg-final { scan-assembler "encodekey128\[ \\t\]+\[^\\n\]*%eax\[^\\n\\r\]*%eax" } } */
/* { dg-final { scan-assembler "(?:movdqu|movups)\[ \\t\]+\[^\\n\]*%xmm0,\[^\\n\\r\]*" } } */
/* { dg-final { scan-assembler "(?:movdqu|movups)\[ \\t\]+\[^\\n\]*%xmm1,\[^\\n\\r\]*16\[^\\n\\r\]*" } } */
/* { dg-final { scan-assembler "(?:movdqu|movups)\[ \\t\]+\[^\\n\]*%xmm2,\[^\\n\\r\]*32\[^\\n\\r\]*" } } */

#include <immintrin.h>

unsigned int ctrl;
char h2[48];
__m128i k1, k2;

unsigned int
test_keylocker_9 (void)
{
  unsigned int ret;

  ret = _mm_encodekey128_u32 (ctrl, k1, h2);

  if (ret)
    k2 = (__m128i){0};

  return ret;
}

