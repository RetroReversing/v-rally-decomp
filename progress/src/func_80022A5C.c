/* Calls the callback at +0x18 of table entry arg0 (0x1C-byte entries, table pointer at obj+0xD0), passing obj. */
void func_80022A5C(s32 arg0, void *arg1) {
#ifdef PORT
    {
        void *tbl = *(void **)((char *)arg1 + 0xD0);
        void (*fn)(void *) = *(void (**)(void *))((char *)tbl + arg0 * 0x1C + 0x18);
        fn(arg1);
    }
#else
    (*(void (**)(void *))(*(s32 *)((char *)arg1 + 0xD0) + arg0 * 0x1C + 0x18))(arg1);
#endif
}
