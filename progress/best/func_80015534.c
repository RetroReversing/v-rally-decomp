extern char D_8009BBC0[];
extern char *D_8009BEE0;
extern u16 D_8009BEE4;
extern char D_800C02AE[];
void func_80015534(s32 arg0, char *arg1)
{
  char pad[8];
  char **pp;
  s32 *dst;
  s32 *src;
  s32 new_var3;
  char *obj;
  u32 i;
  s32 v0;
  char *new_var2;
  s32 new_var;
  s32 v1;
  (void) pad;
  (void) arg0;
  pp = &D_8009BEE0;
  arg1 += ((*((u16 *) (arg1 + 0x22))) * 0x38) + 0x3C;
  *((s32 *) (arg1 + 0x14)) = (s32) pp;
  dst = (s32 *) (*pp);
  i = 0;
  if (D_8009BEE4 != 0)
  {
    obj = *((char **) (D_800C02AE + 0x32F2));
    src = (s32 *) D_8009BBC0;
    do
    {
      ;
      *((s32 *) (((char *) dst) + 0xC)) = -(*((s32 *) (((char *) src) + 0xC)));
      v1 = *((s32 *) (((char *) src) + 0x10));
      v0 = *((s32 *) (((char *) src) + 0x14));
      *((s32 *) (((char *) dst) + 0x10)) = -v0;
      *((s32 *) (((char *) dst) + 0x14)) = -v1;
      new_var3 = *((s32 *) (((char *) src) + 0x1C));
      v0 = *((s32 *) (((char *) src) + 0x18));
      *((s32 *) (((char *) dst) + 0x18)) = -v0;
      dst = (s32 *) (*pp);
      new_var = new_var3;
      v1 = new_var;
      v0 = *((s32 *) ((new_var2 = (char *) src) + 0x20));
      *((s32 *) (((char *) dst) + 0x1C)) = -v0;
      *((s32 *) (((char *) dst) + 0x20)) = -v1;
      if ((*((u16 *) (obj + 0xE))) == 2)
      {
        if (((u32) (i - 2)) < 2U)
        {
          new_var2 = ((char *) dst) + 0x14;
          v0 = *((s32 *) (((char *) dst) + 0x14));
          v0 -= 0x72;
          *((s32 *) new_var2) = v0;
        }
        if (((u32) (i - 5)) < 3U)
        {
          v0 = *((s32 *) (((char *) dst) + 0x14));
          v0 -= 0x72;
          *((s32 *) (((char *) dst) + 0x14)) = v0;
        }
      }
      src = (s32 *) (((char *) src) + 0x28);
      i += 1;
      dst = (s32 *) (((char *) dst) + 0x28);
    }
    while (i < (*((u16 *) (((char *) pp) + 4))));
  }
  *((u16 *) (((char *) pp) + 4)) = 5;
}
