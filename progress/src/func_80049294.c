extern s32 gPadFlags;
extern u8 *gRaceCtx;
extern u8 *gRecords;
extern s32 g_camera;
extern u8 D_800C8120;
extern s32 find_object_by_id(s32);
extern void func_8004BEB4(void);
extern s32 func_80084BF0(s32);
extern void func_80085778(u8, s32);
extern void MusSetMasterVolume(s32, s32);
extern void func_8002FE78(void);

/* Per-frame pause and input handling: clears the per-slot results, takes the
 * pause-button state, polls every input slot and records the first one that
 * requests a pause, then starts or stops pause mode from gPadFlags. */
void func_80049294(void) {
    s32 results[4];
    s32 temp;
    s32 value;
    u32 i;
    s32 pad[0];

    i = 0;
    {s32 *q = results;
    do {
        *q = 0;
        i++;
        q++;
    } while (i < 4);
    }
    {u8 *state = gRaceCtx; u8 *input = gRecords;
    u8 paused;
    u8 btn;
    paused = state[0x384];
    btn = input[0xF];
    if (paused) {
        g_camera = find_object_by_id((btn << 1) + 2);
        func_8004BEB4();
    }
    }
    value=0;
    for(i=0;i<*(u16*)(gRecords+0xE);i++){
        temp=func_80084BF0(i&255);
        results[i]=temp;
        if(temp){
            value=temp;
            if(!gRaceCtx[0x384] && (value&0x1000)){
                gRaceCtx[0x382]=i;
                break;
            }
        }
    }
    if (!(gPadFlags & 0x200)) {
        if (gRaceCtx[0x384] == 0 &&
            (value & 0x1000) &&
            (gPadFlags & 1) &&
            *(u16 *)(gRecords + 0x1E) != 8) {
            func_80085778(gRaceCtx[0x382], 0x8000);
            gRaceCtx[0x384] = 1;
            MusSetMasterVolume(3, 0);
            gPadFlags &= ~0x4000;
            func_8002FE78();
        }
    } else {
        func_80085778(0, value);
        if (!(gPadFlags & 1)) {
            gPadFlags &= ~0x200;
            D_800C8120 = 0;
        }
    }
}
