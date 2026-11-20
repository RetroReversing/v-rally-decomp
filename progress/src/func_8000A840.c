typedef struct Texture { u8 pad0[4]; u16 format, stride; u8 pad8, height, padA[2]; u16 rows, slices; u8 pad10[4]; s32 *pixels; } Texture;
typedef struct { u8 pad0[12]; Texture *tex; u8 pad10[28]; s32 image; u8 pad30[4]; s16 limit; u8 pad36[2]; s32 other; u8 pad3c[4]; s16 x; u8 pad42[6]; s16 y; u8 pad4a[2]; s16 scale; u8 pad4e[9]; s8 flags; void *list; u8 pad5c[4]; } Order;
typedef struct {u8 r,g,b,a;} Color;
typedef struct { u32 op, value; } Packet;
#define EMIT(op, value) do { \
    u32 *packet = (u32 *)var_s3_4; \
    var_s3_4 += 8; \
    packet[0] = (op); \
    packet[1] = (value); \
} while (0)
#define EMIT_REVERSED(op, value) do { \
    u32 *packet = (u32 *)var_s3_4; \
    var_s3_4 += 8; \
    packet[1] = (value); \
    packet[0] = (op); \
} while (0)

s32 func_80009E54(void);
void *gfx_get_dl(s32);                              /* extern */
s32 gfx_set_dl(s32, void *);                    /* extern */
u32 osVirtualToPhysical(const void *);
s32 view_get_ctx_id(void);                              /* extern */
extern s32 D_8009B5D0;
extern u8 gOrderState[];

