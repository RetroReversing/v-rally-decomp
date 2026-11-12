/* Clears the bits in mask from the 16-bit flags at offset 0x4C of input context slot `slot`. */
#ifdef PORT
extern s8 *gControllerInputContext;
#else
extern s32 gControllerInputContext;
#endif

void input_clear_flags(s32 slot, s32 mask) {
    void *ctx;

    ctx = ((slot & 0xFF) * 2) + gControllerInputContext;
    *(u16 *)((s8 *)ctx + 0x4C) = (u16)(*(u16 *)((s8 *)ctx + 0x4C) & ~mask);
}
