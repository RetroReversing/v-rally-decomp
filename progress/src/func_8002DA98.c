typedef struct { s16 h[9]; unsigned int :16; unsigned int :32; unsigned int :32; unsigned int :32; } Matrix;
typedef char matrix_size_check[sizeof(Matrix)==32?1:-1];
typedef struct { char c; Matrix m; } MatrixAlignmentCheck;
typedef char matrix_alignment_check[sizeof(MatrixAlignmentCheck)==36?1:-1];

/* Copies a 32-byte matrix from src to dst, transposing the 3x3 s16 rotation part
   and copying the three translation words at +20, +24 and +28. */
void *func_8002DA98(void *raw0, void *raw1)
{
  Matrix *src = raw0;
  Matrix *dst = raw1;
  s32 i;
  s32 j;

  ((u16 *)dst)[0] = ((u16 *)src)[0];
  ((u16 *)dst)[4] = ((u16 *)src)[4];
  ((u16 *)dst)[8] = ((u16 *)src)[8];
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      ((u16 *)((char *)dst + j * 6))[i] = ((u16 *)((char *)src + i * 6))[j];
    }
  }
  __builtin_memcpy((s32 *)((unsigned char *)dst+20), (const s32 *)((const unsigned char *)src+20), 4);
  __builtin_memcpy((s32 *)((unsigned char *)dst+24), (const s32 *)((const unsigned char *)src+24), 4);
  __builtin_memcpy((s32 *)((unsigned char *)dst+28), (const s32 *)((const unsigned char *)src+28), 4);
  return dst;
}
