s32 streamReadBytes(void *, s32);
u16 readU16LE(void *);
s32 readU32LE(void *);
extern s32 gOrderState;
extern s32 stream_state;

/* Reads the 26-byte stream header into a stack buffer (little-endian fields) and stores
 * its values in the stream state. Also copies two of the fields into the gOrderState block;
 * if the flag bit 8 is set in the first field, the second one is replaced by the value found
 * behind a pointer in that block. */
s32 readStreamHeader(void)
{
    u8 hdr[0x1A];
    s32 temp_v0;

    streamReadBytes(hdr, 0x1A);
    *((u16 *) (((char *) (&stream_state)) + 0x30BA)) = readU16LE(&hdr[2]);
    *((u16 *) (((char *) (&stream_state)) + 0x30BC)) = readU16LE(&hdr[4]);
    *((s32 *) (((char *) (&stream_state)) + 0x30BE)) = readU32LE(&hdr[14]);
    *((s32 *) (((char *) (&stream_state)) + 0x30C2)) = readU32LE(&hdr[18]);
    *((u16 *) (((char *) (&stream_state)) + 0x30C6)) = readU16LE(&hdr[22]);
    *((s32 *) (((char *) (&gOrderState)) + 0x8ACC)) = *((s32 *) (((char *) (&stream_state)) + 0x30BE));
    *((s32 *) (((char *) (&gOrderState)) + 0x8AD0)) = *((s32 *) (((char *) (&stream_state)) + 0x30C2));
    if (*((u16 *) (((char *) (&stream_state)) + 0x30BA)) & 8)
    {
        temp_v0 = *((s32 *) (((char *) (*((void **) (((char *) (&gOrderState)) + 0x8AE4)))) + 4));
        *((s32 *) (((char *) (&stream_state)) + 0x30BE)) = temp_v0;
        *((s32 *) (((char *) (&gOrderState)) + 0x8ACC)) = temp_v0;
    }
    return 0;
}