void func_8000A840(void *texture, s32 arg1, s32 arg2, u8 *arg3, s32 arg4, const u8 *arg5) {
    u8 *temp_a0_11;
    u8 *temp_a0_13;
    u8 *temp_a0_15;
    u8 *temp_a0_17;
    u8 *temp_a0_2;
    u8 *temp_a0_5;
    u8 *temp_a0_8;
    u8 *temp_a1_7;
    u8 *temp_s5;
    u8 *var_a0_10;
    u8 *var_a0_15;
    u8 *var_a0_17;
    u8 *var_a0_19;
    u8 *var_a0_21;
    u8 *var_a0_3;
    u8 *var_a0_5;
    u8 *var_a1_20;
    u8 *var_a1_10;
    u8 *var_a1_11;
    u8 *var_a1_12;
    u8 *var_a1_14;
    u8 *var_a1_15;
    u8 *var_a1_16;
    u8 *var_a1_17;
    u8 *var_a1_18;
    u8 *var_a1_19;
    u8 *var_a0_8;
    u8 *var_a1_21;
    
    u8 *var_a1_3;
    u8 *var_a1_4;
    u8 *var_a1_5;
    u8 *var_a1_6;
    u8 *var_a1_8;
    u8 *var_a1_9;
    u8 *var_a3;
    u8 *var_a3_2;
    u8 *var_a3_3;
    u8 *var_a3_4;
    u8 *var_s0;
    u8 *var_s0_3;
    u32 *packet_loop_0_0;
    u32 *packet_loop_0_1;
    u32 *packet_loop_1_0;
    u32 *packet_loop_1_1;
    u8 *var_s3_4;
    s32 slice_y;
    u32 *last_draw_0_0;
    u32 *last_draw_0_1;
    u32 *last_draw_0_2;
    u32 *last_draw_1_0;
    u32 *last_draw_1_1;
    u32 *last_draw_1_2;
    u32 *last_draw_2_0;
    u32 *last_draw_2_1;
    u32 *last_draw_2_2;
    s32 temp_v0;
    s16 temp_a0_14;
    
    s16 temp_a1_2;
    
    s16 temp_a1_4;
    
    
    s32 temp_lo_2;
    s16 temp_a0_12;
    s32 temp_v0_11;
    s32 temp_v0_13;
    s32 temp_v0_15;
    s32 temp_v0_17;
    s32 temp_v0_19;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1_13;
    s32 temp_v1_17;
    register s32 temp_v1_4;
    s32 temp_v1_8;
    s32 var_a0;
    s32 var_a0_12;
    s32 var_a0_13;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_a1_7;
    u8 var_s4;

    u32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    s32 var_v1_10;
    s32 var_v1_11;
    s32 var_v1_12;
    s32 var_v1_13;
    s32 var_v1_14;
    s32 var_v1_15;
    s32 var_v1_16;
    s32 var_v1_2;
    long var_v1_3;
    s32 var_v1_4;
    s32 var_v1_5;
    s32 var_v1_6;
    s32 var_v1_7;
    s32 var_v1_8;
    s32 var_v1_9;
    u16 temp_a0_3;
    u16 temp_v1;
    u16 temp_v1_10;
    u16 var_a0_14;
    void *slice_texture;
    s32 slice_offset;
    u32 temp_lo;
    u32 var_a0_11;
    u32 var_a0_16;
    u32 var_a0_18;
    u32 var_a0_20;
    u32 var_a0_22;
    u32 var_a0_4;
    u32 var_a0_6;
    u32 var_a0_9;
    u32 var_a1_13;
    u32 var_s2;
    void *temp_a0;
    void *temp_a0_10;
    void *temp_a0_16;
    void *temp_a0_6;
    void *temp_a0_7;
    void *temp_a0_9;
    void *temp_a1;
    void *temp_a1_5;
    void *temp_a1_6;
    void *temp_s0_7;
    void *temp_s0_8;

    void *temp_s3_10;






    void *temp_s3_8;
    void *temp_s3_9;

    void *temp_v1_11;
    void *temp_v1_12;
    void *temp_v1_14;
    void *temp_v1_15;
    void *temp_v1_16;
    void *temp_v1_18;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_5;
    void *temp_v1_6;
    void *temp_v1_7;
    void *temp_v1_9;
    void *var_a0_7;
    void *var_s0_2;
    void *var_s0_4;
    void *var_s0_5;
    void *var_s0_6;
    void *var_s1;



    void *var_s3_5;

    u32 *last_gfx_packet_0;
    u32 *gfx_packet_0;
    u32 *gfx_packet_1;
    u32 *gfx_packet_2;
    u32 *gfx_packet_3;
    u32 *gfx_packet_4;
    u32 *gfx_packet_5;
    u32 *gfx_packet_6;
    u32 *gfx_packet_7;
    u32 *gfx_packet_8;
    u32 *gfx_packet_9;
    u32 *gfx_packet_10;
    u32 *gfx_packet_11;
    u32 *gfx_packet_12;
    u32 *gfx_packet_13;
    u32 *gfx_packet_14;
    u32 *gfx_packet_15;
    u32 *gfx_packet_16;
    u32 *gfx_packet_17;
    u32 *gfx_packet_18;
    u32 *gfx_packet_19;
    u32 *gfx_packet_20;
    u32 *gfx_packet_21;
    u32 *gfx_packet_22;
    u32 *gfx_packet_23;
    u32 *gfx_packet_24;
    u32 *gfx_packet_25;



    s32 held_arg1 = arg1;
    s32 held_arg2 = arg2;
    temp_v0 = view_get_ctx_id();
    var_s3_4 = gfx_get_dl(temp_v0);
    gfx_packet_0 = (u32 *)var_s3_4;
    var_s3_4 += 8;
    gfx_packet_0[0] = 0xDE000000;
    gfx_packet_0[1] = (u32)&D_8009B5D0;
    if (arg4 & 1) {
        if (arg4 & 4) {
            gfx_packet_1 = (u32 *)var_s3_4;
            var_s3_4 += 8;
            gfx_packet_1[0] = 0xE200001C;
            gfx_packet_1[1] = 0x503048;
        } else {
            gfx_packet_2 = (u32 *)var_s3_4;
            var_s3_4 += 8;
            gfx_packet_2[0] = 0xE200001C;
            gfx_packet_2[1] = 0x0F0A4000;
        }
    } else if (arg4 & 4) {
        gfx_packet_3 = (u32 *)var_s3_4;
        var_s3_4 += 8;
        gfx_packet_3[0] = 0xE200001C;
        gfx_packet_3[1] = 0x5041C8;
    } else {
        gfx_packet_4 = (u32 *)var_s3_4;
        var_s3_4 += 8;
        gfx_packet_4[0] = 0xE200001C;
        gfx_packet_4[1] = 0x504240;
    }
    if (arg4 & 0x10) {
        gfx_packet_5 = (u32 *)var_s3_4;
        var_s3_4 += 8;
        gfx_packet_5[0] = 0xE200001C;
        gfx_packet_5[1] = 0;
        gfx_packet_6 = (u32 *)var_s3_4;
        var_s3_4 += 8;
        gfx_packet_6[0] = 0xE3000A01;
        gfx_packet_6[1] = 0x200000;
    } else {
        gfx_packet_7 = (u32 *)var_s3_4;
        var_s3_4 += 8;
        gfx_packet_7[0] = 0xE3000A01;
        gfx_packet_7[1] = 0;
    }
    if (arg4 & 0x80) {
        (*(s8 *)((char *)(arg3) + 0x57)) = 0x10;
    }
    if (arg4 & 0x40) {
        (*(s8 *)((char *)(arg3) + 0x57)) = 1;
    }
    if (arg5 != NULL) {
        gfx_packet_8 = (u32 *)var_s3_4;
        var_s3_4 += 8;
        gfx_packet_8[0] = 0xFCFFFE61;
        gfx_packet_8[1] = 0xFF64F3FF;
        gfx_packet_9 = (u32 *)var_s3_4;
        var_s3_4 += 8;
        gfx_packet_9[0] = 0xFA000000;
        gfx_packet_9[1] = ((u32)((Color *)arg5)->r << 24) | ((u32)((Color *)arg5)->g << 16) | ((u32)((Color *)arg5)->b << 8) | ((Color *)arg5)->a;
    } else {
        gfx_packet_10 = (u32 *)var_s3_4;
        var_s3_4 += 8;
        gfx_packet_10[0] = 0xFC119623;
        gfx_packet_10[1] = 0xFF2FFFFF;
        gfx_packet_11 = (u32 *)var_s3_4;
        var_s3_4 += 8;
        gfx_packet_11[0] = 0xFA000000;
        gfx_packet_11[1] = -0x80;
    }
    gfx_packet_12 = (u32 *)var_s3_4;
    var_s3_4 += 8;
    gfx_packet_12[0] = 0xFB000000;
    gfx_packet_12[1] = 0x80;
    gfx_packet_13 = (u32 *)var_s3_4;
    var_s3_4 += 8;
    gfx_packet_13[0] = 0xE3001001;
    gfx_packet_13[1] = 0x8000;
    gfx_packet_14 = (u32 *)var_s3_4;
    var_s3_4 += 8;
    gfx_packet_14[0] = 0xE7000000;
    gfx_packet_14[1] = 0;
    gfx_packet_15 = (u32 *)var_s3_4;
    var_s3_4 += 8;
    gfx_packet_15[0] = 0x05000017;
    gfx_packet_15[1] = (u32)(arg3 + 0x10);
    if (arg4 & 0x20) {
        temp_a0 = (*(void **)((char *)(arg3) + 0xC));
        (*(s16 *)((char *)(arg3) + 0x40)) = (s16) (held_arg1 * 4);
        (*(s16 *)((char *)(arg3) + 0x48)) = (s16) (held_arg2 * 4);
        temp_v1 = (*(u16 *)((char *)(temp_a0) + 0xE));
        if (temp_v1 == 1) {
            var_s2 = func_80009E54();
            temp_a0_2 = arg3 + 0x60;
            var_a3 = temp_a0_2;
{
u32 *sptr; u32 *dptr; int words;
if ((var_s2 < (u32)temp_a0_2) & ((u32)arg3 < var_s2)) {
sptr = (u32 *)temp_a0_2; dptr = (u32 *)var_s2+24; words=24; do { *--dptr = *--sptr; } while (--words);
} else {
sptr = (u32 *)arg3; dptr = (u32 *)var_s2; words=24; do { *dptr++ = *sptr++; } while (--words);
}
}
last_draw_0_0 = (u32 *)var_s3_4;
var_s3_4 += 8;
last_draw_0_0[0] = 0x05000017;
last_draw_0_0[1] = osVirtualToPhysical((void *)(var_s2 + 0x28));
last_draw_0_1 = (u32 *)var_s3_4;
var_s3_4 += 8;
last_draw_0_1[0] = 0xDC170000;
last_draw_0_1[1] = osVirtualToPhysical((*(void **)((char *)(var_s2) + 0x58)));
last_draw_0_2 = (u32 *)var_s3_4;
var_s3_4 += 8;
last_draw_0_2[0] = 0x02000000;
last_draw_0_2[1] = osVirtualToPhysical((void *)(var_s2 + 0x40));
        } else if ((temp_a0_3 = (*(u16 *)((char *)(temp_a0) + 4))) == 0x10) {
            var_s4 = 0;
            if ((temp_v1 - 1) > 0) {
                temp_s5 = arg3 + 0x60;
                var_s0_2 = var_s3_4 - 4;
                do {
                    var_s2 = func_80009E54();
                    var_a1_3 = temp_s5;
                    if ((var_s2 < (u32) temp_s5) & ((u32) arg3 < var_s2)) {
                        var_a0_3 = (void *)(var_s2 + 0x60);
                        var_v1 = 0x18;
                        do {
                            var_a1_3 -= 4;
                            var_a0_3 -= 4;
                            var_v1 -= 1;
                            (*(s32 *)((char *)(var_a0_3) + 0)) = (*(s32 *)((char *)(var_a1_3) + 0));
                        } while (var_v1 != 0);
                    } else {
                        var_a1_4 = arg3;
                        var_a0_4 = var_s2;
                        var_v1_2 = 0x18;
                        do {
                            temp_v0_5 = (*(s32 *)((char *)(var_a1_4) + 0));
                            var_a1_4 += 4;
                            var_v1_2 -= 1;
                            (*(s32 *)((char *)(var_a0_4) + 0)) = temp_v0_5;
                            var_a0_4 += 4;
                        } while (var_v1_2 != 0);
                    }
                    (*(s16 *)((char *)(var_s2) + 0x34)) = (s16) (((*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC)) * 4) - 1);
                    (*(s16 *)((char *)(var_s2) + 0x4C)) = (s16) ((*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC)) << 5);
                    temp_a1 = (*(void **)((char *)(arg3) + 0xC));
                    temp_a0_12 = (var_s4 & 0xFF);
                    (*(s32 *)((char *)(var_s2) + 0x2C)) = (s32) (*(*(s32 **)((char *)(temp_a1) + 0x14)) + ((s32) (temp_a0_12 * (*(u16 *)((char *)(temp_a1) + 0xC)) * (*(u16 *)((char *)(temp_a1) + 6))) / 2));
                    temp_v1_2 = (*(void **)((char *)(arg3) + 0xC));
                    (*(s32 *)((char *)(var_s2) + 0x38)) = (s32) (*(*(s32 **)((char *)(temp_v1_2) + 0x14)) + ((s32) (temp_a0_12 * (*(u16 *)((char *)(temp_v1_2) + 0xC)) * (*(u16 *)((char *)(temp_v1_2) + 6))) / 2));
                    (*(s16 *)((char *)(var_s2) + 0x48)) = (s16) ((held_arg2 + ((var_s4 & 0xFF) * (*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC)))) * 4);
                    gfx_packet_16 = (u32 *)var_s3_4;
                    var_s3_4 += 8;
                    gfx_packet_16[0] = 0x05000017;
                    gfx_packet_16[1] = osVirtualToPhysical((void *)(var_s2 + 0x28));
                    gfx_packet_17 = (u32 *)var_s3_4;
                    var_s3_4 += 8;
                    gfx_packet_17[0] = 0xDC170000;
                    gfx_packet_17[1] = osVirtualToPhysical((*(void **)((char *)(var_s2) + 0x58)));
                    gfx_packet_18 = (u32 *)var_s3_4;
                    var_s3_4 += 8;
                    gfx_packet_18[0] = 0x02000000;
                    gfx_packet_18[1] = osVirtualToPhysical((void *)(var_s2 + 0x40));
                    gfx_packet_19 = (u32 *)var_s3_4;
                    var_s3_4 += 8;
                    gfx_packet_19[0] = 0xE7000000;
                    gfx_packet_19[1] = 0;
                    var_s4 += 1;
                } while ((var_s4 & 0xFF) < ((*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xE)) - 1));
            }
            var_s2 = func_80009E54();
            temp_a0_5 = arg3 + 0x60;
            var_a1_5 = temp_a0_5;
{
if ((var_s2 < (u32)temp_a0_5) & ((u32)arg3 < var_s2)) {
u32 *sptr; u32 *dptr; int words;
sptr = (u32 *)temp_a0_5; dptr = (u32 *)var_s2+24; words=24; do { *--dptr = *--sptr; } while (--words);

} else {
u32 *sptr; u32 *dptr; int words;
sptr = (u32 *)arg3; dptr = (u32 *)var_s2; words=24; do { *dptr++ = *sptr++; } while (--words);

}
}
            temp_v1_3 = (*(void **)((char *)(arg3) + 0xC));
            temp_v1_4 = ((*(u8 *)((char *)(temp_v1_3) + 9)) - (((*(u16 *)((char *)(temp_v1_3) + 0xE)) - 1) * (*(u16 *)((char *)(temp_v1_3) + 0xC)))) & 0xFF;
            (*(s16 *)((char *)(var_s2) + 0x4C)) = (s16) (temp_v1_4 << 5);
            slice_y = ((var_s4 & 0xFF) * (*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC))) * 4;
            (*(s16 *)((char *)(var_s2) + 0x34)) = (s16) ((temp_v1_4 * 4) - 1);
            (*(s16 *)((char *)(var_s2) + 0x48)) = held_arg2 * 4 + slice_y;
            temp_a0_6 = (*(void **)((char *)(arg3) + 0xC));
            temp_a1_2 = (var_s4 & 0xFF);
            (*(s32 *)((char *)(var_s2) + 0x2C)) = (s32) (*(*(s32 **)((char *)(temp_a0_6) + 0x14)) + ((s32) (temp_a1_2 * (*(u16 *)((char *)(temp_a0_6) + 0xC)) * (*(u16 *)((char *)(temp_a0_6) + 6))) / 2));
            temp_v1_5 = (*(void **)((char *)(arg3) + 0xC));
