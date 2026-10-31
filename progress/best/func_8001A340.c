typedef struct { s32 words[8]; } Copy32;
typedef struct { u32 w0,w1; } Gfx;
typedef struct { s32 m[16]; } Matrix;
typedef struct { char pad[0x10]; Matrix matrix; } Transform;
typedef struct { Gfx *list[12]; void *objects[12]; char pad[0x48]; u16 values[12]; } ModelLists;
typedef struct { char pad[0xc]; void *segment; u32 flags; char pad14[4]; s16 bounds[6]; Transform *transform; char pad28[0x10]; ModelLists *lists; } Object;
Gfx *func_80006008(void *);
void func_80006014(void *,Gfx *);
void *func_8001BD1C(void);
void func_8002DFF4(Matrix *,Matrix *);
void func_80010BFC(void *,s32,Matrix *);
void func_8001AAB4(void);
u32 osVirtualToPhysical(void *);
void func_8007B2A4(void *,Matrix *);
void func_8007B4A4(ModelLists *,s32);
s32 func_8001A340(Object *, s32,void *,s32);

#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern u8 D_800C7926;
extern u8 D_800C792E;
extern void * D_800C7F84;
extern s32 D_800C72D0;
extern u16 D_800C5CF8;
extern u8 D_800ADFB9;
extern u8 D_800ADFBB;
extern u8 D_800ADFBD;
extern u16 D_800ADFB4;
extern u16 D_800ADFC0;
extern u16 D_800B5B50;
extern s32 D_800B56C8;
s32 func_80006230(void *);                            /* extern */
s32 func_80009964(void *, s32);                         /* extern */
s32 func_80016B3C(void *, s32, s32);                  /* extern */
s32 func_80019F9C(s32, u16, void *, s32);             /* extern */
s32 isBoundingBoxVisible(s32, s16 *, s32);                 /* extern */
extern u8 D_8009BBBC;
extern s32 D_8009C328;
extern s32 D_8009C390;
extern s32 D_8009C3F8;
extern s32 D_8009C460;
extern s32 D_8009C5F4;
extern s16 D_8009CBBC;
extern u8 D_8009CBC4;
extern u8 D_8009CBD0;
extern s32 D_8009FF30;




