void func_8001BE68(void*, f32, f32, f32, f32*, f32*, f32*);

/* Tests an axis-aligned box (min/max as s16 pairs in box[0..5]) against the
 * view volume after the transform at mtx+0x80. Returns 0 if all eight corners
 * lie outside the same clip plane, 1 otherwise. */
s32 isBoundingBoxVisible(u8 *mtx, s16 *box) {
    f32 corners[8][3];
    u16 left=0, right=0, bottom=0, top=0, near=0, far=0, inside=0;
    s32 i;
    f32 xmin=-1.02f;
    f32 xmax=1.02f;
    f32 ymin=-1.02f;
    f32 ymax=1.02f;
    f32 zmin=-0.02f;
    f32 zmax=1.02f;
    corners[0][0]=box[0]; corners[0][1]=box[1]; corners[0][2]=box[4];
    corners[1][0]=box[2]; corners[1][1]=box[1]; corners[1][2]=box[4];
    corners[2][0]=box[0]; corners[2][1]=box[3]; corners[2][2]=box[4];
    corners[3][0]=box[0]; corners[3][1]=box[1]; corners[3][2]=box[5];
    corners[4][0]=box[2]; corners[4][1]=box[3]; corners[4][2]=box[4];
    corners[5][0]=box[0]; corners[5][1]=box[3]; corners[5][2]=box[5];
    corners[6][0]=box[2]; corners[6][1]=box[1]; corners[6][2]=box[5];
    corners[7][0]=box[2]; corners[7][1]=box[3]; corners[7][2]=box[5];
    for(i=0;i<8;i++) func_8001BE68(mtx+0x80,corners[i][0],corners[i][1],corners[i][2],&corners[i][0],&corners[i][1],&corners[i][2]);
    for(i=0;i<8;i++) {
        if(corners[i][0]>xmin && corners[i][0]<xmax && corners[i][1]>ymin && corners[i][1]<ymax && corners[i][2]>zmin && corners[i][2]<zmax) { inside++; break; }
        if(corners[i][0]<xmin) left++;
        if(corners[i][0]>xmax) right++;
        if(corners[i][1]<ymin) bottom++;
        if(corners[i][1]>ymax) top++;
        if(corners[i][2]<zmin) near++;
        if(corners[i][2]>zmax) far++;
    }
    if(!inside) {
        if(left==8) return 0;
        else if(right==8) return 0;
        else if(bottom==8) return 0;
        else if(top==8) return 0;
        else if(near==8) return 0;
        else if(far==8) return 0;
    }
    return 1;
}
