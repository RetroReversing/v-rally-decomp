#include "snapshot29_0433f7af8f6d.h"

typedef struct { s16 x,y,z,w; } __attribute__((packed, aligned(2))) Rect;

typedef struct { unsigned char pad[0x14]; void *p14; } A0;
typedef struct { unsigned char pad0[4]; u16 type; u16 w; u16 h; unsigned char padc[6]; void *p10; void *p14; } A1;
typedef struct { u32 a,b; } Cmd;
extern u32 osVirtualToPhysical(void *);
extern Cmd *func_80008500(void *,u32,s32,u16,...);
extern Cmd *func_80007F18(void *,u32,s32,s32,...);
s32 func_80008770(A0 *a0,A1 *a1,s32 idx,void *src) {
 Rect r; u32 t; Cmd *c; u32 p;
 r=*(Rect*)src;
 { Cmd *d=a0->p14; a0->p14=d+1; d->a=0xD7000002; d->b=0x80008000; }
 { Cmd *d=a0->p14; a0->p14=d+1; d->a=0xE3001201; d->b=0x2000; }
 { Cmd *d=a0->p14; a0->p14=d+1; d->a=0xE3000C00; d->b=0x80000; }
 switch(a1->type) { case 0x10:
  p=osVirtualToPhysical(*(void**)a1->p14);
  c=func_80008500(a0->p14,p,2,a1->w,a1->h,r.x,r.y,r.z-1,r.w-1,0,0,0,0,0,0,0);
  a0->p14=c+1; c->a=0xFD100000;
  p=osVirtualToPhysical(((u32*)a1->p10)[idx&255]); c->b=p;
  { Cmd *d=a0->p14; a0->p14=d+1;d->a=0xE8000000;d->b=0; }
  { Cmd *d=a0->p14;a0->p14=d+1;d->a=0xF5000100;d->b=0x7000000; }
  { Cmd *d=a0->p14;a0->p14=d+1;d->a=0xE6000000;d->b=0; }
  { Cmd *d=a0->p14;a0->p14=d+1;d->a=0xF0000000;d->b=0x703C000; }
  { Cmd *d=a0->p14;a0->p14=d+1;d->a=0xE7000000;d->b=0; break; }
 case 0x100:
  p=osVirtualToPhysical(*(void**)a1->p14);
  c=func_80007F18(a0->p14,p,2,1,a1->w,a1->h,r.x,r.y,r.z-1,r.w-1,0,0,0,0,0,0,0);
  a0->p14=c+1;c->a=0xFD100000;
  p=osVirtualToPhysical(((u32*)a1->p10)[idx&255]);c->b=p;
  { Cmd *d=a0->p14;a0->p14=d+1;d->a=0xE8000000;d->b=0; }
  { Cmd *d=a0->p14;a0->p14=d+1;d->a=0xF5000100;d->b=0x7000000; }
  { Cmd *d=a0->p14;a0->p14=d+1;d->a=0xE6000000;d->b=0; }
  { Cmd *d=a0->p14;a0->p14=d+1;d->a=0xF0000000;d->b=0x73FC000; }
  { Cmd *d=a0->p14;a0->p14=d+1;d->a=0xE7000000;d->b=0; break; }
 case 0xA0: {
 Cmd *e;
  p=osVirtualToPhysical(*(void**)a1->p14);
  e=func_80007F18(a0->p14,p,0,3,a1->w,a1->h,r.x,r.y,r.z-1,r.w-1,0,0,0,0,0,0,0);
  a0->p14=e+1;e->a=0xE3001001;e->b=0; break;
 }
 }
 return 0;
}
