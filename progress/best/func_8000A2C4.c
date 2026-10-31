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

s32 func_800056FC();                                /* extern */
s32 func_80005C48(s32);                             /* extern */
void *func_80006008(s32);                           /* extern */
M2C_UNK func_80006014(s32, void *, void *, void *); /* extern */
s32 osVirtualToPhysical(s32, void *);               /* extern */
extern void *D_8009B5A4;
extern s32 D_8009B5A8;
extern M2C_UNK D_8009B5D0;

void func_8000A2C4(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 var_v0;
    s32 temp_v0;
    s32 temp_v0_2;
    void *temp_s2;
    void *temp_s2_10;
    void *temp_s2_11;
    void *temp_s2_2;
    void *temp_s2_3;
    void *temp_s2_4;
    void *temp_s2_5;
    void *temp_s2_6;
    void *temp_s2_7;
    void *temp_s2_8;
    void *temp_s2_9;
    void *temp_s7;
    void *temp_v1;
    void *temp_v1_2;

    temp_s7 = M2C_FIELD(arg0, void **, 0x2C);
    temp_v0 = func_800056FC();
    temp_s2 = func_80006008(temp_v0);
    temp_v0_2 = func_80005C48(D_8009B5A8);
    temp_s2_2 = temp_s2 + 8;
    M2C_FIELD(temp_s2, s32 *, 0) = 0xDE000000;
    temp_s2_3 = temp_s2_2 + 8;
    M2C_FIELD(temp_s2, M2C_UNK **, 4) = &D_8009B5D0;
    M2C_FIELD(temp_s2, s32 *, 8) = (s32) (((M2C_FIELD(D_8009B5A4, s16 *, 4) - 1) & 0xFFF) | 0xFF100000);
    M2C_FIELD(temp_s2_2, s32 *, 4) = osVirtualToPhysical(temp_v0_2, D_8009B5A4);
    if (!(arg3 & 0xFF)) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x2C), s16 *, 0x10) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x2C), s16 *, 0x18) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x2C), s16 *, 0x14) = (s16) (arg1 * 4);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x2C), s16 *, 0x1C) = (s16) (arg2 * 4);
        temp_v1 = M2C_FIELD(arg0, void **, 0x2C);
        M2C_FIELD(temp_v1, u16 *, 0x16) = (u16) M2C_FIELD(temp_v1, u16 *, 0x12);
        temp_v1_2 = M2C_FIELD(arg0, void **, 0x2C);
        M2C_FIELD(temp_v1_2, u16 *, 0x1E) = (u16) M2C_FIELD(temp_v1_2, u16 *, 0x1A);
        M2C_FIELD(temp_s2_2, s32 *, 8) = (s32) ((((s32) ((f32) M2C_FIELD(arg0, s16 *, 0) * 4.0f) & 0xFFF) << 0xC) | (((s32) ((f32) M2C_FIELD(arg0, s16 *, 2) * 4.0f) & 0xFFF) | 0xED000000));
        var_v0 = M2C_FIELD(arg0, s16 *, 4);
    } else {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x2C), s16 *, 0x10) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x2C), s16 *, 0x18) = 0;
        M2C_FIELD(temp_s2_2, s32 *, 8) = (s32) ((((s32) ((f32) M2C_FIELD(arg0, s16 *, 0) * 4.0f) & 0xFFF) << 0xC) | (((s32) ((f32) M2C_FIELD(arg0, s16 *, 2) * 4.0f) & 0xFFF) | 0xED000000));
        var_v0 = M2C_FIELD(arg0, s16 *, 4) + 8;
    }
    temp_s2_4 = temp_s2_3 + 8;
    M2C_FIELD(temp_s2_3, s32 *, 4) = (s32) ((((s32) ((f32) var_v0 * 4.0f) & 0xFFF) << 0xC) | ((s32) ((f32) M2C_FIELD(arg0, s16 *, 6) * 4.0f) & 0xFFF));
    temp_s2_5 = temp_s2_4 + 8;
    temp_s2_6 = temp_s2_5 + 8;
    temp_s2_7 = temp_s2_6 + 8;
    temp_s2_8 = temp_s2_7 + 8;
    temp_s2_9 = temp_s2_8 + 8;
    temp_s2_10 = temp_s2_9 + 8;
    temp_s2_11 = temp_s2_10 + 8;
    M2C_FIELD(temp_s2_3, s32 *, 8) = 0xE200001C;
    M2C_FIELD(temp_s2_4, s32 *, 4) = 0;
    M2C_FIELD(temp_s2_5, s32 *, 4) = 0x200000;
    M2C_FIELD(temp_s2_4, s32 *, 8) = 0xE3000A01;
    M2C_FIELD(temp_s2_6, s32 *, 4) = 0x8000;
    M2C_FIELD(temp_s2_5, s32 *, 8) = 0xE3001001;
    M2C_FIELD(temp_s2_6, s32 *, 8) = 0x05000017;
    M2C_FIELD(temp_s2_7, void **, 4) = (void *) (temp_s7 + 0x38);
    M2C_FIELD(temp_s2_7, s32 *, 8) = 0xE7000000;
    M2C_FIELD(temp_s2_8, s32 *, 4) = 0;
    M2C_FIELD(temp_s2_8, s32 *, 8) = 0x0A000000;
    M2C_FIELD(temp_s2_9, void **, 4) = (void *) (temp_s7 + 0x10);
    M2C_FIELD(temp_s2_9, s32 *, 8) = 0xE7000000;
    M2C_FIELD(temp_s2_10, s32 *, 4) = 0;
    M2C_FIELD(temp_s2_10, s32 *, 8) = 0xE3000A01;
    M2C_FIELD(temp_s2_11, s32 *, 4) = 0;
    func_80006014(temp_v0, temp_s2_11 + 8, temp_s2_6, temp_s2_9);
}
