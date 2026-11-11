/* Refreshes two fields of obj from its sub-objects: when the controller at
 * sub->+0x24 is present, copies its state word (+0x6C -> +8) into obj+0x7A and
 * sets obj+0xE to the sub-object's +0xA value plus 6 (state 1) or 0x10 (other). */
void func_8003E0D4(void *obj) {
    s16 val;
    void *ctrl;

    ctrl = *(void **)(*(void **)((char *)obj + 0xA8) + 0x24);
    if (ctrl != NULL) {
        *(s16 *)((char *)obj + 0x7A) = (s16) *(s32 *)(*(void **)((char *)ctrl + 0x6C) + 8);
        if (*(s32 *)(*(void **)((char *)ctrl + 0x6C) + 8) == 1) {
            val = *(u16 *)(*(void **)(*(void **)((char *)obj + 0xA8) + 0x178) + 0xA) + 6;
        } else {
            val = *(u16 *)(*(void **)(*(void **)((char *)obj + 0xA8) + 0x178) + 0xA) + 0x10;
        }
        *(s16 *)((char *)obj + 0xE) = val;
    }
}
