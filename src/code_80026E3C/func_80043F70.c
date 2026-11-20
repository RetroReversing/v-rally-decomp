#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
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

/* Draws the select-step menu panel and its text, reads the stick and buttons to toggle the choice, and advances the race state when the choice is confirmed or cancelled. */ /* Draws the select-step menu panel and its text, reads the stick and buttons to toggle the choice, and advances the race state when the choice is confirmed or cancelled. */ void func_80043F70(void **menu_car) {
    char step_text[32];
    f32 ortho_mtx[16];
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a3;
    s32 var_a3_2;
    u16 text_y;
    s16 text_x;
    s16 text_x_right;
    s32 mtx_dst;
    s32 quad_id;
    s32 ctx_id;
    s32 buttons;
    s32 entry_state;
    s32 width;
    s32 var_v0;
    s32 var_v0_2;
    s8 stick_axis;
    u16 step_value;
    u16 steps_left;
    void *mtx_src;
    void *text_base;
    void *car;
    void *car_node;
    void *dl_ptr;
    void *dl_ptr2;
    void *quad_dl;
    void *view;
    void *node;
    void *str;
    void *q1,*q2,*q3;
    char *car_entries;

    mtx_src = stream_state + 0x80D2;
    guMtxIdent(mtx_src);
    ctx_id = view_get_ctx_id(M2C_FIELD(*(void * *)(stream_state + 0x7CD6), void **, 0x178));
    dl_ptr = gfx_get_dl(ctx_id);
    M2C_FIELD(dl_ptr, s32 *, 0) = 0xDA380003;
    M2C_FIELD(dl_ptr, void **, 4) = mtx_src;
    gfx_set_dl(ctx_id, dl_ptr + 8);
    mtx_dst = mtx_pool_alloc();
    view = M2C_FIELD(*(void * *)(stream_state + 0x7CD6), void **, 0x178); guOrthoF(&ortho_mtx, (f32) M2C_FIELD(view, s16 *, 8), (f32) M2C_FIELD(view, s16 *, 0xC), (f32) M2C_FIELD(view, s16 *, 0xE), (f32) M2C_FIELD(view, s16 *, 0xA), -1.0f, 10.0f, 1.0f);
    guMtxF2L(&ortho_mtx, mtx_dst);
    gfx_push_mtx(ctx_id, mtx_dst);
    car = *menu_car;
    M2C_FIELD(car, s8 *, 0xF) = 0;
    text_x = ((s32) (0x140 - (font_text_width((void *)(car + 0x10), (void *)(&D_800A4E04), (u8)(1), (f32)(1.0f), (u8)(0)) & 0xFFFF)) / 2) - 0xA;
    dl_ptr2 = gfx_get_dl(ctx_id);
    M2C_FIELD(dl_ptr2, s32 *, 0) = 0xDE000000;
    M2C_FIELD(dl_ptr2, s32 **, 4) = &gSelectMenuDl;
    gfx_set_dl(ctx_id, dl_ptr2 + 8);
    quad_id = gfx_append_quad(ctx_id, 0) & 0xFFFF;
    text_x_right = 0x140 - text_x;
    gfx_set_quad_pos(ctx_id, quad_id, text_x, 0x3C, 0, (s32) text_x, 0xAF, 0, (s32) text_x_right, 0xAF, 0, (s32) text_x_right, 0x3C, 0);
    gfx_set_quad_colors(ctx_id, quad_id, 0x1E, 0x32, 0x94, 0xAA, 0x1E, 0x32, 0x94, 0xAA, 0x1E, 0x32, 0x94, 0xAA, 0x1E, 0x32, 0x94, 0xAA);
    gfx_round_vtx_pos(ctx_id);
    width=0;
    if (M2C_FIELD(*(void **)(stream_state+0x32F2),u16 *,0xE)!=0) do {
        if (!pad_port_disconnected(width & 255)) goto fail;
        width++;
    } while ((u16)width < M2C_FIELD(*(void **)(stream_state+0x32F2),u16 *,0xE));
block_3:
    car_node = **(void ** *)(gOrderState + 0x73F0);
    if ((M2C_FIELD(car_node, s32 *, 0x14) & 0x200) && !(gPadFlags & 1)) {
        step_value = M2C_FIELD(*(void * *)(stream_state + 0x32F2), u16 *, 0x36);
        font_set_color((void *)(M2C_FIELD(car, void **, 0x10)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
        text_base = car + 0x10;
        width = font_text_width((void *)(text_base), (void *)(pool_get_item(gSelectStepHandle, 0xEE)), (u8)(1), (f32)(1.0f), (u8)(0));
        font_set_color((void *)(M2C_FIELD(car, void **, 0x10)), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
        str=pool_get_item(gSelectStepHandle, 0xEE);
        font_draw_text(M2C_FIELD(car, void **, 0x10), ctx_id, 0xA0 - ((u32) (width & 0xFFFF) >> 1), 0x46, str, 0);
        font_set_color((void *)(M2C_FIELD(car, void **, 0x10)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
        format_to_buffer(&step_text, &gSelectStepFmt, pool_get_item(gSelectStepHandle, 0xEF), step_value);
        font_draw_text(M2C_FIELD(car, void **, 0x10), ctx_id, 0xA0 - ((u32) (font_text_width((void *)(text_base), (void *)(&step_text), (u8)(1), (f32)(1.0f), (u8)(0)) & 0xFFFF) >> 1), 0x5A, &step_text, 0);
        text_y=125;
        if (M2C_FIELD(car, u16 *, 0xC) == 0) {
            font_set_color((void *)(M2C_FIELD(car,void **,0x10)),(s32)(254),(s32)(213),(s32)(30),(u8)(255));
        } else {
            font_set_color((void *)(M2C_FIELD(car,void **,0x10)),(s32)(255),(s32)(255),(s32)(255),(u8)(255));
        }

        width = font_text_width((void *)(car + 0x10), (void *)(pool_get_item(gSelectStepHandle, 0xF0)), (u8)(1), (f32)(1.0f), (u8)(0));
        str=pool_get_item(gSelectStepHandle, 0xF0);
        font_draw_text(M2C_FIELD(car, void **, 0x10), ctx_id, 0xA0 - ((u32) (width & 0xFFFF) >> 1), text_y, str, 0);
        text_y+=20;
        if (M2C_FIELD(car, u16 *, 0xC) != 0) {
            font_set_color((void *)(M2C_FIELD(car,void **,0x10)),(s32)(254),(s32)(213),(s32)(30),(u8)(255));
        } else {
            font_set_color((void *)(M2C_FIELD(car,void **,0x10)),(s32)(255),(s32)(255),(s32)(255),(u8)(255));
        }

        width = font_text_width((void *)(car + 0x10), (void *)(pool_get_item(gSelectStepHandle, 0xF1)), (u8)(1), (f32)(1.0f), (u8)(0));
        str=pool_get_item(gSelectStepHandle, 0xF1);
        font_draw_text(M2C_FIELD(car, void **, 0x10), ctx_id, 0xA0 - ((u32) (width & 0xFFFF) >> 1), text_y, str, 0);
        buttons = input_get_buttons(0);
        input_clear_flags(0, buttons);
        stick_axis = input_get_stick_axis(0, 0x10000);
        if (((stick_axis >= 90 || (buttons & 0x800)) && M2C_FIELD(car,u16 *,0xC)) ||
            ((stick_axis < -89 || (buttons & 0x400)) && !M2C_FIELD(car,u16 *,0xC))) {
            M2C_FIELD(car,u16 *,0xC)=1-M2C_FIELD(car,u16 *,0xC);
        }
        if (buttons & 0x8000) {
            if (M2C_FIELD(car, u16 *, 0xC) != 0) {
                goto cancel;
            } else {
                steps_left = M2C_FIELD(*(void * *)(stream_state + 0x32F2), u16 *, 0x36);
                if (steps_left != 0) {
                    M2C_FIELD(*(void * *)(stream_state + 0x32F2), u16 *, 0x36) = (u16) (steps_left - 1);
                }
                node = **(void ** *)(gOrderState + 0x73F0);
                gSelectStepConfirmed = 1;
                if (node != NULL) {
                    car_entries=gCarEntryTable;
                    do {
                        entry_state = *M2C_FIELD(node, s32 **, 0x48);
                        if (entry_state < 5) {
                            q1=car_entries + (entry_state * 0x44);
                            M2C_FIELD(q1,s16 *,0xA)=3;
                            quad_dl = car_entries + (*M2C_FIELD(node, s32 **, 0x48) * 0x44);
                            M2C_FIELD(quad_dl, u16 *, 8) &= 0xFDFF;
                            q2=car_entries + (*M2C_FIELD(node, s32 **, 0x48) * 0x44);
                            M2C_FIELD(q2,s16 *,0xC)=0;
                            q3=car_entries + (*M2C_FIELD(node, s32 **, 0x48) * 0x44);
                            M2C_FIELD(q3,s16 *,0xE)=0;
                            M2C_FIELD(M2C_FIELD(node, void **, 0x44), s32 *, 0x28) = -1;
                            M2C_FIELD(M2C_FIELD(node, void **, 0x70), s32 *, 0x28) = -1;
                        }
                        node = M2C_FIELD(node, void **, 4);
                    } while (node != NULL);
                }
                input_set_all_flags(0);
                M2C_FIELD(car, u8 *, 0xE) = 1U;
                M2C_FIELD(car, u16 *, 0xC) = 0U;
            }
        }
        goto check;
fail:
        gPadFlags |= 2;
        return;
cancel:
        M2C_FIELD(car, u8 *, 0xE) = 0U;
        input_clear_flags(0,0x8000);
check:
        if (M2C_FIELD(car, u8 *, 0xE) == 0) {
            gRaceState = 1;
            M2C_FIELD(car, s8 *, 0xF) = 1;
            node=*(void **)(stream_state+0x32F2);
            M2C_FIELD(car_node, s32 *, 0x14) &= ~0x200;
            M2C_FIELD(node, u16 *, 0x36) = 0U;
        }
    }
}

