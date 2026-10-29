#include "snapshot29_0433f7af8f6d.h"

extern char D_800C02AE[];
extern u8 *D_800C7F80;
void *func_80016204(void *);
void *func_8007EAA0(s32, s32);
void func_80097E30(void *, s32, s32);
s32 func_80005CB8(s32, s32, s32, s32, s32);
void func_80005D98(s32);
void func_80016354(void *, void *);
void func_800560E0(void *, s32);
typedef struct 
{
  u8 b[8];
} B8;
typedef struct 
{
  u8 b[12];
} B12;
typedef struct 
{
  u32 w[31];
} B124;
typedef struct 
{
  u32 w[4];
} B16;
typedef struct 
{
  u32 w[3];
} Btail;
typedef struct 
{
  u32 w[5];
} B20;
typedef struct 
{
  u32 w[16];
} B64;
void *func_800163E4(void *arg0, u8 *arg1, u8 *arg2)
{
  char *new_var;
  u8 *fp = func_80016204(arg0);
  u8 *r;
  u8 *p;
  u8 *q;
  s32 n;
  s32 i;
  s32 handle;
  s32 mode;
  *((u16 *) (arg1 + 0x22)) = *((u16 *) (arg1 + 0x20));
  new_var = D_800C02AE + 0x5dce;
  r = arg1 + (((*((u16 *) (arg1 + 0x20))) * 0x38) + 0x3c);
  *((B8 *) r) = *((B8 *) arg2);
  {
    u8 *dst = func_8007EAA0(1, 0x7c);
    u8 *src = D_800C7F80;
    u8 *end = src + 0x70;
    *((void **) (r + 8)) = dst;
    do
    {
      *((B16 *) dst) = *((B16 *) src);
      src += 16;
      dst += 16;
    }
    while (src != end);
    *((Btail *) dst) = *((Btail *) src);
  }
  n = *((u16 *) ((*((u8 **) (r + 8))) + 0x28));
  *((void **) ((*((u8 **) (r + 8))) + 0x24)) = func_8007EAA0(1, n * 20);
  for (i = 0; i < n; i++)
  {
    ((B20 *) (*((void **) ((*((u8 **) (r + 8))) + 0x24))))[i] = ((B20 *) (*((void **) (D_800C7F80 + 0x24))))[i];
  }

  *((u8 **) new_var) = r;
  *((B12 *) (r + 0x20)) = *((B12 *) (D_800C7F80 + 4));
  *((u16 *) (r + 0x2c)) = 1;
  r[0x2f] = 0;
  ++(*((u16 *) (arg1 + 0x20)));
  *((void **) (r + 0x10)) = func_8007EAA0(1, (*((u16 *) (fp + 4))) * 4);
  *((u32 *) (r + 0xc)) = *((u16 *) (fp + 4));
  for (i = 0; ((u32) i) < (*((u32 *) (r + 0xc))); i++)
  {
    handle = 0;
    p = (*((u8 **) fp)) + (i * 0x6c);
    q = func_8007EAA0(1, 0x94);
    func_80097E30(q, 0, 0x94);
    *((u32 *) q) = 0;
    *((B64 *) (q + 8)) = *((B64 *) (p + 0xc));
    *((B64 *) (q + 0x48)) = *((B64 *) (p + 0xc));
    (*((u8 ***) (r + 0x10)))[i] = q;
    *((u8 **) ((*((u8 ***) (r + 0x10)))[i] + 0x8c)) = p;
    mode = (u8) D_800C02AE[0x7678];
    if (i == 0)
    {
      switch (mode)
      {
        case 0:
          handle = func_80005CB8(1, 0x960, 0x230, 1, 6);
          break;

        case 1:
          handle = func_80005CB8(1, 0x708, 0x140, 1, 6);
          break;

        case 2:
          handle = func_80005CB8(1, 0x708, 0x140, 1, 6);
          break;

        case 3:
          handle = func_80005CB8(1, 0x12c, 0x80, 1, 6);
          break;

      }

    }
    else
    {
      switch (mode)
      {
        case 0:
          handle = func_80005CB8(1, 0x80, 0x40, 1, 6);
          break;

        case 1:
          handle = func_80005CB8(1, 0x80, 0x40, 1, 6);
          break;

        case 2:
          handle = func_80005CB8(1, 0x80, 0x40, 1, 6);
          break;

        case 3:
          handle = func_80005CB8(1, 0x80, 0x40, 1, 6);
          break;

      }

    }
    *((s32 *) ((*((u8 ***) (r + 0x10)))[i] + 0x90)) = handle;
    func_800560E0(p, handle);
    func_80005D98(handle);
  }

  func_80016354((*((void ***) (r + 0x10)))[1], (*((void ***) (r + 0x10)))[0]);
  func_80016354((*((void ***) (r + 0x10)))[2], (*((void ***) (r + 0x10)))[0]);
  func_80016354((*((void ***) (r + 0x10)))[3], (*((void ***) (r + 0x10)))[0]);
  func_80016354((*((void ***) (r + 0x10)))[4], (*((void ***) (r + 0x10)))[0]);
  *((u32 *) ((*((u8 ***) (r + 0x10)))[0] + 4)) = 0;
  *((u32 *) ((*((u8 ***) (r + 0x10)))[0] + 0x88)) = 0;
  *((void **) ((*((u8 ***) (r + 0x10)))[1] + 4)) = (*((void ***) (r + 0x10)))[0];
  *((void **) ((*((u8 ***) (r + 0x10)))[2] + 4)) = (*((void ***) (r + 0x10)))[0];
  *((void **) ((*((u8 ***) (r + 0x10)))[3] + 4)) = (*((void ***) (r + 0x10)))[0];
  *((void **) ((*((u8 ***) (r + 0x10)))[4] + 4)) = (*((void ***) (r + 0x10)))[0];
  return r;
}
