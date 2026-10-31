extern void func_800932E0(void*,s32,u32,s32,s32);
extern s32 D_800A1CD0;
extern u8 *D_800B5AF8;
extern void __osLeoResume(void),__osLeoAbnormalResume(void);
#define L(p,o) (*(s32*)((u8*)(p)+(o)))
#define U(p,o) (*(u16*)((u8*)(p)+(o)))

s32 func_8008FBC0(void) {
    volatile s32 sp18;
    s32 temp_a0;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 var_v0;
    u32 temp_a0_2;
    void *temp_s0;
    void *temp_s1;
    void *temp_v1_2;

    temp_s0 = D_800B5AF8 + 0x14;
    temp_s1 = temp_s0 + ((U(D_800B5AF8,0x1a) * 0x24) + 0x18);
    sp18 = *(volatile s32 *)0xA4600010;
    if (sp18 & 1) {
        L(temp_s1,0x0) = 0x1D;
        D_800A1CD0 &= ~0x800;
        __osLeoResume();
        return 1;
    }
    temp_v0 = *(volatile s32 *)0xA4600010;
    sp18 = temp_v0;
    if (sp18 & 3) {
        do {
            temp_v0_2 = *(volatile s32 *)0xA4600010;
            sp18 = temp_v0_2;
        } while (sp18 & 3);
    }
    temp_s2 = *(volatile s32 *)0xA5000508;
    if (temp_s2 & 0x02000000) {
        temp_v0_3 = *(volatile s32 *)0xA4600010;
        sp18 = temp_v0_3;
        if (sp18 & 3) {
            do {
                temp_v0_4 = *(volatile s32 *)0xA4600010;
                sp18 = temp_v0_4;
            } while (sp18 & 3);
        }
        *(volatile s32 *)0xA5000510 = L(temp_s0,0x10) | 0x01000000;
        L(temp_s1,0x0) = 0;
        return 0;
    }
    temp_v1 = L(temp_s0,0);
    if (temp_v1 != 2) {
        if (temp_s2 & 0x08000000) {
            temp_v0_5 = *(volatile s32 *)0xA4600010;
            sp18 = temp_v0_5;
            if (sp18 & 3) {
                do {
                    temp_v0_6 = *(volatile s32 *)0xA4600010;
                    sp18 = temp_v0_6;
                } while (sp18 & 3);
            }
            temp_s2 = *(volatile s32*)0xA5000508;
            L(temp_s1,0x0) = 0x16;
            __osLeoResume();
            *(volatile s32 *)0xA4600010 = 2;
            D_800A1CD0 |= 0x100401;
            return 1;
        }
        if (temp_v1 == 1) {
            if (!(temp_s2 & 0x40000000)) {            var_v0 = 0x18;
            if ((L(temp_s0,0x8) + 1) == (U(temp_s0,0x4) * 0x55)) {
                *(volatile s32 *)0xA4600010 = 2;
                L(temp_s1,0x0) = 0;
                D_800A1CD0 |= 0x100401;
                __osLeoResume();
                return 1;
            }
            goto block_56;
            }

                L(temp_s1,0x4) = (s32) (L(temp_s1,0x4) + L(temp_s1,0xC));
                L(temp_s0,0x8) = (s32) (L(temp_s0,0x8) + 1);
                func_800932E0(D_800B5AF8, 1, 0x05000400, L(temp_s1,0x4), L(temp_s1,0xC));
                return 1;
  }
        var_v0 = 4;
        if (temp_v1 == 0) {
            if (U(temp_s0,0x4) == 3) {
                if ((L(temp_s1,0x10) + 0x11) < L(temp_s0,0x8)) {
                    L(temp_s1,0x0) = 0;
                    goto block_57;
                }
                if (!(temp_s2 & 0x40000000)) {
                    var_v0 = 0x17;
                    goto block_56;
                }
                goto block_30;
            }
            L(temp_s1,0x4) = (s32) (L(temp_s1,0x4) + L(temp_s1,0xC));
block_30:
            temp_a0 = *(volatile s32 *)0xA5000510;
            if (((temp_a0 & 0x600000) == 0x600000) || (temp_a0 & 0x02000000)) {
                temp_a0_2 = L(temp_s1,0x10);
                if (temp_a0_2 >= 4U) {
                    var_v0 = 0x17;
                    if (U(temp_s0,0x4) == 3) {
                        if (L(temp_s0,0x8) >= 0x53) {
                            L(temp_s1,0x0) = 0x17;
                            goto block_57;
                        }
                        goto block_37;
                    }
                    goto block_56;
                }
                L(temp_s1,temp_a0_2*4+0x14) = (s32) (L(temp_s0,0x8) + 1);
block_37:
                L(temp_s1,0x10) = (u32) (L(temp_s1,0x10) + 1);
                goto block_38;
            }
block_38:
            if (temp_s2 & 0x10000000) {
                if ((L(temp_s0,0x8) + 1) != 0x58) {
                    L(temp_s1,0x0) = 0x18;
                    __osLeoAbnormalResume();
                }
                if (L(temp_s0,4) == 0x20000) {
                    U(temp_s0,0x6) = 1;
                    L(temp_s0,0x8) = -1;
                    L(temp_s0,0x40) = (s32) (L(temp_s0,0x40) - L(temp_s0,0x48));
                    L(temp_s1,0x0) = 0x16;
                } else {
                    *(volatile s32 *)0xA4600010 = 2;
                    L(D_800B5AF8,0x14) = 2;
                    L(temp_s1,0x0) = 0;
                    D_800A1CD0 |= 0x100401;
                }
                func_800932E0(D_800B5AF8, 0, 0x05000000, L(temp_s1,0x8), L(temp_s1,0xC) * 4);
                return 1;
            }
            if ((L(temp_s0,0x8) == -1) && (L(temp_s0,4) == 0x20001)) {
                if (L(temp_s0,0x28) == 0) {
                    temp_v1_2 = (void*)L(temp_s0,0x20);
                    if ((L(temp_v1_2,0x0) | L(temp_v1_2,0x4) | L(temp_v1_2,0x8) | L(temp_v1_2,0xC)) != 0) {
                        L(temp_s0,0x18) = 0x17;
                        goto block_57;
                    }
                }
                L(temp_s0,0x18) = 0;
                __osLeoResume();
                goto block_51;
            }
block_51:
            temp_v1_3 = L(temp_s0,0x8) + 1;
            L(temp_s0,0x8) = temp_v1_3;
            if (temp_s2 & 0x40000000) {
                if (temp_v1_3 >= 0x55) {
                    var_v0 = 0x18;
                    goto block_56;
                }
                func_800932E0(D_800B5AF8, 0, 0x05000400, L(temp_s1,0x4), L(temp_s1,0xC));
                L(temp_s1,0x0) = 0;
                return 1;
            }
            var_v0 = 0x18;
            if (temp_v1_3 < 0x55) {
                goto block_56;
            }
            goto block_58;
        }
block_56:
        L(temp_s1,0x0) = var_v0;
block_57:
        __osLeoAbnormalResume();
        goto block_58;
    }
block_58:
    return 1;
}
