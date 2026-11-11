typedef struct { s32 pad[3]; s32 a[3]; s32 b[3]; s32 pad2; } E15534;
typedef struct { E15534 *list; u16 count; } H15534;
extern E15534 D_8009BBC0[];
extern H15534 D_8009BEE0;
extern u16 D_8009BEE4;
extern char gStreamState[];

/* Copies the mirrored entries of the source table into the list for the current frame, negating their
 * vectors, and offsets two sets of entries when the track's kind is 2. Then sets the list count to 5. */
void func_80015534(s32 unused0, char *slot)
{
  char pad[8];
  H15534 *table;
  E15534 *list;
  E15534 *dst;
  E15534 *src;
  char *track;
  u32 i;
  s32 y, z;
  table = &D_8009BEE0;
  slot += *(u16 *)(slot + 0x22) * 0x38 + 0x3C;
  *(H15534 **)(slot + 0x14) = table;
  list = table->list;
  i = 0;
  if (D_8009BEE4 != 0) {
    track = *(char **)(gStreamState + 0x32F2);
    do {
      dst = &list[i];
      src = &D_8009BBC0[i];
      dst->a[0] = -src->a[0];
      y = -src->a[1];
      dst->a[1] = -src->a[2]; dst->a[2] = y;
      dst->b[0] = -src->b[0];
      y = -src->b[1];
      dst->b[1] = -src->b[2]; dst->b[2] = y;
      if (*(u16 *)(track + 0xE) == 2) {
        if (i - 2 < 2) dst->a[2] -= 0x72;
        if (i - 5 < 3) dst->a[2] -= 0x72;
      }
      i++;
    } while (i < table->count);
  }
  table->count = 5;
}
