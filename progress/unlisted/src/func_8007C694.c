typedef struct { u8 pad[0xC]; u16 unkC; u16 unkE; } Vp178;
typedef struct { u8 pad[0x178]; Vp178 *unk178; } VpCtx;
typedef struct { u8 pad[6]; u16 unk6; } TexHdr;
typedef struct { TexHdr *t[4]; } TexSet;
typedef struct { u8 pad[4]; TexSet *unk4; } TexOwner;
typedef struct { u8 pad[0xE]; u16 unkE; u8 pad2[0xE]; u16 unk1E; } GameState;

extern GameState *gRecords;
extern VpCtx *g_camera;
extern u8 D_800C8380[];
extern u8 D_800C83C4[];
#define D_800C8385 D_800C83C4[1]
extern u8 D_800C8170[];
typedef struct { u8 pad[0x1D00]; void *font; u16 timer; u16 page; } DbgBlk;
extern DbgBlk gOrderState;
#define D_800B0550 gOrderState.font
#define D_800B0554 gOrderState.timer
#define D_800B0556 gOrderState.page
extern TexOwner *D_800AFA50;
extern u32 D_800AFA6C;
extern u8 D_800B5580[];
extern u8 D_800B6888[];
extern s32 D_800A18D0;

extern char D_800A6018[], D_800A6030[], D_800A604C[], D_800A605C[], D_800A6068[], D_800A6074[], D_800A6080[], D_800A608C[], D_800A60A0[];
extern char D_800A60AC[], D_800A60BC[], D_800A60CC[], D_800A60D8[];
extern char D_800A60E4[], D_800A60F4[], D_800A6104[], D_800A6118[], D_800A6130[], D_800A6144[], D_800A6154[];
extern char D_800A6168[], D_800A6178[], D_800A6180[], D_800A618C[], D_800A6198[], D_800A61A0[], D_800A61AC[], D_800A61B4[], D_800A61C4[];
extern char D_800A61D0[], D_800A61DC[], D_800A61E8[], D_800A61F8[], D_800A6204[], D_800A620C[], D_800A6218[], D_800A6228[];
extern char D_800A6238[], D_800A6250[], D_800A6258[], D_800A6260[], D_800A626C[], D_800A6278[];
extern char D_800A6284[], D_800A6298[], D_800A62A4[], D_800A62AC[], D_800A62B8[], D_800A62C4[], D_800A62D0[], D_800A62D8[];
extern char D_800A62E4[], D_800A62FC[], D_800A6308[], D_800A6318[], D_800A6328[];
extern char D_800A6334[], D_800A6350[], D_800A635C[], D_800A6364[], D_800A6370[];
extern char D_800A637C[], D_800A6394[], D_800A63A0[], D_800A63B0[], D_800A63C8[], D_800A63D4[];
extern char D_800A63E0[], D_800A63F0[], D_800A63F8[], D_800A6404[], D_800A6410[], D_800A641C[], D_800A6428[], D_800A6440[], D_800A644C[], D_800A6458[];
extern char D_800A6468[], D_800A6474[], D_800A6484[], D_800A648C[], D_800A6498[], D_800A64A4[], D_800A64B0[], D_800A64BC[], D_800A64C8[];
extern char D_800A64D4[], D_800A64E4[], D_800A6508[], D_800A6528[], D_800A653C[];
extern char D_800A655C[], D_800A656C[], D_800A6578[], D_800A658C[], D_800A6594[], D_800A65B0[];
extern char D_800A65D4[], D_800A65EC[], D_800A6608[], D_800A6620[];
extern char D_800A6638[], D_800A6650[], D_800A6668[], D_800A6674[];
extern char D_800A6694[], D_800A66B0[], D_800A66C8[], D_800A66DC[], D_800A66EC[], D_800A6710[], D_800A6738[];
extern char D_800A675C[], D_800A6770[], D_800A6790[], D_800A67AC[], D_800A67CC[], D_800A67E8[], D_800A67FC[];
extern char D_800A6820[], D_800A6830[], D_800A6840[];
extern char D_800A685C[], D_800A6868[], D_800A6874[];
extern char D_800A6884[], D_800A689C[], D_800A68C8[], D_800A68DC[], D_800A68F8[], D_800A691C[];
extern char D_800A693C[], D_800A6950[], D_800A6960[], D_800A6970[], D_800A697C[], D_800A6990[];
extern char D_800A699C[], D_800A69B4[], D_800A69C4[], D_800A69E4[], D_800A6A00[], D_800A6A20[], D_800A6A3C[];
extern char D_800A6A60[], D_800A6A78[], D_800A6A98[], D_800A6AB8[], D_800A6ADC[], D_800A6B00[], D_800A6B20[];
extern char D_800A6B3C[], D_800A6B58[], D_800A6B7C[], D_800A6B90[];
extern char D_800A6B9C[], D_800A6BB0[], D_800A6BC8[], D_800A6BEC[], D_800A6C04[], D_800A6C1C[], D_800A6C38[];

