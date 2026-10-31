typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
M2C_UNK func_80052E94(s32, s16 *);
s16 *func_80057918(s32, s32);
void *func_800592D0(s32);
M2C_UNK func_80059618(void *, u8, u8, u8, s32);
M2C_UNK func_800596F4(void *, s16, s16, s16 *);
M2C_UNK func_8005A6BC(s32);
M2C_UNK func_8005A6E0(s32);
M2C_UNK func_80097E30(s16 *, s32, s32);
M2C_UNK func_800980D0(s16 *, M2C_UNK *);
M2C_UNK func_80099DF8(s16 *, M2C_UNK *, s32, void *);
extern void *D_800A1468;
extern M2C_UNK D_800A56C4;
extern s16 D_800A56CC;
extern s8 D_800A56CE;
extern M2C_UNK D_800A56D0;
extern void *D_800C35A0;
extern char D_800C3650[];
extern s32 D_800C8328;
extern void *D_800D0634[];

void func_80064F98(void) {
    struct { s16 half; s8 byte; char rest[12]; } buffer;
    M2C_UNK var_a0;
    s32 temp_a2, temp_a2_2, temp_s0, temp_s1, var_s3, var_s6;
    s16 *text;
    void *temp_s2, *temp_s4;

    char *rowBase;

    func_80097E30(&buffer.half, 0, 0xF);
    var_s6 = 0;
    if (M2C_FIELD(D_800A1468, u8 *, 0x245) == 0) {
        temp_s2 = func_800592D0(0x10);
        var_s3 = 0;
        rowBase = D_800C3650;
        do {
            void *mgr;
            u16 mgrIdx;

            mgr = D_800C35A0;
            temp_s0 = var_s3 & 0xFF;
            temp_a2 = temp_s0 + 1;
            var_s3 += 1;
            mgrIdx = *(u16 *)((char *)mgr + 0x20);
            func_80099DF8(&buffer.half, &D_800A56C4, temp_a2, (void *)(rowBase + (temp_s0 << 4) + (mgrIdx << 6) + 6));
            func_800596F4(temp_s2, M2C_FIELD(temp_s2, s16 *, 6), (s16)(M2C_FIELD(temp_s2, u16 *, 8) + temp_s0 * 0x16), &buffer.half);
        } while ((u32)(var_s3 & 0xFF) < 3U);
        temp_s2 = func_800592D0(0x12);
        temp_s4 = func_800592D0(0x11);
        text = &buffer.half;
        var_s3 = 0;
        do {
            temp_s1 = var_s3 & 0xFF;
            temp_s0 = *(s32 *)(D_800C3650 + (temp_s1 * 0x10) + (M2C_FIELD(D_800C35A0, u16 *, 0x20) << 6));
            func_80097E30(&buffer.half, 0, 0xF);
            func_80052E94(temp_s0 & 0xFFFF, &buffer.half);
            func_800596F4(temp_s2, M2C_FIELD(temp_s2, s16 *, 6), (s16)(M2C_FIELD(temp_s2, u16 *, 8) + temp_s1 * 0x16), &buffer.half);
            if (temp_s1 == 0) {
                var_s6 = temp_s0;
            } else {
                func_80097E30(&buffer.half, 0, 0xF);
                buffer.half = D_800A56CC;
                buffer.byte = D_800A56CE;
                func_80052E94((temp_s0 - var_s6) & 0xFFFF, (s16 *)&buffer.byte);
                func_800980D0(text, &D_800A56D0);
                func_800596F4(temp_s4, M2C_FIELD(temp_s4, s16 *, 6), (s16)(M2C_FIELD(temp_s4, u16 *, 8) + (temp_s1 - 1) * 0x16), text);
            }
            var_s3 += 1;
        } while ((u32)(var_s3 & 0xFF) < 3U);
        temp_s2 = func_800592D0(0x13);
        func_80059618(temp_s2, M2C_FIELD(temp_s2, u8 *, 0xB), M2C_FIELD(temp_s2, u8 *, 0xC), M2C_FIELD(temp_s2, u8 *, 0xD), M2C_FIELD(temp_s2, u8 *, 0xE));
        func_800596F4(temp_s2, M2C_FIELD(temp_s2, s16 *, 6), M2C_FIELD(temp_s2, s16 *, 8), func_80057918(D_800C8328, M2C_FIELD(D_800C35A0, u16 *, 0x20) + 0x1CD));
        func_8005A6E0(0x15);
        var_a0 = 0x14;
    } else {
        temp_s2 = func_800592D0(0x10);
        var_s3 = 0;
        do {
            temp_s0 = var_s3 & 0xFF;
            temp_a2_2 = temp_s0 + 1;
            var_s3 += 1;
            func_80099DF8(&buffer.half, &D_800A56C4, temp_a2_2, D_800D0634[M2C_FIELD(D_800A1468, u8 *, 0x23C)] + ((M2C_FIELD(D_800C35A0, u16 *, 0x22) << 6) + 0x2C) + (temp_s0 * 0x10) + 6);
            func_800596F4(temp_s2, M2C_FIELD(temp_s2, s16 *, 6), (s16)(M2C_FIELD(temp_s2, u16 *, 8) + temp_s0 * 0x16), &buffer.half);
        } while ((u32)(var_s3 & 0xFF) < 3U);
        temp_s2 = func_800592D0(0x12);
        temp_s4 = func_800592D0(0x11);
        text = &buffer.half;
        var_s3 = 0;
        do {
            temp_s1 = var_s3 & 0xFF;
            temp_s0 = M2C_FIELD((D_800D0634[M2C_FIELD(D_800A1468, u8 *, 0x23C)] + (temp_s1 * 0x10) + (M2C_FIELD(D_800C35A0, u16 *, 0x22) << 6)), s32 *, 0x2C);
            func_80052E94(temp_s0 & 0xFFFF, &buffer.half);
            func_800596F4(temp_s2, M2C_FIELD(temp_s2, s16 *, 6), (s16)(M2C_FIELD(temp_s2, u16 *, 8) + temp_s1 * 0x16), &buffer.half);
            if (temp_s1 == 0) {
                var_s6 = temp_s0;
            } else {
                func_80097E30(&buffer.half, 0, 0xF);
                buffer.half = D_800A56CC;
                buffer.byte = D_800A56CE;
                func_80052E94((temp_s0 - var_s6) & 0xFFFF, (s16 *)&buffer.byte);
                func_800980D0(text, &D_800A56D0);
                func_800596F4(temp_s4, M2C_FIELD(temp_s4, s16 *, 6), (s16)(M2C_FIELD(temp_s4, u16 *, 8) + (temp_s1 - 1) * 0x16), text);
            }
            var_s3 += 1;
        } while ((u32)(var_s3 & 0xFF) < 3U);
        temp_s2 = func_800592D0(0x13);
        func_80059618(temp_s2, M2C_FIELD(temp_s2, u8 *, 0xB), M2C_FIELD(temp_s2, u8 *, 0xC), M2C_FIELD(temp_s2, u8 *, 0xD), M2C_FIELD(temp_s2, u8 *, 0xE));
        func_800596F4(temp_s2, M2C_FIELD(temp_s2, s16 *, 6), M2C_FIELD(temp_s2, s16 *, 8), func_80057918(D_800C8328, M2C_FIELD(D_800C35A0, u16 *, 0x22) + 0x21A));
        func_8005A6E0(0x14);
        var_a0 = 0x15;
    }
    func_8005A6BC(var_a0);
}
