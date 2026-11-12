void gfx_queue_sublist(s32, s32, s32);
extern s32 gSceneSlot0;
extern char gOrderState[];

/* Gathers up to ten word arguments (the list ends at the first zero word) and passes
 * each one to the debug output handler, in order. */
void func_80005428(s32 arg0, ...)
{
    s32 words[10];
#ifdef PORT
    va_list ap;
#else
    char *arg_ptr;
#endif
    u8 n;
    u8 k;
    s32 val;

    words[0] = arg0;
#ifdef PORT
    va_start(ap, arg0);
    for (n = 1; n < 10; n++)
    {
        words[n] = 0;
        val = va_arg(ap, s32);
        words[n] = val;
        if (val == 0)
        {
            break;
        }
    }
    va_end(ap);
#else
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
#endif
    for (k = 0; k < n; k++)
    {
        gfx_queue_sublist(*(s32 *)(gOrderState + 0x7400), gSceneSlot0, words[k]);
    }
}
