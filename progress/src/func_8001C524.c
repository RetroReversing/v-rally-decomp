extern void *gMirrorListHead;
extern s32 gCarList;
extern char gOrderState[];
extern char gStreamState[];
s32 func_8001C444();
s32 func_80022ED8();
s32 func_800230C0();
s32 StreamListClaimAny();
s32 claimLowestFreeSlot();
s32 mat3_mul_vec3_q12();

/* Copies the car's two 3-word position/velocity blocks, refreshes the physics state, then runs the car's update step. */
void func_8001C524(void *car) {
    s32 pos[3];
    s32 vel[3];
    u32 i;
    void *state;
    void *ctrl;
    s32 result;

    state = gMirrorListHead;
    i = 0;
    do {
        pos[i] = *(s32 *)((char *)car + 0x90 + i * 0x4C);
        i++;
    } while (i < 3U);
    i = 0;
    do {
        vel[i] = *(s32 *)((char *)car + 0x174 + i * 0x4C);
        i++;
    } while (i < 3U);
    if (*(s32 *)((char *)car + 0x258) == 0) {
        mat3_mul_vec3_q12((char *)state + 0x10, pos, pos);
        vel[0] = *(s16 *)((char *)state + 0x14);
        result = func_8001C444(pos, state);
        vel[1] = result;
        vel[2] = *(s16 *)((char *)state + 0x20);
    }
    ctrl = *(void **)(gStreamState + 0x32F2);
    if ((((*(u16 *)((char *)ctrl + 0x1E) != 0) & (*(u16 *)((char *)ctrl + 0x1E) < 5)) || *(u16 *)((char *)ctrl + 0x1E) == 5) && *(u16 *)((char *)ctrl + 0x22) != 0 || *(u16 *)(*(char **)(gStreamState + 0x32F2) + 0x1E) == 8) {
        result = claimLowestFreeSlot(gCarList, ctrl);
    } else {
        result = StreamListClaimAny(gCarList, ctrl);
    }
    if (result != 0) {
        func_800230C0(result, pos, vel);
        func_80022ED8(result);
    }
}
