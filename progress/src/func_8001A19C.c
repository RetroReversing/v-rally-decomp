typedef s32 M2C_UNK;
extern volatile f32 vtx_scale[];
#define vtx_scale (*vtx_scale)
extern volatile f32 uv_scale;
extern volatile f32 D_8009CEC8;
extern s32 rebase_base_addr;
extern s32 gOrderState;
void rebase_words(void *, s32, s32);

/* Per-frame update for an animated object: advances its timer at 0x24 by the
   global step, scales its position fields (0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22)
   by the vertex/UV scale factors, then runs the sub-object update at 0x28. */
void func_8001A19C(void *obj) {
    s32 a1;
    s32 a2;
    s32 *timer;
    s16 *fld18;
    s16 *fld1c;
    s16 *fld1a;
    s16 *fld1e;
    s16 *fld20;
    s16 *fld22;
    s16 t22;
    f32 scale8;
    f32 val22;
    timer = (s32 *)((s8 *)obj + 0x24);
    *timer += *(s32 *)((s8 *)&gOrderState + 0x6E9C);
    fld18 = (s16 *)((s8 *)obj + 0x18);
    fld1c = (s16 *)((s8 *)obj + 0x1C);
    fld1a = (s16 *)((s8 *)obj + 0x1A);
    fld1e = (s16 *)((s8 *)obj + 0x1E);
    fld20 = (s16 *)((s8 *)obj + 0x20);
    fld22 = (s16 *)((s8 *)obj + 0x22);
    *fld18 = (s16)(s32)((f32)*fld18 * vtx_scale);
    *fld1c = (s16)(s32)((f32)*fld1c * vtx_scale);
    *fld1a = (s16)(s32)((f32)*fld1a * uv_scale);
    *fld1e = (s16)(s32)((f32)*fld1e * uv_scale);
    *fld20 = (s16)(s32)((f32)*fld20 * D_8009CEC8);
    t22 = *fld22;
    scale8 = D_8009CEC8;
    val22 = (f32)t22 * scale8;
    a2 = rebase_base_addr;
    a1 = 2;
    *fld22 = (s16)(s32)val22;
    rebase_words((s8 *)obj + 0x28, a1, a2);
}
