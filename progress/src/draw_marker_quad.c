extern u8 *g_camera; extern s32 D_800A02C8;
s32 view_get_ctx_id(s32); void *gfx_get_dl(s32); void gfx_set_dl(); void gfx_push_mtx(s32,s32);
void gfx_set_quad_pos(s32,s32,s16,s16,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
s32 gfx_add_quad_tris(s32); void gfx_set_quad_color(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
s32 obj_mtx_visible(s32,void*,void*); s32 mtx_pool_alloc(void); void mtx_init_translate(void*,s32);

/* Draws one track marker: when the active track entry is flagged, builds its pose matrix,
 * calls the marker display list, pushes the matrix and emits a red/blue quad from the
 * entry's 12 corner values (in the gfx command buffer). Skips the marker when not visible. */
void draw_marker_quad(void){
    u16 corner[12]; u8 pos_mtx[64];
    s32 vtx,slot,gfx;
    u32 *dl; u8 *obj; s32 *track;
    gfx=view_get_ctx_id(*(s32 *)(g_camera+0x178));
    obj=*(u8 **)(g_camera+0x24);track=*(s32 **)(obj+0x9C);
    if(!track[14])return;
    corner[0]=track[0];
    corner[1]=(*(s32 * volatile *)(obj+0x9C))[1];
    corner[2]=(*(s32 * volatile *)(obj+0x9C))[2];
    corner[3]=(*(s32 * volatile *)(obj+0x9C))[3];
    corner[4]=(*(s32 * volatile *)(obj+0x9C))[4];
    corner[5]=(*(s32 * volatile *)(obj+0x9C))[5];
    corner[6]=(*(s32 * volatile *)(obj+0x9C))[6];
    corner[7]=(*(s32 * volatile *)(obj+0x9C))[7];
    corner[8]=(*(s32 * volatile *)(obj+0x9C))[8];
    corner[9]=(*(s32 * volatile *)(obj+0x9C))[9];
    corner[10]=(*(s32 * volatile *)(obj+0x9C))[10];
    corner[11]=(*(s32 * volatile *)(obj+0x9C))[11];
    slot=**(s32 **)(obj+0x8C);
    dl=gfx_get_dl(gfx);
#ifdef PORT
    { uintptr_t *cmd=(uintptr_t *)dl; dl+=4; cmd[0]=0x06000000; cmd[1]=(uintptr_t)&D_800A02C8; }
#else
    { u32 *cmd=dl; dl+=2; cmd[0]=0x06000000; cmd[1]=(u32)&D_800A02C8; }
#endif
#ifdef PORT
    { uintptr_t *cmd=(uintptr_t *)dl; dl+=4; cmd[0]=0xFA000000; cmd[1]=0xC8C8C800; }
#else
    { u32 *cmd=dl; dl+=2; cmd[0]=0xFA000000; cmd[1]=0xC8C8C800; }
#endif
    gfx_set_dl(gfx,dl);
    mtx_init_translate(pos_mtx,slot+16);
    slot=mtx_pool_alloc();
    if((obj_mtx_visible(slot,g_camera+0x38,pos_mtx)&255)!=1)return;
    gfx_push_mtx(gfx,slot);
    vtx=gfx_add_quad_tris(gfx)&65535;
    gfx_set_quad_pos(gfx,vtx,(s16)(corner[0]+1),(s16)(corner[1]+1),(s16)(corner[2]+4000),(s16)(corner[3]+1),(s16)(corner[4]+60),(s16)(corner[5]+4000),(s16)(corner[6]+60),(s16)(corner[7]+60),(s16)(corner[8]+4000),(s16)(corner[9]+70),(s16)(corner[10]+1),(s16)(corner[11]+4000));
    gfx_set_quad_color(gfx,vtx,255,0,0,255,0,0,0,0,255,0,0,255);
}
