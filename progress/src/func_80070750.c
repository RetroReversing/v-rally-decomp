extern unsigned char D_800B0D96;
extern unsigned char D_800B0D97;void *text_obj_get(u32);
s32 func_80059618();
void func_800596F4(void *, s16, s16, void *);
s32 func_80099DF8();
extern char D_800A5CDC[];
extern char D_800AE850[];
void func_80070750(void)
{
  s8 sp18[5];
  void *temp_v0;
  temp_v0 = text_obj_get(5);
  func_80059618(temp_v0, *((u8 *) (((char *) temp_v0) + 0xB)), *((u8 *) (((char *) temp_v0) + 0xC)), *((u8 *) (((char *) temp_v0) + 0xD)), (s32) (*((u8 *) (((char *) temp_v0) + 0xE))));
  sp18[4] = 0;
  func_80099DF8(sp18, &D_800A5CDC, D_800B0D96 + D_800B0D97);
  func_800596F4((void *)(temp_v0), (s16)(*((s16 *) (((char *) temp_v0) + 6))), (s16)(*((s16 *) (((char *) temp_v0) + 8))), (void *)(sp18));
}
