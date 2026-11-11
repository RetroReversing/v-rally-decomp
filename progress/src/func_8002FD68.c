s32 cont_port_is_connected(s32, s32);
s32 func_800858A4();
extern char gOrderState[];

/* Per-channel timer update for the 4 channels in gOrderState+0x2390. Each 16-byte entry
 * holds: limit (u8, +0), count (u16, +2), active flag (s32, +4), kind (u8, +0xC), and
 * the new kind to store (u8, +0xD). A channel whose kind changed is restarted; an active
 * channel counts up and is stopped when the count reaches its limit. */
void func_8002FD68(void)
{
  s32 chanBase;
  s32 chanPtr;
  u8 ch;
  u8 chanIdx;
  s32 off;
  s32 var_v1;

  ch = 0;
  chanBase = 1;
  chanPtr = (s32)(gOrderState + 0x2390);
  do
  {
    chanIdx = ch;
    off = chanIdx << 4;
    if (*((u8 *)(gOrderState + 0x239C + off)) != cont_port_is_connected(chanIdx, 2))
    {
      *((u8 *)(gOrderState + 0x239D + off)) = chanBase;
      *((s32 *)(gOrderState + 0x2394 + off)) = 0;
    }
    if (*((s32 *)(gOrderState + 0x2394 + off)) != 0)
    {
      var_v1 = off + chanPtr;
      *((s16 *)(var_v1 + 2)) = *((u16 *)(gOrderState + 0x2392 + off)) + 1;
      if (*((u8 *)(gOrderState + 0x2390 + off)) <= *((u16 *)(gOrderState + 0x2392 + off)))
      {
        *((s32 *)(gOrderState + 0x2394 + off)) = 0;
        func_800858A4(chanIdx, 2, 0);
      }
    }
    ch++;
  } while (ch < 4);
}
