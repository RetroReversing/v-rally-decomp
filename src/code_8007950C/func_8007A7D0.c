#include "snapshot29_0433f7af8f6d.h"

typedef struct Obj { struct Obj *next; u16 id,x,y; u8 a,b,c,d,e; u8 padf; f32 sx,sy; u8 pad18[2]; u8 active; } Obj;
typedef struct { u8 pad[0x1e4]; void *p; u8 pad2[0x4f]; u8 mode; u8 pad3[0x11]; u8 flag; } State;
typedef struct { u8 pad[6]; u16 x,y; } Dim;
typedef struct { Dim *d; } DimPtr;
typedef struct { u8 pad[4]; DimPtr *p; } World;
extern State *D_800A1468; extern s32 D_800D05D8;
extern Obj *func_800592D0(s32); extern void func_8007A6D0(void);
extern s32 func_8004CEB4(s32, void*, u16*, s32,s32,s32,s32,s32,s32);
void func_8007A7D0(void) {
 u16 p[4]; Obj *o,*q; u8 i; World *w;
 if (!D_800A1468->p) func_8007A6D0();
 o=func_800592D0(0x31); i=0;
 do { o->active=1; o->id=(u16)(i+(D_800A1468->mode*7+0x23e)); o=o->next; i++; } while ((u8)i<7);
 if (D_800A1468->flag) {
  o=func_800592D0(D_800A1468->mode+2); q=func_800592D0(0x39);
  q->x=o->x;q->y=o->y;q->b=o->b;q->c=o->c;q->d=o->d;q->e=o->e;
  q->sx=o->sx;q->sy=o->sy;q->a=o->a;q->id=o->id;
  o=func_800592D0(D_800A1468->mode+0x16); w=(World*)D_800A1468->p;
  p[0]=o->x;p[1]=o->y;
  p[2]=(s16)((f32)w->p->d->x*o->sx); p[3]=(s16)((f32)w->p->d->y*o->sy);
  func_8004CEB4(D_800D05D8,((World*)D_800A1468->p)->p->d,p,0,o->b,o->c,o->d,o->e,0);
 }
}
