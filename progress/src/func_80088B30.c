/* Byte-stream step decoder. `count` advances in 8.8 fixed point (0x100 per step) until
 * it reaches `limit`. When `timer` runs out, the next command byte is read from `ptr`:
 * a byte with the high bit clear sets the last value (`b4`) and reloads the timer with 1;
 * otherwise the value is stored in `b4` and the timer is reloaded from the following
 * byte(s), with a two-byte form for longer waits. */
typedef struct {u8 p0[8];u32 limit;u8 p1[4];u32 count;u8 p2[0x20];u8 * volatile ptr;u8 p3[0x62];u16 timer;u8 p4[0x18];s8 b4;} S88B30;
void func_80088B30(S88B30 *st)
{
  S88B30 *base = st;
  u16 one = 1, ticks;
  u8 *cursor;
  u8 *lastByte;
  u8 *cursor2;
  u8 byte;
  s32 len;
  do {
    base->count += 0x100;
    ticks = base->timer - 1;
    base->timer = ticks;
    if (ticks == 0) {
      cursor = base->ptr;
      base->ptr = cursor + 1;
      byte = *cursor;
      if (byte >= 0x80) {
        cursor2 = base->ptr;
        base->b4 = byte & 0x7f;
        base->ptr = cursor2 + 1;
        byte = *cursor2;
        if (byte >= 0x80) {
          lastByte = base->ptr;
          len = (byte & 0x7f) << 8;
          base->timer = len;
          base->ptr = lastByte + 1;
          base->timer = *lastByte + (len + 2);
        } else {
          base->timer = byte + 2;
        }
      } else {
        base->b4 = byte;
        base->timer = one;
      }
    }
  } while (base->count < base->limit);
}
