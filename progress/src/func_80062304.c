extern unsigned short D_800C34FC;
extern unsigned short D_800C836E;
extern short gNumberBuf;

extern char stream_state[];

/* Copies three 16-bit fields of the current stream record (the pointer at stream_state + 0x32F2) into D_800C34FC, D_800C836E and gNumberBuf. */
void func_80062304(void)
{
    u16 fieldA;
    u16 fieldB;
    char *rec;

    rec = *(char **)(stream_state + 0x32F2);
    fieldA = *(u16 *)(rec + 0x1E);
    fieldB = *(u16 *)(rec + 0x20);
    rec = (char *)*(u16 *)(rec + 0x22);
    D_800C34FC = fieldA;
    D_800C836E = fieldB;
    gNumberBuf = (s16)rec;
}
