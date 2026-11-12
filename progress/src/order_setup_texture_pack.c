extern s32 D_800A1240;
extern char D_800A4FEC[];
extern char gOrderState[];
extern s32 order_release_if_flagged;
s32 flag_set_then_call(void *, s32 *);
s32 getTexturePack(s32, s32);
s32 resolve_path(void *);

/* Registers order_release_if_flagged on the flag at gOrderState+0x73E0, resolves the path D_800A4FEC, and stores the texture pack for index in D_800A1240. */
void order_setup_texture_pack(s32 index)
{
    flag_set_then_call(gOrderState + 0x73E0, &order_release_if_flagged);
    resolve_path(&D_800A4FEC);
    D_800A1240 = getTexturePack(index, 0);
}
