extern s32 D_8009D4E8;
extern s32 rebase_base_addr;
static inline char *inline_fn(void *arg0)
{
  return ((char *) arg0) + 0x14;
}

/* Relocates an object's pointer fields: +0x18 and +0x20 and +0x14 get
 * rebase_base_addr added, and +0x10 gets D_8009D4E8 added. Relocation is
 * applied unconditionally here. */
void RebaseObjectPointers(void *obj)
{
  char *new_var;
  int new_var2;
  *((s32 *) (((char *) obj) + (new_var2 = 0x18))) += rebase_base_addr;
  new_var = ((char *) obj) + 0x10;
  if (1)
  {
    *((s32 *) new_var) += D_8009D4E8;
    *((s32 *) inline_fn(obj)) += rebase_base_addr;
    if (0)
    {
    }
    *((s32 *) (((char *) obj) + 0x20)) += rebase_base_addr;
  }
}
