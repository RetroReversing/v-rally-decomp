#define V(p,o) (*(s32*)((char*)(p)+(o)))
#define W(p,o) (*(s32*)((char*)(p)+(o)))
#define F(p,o) (*(f32*)((char*)(p)+(o)))
#define H(p,o) (*(s16*)((char*)(p)+(o)))
#define U(p,o) (*(u16*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
typedef struct { u32 w0, w1; } DLGfx;
#define CMD(pkt,a,b) { DLGfx *_g = (DLGfx *)(pkt); _g->w0 = (a); _g->w1 = (b); }
typedef struct 
{
  s32 a;
  s32 b;
  s32 c;
} Triple;
extern Triple D_800A1694;
extern Triple D_800A16A0;
extern Triple D_800A16B4;
extern Triple D_800A16C0;
extern f32 D_800A16B8;
extern f32 D_800A16BC;
extern f32 D_800A16C4;
extern f32 D_800A16C8;
extern u16 D_800A16AC;
extern u16 D_800A16AE;
extern s16 D_800A16B2;
extern u8 gStreamReady;
extern char *gSceneSlot1;
extern char *D_800AFA64;
extern char *g_camera;
extern int D_800B706C;
extern int rebase_base_addr;
extern int D_8009D4E8;
extern int *D_800C8374;
extern char D_800C8380[];
extern char D_800ADFB0[];
char *find_object_by_id(int);
DLGfx *gfx_get_dl(int);
int view_get_ctx_id(int);
int mtx_pool_alloc(void);
int func_80005C48(void *);
int osVirtualToPhysical(int);
void func_8006A438(void)
{
  DLGfx *cursor;
  s32 temp_a0;
  s32 temp_a3;
  s32 temp_s7;
  char *temp_s0;
  char *temp_s1;
  char *new_var;
  char *temp_v0;
  char *temp_v0_2;
  int new_var2;
  char *temp_v0_3;
  char *temp_v0_6;
  char *temp_v0_7;
  if (gStreamReady == 0)
  {
    return;
  }
  {
    char *a1;
    s32 a2;
    s32 v0;
    s32 a3;
    u16 *pAC = &D_800A16AC;
#define D_800A16AC (*pAC)
    a1 = D_800AFA64;
    a2 = U(a1, 0x88) * 2 / 3;
    v0 = a2 * U(a1, 0x8A);
    a3 = W(a1, 0x4C);
    temp_a0 = v0 + a3;
    F(&D_800A16B4, 0x0) = (f32) (((s16 (*)[3]) P(a1, 0x54))[temp_a0][0] + W(a1, 0x24));
    D_800A16B8 = (f32) ((((s16 (*)[3]) P(a1, 0x54))[temp_a0][1] + W(a1, 0x28)) - 0x12C);
    D_800A16BC = (f32) (((s16 (*)[3]) P(a1, 0x54))[temp_a0][2] + W(a1, 0x2C));
    temp_a0 = ++a2 * U(a1, 0x8A) + a3;
    F(&D_800A16C0, 0x0) = (f32) (((s16 (*)[3]) P(a1, 0x54))[temp_a0][0] + W(a1, 0x24));
    D_800A16C4 = (f32) ((((s16 (*)[3]) P(a1, 0x54))[temp_a0][1] + W(a1, 0x28)) - 0x12C);
    D_800A16C8 = (f32) (((s16 (*)[3]) P(a1, 0x54))[temp_a0][2] + W(a1, 0x2C));
    temp_v0 = find_object_by_id(3);
    temp_a3 = W(temp_v0, 0x178);
    g_camera = temp_v0;
    temp_s7 = view_get_ctx_id(temp_a3);
    temp_v0_2 = find_object_by_id(3);
    g_camera = temp_v0_2;
    *((Triple *) (temp_v0_2 + 0x118)) = D_800A1694;
    *((Triple *) (g_camera + 0x124)) = D_800A16A0;
    W(g_camera, 0x130) = 0;
    F(g_camera, 0x134) = 100.0f;
    W(g_camera, 0x138) = 0;
    F(g_camera, 0x114) = 1.0f;
    view_set_rect(W(g_camera, 0x178), &D_800A16AC, &D_800A16A0);
    temp_v0_3 = find_object_by_id(1);
    g_camera = temp_v0_3;
    *((Triple *) (temp_v0_3 + 0x118)) = D_800A16B4;
    *((Triple *) (g_camera + 0x124)) = D_800A16C0;
    W(g_camera, 0x130) = 0;
    F(g_camera, 0x134) = 100.0f;
    W(g_camera, 0x138) = 0;
    F(g_camera, 0x10C) = 0.4f;
    F(g_camera, 0x110) = 0.4f;
    F(g_camera, 0x114) = 1.0f;
    cursor = gfx_get_dl(temp_s7);
    CMD(cursor++, 0xE7000000, 0);
    CMD(cursor++, 0xE3000A01, 0x300000);
    new_var2 = D_800B706C + 0x80000000;
    {
      char *tex = gSceneSlot1;
      CMD(cursor++, 0xFE000000, new_var2);
      CMD(cursor++, ((H(tex, 4) - 1) & 0xFFF) | 0xFF100000, new_var2);
      CMD(cursor++, 0xF7000000, 0xFFFCFFFC);
      CMD(cursor++, 0xF6000000 | (((u32)(H(tex, 4) - 1) & 0x3FF) << 14) | (((u32)(D_800A16B2 - 1) & 0x3FF) << 2),
          ((D_800A16AC & 0x3FF) << 14) | ((D_800A16AE & 0x3FF) << 2));
      CMD(cursor++, 0xE7000000, 0);
      CMD(cursor++, ((H(tex, 4) - 1) & 0xFFF) | 0xFF100000, osVirtualToPhysical(func_80005C48(tex)));
    }
    CMD(cursor++, 0xE3000A01, 0);
    CMD(cursor++, 0xF7000000, 0x10001);
    CMD(cursor++, 0xF6000000 | (((u32)(H(gSceneSlot1, 4) - 1) & 0x3FF) << 14) | (((u32)(D_800A16B2 - 1) & 0x3FF) << 2),
        ((D_800A16AC & 0x3FF) << 14) | ((D_800A16AE & 0x3FF) << 2));
#undef D_800A16AC
    gfx_set_dl(temp_s7, cursor);
    temp_s0 = find_object_by_id(3);
    camera_refresh_and_copy(find_object_by_id(3), &D_800A16AC);
    temp_s7 = view_get_ctx_id(W(temp_s0, 0x178));
    cursor = gfx_get_dl(temp_s7);
    guMtxF2L(new_var = temp_s0 + 0x38, mtx_pool_alloc());
    guMtxIdent(D_800C8380);
    CMD(cursor++, 0xDB0E0000, U(temp_s0, 0x104));
    CMD(cursor++, 0xDA380003, (s32) D_800C8380);
    CMD(cursor++, 0xDC08000A, (s32) (temp_s0 + 0x158));
    CMD(cursor++, 0xDC08030A, (s32) (temp_s0 + 0x168));
    CMD(cursor++, 0xE7000000, 0);
    gfx_set_dl(temp_s7, cursor);
    temp_v0_6 = find_object_by_id(3);
    temp_a3 = W(temp_v0_6, 0x178);
    g_camera = temp_v0_6;
    temp_s7 = view_get_ctx_id(temp_a3);
    temp_v0_7 = find_object_by_id(1);
    g_camera = temp_v0_7;
    temp_s1 = temp_v0_7 + 0x38;
    g_camera = find_object_by_id(3);
    view_write_fog_cmds(temp_s7);
    draw_object_parts(D_800ADFB0, *D_800C8374, temp_s7, temp_s7, temp_s1);
    if (rebase_base_addr != 0)
    {
      heap_free_stub(rebase_base_addr);
      rebase_base_addr = 0;
      heap_free_stub(D_8009D4E8);
      D_8009D4E8 = 0;
    }
  }
}
