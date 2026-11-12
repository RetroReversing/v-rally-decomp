s32 func_8008A31C(s32);
extern char D_800BDC14[];

/* Receives the next message for the task whose pointer is stored at D_800BDC14+0x58F4. */
void func_8005A2D0(void)
{
    func_8008A31C(*(s32 *)(D_800BDC14 + 0x58F4));
}
