extern signed char D_800C7FA1;
extern signed char D_800C81FC;
s32 func_8005C198();
s32 func_8005E28C();
s32 func_8005E470();
extern void *D_800A1468;
extern s8 D_800A16D4;
extern char D_800C02AE[];
static inline static static static int inline_fn(s32 arg0)
{
  return arg0 * 0x18;
}

s32 func_800643F0(s32 arg0, s32 arg1)
{
  s32 var_a0;
  s8 new_var;
  u32 temp_v1;
  s8 var_a1;
  u16 temp_v1_2;
  func_8005C198();
  func_8005E470(arg0, arg1);
  var_a1 = 1;
  *((s8 *) (((char *) D_800A1468) + 0x2BD)) = 1;
 do { if (((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x2C))) & 0xFFFFFFFFFFFFFFFF) & 0x800) { *((s16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x1E)) = 8; temp_v1 = (*((u8 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x23))) & 3; D_800C7FA1 = temp_v1; if (temp_v1 == 0) { D_800C81FC = 1; } else { D_800C81FC = 0; } ; temp_v1 &= 0xFF; do { if ((var_a1 & 0xFF) == (temp_v1 & 0xFF)) { *((volatile char *) ((D_800C02AE + 0x7CF3) + inline_fn(var_a1 & 0xFF))) = 0; var_a1 += 1; } else { new_var = var_a1; *((D_800C02AE + 0x7CF3) + inline_fn(var_a1 & 0xFF)) = new_var; var_a1 += 1; } var_a0 = var_a1 & 0xFF; } while (((u32) (var_a1 & 0xFF)) < 4U); temp_v1_2 = *((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20)); *((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20)) = 0U; *((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x22)) = temp_v1_2; } D_800A16D4 = 1; func_8005E28C(0, 0); } while (0);
  return 0;
}
