s32 func_8001095C();
void *func_80022318();
s32 func_80022668();
void *func_8004240C();
f32 sqrtf();
extern char D_800A3FF0[];
extern char D_800AE850[];
extern void *D_800C35A0;
extern void *D_800C7F84;
void func_80010468(void)
{
  u32 count;
  s32 i;
  s32 idx;
  void *temp_s1;
  void *temp_v0;
  void *temp_a0;
  void *node;
  void *temp_v0_2;
  f32 dx;
  f32 dy;
  f32 dz;
  f32 sx;
  f32 sy;
  f32 sz;
  count = *((u8 *) (((char *) D_800C35A0) + 0xF));
  if (count == 0)
  {
    return;
  }
  i = 1;
  do
  {
    idx = ((i & 0xFF) - 1) * 2;
    D_800C7F84 = func_8004240C(idx | 1);
    do
    {
      temp_s1 = func_8004240C(idx + 2);
      temp_v0 = func_80022318(((char *) D_800C7F84) + 0x28, D_800A3FF0);
      if (temp_v0 != NULL)
      {
        ((void (*)(void *)) (*((s32 *) (((char *) temp_v0) + 0x14))))(*((void **) (((char *) temp_v0) + 0x10)));
        func_8001095C(temp_s1);
        temp_a0 = *((void **) (((char *) temp_v0) + 0x10));
        func_80022668(temp_a0, *((s32 *) (((char *) temp_a0) + 8)));
        sx = *((f32 *) (((char *) D_800C7F84) + 0x118));
        dx = (*((f32 *) (((char *) D_800C7F84) + 0x124))) - sx;
        sx = dx * dx;
        sy = *((f32 *) (((char *) D_800C7F84) + 0x11C));
        dy = (*((f32 *) (((char *) D_800C7F84) + 0x128))) - sy;
        sy = dy * dy;
        sz = *((f32 *) (((char *) D_800C7F84) + 0x120));
        dz = (*((f32 *) (((char *) D_800C7F84) + 0x12C))) - sz;
        sz = dz * dz;
        if ((*((s32 *) (((char *) D_800C7F84) + 0x20))) & 0x880000)
        {
          *((s32 *) (((char *) temp_s1) + 0x194)) = 0;
        }
        else
        {
          *((s32 *) (((char *) temp_s1) + 0x194)) = (s32) sqrtf(sy + (sx + sz));
        }
        *((s32 *) (((char *) D_800C7F84) + 0x194)) = *((s32 *) (((char *) temp_s1) + 0x194));
        *((s32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) D_800C7F84) + 0x24)))) + 0x68)))) + 0x1C)) = *((s32 *) (((char *) temp_s1) + 0x194));
        if ((i & 0xFF) == 1)
        {
          node = *(*((void ***) (D_800AE850 + 0x73F0)));
          if (node != NULL)
          {
            do
            {
              if (node != (*((void **) (((char *) D_800C7F84) + 0x24))))
              {
                temp_v0_2 = *((void **) (((char *) node) + 0x5C));
                dx = ((f32) (*((s32 *) (((char *) temp_v0_2) + 0x54)))) - (*((f32 *) ((((char *) D_800C7F84) + 0x38) + 0xE0)));
                dy = ((f32) (*((s32 *) (((char *) temp_v0_2) + 0x58)))) - (*((f32 *) ((((char *) D_800C7F84) + 0x38) + 0xE4)));
                dz = ((f32) (*((s32 *) (((char *) temp_v0_2) + 0x5C)))) - (*((f32 *) ((((char *) D_800C7F84) + 0x38) + 0xE8)));
                *((s32 *) (((char *) (*((void **) (((char *) node) + 0x68)))) + 0x1C)) = (s32) sqrtf(((dx * dx) + (dy * (((f32) (*((s32 *) (((char *) temp_v0_2) + 0x58)))) - (*((f32 *) ((((char *) D_800C7F84) + 0x38) + 0xE4)))))) + (dz * dz));
              }
              node = *((void **) (((char *) node) + 4));
            }
            while (node != NULL);
          }
        }
      }
    }
    while (0);
    i++;
  }
  while (count >= (i & 0xFF));
}
