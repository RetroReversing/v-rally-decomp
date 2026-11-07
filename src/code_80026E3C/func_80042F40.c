#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
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



extern const int D_800B6880;
extern void **D_800B5C40;


s32 func_8000E8B8();
void *func_80022318(void **, u8 *);
s32 func_8002FE78();
void *func_8004240C();
s32 func_80042DE0();
s32 func_800528A4();
s32 func_80073708();
s32 func_800746C0();
s32 func_80076E7C();
extern s32 D_8009D538;
extern char D_800A4DF4[];
extern char D_800AE850[];
extern char D_800C02AE[];
extern void *D_800C35A0; extern void *D_800C7F84;

void func_80042F40(void) {
    s32 temp_v1;
    s32 mode;
    s32 temp_a0;
    void *config;
    void *node;
    void *temp_a1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *var_v1;

    func_8002FE78();
    temp_a0 = M2C_FIELD(D_800C35A0, u16 *, 0xE);
    D_8009D538 |= 1;
    temp_v0 = func_8004240C((temp_a0 * 2) | 1);
    D_800C7F84 = temp_v0;
    node = M2C_FIELD(func_80022318((void **)(temp_v0 + 0x28), (u8 *)(&D_800A4DF4)), void **, 0x10);
    config = D_800C35A0;
    M2C_FIELD(node, s32 *, 8) = 1;
    temp_v0_2 = func_8004240C((M2C_FIELD(config, u16 *, 0xE) * 2) + 2);
    temp_a0 = *(s32 *)((char *)temp_v0_2 + 0x178);
    D_800C7F84 = temp_v0_2;
    func_8000E8B8(temp_a0);
    temp_v1 = M2C_FIELD(D_800C35A0, u16 *, 0x1E);
    switch (temp_v1) {
    case 0: func_800746C0(); break;
    case 1: case 2: case 3: case 4: func_80042DE0(); goto mode_join;
    case 5: func_80042DE0(); func_800528A4();
mode_join: func_80073708(); break;
    }
    temp_v0_3 = func_8004240C((M2C_FIELD(D_800C35A0, u16 *, 0xE) * 2) + 2);
    D_800C7F84 = temp_v0_3;
    func_80076E7C(temp_v0_3);
    var_v1 = *D_800B5C40;
    D_8009D538 |= 0xA00;
    if (var_v1 != NULL) {
        mode = D_800B6880;
        do {
            temp_a1 = *(void * *)((char *)var_v1 + 0x48);
            temp_a0 = *(s32 *)((char *)temp_a1 + 0x20);
            switch (temp_a0) {                      /* switch 2; irregular */
            case 6:                                 /* switch 2 */
                *(s32 *)((char *)temp_a1 + 0x20) = 4;
                break;
            case 10:                                /* switch 2 */
                *(s32 *)((char *)temp_a1 + 0x20) = 8;
                break;
            case 7:                                 /* switch 2 */
                *(s32 *)((char *)temp_a1 + 0x20) = 8;
                break;
            default:                                /* switch 2 */
                M2C_FIELD(*(void * *)((char *)var_v1 + 0x48), s32 *, 0x20) = 8;
                break;
            }
            if (D_800B6880 == 2) {
                M2C_FIELD(*(void * *)((char *)var_v1 + 0x48), s32 *, 0x20) = 4;
            }
            var_v1 = *(void * *)((char *)var_v1 + 4);
        } while (var_v1 != NULL);
    }
}

