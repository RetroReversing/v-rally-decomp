extern f32 D_8009BB94,D_8009BB98,D_8009BB9C,D_8009BBA0;

extern u8 g_dark_mode;
extern u8 *g_camera;

void setupCameraProjection(void *,s32,f32,f32);
void updateCameraTarget(void *);

typedef struct {s32 words[80];
} CameraBlock;

/* Refreshes the camera for the current dark-mode setting: picks the near and far
 * scale pair, rebuilds the projection from the viewport, updates the camera target,
 * then copies the 320-byte camera block into dst. */
void updateCameraView(u8 *dst) {
u8 *cam=g_camera;

s32 viewport=*(s32 *)(cam+0x178);

void *camBlock=cam+0x38;

f32 near=0.0f,far=0.0f;

switch(g_dark_mode) {
case 0:
near=D_8009BB94;
far=D_8009BB9C;
break;

case 1:
near=D_8009BB94;
far=D_8009BBA0;
break;

case 2:case 3:
near=D_8009BB98;
far=D_8009BBA0;
break;

}
setupCameraProjection(camBlock,viewport+8,near,far);

updateCameraTarget(g_camera);

*(CameraBlock *)(dst+0x38)=*(CameraBlock *)(g_camera+0x38);

}
