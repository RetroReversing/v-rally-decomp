extern s32 D_8009FF38;
typedef struct { u8 pad[0x44]; s32 v; u8 pad2[4]; } S76;
void func_8001CB88(S76 *arg0) {
 u16 i=2; s16 (*tbl)[10]=(s16 (*)[10])&D_8009FF38;
 s16 *dst = tbl[*(u16 *)((u8 *)arg0+0x92)];
 do { dst[i]=arg0[i].v; i++; } while(i<10);
}
