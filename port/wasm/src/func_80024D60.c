/* Port-only C (WebAssembly build): written from the assembly so it behaves as the game does, not matching C.
 * The project still has this function open for agents to match. */
#include "common.h"
#include "gap.h"
/* port: prototypes follow the callees' asm (and their port definitions where they exist). */
s32 getCounterValue(void *);                          /* reads (*(arg0+0x5C))->0x68 */
s32 applyDeadZoneScale(s32, s32, s32, s32, s32);         /* uses $a0-$a2 and 0x10($sp); $a3 ignored */
void draw_line_group(void *);
void func_80024B28(void *);
void func_80026E3C(u8 *, void *, s32 *);
s32 angle_atan2_thunk(s32, s32);                        /* wrapper of atan2_angle4096(a0, a1): atan2-like */
s32 cos_q12(s32);                             /* sin/cos of a 12-bit angle, 1.0 = 0x1000 */
void func_8002D460(void *, void *, s32, s32, void *);
void cross_product(void *, s32 *, s32 *);
void func_8002D740(s32 *, s32 *, s32 *);
void mat3_mul_vec3_q12(void *, s32 *, s32 *);           /* s16 3x3 matrix times s32 vector */
void *func_8002DA98(void *, void *);
void mat3x3_from_euler(s16 *, void *);
void vec3_normalize_fixed(s32 *, s32 *);
extern s32 D_8009D538;
extern M2C_UNK D_8009D6D0;
extern M2C_UNK D_8009DC80;
extern s32 D_8009E230;
extern s32 D_8009EB80;
extern M2C_UNK D_800C02AE;

