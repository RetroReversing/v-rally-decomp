/* Partial candidate from function #24307 in project #57; rechecked locally. */
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

s32 func_80009964(void *arg0, s8 arg1) {
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_a1_5;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v1_5;
    s32 var_v0;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a0_3;
    u32 temp_a1;
    u32 temp_v0_2;
    u32 temp_v0_4;
    u32 temp_v0_6;
    u32 temp_v0_8;
    void *temp_v0_3;
    void *temp_v0_5;
    void *temp_v0_7;
    void *temp_v0_9;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_6;

    temp_a3 = arg1 & 0xFF;
    if (temp_a3 == 1) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        M2C_FIELD(arg0, s32 *, 0x80) = 0;
    }
    temp_a0 = M2C_FIELD(arg0, u32 *, 0x84);
    temp_a1 = temp_a0 >> 0x1F;
    if (((((temp_a0 >> 0x15) & 1) ^ temp_a1) | (temp_a3 == 1)) != 0) {
        temp_v0 = (temp_a0 & 0xFFDFFFFF) | (temp_a1 << 0x15);
        M2C_FIELD(arg0, u32 *, 0x84) = (u32) temp_v0;
        if (temp_v0 < 0) {
            temp_v1 = M2C_FIELD(arg0, void **, 0x14);
            M2C_FIELD(arg0, void **, 0x14) = (void *) (temp_v1 + 8);
            M2C_FIELD(temp_v1, s32 *, 0) = 0xD7000002;
        } else {
            temp_v1_2 = M2C_FIELD(arg0, void **, 0x14);
            M2C_FIELD(arg0, void **, 0x14) = (void *) (temp_v1_2 + 8);
            M2C_FIELD(temp_v1_2, s32 *, 0) = 0xD7000000;
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), s32 *, 4) = 0x80008000;
    }
    temp_a1_2 = (M2C_FIELD(arg0, u32 *, 0x84) >> 0x1B) & 0xF;
    if (((((M2C_FIELD(arg0, u32 *, 0x84) >> 0x11) & 0xF) != temp_a1_2) | ((arg1 & 0xFF) == 1)) != 0) {
        temp_v0_2 = (M2C_FIELD(arg0, u32 *, 0x84) & 0xFFE1FFFF) | (temp_a1_2 << 0x11);
        M2C_FIELD(arg0, u32 *, 0x84) = temp_v0_2;
        if (!((temp_v0_2 >> 0x1B) & 0xF)) {
            temp_v0_3 = M2C_FIELD(arg0, void **, 0x14);
            M2C_FIELD(arg0, void **, 0x14) = (void *) (temp_v0_3 + 8);
            M2C_FIELD(temp_v0_3, s32 *, 0) = 0xE3001201;
            M2C_FIELD(temp_v0_3, s32 *, 4) = 0;
        } else {
            temp_v1_3 = M2C_FIELD(arg0, void **, 0x14);
            M2C_FIELD(arg0, void **, 0x14) = (void *) (temp_v1_3 + 8);
            M2C_FIELD(temp_v1_3, s32 *, 0) = 0xE3001201;
            M2C_FIELD(temp_v1_3, s32 *, 4) = 0x2000;
        }
    }
    temp_a0_2 = M2C_FIELD(arg0, u32 *, 0x84);
    temp_a1_3 = (temp_a0_2 >> 0x1A) & 1;
    if (((((temp_a0_2 >> 0x10) & 1) ^ temp_a1_3) | ((arg1 & 0xFF) == 1)) != 0) {
        temp_v0_4 = (temp_a0_2 & 0xFFFEFFFF) | (temp_a1_3 << 0x10);
        M2C_FIELD(arg0, u32 *, 0x84) = temp_v0_4;
        if (temp_v0_4 & 0x04000000) {
            temp_v1_4 = M2C_FIELD(arg0, void **, 0x14);
            M2C_FIELD(arg0, void **, 0x14) = (void *) (temp_v1_4 + 8);
            M2C_FIELD(temp_v1_4, s32 *, 0) = 0xE3000C00;
            M2C_FIELD(temp_v1_4, s32 *, 4) = 0x80000;
        } else {
            temp_v0_5 = M2C_FIELD(arg0, void **, 0x14);
            M2C_FIELD(arg0, void **, 0x14) = (void *) (temp_v0_5 + 8);
            M2C_FIELD(temp_v0_5, s32 *, 0) = 0xE3000C00;
            M2C_FIELD(temp_v0_5, s32 *, 4) = 0;
        }
    }
    temp_a1_4 = (M2C_FIELD(arg0, u32 *, 0x84) >> 0x16) & 3;
    if (((((M2C_FIELD(arg0, u32 *, 0x84) >> 0xC) & 3) != temp_a1_4) | ((arg1 & 0xFF) == 1)) != 0) {
        temp_v0_6 = (M2C_FIELD(arg0, u32 *, 0x84) & ~0x3000) | (temp_a1_4 << 0xC);
        M2C_FIELD(arg0, u32 *, 0x84) = temp_v0_6;
        temp_v1_5 = (temp_v0_6 >> 0x16) & 3;
        switch (temp_v1_5) {                        /* irregular */
        case 1:
            M2C_FIELD(arg0, void **, 0x14) = (void *) (M2C_FIELD(arg0, void **, 0x14) + 8);
            var_v0 = 0x8000;
block_30:
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), s32 *, 0) = 0xE3001001;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), s32 *, 4) = var_v0;
            break;
        case 0:
            temp_v0_7 = M2C_FIELD(arg0, void **, 0x14);
            M2C_FIELD(arg0, void **, 0x14) = (void *) (temp_v0_7 + 8);
            M2C_FIELD(temp_v0_7, s32 *, 0) = 0xE3001001;
            M2C_FIELD(temp_v0_7, s32 *, 4) = 0;
            break;
        case 2:
            M2C_FIELD(arg0, void **, 0x14) = (void *) (M2C_FIELD(arg0, void **, 0x14) + 8);
            var_v0 = 0xC000;
            goto block_30;
        }
    }
    temp_a0_3 = M2C_FIELD(arg0, u32 *, 0x84);
    temp_a1_5 = (temp_a0_3 >> 0x18) & 3;
    if (((((temp_a0_3 >> 0xE) & 3) != temp_a1_5) | ((arg1 & 0xFF) == 1)) != 0) {
        temp_v0_8 = (temp_a0_3 & 0xFFFF3FFF) | (temp_a1_5 << 0xE);
        M2C_FIELD(arg0, u32 *, 0x84) = temp_v0_8;
        if (!((temp_v0_8 >> 0x18) & 3)) {
            temp_v0_9 = M2C_FIELD(arg0, void **, 0x14);
            M2C_FIELD(arg0, void **, 0x14) = (void *) (temp_v0_9 + 8);
            M2C_FIELD(temp_v0_9, s32 *, 0) = 0xD9DFFFFF;
            M2C_FIELD(temp_v0_9, s32 *, 4) = 0;
        } else {
            temp_v1_6 = M2C_FIELD(arg0, void **, 0x14);
            M2C_FIELD(arg0, void **, 0x14) = (void *) (temp_v1_6 + 8);
            M2C_FIELD(temp_v1_6, s32 *, 0) = 0xD9FFFFFF;
            M2C_FIELD(temp_v1_6, s32 *, 4) = 0x200000;
        }
    }
    return 1;
}
