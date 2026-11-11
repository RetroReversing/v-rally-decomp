extern s32 motor_pak_reset(s32, s32);
extern s32 osMotorInit(void *, void *, s32);
extern void *gContCtx;
extern u8 gOrderState;

/* Initialises the rumble pak on each controller that reports one (bit 4 of its
 * status word, and bit 0 of the flag byte). A slot whose pak fails to init is
 * marked as having no pak; a slot with no pak attached is cleared. */
void motor_pak_init_all(void)
{
  unsigned char slot;
  s32 i;
  void *ctx;
  void *pad;
  void *slot_ctx;
  void *slot_ctx2;
  void *slot_ctx3;
  unsigned char tmp;

  ctx = gContCtx;
  i = 0;
  if ((*((s32 *)(((u8 *)ctx) + 4))) > 0)
  {
    do
    {
      slot = i & 0xFF;
      pad = ((u8 *)ctx) + (slot * 4);
      if (((*((u16 *)(((u8 *)pad) + 0xC))) & 4) && ((*((u8 *)(((u8 *)pad) + 0xE))) & 1))
      {
        if ((osMotorInit((&gOrderState) + 0x5A38, ((u8 *)ctx) + ((slot * 0x68) + 0x18C), slot) & 0xFF) == 0)
        {
          motor_pak_reset(slot, 0);
          slot_ctx2 = ((u8 *)gContCtx) + (slot * 0x18);
          *((s32 *)(((u8 *)slot_ctx2) + 0x330)) = 1;
          *((volatile s32 *)(((u8 *)slot_ctx2) + 0x334)) = 0;
        }
        else
        {
          slot_ctx3 = ((u8 *)gContCtx) + (slot * 0x18);
          *((s32 *)(((u8 *)slot_ctx3) + 0x330)) = 0;
          slot = i & 0xFF;
          *((volatile s32 *)(((u8 *)slot_ctx3) + 0x334)) = 0;
        }
      }
      else
      {
        slot_ctx = (char *)((u8 *)gContCtx);
        slot_ctx += (s32)((i & 0xFF) * 0x18);
        *((s32 *)(((u8 *)slot_ctx) + 0x330)) = 0;
        *((s32 *)(((u8 *)slot_ctx) + 0x334)) = 0;
      }
      ctx = gContCtx;
      i += 1;
      slot = (tmp = i & 0xFF);
    }
    while ((i & 0xFF) < (*((s32 *)(((u8 *)gContCtx) + 4))));
  }
}
