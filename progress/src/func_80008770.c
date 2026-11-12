typedef struct { s16 x,y,z,w; } __attribute__((packed, aligned(2))) Rect;

typedef struct { unsigned char pad[0x14]; void *p14; } DispCtx;
typedef struct { unsigned char pad0[4]; u16 type; u16 w; u16 h; unsigned char padc[6]; void *p10; void *p14; } Sprite;
typedef struct { u32 a,b; } Gfx;
extern u32 osVirtualToPhysical(void *);
extern Gfx *gsn_dp_load_texture_block(void *,u32,s32,u16,...);
extern Gfx *func_80007F18(void *,u32,s32,s32,...);
/* Emits the RDP command words that draw one sprite rectangle: a fixed header,
   then a texture-rect command for the sprite type (0x10, 0x100 or 0xA0) that
   reads its image and palette from the sprite. Returns 0. */
s32 func_80008770(DispCtx *dl, Sprite *spr, s32 frame, void *src) {
 Rect rect; u32 phys; Gfx *g; u32 p;
 rect=*(Rect*)src;
 { Gfx *d=dl->p14; dl->p14=d+1; d->a=0xD7000002; d->b=0x80008000; }
 { Gfx *d=dl->p14; dl->p14=d+1; d->a=0xE3001201; d->b=0x2000; }
 { Gfx *d=dl->p14; dl->p14=d+1; d->a=0xE3000C00; d->b=0x80000; }
 switch(spr->type) { case 0x10:
  p=osVirtualToPhysical(*(void**)spr->p14);
  g=gsn_dp_load_texture_block(dl->p14,p,2,spr->w,spr->h,rect.x,rect.y,rect.z-1,rect.w-1,0,0,0,0,0,0,0);
  dl->p14=g+1; g->a=0xFD100000;
  #ifdef PORT
  p=osVirtualToPhysical((void *)(uintptr_t)(((u32*)spr->p10)[frame&255])); g->b=p;
#else
  p=osVirtualToPhysical(((u32*)spr->p10)[frame&255]); g->b=p;
#endif
  { Gfx *d=dl->p14; dl->p14=d+1;d->a=0xE8000000;d->b=0; }
  { Gfx *d=dl->p14;dl->p14=d+1;d->a=0xF5000100;d->b=0x7000000; }
  { Gfx *d=dl->p14;dl->p14=d+1;d->a=0xE6000000;d->b=0; }
  { Gfx *d=dl->p14;dl->p14=d+1;d->a=0xF0000000;d->b=0x703C000; }
  { Gfx *d=dl->p14;dl->p14=d+1;d->a=0xE7000000;d->b=0; break; }
 case 0x100:
  p=osVirtualToPhysical(*(void**)spr->p14);
  g=func_80007F18(dl->p14,p,2,1,spr->w,spr->h,rect.x,rect.y,rect.z-1,rect.w-1,0,0,0,0,0,0,0);
  dl->p14=g+1;g->a=0xFD100000;
  #ifdef PORT
  p=osVirtualToPhysical((void *)(uintptr_t)(((u32*)spr->p10)[frame&255])); g->b=p;
#else
  p=osVirtualToPhysical(((u32*)spr->p10)[frame&255]);g->b=p;
#endif
  { Gfx *d=dl->p14;dl->p14=d+1;d->a=0xE8000000;d->b=0; }
  { Gfx *d=dl->p14;dl->p14=d+1;d->a=0xF5000100;d->b=0x7000000; }
  { Gfx *d=dl->p14;dl->p14=d+1;d->a=0xE6000000;d->b=0; }
  { Gfx *d=dl->p14;dl->p14=d+1;d->a=0xF0000000;d->b=0x73FC000; }
  { Gfx *d=dl->p14;dl->p14=d+1;d->a=0xE7000000;d->b=0; break; }
 case 0xA0: {
 Gfx *e;
  p=osVirtualToPhysical(*(void**)spr->p14);
  e=func_80007F18(dl->p14,p,0,3,spr->w,spr->h,rect.x,rect.y,rect.z-1,rect.w-1,0,0,0,0,0,0,0);
  dl->p14=e+1;e->a=0xE3001001;e->b=0; break;
 }
 }
 return 0;
}
