extern s32 gContCtx;

/* Stores the per-controller values for entry index into the controller context. kind 0x20000
   writes the two bytes at +0x5C/+0x5D and the byte at +0x5F; kind 0x10000 writes +0x61, +0x62 and +0x64.
   The high half of packed is stored at +0x5C (or +0x61). Each entry is 0x14 bytes. */
void func_80084E48(s32 index, s32 kind, s8 val_a, s8 val_b, s32 packed)
{
  unsigned short off;
  s32 hi = ((u16 *) (&packed))[1];
  if (kind == 0x20000)
  {
    s32 base = gContCtx;
    if (1)
    {
      off = (index & 0xFF) * 0x14;
      *((s8 *) ((base + off) + 0x5F)) = val_a;
      *((s8 *) ((gContCtx + off) + 0x5C)) = hi;
    }
    *((s8 *) ((gContCtx + off) + 0x5D)) = val_b;
  }
  else
    if (kind == 0x10000)
  {
    s32 base = gContCtx;
    off = (index & 0xFF) * 0x14;
    *((s8 *) ((base + off) + 0x64)) = val_a;
    *((s8 *) ((gContCtx + off) + 0x61)) = hi;
    *((s8 *) ((gContCtx + off) + 0x62)) = val_a;
  }
}
