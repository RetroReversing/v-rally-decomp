#include "snapshot29_0433f7af8f6d.h"

void func_80072C94(void *arg0, u8 arg1)
{
  extern s32 func_8002FA10(s32);
  extern s32 func_80042D20(void);
  extern s32 func_8004F3C4(void *);
  extern s32 func_800804C4(s32, void *, ...);
  extern s32 func_80080514(s32, void *, s32);
  extern s32 func_8008E13C(s32, s32, s32);
  extern void *D_800A1234;
  extern void *D_800A1238;
  extern void *D_800C35A0;
  extern s32 D_8009CE8C;
  extern s32 D_8009CE90;
  extern s32 D_8009CE94;
  extern s32 D_8009CE98;
  extern s32 D_8009CE9C;
  extern s32 D_8009CEA0;
  extern s32 D_800AE850;
  extern s32 D_800C02AE;
  extern void func_8004F4BC(void);
  extern void func_80042A7C(void);
  u8 i;
  u16 mode;
  u16 count;
  s32 *table = D_800A1234;
  s32 *mgr;
  s32 *a;
  s32 *b;
  s32 len;
  *((s8 *) (((char *) table) + 0x114)) = 0;
  mgr = D_800A1238;
  *((s8 *) (((char *) mgr) + 0x114)) = 0;
  mode = *((u16 *) (((char *) D_800C35A0) + 0x1E));
  if (!mode)
  {
    if ((*((u16 *) (((char *) D_800C35A0) + 0x1A))) == 1)
    {
      i = (u8) arg1;
      a = (s32 *) (((char *) table) + (i * 0x44));
      b = (s32 *) (((char *) mgr) + (i * 0x44));
      *((u16 *) (((char *) a) + 0xC)) = 0;
      len = *((u16 *) (((char *) b) + 0xE));
      *((u16 *) (((char *) a) + 0xA)) = 4;
      *((u16 *) (((char *) a) + 0xE)) = len;
      func_8008E13C(a[0], b[0], ((*((s32 *) (((char *) b) + 0x10))) + 3) & (-4));
      func_8008E13C(a[1], b[1], ((*((s32 *) (((char *) b) + 0x14))) + 3) & (-4));
      {
        struct Copy40
        {
          s32 w[10];
        };
        *((struct Copy40 *) (((char *) a) + 0x1C)) = *((struct Copy40 *) (((char *) b) + 0x1C));
      }
      len = *((s32 *) (((char *) b) + 0x18));
      if (len)
      {
        *(*((s32 **) (((char *) arg0) + 0x88))) = len;
        *((s32 *) (((char *) a) + 0x18)) = *((s32 *) (((char *) b) + 0x18));
      }
      *((u16 *) (((char *) a) + 8)) = ((*((u16 *) (((char *) a) + 8))) & 0xFBFF) | 0xA00;
      *((u16 *) (((char *) b) + 0xC)) = 0;
      *((u16 *) (((char *) b) + 0xA)) = 3;
      if (((*((u32 *) (((char *) arg0) + 0x14))) & 0x4000) && ((*((u16 *) (((char *) D_800C35A0) + 0xE))) == 2))
      {
        i = *(((u8 *) (*((void **) (((char *) arg0) + 0x48)))) + 3);
        if (i)
        {
          u32 len = i * 12;
          D_8009CE8C = *((s32 *) (((char *) (&D_8009CE8C)) + len));
          D_8009CE90 = *((s32 *) (((char *) (&D_8009CE90)) + len));
          D_8009CE94 = *((s32 *) (((char *) (&D_8009CE94)) + len));
        }
        else
        {
          D_8009CE98 = D_8009CE8C;
          D_8009CE9C = D_8009CE90;
          D_8009CEA0 = D_8009CE94;
        }
      }
    }
    else
    {
      count = *((u16 *) (((char *) table) + 0x110));
      {
        for (i = 0; i < (*((u16 *) (((char *) table) + 0x110))); i++)
        {
          a = (s32 *) (((char *) table) + (i * 0x44));
          *((u16 *) (((char *) a) + 0xA)) = 4;
          if (1)
          {
            *((u16 *) (((char *) a) + 0xC)) = 0;
            *((u16 *) (((char *) a) + 8)) = ((*((u16 *) (((char *) a) + 8))) & 0xFBFF) | 0x200;
          }
        }

      }
    }
  }
  else
  {
    count = *((u16 *) (((char *) table) + 0x110));
    for (i = 0; i < (*((u16 *) (((char *) table) + 0x110))); i++)
    {
      a = (s32 *) (((char *) table) + (i * 0x44));
      *((u16 *) (((char *) a) + 0xA)) = 4;
      *((u16 *) (((char *) a) + 0xC)) = 0;
      *((u16 *) (((char *) a) + 8)) = ((*((u16 *) (((char *) a) + 8))) & 0xFBFF) | 0x200;
    }

  }
  func_800804C4(*((s32 *) (((char *) (&D_800AE850)) + 0x73F0)), func_8004F4BC);
  {
    u32 x = *((u32 *) (((char *) arg0) + 0x14));
    x &= ~0x20;
    x &= ~0x40;
    x &= ~0x80;
    x &= ~0x100;
    x &= ~0x200;
    *((u32 *) (((char *) arg0) + 0x14)) = x;
  }
  func_8002FA10(*(*((s32 **) (((char *) arg0) + 0x38))));
  *((u32 *) (((char *) arg0) + 0x14)) &= ~0x10;
  { s32 *obj = *((s32 **) (((char *) arg0) + 0x6C));
  *((s32 *) (((char *) obj) + 0x34)) = 0;
  func_8004F3C4(obj); }
  func_80042D20();
  func_80080514(*((s32 *) (((char *) (&D_800AE850)) + 0x72FC)), func_80042A7C, 3);
  i = (u8) arg1;
  a = (s32 *) (((char *) table) + (i * 0x44));
  if ((*((u16 *) (((char *) a) + 0xE))) < 0x65)
  {
    *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x48)))) + 0x20)) = 4;
  }
}
