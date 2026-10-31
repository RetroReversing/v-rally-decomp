#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s16 func_80089C48(void *, s32, s32, u8, s16 *, u8 *, void *, s32);
extern u8 D_800A1C70;

void func_8008A31C(void *arg0) {
    s16 sp20;
    u8 sp22;
    void (*temp_v0_2)(void);
    void (*temp_v1)(s32);
    void (*temp_v1_3)(s32, s32, s32);
    s16 temp_v0_4;
    s16 temp_v0_5;
    s32 temp_a1;
    s32 var_a2;
    u8 var_s0;
    s32 var_s3;
    s32 var_s4;
    u16 temp_v1_2;
    u8 temp_a3;
    void *temp_s1;
    void *temp_v0;
    void *temp_v0_3;

    temp_s1 = (void *)((s8 *)M2C_FIELD(arg0, s32 *, 0x10) + (M2C_FIELD(arg0, s16 *, 2) * 0x14));
    var_s3 = M2C_FIELD(arg0, s32 (**)(void), 8)();
    temp_v1 = M2C_FIELD(arg0, void (**)(s32), 0xC);
    var_s4 = 0;
    if (temp_v1 != NULL) {
        temp_v1(var_s3);
    }
    temp_v1_2 = M2C_FIELD(arg0, u16 *, 4);
    if (temp_v1_2 == M2C_FIELD(temp_s1, s32 *, 0x10)) {
        if (temp_v1_2 != 0) {
            var_s3 = 0x10000;
            M2C_FIELD(arg0, u16 *, 4) = 0U;
        }
    } else if (var_s3 != 0) {
        var_s4 = 1;
    }
    temp_v1_2 = D_800A1C70;
    if (temp_v1_2 == 0) {
        var_s0 = 0;
        if ((u8) temp_v1_2 < (u8) M2C_FIELD(temp_s1, u8 *, 0xC)) {
            do {
                s32 loop_base;
                var_a2 = var_s0;
                loop_base = M2C_FIELD(temp_s1, s32 *, 8);
                temp_v0 = (void *)((s32)var_a2 * 0xC);
                temp_v0 = (void *)(loop_base + (s32)temp_v0);
                temp_v1_3 = M2C_FIELD(temp_v0, void (**)(s32, s32, s32), 0);
                if ((temp_v1_3 != NULL) && (M2C_FIELD(temp_v0, u8 *, 0xA) != 0)) {
                    temp_a1 = var_a2 + M2C_FIELD(temp_s1, u8 *, 0xD);
                    temp_v1_3(temp_a1 == M2C_FIELD(temp_s1, u8 *, 0xE), temp_a1, (s32)var_a2);
                }
                var_s0 += 1;
            } while (var_s0 < (u8) M2C_FIELD(temp_s1, u8 *, 0xC));
        }
        temp_v0_2 = M2C_FIELD(temp_s1, void (**)(void), 0);
        if (temp_v0_2 != NULL) {
            temp_v0_2();
        }
    }
    sp22 = 0;
    temp_v0_4 = -1;
    sp20 = temp_v0_4;
    if (M2C_FIELD(temp_s1, u8 *, 0xC) != 0) {
        u8 byte_d;
        u8 byte_e;
        s32 entry_base;
        s32 entry_off;
        void *entry_ptr;
        temp_a1 = var_s3;
        byte_e = M2C_FIELD(temp_s1, u8 *, 0xE);
        byte_d = M2C_FIELD(temp_s1, u8 *, 0xD);
        entry_base = M2C_FIELD(temp_s1, s32 *, 8);
        entry_off = (s32) byte_e - (s32) byte_d;
        entry_off = (entry_off << 1) + entry_off;
        entry_off = entry_off << 2;
        entry_ptr = (void *) (entry_off + entry_base);
        temp_v0_4 = func_80089C48(temp_s1, M2C_FIELD(entry_ptr, s32 *, 4), temp_a1, M2C_FIELD(entry_ptr, u8 *, 8), &sp20, &sp22, arg0, (s32) M2C_FIELD(temp_s1, u8 *, 0xE));
        if (temp_v0_4 != -1) {
            M2C_FIELD(temp_s1, u8 *, 0xE) = (u8) temp_v0_4;
        }
        if (sp20 != -1) {
            M2C_FIELD(arg0, s16 *, 2) = sp20;
        }
    }
    if (sp22 == 0) {
        temp_a3 = M2C_FIELD(temp_s1, u8 *, 0xF);
        if (temp_a3 != 0) {
            temp_v0_5 = func_80089C48(temp_s1, M2C_FIELD(temp_s1, s32 *, 4), var_s3, temp_a3, &sp20, &sp22, arg0, 0);
            if (temp_v0_5 != -1) {
                M2C_FIELD(temp_s1, u8 *, 0xE) = (u8) temp_v0_5;
            } else if (sp20 != temp_v0_5) {
                s32 menu_base;
                s32 menu_offs;
                void *menu_entry;
                temp_v0_4 = sp20;
                M2C_FIELD(arg0, s16 *, 2) = temp_v0_4;
                menu_base = M2C_FIELD(arg0, s32 *, 0x10);
                menu_offs = sp20;
                menu_offs = menu_offs * 5;
                menu_offs = menu_offs << 2;
                menu_entry = (void *) (menu_offs + menu_base);
                M2C_FIELD(menu_entry, u8 *, 0xE) = (u8) M2C_FIELD(menu_entry, u8 *, 0xD);
            }
        }
    }
    if ((var_s4 & 0xFF) && (sp22 != 0)) {
        M2C_FIELD(arg0, u16 *, 4) = 0U;
    }
    M2C_FIELD(arg0, u16 *, 4) = (u16) (M2C_FIELD(arg0, u16 *, 4) + 1);
}
