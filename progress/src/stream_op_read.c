typedef struct { u8 pad40[0x40]; s32 x40; s32 x44; u8 pad48[0x2c]; s32 x74; u8 pad78[0x3c]; u8 b4; u8 b5; } OpState;
extern s32 func_80086C00(s32, s32, s32, s32, s32);
extern u8 gOrderState[];
extern u8 stream_state[];

/* Reads one opcode from m (two bytes when the top bit of the first is set),
 * runs it through func_80086C00 with this state's b4/b5 bytes, and if that
 * returns a handle, copies x40 and x74 into every stream record that holds
 * that handle. Returns the position after the opcode. */
void *stream_op_read(OpState *op, u8 *m)
{
 s32 handle, i, count, limit, code, v, high, old, b4, b5;
 u8 *p;
 u8 pad[8];

 code = *m++;
 if (code >= 0x80) {
  v = *m++;
  high = (code & 0x7f) << 8;
  code = high + v;
 }
 b4 = op->b4;
 old = op->x44;
 b5 = op->b5;
 op->x44 = old + 1;
 handle = func_80086C00(code, b4, b5, 0, old);
 op->x44--;
 if (handle) {
  count = *(s32 *)(stream_state + 0x757e);
  p = *(u8 **)(gOrderState + 0x80a0);
  i = 0;
  if (count > 0) {
   limit = count;
   do {
    if (*(s32 *)(p + 0x40) == handle) {
     *(s32 *)(p + 0x40) = op->x40;
     *(s32 *)(p + 0x74) = op->x74;
    }
    i++;
    p += 0x134;
   } while (i < limit);
  }
 }
 return m;
}
