void streamReadBytes(char *a, int b);
short readU16LE(char *a);
int readU32LE(char *a);
extern short gStreamHdrVersion;
extern int D_800C337C;
extern short gStreamHdrFlags;
extern int gStreamHdrDataOffset;

/* Reads the 0x2A-byte stream header and keeps the fields that the stream code needs. */
int streamReadHeader(void)
{
    char buf[0x30];

    streamReadBytes(buf, 0x2A);
    gStreamHdrVersion = readU16LE(buf + 4);
    D_800C337C = readU32LE(buf + 0x10);
    gStreamHdrFlags = readU16LE(buf + 0x18);
    gStreamHdrDataOffset = readU32LE(buf + 0x26);
    return 0;
}
