#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
extern unsigned char D_800C355B;
extern float gSpeedAccum;
extern float D_800C35D8;
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000A140();
s32 func_8000D9CC();
s32 func_8000DA84();
s32 func_8000E774();
s32 func_8000F660();
s32 timing_ring_push();
s32 func_8001BBE4();
s32 streamOpenPath();
s32 func_800388A0();
s32 func_800388CC();
s32 setSoundEntryTable();
s32 func_80040770();
s32 func_800415EC();
s32 clearRaceData();
s32 func_800553B0();
s32 func_80057694();
s32 workSlotsInitAll();
s32 func_8005A790();
s32 func_80066B88();
s32 func_8006B7D4();
s32 poolAlloc();
s32 heapQueryFreeSize();
s32 stream_start_check();
s32 dma_thread_start();
s32 func_80081514();
s32 func_80084AA0();
s32 func_80084DD4();
s32 start_track_voices();
s32 voicesSetIdleParams();
s32 func_80086A94();
s32 MusSetMasterVolume(s32, s32);                /* extern */
s32 voicesSetIdleValue();
s32 func_80089980();
s32 memset();
extern char D_15DB10[];
extern s32 *D_8009B770;
extern s32 gSceneHeapBlock;
extern s32 gRaceFlags;
extern char D_800A3F60[];
extern char D_800A3F6C[];
extern char D_800A3F74[];
extern char D_800A3F80[];
extern char D_800A3F90[];
extern char D_800A73E0[];
extern char gOrderState[];
extern char gStreamState[];
extern char D_BB9470[];
extern s32 func_8000E3E4;
extern s32 func_8000E404;

extern s32 D_800B0BD0;
extern u8 D_800B65A0;
extern s32 gRaceState;
extern void * gRecords;
extern s32 D_800C7828;
extern s32 D_800C8124;
extern s32 D_800C837C;
extern u8 D_800C6F18[];
extern u8 D_800C7950[];
extern u8 D_800B7080[];
extern u8 D_800D03D0[];

/* Boot-time setup and main loop: clears the work area, installs the two
 * callbacks, initialises the subsystems, then loops forever servicing the
 * menu, music volume and the screen-state handlers once per frame. */
void game_main(void) {
    s32 *prevHandler;
    s32 ch;
    s32 i;
    void *menuSub;
    s32 screen;

    memset((u8 *)D_800A73E0 + 0x6C0C, 0, 0x460);
    *(s32 * *)(gStreamState + 0x7DFE) = &func_8000E3E4;
    i = 0;
    stream_start_check();
    prevHandler = *(s32 * *)(gStreamState + 0x7DDE);
    *(s32 * *)(gStreamState + 0x7DDE) = &func_8000E404;
    D_8009B770 = prevHandler;
    func_800388A0();
    dma_thread_start();
    func_800388CC();
    func_80081514(&D_15DB10, (u8 *)&D_BB9470 - (u8 *)&D_15DB10, 1);
    func_800553B0();
    func_80040770();
    func_800415EC();
    func_8001BBE4();
    func_8000A140();
    gSceneHeapBlock = poolAlloc(3, 0x54C70);
    func_8000D9CC();
    func_80084AA0();
    func_8006B7D4();
    setSoundEntryTable(D_800C355B);
    clearRaceData();
    timing_ring_push();
    D_800B0BD0 = 0;
    D_800C837C = 0;
    D_800C7828 = 0;
    D_800C8124 = 0;
    M2C_FIELD(gRecords, u16 *, 0x1E) = 7U;
    M2C_FIELD(gRecords, s16 *, 0x20) = 0;
    M2C_FIELD(gRecords, s16 *, 0x22) = 0;
    func_80057694();
    gRaceState = 5;
    workSlotsInitAll();
    func_80066B88();
    D_800B65A0 = 0U;
    do {
        ch = i & 0xFF;
        if ((ch == D_800B65A0) && (func_80084DD4(ch) != 0)) {
            D_800B65A0 = (u8) (D_800B65A0 + 1);
        }
        i += 1;
    } while ((u32) (i & 0xFF) < 2U);
    menuSub = (u8 *)gOrderState + 0x5558;
    streamOpenPath(menuSub, &D_800A3F60);
    start_track_voices(menuSub);
    voicesSetIdleValue((s32) (gSpeedAccum * 80.0f));
    screen = 7;
loop_6:
    func_80086A94();
    func_80089980();
    do { MusSetMasterVolume(3, (s32) (32767.0f * D_800C35D8)); } while (0);
    func_8005A790();
    if (M2C_FIELD(gRecords, u16 *, 0x1E) == screen) {
        gRaceFlags &= ~0x80;
    } else {
        voicesSetIdleParams(1);
    }
    gRaceFlags &= ~0x40;
    func_8000DA84();
    streamOpenPath(D_800B7080, &D_800A3F6C);
    streamOpenPath(D_800C6F18, &D_800A3F74);
    streamOpenPath(D_800D03D0, &D_800A3F80);
    streamOpenPath(D_800C7950, &D_800A3F90);
    func_8000F660();
    if (D_800C7828 == 0) {
        D_800C7828 = heapQueryFreeSize(2);
    }
    if (D_800C8124 == 0) {
        D_800C8124 = heapQueryFreeSize(1);
    }
    func_8000E774();
    goto loop_6;
}
