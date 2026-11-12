extern s8 *gControllerInputContext;

/* Returns 1 when the controller on this port reports a connected state (field 0x330 of its 0x18-byte entry). */
s32 cont_port_is_connected(s32 port, s32 unused_arg1)
{
  s8 *ctx;
  int entry_off;
  ctx = gControllerInputContext;
  entry_off = (port & 0xFF) * 0x18;
  return (*((s32 *) (ctx + entry_off + 0x330))) == 1;
}
