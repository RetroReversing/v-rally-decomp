void *select_get_entry(u32);
void *textObjGet(u32);
void *list_advance(u32, void *);
extern void *gSelectState;

/* Looks up the select group for index arg0 (low byte) and sets the byte at +0x1A of each of its
 * text objects, plus the byte at +0x41 of the two select entries it refers to, to arg1. The group's
 * own byte at +0xA is also set to arg1. */
void func_8005803C(s32 arg0, s8 arg1) {
    s32 var_a0;
    void *group;
    void *var_a1;

    group = list_advance(arg0 & 0xFF, (void *)(*(void **)((char *)gSelectState + 0x18)));
    var_a1 = textObjGet(*(s8 *)((char *)group + 9));
    var_a0 = 0;
    if (*(u8 *)((char *)group + 8) != 0) {
        do {
            *(s8 *)((char *)var_a1 + 0x1A) = arg1;
            var_a1 = *(void * *)((char *)var_a1 + 0);
            var_a0 += 1;
        } while ((u32) (var_a0 & 0xFF) < (u8) *(u8 *)((char *)group + 8));
    }
    *(s8 *)((char *)select_get_entry(*(u16 *)((char *)group + 4)) + 0x41) = arg1;
    *(s8 *)((char *)select_get_entry(*(u16 *)((char *)group + 6)) + 0x41) = arg1;
    *(s8 *)((char *)group + 0xA) = arg1;
}
