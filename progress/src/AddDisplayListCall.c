#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif

M2C_UNK gfx_set_render_mode();
M2C_UNK dlAddLoadChunk(void *);

/* Appends a G_DL command (0xDE000000, address arg1) to the display list whose
 * write pointer is at obj+0x14, then sets the render mode and adds the load chunk. */
void AddDisplayListCall(void *obj, s32 addr) {
    void *cmd;

    cmd = M2C_FIELD(obj, void **, 0x14);
    M2C_FIELD(obj, void **, 0x14) = (void *) (cmd + 8);
    M2C_FIELD(cmd, s32 *, 0) = 0xDE000000;
    M2C_FIELD(cmd, s32 *, 4) = addr;
    gfx_set_render_mode();
    dlAddLoadChunk(obj);
}
