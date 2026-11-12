extern char gMirrorListHead[];
s32 func_80028D6C(s32);
extern s32 D_8009693C;

/* Receives the next message for the order task whose pointer is stored at D_8009693C+0x58F4. */
void func_8002D270(void)
{
    func_80028D6C(*(s32 *)((u8 *)&gMirrorListHead));
}