void guMtxIdent(void *m);
void guOrthoF(f32 mf[4][4], f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale);
void guMtxF2L(f32 mf[4][4], void *m);
void *view_get_ctx_id(void *);
u32 *gfx_get_dl(void *);
void gfx_set_dl(void *, u32 *);
void *mtx_pool_alloc(void);
void gfx_push_mtx(void *, void *);
void gfx_round_vtx_pos(void *);
void func_8000C22C(void *, s32, s32, s32, u8);
void func_8000C244(void *, void *, s32, s32, char *, s32);
void func_8007C3E0(s32, s32, s32, s32, s32);
VpCtx *find_object_by_id(s32);
s32 func_80084DD4(s32);
void func_8000A5EC(void *, void *, s32, s32, s32, s32, s32);
void D_8000A840(Vp178 *, s16, s16, void *, s32, s32);

#define COL(r,g,b) func_8000C22C((void *)(D_800B0550), (s32)(r), (s32)(g), (s32)(b), (u8)(0xE1))
#define W COL(0xFF,0xFF,0xFF)
#define O COL(0xFF,0x94,0x05)
#define PR(y,s) func_8000C244(D_800B0550, gfx, 0x18, y, s, 2)
#define PR1(y,s) func_8000C244(D_800B0550, gfx, 0x18, y, s, 1)