void func_80024D60(void **arg0) {
    /* port: the stack buffers sp18..sp12F as one block, so the asm's addressing of them
     * (sp1D4 = &sp18 indexed by 0x108 + 4*i reaches sp120[i]) works as on the N64. */
    struct {
        s32 sp18[8];   /* 0x18: 32-byte matrix (s16 3x3 + s32 translation at +0x14) */
        s32 sp38[8];   /* 0x38: matrix */
        s32 sp58[8];   /* 0x58: matrix */
        s32 sp78[8];   /* 0x78: matrix */
        s16 sp98[4];   /* 0x98: s16 angle triple for mat3x3_from_euler */
        s32 spA0[4];   /* 0xA0: s32 vec3 */
        s32 spB0[4];
        s32 spC0[4];
        s32 spD0[4];
        s32 spE0[4];
        s32 spF0[4];
        s32 sp100[4];
        s32 sp110[4];
        s32 sp120[4];  /* 0x120: four s32, also reached as sp18 + 0x108 */
    } fr;
    _Static_assert(__builtin_offsetof(__typeof__(fr), sp120) == 0x120 - 0x18, "frame layout");
    s32 sp134;
    s32 sp13C;
    s32 sp144;
    s32 sp14C;
    s32 sp154;
    s32 sp15C;
    s32 sp164;
    s32 sp16C;
    s32 sp174;
    s32 sp17C;
    s32 sp184;
    s32 sp18C;
    s32 sp194;
    s32 *sp19C;
    s32 *sp1A4;
    void *sp1AC;
    s32 *sp1B4;
    s32 *sp1BC;
    s32 *sp1C4;
    s32 *sp1CC;
    void *sp1D4;
    s32 sp1EC;
    s32 sp1F4;
    s32 sp1FC;
    void *temp_fp;
    void *temp_fp_2;
    void *temp_s4_2;
    void *var_a0_2;
    void *var_a1_2;
    void *var_v1;
    void *var_v1_2;
    void *var_v1_3;
    s16 temp_v0_19;
    s16 temp_v0_20;
    s16 temp_v0_21;
    s32 *temp_v1_21;
    s32 *var_a2_3;
    s32 *var_a2_5;
    s32 temp_a0_12;
    s32 temp_a0_16;
    s32 temp_a0_17;
    s32 temp_a0_18;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a1;
    s32 temp_a1_3;
    s32 temp_a1_5;
    s32 temp_a1_6;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_a2_5;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_a3_3;
    s32 temp_a3_4;
    s32 temp_a3_5;
    s32 temp_a3_6;
    s32 temp_lo;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s2_2;
    s32 temp_s3;
    s32 temp_s3_3;
    s32 temp_s3_4;
    s32 temp_s7;
    s32 temp_t0;
    s32 temp_t1_2;
    s32 temp_v0;
    s32 temp_v0_11;
    s32 temp_v0_13;
    s32 temp_v0_14;
    s32 temp_v0_15;
    s32 temp_v0_17;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1;
    s32 temp_v1_11;
    s32 temp_v1_16;
    s32 temp_v1_20;
    s32 temp_v1_24;
    s32 temp_v1_25;
    s32 temp_v1_26;
    s32 temp_v1_27;
    s32 temp_v1_2;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_9;
    s32 var_a0_10;
    s32 var_a0_11;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_a0_6;
    s32 var_a0_7;
    s32 var_a0_8;
    s32 var_a0_9;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_a1_5;
    s32 var_a1_6;
    s32 var_a1_7;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a2_4;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_s2_4;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s4;
    s32 var_s5;
    s32 var_s5_2;
    s32 var_s5_3;
    s32 var_s7;
    s32 var_s7_2;
    s32 var_s7_3;
    s32 var_s7_4;
    s32 var_s7_5;
    s32 var_s7_6;
    s32 var_t0;
    s32 var_t4;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_7;
    s32 var_v0_8;
    s32 var_v0_9;
    u32 temp_s0;
    u8 temp_a1_2;
    u8 temp_s3_2;
    void *temp_a0;
    void *temp_a0_10;
    void *temp_a0_11;
    void *temp_a0_13;
    void *temp_a0_14;
    void *temp_a0_15;
    void *temp_a0_19;
    void *temp_a0_20;
    void *temp_a0_4;
    void *temp_a0_7;
    void *temp_a0_8;
    void *temp_a0_9;
    void *temp_a1_4;
    void *temp_a2_4;
    void *temp_s0_5;
    void *temp_s2;
    void *temp_s4;
    void *temp_s6;
    void *temp_s6_2;
    void *temp_s6_3;
    void *temp_t1;
    void *temp_t2;
    void *temp_v0_10;
    void *temp_v0_12;
    void *temp_v0_16;
    void *temp_v0_18;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1_10;
    void *temp_v1_12;
    void *temp_v1_13;
    void *temp_v1_14;
    void *temp_v1_15;
    void *temp_v1_17;
    void *temp_v1_18;
    void *temp_v1_19;
    void *temp_v1_22;
    void *temp_v1_23;
    void *temp_v1_28;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_8;
    void *var_a0;
    void *var_a1;
    void *var_s1;

    sp174 = 0;
    sp17C = 0;
    var_s1 = *arg0;
    sp184 = 0;
    sp18C = 0;
    if (var_s1 != NULL) {
        sp1D4 = fr.sp18;
        sp19C = fr.spD0;
        sp1A4 = fr.spC0;
        sp1AC = fr.sp78;
        sp1B4 = fr.spF0;
        sp1C4 = fr.spB0;
        sp1BC = fr.spE0;
        var_a2 = 0;
        do {
            var_s7 = 0;
            var_a1 = M2C_FIELD(var_s1, void **, 0x80);
            var_a0 = M2C_FIELD(var_s1, void **, 0x8C);
loop_3:
            temp_v1 = M2C_FIELD(var_a1, s32 *, 0x1F4);
            var_a1 += 0x14;
            temp_v0 = M2C_FIELD(var_a0, s32 *, 0xB4);
            var_a0 += 0x14;
            var_s7 += 1;
            var_a2 += temp_v0 - temp_v1;
            if (var_s7 < 4) {
                goto loop_3;
            }
            var_v0 = var_a2;
            if (var_a2 < 0) {
                var_v0 = var_a2 + 3;
            }
            temp_a2 = var_v0 >> 2;
            if (temp_a2 >= 0x3E9) {
                func_80024B28(var_s1);
            }
            if (M2C_FIELD(&D_800C02AE, s32 *, 0x8112) != 0) {
                draw_line_group(var_s1);
            }
            temp_v0_2 = M2C_FIELD(var_s1, void **, 0x58);
            M2C_FIELD(temp_v0_2, s32 *, 0x5C) = 0;
            M2C_FIELD(temp_v0_2, s32 *, 0x60) = 0;
            M2C_FIELD(temp_v0_2, s32 *, 0x64) = 0;
            temp_v0_3 = M2C_FIELD(var_s1, void **, 0x58);
            M2C_FIELD(temp_v0_3, s32 *, 0x70) = 0;
            M2C_FIELD(temp_v0_3, s32 *, 0x74) = 0;
            M2C_FIELD(temp_v0_3, s32 *, 0x78) = 0;
            fr.spB0[0] = 0;
            fr.spB0[1] = 0;
            fr.spB0[2] = 0;
            func_8002DA98(M2C_FIELD(var_s1, void **, 0x5C) + 0x40, fr.sp18);
            temp_t2 = M2C_FIELD(var_s1, void **, 0x7C);
            temp_t1 = M2C_FIELD(var_s1, void **, 0x4C);
            temp_s2 = M2C_FIELD(var_s1, void **, 0x48);
            temp_t0 = M2C_FIELD(temp_t1, s32 *, 4);
            if (M2C_FIELD(temp_t2, s32 *, 0x2C) != 0) {
                var_s7_2 = 0;
                goto block_52;
            }
            if (M2C_FIELD(temp_s2, s32 *, 0x10) != 0) {
                var_s7_2 = 0;
                goto block_52;
            }
            temp_a0 = M2C_FIELD(var_s1, void **, 0x54);
            temp_a1 = M2C_FIELD(temp_a0, s32 *, 0);
            if (temp_a1 < 0) {
                var_s7_2 = 0;
block_52:
                var_a0_2 = sp1D4;
                do {
                    temp_v0_4 = M2C_FIELD(((var_s7_2 * 4) + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x354);
                    var_s7_2 += 1;
                    M2C_FIELD(var_a0_2, s32 *, 0x108) = temp_v0_4;
                    var_a0_2 += 4;
                } while (var_s7_2 < 4);
                sp18C = 1;
                if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x80), s32 *, 0x350) == 2) {
                    sp18C = 2;
                }
            } else {
                temp_v1_2 = M2C_FIELD(M2C_FIELD(var_s1, void **, 0x80), s32 *, 0x350);
                switch (temp_v1_2) {                /* irregular */
                case 0:
                    temp_a2_2 = (s32) (M2C_FIELD(temp_a0, s32 *, 4) - temp_a1) >> 4;
                    if (temp_a2_2 > 0x64) {
                        sp174 = 0x64;
                    } else {
                        sp174 = temp_a2_2;
                        if (temp_a2_2 < -0x64) {
                            sp174 = -0x64;
                        }
                    }
                    var_t4 = 0x40;
block_37:
                    sp184 = var_t4;
                    sp18C = 1;
                    break;
                case 1:
                    temp_a0_2 = (s32) (M2C_FIELD(temp_a0, s32 *, 0xC) - M2C_FIELD(temp_a0, s32 *, 8)) >> 4;
                    if (temp_a0_2 > 0x64) {
                        sp17C = 0x64;
                    } else {
                        sp17C = temp_a0_2;
                        if (temp_a0_2 < -0x64) {
                            sp17C = -0x64;
                        }
                    }
                    var_t4 = -0x40;
                    goto block_37;
                case 2:
                    temp_a2_3 = (s32) (M2C_FIELD(temp_a0, s32 *, 4) - temp_a1) >> 4;
                    if (temp_a2_3 > 0x32) {
                        sp174 = 0x32;
                    } else {
                        sp174 = temp_a2_3;
                        if (temp_a2_3 < -0x32) {
                            sp174 = -0x32;
                        }
                    }
                    temp_v1_3 = M2C_FIELD(var_s1, void **, 0x54);
                    temp_v0_5 = (s32) (M2C_FIELD(temp_v1_3, s32 *, 0xC) - M2C_FIELD(temp_v1_3, s32 *, 8)) >> 4;
                    if (temp_v0_5 > 0x32) {
                        sp17C = 0x32;
                    } else {
                        sp17C = temp_v0_5;
                        if (temp_v0_5 < -0x32) {
                            sp17C = -0x32;
                        }
                    }
                    temp_v1_4 = M2C_FIELD(var_s1, void **, 0x54);
                    temp_v0_6 = (s32) ((M2C_FIELD(temp_v1_4, s32 *, 8) + M2C_FIELD(temp_v1_4, s32 *, 0xC)) - (M2C_FIELD(temp_v1_4, s32 *, 0) + M2C_FIELD(temp_v1_4, s32 *, 4))) >> 4;
                    if (temp_v0_6 > 0x19) {
                        sp184 = 0x19;
                    } else {
                        sp184 = temp_v0_6;
                        if (temp_v0_6 < -0x19) {
                            sp184 = -0x19;
                        }
                    }
                    sp18C = 2;
                    break;
                }
                temp_v0_7 = sp184 + 0x40;
                temp_v0_8 = 0x40 - sp184;
                fr.sp120[0] = (sp174 + 0x80) * temp_v0_7;
                fr.sp120[1] = (0x80 - sp174) * temp_v0_7;
                fr.sp120[2] = (sp17C + 0x80) * temp_v0_8;
                fr.sp120[3] = (0x80 - sp17C) * temp_v0_8;
            }
            var_a3 = 0;
            if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x7C), s32 *, 0x2C) != 0) {
                var_s7_3 = 0;
                if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x80), s32 *, 0x350) != 0) {
                    fr.sp120[2] = 0;
                    fr.sp120[3] = 0;
                    var_a3 = 0;
                    goto block_59;
                }
            } else {
block_59:
                var_s7_3 = 0;
            }
            var_a1_2 = sp1D4;
