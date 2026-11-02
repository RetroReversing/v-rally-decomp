s32 func_8000665C(void *, s32);
typedef struct { u32 w0; u32 w1; } GfxW;
#define SHL(v,s,w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define TRIW(a,b,c) (SHL((a)*2,16,8)|SHL((b)*2,8,8)|SHL((c)*2,0,8))

s32 func_80006B4C(void *arg0, s16 arg1) {
    s32 temp_a0;
    s32 temp_v0;
    s32 i;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;

    if (*(u16 *)((char *)arg0 + 0x78) & 1) {
        temp_v1 = *(void **)((char *)arg0 + 0x14);
        *(u16 *)((char *)arg0 + 0x78) = 0U;
        *(void **)((char *)arg0 + 0x14) = (void *)(temp_v1 + 8);
        *(s32 *)((char *)temp_v1 + 0) = 0xD9C0F9FA;
        *(s32 *)((char *)temp_v1 + 4) = 0;
        temp_v1_2 = *(void **)((char *)arg0 + 0x14);
        *(void **)((char *)arg0 + 0x14) = (void *)(temp_v1_2 + 8);
        *(s32 *)((char *)temp_v1_2 + 0) = 0xD9FFFFFF;
        *(s32 *)((char *)temp_v1_2 + 4) = 5;
        temp_v1_3 = *(void **)((char *)arg0 + 0x14);
        *(void **)((char *)arg0 + 0x14) = (void *)(temp_v1_3 + 8);
        *(s32 *)((char *)temp_v1_3 + 0) = 0xD7000000;
        *(s32 *)((char *)temp_v1_3 + 4) = 0;
        temp_v1_4 = *(void **)((char *)arg0 + 0x14);
        *(void **)((char *)arg0 + 0x14) = (void *)(temp_v1_4 + 8);
        *(s32 *)((char *)temp_v1_4 + 0) = 0xFCFFFFFF;
        *(s32 *)((char *)temp_v1_4 + 4) = 0xFFFE793C;
    }
    temp_v0 = (u16)func_8000665C(arg0, 4);
    temp_a0 = temp_v0 * 0x10;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 4) = arg1;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x14) = arg1;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x24) = arg1;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x34) = arg1;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 6) = 0;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x16) = 0;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x26) = 0;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x36) = 0;
    *(u8 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0xF) = 0xFF;
    *(u8 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x1F) = 0xFF;
    *(u8 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x2F) = 0xFF;
    *(u8 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x3F) = 0xFF;
    i = temp_v0 & 0x1F;
    {
        GfxW *_g = (GfxW *)((*(GfxW **)((char *)arg0 + 0x14))++);
        _g->w0 = SHL(7, 24, 8) | TRIW(i, i + 1, i + 2);
        _g->w1 = TRIW(i, i + 2, i + 3);
    }
    return temp_v0;
}
