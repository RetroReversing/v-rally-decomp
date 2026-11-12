extern u8 gOrderState[72286];
extern u8 stream_state[66514];

/* Returns nonzero when the current stream slot's chain check fails: the value
 * read through the order-state chain, XORed with 0x3A98, must be zero. */
s32 func_80049DB0(void)
{
    u8 *root = *(*((u8 ***) (((u8 *) gOrderState) + 0x73F0)));
    u8 *game = *((u8 **) (((u8 *) stream_state) + 0x32F2));
#ifdef PORT
    s32 *p = *((s32 **) ((*((u8 **) (root + 0x6C))) + 0x24));
#else
    s32 p = (s32) *((s32 **) ((*((u8 **) (root + 0x6C))) + 0x24));
#endif

    s32 value;
    s32 scratch;
    scratch = *((u16 *) (game + 0xE));
    if (scratch == 2)
    {
        root = *((u8 **) (root + 4));
        if ((*((u16 *) (game + 0x1A))) == 1)
        {
            root = *((u8 **) (root + 4));
        }
        game = root;
#ifdef PORT
        {
            u8 *q = *((u8 **) (game + 0x6C));
            p = *(s32 **)p;
            root = *((u8 **) (q + 0x24));
        }
        scratch = 0x3A98;
        if (p != (s32 *)0x3A98)
        {
            return 1;
        }
#else
        scratch = (s32)*((u8 **) (game + 0x6C));
        do { do { p=*(s32*)p; } while (0); } while (0);
        root = (u8*) *((s32 **) ((u8*)scratch + 0x24));
        scratch = 0x3A98;
        if (p != scratch)
        {
            return 1;
        }
#endif
        value = *(s32*)root ^ scratch;
        goto done;
    }
    value = *(s32*)p;
    value = value ^ 0x3A98;
    done:
    return value != 0;
}
