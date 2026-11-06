#define PTS(off) (*(u16 *)((off) + *(u8 **)(arg0 + 0x54)))
#define COORD(off, c) (((u16 *)(*(u8 **)(arg0 + 0x54)))[(off)/2 + c])
void func_80030180(void *o, s32 arg1, s16 arg2, s16 *out)
{
  u8 *arg0 = (u8 *) o;
  s16 d[3];
  s16 d0;
  s32 t;
  s32 prev;
  s32 next;
  s32 a;
  s32 b;
  u8 *base;
  u16 *pa;
  u16 *pb;
  int new_var;
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
  d[0] = d0;
  new_var = 1;
  d[1] = COORD(a, 1) - COORD(b, new_var);
  d[2] = COORD(a, 2) - COORD(b, 2);
  d[0] = (d[0] * t) / 500;
  d[1] = (d[1] * t) / 500;
  d[2] = (d[2] * t) / 500;
  out[0] = COORD(b, 0) + d[0];
  out[1] = COORD(b, 1) + d[new_var];
  out[2] = COORD(b, 2) + d[2];
}

