typedef struct 
{
  u8 r;
  u8 g;
  u8 b;
  u8 a;
} Color4;
typedef struct 
{
  s16 x0;
  s16 y0;
  s16 x1;
  s16 y1;
} Rect;
typedef struct 
{
  u8 pad0[0x2C];
  Rect *rect;
  Color4 col;
} Arg2;
typedef struct 
{
  u8 pad0[8];
  s16 x0;
  s16 y0;
  s16 x1;
  s16 y1;
} Box;
typedef struct 
{
  u8 pad0[0x178];
  Box *box;
} Arg3;
typedef struct 
{
  u32 w0;
  u32 w1;
} Gfx;
extern Arg3 *D_800C7F84;
extern s32 func_800056FC(void *);
extern Gfx *func_80006008(s32);
extern void func_80006014(s32, Gfx *);
#define CMD(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (b); }
void func_800485F8(s32 arg0, s32 arg1, Arg2 *arg2, Arg3 *arg3)
{
  Color4 c;
  Gfx *g;
  s32 h;
  u32 col;
  if ((arg1 > 0) && (arg0 < (D_800C7F84->box->y0 + D_800C7F84->box->y1)))
  {
    arg2->rect->x0 = arg3->box->x0;
    arg2->rect->y0 = arg0;
    arg2->rect->x1 = arg3->box->x0 + arg3->box->x1;
    arg2->rect->y1 = arg0 + arg1;
    c = arg2->col;
    h = func_800056FC(D_800C7F84->box);
    g = func_80006008(h);
    CMD(g++, 0xE7000000, 0);
    CMD(g++, 0xE3000A01, 0x300000);
    CMD(g++, (0xED000000 | ((((s32) (D_800C7F84->box->x0 * 4.0f)) & 0xFFF) << 12)) | (((s32) (D_800C7F84->box->y0 * 4.0f)) & 0xFFF),
        ((((s32) (D_800C7F84->box->x1 * 4.0f)) & 0xFFF) << 12) | (((s32) (D_800C7F84->box->y1 * 4.0f)) & 0xFFF));
#define C16 ((((arg2->col.r << 8) & 0xF800) | ((arg2->col.g << 3) & 0x7C0)) | ((arg2->col.b >> 2) & 0x3E) | 1)
    CMD(g++, 0xF7000000, (C16 << 16) | C16);
    CMD(g++, (0xF6000000 | (((arg2->rect->x1 - 1) & 0x3FF) << 14)) | (((arg2->rect->y1 - 1) & 0x3FF) << 2),
        ((arg2->rect->x0 & 0x3FF) << 14) | ((arg2->rect->y0 & 0x3FF) << 2));
    CMD(g++, 0xE7000000, 0);
    func_80006014(h, g);
  }
}
