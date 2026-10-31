extern s32 D_8009FF38;
void func_8001CB88(u8 *arg0) {
 u16 i=2; s16 *dst=(s16 *)&D_8009FF38;
 dst += *(u16 *)(arg0+0x92)*10;
 do { dst[i]=*(s32 *)(arg0+i*76+68); i++; } while(i<10);
}
