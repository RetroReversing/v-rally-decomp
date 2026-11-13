typedef struct 
{
  u8 *data;
  u16 count;
} Obj197;
typedef struct 
{
  u16 a;
  u16 mask;
} MaskEnt;
extern s16 gSlotArgOffsets[][17];
extern MaskEnt gSlotMasks[][17];
extern u8 g_dark_mode;
extern u16 D_800C792C;
void func_80019440(void *, void *, void *, s32, void *);

/* Draws each enabled slot of obj: a slot is skipped when its entry in the
 * mode table is negative, when the caller's mask doesn't select it, or when
 * the hide bits in D_800C792C turn it off (slots 3-6 and 9-11; labels follow jtbl_800A41F8). Each slot's arguments
 * are offset by its entry in gSlotArgOffsets. */
void func_800197A4(Obj197 *obj, s32 *arg1, void *arg2, s32 arg3, u32 mask, s32 *arg5)
{
  s32 i;
  s16 v;
  int stride;
  for (i = 0; i < obj->count; i++)
  {
    if (gSlotArgOffsets[g_dark_mode][i] < 0)
    {
      continue;
    }
    if (!(mask & gSlotMasks[g_dark_mode][i].a))
    {
      continue;
    }
    switch (i)
    {
      case 3: case 5:
        if (D_800C792C & 0x8000)
      {
        continue;
      }
        break;

      case 4: case 6:
        if (D_800C792C & 0x4000)
      {
        continue;
      }
        break;

      case 10:
        if (D_800C792C & 0x800)
      {
        continue;
      }
        break;

      case 11:
        if (D_800C792C & 0x2000)
      {
        continue;
      }
        break;

      case 9:
        if (D_800C792C & 0x1000)
      {
        continue;
      }
        break;

      case 7:

      case 8:
        break;

    }

    stride = i * 0x24;
    v = gSlotArgOffsets[g_dark_mode][i];
    func_80019440(obj->data + stride, arg1 + v, arg2, arg3, arg5 + v);
  }

}
