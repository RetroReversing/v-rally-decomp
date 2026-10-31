extern s32 func_8006B924(void *, s32);
extern u8 D_800C35A0[];
extern s32 D_800C3750[][4];
typedef struct 
{
  u8 pad[0x15A];
  u16 v;
} Table;
extern Table D_800C7124;
extern u8 D_800ADF40[];
static inline static static u8 *inline_fn(u8 *arg0, u8 arg1)
{
  return arg0 + (arg1 * 4);
}

void func_8006C640(s32 arg0, s32 arg1)
{
  int __repair_literal;
  u8 idx = *((u8 *) ((*((u8 **) D_800C35A0)) + 0x21));
  s32 step = idx << 6;
  s32 stride = idx * 3;
  s32 *value = (s32 *) inline_fn(D_800ADF40, idx);
  u8 i = 0;
  s32 j;
  int new_var;
  do
  {
    s32 off;
    u8 *base = (u8 *) D_800C3750;
    j = i;
    __repair_literal = 0x10;
    off = j * __repair_literal;
    new_var = (idx * 4) + j;
    arg1 = func_8006B924((base + off) + step, arg1);
    if ((arg1 & 0xFF) == 5)
    {
      ((Table *) (((u8 *) (&D_800C7124)) + ((stride + j) * 2)))->v = 0xFFFF;
    }
    else
    {
      s32 d;
 do { d = (*value) - D_800C3750[new_var][0]; } while (0);
      if (d >= 0)
      {
        if (d >= 0x4000)
        {
          d = 0x3FFE;
        }
        d &= ~1;
      }
      else
      {
        d = -d;
        if (d >= 0x4000)
        {
          d = 0x3FFE;
        }
        d |= 1;
      }
      ((Table *) (((u8 *) (&D_800C7124)) + ((stride + (i & 0xFF)) * 2)))->v = (s16) (d | ((arg1 & 0xFF) << 14));
    }
    i++;
  }
  while (((u32) (i & 0xFF)) < 3);
}
