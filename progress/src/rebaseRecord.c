s32 rebase_words();
extern s32 rebase_base_addr;
/* Adds rebase_base_addr to a record's pointer fields at +0xC and +0x14, then rebases its word table. */ void rebaseRecord(void *record)
{
  s32 wordsAddr;
  *((s32 *) (((char *) record) + 0xC)) += rebase_base_addr;
  wordsAddr = (*((s32 *) (((char *) record) + 0x14))) + rebase_base_addr;
  *((s32 *) (((char *) record) + 0x14)) = wordsAddr;
  rebase_words(wordsAddr, *((u16 *) (((char *) record) + 0x10)), rebase_base_addr);
}
