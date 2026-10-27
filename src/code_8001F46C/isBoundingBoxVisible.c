#include "common.h"

void func_8001BE68(void*, f32, f32, f32, f32*, f32*, f32*);
s32 isBoundingBoxVisible(u8 *arg0, s16 *b) {
    f32 p[8][3];
    u16 left=0, right=0, bottom=0, top=0, near=0, far=0, inside=0;
    s32 i;
    f32 xmin=-1.02f;
    f32 xmax=1.02f;
    f32 ymin=-1.02f;
    f32 ymax=1.02f;
    f32 zmin=-0.02f;
    f32 zmax=1.02f;
    p[0][0]=b[0]; p[0][1]=b[1]; p[0][2]=b[4];
    p[1][0]=b[2]; p[1][1]=b[1]; p[1][2]=b[4];
    p[2][0]=b[0]; p[2][1]=b[3]; p[2][2]=b[4];
    p[3][0]=b[0]; p[3][1]=b[1]; p[3][2]=b[5];
    p[4][0]=b[2]; p[4][1]=b[3]; p[4][2]=b[4];
    p[5][0]=b[0]; p[5][1]=b[3]; p[5][2]=b[5];
    p[6][0]=b[2]; p[6][1]=b[1]; p[6][2]=b[5];
    p[7][0]=b[2]; p[7][1]=b[3]; p[7][2]=b[5];
    for(i=0;i<8;i++) func_8001BE68(arg0+0x80,p[i][0],p[i][1],p[i][2],&p[i][0],&p[i][1],&p[i][2]);
    for(i=0;i<8;i++) {
        if(p[i][0]>xmin && p[i][0]<xmax && p[i][1]>ymin && p[i][1]<ymax && p[i][2]>zmin && p[i][2]<zmax) { inside++; break; }
        if(p[i][0]<xmin) left++;
        if(p[i][0]>xmax) right++;
        if(p[i][1]<ymin) bottom++;
        if(p[i][1]>ymax) top++;
        if(p[i][2]<zmin) near++;
        if(p[i][2]>zmax) far++;
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
