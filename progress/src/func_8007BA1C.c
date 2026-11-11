extern s32 D_800A1860;
extern s32 D_800A1864;
extern s32 D_800A1868;
extern s32 D_800A186C;
extern s32 D_800A1870;
extern s32 D_800A1874;
extern f32 sSavedCosX;
extern f32 sSavedCosY;
extern u8 D_800A73E0[];
extern u8 gOrderState[];
extern u8 gStreamState[];
s32 func_8002DA98(u8 *arg0, s32 *arg1);
void *mtx3_transform_vec3(void *, void *, void *);
f32 sqrtf(f32);
#define ORG(i) (((s32 *)(gOrderState + 0x6E8C))[i])
#define G(i) (((s32 *)(gStreamState + 0x5D32))[i])
#define GF(i) (((f32 *)(gStreamState + 0x5D32))[i])

/* Checks whether the object at arg0 sits inside the cone of the two stored
 * track lines. Both line ends are rotated into the camera frame, the line
 * direction is normalised, and the object's direction is compared with the
 * two cone limits. Returns the table value for the cone, or 0xFF outside it. */
u8 func_8007BA1C(u8 *arg0)
{
  s16 objPos[3];
  s16 lineA[3];
  s16 lineB[3];
  s32 rot[8];
  f32 dirX, dirY, dirZ, len, s;
  f32 relX, relY, relZ, len2, dot;
  s32 r;

  func_8002DA98(gOrderState + 0x6E78, rot);
  lineA[0] = D_800A1860 - ORG(0);
  lineA[1] = D_800A1864 - ORG(1);
  lineA[2] = D_800A1868 - ORG(2);
  mtx3_transform_vec3(rot, lineA, lineA);
  lineB[0] = D_800A186C - ORG(0);
  lineB[1] = D_800A1870 - ORG(1);
  lineB[2] = D_800A1874 - ORG(2);
  mtx3_transform_vec3(rot, lineB, lineB);
  dirX = lineA[0] - lineB[0];
  dirY = lineA[1] - lineB[1];
  dirZ = lineA[2] - lineB[2];
  s = dirX * dirX;
  s += dirY * dirY;
  s += dirZ * dirZ;
  len = sqrtf(s);
  dirX /= len;
  dirY /= len;
  dirZ /= len;
  G(0) = lineA[0];
  G(1) = lineA[1];
  G(2) = lineA[2];
  G(3) = lineB[0];
  G(4) = lineB[1];
  G(5) = lineB[2];
  GF(6) = sSavedCosX;
  GF(7) = sSavedCosY;
  objPos[0] = ((s32 *)(*(u8 **)(arg0 + 0x5C) + 0x54))[0] - ORG(0);
  objPos[1] = ((s32 *)(*(u8 **)(arg0 + 0x5C) + 0x54))[1] - ORG(1);
  objPos[2] = ((s32 *)(*(u8 **)(arg0 + 0x5C) + 0x54))[2] - ORG(2);
  mtx3_transform_vec3(rot, objPos, objPos);
  relX = G(0) - objPos[0];
  relY = G(1) - objPos[1];
  r = G(2) - objPos[2];
  relZ = r;
  s = relX * relX;
  s += relY * relY;
  s += relZ * relZ;
  len2 = sqrtf(s);
  relX /= len2;
  relY /= len2;
  relZ /= len2;
  dot = relX * dirX;
  dot += relY * dirY;
  dot += relZ * dirZ;
  r = 0xFF;
  if (!(GF(6) < dot) && !(GF(7) < dot)) {
    r = D_800A73E0[0x6BE7];
  }
  return r;
}
