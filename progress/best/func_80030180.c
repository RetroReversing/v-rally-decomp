#define PTS(off) (*(u16 *)((off) + *(u8 **)(arg0 + 0x54)))
void func_80030180(u8 *o, s32 arg1, s16 arg2, s16 *out)
{
  u8 *arg0 = o;
  s16 d[3];
  s16 d0;
  s32 t;
  s32 prev;
  s32 next;
  s32 a;
  s32 b;
  int new_var2;
  u8 *base;
  s16 *new_var;
  u16 *pa;
  u16 *pb;
  s32 one;
  arg1 = (*((s32 *) (arg0 + 0x4C))) + (arg1 * (*((u16 *) (arg0 + 0x8A))));
  t = arg2;
  prev = arg1 - 2;
  next = arg1 + 2;
  if (t < 500)
  {
    base = *((u8 **) (arg0 + 0x54));
    a = arg1 * 6;
    b = prev * 6;
    pa = (u16 *) (a + base);
    pb = (u16 *) (b + base);
    d0 = (*pa) - (*pb);
  }
  else
  {
    base = *((u8 **) (arg0 + 0x54));
    a = next * 6;
    b = arg1 * 6;
    pa = (u16 *) (a + base);
    pb = (u16 *) (b + base);
    d0 = (*pa) - (*pb);
    t -= 500;
  }
  new_var = &d[0];
  new_var2 = b + 2;
  d[0] = d0;
  d[1] = PTS(a + 2) - PTS(new_var2);
  d[2] = PTS(a + 4) - PTS(b + 4);
  d[0] = ((*new_var) * t) / 500;
  d[1] = (d[1] * t) / 500; d[2] = (d[2] * t) / 500;
  out[0] = PTS(b) + d[0];
  out[1] = PTS(t = new_var2) + d[1];
  out[2] = PTS(b + 4) + d[2];
}

