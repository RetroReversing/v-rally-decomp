/* Partial candidate from function #24464 in project #57; rechecked locally. */
void *func_80006008();
s32 func_80006014();
extern char D_8009C068[];
extern char D_8009C0A8[];
extern char D_8009C0E8[];
void func_800169DC(s32 arg0, s32 arg1)
{
  void *temp_a0;
  void *temp_a0_2;
  void *temp_a1;
  void *temp_a2;
  void *temp_t0_3;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v1;
  void *temp_v1_2;
  void *var_t0;
  var_t0 = func_80006008();
  if (arg1 == 1)
  {
    goto block_10;
  }
  if (arg1 < 2)
  {
    goto block_3;
  }
  goto block_6;
  block_3:
  temp_v0 = var_t0;

  if (arg1 == 0)
  {
    goto block_9;
  }
  goto block_14;
  block_6:
  if (arg1 == 2)
  {
    goto block_11;
  }

  temp_v1 = var_t0;
  if (arg1 == 3)
  {
    goto block_12;
  }
  goto block_14;
  block_9:
  var_t0 += 8;

  *((s32 *) (((char *) temp_v0) + 0)) = 0xDE000000;
  *((s32 **) (((char *) temp_v0) + 4)) = &D_8009C068;
  goto block_13;
  block_10:
  temp_v0_2 = var_t0;

  var_t0 += 8;
  *((s32 *) (((char *) temp_v0_2) + 0)) = 0xDE000000;
  *((s32 **) (((char *) temp_v0_2) + 4)) = &D_8009C0A8;
  goto block_13;
  block_11:
  temp_v1_2 = var_t0;

  var_t0 += 8;
  temp_a1 = var_t0;
  var_t0 += 8;
  temp_a0 = var_t0;
  var_t0 += 8;
  *((s32 *) (((char *) temp_v1_2) + 0)) = 0xDE000000;
  *((s32 **) (((char *) var_t0) + 4)) = &D_8009C068;
  *((s32 *) (((char *) temp_a1) + 4)) = -0xDC8;
  temp_a2 = ((char *) temp_a1) + 0;
  *((s32 *) temp_a2) = 0xFC30FFFF;
  *((s32 *) (((char *) temp_a0) + 0)) = 0xFA000000;
  *((s32 *) (((char *) temp_a0) + 4)) = 0x28282800;
  goto block_13;
  block_12:
  var_t0 += 8;

  temp_a2 = var_t0;
  var_t0 += 8;
  temp_a0_2 = var_t0;
  var_t0 += 8;
  *((s32 *) (((char *) temp_v1) + 0)) = 0xDE000000;
  *((s32 **) (((char *) temp_v1) + 4)) = &D_8009C0E8;
  *((s32 *) (((char *) temp_a2) + 0)) = 0xFA000000;
  *((s32 *) (((char *) temp_a2) + 4)) = 0x28282800;
  *((s32 *) (((char *) temp_a0_2) + 0)) = 0xFC30D3FF;
  *((s32 *) (((char *) temp_a0_2) + 4)) = -0x1C8;
  block_13:
  block_14:
  func_80006014(arg0, var_t0);


  return;
}
