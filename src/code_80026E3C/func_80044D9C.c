#include "snapshot29_0433f7af8f6d.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

extern short D_800ADFDC;
extern int D_800AE44C;
extern float D_800C35E0;

s32 func_80027C64();
s32 func_80038A8C();
s32 func_80086854();
s32 func_80086A34();
s32 func_80086DE8();
extern s32 D_8009D538;
extern s32 D_8009F640;
extern char D_800A73E0[];
extern char D_800AE850[];
extern char D_800C02AE[];

void func_80044D9C(void *arg0, s32 arg1, void *arg2) {
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_v1;
    int var_a0;
    u16 temp_v0;
    u16 limit;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_6;
    void *temp_a1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *var_s0;
    void *var_s1;
    void *var_s2;

    var_s1 = arg2;
    if (!(D_8009D538 & 0x800)) {
        temp_a1 = *(void * *)((char *)var_s1 + 0x70);
        var_s2 = arg0;
        temp_v1 = *(s32 *)((char *)temp_a1 + 0x28);
        if (temp_v1 == *(u16 *)((char *)var_s2 + 0)) {
            *(s32 *)((char *)temp_a1 + 0x28) = (s32) (temp_v1 + 1);
            temp_a0 = *(void * *)((char *)var_s1 + 0x70);
            if (*(s32 *)((char *)temp_a0 + 0x28) == D_800ADFDC) {
                *(s32 *)((char *)temp_a0 + 0x28) = 0;
            }
            temp_v0 = M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0x1E);
            if ((temp_v0 != 0) & (temp_v0 != 5)) {
                temp_v1_2 = *(void * *)((char *)var_s1 + 0x6C);
                M2C_FIELD(((*(u16 *)((char *)var_s2 + 0) * 4) + *(s32 *)((char *)temp_v1_2 + 0x18)), s32 *, -4) = (s32) *(s32 *)((char *)temp_v1_2 + 4);
                if (((u16) M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0xE) >= 2U) && (M2C_FIELD(*(void * *)((char *)var_s1 + 0x48), s32 *, 0) < 4)) {
                    var_s0 = **(void ** *)(D_800AE850 + 0x73F0);
                    var_a0 = 1;
                    limit = (u16) M2C_FIELD(*(void * *)((char *)var_s1 + 0x6C), u16 *, 0xA);
                    if (var_s0 != NULL) {
                        do {
                            if ((**(s32 * *)((char *)var_s0 + 0x48) < 4) & ((s32) var_s0 != var_s1)) {
                                var_a0 &= -((u16) M2C_FIELD(*(void * *)((char *)var_s0 + 0x6C), u16 *, 0xA) >= limit);
                            }
                            var_s0 = *(void * *)((char *)var_s0 + 4);
                        } while ((var_s0 != NULL) & ((var_a0 & 0xFF) != 0));
                    }
                    if (var_a0 & 0xFF) {
                        temp_a0_2 = *(void * *)((char *)var_s1 + 0x6C);
                        *(s32 *)((char *)temp_a0_2 + 0x10) += *(u16 *)((char *)var_s2 + 2);
                        temp_v1_3 = *(void * *)((char *)var_s1 + 0x6C);
                        if (*(s32 *)((char *)temp_v1_3 + 0x10) >= 0x64) {
                            *(s32 *)((char *)temp_v1_3 + 0x10) = 0x63;
                        }
                        var_s0 = **(void ** *)(D_800AE850 + 0x73F0);
                        if (var_s0 != NULL) {
                            register var_s2 = (void *)-0x201;
                            do {
                                if ((M2C_FIELD(*(void * *)((char *)var_s0 + 0x48), s32 *, 0) < 4) & (var_s0 != (s32) var_s1)) {
                                    M2C_FIELD(*(void * *)((char *)var_s0 + 0x6C), s32 *, 0x10) = (s32) M2C_FIELD(*(void * *)((char *)var_s1 + 0x6C), s32 *, 0x10);
                                    temp_a0_3 = *(s32 *)((char *)var_s0 + 0x14);
                                    if (temp_a0_3 & 0x200) {
 void *obj = *(void **)((char *)var_s0 + 0x48);
                                        *(s32 *)((char *)var_s0 + 0x14) = (s32) (temp_a0_3 & ~0x200);
                                        D_800AE44C = 0;
                                        M2C_FIELD(*(void * *)((char *)var_s0 + 0x48), s32 *, 0x20) = (s32) (func_80027C64(M2C_FIELD(obj, u16 *, 2)) & 0xFFFF);
                                    }
                                }
                                var_s0 = *(void * *)((char *)var_s0 + 4);
                            } while (var_s0 != NULL);
                        }
                        temp_a0_4 = *(s32 *)((char *)var_s1 + 0x14);
                        if (temp_a0_4 & 0x200) {
                            void *obj = *(void **)((char *)var_s1 + 0x48);
                            *(s32 *)((char *)var_s1 + 0x14) = (s32) (temp_a0_4 & ~0x200);
                            D_800AE44C = 0;
                            M2C_FIELD(*(void * *)((char *)var_s1 + 0x48), s32 *, 0x20) = (s32) (func_80027C64(M2C_FIELD(obj, u16 *, 2)) & 0xFFFF);
                        }
                        goto block_27;
                    }
                } else {
                    temp_a0_5 = *(s32 *)((char *)var_s1 + 0x14);
                    if (temp_a0_5 & 0x200) {
                        void *obj=*(void **)((char *)var_s1+0x48);
                        *(s32 *)((char *)var_s1 + 0x14) = (s32) (temp_a0_5 & ~0x200);
                        D_800AE44C = 0;
                        M2C_FIELD(*(void * *)((char *)var_s1 + 0x48), s32 *, 0x20) = (s32) (func_80027C64(M2C_FIELD(obj, u16 *, 2)) & 0xFFFF);
                    }
                    temp_a0_6 = *(void * *)((char *)var_s1 + 0x6C);
                    *(s32 *)((char *)temp_a0_6 + 0x10) += *(u16 *)((char *)var_s2 + 2);
                    temp_v1_4 = *(void * *)((char *)var_s1 + 0x6C);
                    if (*(s32 *)((char *)temp_v1_4 + 0x10) >= 0x64) {
                        *(s32 *)((char *)temp_v1_4 + 0x10) = 0x63;
                    }
block_27:
                    if (M2C_FIELD(*(void * *)((char *)var_s1 + 0x48), s32 *, 0) < 4) {
                        func_80086A34(1);
                        D_8009F640 &= ~0x10;
                        func_80038A8C(0x14);
                        func_80086854(D_800C02AE + 0x6C6A);
                        func_80086DE8((s32) (D_800C35E0 * 80.0f));
                    }
                }
            }
        }
    }
}
