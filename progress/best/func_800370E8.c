s32 func_8000BA38();
extern char D_800C02AE[];
void func_800370E8(void *arg0, void *arg1, void *arg2)
{
  s16 temp_a3;
  s32 temp_a3_2;
  s16 var_a2;
  s16 var_t2;
  s32 var_v0;
  s32 var_v0_2;
  u16 temp_t0;
  u32 var_v1;
  s32 temp_a0;
  void *temp_a1;
  void *temp_v0;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  temp_a3 = *((u16 *) (((char *) arg1) + 0x10));
  temp_t0 = *((u16 *) (((char *) arg0) + 0x10));
  temp_a3 -= temp_t0;
  var_a2 = (*((u16 *) (((char *) arg1) + 0x12))) - (*((u16 *) (((char *) arg0) + 0x12)));
  var_t2 = temp_a3;
  *((u16 *) (((char *) arg2) + 0x10)) = (u16) (temp_t0 + ((temp_a3 * (*((u8 *) (((char *) arg2) + 0x15)))) / 100));
  temp_a3_2 = (*((u16 *) (((char *) arg0) + 0x12))) + ((var_a2 * (*((u8 *) (((char *) arg2) + 0x15)))) / 100);
  *((s16 *) (((char *) arg2) + 0x12)) = temp_a3_2;
  temp_a0 = *((u8 *) (((char *) arg2) + 0x14));
  switch (temp_a0)
  {
    case 0xC8:
      temp_v0 = *((void **) (((char *) (*((void **) (((char *) arg2) + 0xC)))) + 0x1C));
      var_t2 = (*((u16 *) (((char *) arg2) + 0x10))) - (*((u16 *) (((char *) temp_v0) + 6)));
      var_a2 = temp_a3_2 - (*((u16 *) (((char *) temp_v0) + 8)));
      break;

    case 0x96:
      temp_a1 = *((void **) (((char *) (*((void **) (((char *) arg2) + 0xC)))) + 0x1C));
      var_v0 = (*((u16 *) (((char *) temp_a1) + 6))) * 3;
      if (var_v0 < 0)
    {
      var_v0 += 3;
    }
      var_t2 = (*((u16 *) (((char *) arg2) + 0x10))) - (var_v0 >> 2);
      var_a2 = temp_a3_2 - (((s32) ((*((u16 *) (((char *) temp_a1) + 8))) * 3)) / 4);
      break;

    case 0x64:
      temp_v1 = *((void **) (((char *) (*((void **) (((char *) arg2) + 0xC)))) + 0x1C));
      var_t2 = (*((u16 *) (((char *) arg2) + 0x10))) - (((u16) (*((u16 *) (((char *) temp_v1) + 6)))) >> 1);
      var_v1 = ((u16) (*((u16 *) (((char *) temp_v1) + 8)))) >> 1;
      block_20:
    var_a2 = temp_a3_2 - var_v1;

      break;

    case 0x4B:
      temp_v0 = *((void **) (((char *) (*((void **) (((char *) arg2) + 0xC)))) + 0x1C));
      var_v0_2 = (*((u16 *) (((char *) temp_v0) + 6))) * 3;
      if (var_v0_2 < 0)
    {
      var_v0_2 += 7;
    }
      var_t2 = (*((u16 *) (((char *) arg2) + 0x10))) - (var_v0_2 >> 3);
      var_a2 = temp_a3_2 - (((s32) ((*((u16 *) (((char *) temp_v0) + 8))) * 3)) / 8);
      break;

    case 0x32:
      temp_v1_2 = *((void **) (((char *) (*((void **) (((char *) arg2) + 0xC)))) + 0x1C));
      var_t2 = (*((u16 *) (((char *) arg2) + 0x10))) - (((u16) (*((u16 *) (((char *) temp_v1_2) + 6)))) >> 2);
      var_v1 = ((u16) (*((u16 *) (((char *) temp_v1_2) + 8)))) >> 2;
      goto block_20;

    case 0x19:
      temp_v1_3 = *((void **) (((char *) (*((void **) (((char *) arg2) + 0xC)))) + 0x1C));
      var_t2 = (*((u16 *) (((char *) arg2) + 0x10))) - (((u16) (*((u16 *) (((char *) temp_v1_3) + 6)))) >> 3);
      var_v1 = ((u16) (*((u16 *) (((char *) temp_v1_3) + 8)))) >> 3;
      goto block_20;

  }

  func_8000BA38(*((s32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x178)), var_t2, var_a2, (*((void **) (((char *) arg2) + 0xC))) + 0x10, 0, (s32) (*((u8 *) (((char *) arg2) + 0x14))), (s32) (*((u8 *) (((char *) arg2) + 0x16))), (s32) (*((u8 *) (((char *) arg2) + 0x17))), (s32) (*((u8 *) (((char *) arg2) + 0x18))), 0x87);
}