(*(s32 *)((char *)(var_s2) + 0x38)) = *(*(s32 **)((char *)(temp_v1_5) + 0x14)) + (temp_a1_2 * (*(u16 *)((char *)(temp_v1_5) + 0xC)) * (*(u16 *)((char *)(temp_v1_5) + 6))) / 2;
last_draw_1_0 = (u32 *)var_s3_4;
var_s3_4 += 8;
last_draw_1_0[0] = 0x05000017;
last_draw_1_0[1] = osVirtualToPhysical((void *)(var_s2 + 0x28));
last_draw_1_1 = (u32 *)var_s3_4;
var_s3_4 += 8;
last_draw_1_1[0] = 0xDC170000;
last_draw_1_1[1] = osVirtualToPhysical((*(void **)((char *)(var_s2) + 0x58)));
last_draw_1_2 = (u32 *)var_s3_4;
var_s3_4 += 8;
last_draw_1_2[0] = 0x02000000;
last_draw_1_2[1] = osVirtualToPhysical((void *)(var_s2 + 0x40));
        } else if (temp_a0_3 == 0x100) {
            var_s4 = 0;
            if ((temp_v1 - 1) > 0) {
                temp_s5 = arg3 + 0x60;
                var_s0_4 = var_s3_4 - 4;
                do {
                    var_s2 = func_80009E54();
                    var_a1_8 = temp_s5;
                    if ((var_s2 < (u32) temp_s5) & ((u32) arg3 < var_s2)) {
                        var_a0_8 = (void *)(var_s2 + 0x60);
                        var_v1_5 = 0x18;
                        do {
                            var_a1_8 -= 4;
                            var_a0_8 -= 4;
                            var_v1_5 -= 1;
                            (*(s32 *)((char *)(var_a0_8) + 0)) = (*(s32 *)((char *)(var_a1_8) + 0));
                        } while (var_v1_5 != 0);
                    } else {
                        var_a1_9 = arg3;
                        var_a0_9 = var_s2;
                        var_v1_6 = 0x18;
                        do {
                            temp_v0_8 = (*(s32 *)((char *)(var_a1_9) + 0));
                            var_a1_9 += 4;
                            (*(s32 *)((char *)(var_a0_9) + 0)) = temp_v0_8;
                            var_v1_6--;
                            var_a0_9 += 4;
                        } while (var_v1_6 != 0);
                    }
                    (*(s16 *)((char *)(var_s2) + 0x34)) = (s16) (((*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC)) * 4) - 1);
                    (*(s16 *)((char *)(var_s2) + 0x4C)) = (s16) ((*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC)) << 5);
                    temp_a0_7 = (*(void **)((char *)(arg3) + 0xC));
                    temp_a0_12 = (var_s4 & 0xFF);
                    (*(s32 *)((char *)(var_s2) + 0x2C)) = (s32) (*(*(s32 **)((char *)(temp_a0_7) + 0x14)) + (temp_a0_12 * (*(u16 *)((char *)(temp_a0_7) + 0xC)) * (*(u16 *)((char *)(temp_a0_7) + 6))));
                    temp_v1_6 = (*(void **)((char *)(arg3) + 0xC));
                    (*(s32 *)((char *)(var_s2) + 0x38)) = (s32) (*(*(s32 **)((char *)(temp_v1_6) + 0x14)) + (temp_a0_12 * (*(u16 *)((char *)(temp_v1_6) + 0xC)) * (*(u16 *)((char *)(temp_v1_6) + 6))));
                    (*(s16 *)((char *)(var_s2) + 0x48)) = (s16) ((held_arg2 + ((var_s4 & 0xFF) * (*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC)))) * 4);
                    gfx_packet_20 = (u32 *)var_s3_4;
                    var_s3_4 += 8;
                    gfx_packet_20[0] = 0x05000017;
                    gfx_packet_20[1] = osVirtualToPhysical((void *)(var_s2 + 0x28));
                    gfx_packet_21 = (u32 *)var_s3_4;
                    var_s3_4 += 8;
                    gfx_packet_21[0] = 0xDC170000;
                    gfx_packet_21[1] = osVirtualToPhysical((*(void **)((char *)(var_s2) + 0x58)));
                    gfx_packet_22 = (u32 *)var_s3_4;
                    var_s3_4 += 8;
                    gfx_packet_22[0] = 0x02000000;
                    gfx_packet_22[1] = osVirtualToPhysical((void *)(var_s2 + 0x40));
                    gfx_packet_23 = (u32 *)var_s3_4;
                    var_s3_4 += 8;
                    gfx_packet_23[0] = 0xE7000000;
                    gfx_packet_23[1] = 0;
                    var_s4 += 1;
                } while ((var_s4 & 0xFF) < ((*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xE)) - 1));
            }
            var_s2 = func_80009E54();
            temp_a0_8 = arg3 + 0x60;
            var_a1_10 = temp_a0_8;
{
if ((var_s2 < (u32)temp_a0_8) & ((u32)arg3 < var_s2)) {
u32 *sptr; u32 *dptr; int words;
sptr = (u32 *)temp_a0_8; dptr = (u32 *)var_s2+24; words=24; do { *--dptr = *--sptr; } while (--words);

} else {
u32 *sptr; u32 *dptr; int words;
sptr = (u32 *)arg3; dptr = (u32 *)var_s2; words=24; do { *dptr++ = *sptr++; } while (--words);

}
}
            temp_v1_7 = (*(void **)((char *)(arg3) + 0xC));
            temp_v1_8 = ((*(u8 *)((char *)(temp_v1_7) + 9)) - (((*(u16 *)((char *)(temp_v1_7) + 0xE)) - 1) * (*(u16 *)((char *)(temp_v1_7) + 0xC)))) & 0xFF;
            (*(s16 *)((char *)(var_s2) + 0x4C)) = (s16) (temp_v1_8 << 5);
            slice_y = ((var_s4 & 0xFF) * (*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC))) * 4;
            (*(s16 *)((char *)(var_s2) + 0x34)) = (s16) ((temp_v1_8 * 4) - 1);
            (*(s16 *)((char *)(var_s2) + 0x48)) = held_arg2 * 4 + slice_y;
            temp_a0_9 = (*(void **)((char *)(arg3) + 0xC));
            temp_a1_4 = (var_s4 & 0xFF);
            (*(s32 *)((char *)(var_s2) + 0x2C)) = (s32) (*(*(s32 **)((char *)(temp_a0_9) + 0x14)) + (temp_a1_4 * (*(u16 *)((char *)(temp_a0_9) + 0xC)) * (*(u16 *)((char *)(temp_a0_9) + 6))));
            temp_v1_9 = (*(void **)((char *)(arg3) + 0xC));
