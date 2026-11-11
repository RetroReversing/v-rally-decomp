s32 list_unlink_free();
extern void *D_800B0BC0;

/* Drains the list headed by D_800B0BC0: each node's callback at +0xC runs, then the node
 * is unlinked, until the head's next pointer (+4) is NULL. */
void func_80022214(void)
{
  s32 (*var_v0)();
  void *var_a0;
  void *var_a1;
  void *var_s0;
  void *var_v1;
  var_v1 = D_800B0BC0;
  if ((*((s32 (**)()) (((char *) var_v1) + 4))) != NULL)
  {
    do
    {
      var_s0 = *((void **) (((char *) var_v1) + 4));
      var_v0 = *((s32 (**)()) (((char *) var_s0) + 0xC));
      var_v0();
      var_a1 = D_800B0BC0;
      var_a0 = var_s0;
      list_unlink_free(var_a0, var_a1);
      var_v1 = D_800B0BC0;
    }
    while ((*((s32 (**)()) (((char *) var_v1) + 4))) != NULL);
  }
}
