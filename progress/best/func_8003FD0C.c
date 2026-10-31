typedef struct R {u8 pad[8]; u16 x,y,w,h;} R;
typedef struct O {u8 pad[0x178]; R *r;} O;
extern u8 D_800C02AE[];
O *func_8004240C();
void func_8000EF0C();
#define OBJ (*(O **)(D_800C02AE+0x7cd6))
#define STATE (*(u8 **)(D_800C02AE+0x32f2))
void func_8003FD0C(s32 arg0) {
 s16 rect[4]; s8 color[4]; s32 id; R *r;
 color[0]=0; color[1]=0; color[2]=0; color[3]=255;
 if (*(u16 *)(STATE+14)==2) {
 id=6; if (!(arg0&255)) id=5;
 OBJ=func_8004240C(id);
 if (*(u16 *)(STATE+18)&1) {
 rect[0]=OBJ->r->x+32;
 r=OBJ->r; rect[1]=r->y+(s16)r->h/2-1;
 rect[2]=OBJ->r->w-32;
 r=OBJ->r; rect[3]=r->y+(s16)r->h/2+1;
 OBJ=func_8004240C(5);
 func_8000EF0C(OBJ->r,rect);
 r=OBJ->r; rect[0]=r->x+r->w-32;
 rect[1]=OBJ->r->y;
 r=OBJ->r; rect[2]=r->x+r->w-16;
 rect[3]=OBJ->r->h; } else {
 r=OBJ->r; rect[0]=r->x+(s16)r->w/2-1;
 rect[1]=OBJ->r->y;
 r=OBJ->r; rect[2]=r->x+(s16)r->w/2+1;
 rect[3]=OBJ->r->h;
 }
 func_8000EF0C(OBJ->r,rect,color);
 }
}