(*(s32 *)((char *)(var_s2) + 0x38)) = *(*(s32 **)((char *)(temp_v1_9) + 0x14)) + (temp_a1_4 * (*(u16 *)((char *)(temp_v1_9) + 0xC)) * (*(u16 *)((char *)(temp_v1_9) + 6)));
last_draw_2_0 = (u32 *)var_s3_4;
var_s3_4 += 8;
last_draw_2_0[0] = 0x05000017;
last_draw_2_0[1] = osVirtualToPhysical((void *)(var_s2 + 0x28));
last_draw_2_1 = (u32 *)var_s3_4;
var_s3_4 += 8;
last_draw_2_1[0] = 0xDC170000;
last_draw_2_1[1] = osVirtualToPhysical((*(void **)((char *)(var_s2) + 0x58)));
last_draw_2_2 = (u32 *)var_s3_4;
var_s3_4 += 8;
last_draw_2_2[0] = 0x02000000;
last_draw_2_2[1] = osVirtualToPhysical((void *)(var_s2 + 0x40));
        }
order_end:
 last_gfx_packet_0=(u32 *)var_s3_4;var_s3_4+=8;last_gfx_packet_0[0]=0xDC170000;last_gfx_packet_0[1]=osVirtualToPhysical(gOrderState+0x20);
    } else {
        temp_a0_10 = (*(void **)((char *)(arg3) + 0xC));
        (*(s16 *)((char *)(arg3) + 0x40)) = (s16) (held_arg1 * 4);
        (*(s16 *)((char *)(arg3) + 0x48)) = (s16) (held_arg2 * 4);
        temp_v1_10 = (*(u16 *)((char *)(temp_a0_10) + 0xE));
        if (temp_v1_10 == 1) {
            var_s2 = func_80009E54();
            temp_a0_11 = arg3 + 0x60;
            var_a3_3 = temp_a0_11;
{
u32 *sptr; u32 *dptr; int words;
if ((var_s2 < (u32)temp_a0_11) & ((u32)arg3 < var_s2)) {
sptr = (u32 *)temp_a0_11; dptr = (u32 *)var_s2+24; words=24; do { *--dptr = *--sptr; } while (--words);

} else {
sptr = (u32 *)arg3; dptr = (u32 *)var_s2; words=24; do { *dptr++ = *sptr++; } while (--words);

}
}
            gfx_packet_24 = (u32 *)var_s3_4;
            var_s3_4 += 8;
            gfx_packet_24[0] = 0x0800002F;
            gfx_packet_24[1] = var_s2 + 0x28;
        } else {
            var_a0_14 = (*(u16 *)((char *)(temp_a0_10) + 4));
            if (var_a0_14 == 0x10) {
                var_s4 = 0;
                if ((s32)(arg4 & 0x20) < (temp_v1_10 - 1)) {
                    temp_s5 = arg3 + 0x60;
                    do {
                        var_s2 = func_80009E54();
                        var_a1_14 = temp_s5;
                        if ((var_s2 < (u32) temp_s5) & ((u32) arg3 < var_s2)) {
                            var_a0_15 = (void *)(var_s2 + 0x60);
                            var_v1_9 = 0x18;
                            do {
                                var_a1_14 -= 4;
                                var_a0_15 -= 4;
                                var_v1_9 -= 1;
                                (*(s32 *)((char *)(var_a0_15) + 0)) = (*(s32 *)((char *)(var_a1_14) + 0));
                            } while (var_v1_9 != 0);
                        } else {
                            var_a1_15 = arg3;
                            var_a0_16 = var_s2;
                            var_v1_10 = 0x18;
                            do {
                                temp_v0_13 = (*(s32 *)((char *)(var_a1_15) + 0));
                                var_a1_15 += 4;
                                var_v1_10 -= 1;
                                (*(s32 *)((char *)(var_a0_16) + 0)) = temp_v0_13;
                                var_a0_16 += 4;
                            } while (var_v1_10 != 0);
                        }
                        (*(s16 *)((char *)(var_s2) + 0x34)) = (s16) (((*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC)) * 4) - 1);
                        (*(s16 *)((char *)(var_s2) + 0x4C)) = (s16) ((*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC)) << 5);
                        temp_a1_5 = (*(void **)((char *)(arg3) + 0xC));
                        temp_a0_12 = (var_s4 & 0xFF);
                        (*(s32 *)((char *)(var_s2) + 0x2C)) = (s32) (*(*(s32 **)((char *)(temp_a1_5) + 0x14)) + ((s32) (temp_a0_12 * (*(u16 *)((char *)(temp_a1_5) + 0xC)) * (*(u16 *)((char *)(temp_a1_5) + 6))) / 2));
                        temp_v1_11 = (*(void **)((char *)(arg3) + 0xC));
                        (*(s32 *)((char *)(var_s2) + 0x38)) = (s32) (*(*(s32 **)((char *)(temp_v1_11) + 0x14)) + ((s32) (temp_a0_12 * (*(u16 *)((char *)(temp_v1_11) + 0xC)) * (*(u16 *)((char *)(temp_v1_11) + 6))) / 2));
                        (*(s16 *)((char *)(var_s2) + 0x48)) = (s16) ((held_arg2 + ((var_s4 & 0xFF) * (*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC)))) * 4);
packet_loop_0_0 = (u32 *)var_s3_4;
var_s3_4 += 8;
packet_loop_0_0[0] = 0x0800002F;
packet_loop_0_0[1] = var_s2+0x28;
packet_loop_0_1 = (u32 *)var_s3_4;
var_s3_4 += 8;
packet_loop_0_1[0] = 0xE7000000;
packet_loop_0_1[1] = 0;

var_s4 += 1;
                    } while ((var_s4 & 0xFF) < ((*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xE)) - 1));
                }
                var_s2 = func_80009E54();
                temp_a0_13 = arg3 + 0x60;
                var_a1_16 = temp_a0_13;
{
if ((var_s2 < (u32)temp_a0_13) & ((u32)arg3 < var_s2)) {
u32 *sptr; u32 *dptr; int words;
sptr = (u32 *)temp_a0_13; dptr = (u32 *)var_s2+24; words=24; do { *--dptr = *--sptr; } while (--words);

} else {
u32 *sptr; u32 *dptr; int words;
sptr = (u32 *)arg3; dptr = (u32 *)var_s2; words=24; do { *dptr++ = *sptr++; } while (--words);

}
}
                temp_v1_12 = (*(void **)((char *)(arg3) + 0xC));
                temp_v1_13 = ((*(u8 *)((char *)(temp_v1_12) + 9)) - (((*(u16 *)((char *)(temp_v1_12) + 0xE)) - 1) * (*(u16 *)((char *)(temp_v1_12) + 0xC)))) & 0xFF;
                (*(s16 *)((char *)(var_s2) + 0x4C)) = (s16) (temp_v1_13 << 5);
            slice_y = ((var_s4 & 0xFF) * (*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC))) * 4;
                (*(s16 *)((char *)(var_s2) + 0x34)) = (s16) ((temp_v1_13 * 4) - 1);
                (*(s16 *)((char *)(var_s2) + 0x48)) = held_arg2 * 4 + slice_y;
                temp_a1_6 = (*(void **)((char *)(arg3) + 0xC));
                temp_a0_14 = (var_s4 & 0xFF);
                (*(s32 *)((char *)(var_s2) + 0x2C)) = (s32) (*(*(s32 **)((char *)(temp_a1_6) + 0x14)) + ((s32) (temp_a0_14 * (*(u16 *)((char *)(temp_a1_6) + 0xC)) * (*(u16 *)((char *)(temp_a1_6) + 6))) / 2));
                temp_v1_14 = (*(void **)((char *)(arg3) + 0xC));
                temp_a1_7 = var_s3_4;
                var_s3_4 += 8;
                (*(s32 *)((char *)(var_s2) + 0x38)) = (s32) (*(*(s32 **)((char *)(temp_v1_14) + 0x14)) + ((s32) (temp_a0_14 * (*(u16 *)((char *)(temp_v1_14) + 0xC)) * (*(u16 *)((char *)(temp_v1_14) + 6))) / 2));
                (*(s32 *)((char *)(temp_a1_7) + 0)) = 0x0800002F;
                (*(s32 *)((char *)(temp_a1_7) + 4)) = (s32) (var_s2 + 0x28);
            } else if (var_a0_14 == 0x100) {
                var_s4 = 0;
                if ((s32)(arg4 & 0x20) < (temp_v1_10 - 1)) {
                    temp_s5 = arg3 + 0x60;
                    do {
                        var_s2 = func_80009E54();
                        var_a1_18 = temp_s5;
{
if ((var_s2 < (u32)temp_s5) & ((u32)arg3 < var_s2)) {
u32 *sptr; u32 *dptr; int words;
sptr = (u32 *)temp_s5; dptr = (u32 *)var_s2+24; words=24; do { *--dptr = *--sptr; } while (--words);

} else {
u32 *sptr; u32 *dptr; int words;
sptr = (u32 *)arg3; dptr = (u32 *)var_s2; words=24; do { *dptr++ = *sptr++; } while (--words);

}
}
                        (*(s16 *)((char *)(var_s2) + 0x34)) = (s16) (((*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC)) * 4) - 1);
                        (*(s16 *)((char *)(var_s2) + 0x4C)) = (s16) ((*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC)) << 5);
                        slice_texture = (*(void **)((char *)(arg3) + 0xC));
                        temp_a0_12 = (var_s4 & 0xFF);
                        (*(s32 *)((char *)(var_s2) + 0x2C)) = (s32) (*(*(s32 **)((char *)(slice_texture) + 0x14)) + (temp_a0_12 * (*(u16 *)((char *)(slice_texture) + 0xC)) * (*(u16 *)((char *)(slice_texture) + 6))));
                        temp_v1_15 = (*(void **)((char *)(arg3) + 0xC));
                        (*(s32 *)((char *)(var_s2) + 0x38)) = (s32) (*(*(s32 **)((char *)(temp_v1_15) + 0x14)) + (temp_a0_12 * (*(u16 *)((char *)(temp_v1_15) + 0xC)) * (*(u16 *)((char *)(temp_v1_15) + 6))));
                        (*(s16 *)((char *)(var_s2) + 0x48)) = (s16) ((held_arg2 + ((var_s4 & 0xFF) * (*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC)))) * 4);
