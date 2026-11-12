/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -g3, tried by autopilot */
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

M2C_UNK func_8004C7B8();                            /* extern */
M2C_UNK heapFreeBlock(void *);                      /* extern */
M2C_UNK heap_free_stub(s32);                        /* extern */
M2C_UNK object_free_blocks(s32);                    /* extern */
M2C_UNK stream_obj_free(s32);                       /* extern */
extern void *D_800A0384;
extern M2C_UNK stream_state;

void race_ctx_free(void) {
    heap_free_stub(M2C_FIELD(D_800A0384, s32 *, 0));
    stream_obj_free(M2C_FIELD(D_800A0384, s32 *, 4));
    heapFreeBlock(D_800A0384);
    D_800A0384 = NULL;
    object_free_blocks(M2C_FIELD(&stream_state, s32 *, 0x807A));
    func_8004C7B8();
}
