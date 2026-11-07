u32 *func_80006008(void *);
void func_80006014(void *, u32 *);
extern char D_8009C030[];
extern char D_8009C068[];
extern char D_8009C0A8[];
extern char D_8009C0E8[];

#define gCmd(pkt, a, b) { u32 *_g = (u32 *)(pkt); _g[0] = (a); _g[1] = (u32)(b); }

void func_80016910(void *r, s32 mode)
{
  struct { u32 w0, w1; } *gfx;

  gfx = func_80006008(r);
  gCmd(gfx++, 0xDE000000, D_8009C030);
  switch (mode) {
  case 0:
    gCmd(gfx++, 0xDE000000, D_8009C068);
    break;
  case 1:
    gCmd(gfx++, 0xDE000000, D_8009C0A8);
    break;
  case 2:
    gCmd(gfx++, 0xDE000000, D_8009C0E8);
    break;
  case 3:
    gCmd(gfx++, 0xDE000000, D_8009C0E8);
    break;
  }
  func_80006014(r, gfx);
}
