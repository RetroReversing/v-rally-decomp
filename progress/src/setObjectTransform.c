void mat3_set_identity(void *);
void mat3_set_current(void *);
void order_state_store_translation(void *);
void setYRotationMatrix(void *, void *);
void scaleMatrixByVec(void *, void *);
void object_transform_tail(void *, void *, void *);

/* Sets up an object's transform: a Y rotation for `yaw`, scaled by (scaleXZ, 0x1000, scaleXZ),
 * made current, then the position (posX, 0, posZ) is passed on with the scale to object_transform_tail. */
void setObjectTransform(void *yaw, s16 posX, s16 posZ, s32 *scale, s16 scaleXZ) {
    s32 mtx[8];
    s16 pos[3];
    u32 out;

    mat3_set_identity(mtx);
    setYRotationMatrix(yaw, mtx);
    mtx[5] = 0;
    mtx[6] = 0;
    mtx[7] = 0;
    order_state_store_translation(mtx);
    scale[1] = 0x1000;
    scale[0] = scaleXZ;
    scale[2] = scaleXZ;
    scaleMatrixByVec(mtx, scale);
    mat3_set_current(mtx);
    pos[0] = posX;
    pos[1] = 0;
    pos[2] = posZ;
    object_transform_tail(pos, scale, &out);
}
