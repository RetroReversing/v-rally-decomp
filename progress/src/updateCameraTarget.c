extern u8 stream_state[];

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Quad;

void setupCameraView(s16 *arg0, u8 *arg1, s32 arg2, u8 *arg3);

/* Per-frame camera update for an object: if it has a camera target, copies the
   target's negated offset block and hands it to setupCameraView; otherwise clears
   the target's camera flag. */
void updateCameraTarget(u8 *owner) {
    s32 corners[8];
    u8 *target;
    u8 *src;
    u8 *view;
    u8 *cam_state;
    s32 view_arg;

    target = *(u8 **)(owner + 0x24);
    if (target != NULL) {
        if (*(u32 *)(owner + 0x20) & 0x880000) {
            cam_state = *(u8 **)(target + 0x88);
            view = *(u8 **)(stream_state + 0x32F2);
            *(s32 *)(cam_state + 0x78) = 1;
            if (*(u16 *)(view + 0x1E) == 7) {
                view_arg = 0;
            } else {
                view_arg = **(s32 **)(target + 0x48);
            }
            if (*(u16 *)(*(u8 **)(stream_state + 0x7CD6) + 0x20) & 0x40) {
                setupCameraView((s16 *)(*(u8 **)(target + 0x5C) + 0x40), owner + 0x38, view_arg, target);
                return;
            }
            src = *(u8 **)(target + 0x5C);
            *(Quad *)&corners[0] = *(Quad *)(src + 0x40);
            *(Quad *)&corners[4] = *(Quad *)(src + 0x50);
            *(s16 *)((u8 *)corners + 0x0) = -*(u16 *)(*(u8 **)(target + 0x5C) + 0x40);
            *(s16 *)((u8 *)corners + 0x6) = -*(u16 *)(*(u8 **)(target + 0x5C) + 0x46);
            *(s16 *)((u8 *)corners + 0xC) = -*(u16 *)(*(u8 **)(target + 0x5C) + 0x4C);
            *(s16 *)((u8 *)corners + 0x4) = -*(u16 *)(*(u8 **)(target + 0x5C) + 0x44);
            *(s16 *)((u8 *)corners + 0xA) = -*(u16 *)(*(u8 **)(target + 0x5C) + 0x4A);
            *(s16 *)((u8 *)corners + 0x10) = -*(u16 *)(*(u8 **)(target + 0x5C) + 0x50);
            setupCameraView((s16 *)corners, owner + 0x38, view_arg, target);
            return;
        }
        *(s32 *)(*(u8 **)(target + 0x88) + 0x78) = 0;
    }
}
