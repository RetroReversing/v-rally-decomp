#include "common.h"

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



extern unsigned char D_800ADFA8;
extern unsigned char D_800ADFE1;
extern int D_800ADFE8;
extern unsigned char D_800ADFE0;


s32 func_80042CC4();
s32 func_800448A4();
s32 func_80044908();
void *func_8004D784();
s8 func_80084C0C();
extern s32 D_8009D538;
extern s32 (*D_800A0280[])(void *,void *);
extern s32 (*D_800A0284)(void *, void *);
extern char D_800A73E0[];
extern char D_800C02AE[];
extern void *D_800C35A0;

void func_80046AB0(void *arg0) {
    char pad[24];
    s32 (*temp_v0)(void *, void *);
    s32 temp_s2;
    s32 var_a0;
    s32 var_s1;
    s32 var_s4;
    u16 temp_v0_3;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_s6;
    void *temp_v0_2;
    void *temp_v1;
    void *temp_v1_2;
    void *var_s0;

    M2C_FIELD(*(void * *)((char *)arg0 + 0x9C), s32 *, 0x38) = 1;
    if (!(*(s32 *)((char *)arg0 + 0x14) & 0x80) && (M2C_FIELD(D_800C35A0, u16 *, 0x1E) != 7)) {
        temp_s6 = **(void ** *)((char *)arg0 + 0x8C);
        temp_v1 = *(void * *)((char *)temp_s6 + 0x5C);
        var_s4 = 0;
        if (temp_v1 != NULL) {
            var_s4 = (s32) temp_v1 & -(*(s32 *)((char *)temp_v1 + 0x50) != 0);
        }
        temp_v1_2 = *(void * *)((char *)temp_s6 + 0x58);
        var_a0 = 0;
        if (temp_v1_2 != NULL) {
            var_a0 = (s32) temp_v1_2 & -(*(s32 *)((char *)temp_v1_2 + 0x50) != 0);
        }
        if ((var_a0 != 0) && (M2C_FIELD(*(void * *)((char *)arg0 + 0x48), s32 *, 0) < 4)) {
            temp_s2 = *(s32 *)((char *)var_a0 + 0x50);
            var_s0 = *(void * *)((char *)var_a0 + 0x68);
            var_s1 = 0;
            if (temp_s2 > 0) {
                do {
                    if (*(s16 *)((char *)var_s0 + 4) == 1) {
                        D_800A0284(var_s0, arg0);
                    }
                    var_s1 += 1;
                    var_s0 += 8;
                } while (var_s1 < temp_s2);
            }
        }
        var_s0 = *(void * *)((char *)temp_s6 + 0x68);
        if (var_s0 != NULL) {
            temp_s2 = *(s32 *)((char *)temp_s6 + 0x50);
            var_s1 = 0;
            if (temp_s2 > 0) {
loop_main:
                {
                    temp_a0 = var_s0;
                    temp_v0 = D_800A0280[*(s16 *)((char *)var_s0 + 4)];
                    temp_v0(temp_a0, arg0);
                    var_s0 += 8;
                    var_s1 += 1;
                }
                if(var_s1<temp_s2) goto loop_main;
            }
        }
        if ((var_s4 != 0) && (M2C_FIELD(*(void * *)((char *)arg0 + 0x48), s32 *, 0) < 4)) {
            temp_s2 = *(s32 *)((char *)var_s4 + 0x50);
            var_s0 = *(void * *)((char *)var_s4 + 0x68);
            var_s1 = 0;
            if (temp_s2 > 0) {
                do {
                    if (*(s16 *)((char *)var_s0 + 4) == 1) {
                        D_800A0284(var_s0, arg0);
                    }
                    var_s1 += 1;
                    var_s0 += 8;
                } while (var_s1 < temp_s2);
            }
        }
        if (((!(D_8009D538 & 0x800) && !(*(s32 *)((char *)arg0 + 0x14) & 0x100)) || (M2C_FIELD(D_800C35A0, u16 *, 0x1E) == 0)) && (func_80044908(arg0), ((M2C_FIELD(*(void * *)((char *)arg0 + 0x48), s32 *, 0) < 4) != 0)) && !(*(s32 *)((char *)arg0 + 0x14) & 0x200)) {
            func_800448A4(arg0);
        } else {
            *(s32 *)((char *)arg0 + 0x14) = (s32) (*(s32 *)((char *)arg0 + 0x14) & ~0x20);
        }
        if ((D_800ADFA8 == 0) && (D_800ADFE1 != 0) && (M2C_FIELD(*(void * *)((char *)arg0 + 0x48), s32 *, 0) < 4) && (*(s16 *)((char *)temp_s6 + 8) == (D_800ADFE8 - 5)) && (**(s32 * *)((char *)arg0 + 0x70) == (D_800ADFE0 - 1))) {
            temp_v0_2 = func_8004D784(M2C_FIELD(*(void * *)(D_800C02AE + 0x326A), s32 *, 0x24));
            if (!(*(u16 *)((char *)temp_v0_2 + 0xA) & 1)) {
                { s32 flags=*(s32 *)((char *)temp_v0_2+0x10);
                D_800ADFA8=1;
                *(s32 *)((char *)temp_v0_2+0x10)=(flags|2)&~1; }
            }
        }
        temp_a0_2 = D_800C35A0;
        temp_v0_3 = *(u16 *)((char *)temp_a0_2 + 0x1E);
        if ((temp_v0_3 != 0) & (temp_v0_3 != 5)) {
            if (*(u16 *)((char *)temp_a0_2 + 0x1C) != 0) {
                func_80042CC4(arg0);
                temp_a0_2=D_800C35A0;
                goto block_40;
            }
        } else {
block_40:
            if ((*(u16 *)((char *)temp_a0_2 + 0x1C) != 0) && (*(u16 *)((char *)temp_a0_2 + 0x1E) == 0)) {
                temp_a1 = *(void * *)((char *)arg0 + 0x48);
                { void *rec=temp_a0_2; s32 idx=M2C_FIELD((temp_a0_2+*(s32 *)((char *)temp_a1+0x2C)),u8 *,0x32); rec+=idx*0x28;
                if (M2C_FIELD(rec,u16 *,0x4E)>=0x10U) {
                    M2C_FIELD(*(void * *)((char *)arg0 + 0x4C), s32 *, 0x14) = (s32) (func_80084C0C(*(u8 *)((char *)temp_a1 + 3), 0x10000) + 0x10);
                }}
            }
        }
    }
}
