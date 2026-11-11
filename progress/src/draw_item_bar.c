extern void *D_800A11B0;
extern void *func_80022668(s32,s32);
extern s32 draw_shaded_bar(s32,void *,s16 *,s32,s32,s32,s32,s32,s32);
/* Gets the bar of a list item: the item's node data holds a bar struct with
 * width at +6 and height at +8. */
#define ITEM_BAR(t) (*(void ***)((u8 *)*(void ***)((u8 *)(t)+0xC)+4))

/* Draws the shaded bar for list item `item_id`: the bar's width and height,
 * scaled by `scale` and centred on the origin, are passed to draw_shaded_bar
 * as its bounds rectangle. Does nothing if the item is not in the list. */
void draw_item_bar(s32 ctx,u32 item_id,f32 scale,s32 tex,u8 colour) {
s16 bounds[4]; void *item; u8 col; s32 temp_s2;
col=colour; temp_s2=tex;
item=func_80022668((s32)D_800A11B0,item_id&0xFFFF);
if(item!=NULL) {
bounds[0]=(s16)(s32)(-(s32)*(u16 *)((u8 *)*ITEM_BAR(item)+6)*scale*0.5f);
bounds[1]=(s16)(s32)(-(s32)*(u16 *)((u8 *)*ITEM_BAR(item)+8)*scale*0.5f);
bounds[2]=(s16)(s32)((f32)*(u16 *)((u8 *)*ITEM_BAR(item)+6)*scale);
bounds[3]=(s16)(s32)((f32)*(u16 *)((u8 *)*ITEM_BAR(item)+8)*scale);
draw_shaded_bar(ctx,*ITEM_BAR(item),bounds,tex&0xFF,col,col,col,col,0);
}
}
