#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

extern char stream_state[];

/* Copies field +0x44 of entries 1..10 (stride 0x4C, starting at base+0x4C) into the 16-bit table at stream_state+0x10370. */
void func_8001D954(char *base) {
    char *dst;
    s32 temp_v0;
    s32 i;
    char *src;

    i = 1;
    dst = stream_state + 0x10370;
    src = base + 0x4C;
    do {
        temp_v0 = M2C_FIELD(src, s32 *, 0x44);
        src += 0x4C;
        i += 1;
        *(s16 *)dst = (s16) temp_v0;
        dst += 2;
    } while (i < 0xB);
}