s32 streamReleaseEntry();
extern int gOrderState[];

/* Releases the nine entry handles stored in the gOrderState table at 0x87F8. */
void func_800693CC(void)
{
    u8 i;

    for (i = 0; i < 9; i++) {
        streamReleaseEntry(*(s32 *)((char *)gOrderState + 0x87F8 + i * 4));
    }
}
