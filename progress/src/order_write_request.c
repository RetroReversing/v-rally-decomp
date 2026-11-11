extern char gOrderState[];

typedef struct {
    u8 b[12];
} Blk12;

/* Writes a 12-byte request (type 2, 8, 4, then arg) into the order state at +0x8660,
   after clearing the 4 bytes in front of it, and ends it with 0xFE. Sets the
   pending flag at +0x869C. */
void order_write_request(s8 arg)
{
    Blk12 buf;
    u8 *p;
    s32 i;

    p = (u8 *)gOrderState + 0x8660;
    *(s32 *)(gOrderState + 0x869C) = 1;
    buf.b[0] = 2;
    buf.b[1] = 8;
    buf.b[2] = 4;
    buf.b[3] = arg;
    for (i = 3; i >= 0; i--) {
        *p++ = 0;
    }
    *(Blk12 *)p = buf;
    p[12] = 0xFE;
}
