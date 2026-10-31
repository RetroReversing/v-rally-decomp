typedef struct {
    u16 pad0;
    u16 field2;
    u8 pad4[2];
    u16 field6;
    u8 pad8[12];
    u16 field14;
    u8 field16;
    u8 field17;
    u8 pad18[4];
    u16 field1c;
    u16 field1e;
    s16 field20;
    s16 field22;
    s16 field24;
    s16 field26;
} Bg;

void guS2DInitBg(Bg *bg) {
    u32 size;
    s32 shift;
    u16 a;
    u16 b;
    s32 prod;

    size = 0x200;
    if (bg->field16 == 2)
        size = 0x100;
    shift = 6 - bg->field17;
    if (bg->field14 == 0x33) {
        b = (u16)((s32)bg->field2 >> shift);
        bg->field1c = b;
        bg->field1e = (u16)((size / b) * 4);
        a = bg->field1c * 2;
        prod = bg->field1e * a;
        bg->field24 = a;
        bg->field22 = (s16)(0x7ff / bg->field1c + 1);
        bg->field26 = (s16)prod;
        bg->field20 = (u16)(((prod & 0xfffe) >> 1) - 1);
    } else {
        a = (u16)(((s32)bg->field6 >> shift) + 3);
        bg->field1e = (u16)((size / a) * 4);
        b = (u16)((s32)bg->field2 >> shift);
        b = b * 2;
        prod = bg->field1e * (b & 0xfffe);
        bg->field1c = a;
        bg->field24 = b;
        bg->field22 = (s16)(bg->field1e - 1);
        bg->field26 = (s16)(prod >> 16);
        bg->field20 = (u16)prod;
    }
}
