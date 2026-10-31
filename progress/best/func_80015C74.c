s32 func_8007EE9C();
s32 func_80097E30();
extern s32 D_8009BF88[];
extern s8 D_800A16D5;
extern char D_800A73E0[];
void func_80015C74(void *arg0, s32 arg1)
{
  s32 off;
  u8 *entry;
  s32 i;
  u8 *sub;
  u8 *p;
  u32 j;
  u8 *base;
  s32 a1;
  s32 pad[4];
  s32 cnt;
  base = arg0;
  a1 = (j = arg1);
  cnt = *((u16 *) (base + 0x20));
  i = 0;
  if (cnt > 0)
  {
    off = 0x3C;
    do
    {
      entry = base + off;
      sub = *((u8 **) (entry + 8));
      p = sub + 0x24;
      j = 0;
      if (*((u32 *) (sub + 0x20)))
      {
        do
        {
          i = (*((u16 *) (p + 6))) << 2;
          ((void (*)(void *, s32)) (*((void **) (((u8 *) D_8009BF88) + i))))(entry, a1);
          j++;
          p += 8;
        }
        while (j < (*((u32 *) ((*((u8 **) (entry + 8))) + 0x20))));
      }
      func_8007EE9C(*((void **) (entry + 8)));
      off += 0x38;
      i++;
    }
    while (i < (*((u16 *) (base + 0x20))));
  }
  *((u16 *) (base + 0x20)) = 0;
  func_80097E30(D_800A73E0 + 0x6C0C, 0, 0x460);
  D_800A16D5 = 0;
}
