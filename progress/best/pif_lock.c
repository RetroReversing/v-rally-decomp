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

M2C_UNK osCreateMesgQueue(void *, void *, M2C_UNK); /* extern */
M2C_UNK osRecvMesg(void *, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK osSendMesg(void *, M2C_UNK, M2C_UNK);       /* extern */
extern s32 D_800A1CF0;
extern M2C_UNK gGameState;
extern M2C_UNK stream_state;

void pif_lock(void) {
    M2C_UNK sp10;

    if (D_800A1CF0 == 0) {
        D_800A1CF0 = 1;
        osCreateMesgQueue(&stream_state + 0x10312, &gGameState + 0x45B0, 1);
        osSendMesg(&stream_state + 0x10312, 0, 0);
    }
    osRecvMesg(&stream_state + 0x10312, &sp10, 1);
}