loop_61:
            temp_a0_3 = M2C_FIELD(var_a1_2, s32 *, 0x108);
            temp_v1_5 = var_s7_3 * 4;
            if (temp_a0_3 != 0) {
                var_a3 += M2C_FIELD(M2C_FIELD(var_s1, void **, 0x54), s32 *, temp_v1_5);
            }
            var_s7_3 += 1;
            M2C_FIELD((temp_v1_5 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x354) = temp_a0_3;
            var_a1_2 += 4;
            if (var_s7_3 < 4) {
                goto loop_61;
            }
            temp_a2_4 = M2C_FIELD(var_s1, void **, 0x50);
            var_a1_3 = M2C_FIELD(temp_a2_4, s32 *, 0);
            temp_s3 = (s32) (((s32) (M2C_FIELD(temp_t2, s32 *, var_a1_3 * 4) * (0x84 - (M2C_FIELD(temp_a2_4, s32 *, 0xC) * 8))) >> 7) * 0x130) >> 8;
            temp_a3 = var_a3 >> sp18C;
            if ((var_a1_3 != 1) && (M2C_FIELD(temp_a2_4, s32 *, 8) < 6)) {
                var_a1_3 = M2C_FIELD(temp_s2, s32 *, 0x18);
                if (var_a1_3 == 0) {
                    var_t0 = (s32) (temp_a3 * temp_s3) >> 7;
                } else {
                    temp_lo = (0xFF - var_a1_3) * (temp_t0 - ((s32) (temp_a3 * temp_s3) >> 7));
                    var_t0 = temp_t0 + ((s32) (((var_a1_3 * (M2C_FIELD(temp_t1, s32 *, 8) * 0x10)) - ((s32) (temp_lo & ((s32) ~temp_lo >> 0x1F)) >> 3)) - 0x32) >> 8);
                }
            } else {
                var_t0 = temp_t0 - 0x32 + (M2C_FIELD(temp_t1, s32 *, 8) * 0x10);
            }
            if ((var_t0 == 0) && (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0) < 0x12C) && ((u16) M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x16) >= 2U)) {
                M2C_FIELD(M2C_FIELD(var_s1, void **, 0x4C), s32 *, 0) = 0;
            }
            temp_a0_4 = M2C_FIELD(var_s1, void **, 0x78);
            temp_v1_6 = M2C_FIELD(temp_a0_4, s32 *, 4);
            if (temp_v1_6 < var_t0) {
                var_t0 = temp_v1_6;
            }
            temp_v1_7 = M2C_FIELD(temp_a0_4, s32 *, 0);
            if (var_t0 < temp_v1_7) {
                var_t0 = temp_v1_7;
            }
            temp_t1_2 = M2C_FIELD(temp_t1, s32 *, 8);
            sp134 = temp_t1_2;
            temp_v1_8 = M2C_FIELD(var_s1, void **, 0x4C);
            M2C_FIELD(temp_v1_8, s32 *, 4) = (s32) (var_t0 & -(M2C_FIELD(temp_v1_8, s32 *, 0) >= 2));
            fr.sp98[0] = 0;
            sp134 = (s32) (temp_t1_2 * temp_s3 * 0x1B) >> 0xD;
            if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x48), s32 *, 0) == 5) {
                temp_a0_5 = M2C_FIELD(temp_s2, s32 *, 0x14);
                if (temp_a0_5 > 0) {
                    fr.sp98[1] = (s16) ((s32) (0x1000 - cos_q12(temp_a0_5 * 8)) >> 3);
                } else {
                    var_v0_2 = (s32) (cos_q12(temp_a0_5 * 8) - 0x1000) >> 3;
                    goto block_91;
                }
            } else {
                if ((u32) (getCounterValue(var_s1) & 0xFFFF) < 0x3CU) {
                    temp_v1_9 = M2C_FIELD(temp_s2, s32 *, 0x14);
                    var_v0_3 = temp_v1_9;
                    if (temp_v1_9 < 0) {
                        var_v0_3 = -var_v0_3;
                    }
                    if (var_v0_3 >= 0x7E) {
                        var_v0_2 = 0x1FC;
                        if (temp_v1_9 <= 0) {
                            var_v0_2 = -0x1FC;
                        }
                    } else {
                        goto block_88;
                    }
                } else {
block_88:
                    temp_a0_6 = M2C_FIELD(temp_s2, s32 *, 0x14);
                    temp_a1_2 = M2C_FIELD(M2C_FIELD(var_s1, void **, 0x48), u8 *, 0x33);
                    if (temp_a0_6 > 0) {
                        var_v0_2 = ((u8 *) &D_800C02AE)[0x5BAA + (temp_a1_2 * 0x81) + temp_a0_6] * 4; /* port: byte table (lbu), m2c scaled it as s32 */
                    } else {
                        var_v0_2 = (s32) ((u8 *) &D_800C02AE)[(0x5BAA + (temp_a1_2 * 0x81)) - temp_a0_6] * -4; /* port: byte table (lbu) */
                    }
                }
block_91:
                fr.sp98[1] = (s16) var_v0_2;
            }
            M2C_FIELD(M2C_FIELD(var_s1, void **, 0x88), s32 *, 0x70) = (s32) fr.sp98[1];
            fr.sp98[2] = 0;
            mat3x3_from_euler(fr.sp98, fr.sp38);
            func_8002DA98(fr.sp38, fr.sp58);
            sp16C = 0;
            if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x50), s32 *, 4) & 2) {
                sp14C = 0;
            } else if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x7C), s32 *, 0x2C) != 0) {
                sp14C = M2C_FIELD(M2C_FIELD(var_s1, void **, 0x84), s32 *, 0x40);
            } else {
                sp14C = (s32) ((0x1000 - cos_q12(M2C_FIELD(temp_s2, s32 *, 0x10) * 4)) * M2C_FIELD(M2C_FIELD(var_s1, void **, 0x84), s32 *, 0x40)) >> 0xC;
            }
            mat3_mul_vec3_q12(fr.sp18, M2C_FIELD(var_s1, void **, 0x58) + 0x20, sp19C);
            temp_v0_9 = fr.spD0[2] >> 6;
            sp144 = temp_v0_9;
            temp_a0_7 = M2C_FIELD(var_s1, void **, 0x80) + 0x374;
            func_8002D460(temp_a0_7, temp_a0_7, 0, (s32) (temp_v0_9 * temp_v0_9) >> 0x14, sp1A4);
            temp_v0_10 = M2C_FIELD(var_s1, void **, 0x58);
            temp_a3_2 = M2C_FIELD(temp_v0_10, s32 *, 0x4C);
            fr.spD0[0] = M2C_FIELD(temp_v0_10, s32 *, 0x48);
            fr.spD0[1] = temp_a3_2;
            fr.spD0[2] = M2C_FIELD(temp_v0_10, s32 *, 0x50);
            fr.spD0[2] = 0;
            func_80026E3C(var_s1, sp19C, sp1A4);
            sp1F4 = 0;
            var_s7_4 = 0;
            var_s5 = 0;
            sp1FC = 0;
            sp194 = (s32) M2C_FIELD(((M2C_FIELD(M2C_FIELD(var_s1, void **, 0x54), s32 *, 0x50) * 0x2C4) + M2C_FIELD(&D_800C02AE, s32 *, 0x103AA)), u16 *, 0x14);
