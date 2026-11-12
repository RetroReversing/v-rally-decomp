s32 gfx_set_quad_uv();

/* Sets entry `index` of obj's coordinate table from obj's size fields at +0x88 and +0x8A
 * (each doubled). Calls gfx_set_quad_uv, which stores the coordinates. */
void setEntryCoordsFromSize(void *obj, s32 index) {
    s32 wide;
    s32 high;

    wide = (*(u16 *)((char *)obj + 0x8A) * 2) & 0xFFFF;
    high = (*(u16 *)((char *)obj + 0x88) * 2) & 0xFFFF;
    gfx_set_quad_uv(obj, index & 0xFFFF, wide, high, wide, 0, 0, 0, 0, high);
}
