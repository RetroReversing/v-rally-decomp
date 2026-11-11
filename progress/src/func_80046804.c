typedef struct 
{
  s32 x;
  s32 y;
  s32 z;
  s32 w;
} Vec4_80046804;
extern void (*D_800A0264[])(u8 *, s32, u8 *, s32);

/* Zone trigger for one car (arg1) against a zone (*arg0). When the car is within
 * range of the zone's centre, it sets this car's bit in the zone's flag word; if
 * the car is moving towards the zone and the bit was not yet set, it runs each of
 * the zone's entry handlers (u16 handler, u16 arg, s32 size, data) once. Moving away
 * clears the bit. */
void func_80046804(u8 **arg0, u8 *arg1)
{
  Vec4_80046804 dv;
  Vec4_80046804 pos;
  Vec4_80046804 dd;
  s32 unused[2];
  s32 *zone;
  s32 bit;
  u16 bit2;
  s32 t;
  s32 i;
  s32 n;
  u8 *e;
  zone = (s32 *) (*arg0);
  pos.x = *((s32 *) ((*((u8 **) (arg1 + 0x80))) + 0x2B8));
  pos.z = *((s32 *) ((*((u8 **) (arg1 + 0x80))) + 0x2C0));
  dd.x = pos.x - zone[0];
  dd.z = pos.z - zone[2];
  if (((u32) (((dd.x >> 4) * (dd.x >> 4)) + ((dd.z >> 4) * (dd.z >> 4)))) < 50000)
  {
    bit = 1;
    n = (u16) (((*((u16 *) ((*((u8 **) (arg1 + 0x48))) + 0x2E))) * 2) | 1);
    i = 0;
    if (n > 0)
    {
      do
      {
        bit = (bit & 0xFFFF) << 1;
        i++;
      }
      while (i < n);
    }
    dv.x = pos.x - zone[0];
    dv.y = pos.y - zone[1];
    dv.z = pos.z - zone[2];
    t = (bit & 0xFFFF) << 1;
    bit2 = t;
    if (((dv.x * zone[3]) + (dv.z * zone[5])) < 0)
    {
      if (((*((u16 *) (((u8 *) zone) + 0x1A))) & t) == bit2)
      {
        i = 0;
        e = ((u8 *) zone) + 0x1C;
        if (i < (*((u16 *) (((u8 *) zone) + 0x18))))
        {
          loop:
          D_800A0264[*((u16 *) e)](e + 8, *((u16 *) (e + 2)), arg1, 0);

          i++;
          e += (*((s32 *) (e + 4))) + 8;
          if (i < (*((u16 *) (((u8 *) zone) + 0x18))))
          {
            goto loop;
          }
        }
      }
      *((u16 *) (((u8 *) zone) + 0x1A)) = ((*((u16 *) (((u8 *) zone) + 0x1A))) | bit) & (~bit2);
    }
    else
    {
      *((u16 *) (((u8 *) zone) + 0x1A)) = ((*((u16 *) (((u8 *) zone) + 0x1A))) | bit2) & (~bit);
    }
  }
}
