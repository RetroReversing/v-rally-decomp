/* Rounds the u16 at +0x7A up to the next multiple of 0x20 when its low five bits are set. */
void gfx_round_vtx_pos(void *obj) {
    u16 pos;

    pos = *(u16 *)((s8 *)obj + 0x7A);
    if (pos & 0x1F) {
        *(u16 *)((s8 *)obj + 0x7A) = (u16)((pos & 0xFFE0) + 0x20);
    }
}
