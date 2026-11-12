#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 getTexturePack(void *, s32);                    /* extern */
M2C_UNK resolve_path(M2C_UNK *);                   /* extern */
extern M2C_UNK D_800A48C0;
extern u8 stream_state[];

/* Resolves the path in D_800A48C0, then copies three flag bytes from the order
 * record (+0xDC, +0x128, +0x174) into stream_state, and stores the result of
 * getTexturePack on the record's name field (+0x4C) at stream_state+0x6C22. */
void func_8001F4B0(void *order) {
    resolve_path(&D_800A48C0);
    *(s32 *)(stream_state + 0x6C22) = getTexturePack((u8 *)order + 0x4C, 0);
    *(s8 *)(stream_state + 0x6C27) = (s8) *(s32 *)((u8 *)order + 0xDC);
    *(s8 *)(stream_state + 0x6C26) = (s8) *(s32 *)((u8 *)order + 0x128);
    *(s8 *)(stream_state + 0x6C28) = (s8) *(s32 *)((u8 *)order + 0x174);
}
