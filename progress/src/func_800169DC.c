typedef struct { u32 w0, w1; } Gfx16;
Gfx16 *gfx_get_dl();
s32 gfx_set_dl();
extern char D_8009C068[];
extern char D_8009C0A8[];
extern char D_8009C0E8[];
#define GW(pkt, a, b) { Gfx16 *_g = (Gfx16 *)(pkt); _g->w0 = (a); _g->w1 = (u32)(b); }

/* Appends the RDP state commands for render mode `mode` to the current display list,
   then hands the list back to gfx_set_dl. */
void func_800169DC(s32 dl_ctx, s32 mode)
{
  Gfx16 *gfx;
  gfx = gfx_get_dl();
  switch (mode)
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
  gfx_set_dl(dl_ctx, gfx);
}
