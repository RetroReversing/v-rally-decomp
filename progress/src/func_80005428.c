void func_80005FE8(s32, s32, s32);
extern s32 gSceneSlot0;
extern char gOrderState[];

/* Gathers up to ten word arguments (the list ends at the first zero word) and passes
 * each one to the debug output handler, in order. */
void func_80005428(s32 arg0, ...)
{
    s32 words[10];
    char *arg_ptr;
    u8 n;
    u8 k;
    s32 val;

    words[0] = arg0;
    arg_ptr = (char *)__builtin_next_arg(arg0);
    for (n = 1; n < 10; n++)
    {
        words[n] = 0;
        val = *(s32 *)((u32)(arg_ptr + 3) & ~3);
        arg_ptr = (char *)(((u32)(arg_ptr + 3) & ~3) + 4);
        words[n] = val;
        if (val == 0)
        {
            break;
        }
    }
    for (k = 0; k < n; k++)
    {
        func_80005FE8(*(s32 *)(gOrderState + 0x7400), gSceneSlot0, words[k]);
    }
}
