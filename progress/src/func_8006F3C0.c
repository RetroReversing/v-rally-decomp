extern u8 gStreamState[];
extern u8 gOrderState[];
s32 func_80077FA8(s32 arg0);

/* Clears the two u16 counters at stream state +0x6E60/+0x6E62, sets the
 * top-byte mask and bit 26 of the u32 at +0x6E76, and rewrites the u16 control
 * register at +0x6E5E (bits 0x44, 0x2000 and 0x8000 manipulated). */
void func_8006F3C0(void)
{
  u32 word;
  u32 mask;
  u32 __repair_v0_1;
  u32 bits;
  vu16 *reg = (vu16 *) (gStreamState + 0x6e5e);
  word = *((u32 *) (gStreamState + 0x6e76));
  mask = 0xf0ffffff;
  *((u16 *) (gStreamState + 0x6e60)) = 0;
  *((u16 *) (gStreamState + 0x6e62)) = 0;
  word &= mask;
  __repair_v0_1 = *reg;
  word |= 0x04000000;
  __repair_v0_1 &= 0xff44;
  __repair_v0_1 |= 0x44;
  bits = __repair_v0_1 | 0x2000;
  *reg = __repair_v0_1;
  bits &= 0x2044;
  __repair_v0_1 &= 0x7fff;
  *((u32 *) (gStreamState + 0x6e76)) = word;
  *reg = __repair_v0_1;
  *((u16 *) (gStreamState + 0x6e5e)) = bits;
}
