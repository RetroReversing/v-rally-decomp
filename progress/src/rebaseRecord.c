s32 rebase_words();
extern s32 rebase_base_addr;
void rebaseRecord(void *arg0)
{
  s32 temp_a0;
  *((s32 *) (((char *) arg0) + 0xC)) += rebase_base_addr;
  temp_a0 = (*((s32 *) (((char *) arg0) + 0x14))) + rebase_base_addr;
  *((s32 *) (((char *) arg0) + 0x14)) = temp_a0;
  rebase_words(temp_a0, *((u16 *) (((char *) arg0) + 0x10)), rebase_base_addr);
}
