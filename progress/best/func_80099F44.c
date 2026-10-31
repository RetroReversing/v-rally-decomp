s32 func_80099F44(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u64 p;
    u32 t;
    p = (u64)arg1 * (u64)arg2;
    t = (u32)p;
    p = (u64)arg0 * (u64)arg3;
    t += (u32)p;
    p = (u64)arg0 * (u64)arg2;
    (void)(u32)p;
    return (s32)((u32)(p >> 32) + t);
}
