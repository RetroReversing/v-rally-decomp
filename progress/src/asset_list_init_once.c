s32 flag_test_bit0();
s32 flag_set_then_call();
s32 poolAllocHeadNode();
extern char gOrderState[];
extern s32 asset_list_teardown;

/* Initializes the asset list at gOrderState+0x6D94 the first time it is called
 * (flag word at gOrderState+0x7348). Returns 1 if this call did the init, 0 if
 * the list was already set up. The teardown callback is registered with the flag. */
s32 asset_list_init_once(void)
{
    void *flags;
    s32 did_init;

    flags = gOrderState + 0x7348;
    if (flag_test_bit0(flags)) {
        did_init = 0;
    } else {
        *((s32 *)(gOrderState + 0x6D94)) = poolAllocHeadNode();
        flag_set_then_call(flags, &asset_list_teardown);
        did_init = 1;
    }
    return did_init;
}
