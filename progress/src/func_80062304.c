extern unsigned short D_800C34FC;
extern unsigned short D_800C836E;
extern short gNumberBuf;

extern char gOrderState[];
extern char stream_state[];

/* Copies three 16-bit fields of the current stream record (pointed to by stream_state + 0x32F2)
 * into the globals D_800C34FC, D_800C836E and gNumberBuf. */
void func_80062304(void) {
    u16 fieldA;
    u16 fieldB;
    void *rec;

    rec = stream_state + 0x32F2;
    rec = *(void **)(stream_state + 0x32F2);
    fieldA = *(u16 *)((char *)rec + 0x1E);
    fieldB = *(u16 *)((char *)rec + 0x20);
    #ifdef PORT
    gNumberBuf = (s16)*(u16 *)((char *)rec + 0x22);
#else
    rec = (void *)*(u16 *)((char *)rec + 0x22);
#endif
    D_800C34FC = fieldA;
    D_800C836E = fieldB;
    #ifndef PORT
    gNumberBuf = (s16)rec;
#endif
}