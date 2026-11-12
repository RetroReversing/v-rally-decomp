extern char gOrderState[];
extern char stream_state[];
void *func_8004C4D0(s32, s32);

/* Creates a node from src in the stream's pool, makes it the current order-state object, and sets its flag bit 0x4. */
void func_8001D1A4(s32 src)
{
  s32 i;
  void *obj;
  void *pool;
  s32 flags;

  i = 1;
  do {
    i++;
  } while ((u8) i < 0xD);
  i++;
  pool = *((void **) (stream_state + 0x5A7A));
  obj = func_8004C4D0(*((s32 *) ((char *) pool + 0x10)), src);
  flags = *((s32 *) ((char *) obj + 0xC));
  *((void **) (gOrderState + 0x18)) = obj;
  *((s32 *) ((char *) obj + 0xC)) = flags | 4;
}
