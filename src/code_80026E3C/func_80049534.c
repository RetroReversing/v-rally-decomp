#include "common.h"

typedef struct {
    u8 b[13];
} Buf13;

typedef struct {
    u8 b[14];
} Buf14;

typedef struct {
    Buf13 a;
    u8 c[3];
    Buf14 d;
    u8 e[2];
} Frame;

extern Buf13 D_800A4E60;
extern Buf14 D_800A4E70;
extern char D_800A4E80[];
void func_80097E30(void *, s32, s32);
void func_8004C7F0(void *);
void func_80081540(void *);

void func_80049534(void) {
    Frame f;
    s32 i;

    f.a = D_800A4E60;
    func_80097E30(f.c, 0, 3);
    f.d = D_800A4E70;
    func_80097E30(f.e, 0, 2);
    func_80081540(D_800A4E80);
    i = 1;
    do {
        f.a.b[7] = i + 0x30;
        func_8004C7F0(&f.a);
        i++;
    } while ((u8)i < 9);
    i = 1;
    do {
        f.d.b[8] = i + 0x30;
        func_8004C7F0(&f.d);
        i++;
    } while ((u8)i < 9);
}
