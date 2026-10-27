#include "checkpoint_common.h"

void func_80097F00(u32 size, u8 *a, u8 *b);
void func_80097F30(u8 *base, u32 n, u32 size, s32 (*cmp)(u8 *, u8 *))
{
    u32 gap;
    u32 half;
    u32 step;
    u8 *end;
    u8 *q;
    u8 *p;

    if (n < 2) {
        return;
    }
    if (n == 2) {
        p = base + size;
        if (cmp(base, p) > 0) {
            func_80097F00(size, base, p);
        }
        return;
    }
    gap = 1;
    while (gap < n) {
        gap = (gap * 2) + 1;
    }
    gap >>= 1;
    end = base + (n * size);
    while (gap != 0) {
        step = gap * size;
        q = base + step;
        if (q < end) {
            do {
                p = q - step;
                while (p >= base && p < end) {
                    if (cmp(p, p + step) <= 0) {
                        break;
                    }
                    func_80097F00(size, p, p + step);
                    p -= step;
                }
                q += size;
            } while (q < end);
        }
        half = gap >> 1;
        if (half == 0) {
            break;
        }
        gap = half;
    }
}
