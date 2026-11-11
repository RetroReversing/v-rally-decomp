s32 setupCameraProjection(void *a, void *b, s32 c, s32 d);
s32 updateCameraTarget(void *a);
extern u8 *g_camera;

typedef struct {
    s32 w[4];
} Block16;

/* Refreshes the camera (projection from the viewport, then the target update), and
 * copies its state block (camera +0x38 to +0x178) into dst_cam. */
void camera_refresh_and_copy(u8 *dst_cam, void *viewport) {
    Block16 *src;
    Block16 *end;
    Block16 *dst;

    setupCameraProjection(g_camera + 0x38, viewport, *(s32 *)(*(u8 **)(g_camera + 0x178) + 0x3C), *(s32 *)(*(u8 **)(g_camera + 0x178) + 0x40));
    updateCameraTarget(g_camera);
    dst = (Block16 *)(dst_cam + 0x38);
    src = (Block16 *)(g_camera + 0x38);
    end = (Block16 *)(g_camera + 0x178);
    do {
        *dst++ = *src++;
    } while (src != end);
}
