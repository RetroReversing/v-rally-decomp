typedef struct { s32 pad[3]; s32 a[3]; s32 b[3]; s32 pad2; } E15534;
typedef struct { E15534 *list; u16 count; } H15534;
extern E15534 D_8009BBC0[];
extern H15534 D_8009BEE0;
extern u16 D_8009BEE4;
extern char D_800C02AE[];
void func_80015534(s32 arg0, char *arg1)
{
  char pad[8];
  H15534 *h;
  E15534 *list;
  E15534 *dst;
  E15534 *src;
  char *obj;
  u32 i;
  s32 y, z;
  h = &D_8009BEE0;
  arg1 += *(u16 *)(arg1 + 0x22) * 0x38 + 0x3C;
  *(H15534 **)(arg1 + 0x14) = h;
  list = h->list;
  i = 0;
  if (D_8009BEE4 != 0) {
    obj = *(char **)(D_800C02AE + 0x32F2);
    do {
      dst = &list[i];
      src = &D_8009BBC0[i];
      dst->a[0] = -src->a[0];
      y = -src->a[1];
      dst->a[1] = -src->a[2]; dst->a[2] = y;
      dst->b[0] = -src->b[0];
      y = -src->b[1];
      dst->b[1] = -src->b[2]; dst->b[2] = y;
      if (*(u16 *)(obj + 0xE) == 2) {
        if (i - 2 < 2) dst->a[2] -= 0x72;
        if (i - 5 < 3) dst->a[2] -= 0x72;
      }
      i++;
    } while (i < h->count);
  }
  h->count = 5;
}
