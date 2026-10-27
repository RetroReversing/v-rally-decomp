#include "common.h"

extern s32 D_800B5C40;
extern s32 D_800C35A0;
static inline u8 inline_fn(u8 *arg0)
{
  return arg0[0x44];
}

void func_8003ED94(void *arg0)
{
  u8 *self;
  void *node;
  void *x;
  u8 *base;
  s32 var;
  u8 var_a2;
  s32 t1;
  s32 ff;
  self = arg0;
  node = *((void **) ((*((u8 **) (self + 0xA8))) + 0x24)); x=node;
  x = *((void **) (((u8 *) x) + 0x6C));
  t1 = *((s32 *) (((u8 *) x) + 8));
  var_a2 = 0;
  if ((*((s32 *) (((u8 *) x) + 0x20))) == 0)
  {
    node = *((void **) D_800B5C40);
    ff = 255;
    while (node)
    {
      *((s32 *) (self + 0x80)) &= ~4;
      self[0x92] = (self[0x91] = (self[0x90] = ff));
      if ((*((u16 *) (self + 0x76))) == (*((s32 *) ((*((u8 **) (((u8 *) node) + 0x6C))) + 8))))
      {
        base = (u8 *) D_800C35A0;
        var = *((u8 *) ((((u32) base) + var_a2) + 0x32));
        base += var * 40;
        base += *((u16 *) (self + 0x78));
        var = inline_fn(base);
        if (var >= 65)
        {
          *((s16 *) (self + 0x7A)) = inline_fn(base) - 65;
        }
        else
        {
          *((s16 *) (self + 0x7A)) = inline_fn(base) - 22;
        }
        if ((*((s16 *) (self + 0x7A))) < 0)
        {
          *((s16 *) (self + 0x7A)) = 0;
        }
        if (t1 == (*((u16 *) (self + 0x76))))
        {
          self[0x90] = 254;
          self[0x91] = 213;
          self[0x92] = 30;
        }
        break;
      }
      node = *((void **) (((u8 *) node) + 4));
      do
      {
      }
      while (0);
      var_a2++;
    }

  }
}
