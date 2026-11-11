s32 text_load_and_parse(void *, void *);
void *poolAlloc(s32, s32);
s32 func_80084BF0(s32);
extern u8 D_800A13C0[];
extern u8 *gSelectState;
extern u8 D_800A5230[];

/* Allocates the 0x2C0-byte select state and zeroes its fields. Only the fields
   that start out non-zero are set to other values: byte 0x246 = 1, byte 0x22B = -1,
   byte 0x2BC = 3 and halfword 0x222 = -1. The 0x184 table gets 4 zeroed words.
   Byte 0x248 is set from the input flags of func_80084BF0(0). Then it is published
   as gSelectState and the associated data is loaded. */
void func_80057998(void)
{
    u8 *sel;
    u8 i;

    sel = poolAlloc(1, 0x2C0);
    i = 0;
    *(s8 *)(sel + 0x246) = 1;
    *(s8 *)(sel + 0x22B) = -1;
    *(s32 *)(sel + 0x8) = 0;
    *(void **)(sel + 0x0) = NULL;
    *(void **)(sel + 0x4) = NULL;
    *(s32 *)(sel + 0x14) = 0;
    *(void **)(sel + 0xC) = NULL;
    *(void **)(sel + 0x10) = NULL;
    *(s32 *)(sel + 0x20) = 0;
    *(void **)(sel + 0x18) = NULL;
    *(void **)(sel + 0x1C) = NULL;
    *(s32 *)(sel + 0x2C) = 0;
    *(void **)(sel + 0x24) = NULL;
    *(void **)(sel + 0x28) = NULL;
    *(s8 *)(sel + 0x234) = 0;
    *(s8 *)(sel + 0x232) = 0;
    *(s8 *)(sel + 0x233) = 0;
    *(s8 *)(sel + 0x22C) = 0;
    *(s8 *)(sel + 0x22D) = 0;
    *(s32 *)(sel + 0x288) = 0;
    *(s32 *)(sel + 0x28C) = 0;
    *(s32 *)(sel + 0x290) = 0;
    *(s32 *)(sel + 0x294) = 0;
    *(s8 *)(sel + 0x247) = 0;
    *(s8 *)(sel + 0x228) = 0;
    *(s8 *)(sel + 0x2BC) = 3;
    *(s8 *)(sel + 0x24D) = 0;
    *(s8 *)(sel + 0x24E) = 0;
    do {
        *(s32 *)(sel + (i * 4) + 0x184) = 0;
        i++;
    } while (i < 4);
    *(s16 *)(sel + 0x222) = -1;
    if (func_80084BF0(0) & 0x2020) {
        *(s8 *)(sel + 0x248) = 1;
    } else {
        *(s8 *)(sel + 0x248) = 0;
    }
    gSelectState = sel;
    text_load_and_parse(D_800A13C0, D_800A5230);
}
