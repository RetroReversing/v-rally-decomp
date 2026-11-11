u64 __udivdi3(u64, u64);
extern char gOrderState[];

s32 func_80013E60(void)
{
    char *p;

    p = *(char **)(gOrderState + 0x7FCC);
    p += *(s32 *)p * 8;
    return (s32)__udivdi3(*(u64 *)(p + 0x48), 0xFA) + 0x28;
}