s32 func_8001A340(Object *arg0, s32 arg1, void *arg2, s32 arg3) {
    Matrix sp10;
    unsigned sp54;
    void *sp5C;
    int sp64;
    u32 sp6C;
    s32 *var_v1;
    Gfx *temp_a0_2;
    Gfx *temp_s2_3;
    Gfx *temp_s2;
    Gfx *temp_s2_2;
    void *temp_s1;
    s32 var_s3;
    Gfx *phi_v0;
    register Gfx *temp_s2_6;
    Gfx *temp_s2_7;
    Gfx *temp_v0;
    Gfx *var_a1;
    Gfx *var_s2;
    Gfx *var_s2_2;
    Gfx *var_s2_3;
    register s16 var_v1_3;
    ModelLists *temp_v1;
    Transform *temp_v0_4;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 var_v1_2;
    Gfx *var_v0;
    long temp_a0;
    register unsigned temp_fp;
    Gfx *temp_s2_4;
    register s32 var_s3_2;
    unsigned temp_v0_5;
    register unsigned long var_v1_4;
    u8 temp_s1_3;
    void **var_s0;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a3;
    Gfx *temp_s1_2;
    void *temp_t0;
    Gfx *temp_s2_5;

    sp54 = arg3;
    if (arg0->lists == NULL) {
        func_8001AAB4();
    }
    temp_s1 = func_8001BD1C();
    func_8002DFF4(&sp10, &arg0->transform->matrix);
    func_80010BFC(temp_s1, sp54, &sp10);
    var_s2 = func_80006008(arg2);
    var_a1 = var_s2;
    D_8009CBBC = 0;
    temp_fp = D_800C7926 & -(D_800C792E & 1);
    if (arg1 >= 0) {
        if (arg1 >= 3) {
            if (arg1 < 7) {
                temp_v0 = var_s2;
                phi_v0 = temp_v0;
                if ((D_8009FF30 == 2) && (phi_v0 = var_s2, (D_800C7926 == 0))) {
                    var_s2->w0 = (s32)0xDE000000;
                    var_v1 = &D_8009C460;
                    ++var_s2;
                } else {
                    ++var_s2;
                    temp_v0->w0 = 0xDE000000;
                    var_v1 = &D_8009C3F8;
                }
                goto block_15;
            }
        } else {
            phi_v0 = var_s2;
            if (D_8009FF30 != 2) {
block_10:
                var_s2->w0 = 0xDE000000;
                var_v1 = &D_8009C328;
                var_s2 += 1;
block_15:
                phi_v0->w1 = var_v1;
            } else {
                if (D_800C7926 == 0) {
                    var_s2 += 1;
                    var_a1->w0 = 0xDE000000;
                    var_a1->w1 = (u32) &D_8009C390;
                } else {
                    goto block_10;
                }
            }
            var_a1 = var_s2;
        }
    }
    var_a1->w0 = (unsigned)0xF8000000;
    var_a1->w1 = ((int)D_800ADFB9 << 0x18) | ((int)D_800ADFBB << 0x10) | (D_800ADFBD << 8) | 0xFF;
    var_s2_2 = var_s2 + 1;
    if (D_8009FF30 == 5) {
        temp_v0_2 = D_800ADFB4 + D_800ADFC0;
        var_v1_2 = temp_v0_2;
        if ((short)temp_v0_2 >= 0x3E5) {
            var_v1_2 = 0x3E4;
        }
        if (var_v1_2 < 0x2BC) {
            var_v1_2 = 0x2BC;
        }
        temp_v0_3 = 0x3E8 - ((0x3E8 - var_v1_2) / 10);
        var_v1_3 = temp_v0_3;
        if (temp_v0_3 >= 0x3E5) {
            var_v1_3 = 0x3E4;
        }
        temp_a0 = 0x3E8 - var_v1_3;
        temp_a0_2 = var_s2_2;
        ++var_s2_2;
        temp_a0_2->w0 = 0xDB080000;
        temp_a0_2->w1 = ((0x1F400 / temp_a0) << 0x10) | (((s32) ((0x1F4 - (short)var_v1_3) << 8) / temp_a0) & 0xFFFF);
    }
    if ((isBoundingBoxVisible(sp54, arg0->bounds, F(D_800C7F84,s32,0x178)) != 0) || (arg1 == 0)) {
        temp_v0_4 = arg0->transform;
        *(Copy32 *)&D_800B56C8 = *(Copy32 *)&temp_v0_4->matrix;
        temp_a0_3 = F(D_800C7F84,void *,0x24);
        if (temp_a0_3 != NULL) {
            if ((((int)D_8009FF30 == 2) & (arg1 < 3)) && (D_800C7926 == 0)) {
                func_8007B4A4(arg0->lists, 0);
                func_8007B2A4(temp_a0_3, &arg0->transform->matrix);
            }
        }
        temp_s2 = var_s2_2 + 1;
        var_s2_2->w0 = 0xDA380007;
        temp_s1_2 = temp_s2;
        var_s2_2 = temp_s2 + 1;
        temp_s2[-1].w1 = osVirtualToPhysical(temp_s1);
        temp_s1_2->w0 = 0xDB060004;
        var_s3 = 0;
        sp64 = arg1 < 3;
        sp6C = 0xFBFFFFFF;
        temp_v0_5 = osVirtualToPhysical(arg0->segment);
        sp5C = (arg1 * 0x30) + (u8 *)&D_8009C5F4;
        temp_s1_2->w1 = temp_v0_5;
        do {
            temp_s1_3 = *(&D_8009CBC4 + var_s3);
            temp_t0 = (D_800C7926 * 0x150) + sp5C + (temp_s1_3 * 4);
            if (arg0->flags & F(temp_t0,u16,0x2)) {
                if ((arg0->lists->list[temp_s1_3] != NULL) && (F(temp_t0,s16,0x0) >= 0)) {
                    if (*((arg1 * 0xC) + ((temp_fp * 0x54) + ((D_800B5B50 * 0x150) + &D_8009CBD0)) + temp_s1_3) == 1) {
                        temp_s2_2 = var_s2_2 + 1;
                        temp_s2_3 = temp_s2_2 + 1;
                        var_v0 = temp_s2_3;
                        var_s2_3 = temp_s2_3 + 1;
                        var_v1_4 = 0xC8113078;
                        var_s2_2->w0 = 0xE7000000;
                        var_s2_2->w1 = 0;
                        temp_s2_2->w1 = 0x210405;
                        F(var_s2_2,s32,0x8) = 0xD9FFFFFF;
                    } else {
                        temp_s2_4 = var_s2_2 + 1;
                        temp_s2_5 = temp_s2_4 + 1;
                        var_v0 = temp_s2_5;
                        var_s2_3 = temp_s2_5 + 1;
                        var_v1_4 = 0xC8113048;
                        var_s2_2->w0 = 0xE7000000;
                        var_s2_2->w1 = 0;
                        F(var_s2_2,s32,0x8) = 0xD9FFFFFE;
                        temp_s2_4->w1 = 0;
                    }
                    var_v0->w0 = 0xE200001C;
                    var_v0->w1 = var_v1_4;
                    var_s2_3->w0 = 0xDE000000;
                    var_s2_2 = var_s2_3 + 1;
                    var_s2_3->w1 = arg0->lists->list[temp_s1_3];
                }
                if ((arg0->lists->objects[temp_s1_3] != 0) && (((u32) ~F(temp_t0,s16,0x0) >> 0x1F) & sp64)) {
                    temp_s2_6 = var_s2_2 + 1;
                    temp_s2_7 = temp_s2_6 + 1;
                    F(temp_s2_6,s32,0x8) = 0xE200001C;
                    var_s2_2->w0 = 0xE7000000;
                    var_s2_2->w1 = 0;
                    F(var_s2_2,s32,0x8) = 0xD9FFFFFF;
                    temp_s2_6->w1 = 0x210405;
                    temp_s2_7->w1 = 0xC8113078;
                    func_80006014(arg2, temp_s2_7 + 1);
                    func_80006230(arg2);
                    F(arg2,s32,(unsigned)0x84) = (s32) (F(arg2,s32,0x84) & sp6C);
                    temp_v1 = arg0->lists;
                    func_80019F9C(temp_v1->objects[temp_s1_3], temp_v1->values[temp_s1_3], arg2, sp54);
                    if (sp64) {
                        F(arg2,s32,0x84) = (s32) ((F(arg2,s32,0x84) & sp6C) | 0x04000000);
                        func_80009964(arg2, 0);
                    }
                    var_s2_2 = func_80006008(arg2);
                }
            }
            var_s3 += 1;
        } while (0xC > var_s3);
        if (!D_8009BBBC) {
            func_80006014(arg2, var_s2_2);
            var_s3_2 = 0;
            if ((s32) D_800C5CF8 > 0) {
                var_s0 = (void *)(&D_800C5CF8 + 2);
                do {
                    temp_a0_4 = *var_s0;
                    if ((F(F(temp_a0_4,void *,0x8C),Transform *,0x28) == arg0->transform) && (temp_a0_4 != F(D_800C7F84,void *,0x24))) {
                        func_80016B3C(temp_a0_4, D_800C72D0, sp54);
                    }
                    var_s3_2 += 1;
                    var_s0 += 1;
                } while (var_s3_2 < D_800C5CF8);
            }
            var_s2_2 = func_80006008(arg2);
        }
    }
    func_80006014(arg2, var_s2_2);
    return 1;
}
