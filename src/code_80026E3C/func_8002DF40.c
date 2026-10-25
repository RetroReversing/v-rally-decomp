#include "common.h"

void func_8001C1A8(f32 *);
extern f64 D_800A4A40;

void func_8002DF40(s16 *arg0) {
    f32 sp10[4];

    sp10[0] = (f32) ((f64) (arg0[0] * 0x168) * D_800A4A40);
    sp10[1] = (f32) ((f64) (arg0[1] * 0x168) * D_800A4A40);
    sp10[2] = (f32) ((f64) (arg0[2] * 0x168) * D_800A4A40);
    func_8001C1A8(sp10);
}
