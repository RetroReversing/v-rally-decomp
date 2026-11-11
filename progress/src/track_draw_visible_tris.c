typedef struct {u8 pad[0x118];f32 a,b,c;} Ctx;
typedef struct {void *p;u8 pad[2];u8 r,g;u32 n; s32 d;} Obj;
typedef struct {u8 b[2];s16 ss[2];u16 u[3];} Packet;
extern u8 gStreamState[],D_8009F5A0;
extern Ctx *g_camera; extern Obj *g_ent_list;
extern s32 mtx_pool_alloc();
extern void guMtxIdentF(void*);
extern void obj_mtx_visible(void*,void*,void*),update_part_scroll(s16*,s32),gfx_push_mtx(void*,void*);
extern void*gfx_get_dl(void*);
extern void gfx_set_dl(void*,void*),func_800075BC(void*,s32,u8),func_80019C90(void*,void*,void*,u16,u16),func_8001BE68(void*,f32,f32,f32,f32*,f32*,f32*);

/* Draws one layer of track triangles: vertex triples from verts, transformed by
 * the camera matrix; visible triangles are emitted as display-list commands
 * (after a texture/colour setup), culled ones get their marker set to 1001. */
void track_draw_visible_tris(s16 *verts, void *gfx_ctx, s32 layer){
 s16 *tri; u32 *gfx; void *vtx; f32 mtx[16]; Packet tri_pkt; f32 sx,sy,sz; u32 remaining,count,old; s32 first,second,mtx_id,arg_a; u8 r,g;
 mtx_id=mtx_pool_alloc(); guMtxIdentF(mtx); mtx[12]=g_camera->a;mtx[13]=g_camera->b;mtx[14]=g_camera->c;
 obj_mtx_visible((void*)mtx_id,(u8*)g_camera+0x38,mtx); update_part_scroll(verts,layer&255); gfx_push_mtx(gfx_ctx,(void*)mtx_id); gfx=gfx_get_dl(gfx_ctx);
 {u32 *cmd=gfx; Obj *o=g_ent_list;gfx+=2;cmd[0]=0xDE000000;cmd[1]=(u32)&D_8009F5A0;
 {u32 *cmd=gfx;gfx+=2;cmd[0]=0xFB000000;r=o->r;cmd[1]=(r<<24)|(r<<16)|(r<<8)|o->g;}}
 gfx_set_dl(gfx_ctx,gfx); remaining=g_ent_list->n; first=1;second=0; count=(remaining>>1)-1;
 while((old=remaining,remaining--,old!=0)){tri=verts+1; if(remaining==count)second=1;
  func_8001BE68((u8*)g_camera+0xB8,(f32)*verts,(f32)tri[0],(f32)tri[1],&sx,&sy,&sz);
  if(sx<1.0f&&sx>-1.0f&&sy<1.0f&&sy>-1.0f&&sz<1.0f&&sz>-1.0f){
   if(first){vtx=*(void**)((u8*)g_ent_list->p+4);arg_a=*(s32*)vtx;func_800075BC(gfx_ctx,arg_a,*((u8*)tri+4));first=0;}
   else if(second){vtx=*(void**)((u8*)g_ent_list->p+4);arg_a=*(s32*)vtx;second=0;func_800075BC(gfx_ctx,arg_a,*((u8*)tri+4));}
   tri_pkt.b[0]=3;tri_pkt.b[1]=0;tri_pkt.ss[0]=g_ent_list->d*2;tri_pkt.ss[1]=g_ent_list->d*2;tri_pkt.u[0]=*verts;tri_pkt.u[1]=tri[0];tri_pkt.u[2]=tri[1];
   vtx=*(void**)*(void**)((u8*)g_ent_list->p+4); func_80019C90(gfx_ctx,(u8*)g_camera+0x38,&tri_pkt,*(u16*)((u8*)vtx+6),*(u16*)((u8*)vtx+8));
  } else tri[0]=1001; verts+=4;
 }
}
