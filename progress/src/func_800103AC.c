void *func_80010344();
void *poolAllocNode();

/* Looks up the registry entry named by arg1 + 0xE4. If it exists, allocates a 0x90-byte
 * object for owner, hands it to the entry's handler, then copies four words of state
 * from offset 0x10 to offset 0x20. */
void func_800103AC(s32 owner, s32 arg1)
{
    u32 i;
    unsigned int new_var;
    void *entry;
    void *obj;

    entry = func_80010344(arg1 + 0xE4);
    if (entry == NULL)
    {
        goto done;
    }
    obj = poolAllocNode(owner, 0x90);
    *((s32 *) (((char *) obj) + 0xC)) = (s32) (*((s32 *) (((char *) entry) + 8)));
    *((s32 *) (((char *) obj) + 0x6C)) = owner;
    (*((s32 (**)(void *, s32)) (((char *) entry) + 4)))(obj, arg1);
    i = 0;
    loop:
    i += 1;

    *((s32 *) (((char *) obj) + 0x20)) = (s32) (new_var = *((s32 *) (((char *) obj) + 0x10)));
    obj += 4;
    if (i < 4U)
    {
        goto loop;
    }
    done:
    return;
}
