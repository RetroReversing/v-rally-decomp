void func_8001FB4C(void *);
void mat3_set_current(void *);
void func_8002D9D8(void *);
void setYRotationMatrix(void *, void *);
void scaleMatrixByVec(void *, void *);
void func_8002E654(void *, void *, void *);

/* Sets up an object's transform: a Y rotation for `yaw`, scaled by (scaleXZ, 0x1000, scaleXZ),
 * made current, then the position (posX, 0, posZ) is passed on with the scale to func_8002E654. */
void setObjectTransform(void *yaw, s16 posX, s16 posZ, s32 *scale, s16 scaleXZ) {
    s32 mtx[8];
    s16 pos[3];
    u32 out;

    func_8001FB4C(mtx);
    setYRotationMatrix(yaw, mtx);
    mtx[5] = 0;
    mtx[6] = 0;
    mtx[7] = 0;
    func_8002D9D8(mtx);
    scale[1] = 0x1000;
    scale[0] = scaleXZ;
    scale[2] = scaleXZ;
    scaleMatrixByVec(mtx, scale);
    mat3_set_current(mtx);
    pos[0] = posX;
    pos[1] = 0;
    pos[2] = posZ;
    func_8002E654(pos, scale, &out);
}
