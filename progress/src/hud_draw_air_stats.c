void func_8000C22C(void *, s32, s32, s32, u8); extern char D_800C8380[];
extern char *gRecords;
extern char *g_camera;
extern u32 D_800C34DC;
extern u8 D_800C34F0;
extern u32 D_800C34E0;
extern u32 D_800C34D8;
extern u32 D_800C34E8;
extern u8 D_800C34F2[1];
#define D_800C34F2 D_800C34F2[0]
extern u32 D_800C34EC;
extern u8 D_800C34F3;
extern u32 D_800C34E4;
extern u8 D_800C34F1;
extern u16 D_800C34EE;
extern u16 D_800C34E6;
#define W(p,o) (*(s32*)((char*)(p)+(o)))
#define H(p,o) (*(s16*)((char*)(p)+(o)))
#define B(p,o) (*(u8*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern char gStreamState[],D_800A5FDC[],D_800A5FE8[],D_800A5FF8[],D_800A6008[];extern char *gRaceCtx,*gCarList;extern int D_800AFA6C,D_800A18D0;
int view_get_ctx_id(int);char *gfx_get_dl(int);int mtx_pool_alloc(void);void rect_set_set_scale(int,float,float,float);
void guOrthoF(void*,float,float,float,float,float,float,float);

/* HUD overlay: while the car is on the ground in the race, counts airborne frames,
 * and when it lands records the best airtime, jump height and one delta value.
 * Draws the three best values as text rows; a row flashes (drawn in yellow) for
 * 50 frames after a new record. */
void hud_draw_air_stats(void) {
    float proj_mtx[16];
    s16 text_y;
    int text_x;
    char text_buf[120];
    char time_buf[24];
    s32 ortho_mtx;
    s32 mtx_ptr_v0;
    s32 var_v0;
    s32 var_v1;
    char *ident_mtx;
    char *obj;
    char *gfx_ctx;
    char *gfx_ptr;
    char *obj_state;
    char *hud_data;
    char *dl_ptr;
    u8 *pf;

    if ((u32) D_800AFA6C >= 0xAU) {
        obj = P(gCarList,0);
        if (((*(u16 *)(gRecords+0xE)) == 1) && (W(P(obj,0x48),0) == 0) && (D_800A18D0 & 1) && ((*(u16 *)(gRecords+0x1E)) == 0)) {
            ident_mtx = &D_800C8380[0];
            guMtxIdent(ident_mtx);
            gfx_ctx = view_get_ctx_id(W(g_camera,0x178));
            dl_ptr = gfx_get_dl(gfx_ctx);
            W(dl_ptr,0x0) = 0xDA380003;
            W(dl_ptr,0x4) = ident_mtx;
            gfx_set_dl(gfx_ctx, dl_ptr + 8);
            ortho_mtx = mtx_pool_alloc();
            guOrthoF(proj_mtx, 0.0f, 320.0f, 240.0f, 0.0f, -1.0f, 10.0f, 1.0f);
            guMtxF2L(&proj_mtx, ortho_mtx);
            gfx_push_mtx(gfx_ctx, ortho_mtx);
            rect_set_set_scale(W(gRaceCtx,0x4), 0.7f, 0.7f, 0.7f);
            func_8000C22C((void *)(W(gRaceCtx,0x4)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
            obj_state = P(obj,0x80);
            /* Airborne when all four wheel contact values are non-negative. */
            if ((W(obj_state,0x310) >= 0) && (W(obj_state,0x314) >= 0) && (W(obj_state,0x318) >= 0) && (W(obj_state,0x31C) >= 0)) {
                { u32 *pc = &D_800C34DC; *pc += 1; }
                if (D_800C34F0 == 0) {
                    /* First airborne frame: sample takeoff height and ground reference. */
                    D_800C34E0 = (s32) W(P(obj,0x88),0x84);
                    D_800C34D8 = (s32) W(P(obj,0x5C),0x58);
                }
                D_800C34F0 = 1U;
            } else if (*(pf = &D_800C34F0) != 0) {
                /* Just landed: update the three records. */
                *pf = 0U;
                if ((u32) D_800C34DC > (u32) D_800C34E8) {
                    D_800C34E8 = (u32) D_800C34DC;
                    D_800C34F2 = 0x32U;
                }
                D_800C34DC = 0U;
                var_v0 = abs(W(P(obj,0x88),0x84) - (s32)D_800C34E0);
                if ((u32) D_800C34EC < (u32) var_v0) {
                    D_800C34EC = (u32) var_v0;
                    D_800C34F3 = 0x32U;
                }
                D_800C34E0 = 0;
                hud_data = P(obj,0x8C);
                { f32 s = (f32) H(hud_data,0xB6); s += (f32) H(hud_data,0xCA); s += (f32) H(hud_data,0xDE); s += (f32) H(hud_data,0xF2);
                var_v1 = abs((s32) (((s * 0.25f) - (f32) W(P(obj,0x80),0x4)) - (f32) W(P(obj,0x5C),0x58))); }
                if ((u32) D_800C34E4 < (u32) var_v1) {
                    D_800C34E4 = (u32) var_v1;
                    D_800C34F1 = 0x32U;
                }
            }
            /* Draw the three rows. Each row is printed in yellow while its flash counter is running. */
            text_x = 22; text_y = 32;
            func_8000C244(W(gRaceCtx,0x4), gfx_ctx, 0x16, 0x16, &D_800A5FDC, 0);
            if (D_800C34F2 != 0) {
                D_800C34F2--;
                func_8000C22C((void *)(W(gRaceCtx,0x4)), (s32)(0xDC), (s32)(0xDC), (s32)(0x10), (u8)(0xFF));
            } else {
                func_8000C22C((void *)(W(gRaceCtx,0x4)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
            }
            func_80052E94(D_800C34E8, &time_buf);
            formatString(&text_buf, &D_800A5FE8, &time_buf);
            if (!(((u8) D_800C34F3 >> 3) & 1)) {
                func_8000C244(W(gRaceCtx,0x4), gfx_ctx, text_x, text_y, &text_buf, 0);
            }
            text_y+=10;
            if (D_800C34F3 != 0) {
                D_800C34F3--;
                func_8000C22C((void *)(W(gRaceCtx,0x4)), (s32)(0xDC), (s32)(0xDC), (s32)(0x10), (u8)(0xFF));
            } else {
                func_8000C22C((void *)(W(gRaceCtx,0x4)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
            }
            formatString(&text_buf, &D_800A5FF8,  D_800C34EE);
            if (!(((u8) D_800C34F3 >> 3) & 1)) {
                func_8000C244(W(gRaceCtx,0x4), gfx_ctx, text_x, text_y, &text_buf, 0);
            }
            text_y+=10;
            if (D_800C34F1 != 0) {
                D_800C34F1--;
                func_8000C22C((void *)(W(gRaceCtx,0x4)), (s32)(0xDC), (s32)(0xDC), (s32)(0x10), (u8)(0xFF));
            } else {
                func_8000C22C((void *)(W(gRaceCtx,0x4)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
            }
            formatString(&text_buf, &D_800A6008,  D_800C34E6);
            if (!(((u8) D_800C34F1 >> 3) & 1)) {
                func_8000C244(W(gRaceCtx,0x4), gfx_ctx, text_x, text_y, &text_buf, 0);
            }
            rect_set_set_scale(W(gRaceCtx,0x4), 0.8f, 0.8f, 0.8f);
        }
    }
}
