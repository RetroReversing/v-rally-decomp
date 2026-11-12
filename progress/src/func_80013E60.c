u64 __udivdi3(u64, u64);
extern char gOrderState[];

/* Returns the current entry's 64-bit field at +0x48 divided by 250, plus 40. */ s32 func_80013E60(void)
{
    char *entry;

    entry = *(char **)(gOrderState + 0x7FCC);
    entry += *(s32 *)entry * 8;
    return (s32)__udivdi3(*(u64 *)(entry + 0x48), 0xFA) + 0x28;
}