void func_8007C694(void) {
    f32 mf[4][4];
    void *gfx;
    u32 *p;
    void *m;
    s32 x0;
    s32 x1;

    if (gRecords->unk1E == 7) {
        guMtxIdent(D_800C8380);
        x1 = 0;
        gfx = view_get_ctx_id(g_camera->unk178);
        p = gfx_get_dl(gfx);
        p[0] = 0xDA380003;
        p[1] = (u32)D_800C8380;
        gfx_set_dl(gfx, p + 2);
        m = mtx_pool_alloc();
        guOrthoF(mf, 0.0f, 320.0f, 240.0f, 0.0f, -1.0f, 10.0f, 1.0f);
        guMtxF2L(mf, m);
        gfx_push_mtx(gfx, m);
        func_8000C22C((void *)(D_800B0550), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
        if (--D_800B0554 == 0) {
            if (++D_800B0556 >= 16) {
                D_800B0556 = 0;
            }
            D_800B0554 = 100;
        }
        gfx_round_vtx_pos(gfx);
        if (!(D_800A18D0 & 4)) {
            func_8007C3E0(0x30, 2, 1, 0x30, 0x2000);
            switch (D_800B0556) {
            case 0:
                W; PR(0x40, D_800A6018);
                O; PR(0x4C, D_800A6030);
                break;
            case 1:
                W; PR(0x40, D_800A604C); PR(0x4C, D_800A605C);
                O; PR(0x58, D_800A6068);
                W; PR(0x64, D_800A6074);
                O; PR(0x70, D_800A6080);
                W; PR(0x7C, D_800A608C);
                O; PR(0x88, D_800A60A0);
                break;
            case 2:
                W; PR(0x40, D_800A60AC);
                O; PR(0x4C, D_800A60BC);
                W; PR(0x58, D_800A60CC);
                O; PR(0x64, D_800A60D8);
                break;
            case 3:
                func_8007C3E0(0x200, 0x100, 0x8000, 0xC000, 0x8000);
                W; PR(0x40, D_800A60E4);
                O; PR(0x4C, D_800A60F4); PR(0x58, D_800A6104); PR(0x64, D_800A6118); PR(0x70, D_800A6130); PR(0x7C, D_800A6144); PR(0x88, D_800A6154);
                break;
            case 4:
                func_8007C3E0(0x800, 0x400, 0x8000, 2, 1);
                W; PR(0x40, D_800A6168);
                O; PR(0x4C, D_800A6178); PR(0x58, D_800A6180); PR(0x64, D_800A618C); PR(0x70, D_800A6198); PR(0x7C, D_800A61A0); PR(0x88, D_800A61AC);
                W; PR(0x94, D_800A61B4);
                O; PR(0xA0, D_800A61C4);
                break;
            case 5:
                func_8007C3E0(0x20, 0x10, 0x2000, 0x4000, 4);
                W; PR(0x40, D_800A61D0);
                O; PR(0x4C, D_800A61DC);
                W; PR(0x64, D_800A61E8);
                O; PR(0x70, D_800A61F8);
                W; PR(0x7C, D_800A6204);
                O; PR(0x88, D_800A620C); PR(0x94, D_800A6218); PR(0xA0, D_800A6228);
                break;
            case 6:
                func_8007C3E0(8, 4, 0x2000, 0x10, 2);
                W; PR(0x40, D_800A6238);
                O; PR(0x4C, D_800A6250); PR(0x58, D_800A6258); PR(0x64, D_800A6260); PR(0x70, D_800A626C); PR(0x7C, D_800A6278);
                break;
            case 7:
                func_8007C3E0(0x800, 8, 0x400, 4, 8);
                PR(0x40, D_800A6284);
                O; PR(0x4C, D_800A6298); PR(0x58, D_800A62A4); PR(0x64, D_800A62AC); PR(0x70, D_800A62B8); PR(0x7C, D_800A62C4); PR(0x88, D_800A62D0); PR(0x94, D_800A62D8);
                break;
            case 8:
                func_8007C3E0(0x800, 0x200, 4, 1, 0x10);
                W; PR(0x40, D_800A62E4);
                O; PR(0x4C, D_800A62FC); PR(0x58, D_800A6308); PR(0x64, D_800A6318); PR(0x70, D_800A6328);
                break;
            case 9:
                W; PR(0x40, D_800A6334);
                O; PR(0x4C, D_800A6350); PR(0x58, D_800A635C); PR(0x64, D_800A6364); PR(0x70, D_800A6370);
                break;
            case 10:
                W; PR(0x40, D_800A637C);
                O; PR(0x4C, D_800A6394); PR(0x58, D_800A63A0);
                W; PR(0x64, D_800A63B0);
                O; PR(0x70, D_800A63C8); PR(0x7C, D_800A63D4);
                break;
            case 11:
                W; PR(0x40, D_800A63E0);
                O; PR(0x4C, D_800A63F0); PR(0x58, D_800A63F8); PR(0x64, D_800A6404); PR(0x70, D_800A6410); PR(0x7C, D_800A641C);
                W; PR(0x88, D_800A6428);
                O; PR(0x94, D_800A6440); PR(0xA0, D_800A644C); PR(0xAC, D_800A6458);
                break;
            case 12:
                W; PR(0x40, D_800A6468);
                O; PR(0x4C, D_800A6474); PR(0x58, D_800A6484); PR(0x64, D_800A648C); PR(0x70, D_800A6498);
                W; PR(0x7C, D_800A64A4);
                O; PR(0x88, D_800A64B0); PR(0xA0, D_800A64BC); PR(0x94, D_800A64C8);
                break;
            case 13:
                W; PR(0x40, D_800A64D4);
                O; PR(0x4C, D_800A64E4); PR(0x58, D_800A6508); PR(0x64, D_800A6528); PR(0x70, D_800A653C);
                break;
            case 14:
                W; PR1(0x40, D_800A655C);
                O; PR1(0x4C, D_800A656C); PR1(0x58, D_800A6578);
                W; PR1(0x64, D_800A658C);
                O; PR1(0x70, D_800A6594);
                W; PR(0x88, D_800A65B0);
                break;
            case 15:
                break;
            }
        } else {
            func_8000C22C((void *)(D_800B0550), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
            switch (D_800B0556) {
            case 0:
                PR(0x40, D_800A65D4);
                break;
            case 1:
                PR(0x40, D_800A65EC); PR(0x4C, D_800A6608); PR(0x58, D_800A6620);
                break;
            case 2:
                PR(0x40, D_800A6638); PR(0x4C, D_800A6650); PR(0x58, D_800A6668); PR(0x64, D_800A6674);
                break;
            case 3:
                PR(0x40, D_800A6694); PR(0x4C, D_800A66B0); PR(0x58, D_800A66C8); PR(0x70, D_800A66DC); PR(0x7C, D_800A66EC); PR(0x88, D_800A6710); PR(0x94, D_800A6738);
                func_8007C3E0(0x30, 2, 1, 0x30, 8);
                break;
            case 4:
                func_8007C3E0(0x200, 0x100, 0x8000, 0xC000, 0x8000);
                PR(0x40, D_800A675C); PR(0x4C, D_800A6770); PR(0x58, D_800A6790); PR(0x64, D_800A67AC); PR(0x70, D_800A67CC); PR(0x7C, D_800A67E8); PR(0x88, D_800A67FC);
                break;
            case 5:
                func_8007C3E0(0x800, 0x400, 0x8000, 2, 1);
                PR(0x40, D_800A6820); PR(0x4C, D_800A6830); PR(0x58, D_800A6840);
                break;
            case 6:
                func_8007C3E0(0x20, 0x10, 0x2000, 0x4000, 4);
                PR(0x40, D_800A685C); PR(0x4C, D_800A6868); PR(0x58, D_800A6874);
                break;
            case 7:
                func_8007C3E0(8, 4, 0x2000, 0x10, 2);
                PR(0x40, D_800A6884); PR(0x4C, D_800A689C); PR(0x58, D_800A68C8); PR(0x64, D_800A68DC); PR(0x70, D_800A68F8); PR(0x7C, D_800A691C);
                break;
            case 8:
                func_8007C3E0(0x800, 8, 0x400, 4, 8);
                PR(0x40, D_800A693C); PR(0x58, D_800A6950); PR(0x64, D_800A6960); PR(0x70, D_800A6970); PR(0x7C, D_800A697C); PR(0x88, D_800A6990);
                break;
            case 9:
                func_8007C3E0(0x800, 0x200, 4, 1, 0x10);
                PR(0x40, D_800A699C); PR(0x58, D_800A69B4); PR(0x64, D_800A69C4); PR(0x70, D_800A69E4); PR(0x7C, D_800A6A00); PR(0x88, D_800A6A20); PR(0x94, D_800A6A3C);
                break;
            case 10:
                PR(0x58, D_800A6A60); PR(0x64, D_800A6A78); PR(0x70, D_800A6A98); PR(0x7C, D_800A6AB8); PR(0x88, D_800A6ADC); PR(0x94, D_800A6B00); PR(0xB8, D_800A6B20);
                break;
            case 11:
                PR(0x40, D_800A6B3C); PR(0x58, D_800A6B58); PR(0x64, D_800A6B7C);
                break;
            case 12:
                PR(0x40, D_800A6B90);
                break;
            case 13:
                PR(0x40, D_800A6B9C); PR(0x58, D_800A6BB0); PR(0x70, D_800A6BC8); PR(0x7C, D_800A6BEC); PR(0x88, D_800A6C04); PR(0x94, D_800A6C1C);
                break;
            case 14:
                PR(0x40, D_800A6C38);
                break;
            }
        }
        gfx_round_vtx_pos(gfx);
        g_camera = find_object_by_id((gRecords->unkE << 1) | 1);
        if (func_80084DD4(0) == 0) {
            func_8000A5EC(D_800B5580, D_800AFA50->unk4->t[3], 0, 0, 0, 0, 0);
            x0 = (s16)g_camera->unk178->unkC / 2 - (D_800AFA50->unk4->t[3]->unk6 >> 1);
            func_8000A5EC(D_800B6888, D_800AFA50->unk4->t[2], 0, 0, 0, 0, 0);
            x1 = (s16)g_camera->unk178->unkC / 2 - (D_800AFA50->unk4->t[2]->unk6 >> 1);
        } else {
            func_8000A5EC(D_800B5580, D_800AFA50->unk4->t[1], 0, 0, 0, 0, 0);
            x0 = (s16)g_camera->unk178->unkC / 2 - (D_800AFA50->unk4->t[1]->unk6 >> 1);
        }
        func_8000A5EC(D_800C8170, D_800AFA50->unk4->t[0], 0, 0, 0, 0, 0);
        if ((D_800AFA6C >> 3) & 1) {
            if (func_80084DD4(0) == 0) {
                D_8000A840(g_camera->unk178, x0, g_camera->unk178->unkE - 0x24, D_800B5580, 1, 0);
                D_8000A840(g_camera->unk178, x1, g_camera->unk178->unkE - 0x1A, D_800B6888, 1, 0);
            } else {
                D_8000A840(g_camera->unk178, x0, g_camera->unk178->unkE - 0x24, D_800B5580, 1, 0);
            }
        }
        D_8000A840(g_camera->unk178, 0x10, 0x10, D_800C8170, 1, 0);
    }
    if (D_800C8385) {
        D_800C8385--;
    }
}
