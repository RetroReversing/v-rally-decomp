#include "common.h"

typedef struct Ent {
    s32 f0;
    s32 f4;
    s16 f8;
    s16 fA;
    s16 fC;
    s16 fE;
    f32 f10;
    s32 f14;
    s32 f18;
    f32 f1C;
    void *f20;
    s32 f24;
} Ent;

typedef struct S0 {
    u8 pad[0x20];
    Ent *arr;
} S0;

extern u8 *D_800A2500;
extern f64 D_800A71F0;
extern f64 D_800A71F8;

void func_80091D80(void *);

s32 func_80094FA4(S0 *arg0, s32 arg1, s32 *arg2) {
    s32 n = arg1 - 2;
    s32 idx = n % 8;
    s32 val;

    arg1 = n / 8;
    val = *arg2;
    switch (idx) {
    case 0:
        arg0->arr[arg1].f0 = val & ~7;
        break;
    case 1:
        arg0->arr[arg1].f4 = val & ~7;
        break;
    case 2:
        arg0->arr[arg1].f8 = val;
        break;
    case 3:
        arg0->arr[arg1].fA = val;
        break;
    case 4:
        arg0->arr[arg1].fC = val;
        break;
    case 5:
        arg0->arr[arg1].f10 = (f32)((f64)((f32)val / 1000.0f) * 2.0 / (f64)*(s32 *)(D_800A2500 + 0x44));
        break;
    case 6: {
        f64 t = (f64)(f32)val / D_800A71F0;
        s32 diff = arg0->arr[arg1].f4 - arg0->arr[arg1].f0;
        f64 d = (f64)diff;
        if (diff < 0) {
            d += D_800A71F8;
        }
        arg0->arr[arg1].f1C = (f32)(t * d);
        break;
    }
    case 7:
        if (arg0->arr[arg1].f20 != NULL) {
            *(s16 *)arg0->arr[arg1].f20 = val;
            func_80091D80(arg0->arr[arg1].f20);
        }
        break;
    }
    return 0;
}
