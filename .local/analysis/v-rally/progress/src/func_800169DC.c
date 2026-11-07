typedef struct { u32 w0, w1; } Gfx16;
Gfx16 *func_80006008();
s32 func_80006014();
extern char D_8009C068[];
extern char D_8009C0A8[];
extern char D_8009C0E8[];
#define GW(pkt, a, b) { Gfx16 *_g = (Gfx16 *)(pkt); _g->w0 = (a); _g->w1 = (u32)(b); }
void func_800169DC(s32 arg0, s32 arg1)
{
  Gfx16 *gfx;
  gfx = func_80006008();
  switch (arg1)
  {
    case 0:
      GW(gfx++, 0xDE000000, D_8009C068);
      break;
    case 1:
      GW(gfx++, 0xDE000000, D_8009C0A8);
      break;
    case 2:
      GW(gfx++, 0xDE000000, D_8009C068);
      GW(gfx++, 0xFC30FFFF, -0xDC8);
      GW(gfx++, 0xFA000000, 0x28282800);
      break;
    case 3:
      GW(gfx++, 0xDE000000, D_8009C0E8);
      GW(gfx++, 0xFA000000, 0x28282800);
      GW(gfx++, 0xFC30D3FF, -0x1C8);
      break;
  }
  func_80006014(arg0, gfx);
}
