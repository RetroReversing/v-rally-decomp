extern char D_800A73E0[];
extern char D_800AE850[];
extern void *D_800C8054;
s32 func_80009E10(s32);
void func_80009E7C(void);
void func_80009ED8(void)
{
    s32 *p = (s32 *) (D_800A73E0 + 0x6BA8);
    s32 v;
    unsigned short new_var;
    s32 a;
    s32 b;
    *p = func_80009E10(0x15E);
    v = func_80009E10(0x15E);
    a = p[0];
    b = *(&D_800C8054);
    p[1] = v;
    p[4] = 0;
    new_var = 5;
    p[3] = v;
    p[5] = 0x15E;
    D_800C8054 = func_80009E7C;
    p[new_var] = 0x15E;
    p[2] = a;
do { } while (0);
    *((s32 *) (D_800AE850 + 0x11F4)) = b;
}
