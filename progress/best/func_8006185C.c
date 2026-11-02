#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
#define CV(out,val,threshold) {f64 d=(val);if(!((threshold)<=d))out=(s32)d;else out=(s32)(d-(threshold))|0x80000000;}
extern s32 func_80057918(s32, u16);
extern s32 func_8000C9B0(void *, s32, u8, s32, s32);
extern void func_8004C100(s32, s32, s32, s32, s32);
extern void func_8004C1B4(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_800A73E0[];
extern u8 D_800C02AE[];
extern s32 D_800ADF80;
extern u8 D_80000002[];
extern u8 D_80000004[];
extern u8 *D_800A1468;
extern u8 *D_800A14D0;
extern f64 D_800A55E8;
extern f64 D_800A55F0;
extern f64 D_800A55F8;
extern f64 D_800A5600;
extern f64 D_800A5608;
extern f64 D_800A5610;
extern f64 D_800A5618;
extern f64 D_800A5620;
extern f64 D_800A5628;
extern f64 D_800A5630;
extern f64 D_800A5638;
void func_8006185C(u8 *arg0, s32 arg1)
{
  u32 scratch[2];
  s32 result;
  s32 font;
  u32 boxheight;
  u8 *table;
  s32 x;
  s32 xend;
  s32 top;
  s32 extent;
  s32 gap;
  s32 height;
  s32 y;
  s32 center;
  s16 anchor;
  s32 offset;
  s32 width = 0;
  u32 h;
  u32 c;
  u32 w;
  u8 i;
  u8 count;
  u32 new_var;
  u8 *node;
  font = func_80057918(*((s32 *) (D_800C02AE + 0x807A)), *((u16 *) (((u8 *) arg0) + 8)));
  table = D_800A1468 + ((*((s8 *) (((u8 *) arg0) + 14))) * 2);
  result = func_8000C9B0(D_800A1468 + (((*((u8 *) (((u8 *) table) + 0xd0))) * 4) + 0xe4), font, *((u8 *) (((u8 *) table) + 0xd1)), *((s32 *) (((u8 *) arg0) + 20)), 0);
  extent = result + 24;
  offset = *((s16 *) (((u8 *) arg0) + 10));
  offset = (offset < 0) ? ((-offset) - result) : offset;
  x = offset - 12;
  xend = x + extent;
  top = (*((u16 *) (((u8 *) arg0) + 12))) - 8;
  boxheight = 32;
  func_8004C1B4(D_800ADF80, (u16) x, (u16) top, (u16) x, (u16) (top + boxheight), (u16) xend, (u16) (top + boxheight), (u16) xend, (u16) top);
  if (!(arg1 & 255))
  {
    gap = (*((u16 *) (((u8 *) D_800A14D0) + 0))) - xend;
    CV(w, (((f64) (*((f32 *) (((u8 *) D_800A14D0) + 4)))) - D_800A55E8) * D_800A55F0, D_800A55F8);
    width = w;
    CV(h, ((f64) (*((f32 *) (((u8 *) D_800A14D0) + 4)))) * D_800A5600, D_800A5608);
    height = h;
    y = (*((u16 *) (((u8 *) D_800A14D0) + 2))) + ((*((u8 *) (((u8 *) D_800A14D0) + 8))) * (*((u16 *) (((u8 *) (*((u8 **) (((u8 *) D_800C02AE) + 0x32F2)))) + 34))));
    CV(c, (double) (((f64) ((u16) y)) + (((f64) ((u16) height)) * D_800A5610)), D_800A5618);
    func_8004C100(D_800ADF80, (u16) (x + extent), (u16) (top + (boxheight >> 1)), (u16) ((gap + (x + extent)) - 4), (u16) c);
    func_8004C1B4(D_800ADF80, (u16) ((*((u16 *) (((u8 *) D_800A14D0) + 0))) - 3), (u16) (y - 3), (u16) ((*((u16 *) (((u8 *) D_800A14D0) + 0))) - 3), (u16) ((y + height) + 2), (u16) (((*((u16 *) (((u8 *) D_800A14D0) + 0))) + width) + 2), (u16) ((y + height) + 2), (u16) (((*((u16 *) (((u8 *) D_800A14D0) + 0))) + width) + 2), (u16) (y - 3));
  }
  else
  {
    new_var = h;
    gap = 356 - xend;
    i = 0;
    count = *((u8 *) (((u8 *) arg0) + 77));
    node = *((u8 **) (((u8 *) arg0) + 40));
    if (count)
    {
      do
      {
        if (i == (*((u8 *) (((u8 *) D_800A1468) + 0x239))))
        {
          font = func_80057918(*((s32 *) (D_800C02AE + 0x807A)), *((u16 *) (((u8 *) node) + 4)));
          table = D_800A1468 + ((*((s8 *) (((u8 *) node) + 10))) * 2);
          width = func_8000C9B0(D_800A1468 + (((*((u8 *) (((u8 *) table) + 0xd0))) * 4) + 0xe4), font, *((u8 *) (((u8 *) table) + 0xd1)), *((s32 *) (((u8 *) node) + 16)), 0);
          break;
        }
        ++i;
        node = *((u8 **) (((u8 *) node) + 0));
      }
      while (i < count);
    }
    CV(new_var, ((f64) (*((f32 *) (((u8 *) node) + 20)))) * D_800A5620, D_800A5628);
    height = new_var;
    if ((*((u8 *) (((u8 *) D_800A1468) + 0x238))) == 0)
    {
      y = ((*((u8 *) (((u8 *) D_800A1468) + 0x239))) * 20) + 280;
    }
    else
      if ((*((u8 *) (((u8 *) D_800A1468) + 0x238))) == 1)
    {
      if (x || boxheight)
      {
        y = ((*((u8 *) (((u8 *) D_800A1468) + 0x239))) * 20) + 260;
      }
      else
      {
        y = ((*((u8 *) (((u8 *) D_800A1468) + 0x239))) * 20) + 260;
      }
    }
    else
    {
      y = ((*((u8 *) (((u8 *) D_800A1468) + 0x239))) * 20) + 292;
    }
    CV(c, ((f64) ((u16) y)) + (((f64) ((u16) height)) * D_800A5630), D_800A5638);
    func_8004C100(D_800ADF80, (u16) (x + extent), (u16) (top + (boxheight >> 1)), (u16) ((gap + (x + extent)) - 4), (u16) c);
    func_8004C1B4(D_800ADF80, 352, (u16) (y - 4), 352, (u16) ((y + height) + 4), (u16) (width + 360), (u16) ((y + height) + 4), (u16) (width + 360), (u16) (y - 4));
  }
}

