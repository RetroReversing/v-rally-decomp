#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

typedef struct Cursor { s16 marker; u16 position; } Cursor;
extern Cursor D_800ADFDC;
extern int D_800AE44C;
extern float gSpeedAccum;

s32 MapTypeCode();
s32 func_80038A8C();
s32 start_track_voices();
s32 voicesSetIdleParams();
s32 voicesSetIdleValue();
extern s32 gPadFlags;
extern s32 gRaceFlags;
extern char D_800A73E0[];
extern char gOrderState[];
extern char gStreamState[];

/* Advances the car's place in the race order when it reaches the next marker.
 * The car is ranked among the others by its progress counter; if it leads the
 * rest it bumps its position, and when it is the last car across the finish
 * it raises the end-of-race sound and clears the pending sound flags. */
void car_race_position_update(void *src, s32 arg1, void *car) {
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_v1;
    int allBehind;
    u16 temp_v0;
    u16 limit;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_6;
    void *temp_a1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *other;
    void *var_s1;
    void *var_s2;

    var_s1 = car;
    if (!(gPadFlags & 0x800)) {
        temp_a1 = *(void * *)((char *)var_s1 + 0x70);
        var_s2 = src;
        temp_v1 = *(s32 *)((char *)temp_a1 + 0x28);
        if (temp_v1 == *(u16 *)((char *)var_s2 + 0)) {
            *(s32 *)((char *)temp_a1 + 0x28) = (s32) (temp_v1 + 1);
            temp_a0 = *(void * *)((char *)var_s1 + 0x70);
            if (*(s32 *)((char *)temp_a0 + 0x28) == D_800ADFDC.marker) {
                *(s32 *)((char *)temp_a0 + 0x28) = 0;
            }
            temp_v0 = M2C_FIELD(*(void * *)(gStreamState + 0x32F2), u16 *, 0x1E);
            if ((temp_v0 != 0) & (temp_v0 != 5)) {
                temp_v1_2 = *(void * *)((char *)var_s1 + 0x6C);
                M2C_FIELD(((*(u16 *)((char *)var_s2 + 0) * 4) + *(s32 *)((char *)temp_v1_2 + 0x18)), s32 *, -4) = (s32) *(s32 *)((char *)temp_v1_2 + 4);
                if (((u16) M2C_FIELD(*(void * *)(gStreamState + 0x32F2), u16 *, 0xE) >= 2U) && (M2C_FIELD(*(void * *)((char *)var_s1 + 0x48), s32 *, 0) < 4)) {
                    other = **(void ** *)(gOrderState + 0x73F0);
                    allBehind = 1;
                    limit = (u16) M2C_FIELD(*(void * *)((char *)var_s1 + 0x6C), u16 *, 0xA);
                    if (other != NULL) {
                        do {
                            if ((**(s32 * *)((char *)other + 0x48) < 4) & ((s32) other != var_s1)) {
                                allBehind &= -((u16) M2C_FIELD(*(void * *)((char *)other + 0x6C), u16 *, 0xA) >= limit);
                            }
                            other = *(void * *)((char *)other + 4);
                        } while ((other != NULL) & ((allBehind & 0xFF) != 0));
                    }
                    if (allBehind & 0xFF) {
                        temp_a0_2 = *(void * *)((char *)var_s1 + 0x6C);
                        *(s32 *)((char *)temp_a0_2 + 0x10) += *(u16 *)((char *)var_s2 + 2);
                        temp_v1_3 = *(void * *)((char *)var_s1 + 0x6C);
                        if (*(s32 *)((char *)temp_v1_3 + 0x10) >= 0x64) {
                            *(s32 *)((char *)temp_v1_3 + 0x10) = 0x63;
                        }
                        other = **(void ** *)(gOrderState + 0x73F0);
                        if (other != NULL) {
                            register var_s2 = (void *)-0x201;
                            do {
                                if ((M2C_FIELD(*(void * *)((char *)other + 0x48), s32 *, 0) < 4) & (other != (s32) var_s1)) {
                                    M2C_FIELD(*(void * *)((char *)other + 0x6C), s32 *, 0x10) = (s32) M2C_FIELD(*(void * *)((char *)var_s1 + 0x6C), s32 *, 0x10);
                                    temp_a0_3 = *(s32 *)((char *)other + 0x14);
                                    if (temp_a0_3 & 0x200) {
                                        void *obj = *(void **)((char *)other + 0x48);
                                        *(s32 *)((char *)other + 0x14) = (s32) (temp_a0_3 & ~0x200);
                                        D_800AE44C = 0;
                                        M2C_FIELD(*(void * *)((char *)other + 0x48), s32 *, 0x20) = (s32) (MapTypeCode(M2C_FIELD(obj, u16 *, 2)) & 0xFFFF);
                                    }
                                }
                                other = *(void * *)((char *)other + 4);
                            } while (other != NULL);
                        }
                        temp_a0_4 = *(s32 *)((char *)var_s1 + 0x14);
                        if (temp_a0_4 & 0x200) {
                            void *obj = *(void **)((char *)var_s1 + 0x48);
                            *(s32 *)((char *)var_s1 + 0x14) = (s32) (temp_a0_4 & ~0x200);
                            D_800AE44C = 0;
                            M2C_FIELD(*(void * *)((char *)var_s1 + 0x48), s32 *, 0x20) = (s32) (MapTypeCode(M2C_FIELD(obj, u16 *, 2)) & 0xFFFF);
                        }
                        goto block_27;
                    }
                } else {
                    temp_a0_5 = *(s32 *)((char *)var_s1 + 0x14);
                    if (temp_a0_5 & 0x200) {
                        void *obj=*(void **)((char *)var_s1+0x48);
                        *(s32 *)((char *)var_s1 + 0x14) = (s32) (temp_a0_5 & ~0x200);
                        D_800AE44C = 0;
                        M2C_FIELD(*(void * *)((char *)var_s1 + 0x48), s32 *, 0x20) = (s32) (MapTypeCode(M2C_FIELD(obj, u16 *, 2)) & 0xFFFF);
                    }
                    temp_a0_6 = *(void * *)((char *)var_s1 + 0x6C);
                    *(s32 *)((char *)temp_a0_6 + 0x10) += *(u16 *)((char *)var_s2 + 2);
                    temp_v1_4 = *(void * *)((char *)var_s1 + 0x6C);
                    if (*(s32 *)((char *)temp_v1_4 + 0x10) >= 0x64) {
                        *(s32 *)((char *)temp_v1_4 + 0x10) = 0x63;
                    }
block_27:
                    if (M2C_FIELD(*(void * *)((char *)var_s1 + 0x48), s32 *, 0) < 4) {
                        voicesSetIdleParams(1);
                        gRaceFlags &= ~0x10;
                        func_80038A8C(0x14);
                        start_track_voices(gStreamState + 0x6C6A);
                        voicesSetIdleValue((s32) (gSpeedAccum * 80.0f));
                    }
                }
            }
        }
    }
}
