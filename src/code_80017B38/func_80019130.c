#include "common.h"

s32 func_80005CB8();
s32 func_800154A8();
s32 func_800190D4();
s32 func_8007EF5C();
s32 func_8007F050();
s32 func_80081540();
s32 func_80081664();
s32 func_80081B44();
extern s32 D_8009B960;
extern s32 D_8009B964;
extern s32 D_8009B9D8;
extern u8 D_8009BBBC;
extern s32 D_8009D4E8;
extern s32 D_8009D4EC;
extern char D_800A4190[];
extern char D_800AE850[];
extern char D_800C02AE[];

void *func_80019130(u8 *arg0)
{
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    u8 *var_s1;
    s32 var_s0;
    u8 *var_s2;
    u8 *var_s3;
    s32 v;


    var_s3 = arg0;
    func_80081540(D_800A4190);
    D_8009D4EC = func_80081664(D_8009B9D8, D_800AE850 + 0x23D8);
    D_8009D4E8 = func_80081664(D_8009B9D8, D_800C02AE + 0x5B82);
    func_80081B44();
    D_8009B960 = func_8007F050(1);
    D_8009B964 = func_8007EF5C(2);
    if (D_8009BBBC == 0) {
        v = *(u8 *)(D_800C02AE + 0x7678);
        switch (v) {
        case 0: *(s32 *)(D_800AE850 + 0x72F4) = func_80005CB8(1, 0xF618, 0xD6D8, 1, 6); break;
        case 1: *(s32 *)(D_800AE850 + 0x72F4) = func_80005CB8(1, 0xFA00, 0xD6D8, 1, 6); break;
        case 2: *(s32 *)(D_800AE850 + 0x72F4) = func_80005CB8(1, 0xFA00, 0xD6D8, 1, 6); break;
        case 3: *(s32 *)(D_800AE850 + 0x72F4) = func_80005CB8(1, 0xFA00, 0xC350, 1, 6); break;
        default: goto skip;
        }

    }
skip:
    func_800154A8(var_s3, 1, D_8009D4EC);
    var_s1 = *(u8 **)var_s3;
    func_800154A8(var_s1, *(u16 *)(var_s3 + 4), D_8009D4EC);
    var_s2 = var_s3;
    for (var_s0 = 0; var_s0 < (s32)*(u16 *)(var_s2 + 4); var_s0++) {
        func_800190D4(var_s1);
        var_s1 += 8;
    }
    return var_s3;
}
