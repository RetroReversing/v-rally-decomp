extern void *gSelectState;
extern u16 D_800A16E0[];
extern void *gRecords;
s32 select_stream_char(u8, u8, u8);
void *list_advance(u32, void *);
s32 slotSetSelected(s32, s32);

/* Refreshes the car-select screen: picks the selected car's record, writes the
 * stat row values (rows w..w+4) and the start-label id into the screen's
 * object lists. */
void func_8006AE34(void)
{
  s8 car;
  s16 label;
  s16 stat;
  s32 z;
  s32 y;
  s32 w;
  s32 new_var;
  u8 k;
  char index;
  void *p;
  void *b;
  void *c;
  void *base;
  void *t = gSelectState;
  b = gRecords;
  car = *((s8 *) (((u8 *) t) + 0x228));
  b = ((u8 *) b) + car;
  index = *((u8 *) (((u8 *) b) + 0x32));
  *((s8 *) (((u8 *) t) + 0x22b)) = car;
  base = gRecords;
  index = (s8) index;
  p = ((u8 *) base) + ((((s32) index) * 0x28) + 0x44);
  if ((*((u16 *) (((u8 *) base) + 0x1e))) == 0)
  {
    k = 0x1e;
  }
  else
  {
    k = 0x14;
    if ((*((u16 *) (((u8 *) base) + 0x1e))) == 5)
    {
      k = 0x2d;
    }
  }
  w = k & 255;
  new_var = select_stream_char(*((u8 *) (((u8 *) gRecords) + 0x1f)), *((u8 *) (((u8 *) gRecords) + 0x21)), *((u8 *) (((u8 *) gRecords) + 0x23)));
  y = new_var;
  t = list_advance(0, (void *)(*((void **) gSelectState)));
  y &= 255;
  z = y * 2;
  *((u16 *) (((u8 *) t) + 4)) = D_800A16E0[z / 2];
  slotSetSelected(w, *((u8 *) (((u8 *) p) + 9)));
  c = ((u8 *) p) + y;
  slotSetSelected(w + 1, *((u8 *) (((u8 *) c) + 0x10)));
  #ifdef PORT
  stat = *((s16 *) ((((u8 *) p) + z) + 0x1c));
#else
  stat = *((s16 *) (((u8 *) (z + ((s32) p))) + 0x1c));
#endif
  slotSetSelected(w + 2, (-((s16) (stat / 10))) + 2);
  slotSetSelected(w + 3, *((u8 *) (((u8 *) c) + 0x18)));
  slotSetSelected(w + 4, *((u8 *) (((u8 *) c) + 0x14)));
  {
    void *out = list_advance(2, (void *)(*((void **) gSelectState)));
    label = 0x128;
    index = (*((s8 *) (((u8 *) gSelectState) + 0x228))) == 0;
    if (index)
    {
      label = 0x126;
    }
    *((s16 *) (((u8 *) out) + 4)) = label;
  }
}
