#include "decompdecomp_snapshot_8002da98.h"
#line 1 "func.c"
typedef struct { s16 h[9]; unsigned int :16; unsigned int :32; unsigned int :32; unsigned int :32; } Matrix;
typedef char matrix_size_check[sizeof(Matrix)==32?1:-1];
typedef struct { char c; Matrix m; } MatrixAlignmentCheck;
typedef char matrix_alignment_check[sizeof(MatrixAlignmentCheck)==36?1:-1];
void *func_8002DA98(void *raw0, void *raw1)
{
  Matrix *arg0 = raw0;
  Matrix *arg1 = raw1;
  s32 i;
  s32 j;

  ((u16 *)arg1)[0] = ((u16 *)arg0)[0];
  ((u16 *)arg1)[4] = ((u16 *)arg0)[4];
  ((u16 *)arg1)[8] = ((u16 *)arg0)[8];
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      ((u16 *)((char *)arg1 + j * 6))[i] = ((u16 *)((char *)arg0 + i * 6))[j];
    }
  }
  __builtin_memcpy((s32 *)((unsigned char *)arg1+20), (const s32 *)((const unsigned char *)arg0+20), 4);
__builtin_memcpy((s32 *)((unsigned char *)arg1+24), (const s32 *)((const unsigned char *)arg0+24), 4);
__builtin_memcpy((s32 *)((unsigned char *)arg1+28), (const s32 *)((const unsigned char *)arg0+28), 4);
  return arg1;
}

