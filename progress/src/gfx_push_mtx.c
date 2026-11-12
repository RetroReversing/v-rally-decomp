#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

void dlAddLoadChunk(void *ctx);

/* Appends a G_MTX (0xDA380007) display-list command for the matrix at addr, then queues the chunk. */
void gfx_push_mtx(s8 *ctx, s32 addr) {
    s8 *dl;

    dl = M2C_FIELD(ctx, s8 **, 0x14);
    M2C_FIELD(ctx, s8 **, 0x14) = dl + 8;
    M2C_FIELD(dl, s32 *, 0) = 0xDA380007;
    M2C_FIELD(dl, s32 *, 4) = addr;
    dlAddLoadChunk(ctx);
}
