u32 *gfx_get_dl(void *);
void gfx_set_dl(void *, u32 *);
extern char D_8009C030[];
extern char D_8009C068[];
extern char D_8009C0A8[];
extern char D_8009C0E8[];

#ifdef PORT
#define GFX_DL_CALL(pkt, addr) { uintptr_t *_g = (uintptr_t *)(pkt); _g[0] = 0xDE000000; _g[1] = (uintptr_t)(addr); }
#else
#define GFX_DL_CALL(pkt, addr) { u32 *_g = (u32 *)(pkt); _g[0] = 0xDE000000; _g[1] = (u32)(addr); }
#endif

/* Adds a display-list call to the list for view r: first the common list
 * D_8009C030, then the list for the mode (0-3, modes 2 and 3 share one). */
void gfx_call_mode_dl(void *r, s32 mode)
{
#ifdef PORT
  struct { uintptr_t w0, w1; } *gfx;
#else
  struct { u32 w0, w1; } *gfx;
#endif

  gfx = gfx_get_dl(r);
  GFX_DL_CALL(gfx++, D_8009C030);
  switch (mode) {
  case 0:
    GFX_DL_CALL(gfx++, D_8009C068);
    break;
  case 1:
    GFX_DL_CALL(gfx++, D_8009C0A8);
    break;
  case 2:
    GFX_DL_CALL(gfx++, D_8009C0E8);
    break;
  case 3:
    GFX_DL_CALL(gfx++, D_8009C0E8);
    break;
  }
  gfx_set_dl(r, gfx);
}
