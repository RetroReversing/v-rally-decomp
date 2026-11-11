extern char D_8009BEE8[];

/* Runs the handler for each entry of the item list in arg0 (the list's entries are 8 bytes each at +0x24; the count is at +0x20). Each entry's handler is picked by its u16 index at +6 from the D_8009BEE8 table. */
void itemListRunHandlers(void *list)
{
  char pad[8];
  u32 i;
  void *s2;
  u8 *s0;

  s2 = *(void **)((u8 *)list + 0x44);
  i = 0;
  s0 = (u8 *)s2 + 0x24;
  if (*(u32 *)((u8 *)s2 + 0x20) != 0) {
    do {
      u32 off = *(u16 *)(s0 + 6) * 4;
      ((void (*)(void *))(*(void **)(D_8009BEE8 + off)))(s0);
      i++;
      s0 += 8;
    } while (i < *(u32 *)((u8 *)s2 + 0x20));
  }
}
