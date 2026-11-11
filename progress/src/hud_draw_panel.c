typedef struct { u8 pad[0x14]; void *p14; } A0;
typedef struct { u8 pad48[0x48]; struct { s32 x[5]; } *p48; s32 pad4c; s32 *p50; u8 pad88[0x34]; void *p88; } A1;
typedef struct { u8 pad110[0x110]; f32 x110; u8 pad114[4]; f32 x118; } A2;
extern s32 gShadeMode; extern void *D_800A1240; extern u8 D_800A12C0;
extern void *gfx_get_dl(s32); extern void gfx_set_dl(s32,void*);
extern void func_800075BC(s32,s32,s32); extern void func_80051994(s32, A2*, u16*, s32);
typedef struct {u32 w0,w1;} G;

/* Builds the display-list commands for one HUD panel: a fill colour, then a set of
 * textured quads whose corner coordinates come from the panel record. Which quads
 * are drawn depends on the panel's mode (gShadeMode) and on the timing values in
 * hud->p48 and hud->p50. */
void hud_draw_panel(s32 gfxCtx,A1 *hud,A2 *vtx,u32 alpha){
 u16 coords[6]; u8 *rec; s32 tex; s32 alphaWord; G *dl;
 alpha = alpha & 255;
 alpha &= 255;
 if(D_800A1240){
  rec=(u8*)*(void**)((u8*)hud->p88+0x7c); dl=gfx_get_dl(gfxCtx);
  { G *p=dl++; p->w0=0xde000000; p->w1=(u32)&D_800A12C0;}
  { G *p=dl++; alphaWord=alpha|~255; p->w0=0xfa000000; p->w1=alphaWord;}
  gfx_set_dl(gfxCtx,dl);
  if(gShadeMode==2){
   tex=*(s32*)((u8*)*(void**)((u8*)D_800A1240+4)+4); func_800075BC(gfxCtx,tex,0);
   coords[1]=*(u16*)(rec+0x10);coords[2]=*(u16*)(rec+0x16);coords[3]=*(u16*)rec;coords[4]=*(u16*)(rec+2);coords[5]=*(u16*)(rec+4);
   func_80051994(gfxCtx,vtx,coords,tex);coords[3]=-(s16)*(u16*)rec;func_80051994(gfxCtx,vtx,coords,tex);
   dl=gfx_get_dl(gfxCtx);
   if(hud->p48->x[4]<0x78 || *hud->p50==0){{ G *p=dl++; p->w0=0xfa000000;p->w1=(alpha>>1)|~255;}}else{{ G *p=dl++;p->w0=0xfa000000;p->w1=alphaWord;}}
   gfx_set_dl(gfxCtx,dl);
   if(gShadeMode==2) goto L2;
  }
  if(hud->p48->x[4]>=0x79 && *hud->p50){
L2: tex=*(s32*)((u8*)*(void**)((u8*)D_800A1240+4)+8);func_800075BC(gfxCtx,tex,0);
   coords[1]=*(u16*)(rec+0x12);coords[2]=*(u16*)(rec+0x18);coords[3]=*(u16*)(rec+8);coords[4]=*(u16*)(rec+10);coords[5]=*(u16*)(rec+12);
   func_80051994(gfxCtx,vtx,coords,tex);coords[3]=-(s16)*(u16*)(rec+8);func_80051994(gfxCtx,vtx,coords,tex);
   dl=gfx_get_dl(gfxCtx);{ G *p=dl++;p->w0=0xfa000000;p->w1=alpha|~255;}gfx_set_dl(gfxCtx,dl);
  }
  if(*hud->p50==0){tex=*(s32*)((u8*)*(void**)((u8*)D_800A1240+4)+12);func_800075BC(gfxCtx,tex,0);
   coords[1]=*(u16*)(rec+0x14);coords[2]=*(u16*)(rec+0x1a);coords[3]=*(u16*)(rec+0x1c);coords[4]=*(u16*)(rec+0x1e);coords[5]=*(u16*)(rec+0xc);
   func_80051994(gfxCtx,vtx,coords,tex);coords[3]=-(s16)*(u16*)(rec+0x1c);func_80051994(gfxCtx,vtx,coords,tex);
  }
 }
}