loop_98:
            temp_v1_10 = M2C_FIELD(var_s1, void **, 0x80);
            temp_s4 = M2C_FIELD(var_s1, void **, 0x88) + (sp1F4 + 0x18);
            temp_v1_11 = M2C_FIELD(temp_v1_10, s32 *, 4) + ((s32) M2C_FIELD((var_s5 + temp_v1_10), s32 *, 0x310) >> 4);
            M2C_FIELD(temp_s4, s32 *, 4) = temp_v1_11;
            temp_v0_11 = M2C_FIELD(M2C_FIELD(var_s1, void **, 0x80), s32 *, 8);
            if (temp_v1_11 < temp_v0_11) {
                M2C_FIELD(temp_s4, s32 *, 4) = temp_v0_11;
            }
            temp_fp = M2C_FIELD(var_s1, void **, 0x8C) + ((var_s7_4 << 5) + 0x30);
            func_8002DA98(temp_fp, sp1AC);
            fr.spA0[0] = (s32) (M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x100) * 0x32) >> 0xA;
            fr.spA0[1] = (s32) (M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x104) * 0x32) >> 0xA;
            fr.spA0[2] = (s32) (M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x108) * 0x32) >> 0xA;
            cross_product(M2C_FIELD(var_s1, void **, 0x58) + 0xAC, fr.spA0, sp1B4);
            fr.spF0[0] += M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0x20);
            fr.spF0[1] += M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0x24);
            fr.spF0[2] += M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0x28);
            temp_v1_12 = var_s5 + M2C_FIELD(var_s1, void **, 0x80);
            sp13C = sp134;
            if (M2C_FIELD(temp_v1_12, s32 *, 0x310) < -0x1F4) {
                M2C_FIELD(temp_v1_12, s32 *, 0x310) = -0x1F4;
            }
            temp_v0_12 = var_s5 + M2C_FIELD(var_s1, void **, 0x80);
            sp154 = (s32) -(M2C_FIELD(temp_v0_12, s32 *, 0x310) * M2C_FIELD(temp_v0_12, s32 *, 0x330)) >> 6;
            mat3_mul_vec3_q12(sp1AC, sp1B4, sp19C);
            temp_s2_2 = fr.spD0[1];
            mat3_mul_vec3_q12(fr.sp18, sp1B4, sp19C);
            temp_v1_13 = M2C_FIELD(var_s1, void **, 0x64);
            temp_s3_2 = M2C_FIELD(temp_v1_13, u8 *, 0xB);
            temp_s0 = (u32) M2C_FIELD(temp_v1_13, u32 *, 4) >> 1;
            if (var_s7_4 < 2) {
                mat3_mul_vec3_q12(fr.sp58, sp19C, sp1B4);
                fr.spE0[0] = -(temp_s0 & 0xFF);
                temp_s0_2 = temp_s3_2 & 0xFF;
                fr.spE0[2] = 0;
                fr.spE0[1] = M2C_FIELD(temp_s4, s32 *, 4) + temp_s0_2;
                mat3_mul_vec3_q12(fr.sp38, fr.spE0, M2C_FIELD(var_s1, void **, 0x64) + (sp1FC + 0x8C));
                temp_v1_14 = sp1FC + M2C_FIELD(var_s1, void **, 0x64);
                M2C_FIELD(temp_v1_14, s32 *, 0xA0) = (s32) -M2C_FIELD(temp_v1_14, s32 *, 0x8C);
                M2C_FIELD((sp1FC + M2C_FIELD(var_s1, void **, 0x64)), s32 *, 0xA4) = (s32) (M2C_FIELD(temp_s4, s32 *, 4) + temp_s0_2);
                temp_v1_15 = sp1FC + M2C_FIELD(var_s1, void **, 0x64);
                M2C_FIELD(temp_v1_15, s32 *, 0xA8) = (s32) -M2C_FIELD(temp_v1_15, s32 *, 0x94);
                temp_a0_8 = sp1FC + M2C_FIELD(var_s1, void **, 0x64);
                M2C_FIELD(temp_a0_8, s32 *, 0x8C) = (s32) (M2C_FIELD(temp_a0_8, s32 *, 0x8C) + M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x10));
                temp_a0_9 = sp1FC + M2C_FIELD(var_s1, void **, 0x64);
                M2C_FIELD(temp_a0_9, s32 *, 0x94) = (s32) (M2C_FIELD(temp_a0_9, s32 *, 0x94) + M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x18));
                temp_a0_10 = sp1FC + M2C_FIELD(var_s1, void **, 0x64);
                M2C_FIELD(temp_a0_10, s32 *, 0xA0) = (s32) (M2C_FIELD(temp_a0_10, s32 *, 0xA0) + M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x10));
                temp_a0_11 = sp1FC + M2C_FIELD(var_s1, void **, 0x64);
                M2C_FIELD(temp_a0_11, s32 *, 0xA8) = (s32) (M2C_FIELD(temp_a0_11, s32 *, 0xA8) + M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x18));
            } else {
                fr.spF0[0] = fr.spD0[0];
                fr.spF0[1] = fr.spD0[1];
                fr.spF0[2] = fr.spD0[2];
                temp_a1_3 = temp_s0 & 0xFF;
                M2C_FIELD((sp1FC + M2C_FIELD(var_s1, void **, 0x64)), s32 *, 0x8C) = (s32) (M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x10) - temp_a1_3);
                temp_a0_12 = temp_s3_2 & 0xFF;
                M2C_FIELD((sp1FC + M2C_FIELD(var_s1, void **, 0x64)), s32 *, 0x90) = (s32) (M2C_FIELD(temp_s4, s32 *, 4) + temp_a0_12);
                M2C_FIELD((sp1FC + M2C_FIELD(var_s1, void **, 0x64)), s32 *, 0x94) = (s32) M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x18);
                M2C_FIELD((sp1FC + M2C_FIELD(var_s1, void **, 0x64)), s32 *, 0xA0) = (s32) (M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x10) + temp_a1_3);
                M2C_FIELD((sp1FC + M2C_FIELD(var_s1, void **, 0x64)), s32 *, 0xA4) = (s32) (M2C_FIELD(temp_s4, s32 *, 4) + temp_a0_12);
                M2C_FIELD((sp1FC + M2C_FIELD(var_s1, void **, 0x64)), s32 *, 0xA8) = (s32) M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x18);
            }
            fr.sp110[0] = fr.spF0[0];
            fr.sp110[1] = fr.spF0[1];
            fr.sp110[2] = fr.spF0[2];
            fr.sp100[0] = 0x1000;
            fr.sp100[1] = 0;
            fr.sp100[2] = 0;
            fr.spF0[0] = fr.spF0[0] >> 4;
            fr.spF0[1] = fr.spF0[1] >> 4;
            fr.spF0[2] = fr.spF0[2] >> 4;
            if (var_s7_4 < 2) {
                mat3_mul_vec3_q12(fr.sp38, fr.sp100, fr.spD0);
            } else {
                fr.spD0[0] = fr.sp100[0];
                fr.spD0[1] = fr.sp100[1];
                fr.spD0[2] = fr.sp100[2];
            }
            mat3_mul_vec3_q12(M2C_FIELD(var_s1, void **, 0x5C) + 0x40, sp19C, sp1BC);
            mat3_mul_vec3_q12(fr.sp78, sp1BC, sp19C);
            fr.spD0[1] = 0;
            mat3_mul_vec3_q12(temp_fp, sp19C, sp1BC);
            mat3_mul_vec3_q12(fr.sp18, sp1BC, sp19C);
            fr.spD0[2] = 0;
            vec3_normalize_fixed(sp19C, fr.sp100);
            if (M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x50) != 0) {
                M2C_FIELD(M2C_FIELD(var_s1, void **, 0x5C), s32 *, 0x64) = (s32) ((s32) (fr.spF0[2] * 0x27C) >> 0xA);
            } else {
                M2C_FIELD(M2C_FIELD(var_s1, void **, 0x5C), s32 *, 0x64) = fr.spF0[2];
            }
            temp_a0_13 = M2C_FIELD(var_s1, void **, 0x5C);
            M2C_FIELD(temp_a0_13, s32 *, 0x68) = (s32) ((s32) (M2C_FIELD(temp_a0_13, s32 *, 0x64) * 0x12) >> 0xA);
            M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0) = fr.spF0[2];
            if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x7C), s32 *, 0x2C) != 0) {
                var_s3 = (var_s7_4 >= 2) << 0xC;
            } else {
                var_s3 = M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x364);
            }
            temp_a1_4 = var_s5 + M2C_FIELD(var_s1, void **, 0x80);
            if (M2C_FIELD(temp_a1_4, s32 *, 0x310) < 0) {
                if (sp194 != 0) {
                    var_a0_3 = (M2C_FIELD(temp_a1_4, s32 *, 0x320) + D_8009E230) * 0x38;
                    var_v1 = &D_8009DC80;
                    var_v0_4 = M2C_FIELD(temp_a1_4, s32 *, 0x2E0) * 0x1C;
                } else {
                    var_a0_3 = (M2C_FIELD(temp_a1_4, s32 *, 0x320) + D_8009E230) * 0x38;
                    var_v0_4 = M2C_FIELD(temp_a1_4, s32 *, 0x2E0) * 0x1C;
                    var_v1 = &D_8009D6D0;
                }
                temp_s6 = var_a0_3 + (var_v0_4 + var_v1);
                fr.spB0[0] = M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x10) << 5;
                fr.spB0[2] = M2C_FIELD((sp1F4 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x18) << 5;
                if (temp_s2_2 < 0) {
                    var_s2 = sp154 - ((s32) (temp_s2_2 * M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x340)) >> 0xA);
                } else {
                    var_s2 = sp154 - ((s32) (temp_s2_2 * (M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x340) * 3)) >> 0xC);
                }
                fr.spE0[0] = (s32) M2C_FIELD(temp_fp, s16 *, 2);
                fr.spE0[1] = (s32) M2C_FIELD(temp_fp, s16 *, 8);
                fr.spE0[2] = (s32) M2C_FIELD(temp_fp, s16 *, 0xE);
                mat3_mul_vec3_q12(fr.sp18, fr.spE0, fr.spD0);
                temp_a2_5 = (s32) (var_s2 * fr.spD0[1]) >> 0xC;
                fr.spC0[0] = (s32) (var_s2 * fr.spD0[0]) >> 0xC;
                fr.spC0[1] = temp_a2_5;
                fr.spC0[2] = (s32) (var_s2 * fr.spD0[2]) >> 0xC;
                var_s2_2 = -angle_atan2_thunk(fr.spD0[1], fr.spD0[0]);
                if ((u32) (var_s2_2 - 0x300) >= 0x201U) {
                    var_s0 = 0;
                    fr.spB0[1] = M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0x4C);
                } else {
                    temp_s0_3 = (s32) (cos_q12((var_s2_2 - 0x400) * 4) * (M2C_FIELD(temp_s6, s32 *, 0xC) + M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x54)), s32 *, 0x30))) >> 0xC;
                    var_s2_2 = angle_atan2_thunk(fr.sp110[0], fr.sp110[2]);
                    M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x54)), s32 *, 0x40) = var_s2_2;
                    fr.spB0[1] = M2C_FIELD(temp_s4, s32 *, 4) << 5;
                    var_a2_2 = var_s2_2;
                    if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x48), s32 *, 0) == 5) {
                        var_a1_4 = M2C_FIELD(temp_s6, s32 *, 0x10);
                        temp_a3_3 = M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x54)), s32 *, 0x10);
                        if (var_s2_2 >= 0x401) {
                            var_a2_2 = 0x800 - var_s2_2;
                        }
                        if (var_s2_2 < -0x400) {
                            var_a2_2 = -0x800 - var_s2_2;
                        }
                        if ((var_a1_4 < var_a2_2) || (var_a1_4 = -var_a1_4, ((var_a2_2 < var_a1_4) != 0))) {
                            var_a2_2 = var_a1_4;
                        }
                        temp_v0_13 = temp_a3_3 >> 5;
                        if (temp_a3_3 > 0) {
                            var_a0_4 = temp_s0_3 + temp_v0_13;
                        } else {
                            var_a0_4 = temp_s0_3 - temp_v0_13;
                        }
                        var_a0_5 = var_a0_4 + (sp154 >> 4);
                        if (((u32) (fr.spF0[2] + 0x257) < 0x4AFU) && ((u32) (fr.spF0[0] + 0x257) < 0x4AFU)) {
                            goto block_149;
                        }
                        goto block_150;
                    }
                    var_a1_5 = M2C_FIELD(temp_s6, s32 *, 0x10);
                    temp_a3_4 = M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x54)), s32 *, 0x10) * 2;
                    if (var_s2_2 >= 0x401) {
                        var_a2_2 = 0x800 - var_s2_2;
                    }
                    if (var_s2_2 < -0x400) {
                        var_a2_2 = -0x800 - var_s2_2;
                    }
                    if ((var_a1_5 < var_a2_2) || (var_a1_5 = -var_a1_5, ((var_a2_2 < var_a1_5) != 0))) {
                        var_a2_2 = var_a1_5;
                    }
                    temp_v0_14 = temp_a3_4 >> 5;
                    if (temp_a3_4 > 0) {
                        var_a0_6 = temp_s0_3 + temp_v0_14;
                    } else {
                        var_a0_6 = temp_s0_3 - temp_v0_14;
                    }
                    var_a0_5 = var_a0_6 + (sp154 >> 4);
                    if (((u32) (fr.spF0[2] + 0x257) < 0x4AFU) && ((u32) (fr.spF0[0] + 0x257) < 0x4AFU)) {
block_149:
                        var_v0_5 = (s32) (fr.spF0[0] * var_a0_5) >> 8;
                    } else {
block_150:
                        var_v0_5 = (s32) (sp154 * var_a0_5 * var_a2_2) >> 0x10;
                    }
                    var_s0 = var_v0_5;
                }
                func_80026E3C(var_s1, sp1C4, sp1A4);
                fr.spD0[0] = (s32) (var_s0 * fr.sp100[0]) >> 0xC;
                fr.spD0[1] = (s32) (var_s0 * fr.sp100[1]) >> 0xC;
                fr.spD0[2] = (s32) (var_s0 * fr.sp100[2]) >> 0xC;
                if (var_s7_4 < 2) {
                    mat3_mul_vec3_q12(fr.sp38, fr.spD0, sp1A4);
                    var_a2_3 = sp1A4;
                } else {
                    var_a2_3 = fr.spD0;
                }
                func_80026E3C(var_s1, sp1C4, var_a2_3);
                if (fr.spF0[2] < 0) {
                    temp_a3_5 = M2C_FIELD(M2C_FIELD(var_s1, void **, 0x54), s32 *, var_s5);
                    var_a1_6 = temp_a3_5 >> 6;
                    if (temp_a3_5 > 0) {
                        var_a0_7 = sp14C;
                    } else {
                        var_a0_7 = -sp14C;
                    }
                    if (var_a1_6 > 0xA) {
                        var_a1_6 = 0xA;
                    } else if (var_a1_6 < -0xA) {
                        var_a1_6 = -0xA;
                    }
                    if (((u32) (temp_a3_5 + 0x12B) < 0x257U) & (sp14C > 0)) {
                        M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x54)), s32 *, 0x10) = 0;
                        var_a3_2 = fr.spF0[2] / (s32) M2C_FIELD(M2C_FIELD(var_s1, void **, 0x80), s32 *, 0xC);
                        var_a2_4 = -fr.spF0[2];
                    } else {
                        temp_v1_16 = ((s32) (temp_a3_5 * M2C_FIELD(M2C_FIELD(var_s1, void **, 0x80), s32 *, 0xC)) >> 0xC) - fr.spF0[2];
                        var_a2_4 = 0x190;
                        if (temp_v1_16 <= 0x190) {
                            var_a2_4 = temp_v1_16;
                            if (var_a2_4 < -0x190) {
                                var_a2_4 = -0x190;
                            }
                        }
                        M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x54)), s32 *, 0x10) = (s32) (var_a2_4 * 2);
                        var_a3_2 = temp_a3_5 + ((s32) ((((((s32) (sp13C * M2C_FIELD((var_s5 + sp1D4), s32 *, 0x108)) >> 0xD) - ((s32) (var_a0_7 * var_s3) >> 0xC)) - var_a1_6) - var_a2_4) * M2C_FIELD(&D_800C02AE, s32 *, 0x80C2)) >> 4);
                    }
                    var_a0_8 = 0x800;
                    if (var_a3_2 <= 0x800) {
                        var_a0_8 = var_a3_2;
                        if (var_a0_8 < -0x800) {
                            var_a0_8 = -0x800;
                        }
                    }
                    M2C_FIELD(M2C_FIELD(var_s1, void **, 0x54), s32 *, var_s5) = var_a0_8;
                } else {
                    if (fr.spF0[2] >= 0x12D) {
                        var_s3_2 = 0;
                        temp_s0_4 = (((s32) (sp13C * M2C_FIELD((var_s5 + sp1D4), s32 *, 0x108)) >> 0xD) - ((s32) (sp14C * var_s3) >> 0xC)) - 0xA;
                        do {
                            var_a2_4 = applyDeadZoneScale(M2C_FIELD(temp_s6, s32 *, 0x14), sp154, M2C_FIELD(temp_s6, s32 *, 0xC) * 2, var_s2_2, M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x54)), s32 *, 0x10));
                            temp_a0_14 = var_s5 + M2C_FIELD(var_s1, void **, 0x54);
                            var_s3_2 += 1;
                            M2C_FIELD(temp_a0_14, s32 *, 0x10) = (s32) (M2C_FIELD(temp_a0_14, s32 *, 0x10) + ((s32) ((temp_s0_4 - var_a2_4) * M2C_FIELD(&D_800C02AE, s32 *, 0x80C2)) >> 6));
                        } while (var_s3_2 < 4);
                        temp_v1_17 = var_s5 + M2C_FIELD(var_s1, void **, 0x54);
                        if (M2C_FIELD(temp_v1_17, s32 *, 0x10) < -0x1000) {
                            M2C_FIELD(temp_v1_17, s32 *, 0x10) = -0x1000;
                        }
                        var_s0_2 = 0x1000;
                        if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x48), s32 *, 0) != 5) {
                            var_s0_2 = M2C_FIELD(((D_8009EB80 * 4) + M2C_FIELD(var_s1, s32 *, 0x28)), s32 *, 0xA8);
                        }
                        temp_v1_18 = var_s5 + M2C_FIELD(var_s1, void **, 0x54);
                        if (var_s0_2 < M2C_FIELD(temp_v1_18, s32 *, 0x10)) {
                            M2C_FIELD(temp_v1_18, s32 *, 0x10) = var_s0_2;
                        }
                    } else {
                        M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x54)), s32 *, 0x10) = 0;
                        var_a2_4 = (((s32) (sp13C * M2C_FIELD((var_s5 + sp1D4), s32 *, 0x108)) >> 0xD) - ((s32) (((s32) (sp14C * fr.spF0[2]) >> 0xA) * var_s3) >> 0xC)) - (fr.spF0[2] >> 2);
                    }
                    temp_v1_19 = var_s5 + M2C_FIELD(var_s1, void **, 0x54);
                    M2C_FIELD(temp_v1_19, s32 *, 0) = (s32) ((s32) ((M2C_FIELD(temp_v1_19, s32 *, 0x10) + 0x1000) * fr.spF0[2]) >> 0xD);
                }
                fr.spC0[0] = 0;
                fr.spC0[1] = 0;
                fr.spC0[2] = ((s32) (sp154 * M2C_FIELD(temp_s6, s32 *, 8) * fr.spF0[2]) >> 0x13) + var_a2_4;
                var_v0_6 = var_s7_4 < 2;
                if (M2C_FIELD(var_s1, s32 *, 0x14) & 0x10) {
                    M2C_FIELD(M2C_FIELD(var_s1, void **, 0x54), s32 *, var_s5) = 0;
                    var_v0_6 = var_s7_4 < 2;
                }
                if (var_v0_6 != 0) {
                    mat3_mul_vec3_q12(fr.sp38, fr.spC0, sp19C);
                    var_a2_5 = sp19C;
                } else {
                    var_a2_5 = fr.spC0;
                }
                func_80026E3C(var_s1, fr.spB0, var_a2_5);
                M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x64)), s32 *, 0x1CC) = fr.spF0[0];
                sp16C += 1;
                M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x64)), s32 *, 0x1DC) = (s32) (((s32) (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x54), s32 *, var_s5) * M2C_FIELD(M2C_FIELD(var_s1, void **, 0x80), s32 *, 0xC)) >> 0xC) - fr.spF0[2]);
            } else {
                temp_v1_20 = M2C_FIELD(M2C_FIELD(var_s1, void **, 0x54), s32 *, var_s5);
                if (temp_v1_20 < 0) {
                    var_a1_7 = -0xA;
                    if (temp_v1_20 < -0x32) {
                        var_a0_9 = -sp14C;
                    } else {
                        var_v0_7 = sp14C * temp_v1_20;
                        var_a1_7 = temp_v1_20 >> 2;
                        goto block_199;
                    }
                } else {
                    var_a1_7 = temp_v1_20 >> 2;
                    if (temp_v1_20 >= 0x33) {
                        var_a0_9 = sp14C;
                        var_a1_7 = 0xA;
                    } else {
                        var_v0_7 = sp14C * temp_v1_20;
block_199:
                        var_a0_9 = var_v0_7 >> 6;
                    }
                }
                temp_v1_21 = var_s5 + M2C_FIELD(var_s1, void **, 0x54);
                *temp_v1_21 += (s32) (((((s32) (sp13C * M2C_FIELD((var_s5 + sp1D4), s32 *, 0x108)) >> 0xD) - ((s32) (var_a0_9 * var_s3) >> 0xC)) - var_a1_7) * M2C_FIELD(&D_800C02AE, s32 *, 0x80C2)) >> 6;
                if (fr.spF0[2] != 0) {
                    temp_a0_15 = var_s5 + M2C_FIELD(var_s1, void **, 0x54);
                    M2C_FIELD(temp_a0_15, s32 *, 0x10) = (s32) (((s32) (M2C_FIELD(temp_a0_15, s32 *, 0) * M2C_FIELD(M2C_FIELD(var_s1, void **, 0x80), s32 *, 0xC)) / fr.spF0[2]) - 0x1000);
                } else {
                    M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x54)), s32 *, 0x10) = 0;
                }
                temp_v1_22 = var_s5 + M2C_FIELD(var_s1, void **, 0x54);
                if (M2C_FIELD(temp_v1_22, s32 *, 0x10) < -0x1000) {
                    M2C_FIELD(temp_v1_22, s32 *, 0x10) = -0x1000;
                }
                temp_v1_23 = var_s5 + M2C_FIELD(var_s1, void **, 0x54);
                if (M2C_FIELD(temp_v1_23, s32 *, 0x10) > 0x7FFF) {
                    M2C_FIELD(temp_v1_23, s32 *, 0x10) = 0x7FFF;
                }
                M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x64)), s32 *, 0x1CC) = 0;
                M2C_FIELD((var_s5 + M2C_FIELD(var_s1, void **, 0x64)), s32 *, 0x1DC) = 0;
            }
            var_s5 += 4;
            var_s7_4 += 1;
            sp1F4 += 0x14;
            sp1FC += 0x28;
            if (var_s7_4 < 4) {
                goto loop_98;
            }
            sp164 = 0;
            var_s5_2 = 0;
            var_s7_5 = 0;
            sp15C = 0;
            if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x8C), s32 *, 0x334) > 0) {
                sp1EC = 0x338;
                do {
                    temp_s4_2 = M2C_FIELD(var_s1, void **, 0x8C) + sp1EC;
                    temp_s3_3 = M2C_FIELD(temp_s4_2, s32 *, 0x24);
                    func_8002DA98(temp_s4_2, fr.sp78);
                    temp_v0_15 = temp_s3_3 * 4;
                    if (sp194 != 0) {
                        var_a0_10 = M2C_FIELD(temp_s4_2, s32 *, 0x2C) * 0x38;
                        var_v1_2 = &D_8009DC80;
                        var_v0_8 = M2C_FIELD((temp_v0_15 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x2E0) * 0x1C;
                    } else {
                        var_a0_10 = M2C_FIELD(temp_s4_2, s32 *, 0x2C) * 0x38;
                        var_v0_8 = M2C_FIELD((temp_v0_15 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x2E0) * 0x1C;
                        var_v1_2 = &D_8009D6D0;
                    }
                    temp_s6_2 = var_a0_10 + (var_v0_8 + var_v1_2);
                    temp_a0_16 = temp_s3_3 * 0x14;
                    fr.spA0[0] = M2C_FIELD((temp_a0_16 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x100) * 0xC;
                    fr.spA0[1] = M2C_FIELD((temp_a0_16 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x104) * 0xC;
                    fr.spA0[2] = M2C_FIELD((temp_a0_16 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x108) * 0xC;
                    func_8002D740(M2C_FIELD(var_s1, void **, 0x58) + 0xAC, fr.spA0, sp1B4);
                    temp_a0_17 = fr.spF0[0] + ((s32) M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0x20) >> 4);
                    fr.spF0[0] = temp_a0_17;
                    temp_a1_5 = fr.spF0[1] + ((s32) M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0x24) >> 4);
                    fr.spF0[1] = temp_a1_5;
                    temp_v1_24 = fr.spF0[2] + ((s32) M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0x28) >> 4);
                    fr.spF0[2] = temp_v1_24;
                    temp_v0_16 = M2C_FIELD(temp_s4_2, void **, 0x20);
                    if (temp_v0_16 != NULL) {
                        fr.spF0[0] = temp_a0_17 - ((s32) M2C_FIELD(M2C_FIELD(temp_v0_16, void **, 0x58), s32 *, 0x20) >> 4);
                        fr.spF0[1] = temp_a1_5 - ((s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_s4_2, void **, 0x20), void **, 0x58), s32 *, 0x24) >> 4);
                        fr.spF0[2] = temp_v1_24 - ((s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_s4_2, void **, 0x20), void **, 0x58), s32 *, 0x28) >> 4);
                    }
                    if (M2C_FIELD(temp_s4_2, s32 *, 0x28) < -0x1F4) {
                        M2C_FIELD(temp_s4_2, s32 *, 0x28) = -0x1F4;
                    }
                    sp154 = (s32) -(M2C_FIELD(temp_s4_2, s32 *, 0x28) * M2C_FIELD(temp_s6_2, s32 *, 0)) >> 6;
                    mat3_mul_vec3_q12(fr.sp78, sp1B4, fr.spD0);
                    if (((u32) (fr.spD0[2] + 0x12B) < 0x257U) && ((u32) (fr.spD0[0] + 0x12B) < 0x257U)) {
                        var_s0_3 = M2C_FIELD(temp_s6_2, s32 *, 0xC) << 5;
                    } else {
                        var_s0_3 = (s32) (sp154 * M2C_FIELD(temp_s6_2, s32 *, 0xC)) >> 4;
                    }
                    if (fr.spD0[1] < 0) {
                        var_s2_3 = sp154 - ((fr.spD0[1] >> 6) * M2C_FIELD(temp_s6_2, s32 *, 4));
                    } else {
                        var_s2_3 = sp154 - ((fr.spD0[1] >> 8) * M2C_FIELD(temp_s6_2, s32 *, 4) * 3);
                    }
                    fr.spE0[0] = (s32) M2C_FIELD(temp_s4_2, s16 *, 2);
                    fr.spE0[1] = (s32) M2C_FIELD(temp_s4_2, s16 *, 8);
                    var_s5_2 -= fr.spD0[1];
                    fr.spE0[2] = (s32) M2C_FIELD(temp_s4_2, s16 *, 0xE);
                    mat3_mul_vec3_q12(fr.sp18, sp1BC, sp1A4);
                    fr.spC0[0] = (s32) (var_s2_3 * fr.spC0[0]) >> 0xC;
                    fr.spC0[1] = (s32) (var_s2_3 * fr.spC0[1]) >> 0xC;
                    fr.spC0[2] = (s32) (var_s2_3 * fr.spC0[2]) >> 0xC;
                    if (M2C_FIELD(temp_s4_2, s32 *, 0x2C) == 0) {
                        fr.spC0[1] = 0;
                    }
                    temp_v1_25 = temp_s3_3 * 0x14;
                    fr.spB0[0] = M2C_FIELD((temp_v1_25 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x10) << 5;
                    fr.spB0[1] = M2C_FIELD((temp_v1_25 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x14) << 5;
                    fr.spB0[2] = M2C_FIELD((temp_v1_25 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x18) << 5;
                    if (M2C_FIELD(temp_s4_2, s32 *, 0x2C) == 0) {
                        fr.spB0[1] = M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0x4C);
                    }
                    func_80026E3C(var_s1, sp1C4, sp1A4);
                    fr.spD0[1] = 0;
                    fr.spE0[1] = 0;
                    fr.spE0[0] = (s32) (var_s0_3 * fr.spD0[0]) >> 0xC;
                    fr.spE0[2] = (s32) (var_s0_3 * fr.spD0[2]) >> 0xC;
                    mat3_mul_vec3_q12(temp_s4_2, sp1BC, sp1A4);
                    mat3_mul_vec3_q12(fr.sp18, sp1A4, sp19C);
                    func_80026E3C(var_s1, sp1C4, sp19C);
                    if (temp_s3_3 & 1) {
                        sp164 += 1;
                    } else {
                        sp15C += 1;
                    }
                    var_s7_5 += 1;
                    sp1EC += 0x30;
                } while (var_s7_5 < M2C_FIELD(M2C_FIELD(var_s1, void **, 0x8C), s32 *, 0x334));
            }
            M2C_FIELD(M2C_FIELD(var_s1, void **, 0x8C), s32 *, 0x334) = 0;
            var_s7_6 = 0;
            if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x8C), s32 *, 0x100) > 0) {
                sp1CC = fr.spA0;
                var_s4 = 0x104;
                do {
                    temp_s0_5 = M2C_FIELD(var_s1, void **, 0x8C) + var_s4;
                    temp_s3_4 = M2C_FIELD(temp_s0_5, s32 *, 0x2C);
                    temp_fp_2 = temp_s0_5 + 8;
                    func_8002DA98(temp_fp_2, fr.sp78);
                    temp_v0_17 = temp_s3_4 * 4;
                    if (sp194 != 0) {
                        var_a0_11 = M2C_FIELD(temp_s0_5, s32 *, 0x34) * 0x38;
                        var_v1_3 = &D_8009DC80;
                        var_v0_9 = M2C_FIELD((temp_v0_17 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x2E0) * 0x1C;
                    } else {
                        var_a0_11 = M2C_FIELD(temp_s0_5, s32 *, 0x34) * 0x38;
                        var_v0_9 = M2C_FIELD((temp_v0_17 + M2C_FIELD(var_s1, void **, 0x80)), s32 *, 0x2E0) * 0x1C;
                        var_v1_3 = &D_8009D6D0;
                    }
                    temp_s6_3 = var_a0_11 + (var_v0_9 + var_v1_3);
                    fr.spB0[0] = M2C_FIELD(temp_s0_5, s16 *, 0) * 0xC;
                    fr.spB0[1] = M2C_FIELD(temp_s0_5, s16 *, 2) * 0xC;
                    fr.spB0[2] = M2C_FIELD(temp_s0_5, s16 *, 4) * 0xC;
                    mat3_mul_vec3_q12(M2C_FIELD(var_s1, void **, 0x5C) + 0x40, fr.spB0, sp1CC);
                    func_8002D740(M2C_FIELD(var_s1, void **, 0x58) + 0xAC, sp1CC, sp1B4);
                    temp_a0_18 = fr.spF0[0] + ((s32) M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0x20) >> 4);
                    fr.spF0[0] = temp_a0_18;
                    temp_a1_6 = fr.spF0[1] + ((s32) M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0x24) >> 4);
                    fr.spF0[1] = temp_a1_6;
                    temp_v1_26 = fr.spF0[2] + ((s32) M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s32 *, 0x28) >> 4);
                    fr.spF0[2] = temp_v1_26;
                    temp_v0_18 = M2C_FIELD(temp_s0_5, void **, 0x28);
                    if (temp_v0_18 != NULL) {
                        fr.spF0[0] = temp_a0_18 - ((s32) M2C_FIELD(M2C_FIELD(temp_v0_18, void **, 0x58), s32 *, 0x20) >> 4);
                        fr.spF0[1] = temp_a1_6 - ((s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_s0_5, void **, 0x28), void **, 0x58), s32 *, 0x24) >> 4);
                        fr.spF0[2] = temp_v1_26 - ((s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_s0_5, void **, 0x28), void **, 0x58), s32 *, 0x28) >> 4);
                    }
                    mat3_mul_vec3_q12(fr.sp78, sp1B4, fr.spD0);
                    if (M2C_FIELD(temp_s0_5, s32 *, 0x30) < -0x1F4) {
                        M2C_FIELD(temp_s0_5, s32 *, 0x30) = -0x1F4;
                    }
                    sp154 = (s32) -(M2C_FIELD(temp_s0_5, s32 *, 0x30) * M2C_FIELD(temp_s6_3, s32 *, 0)) >> 6;
                    if (((u32) (fr.spD0[2] + 0x12B) < 0x257U) && ((u32) (fr.spD0[0] + 0x12B) < 0x257U)) {
                        var_s0_4 = M2C_FIELD(temp_s6_3, s32 *, 0xC) * 4;
                    } else {
                        var_s0_4 = (s32) (sp154 * M2C_FIELD(temp_s6_3, s32 *, 0xC)) >> 4;
                    }
                    if (fr.spD0[1] < 0) {
                        var_s2_4 = sp154 - ((fr.spD0[1] >> 6) * M2C_FIELD(temp_s6_3, s32 *, 4));
                    } else {
                        var_s0_4 = 0;
                        var_s2_4 = sp154 - ((fr.spD0[1] >> 8) * M2C_FIELD(temp_s6_3, s32 *, 4) * 3);
                    }
                    temp_v0_19 = M2C_FIELD(temp_fp_2, s16 *, 2);
                    fr.spE0[0] = (s32) temp_v0_19;
                    temp_v0_20 = M2C_FIELD(temp_fp_2, s16 *, 8);
                    fr.spE0[1] = (s32) temp_v0_20;
                    temp_v0_21 = M2C_FIELD(temp_fp_2, s16 *, 0xE);
                    fr.spE0[2] = (s32) temp_v0_21;
                    fr.spE0[0] = (s32) (var_s2_4 * temp_v0_19) >> 0xC;
                    temp_a3_6 = (s32) (var_s2_4 * temp_v0_20) >> 0xC;
                    fr.spE0[1] = temp_a3_6;
                    fr.spE0[2] = (s32) (var_s2_4 * temp_v0_21) >> 0xC;
                    mat3_mul_vec3_q12(fr.sp18, sp1BC, sp1A4);
                    func_80026E3C(var_s1, fr.spB0, sp1A4);
                    fr.spD0[1] = 0;
                    fr.spE0[1] = 0;
                    fr.spE0[0] = (s32) (var_s0_4 * fr.spD0[0]) >> 0xC;
                    fr.spE0[2] = (s32) (var_s0_4 * fr.spD0[2]) >> 0xC;
                    mat3_mul_vec3_q12(temp_fp_2, sp1BC, sp1A4);
                    mat3_mul_vec3_q12(fr.sp18, sp1A4, fr.spD0);
                    var_s7_6 += 1;
                    var_s4 += 0x38;
                } while (var_s7_6 < M2C_FIELD(M2C_FIELD(var_s1, void **, 0x8C), s32 *, 0x100));
            }
            *M2C_FIELD(var_s1, s32 **, 0x94) = 0;
            temp_s7 = sp15C + sp164;
            if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x54), s32 *, 0xA0) != temp_s7) {
                var_s5_3 = ((var_s5_2 & ((s32) ~var_s5_2 >> 0x1F)) * 8) + 0x3E8;
                if (var_s5_3 >= 0x4000) {
                    var_s5_3 = 0x3FFF;
                }
                *M2C_FIELD(var_s1, s32 **, 0x94) = var_s5_3;
            }
            M2C_FIELD(M2C_FIELD(var_s1, void **, 0x54), s32 *, 0xA0) = temp_s7;
            M2C_FIELD(M2C_FIELD(var_s1, void **, 0x8C), s32 *, 0x100) = 0;
            if ((sp144 > 0) && !(D_8009D538 & 0x800) && !(M2C_FIELD(var_s1, s32 *, 0x14) & 0x180)) {
                temp_a0_19 = M2C_FIELD(var_s1, void **, 0x6C);
                temp_v1_27 = (s32) (sp144 * M2C_FIELD(&D_800C02AE, s32 *, 0x80C2)) >> 0xB;
                M2C_FIELD(temp_a0_19, s32 *, 0x2C) = (s32) (M2C_FIELD(temp_a0_19, s32 *, 0x2C) + temp_v1_27);
                temp_a0_20 = M2C_FIELD(var_s1, void **, 0x88);
                M2C_FIELD(temp_a0_20, s32 *, 0x84) = (s32) (M2C_FIELD(temp_a0_20, s32 *, 0x84) + temp_v1_27);
            }
            if (((sp15C + sp164) >= 2) & (sp16C < 3)) {
                temp_v1_28 = M2C_FIELD(var_s1, void **, 0x54);
                M2C_FIELD(temp_v1_28, s32 *, 0xA4) = (s32) (M2C_FIELD(temp_v1_28, s32 *, 0xA4) + 1);
                if (M2C_FIELD(M2C_FIELD(var_s1, void **, 0x54), s32 *, 0xA4) == 0x1E) {
                    func_80024B28(var_s1);
                }
            } else {
                M2C_FIELD(M2C_FIELD(var_s1, void **, 0x54), s32 *, 0xA4) = 0;
            }
            M2C_FIELD(M2C_FIELD(var_s1, void **, 0x80), s32 *, 0x39C) = sp16C;
            var_s1 = M2C_FIELD(var_s1, void **, 4);
            var_a2 = 0;
        } while (var_s1 != NULL);
    }
}