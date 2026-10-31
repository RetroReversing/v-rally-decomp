typedef struct 
{
  u8 pad[0x20];
  u16 index;
  s16 slot;
} Obj;
s32 func_8005946C(s32, s32);
extern u8 D_800C02AE;
extern u8 *D_800D0634;
s32 func_80063D9C(s32 arg0)
{
  Obj *p;
  u8 *base;
  s32 off;
  s32 cur;
  s32 count;
  u8 *new_var;
  u8 mask;
  s32 next;
  s32 found;
  Obj *p2;
  s32 off2;
  s32 one;
  u8 *ent;
  s32 bit;
  u16 n;
  u16 idx;
  p = *((Obj **) (((u8 *) (&D_800C02AE)) + 0x32F2));
  idx = p->index;
  found = -1;
  base = D_800D0634;
  off = idx * 708;
  {
    u8 *scan;
    scan = (u8 *) (off + ((s32) base));
    n = *((u16 *) (scan + 0x14));
  }
  cur = *((u8 *) (((u8 *) p) + 0x23));
  count = 0;
  if (((s32) (n - 1)) > 0)
  {
    p2 = p;
    off2 = off;
    one = 1;
    do
    {
      ent = (u8 *) (off2 + ((s32) base));
      n = *((u16 *) (ent + 0x14));
      if (((s8) cur) < (n - 1))
      {
        cur += 1;
      }
      else
      {
        cur = 0;
      }
      mask = *((((u8 *) (&D_800C02AE)) + 0x327E) + p2->index);
      bit = one << cur;
      next = count;
      cur = mask & bit;
      next += 1;
      if (cur == bit)
      {
        found = cur;
        break;
      }
      count = next;
      base = D_800D0634;
      off = (p2->index * 708) + ((s32) base);
      n = *((u16 *) (((u8 *) off) + 0x14));
      new_var = base;
      ent = (u8 *) (off2 + ((s32) new_var));
    }
    while (((s8) next) < (n - 1));
  }
  count = 1;
  if (((s8) found) != (-count))
  {
    ;
    *((s16 *) (((u8 *) (*((Obj **) (((u8 *) (&D_800C02AE)) + 0x32F2)))) + 0x22)) = (s8) found;
    func_8005946C(arg0, (u16) ((s8) found));
  }
  return 0;
}
