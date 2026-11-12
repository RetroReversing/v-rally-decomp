
extern int D_800B65EC;
extern int D_800B65F0;
extern int D_800B6AFC;
extern int D_800C34F4;
extern int D_800B65F4;
extern char gOrderState[];
extern char stream_state[];
/* Copies five words of an object (offsets 0x128, 0x90, 0xDC, 0x174, 0x1C0) into the D_800B65xx/D_800C34F4 globals. */ void func_8001CC54(void *obj)
{
  s32 field174;
  void *objAlias;
  s32 fieldDC;
  s32 field128;
  s32 field90;
  s32 field90Load;
  field128 = *((s32 *) (((char *) obj) + 0x128));
  objAlias = obj;
  field90Load = *((s32 *) (((char *) objAlias) + 0x90));
  field90 = field90Load;
  fieldDC = *((s32 *) (((char *) obj) + 0xDC));
  D_800B65EC = field128;
  field174 = *((s32 *) (((char *) obj) + 0x174));
  field128 = field174;
  D_800B65F0 = field128;
  field128 = *((s32 *) (((char *) obj) + 0x1C0));
  D_800B6AFC = field90;
  D_800C34F4 = fieldDC;
  D_800B65F4 = field128;
}
