#define P(p,o) (*(void**)((u8*)(p)+o))
#define H(p,o) (*(s16*)((u8*)(p)+o))
#define U(p,o) (*(u16*)((u8*)(p)+o))
#define W(p,o) (*(s32*)((u8*)(p)+o))
extern void *D_800C7F84;
extern void *D_800C35A0;
extern s32 func_8003B310;
extern s32 func_8003B008;
extern s32 func_8003B240;
extern unsigned char func_8003AE84;
extern s32 func_8003B2C0;
extern s32 func_8003AF74;
extern s32 func_8003A9AC();
extern s32 func_80034FF0();
extern void *func_80040260();
void func_8003D9C8(s32 arg0, s32 arg1, int arg2)
{
  void *root = D_800C7F84;
  s16 new_var;
  void *event = D_800C35A0;
  void *v = P(root, 0x178);
  void *item;
  s32 y = H(v, 10);
  s32 x = H(v, 8);
  s32 height = H(v, 14);
  u16 base = y + 6;
  s32 index = 0;
  s32 step;
  s32 tx;
  s32 xx;
  switch (U(event, 14))
  {
    case 1:
      if (!U(event, 30))
    {
      void *__repair_cached_pointer = D_800C7F84;
      y = (y + height) - 18;
      arg2--;
      func_8003A9AC(arg0, x + 77, y, &func_8003B310, arg1, (u16) arg2, 0);
      item = func_80040260(arg0, (s16) (U(P(__repair_cached_pointer, 0x178), 8) + 68), (s16) y, 2, &func_8003B008, 0);
      W(item, 0xa4) = func_80034FF0(arg1 + 76);
      H(item, 0x76) = arg2;
    }
    else
    {
      step = 11;
      index = 2;
      do
      {
        func_8003A9AC(arg0, H(P(D_800C7F84, 0x178), 8) + 95, base + ((u16) step), &func_8003B310, arg1, (u16) index, 0);
        item = func_80040260(arg0, (s16) (U(P(D_800C7F84, 0x178), 8) + 86), (s16) (step + base), 2, &func_8003B008, 0);
        tx = func_80034FF0(arg1 + 76, 0);
        step += 11;
        H(item, 0x76) = index;
        P(item, 0xa8) = D_800C7F84;
        index++;
        W(item, 0xa4) = tx;
      }
      while (((u16) index) < 5);
    }
      break;

    case 2:
      if (!(U(event, 18) & 1))
    {
      x += 22;
      if (W(root, 12) == 3)
      {
        x -= 14;
      }
    }
      if (!U(D_800C35A0, 30))
    {
      v = P(D_800C7F84, 0x178);
      y = (H(v, 10) + H(v, 14)) - 18;
      arg2--;
      func_8003A9AC(arg0, x + 57, y, &func_8003B310, arg1, (u16) arg2, 0);
      item = func_80040260(arg0, (s16) (x + 46), (s16) y, 2, &func_8003B008, 0);
      tx = func_80034FF0(arg1 + 76, 0);
      W(item, 0xa4) = tx;
      H(item, 0x76) = arg2;
    }
    else
    {
      xx = x + 49;
      y = base + 10;
      new_var = (s16) y;
      index &= 65535;
      func_8003A9AC(arg0, xx, y, &func_8003B240, arg1, (u16) index, 0);
      x = (s16) (x + 40);
      item = func_80040260(arg0, x, new_var, 2, &func_8003AE84, 0);
      ;
      W(item, 0xa4) = func_80034FF0(arg1 + 76, 0);
      ((u8 *) item)[0x90] = 254;
      ((u8 *) item)[0x91] = 213;
      ((u8 *) item)[0x92] = 30;
      ((u8 *) item)[0x93] = 255;
      func_8003A9AC(arg0, xx, base, &func_8003B2C0, arg1, (u16) index, 0);
      item = func_80040260(arg0, x, (s16) base, 2, &func_8003AF74, 0);
      W(item, 0xa4) = func_80034FF0(arg1 + 76, 0);
    }
      P(item, 0xa8) = D_800C7F84;
      P(item, 0xa8) = D_800C7F84;
      break;

  }

}
