s32 func_8008188C(s32, s32);
void osWritebackDCacheAll(void);

/* Calls func_8008188C with the arguments swapped, writes back the data cache, and returns its result. */
s32 func_80081664(s32 arg0, s32 arg1) {
    s32 result;

    result = func_8008188C(arg1, arg0);
    osWritebackDCacheAll();
    return result;
}
