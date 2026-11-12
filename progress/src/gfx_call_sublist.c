/* Appends a call to a sublist in the parent display list (G_DL), then closes the sublist with G_ENDDL. */
s32 gfx_call_sublist(void *parent, void *sub)
{
    void *cmd;
    void *subCmd;

    cmd = *(void **)((s8 *)parent + 0x14);
    *(void **)((s8 *)parent + 0x14) = (s8 *)cmd + 8;
    *(s32 *)cmd = 0xDE000000;
    *((s32 *)cmd + 1) = *(s32 *)((s8 *)sub + 0x10);
    subCmd = *(void **)((s8 *)sub + 0x14);
    *(void **)((s8 *)sub + 0x14) = (s8 *)subCmd + 8;
    *(s32 *)subCmd = 0xDF000000;
    *((s32 *)subCmd + 1) = 0;
    return 1;
}