packet_loop_1_0 = (u32 *)var_s3_4;
var_s3_4 += 8;
packet_loop_1_0[0] = 0x0800002F;
packet_loop_1_0[1] = var_s2+0x28;
packet_loop_1_1 = (u32 *)var_s3_4;
var_s3_4 += 8;
packet_loop_1_1[0] = 0xE7000000;
packet_loop_1_1[1] = 0;

var_s4 += 1;
                    } while ((var_s4 & 0xFF) < ((*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xE)) - 1));
                }
                var_s2 = func_80009E54();
                temp_a0_15 = arg3 + 0x60;
                var_a1_20 = temp_a0_15;
{
if ((var_s2 < (u32)temp_a0_15) & ((u32)arg3 < var_s2)) {
u32 *sptr; u32 *dptr; int words;
sptr = (u32 *)temp_a0_15; dptr = (u32 *)var_s2+24; words=24; do { *--dptr = *--sptr; } while (--words);

} else {
u32 *sptr; u32 *dptr; int words;
sptr = (u32 *)arg3; dptr = (u32 *)var_s2; words=24; do { *dptr++ = *sptr++; } while (--words);

}
}
                temp_v1_16 = (*(void **)((char *)(arg3) + 0xC));
                temp_v1_17 = ((*(u8 *)((char *)(temp_v1_16) + 9)) - (((*(u16 *)((char *)(temp_v1_16) + 0xE)) - 1) * (*(u16 *)((char *)(temp_v1_16) + 0xC)))) & 0xFF;
                (*(s16 *)((char *)(var_s2) + 0x4C)) = (s16) (temp_v1_17 << 5);
            slice_y = ((var_s4 & 0xFF) * (*(u16 *)((char *)((*(void **)((char *)(arg3) + 0xC))) + 0xC))) * 4;
                (*(s16 *)((char *)(var_s2) + 0x34)) = (s16) ((temp_v1_17 * 4) - 1);
                (*(s16 *)((char *)(var_s2) + 0x48)) = held_arg2 * 4 + slice_y;
                temp_a0_16 = (*(void **)((char *)(arg3) + 0xC));
                temp_a0_12 = (var_s4 & 0xFF);
                (*(s32 *)((char *)(var_s2) + 0x2C)) = (s32) (*(*(s32 **)((char *)(temp_a0_16) + 0x14)) + (temp_a0_12 * (*(u16 *)((char *)(temp_a0_16) + 0xC)) * (*(u16 *)((char *)(temp_a0_16) + 6))));
                temp_v1_18 = (*(void **)((char *)(arg3) + 0xC));
                temp_a0_17 = var_s3_4;
                var_s3_4 += 8;
                (*(s32 *)((char *)(var_s2) + 0x38)) = (s32) (*(*(s32 **)((char *)(temp_v1_18) + 0x14)) + (temp_a0_12 * (*(u16 *)((char *)(temp_v1_18) + 0xC)) * (*(u16 *)((char *)(temp_v1_18) + 6))));
                (*(s32 *)((char *)(temp_a0_17) + 0)) = 0x0800002F;
                (*(s32 *)((char *)(temp_a0_17) + 4)) = (s32) (var_s2 + 0x28);
            }
        }
    }
    gfx_packet_25 = (u32 *)var_s3_4;
    var_s3_4 += 8;
    gfx_packet_25[0] = 0xE7000000;
    gfx_packet_25[1] = 0;
    gfx_set_dl(temp_v0, var_s3_4);
}
