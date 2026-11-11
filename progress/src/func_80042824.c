s32 flag_test_bit0();
s32 getTexturePack();
s32 func_800427CC();
void *poolAllocNode();
s32 resolve_path();
extern char D_800A4DC0[];
extern char gOrderState[];

/* Loads the texture pack for the given id, runs the setup if the state at gOrderState+0x73C0
   is not ready, and allocates a 0x14-byte record that stores the pack and three colour bytes. */
void func_80042824(s32 pack_id, s8 red, s8 green, s8 blue) {
    s32 pack;
    void *rec;

    if (flag_test_bit0(gOrderState + 0x73C0) == 0) {
        func_800427CC();
    }
    resolve_path(&D_800A4DC0);
    pack = getTexturePack(pack_id, 0);
    rec = poolAllocNode(*(s32 *)(gOrderState + 0x87F4), 0x14);
    *(s32 *)((char *)rec + 0xC) = pack;
    *(s8 *)((char *)rec + 0x10) = red;
    *(s8 *)((char *)rec + 0x11) = green;
    *(s8 *)((char *)rec + 0x12) = blue;
    *(s8 *)((char *)rec + 0x13) = 0;
}
