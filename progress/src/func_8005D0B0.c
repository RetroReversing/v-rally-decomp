typedef struct {
    u8 pad0[6];
    s16 x;
    s16 y;
    u8 padA;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
} Win;
typedef struct {
    u8 pad0[0x37];
    u8 id;
    u8 pad38[8];
} Sub;
typedef struct {
    Sub sub[8];
    u8 pad200[0x2C];
    u32 vals[38];
} Rec;
typedef struct {
    u8 pad0[0x1E];
    u16 a;
    u16 b;
    u16 c;
    u8 pad24[0xC];
    u8 n;
    u8 pad31[0x1F];
    u16 mode;
} Cfg;
extern s32 D_800B5C60;
extern s32 D_800D05D8;
extern f32 D_800C6CF8;
extern s32 D_800C8328;
extern Cfg *D_800C35A0;
extern Rec *D_800D0634[];
extern u8 D_800A14D5;
extern u8 D_800A1548;
extern char D_800A5418[];
extern char D_800A541C[];
extern char D_800A5428[];
extern char D_800A5434[];
extern f64 D_800A5440;
s32 func_8004240C();
s32 func_80047B54();
void func_8004CF7C(s32 arg0, u16 arg1, s16 arg2, s16 arg3, f32 arg4, u8 arg5, u16 arg6);
char *func_80057918();void *func_800592D0(u32);
void func_80059618(Win *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
s32 func_800596F4();void func_8005A6BC(u32);void func_8005A6E0(u32);
s32 memset();
s32 func_80099DF8();

void func_8005D0B0(void)
{
    char buf1[16];
    char buf3[8];
    char buf2[16];
    Win *w;
    u32 val;

    memset(buf1, 0, 16);
    D_800B5C60 = 0;
    if (D_800A1548 != 0) {
        func_80047B54(func_8004240C(0), 0, 0, 0);
        D_800A1548--;
    }
    func_8004CF7C(D_800D05D8, 0, 0x68, 0x4A, D_800C6CF8, 0, 0xFF);
    w = func_800592D0(0);
    func_80059618(w, w->b, w->c, w->d, 0xFF);
    func_80099DF8(buf1, D_800A5418, func_80057918(D_800C8328, D_800D0634[D_800C35A0->a][D_800C35A0->b].sub[D_800C35A0->c].id + 0x1E4));
    func_800596F4(w, w->x, w->y, buf1);
    memset(buf2, 0, 10);
    w = func_800592D0(2);
    val = D_800D0634[D_800C35A0->a][D_800C35A0->b].vals[D_800C35A0->c];
    if (D_800C35A0->mode == 0) {
        func_80099DF8(buf2, D_800A541C, (u16)(val / 1000), (u16)(val % 1000 / 100));
    } else {
        val = val * D_800A5440;
        func_80099DF8(buf2, D_800A5428, (u16)(val / 1000), (u16)(val % 1000 / 100));
    }
    func_80059618(w, w->b, w->c, w->d, w->e);
    func_800596F4(w, w->x, w->y, buf2);
    if (D_800A14D5 != 0) {
        func_8005A6BC(0xD);
        w = func_800592D0(0xE);
        memset(buf3, 0, 2);
        func_80059618(w, w->b, w->c, w->d, w->e);
        if (D_800C35A0->a == 0) {
            if (D_800C35A0->n == 0) {
                func_800596F4(w, w->x, w->y, func_80057918(D_800C8328, 0x174));
            } else {
                func_80099DF8(buf3, D_800A5434, D_800C35A0->n);
                func_800596F4(w, w->x, w->y, buf3);
            }
        } else {
            func_80099DF8(buf3, D_800A5434, 3);
            func_800596F4(w, w->x, w->y, buf3);
        }
    } else {
        func_8005A6E0(0xD);
    }
}
