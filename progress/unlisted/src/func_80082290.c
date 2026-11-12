s32 streamReadBytes();
extern char gOrderState[];

s32 func_80082290(s32 arg0) {
    if (arg0 != 0) {
        streamReadBytes(gOrderState + 0x8A30, arg0);
        *(gOrderState + 0x8A30 + arg0) = 0;
    }
    return 0;
}
