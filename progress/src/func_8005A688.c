extern u8 *D_800A1468;
void *func_800592AC(u32 index);

void *func_8005A688(u32 index)
{
  return *(void **)(D_800A1468 + *((s8 *)func_800592AC(index) + 0xE) * 4 + 0xE4);
}
