
s32 func_80040084(s32, s32, s32);
s32 func_80098180(const void *, const void *);
extern u8 D_8009FE40[];

typedef s32 (*Handler)(void *, void *, s32);
typedef struct Entry { const void *key; Handler handler; s32 value; } Entry;

s32 func_8003FFB4(void *arg0, void *arg1) {
    Entry *entry;
    s32 result = 0;
    u8 done = 0;
    entry = (Entry *)D_8009FE40;
    while (entry->handler != NULL) {
        if (func_80098180((u8 *)arg1 + 0x4C, entry->key) == 0) {
            result = *(s32 *)((u8 *)arg0 + 4);
            entry->handler(arg0, arg1, entry->value);
            if (*(s32 *)((u8 *)arg0 + 4) != result) {
                result = *(s32 *)((u8 *)arg0 + 4);
            } else {
                result = 0;
                done = 1;
            }
        }
        entry++;
        if (done) break;
    }
    if (!done) result = func_80040084((s32)arg0, (s32)arg1, 0);
    return result;
}
