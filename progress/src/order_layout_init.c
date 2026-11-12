extern char gOrderState[];

s32 func_80022068(void *, s32);

/* Resets the order screen's scroll counter and sets the offsets of its layout fields (half-size, top, and origin values) from the state block, then calls func_80022068 with the object's 0x48 field. */ void order_layout_init(void *obj) {
    s32 c;
    s32 top;
    char *state;

    *(s32 *)(*(char **)((char *)obj + 0x54) + 0xA4) = 0;
    *(s32 *)(*(char **)((char *)obj + 0x80) + 0x10) = *(s32 *)(*(char **)((char *)obj + 0x80) + 0x390) >> 1;
    *(s32 *)(*(char **)((char *)obj + 0x80) + 0x14) = *(s32 *)(*(char **)((char *)obj + 0x80) + 4) + 0x1E;
    c = 0x80;
    *(s32 *)(*(char **)((char *)obj + 0x80) + 0x18) = c;
    *(s32 *)(*(char **)((char *)obj + 0x80) + 0x24) = -(*(s32 *)(*(char **)((char *)obj + 0x80) + 0x390) >> 1);
    *(s32 *)(*(char **)((char *)obj + 0x80) + 0x28) = *(s32 *)(*(char **)((char *)obj + 0x80) + 4) + 0x1E;
    *(s32 *)(*(char **)((char *)obj + 0x80) + 0x2C) = c;
    *(s32 *)(*(char **)((char *)obj + 0x80) + 0x38) = *(s32 *)(*(char **)((char *)obj + 0x80) + 0x394) >> 1;
    *(s32 *)(*(char **)((char *)obj + 0x80) + 0x3C) = *(s32 *)(*(char **)((char *)obj + 0x80) + 4) + 0x1E;
    *(s32 *)(*(char **)((char *)obj + 0x80) + 0x40) = c - *(s32 *)(*(char **)((char *)obj + 0x80) + 0x398);
    *(s32 *)(*(char **)((char *)obj + 0x80) + 0x4C) = -(*(s32 *)(*(char **)((char *)obj + 0x80) + 0x394) >> 1);
    state = *(char **)((char *)obj + 0x80);
    top = *(s32 *)(state + 4);
    *(s32 *)(gOrderState + 0x80A4) = 0;
    *(s32 *)(state + 0x50) = top + 0x1E;
    *(s32 *)(*(char **)((char *)obj + 0x80) + 0x54) = c - *(s32 *)(*(char **)((char *)obj + 0x80) + 0x398);
    func_80022068(obj, *(s32 *)(*(char **)((char *)obj + 0x84) + 0x48));
}
