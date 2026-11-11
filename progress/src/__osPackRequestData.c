extern char gOrderState[];
extern u8 D_800B60E0;

typedef struct {
    u8 b[8];
} Pkt;

/* Clears the 15 slot words in the request buffer, then writes one 8-byte request
 * packet (0xFF, 1, 3, cmd, 0xFF x4) for each controller and ends the list with 0xFE. */
void __osPackRequestData(u8 cmd)
{
    Pkt packet;
    s32 i;
    s32 *slot;
    Pkt *out;

    i = 0xE;
    slot = (s32 *) (gOrderState + 0x1288);
    do {
        *slot = 0;
        i -= 1;
        slot -= 1;
    } while (i >= 0);
    *(s32 *) (gOrderState + 0x128C) = 1;
    out = (Pkt *) (gOrderState + 0x128C - 0x3C);
    packet.b[0] = 0xFF;
    packet.b[1] = 1;
    packet.b[2] = 3;
    packet.b[3] = cmd;
    packet.b[4] = 0xFF;
    packet.b[5] = 0xFF;
    packet.b[6] = 0xFF;
    packet.b[7] = 0xFF;
    for (i = 0; i < D_800B60E0; i++) {
        *out = packet;
        out += 1;
    }
    *(u8 *) out = 0xFE;
}
