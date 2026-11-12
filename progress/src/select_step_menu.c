/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

extern int gSelectStepHandle;
extern int gRaceState;
s32 view_get_ctx_id();
void *gfx_get_dl();
s32 gfx_set_dl();
s32 gfx_push_mtx();
s32 gfx_round_vtx_pos();
s32 gfx_set_quad_pos();
s32 gfx_append_quad();
s32 gfx_set_quad_colors();
void font_set_color(void *, s32, s32, s32, u8);
s32 font_draw_text();
s32 font_text_width(void *, void *, u8, f32, u8);
s32 mtx_pool_alloc();
s32 *pool_get_item();
s32 input_get_buttons();
s8 input_get_stick_axis();
s32 pad_port_disconnected();
s32 input_clear_flags();
s32 input_set_all_flags();
s32 format_to_buffer();
s32 guMtxF2L(s32 *, s32);                   /* extern */
s32 guMtxIdent(void *);                         /* extern */
s32 guOrthoF(s32 *, f32, f32, f32, f32, f32, f32, f32); /* extern */
extern s32 gPadFlags;
extern s32 gSelectStepConfirmed;
extern char gSelectMenuDl[];
extern char *gCarEntryTable;
extern char D_800A4E04[];
extern char gSelectStepFmt[];
extern char gOrderState[];
extern char stream_state[];

