extern char D_800A5344[];
extern char D_800A5354[];
extern u8 *gSelectState;
extern char stream_state[];
void appendString(u8 *, u8 *);
s32 getTexturePack(u8 *, s32);
void resolve_path(u8 *);

/* Fills the four selection slots: for each slot, reads the 5-character name of the
 * matching entry in the record table, formats it with D_800A5354, and stores the
 * result in gSelectState. */
void func_8005BB5C(void)
{
  u8 buf[16];
  u8 *b;
  u8 *ptr;
  u8 *src;
  u8 *new_var;
  u8 k;
  u8 i;
  resolve_path(D_800A5344);
  i = 0;
  b = buf;
  do
  {
    ptr = *((u8 **) (stream_state + 0x32F2));
    ptr = ptr + ((ptr + i)[0x32] * 0x28);
    src = (*((u8 **) (stream_state + 0x103AA))) + ((*((u16 *) (ptr + 0x4E))) * 0x2C4);
    for (k = 0; k < 5; k++)
    {
      b[k] = src[k];
    }

    b[k] = 0;
    appendString(b, D_800A5354);
    *((s32 *) (((new_var = gSelectState) + (i * 4)) + 0x184)) = getTexturePack(b, 0);
    i++;
  }
  while (i < 4);
}
