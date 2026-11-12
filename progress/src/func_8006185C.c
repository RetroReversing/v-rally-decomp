#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
#define CV(out,val,threshold) {f64 d=(val);if(!((threshold)<=d))out=(s32)d;else out=(s32)(d-(threshold))|0x80000000;}
extern s32 pool_get_item(s32, u16);
s32 font_text_width(void *, void *, u8, f32, u8);
extern void func_8004C100(s32, s32, s32, s32, s32);
extern void drawQuadEdges(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 gGameState[];
extern u8 stream_state[];
extern s32 D_800ADF80;
extern u8 D_80000002[];
extern u8 D_80000004[];
extern u8 *gSelectState;
extern u8 *gSelectBuffer;
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

/* Draws one row of the menu list box for `item` (a list entry with its own
 * font, position and value bar). mode 0 draws the bar for the main item at
 * gSelectBuffer; any other mode draws the bar for the selected sub-entry and
 * places the box according to the menu layout bytes at gSelectState+0x238/0x239. */
#ifdef PORT
#define ID_PTR(x) ((void *)(uintptr_t)(x))
#else
#define ID_PTR(x) ((void *)(x))
#endif

void func_8006185C(u8 *item, s32 mode)
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
  font = pool_get_item(*((s32 *) (stream_state + 0x807A)), *((u16 *) (((u8 *) item) + 8)));
  table = gSelectState + ((*((s8 *) (((u8 *) item) + 14))) * 2);
  result = font_text_width((void *)(gSelectState + (((*((u8 *) (((u8 *) table) + 0xd0))) * 4) + 0xe4)), ID_PTR(font), (u8)(*((u8 *) (((u8 *) table) + 0xd1))), (f32)(*((f32 *) (((u8 *) item) + 20))), (u8)(0));
  extent = result + 24;
  offset = *((s16 *) (((u8 *) item) + 10));
  do {center=offset; if(offset<0){offset=0;center=-center-result;}} while(0); offset=center;
  x = offset - 12;
  xend = x + extent;
  top = (*((u16 *) (((u8 *) item) + 12))) - 8;
  boxheight = 32;
  drawQuadEdges(D_800ADF80, (u16) x, (u16) top, (u16) x, (u16) (top + boxheight), (u16) xend, (u16) (top + boxheight), (u16) xend, (u16) top);
  if (!(mode & 255))
  {
    gap = (*((u16 *) (((u8 *) gSelectBuffer) + 0))) - xend;
    CV(w, (((f64) (*((f32 *) (((u8 *) gSelectBuffer) + 4)))) - D_800A55E8) * D_800A55F0, D_800A55F8);
    width = w;
    {f64 d=((f64) (*((f32 *) (((u8 *) gSelectBuffer) + 4)))) * D_800A5600;if(!(D_800A5608<=d))h=(s32)d;else {h=(s32)(d-D_800A5608);h|=0x80000000;}}
    height = h;
    { u8 *p = gSelectBuffer; u32 n = p[8]; y = (*((u16 *) (p + 2))) + ((*((u16 *) (((u8 *) (*((u8 **) (((u8 *) stream_state) + 0x32F2)))) + 34))) * n); }
    CV(c, (double) (((f64) ((u16) y)) + (((f64) ((u16) height)) * D_800A5610)), D_800A5618);
    func_8004C100(D_800ADF80, (u16) (x + extent), (u16) (top + (boxheight >> 1)), (u16) ((gap + (x + extent)) - 4), (u16) c);
    drawQuadEdges(D_800ADF80, (u16) ((*((u16 *) (((u8 *) gSelectBuffer) + 0))) - 3), (u16) (y - 3), (u16) ((*((u16 *) (((u8 *) gSelectBuffer) + 0))) - 3), (u16) ((y + height) + 2), (u16) (((*((u16 *) (((u8 *) gSelectBuffer) + 0))) + width) + 2), (u16) ((y + height) + 2), (u16) (((*((u16 *) (((u8 *) gSelectBuffer) + 0))) + width) + 2), (u16) (y - 3));
  }
  else
  {

    gap = 356 - xend;
    i = 0;
    count = *((u8 *) (((u8 *) item) + 77));
    node = *((u8 **) (((u8 *) item) + 40));
    if (count)
    {
      do
      {
        if (i == (*((u8 *) (((u8 *) gSelectState) + 0x239))))
        {
          font = pool_get_item(*((s32 *) (stream_state + 0x807A)), *((u16 *) (((u8 *) node) + 4)));
          table = gSelectState + ((*((s8 *) (((u8 *) node) + 10))) * 2);
          width = font_text_width((void *)(gSelectState + (((*((u8 *) (((u8 *) table) + 0xd0))) * 4) + 0xe4)), ID_PTR(font), (u8)(*((u8 *) (((u8 *) table) + 0xd1))), (f32)(*((f32 *) (((u8 *) node) + 16))), (u8)(0));
          break;
        }
        ++i;
        node = *((u8 **) (((u8 *) node) + 0));
      }
      while (i < count);
    }
    CV(new_var, ((f64) (*((f32 *) (((u8 *) node) + 20)))) * D_800A5620, D_800A5628);
    height = new_var;
    if ((*((u8 *) (((u8 *) gSelectState) + 0x238))) == 0)
    {
      y = ((*((u8 *) (((u8 *) gSelectState) + 0x239))) * 20) + 280;
    }
    else
      if ((*((u8 *) (((u8 *) gSelectState) + 0x238))) == 1)
    {
      if (x || boxheight)
      {
        y = ((*((u8 *) (((u8 *) gSelectState) + 0x239))) * 20) + 260;
      }
      else
      {
        y = ((*((u8 *) (((u8 *) gSelectState) + 0x239))) * 20) + 260;
      }
    }
    else
    {
      y = ((*((u8 *) (((u8 *) gSelectState) + 0x239))) * 20) + 292;
    }
    CV(c, ((f64) ((u16) y)) + (((f64) ((u16) height)) * D_800A5630), D_800A5638);
    func_8004C100(D_800ADF80, (u16) (x + extent), (u16) (top + (boxheight >> 1)), (u16) ((gap + (x + extent)) - 4), (u16) c);
    drawQuadEdges(D_800ADF80, 352, (u16) (y - 4), 352, (u16) ((y + height) + 4), (u16) (width + 360), (u16) ((y + height) + 4), (u16) (width + 360), (u16) (y - 4));
  }
}