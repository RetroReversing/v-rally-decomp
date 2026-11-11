extern u8 gOrderState[72286];
extern u8 gStreamState[66514];

/* Returns nonzero when the current stream slot's chain check fails: the value
 * read through the order-state chain, XORed with 0x3A98, must be zero. */
s32 func_80049DB0(void)
{
    u8 *root = *(*((u8 ***) (((u8 *) gOrderState) + 0x73F0)));
    u8 *game = *((u8 **) (((u8 *) gStreamState) + 0x32F2));
    s32 p = (s32) *((s32 **) ((*((u8 **) (root + 0x6C))) + 0x24));

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
        scratch = (s32)*((u8 **) (game + 0x6C));
        do { do { p=*(s32*)p; } while (0); } while (0);
        root = (u8*) *((s32 **) ((u8*)scratch + 0x24));
        scratch = 0x3A98;
        if (p != scratch)
        {
            return 1;
        }
        value = *(s32*)root ^ scratch;
        goto done;
    }
    value=*(s32*)p;
    value = value ^ 0x3A98;
    done:
    return value != 0;
}
