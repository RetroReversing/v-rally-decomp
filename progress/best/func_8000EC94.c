/* Partial candidate from function #24370 in project #57; rechecked locally. */
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s32 func_800056FC(s32);                             /* extern */
s32 func_80005C48(void *);                          /* extern */
void *func_80006008(s32);                           /* extern */
M2C_UNK func_80006014(s32, void *, void *);         /* extern */
s32 osVirtualToPhysical(s32,  void *);     /* extern */
extern void *D_800A1108;

void func_8000EC94(s32 arg0, void *arg1, void *arg2) {
    s32 temp_s5;
    s32 temp_v0;
    s32 temp_v1;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s0_4;
    void *temp_s0_5;
    void *temp_s0_6;
    void *temp_s0_7;
    void *temp_v0_2;

    temp_s5 = func_80005C48(D_800A1108);
    temp_v0 = func_800056FC(arg0);
    temp_v0_2 = func_80006008(temp_v0);
    M2C_FIELD(temp_v0_2, s32 *, 0) = (s32) ((((s32) ((f32) M2C_FIELD(arg1, s16 *, 0) * 4.0f) & 0xFFF) << 0xC) | (((s32) ((f32) M2C_FIELD(arg1, s16 *, 2) * 4.0f) & 0xFFF) | 0xED000000));
    temp_s0 = temp_v0_2 + 8;
    temp_s0_2 = temp_s0 + 8;
    temp_s0_3 = temp_s0_2 + 8;
    temp_s0_4 = temp_s0_3 + 8;
    M2C_FIELD(temp_v0_2, s32 *, 4) = (s32) ((((s32) ((f32) M2C_FIELD(arg1, s16 *, 4) * 4.0f) & 0xFFF) << 0xC) | ((s32) ((f32) M2C_FIELD(arg1, s16 *, 6) * 4.0f) & 0xFFF));
    M2C_FIELD(temp_v0_2, s32 *, 8) = 0xE7000000;
    M2C_FIELD(temp_s0, s32 *, 4) = 0;
    M2C_FIELD(temp_s0, s32 *, 8) = 0xE3000A01;
    M2C_FIELD(temp_s0_2, s32 *, 4) = 0x300000;
    M2C_FIELD(temp_s0_2, s32 *, 8) = (s32) (((M2C_FIELD(D_800A1108, s16 *, 4) - 1) & 0xFFF) | 0xFF100000);
    temp_s0_5 = temp_s0_4 + 8;
    M2C_FIELD(temp_s0_3, s32 *, 4) = osVirtualToPhysical(temp_s5,  temp_s0_2);
    M2C_FIELD(temp_s0_3, s32 *, 8) = 0xF7000000;
    temp_s0_6 = temp_s0_5 + 8;
    temp_v1 = ((M2C_FIELD(arg2, u8 *, 0) << 8) & 0xF800) | ((M2C_FIELD(arg2, u8 *, 1) * 8) & 0x7C0) | (((u8) M2C_FIELD(arg2, u8 *, 2) >> 2) & 0x3E);
    M2C_FIELD(temp_s0_4, s32 *, 4) = (s32) (((temp_v1 | 1) << 0x10) | 1 | temp_v1);
    temp_s0_7 = temp_s0_6 + 8;
    M2C_FIELD(temp_s0_4, s32 *, 8) = (s32) ((((M2C_FIELD(arg1, s16 *, 4) - 1) & 0x3FF) << 0xE) | ((((M2C_FIELD(arg1, s16 *, 6) - 1) & 0x3FF) * 4) | 0xF6000000));
    M2C_FIELD(temp_s0_5, s32 *, 4) = (s32) ((((u16) M2C_FIELD(arg1, s16 *, 0) & 0x3FF) << 0xE) | (((u16) M2C_FIELD(arg1, s16 *, 2) & 0x3FF) * 4));
    M2C_FIELD(temp_s0_5, s32 *, 8) = 0xE7000000;
    M2C_FIELD(temp_s0_6, s32 *, 4) = 0;
    M2C_FIELD(temp_s0_6, s32 *, 8) = 0xE3000A01;
    M2C_FIELD(temp_s0_7, s32 *, 4) = 0;
    func_80006014(temp_v0, temp_s0_7 + 8, temp_s0_5);
}
