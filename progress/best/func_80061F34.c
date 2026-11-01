extern void func_8004C7F0(void *);
extern void func_8004D31C(void);
extern s32 func_800602F4(void *, u16);
extern void func_80081540(void *);
extern void func_800980D0(void *, void *);
extern void *func_80097E30(void *, int, u32);
extern u8 D_800A5408[];
extern u8 D_800A564C[];
extern u8 D_800A5654[];
extern u8 D_800A565C[];
extern u8 *D_800A14E4[];
extern u8 D_800AE850[];
extern u8 * volatile D_800C35A0;
extern u8 *D_800D0634[];

void func_80061F34(void) {
    u8 temp[12];
    u8 *p;
    u16 x, y, z;
    u32 index;
    func_80081540(D_800A5408);
    func_8004D31C();
    func_8004C7F0(D_800AE850 + 0x130C + D_800C35A0[0x2E] * 28);
    p = D_800C35A0;
    x = *(u16 *)(p + 0x1E);
    y = *(u16 *)(p + 0x20);
    z = *(u16 *)(p + 0x22);
    index = func_800602F4(D_800D0634[x] + y * 0x2C4 + (z * 14 + 0x24C), z);
    func_80097E30(temp, 0, 12);
    func_800980D0(temp, D_800A564C);
    func_800980D0(temp, D_800A14E4[index & 0xFF]);
    func_800980D0(temp, D_800A5654);
    func_8004C7F0(temp);
    func_8004C7F0(D_800A565C);
}
