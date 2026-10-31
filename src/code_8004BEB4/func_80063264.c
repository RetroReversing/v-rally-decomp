#include "snapshot31_verified.h"

extern char D_800C02AE[];
#define D_800D0634 (*(s32 *)(D_800C02AE + 0x10386))
#define D_800D061E (*(u16 *)(D_800C02AE + 0x10370))
static inline static static int inline_fn(s32 arg0)
{
  return ((u32) (arg0 & 0xFF)) < ((u16) D_800D061E);
}

static inline static int inline_fn2(s32 arg0, s32 arg1)
{
  return ((u32) (arg0 & 0xFF)) < ((u16) (*((u16 *) (arg1 + 0x14))));
}

void func_80063264(s32 arg0)
{
  s32 temp_a1;
  u32 temp_a3;
  s32 var_a2;
  int new_var;
  u16 var_t1;
  s32 var_t2;
  s32 var_t3;
  char *var_t0;
  var_t1 = 1;
  var_t3 = D_800D0634;
  var_t2 = 0;
  var_t0 = (char *)var_t3 + 0x14;
  if (D_800D061E != 0)
  {
    new_var = 0;
    ;
    do
    {
      var_a2 = 0;
      if ((((u32) new_var) < ((u16) (*((u16 *) (var_t3 + 0x14))))) && var_t1)
      {
        temp_a3 = var_t2 & 0xFF;
        do
        {
          temp_a1 = var_a2 & 0xFF;
          if ((*((u8 *) (((char *) (var_t3 + (temp_a1 << 6))) + 0x37))) == (arg0 & 0xFFFF))
          {
            var_t1 = 0;
            *((D_800C02AE + 0x327E) + temp_a3) = (*((D_800C02AE + 0x327E) + temp_a3)) | (1 << temp_a1);
          }
          var_a2 += 1;
        }
        while (var_t1 & inline_fn2(var_a2, var_t3));
      }
      var_t0 += 0x2C4;
      var_t3 += 0x2C4;
      var_t2 += 1;
    }
    while (var_t1 & inline_fn(var_t2));
  }
}