/* Draws the select-step menu panel and its text, reads the stick and buttons to toggle the choice, and advances the race state when the choice is confirmed or cancelled. */ void select_step_menu(void **arg0) {
    char sp48[32];
    f32 sp68[16];
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a3;
    s32 var_a3_2;
    u16 y;
    s16 temp_s0_3;
    s16 temp_s1;
    s32 temp_s0_2;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v1_2;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    s8 temp_v0_5;
    u16 temp_s2_2;
    u16 temp_v0_6;
    void *temp_s0;
    void *temp_s1_2;
    void *temp_s3;
    void *temp_s6;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_7;
    void *temp_v1;
    void *var_a0;
    void *text;
    void *q1,*q2,*q3;
    char *resetBase;

    temp_s0 = stream_state + 0x80D2;
    guMtxIdent(temp_s0);
    temp_v0 = view_get_ctx_id(M2C_FIELD(*(void * *)(stream_state + 0x7CD6), void **, 0x178));
    temp_v0_2 = gfx_get_dl(temp_v0);
    M2C_FIELD(temp_v0_2, s32 *, 0) = 0xDA380003;
    M2C_FIELD(temp_v0_2, void **, 4) = temp_s0;
    gfx_set_dl(temp_v0, temp_v0_2 + 8);
    temp_s0_2 = mtx_pool_alloc();
    temp_v1 = M2C_FIELD(*(void * *)(stream_state + 0x7CD6), void **, 0x178); guOrthoF(&sp68, (f32) M2C_FIELD(temp_v1, s16 *, 8), (f32) M2C_FIELD(temp_v1, s16 *, 0xC), (f32) M2C_FIELD(temp_v1, s16 *, 0xE), (f32) M2C_FIELD(temp_v1, s16 *, 0xA), -1.0f, 10.0f, 1.0f);
    guMtxF2L(&sp68, temp_s0_2);
    gfx_push_mtx(temp_v0, temp_s0_2);
    temp_s3 = *arg0;
    M2C_FIELD(temp_s3, s8 *, 0xF) = 0;
    temp_s0_3 = ((s32) (0x140 - (font_text_width((void *)(temp_s3 + 0x10), (void *)(&D_800A4E04), (u8)(1), (f32)(1.0f), (u8)(0)) & 0xFFFF)) / 2) - 0xA;
    temp_v0_3 = gfx_get_dl(temp_v0);
    M2C_FIELD(temp_v0_3, s32 *, 0) = 0xDE000000;
    M2C_FIELD(temp_v0_3, s32 **, 4) = &gSelectMenuDl;
    gfx_set_dl(temp_v0, temp_v0_3 + 8);
    temp_s2 = gfx_append_quad(temp_v0, 0) & 0xFFFF;
    temp_s1 = 0x140 - temp_s0_3;
    gfx_set_quad_pos(temp_v0, temp_s2, temp_s0_3, 0x3C, 0, (s32) temp_s0_3, 0xAF, 0, (s32) temp_s1, 0xAF, 0, (s32) temp_s1, 0x3C, 0);
    gfx_set_quad_colors(temp_v0, temp_s2, 0x1E, 0x32, 0x94, 0xAA, 0x1E, 0x32, 0x94, 0xAA, 0x1E, 0x32, 0x94, 0xAA, 0x1E, 0x32, 0x94, 0xAA);
    gfx_round_vtx_pos(temp_v0);
    var_s0=0;
    if (M2C_FIELD(*(void **)(stream_state+0x32F2),u16 *,0xE)!=0) do {
        if (!pad_port_disconnected(var_s0 & 255)) goto fail;
        var_s0++;
    } while ((u16)var_s0 < M2C_FIELD(*(void **)(stream_state+0x32F2),u16 *,0xE));
block_3:
    temp_s6 = **(void ** *)(gOrderState + 0x73F0);
    if ((M2C_FIELD(temp_s6, s32 *, 0x14) & 0x200) && !(gPadFlags & 1)) {
        temp_s2_2 = M2C_FIELD(*(void * *)(stream_state + 0x32F2), u16 *, 0x36);
        font_set_color((void *)(M2C_FIELD(temp_s3, void **, 0x10)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
        temp_s1_2 = temp_s3 + 0x10;
        var_s0 = font_text_width((void *)(temp_s1_2), (void *)(pool_get_item(gSelectStepHandle, 0xEE)), (u8)(1), (f32)(1.0f), (u8)(0));
        font_set_color((void *)(M2C_FIELD(temp_s3, void **, 0x10)), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
        text=pool_get_item(gSelectStepHandle, 0xEE);
        font_draw_text(M2C_FIELD(temp_s3, void **, 0x10), temp_v0, 0xA0 - ((u32) (var_s0 & 0xFFFF) >> 1), 0x46, text, 0);
        font_set_color((void *)(M2C_FIELD(temp_s3, void **, 0x10)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
        format_to_buffer(&sp48, &gSelectStepFmt, pool_get_item(gSelectStepHandle, 0xEF), temp_s2_2);
        font_draw_text(M2C_FIELD(temp_s3, void **, 0x10), temp_v0, 0xA0 - ((u32) (font_text_width((void *)(temp_s1_2), (void *)(&sp48), (u8)(1), (f32)(1.0f), (u8)(0)) & 0xFFFF) >> 1), 0x5A, &sp48, 0);
        y=125;
        if (M2C_FIELD(temp_s3, u16 *, 0xC) == 0) {
            font_set_color((void *)(M2C_FIELD(temp_s3,void **,0x10)),(s32)(254),(s32)(213),(s32)(30),(u8)(255));
        } else {
            font_set_color((void *)(M2C_FIELD(temp_s3,void **,0x10)),(s32)(255),(s32)(255),(s32)(255),(u8)(255));
        }

        var_s0 = font_text_width((void *)(temp_s3 + 0x10), (void *)(pool_get_item(gSelectStepHandle, 0xF0)), (u8)(1), (f32)(1.0f), (u8)(0));
        text=pool_get_item(gSelectStepHandle, 0xF0);
        font_draw_text(M2C_FIELD(temp_s3, void **, 0x10), temp_v0, 0xA0 - ((u32) (var_s0 & 0xFFFF) >> 1), y, text, 0);
        y+=20;
        if (M2C_FIELD(temp_s3, u16 *, 0xC) != 0) {
            font_set_color((void *)(M2C_FIELD(temp_s3,void **,0x10)),(s32)(254),(s32)(213),(s32)(30),(u8)(255));
        } else {
            font_set_color((void *)(M2C_FIELD(temp_s3,void **,0x10)),(s32)(255),(s32)(255),(s32)(255),(u8)(255));
        }

        var_s0 = font_text_width((void *)(temp_s3 + 0x10), (void *)(pool_get_item(gSelectStepHandle, 0xF1)), (u8)(1), (f32)(1.0f), (u8)(0));
        text=pool_get_item(gSelectStepHandle, 0xF1);
        font_draw_text(M2C_FIELD(temp_s3, void **, 0x10), temp_v0, 0xA0 - ((u32) (var_s0 & 0xFFFF) >> 1), y, text, 0);
        temp_v0_4 = input_get_buttons(0);
        input_clear_flags(0, temp_v0_4);
        temp_v0_5 = input_get_stick_axis(0, 0x10000);
        if (((temp_v0_5 >= 90 || (temp_v0_4 & 0x800)) && M2C_FIELD(temp_s3,u16 *,0xC)) ||
            ((temp_v0_5 < -89 || (temp_v0_4 & 0x400)) && !M2C_FIELD(temp_s3,u16 *,0xC))) {
            M2C_FIELD(temp_s3,u16 *,0xC)=1-M2C_FIELD(temp_s3,u16 *,0xC);
        }
        if (temp_v0_4 & 0x8000) {
            if (M2C_FIELD(temp_s3, u16 *, 0xC) != 0) {
                goto cancel;
            } else {
                temp_v0_6 = M2C_FIELD(*(void * *)(stream_state + 0x32F2), u16 *, 0x36);
                if (temp_v0_6 != 0) {
                    M2C_FIELD(*(void * *)(stream_state + 0x32F2), u16 *, 0x36) = (u16) (temp_v0_6 - 1);
                }
                var_a0 = **(void ** *)(gOrderState + 0x73F0);
                gSelectStepConfirmed = 1;
                if (var_a0 != NULL) {
                    resetBase=gCarEntryTable;
                    do {
                        temp_v1_2 = *M2C_FIELD(var_a0, s32 **, 0x48);
                        if (temp_v1_2 < 5) {
                            q1=resetBase + (temp_v1_2 * 0x44);
                            M2C_FIELD(q1,s16 *,0xA)=3;
                            temp_v0_7 = resetBase + (*M2C_FIELD(var_a0, s32 **, 0x48) * 0x44);
                            M2C_FIELD(temp_v0_7, u16 *, 8) &= 0xFDFF;
                            q2=resetBase + (*M2C_FIELD(var_a0, s32 **, 0x48) * 0x44);
                            M2C_FIELD(q2,s16 *,0xC)=0;
                            q3=resetBase + (*M2C_FIELD(var_a0, s32 **, 0x48) * 0x44);
                            M2C_FIELD(q3,s16 *,0xE)=0;
                            M2C_FIELD(M2C_FIELD(var_a0, void **, 0x44), s32 *, 0x28) = -1;
                            M2C_FIELD(M2C_FIELD(var_a0, void **, 0x70), s32 *, 0x28) = -1;
                        }
                        var_a0 = M2C_FIELD(var_a0, void **, 4);
                    } while (var_a0 != NULL);
                }
                input_set_all_flags(0);
                M2C_FIELD(temp_s3, u8 *, 0xE) = 1U;
                M2C_FIELD(temp_s3, u16 *, 0xC) = 0U;
            }
        }
        goto check;
fail:
        gPadFlags |= 2;
        return;
cancel:
        M2C_FIELD(temp_s3, u8 *, 0xE) = 0U;
        input_clear_flags(0,0x8000);
check:
        if (M2C_FIELD(temp_s3, u8 *, 0xE) == 0) {
            gRaceState = 1;
            M2C_FIELD(temp_s3, s8 *, 0xF) = 1;
            var_a0=*(void **)(stream_state+0x32F2);
            M2C_FIELD(temp_s6, s32 *, 0x14) &= ~0x200;
            M2C_FIELD(var_a0, u16 *, 0x36) = 0U;
        }
    }
}
