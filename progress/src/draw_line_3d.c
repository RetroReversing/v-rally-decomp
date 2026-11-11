extern f32 func_8001BE68(void *,f32,f32,f32,f32*,f32*,f32*);
extern void draw_screen_line(s32,s32,s32,s32,s32);
extern s32 gOrderState;

/* Projects both ends of a 3D line (start point and start + offset) to the
 * 320x240 screen through the camera at gOrderState+0x72B0, then draws the
 * screen-space line in colour 0xFFC1FFC1. */
void draw_line_3d(s32 arg0, s32 *start, s32 *offset) {
    f32 sx, sy, sz, ex, ey, ez;
    f32 x1, y1, z1, x2, y2, z2;
    s32 sx1, sy1, sx2, sy2;

    x1 = (f32)start[0];
    y1 = (f32)start[1];
    z1 = (f32)start[2];
    x2 = (f32)offset[0] + x1;
    y2 = (f32)offset[1] + y1;
    z2 = (f32)offset[2] + z1;
    func_8001BE68((u8*)&gOrderState + 0x72B0, x1, y1, z1, &sx, &sy, &sz);
    func_8001BE68((u8*)&gOrderState + 0x72B0, x2, y2, z2, &ex, &ey, &ez);
    sx1 = (s32)(sx * 160.0f + 160.0f);
    sy1 = (s32)(-sy * 120.0f + 120.0f);
    sx2 = (s32)(ex * 160.0f + 160.0f);
    sy2 = (s32)(-ey * 120.0f + 120.0f);
    draw_screen_line(sx1, sy1, sx2, sy2, 0xFFC1FFC1);
}
