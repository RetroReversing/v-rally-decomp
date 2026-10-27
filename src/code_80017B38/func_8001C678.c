#include "common.h"

extern unsigned char D_800C7926;
extern char D_800A4748[];
extern char D_800A4754[];
extern char D_800A4760[];

s32 func_8001B854();
s32 func_80081540();
s32 *func_80081664();
s32 func_80099DF8();

void func_8001C678(s32 *arg0) {
    s32 buf[4];
    s32 v;
    s32 *s0;
    s32 *s1;

    v = D_800C7926;
    s1 = arg0;
    if (v == 0) {
        func_80099DF8(buf, D_800A4748, (s32)s1 + 0x4C);
    } else {
        if (v < 0) {
            func_80099DF8(buf, D_800A4760, (s32)s1 + 0x4C);
        } else if (v < 3) {
            func_80099DF8(buf, D_800A4754, (s32)s1 + 0x4C);
        } else {
            func_80099DF8(buf, D_800A4760, (s32)s1 + 0x4C);
        }
    }
    s0 = func_80081664(6, buf);
    s1 = (s32 *)((u8 *)s1 + 0x98);
    func_80081540(s1);
    func_8001B854(s0, s1);
}
