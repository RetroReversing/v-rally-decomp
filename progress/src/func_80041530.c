extern s32 gSlotTableB[];

s32 func_80041530(s32 arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = gSlotTableB[arg0];
    return temp_v1 + arg1 * 0x2C4;
}
