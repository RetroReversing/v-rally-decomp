s32 func_80050DF4();
s32 func_80050FC4();
extern s32 gSavedGameFiles[];
extern char stream_state[];
extern void *gRecords;
extern char D_800C8214[];

typedef struct
{
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Chunk;

/* Sets the in-use flag (0x10) on the records, picks a random slot and loads
 * its saved game from gSavedGameFiles. If the flag is clear after that, it
 * copies the 0xF4-byte record block to D_800C8214 instead. Ends by setting
 * the record state fields to 7 and 1. */
void func_80050F08(void)
{
    char *src;
    char *dst;
    s32 slot;
    char *end;

    *(u16 *)((char *)gRecords + 0x2C) |= 0x10;
    slot = func_80050DF4() & 0xFF;
    if (*(u16 *)((char *)gRecords + 0x2C) & 0x10)
    {
        func_80050FC4(gSavedGameFiles[slot]);
    }
    else
    {
        dst = D_800C8214;
        src = gRecords;
        end = src + 0xF0;
        do
        {
            *(Chunk *)dst = *(Chunk *)src;
            src += 0x10;
            dst += 0x10;
        } while (src != end);
        *(s32 *)dst = *(s32 *)src;
    }
    *(s16 *)((char *)gRecords + 0x1E) = 7;
    *(s16 *)((char *)gRecords + 0xE) = 1;
}
