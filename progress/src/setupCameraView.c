extern s32 D_800B6AFC;
extern s32 D_8009CE8C[];
extern s32 D_8009CE90[];
extern s32 D_8009CE94[];
extern s32 D_8009CE80;
extern s32 D_8009CE84;
extern s32 D_8009CE88;
extern u8 *g_camera;
void mat3_mul_vec3_q12(void *, void *, void *);
void func_8002DA98(void *, void *);
void buildPoseMatrix(void *, void *);

/* Scratch space for setupCameraView: the camera offset (camPos), the car
 * position plus offset (offset), the car's rotation (rot), and the view matrix
 * (viewMtx) with its translation row (viewTrans). The layout is fixed by the code. */
typedef struct CamScratch
{
  s32 camPos[3];
  s32 pad1C;
  s32 offset[3];
  s32 pad2C;
  f32 rot[8];
  f32 viewMtx[4][4];
  f32 viewTrans[4];
} CamScratch;

/* Builds the camera for car at track segment pathIdx: picks the camera offset
 * (table or default, shifted when the camera flag 0x40 is set), rotates it by
 * the car's orientation, and writes the 4x4 view matrix into cam + 0x40. */
void setupCameraView(u8 *car, u8 *cam, s32 pathIdx)
{
  CamScratch scratch;
  u32 row;
  u32 col;
  s32 x;
  f32 *dst;
  f32 *src;
  u8 *dstRow;
  u8 *srcRow;

  if ((*((u16 *) (g_camera + 0x20))) & 0x80)
  {
    x = *(s32 *)0x800B6AFC;
    *((s32 *) (cam + 0xC0)) = D_8009CE8C[pathIdx * 3];
    *((s32 *) (cam + 0xC4)) = D_8009CE90[pathIdx * 3] + ((x + ((s32) (((u32) x) >> 31))) >> 1);
    *((s32 *) (cam + 0xC8)) = D_8009CE94[pathIdx * 3];
    if ((*((u16 *) (g_camera + 0x20))) & 0x40)
    {
      *((s32 *) (cam + 0xC4)) -= 0x28;
    }
  }
  else
  {
    *((s32 *) (cam + 0xC0)) = D_8009CE80;
    *((s32 *) (cam + 0xC4)) = D_8009CE84;
    *((s32 *) (cam + 0xC0)) = D_8009CE88;
  }
  mat3_mul_vec3_q12(car, cam + 0xC0, scratch.offset);
  func_8002DA98(car, scratch.rot);
  scratch.offset[0] += *((s32 *) (car + 0x14));
  scratch.offset[1] += *((s32 *) (car + 0x18));
  scratch.offset[2] += *((s32 *) (car + 0x1C));
  mat3_mul_vec3_q12(scratch.rot, scratch.offset, scratch.camPos);
  buildPoseMatrix(scratch.viewMtx, scratch.rot);
  row = 0;
  srcRow = (u8 *) scratch.camPos;
  scratch.viewTrans[0] = (f32) (-scratch.camPos[0]);
  scratch.viewTrans[1] = (f32) (-scratch.camPos[1]);
  dstRow = cam;
  scratch.viewTrans[2] = (f32) (-scratch.camPos[2]);
  scratch.viewMtx[3][0] = (f32) (-scratch.camPos[0]);
  scratch.viewMtx[3][1] = (f32) (-scratch.camPos[1]);
  scratch.viewMtx[3][2] = (f32) (-scratch.camPos[2]);
  do
  {
    col = 0;
    dst = (f32 *) (dstRow + 0x40);
    src = (f32 *) (srcRow + 0x40);
    do
    {
      *dst++ = *src++;
      col++;
    } while (col < 4);
    srcRow += 0x10;
    dstRow += 0x10;
    row++;
  } while (row < 4);
}
