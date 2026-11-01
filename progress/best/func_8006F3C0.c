extern u8 D_800C02AE[];
extern u8 D_800AE850[];
s32 func_80077FA8(s32 arg0);
void func_8006F3C0(void)
{
  u32 a1;
  u32 v0;
    u32 __repair_v0_1;
  u32 v1;
  vu16 *a0 = (vu16 *) (D_800C02AE + 0x6e5e);
  a1 = *((u32 *) (D_800C02AE + 0x6e76));
  v0 = 0xf0ffffff;
  *((u16 *) (D_800C02AE + 0x6e60)) = 0;
  *((u16 *) (D_800C02AE + 0x6e62)) = 0;
  a1 &= v0;
  __repair_v0_1 = *a0;
  a1 |= 0x04000000;
  __repair_v0_1 &= 0xff44;
  __repair_v0_1 |= 0x44;
  v1 = __repair_v0_1 | 0x2000;
  *a0 = __repair_v0_1;
  __repair_v0_1 &= 0x7fff;
  *((u32 *) (D_800C02AE + 0x6e76)) = a1;
  *a0 = __repair_v0_1;
  *a0 = v1;
}

