u64 osGetTime(void);
s32 func_80098090(void);
void rand_seed(s32);
extern s32 D_8009F4F0[];
extern s32 D_8009F4F4[];
extern s32 D_8009F4F8[];
extern s32 D_8009F4FC[];
extern s32 D_8009F510[];

/* Seeds the random generator from the OS clock, then randomises three entries
 * of five 0x30-byte tables: each value moves by up to +/-5% of itself. */
void func_80033724(void)
{
    s32 entry;
    s32 rnd;
    s32 off;
    s32 ten;
    s32 five;
    s32 value;

    rand_seed((s32)osGetTime());
    entry = 0;
    ten = 10;
    five = 5;
    do {
        rnd = func_80098090() % ten;
        off = (entry & 0xFF) * 0x30;
        value = *(s32 *)(off + (int)D_8009F4F0); rnd -= five; rnd *= value; rnd /= 100; value += rnd; *(s32 *)((char *)D_8009F4F0 + off) = value;
        entry += 1;
        rnd = func_80098090() % ten;
        value = *(s32 *)((char *)D_8009F4F4 + off); rnd -= five; rnd *= value; rnd /= 100; value += rnd; *(s32 *)((char *)D_8009F4F4 + off) = value;
        rnd = func_80098090() % ten;
        value = *(s32 *)((char *)D_8009F4F8 + off); rnd -= five; rnd *= value; rnd /= 100; value += rnd; *(s32 *)((char *)D_8009F4F8 + off) = value;
        rnd = func_80098090() % ten;
        value = *(s32 *)((char *)D_8009F4FC + off); rnd -= five; rnd *= value; rnd /= 100; value += rnd; *(s32 *)((char *)D_8009F4FC + off) = value;
        rnd = func_80098090() % ten;
        value = *(s32 *)((char *)D_8009F510 + off); rnd -= five; rnd *= value; rnd /= 100; value += rnd; *(s32 *)((char *)D_8009F510 + off) = value;
    } while ((u32)(entry & 0xFF) < 3);
}
