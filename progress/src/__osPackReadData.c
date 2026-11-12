extern char gOrderState[];
extern u8 __osMaxControllers;

typedef struct {
    u8 b[6];
    s8 tail[2];
} Buf8;

/* Clears the 15 slot words at the request buffer, then writes one 8-byte read-request
 * packet (0xFF, 1, 4, 1, 0xFFFF, 0xFF, 0xFF) for each controller and ends the list with 0xFE. */
void __osPackReadData(void)
{
    Buf8 pat;
    register s32 i;
    s32 n;
    s32 *slot;
    u8 *dst;
    u8 count;

    dst = (u8 *)(gOrderState + 0x1250);
    i = 0xE;
    slot = (s32 *)(dst + 0x38);
    do {
        *slot = 0;
        i -= 1;
        slot -= 1;
    } while (i >= 0);

    count = __osMaxControllers;
    n = 0;
    *(s32 *)(gOrderState + 0x128C) = 1;

    pat.b[0] = 0xFF;
    pat.b[1] = 1;
    pat.b[2] = 4;
    *(u16 *)&pat.b[4] = 0xFFFF;
    pat.b[3] = 1;
    pat.tail[0] = -1;
    pat.tail[1] = -1;

    for (i = 0; i < __osMaxControllers; i++) {
        *(Buf8 *)dst = pat;
        dst += 8;
    }
    *dst = 0xFE;
}
