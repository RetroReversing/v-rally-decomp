s32 order_start(s32, s32);

/* Starts the order stored in the object for the given argument. */
void func_8000DF50(s32 arg, void *obj) {
    order_start(*(s32 *)((s8 *)obj + 0x20), arg);
}
