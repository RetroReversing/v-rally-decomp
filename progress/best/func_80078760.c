/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -g3, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 draw_panel_quad();
s32 font_draw_string();
s32 font_draw_text();
s32 font_set_color();
s32 font_text_width();
s32 format_to_buffer();
s32 func_8004CEB4();
s32 func_80052E94();
s32 func_80073108();
s32 gfx_append_quad();
void *gfx_get_dl();
s32 gfx_round_vtx_pos();
s32 gfx_set_dl();
s32 gfx_set_quad_colors_shared_alpha();
s32 gfx_set_quad_pos();
s32 *pool_get_item();
extern char D_800A1798[];
extern u8 D_800A17E9;
extern u8 D_800A17EA;
extern char D_800A1824[];
extern char D_800A5EB8[];
extern char D_800A5ED8[];
extern char D_800A5EE0[];
extern char D_800A5EEC[];
extern char D_800A5EF4[];
extern char D_800A5EFC[];
extern char D_800A5F04[];
extern char D_800A5F0C[];
extern char D_800A5F14[];
extern char D_800A5F18[];
extern char D_800A5F2C[];
extern char D_800A5F38[];
extern s32 gStreamState;

void func_80078760(s32 arg0) {
    s32 sp40;
    s32 spB8;
    s32 spD0;
    s32 spE8;
    s16 sp100;
    s16 sp102;
    s16 sp104;
    u16 sp106;
    s16 sp10E;
    s32 sp114;
    s32 *sp134;
    s32 *temp_s0_3;
    s32 *temp_s0_7;
    s32 *var_a1_2;
    s32 *var_v0_2;
    s32 *var_v0_3;
    s32 *var_v0_4;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s16 temp_s0_5;
    s16 temp_s0_6;
    s16 temp_s1;
    s16 temp_s2_2;
    s16 temp_s2_3;
    s16 temp_s3_2;
    s16 temp_s4;
    s16 var_a2_2;
    s16 var_a3_2;
    s16 var_fp;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s1_2;
    s32 temp_s1_3;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s3_3;
    s32 temp_s3_4;
    s32 temp_s3_5;
    s32 temp_s3_6;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_s1;
    s32 var_s7;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    u16 var_s4;
    u32 temp_s0_4;
    u32 temp_v0_2;
    void *temp_s0_8;
    void *temp_s1_4;
    void *temp_v0;

    temp_v0 = gfx_get_dl();
    M2C_FIELD(temp_v0, s32 *, 0) = 0xDE000000;
    M2C_FIELD(temp_v0, s32 **, 4) = D_800A1798;
    gfx_set_dl(arg0, temp_v0 + 8);
    temp_s0 = gfx_append_quad(arg0, 0) & 0xFFFF;
    gfx_set_quad_pos(arg0, temp_s0, 0, 0, 0, 0x140, 0, 0, 0x140, 0xF0, 0, 0, 0xF0, 0);
    gfx_set_quad_colors_shared_alpha(arg0, temp_s0, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0xAA);
    gfx_round_vtx_pos(arg0);
    sp100 = -4;
    sp102 = -4;
    sp104 = M2C_FIELD(*M2C_FIELD(M2C_FIELD(&gStreamState, void **, 0x7F4A), void ***, 4), u16 *, 6) - 4;
    sp106 = M2C_FIELD(*M2C_FIELD(M2C_FIELD(&gStreamState, void **, 0x7F4A), void ***, 4), u16 *, 8);
    sp134 = &sp40;
    var_fp = 0x5A;
    func_8004CEB4(M2C_FIELD(M2C_FIELD(&gStreamState, void **, 0x7CD6), s32 *, 0x178), *M2C_FIELD(M2C_FIELD(&gStreamState, void **, 0x7F4A), void ***, 4), &sp100, 0, 0xAA, 0xAA, 0xAA, 0xAA, 0);
    font_set_color(M2C_FIELD(&gStreamState, s32 *, 0x7F5E), 0xFF, 0xFF, 0xFF, 0xFF);
    format_to_buffer(&sp40, D_800A5EB8);
    temp_s0_2 = D_800A17EA + D_800A17E9 + font_text_width(&gStreamState + 0x7F5E, &sp40, 1, 0x3F800000, 1);
    temp_v0_2 = (u32) (temp_s0_2 & 0xFFFF) >> 1;
    temp_s2 = temp_v0_2 + 0xA0;
    temp_s1 = 0xA0 - temp_v0_2;
    font_set_color(M2C_FIELD(&gStreamState, s32 *, 0x7F5E), 0xDC, 0xDC, 0x80, 0xFF);
    draw_panel_quad(arg0, (temp_s1 - 7) & 0xFFFF, 0x46, (temp_s0_2 + 0xD) & 0xFFFF, 0x11);
    var_s7 = 0;
    sp10E = temp_s1;
    font_draw_text(M2C_FIELD(&gStreamState, s32 *, 0x7F5E), arg0, temp_s1, 0x48, pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), 0xCF), 1);
    font_set_color(M2C_FIELD(&gStreamState, s32 *, 0x7F5E), 0xFF, 0xFF, 0xFF, 0xFF);
    sp114 = temp_s2 * -0x10000;
    do {
        var_s4 = (u16) sp10E;
        temp_v1 = var_s7 & 0xFFFF;
        if (temp_v1 == 4) {
            var_s4 = 0x25;
            temp_s2_2 = var_fp + 0x19;
            var_fp = temp_s2_2 + 0x12;
            temp_s0_3 = pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), *(D_800A1824 + (M2C_FIELD(&gStreamState, u16 *, 0x7F88) * 4)));
            format_to_buffer(&sp40, D_800A5ED8, temp_s0_3, pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), 0xD2));
            temp_s1_2 = font_text_width((&gStreamState + 0x7F88) - 0x2A, &sp40, 1, 0x3F800000, 1);
            temp_s3 = temp_s1_2;
            font_set_color(M2C_FIELD(&gStreamState, s32 *, 0x7F5E), 0xDC, 0xDC, 0x80, 0xFF);
            temp_s0_4 = (u32) (temp_s3 & 0xFFFF) >> 1;
            draw_panel_quad(arg0, (0x97 - temp_s0_4) & 0xFFFF, (temp_s2_2 - 2) & 0xFFFF, (temp_s1_2 + 0xF) & 0xFFFF, 0x11);
            font_draw_text(M2C_FIELD(&gStreamState, s32 *, 0x7F5E), arg0, 0xA0 - temp_s0_4, temp_s2_2, sp134, 1);
            var_a1 = 0xFF;
            var_a2 = 0xFF;
            var_a3 = 0xFF;
            goto block_5;
        }
        var_v1 = var_s7 & 0xFFFF;
        if (*(&gStreamState + 0x7CE6 + (temp_v1 * 0x18)) == M2C_FIELD(&gStreamState, s32 *, 0x7D46)) {
            var_a1 = 0xDC;
            var_a2 = 0xDC;
            var_a3 = 0x10;
block_5:
            font_set_color(M2C_FIELD(&gStreamState, s32 *, 0x7F5E), var_a1, var_a2, var_a3, 0xFF);
            var_v1 = var_s7 & 0xFFFF;
        }
        temp_a0 = *(&gStreamState + 0x7CE6 + (var_v1 * 0x18));
        if (temp_a0 != 0) {
            func_80052E94(temp_a0, &spB8);
            var_v1_2 = var_s7 & 0xFFFF;
        } else {
            format_to_buffer(&spB8, D_800A5EE0);
            var_v1_2 = var_s7 & 0xFFFF;
        }
        temp_a0_2 = *(&gStreamState + 0x7CEA + (var_v1_2 * 0x18));
        if (temp_a0_2 != 0) {
            func_80052E94(temp_a0_2, &spD0);
            var_v1_3 = var_s7 & 0xFFFF;
        } else {
            format_to_buffer(&spD0, D_800A5EE0);
            var_v1_3 = var_s7 & 0xFFFF;
        }
        temp_v1_2 = *(&gStreamState + 0x7CEE + (var_v1_3 * 0x18));
        if (temp_v1_2 != 0) {
            if (M2C_FIELD(&gStreamState, u16 *, 0x7FB6) != 0) {
                format_to_buffer(&spE8, D_800A5EEC, (s32 *) ((u32) (temp_v1_2 * 0x9F00) >> 0x10));
                var_v0 = var_s7 & 0xFFFF;
            } else {
                format_to_buffer(&spE8, D_800A5EF4, (s32 *) (temp_v1_2 & 0xFFFF));
                var_v0 = var_s7 & 0xFFFF;
            }
        } else {
            if (M2C_FIELD(&gStreamState, u16 *, 0x7FB6) != 0) {
                var_a1_2 = D_800A5EFC;
            } else {
                var_a1_2 = D_800A5F04;
            }
            format_to_buffer(&spE8, var_a1_2);
            var_v0 = var_s7 & 0xFFFF;
        }
        if (var_v0 != 4) {
            format_to_buffer(&sp40, D_800A5F0C, var_v0 + 1, (var_v0 * 0x18) + (&gStreamState + 0x7CE2));
            var_s1 = var_s7 & 0xFFFF;
        } else {
            format_to_buffer(&sp40, D_800A5F14, &gStreamState + 0x7D42);
            var_s1 = var_s7 & 0xFFFF;
        }
        if (var_s1 != 4) {
            font_draw_text(M2C_FIELD(&gStreamState, s32 *, 0x7F5E), arg0, (s16) var_s4, var_fp, sp134, 1);
        }
        temp_s0_5 = var_s4 + D_800A17E9;
        temp_s4 = var_fp - 1;
        if (((u32) (temp_s0_5 & 0xFFFF) < 0x141U) & (var_s1 != 4)) {
            func_80073108(arg0, temp_s0_5, temp_s4, M2C_FIELD(&gStreamState, s32 *, 0x103B2), (s32) *(&gStreamState + 0x7CF4 + (var_s1 * 0x18)));
        }
        temp_s2_3 = temp_s4 + 1;
        temp_s0_6 = temp_s0_5 + D_800A17EA;
        if (var_s1 != 0) {
            if (var_s1 == 4) {
                temp_s1_3 = (s32) (0x140 - ((D_800A17EA + (D_800A17E9 + 0xFFF1) + font_text_width(&gStreamState + 0x7F5E, D_800A5F18, 1, 0x3F800000, 1)) & 0xFFFF)) / 2;
                temp_s3_2 = temp_s1_3 & 0xFFFF;
                font_draw_text(M2C_FIELD(&gStreamState, s32 *, 0x7F5E), arg0, temp_s3_2, temp_s2_3, sp134, 1);
                if ((u32) (temp_s0_6 & 0xFFFF) < 0x141U) {
                    func_80073108(arg0, (s16) (temp_s1_3 + (D_800A17E9 + 0xFFF1)), temp_s4, M2C_FIELD(&gStreamState, s32 *, 0x103B2), (s32) M2C_FIELD(&gStreamState, u8 *, 0x7D54));
                }
                format_to_buffer(sp134, D_800A5ED8, &spB8, &spE8);
                font_draw_text(M2C_FIELD(&gStreamState, s32 *, 0x7F5E), arg0, temp_s3_2 - 0xF + D_800A17E9 + D_800A17EA, temp_s2_3, sp134, 1);
                var_fp = temp_s2_3 + 0xF;
            } else {
                format_to_buffer(&sp40, D_800A5F2C, &spB8, &spD0);
                goto block_34;
            }
        } else {
block_34:
            font_draw_text(M2C_FIELD(&gStreamState, s32 *, 0x7F5E), arg0, temp_s0_6, temp_s2_3, (s32 *)1);
            font_draw_string(&gStreamState + 0x7F5E, arg0, sp114 >> 0x10, temp_s2_3, &spE8, 1, 1.0f, 1.0f, 0, 1);
            var_fp = temp_s2_3 + 0xF;
        }
        var_s7 += 1;
        font_set_color(M2C_FIELD(&gStreamState, s32 *, 0x7F5E), 0xFF, 0xFF, 0xFF, 0xFF);
    } while ((u32) (var_s7 & 0xFFFF) < 5U);
    temp_s1_4 = &gStreamState + 0x7F62;
    font_set_color(M2C_FIELD(&gStreamState, s32 *, 0x7F62), 0xDC, 0xDC, 0x10, 0xFF);
    if ((u8) M2C_FIELD(&gStreamState, u8 *, 0x7CF2) < 4U) {
        format_to_buffer(&sp40, D_800A5ED8, pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), 0xD8), (&gStreamState + 0x7CF2) - 0x10);
        font_draw_text(M2C_FIELD(&gStreamState, s32 *, 0x7F62), arg0, 0xA0 - ((u32) (font_text_width(temp_s1_4, &sp40, 1, 0x3F800000, 0) & 0xFFFF) >> 1), 0x14, &sp40, 0);
        temp_s3_3 = font_text_width(temp_s1_4, pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), 0xE3), 1, 0x3F800000, 0);
        font_draw_text(M2C_FIELD(&gStreamState, s32 *, 0x7F62), arg0, 0xA0 - ((u32) (temp_s3_3 & 0xFFFF) >> 1), 0x23, pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), 0xE3), 0);
        temp_s3_4 = font_text_width(temp_s1_4, pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), *(D_800A1824 + (M2C_FIELD(&gStreamState, u16 *, 0x7F88) * 4))), 1, 0x3F800000, 0);
        var_v0_2 = pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), *(D_800A1824 + (M2C_FIELD(&gStreamState, u16 *, 0x7F88) * 4)));
        var_a2_2 = 0xA0 - ((u32) (temp_s3_4 & 0xFFFF) >> 1);
        var_a3_2 = 0x32;
    } else if (M2C_FIELD(&gStreamState, s32 *, 0x32AA) == 3) {
        temp_s3_5 = font_text_width(temp_s1_4, pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), *(D_800A1824 + (M2C_FIELD(&gStreamState, u16 *, 0x7F88) * 4))), 1, 0x3F800000, 0);
        font_draw_text(M2C_FIELD(&gStreamState, s32 *, 0x7F62), arg0, 0xA0 - ((u32) (temp_s3_5 & 0xFFFF) >> 1), 0x14, pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), *(D_800A1824 + (M2C_FIELD(&gStreamState, u16 *, 0x7F88) * 4))), 0);
        if ((u8) M2C_FIELD(&gStreamState, u8 *, 0x7D0A) < 4U) {
            var_v0_3 = pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), 0xDC);
            var_a1_3 = 0xC6;
        } else if ((u8) M2C_FIELD(&gStreamState, u8 *, 0x7D22) < 4U) {
            var_v0_3 = pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), 0xDC);
            var_a1_3 = 0xC7;
        } else {
            var_v0_3 = pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), 0xDC);
            var_a1_3 = 0xC8;
        }
        format_to_buffer(&sp40, D_800A5ED8, var_v0_3, pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), var_a1_3));
        var_a2_2 = 0xA0 - ((u32) (font_text_width(&gStreamState + 0x7F62, &sp40, 1, 0x3F800000, 0) & 0xFFFF) >> 1);
        var_a3_2 = 0x23;
        var_v0_2 = &sp40;
    } else {
        if ((u8) M2C_FIELD(&gStreamState, u8 *, 0x7D0A) < 4U) {
            var_v0_4 = pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), 0xDC);
            var_a1_4 = 0xC6;
        } else if ((u8) M2C_FIELD(&gStreamState, u8 *, 0x7D22) < 4U) {
            var_v0_4 = pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), 0xDC);
            var_a1_4 = 0xC7;
        } else {
            var_v0_4 = pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), 0xDC);
            var_a1_4 = 0xC8;
        }
        temp_s0_7 = pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), var_a1_4);
        format_to_buffer(&sp40, D_800A5F38, var_v0_4, temp_s0_7, pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), 0xE0));
        temp_s0_8 = &gStreamState + 0x7F62;
        font_draw_text(M2C_FIELD(&gStreamState, s32 *, 0x7F62), arg0, 0xA0 - ((u32) (font_text_width(temp_s0_8, &sp40, 1, 0x3F800000, 0) & 0xFFFF) >> 1), 0x14, &sp40, 0);
        temp_s3_6 = font_text_width(temp_s0_8, pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), *(D_800A1824 + (M2C_FIELD(&gStreamState, u16 *, 0x7F88) * 4))), 1, 0x3F800000, 0);
        var_v0_2 = pool_get_item(M2C_FIELD(&gStreamState, s32 *, 0x807A), *(D_800A1824 + (M2C_FIELD(&gStreamState, u16 *, 0x7F88) * 4)));
        var_a2_2 = 0xA0 - ((u32) (temp_s3_6 & 0xFFFF) >> 1);
        var_a3_2 = 0x23;
    }
    font_draw_text(M2C_FIELD(&gStreamState, s32 *, 0x7F62), arg0, var_a2_2, var_a3_2, var_v0_2, 0);
    font_set_color(M2C_FIELD(&gStreamState, s32 *, 0x7F62), 0xFF, 0xFF, 0xFF, 0xFF);
}
