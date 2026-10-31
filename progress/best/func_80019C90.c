u16 func_8000665C();
void func_800068C0();
void func_80008B28();

typedef struct { u8 pad[0x14]; u32 *p; } G;
typedef struct { u8 pad[2]; u16 w; u16 h; s16 x; s16 y; s16 z; } R;

s32 func_80019C90(G *arg0, u8 *arg1, R *arg2, u16 arg3, u16 arg4) {
    volatile f32 sp38; volatile f32 sp3C; volatile f32 sp40;
    s32 s1; u32 a2; u32 a1; u8 v1;
    u32 *a3;
    u32 *dl_ptr;
    sp38 = *(f32*)(arg1+0x110) * (f32)arg2->w * 0.5f;
    sp40 = *(f32*)(arg1+0x118) * (f32)arg2->w * 0.5f; s1 = func_8000665C(arg0, 4) & 0xFFFF;
    func_800068C0(arg0, s1, (s16)(s32)((f32)arg2->x - sp38), arg2->y, (s16)(s32)((f32)arg2->z - sp40), (s16)(s32)((f32)arg2->x - sp38), (s16)(arg2->y - arg2->h), (s16)(s32)((f32)arg2->z - sp40), (s16)(s32)((f32)arg2->x + sp38), (s16)(arg2->y - arg2->h), (s16)(s32)((f32)arg2->z + sp40), (s16)(s32)((f32)arg2->x + sp38), arg2->y, (s16)(s32)((f32)arg2->z + sp40));
    func_80008B28(arg0, s1, arg3, arg4, arg3, 0, 0, 0, 0, arg4);
    a3 = arg0->p;
    a1 = s1 & 0x1F;
    a2 = a1 << 0x11;
    v1 = (u8)((a1 + 2) * 2);
    arg0->p = a3 + 2;
    a3[0] = a2 | ((a1 + 1) << 9) | v1 | 0x07000000;
    a3[1] = (v1 << 8) | a2 | ((a1 + 3) * 2);
    dl_ptr = arg0->p;
    arg0->p = dl_ptr + 2;
    dl_ptr[0] = 0xE7000000;
    dl_ptr[1] = 0;
    return s1;
}
