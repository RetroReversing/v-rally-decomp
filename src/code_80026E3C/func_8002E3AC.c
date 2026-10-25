#include "common.h"

void *func_8002E3AC(void *arg0, void *arg1, void *arg2)
{
    s16 *m;
    s16 *v;
    s16 out[3];
    s32 sum;
    s32 t;

    m = arg0;
    v = arg1;

    sum = m[0] * v[0] + m[1] * v[1] + m[2] * v[2];
    t = sum;
    if (sum < 0) {
        t = sum + 0xFFF;
    }
    sum = t >> 12;
    if (sum < -0x8000) {
        sum = -0x8000;
    }
    if (sum > 0x7FFF) {
        sum = 0x7FFF;
    }
    out[0] = sum;

    sum = m[3] * v[0] + m[4] * v[1] + m[5] * v[2];
    t = sum;
    if (sum < 0) {
        t = sum + 0xFFF;
    }
    sum = t >> 12;
    if (sum < -0x8000) {
        sum = -0x8000;
    }
    if (sum > 0x7FFF) {
        sum = 0x7FFF;
    }
    out[1] = sum;

    sum = m[6] * v[0] + m[7] * v[1] + m[8] * v[2];
    t = sum;
    if (sum < 0) {
        t = sum + 0xFFF;
    }
    sum = t >> 12;
    if (sum < -0x8000) {
        sum = -0x8000;
    }
    if (sum > 0x7FFF) {
        sum = 0x7FFF;
    }
    out[2] = sum;

    ((s16 *) arg2)[0] = out[0];
    ((s16 *) arg2)[1] = out[1];
    ((s16 *) arg2)[2] = out[2];
    return arg2;
}
