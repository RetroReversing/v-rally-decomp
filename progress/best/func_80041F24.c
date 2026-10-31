extern char D_800A0130[];
extern char D_800C02AE[];
extern s32 D_800C7F84;
s32 func_8004240C(s32, s32, s32);
void *func_8002255C(void *, void *);
s32 func_800223B4(s32, s32, s32, void *, s32);
typedef struct { char pad[8]; void (*cb)(s32, void *); s32 a, b; } Entry;
s32 func_80041F24(void *arg0, s32 arg1) {
    s32 a3, a0, v, result;
    u16 a2;
    Entry *entry;
    a3 = *(s32 *)((char *)arg0 + 0x90);
    a0 = a3;
    a2 = *(u16 *)(*(char **)(D_800C02AE + 0x32F2) + 0xE);
    if ((a0 & 255) == 3) a0 = (a2 * 2) | 1;
    else if (a0 & 255) a0 = ((arg1 & 255) * 2) - a3;
    v = func_8004240C(a0 & 255, a2, a3);
    D_800C7F84 = v;
    entry = func_8002255C(D_800A0130, (char *)arg0 + 0x98);
    result = func_800223B4(v + 0x28, entry->a, entry->b, entry, *(s32 *)((char *)arg0 + 0x174));
    if (entry->cb) entry->cb(result, arg0);
    return result;
}
