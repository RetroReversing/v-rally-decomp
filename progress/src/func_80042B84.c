s32 flag_test_bit0();
s32 getTexturePack();
s32 func_80042B2C();
void *poolAllocNode();
s32 resolve_path();
extern char D_800A4DDC[];
extern char gOrderState[];

/* Resolves the path and texture pack for a new 0x14-byte record, then fills in its id and four state bytes. */
void func_80042B84(s32 pack, s8 mode, s8 flagA, s8 flagB, u8 flagC) {
    s32 texPack;
    void *rec;

    if (flag_test_bit0(gOrderState + 0x73E8) == 0) {
        func_80042B2C();
    }
    resolve_path(&D_800A4DDC);
    texPack = getTexturePack(pack, 0);
    rec = poolAllocNode(*(s32 *)(gOrderState + 0x2354), 0x14);
    *(s32 *)((char *)rec + 0xC) = texPack;
    *(s8 *)((char *)rec + 0x10) = mode;
    *(s8 *)((char *)rec + 0x11) = flagA;
    *(s8 *)((char *)rec + 0x12) = flagB;
    *(u8 *)((char *)rec + 0x13) = flagC;
}
