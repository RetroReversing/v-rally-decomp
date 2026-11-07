s32 func_80027CDC(s32, s32);
s32 func_80027CFC(s32);
s32 func_800502D4(s32);
extern s32 D_800A1238;
void func_800280EC(void **arg0, s32 arg1)
{
  u16 *new_var;
  if ((*(new_var = (u16 *) (((char *) (D_800A1238 + (0x44 * (*((u8 *) (((char *) (*((void **) (((char *) (*arg0)) + 0x48)))) + 3)))))) + 8))) & 0x10)
  {
    func_80027CDC(func_800502D4(D_800A1238), arg1);
    func_80027CFC(arg1);
  }
}

