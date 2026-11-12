s32 record_reset(s32);
s32 streamCtlReset();
s32 text_load_and_parse(s32 *, s32);
s32 stream_free_all_blocks();
s32 clearRaceData();
s32 func_80057810(s32);
s32 object_free_blocks(s32);
s32 select_group_set_value(s32, s32);
s32 func_8005BB5C();
s32 select_clear_slots();
s32 func_8005EB48();
s32 race_reset_and_save();
s32 func_8006E33C();
s32 save_race_to_pak();
s32 stream_clear_scratch();
extern u8 *gSelectState;
extern s32 D_800A14C0;
extern s8 D_800A16F0;
extern s32 D_800A54F0;
extern u8 stream_state[];

/* Resets the select and stream state before a new session: clears the select
 * flags, the stream counters and the race data, then reloads the stream timer. */
s32 func_8005F460(void)
{
    select_group_set_value(0, 0);
    *(s8 *)(gSelectState + 0x24D) = 0;
    D_800A16F0 = 0;
    record_reset(*(s32 *)(stream_state + 0x32F2));
    streamCtlReset();
    stream_clear_scratch();
    D_800A16F0 = 0;
    text_load_and_parse(&D_800A54F0, 0);
    race_reset_and_save();
    func_8006E33C();
    save_race_to_pak();
    clearRaceData();
    *(s32 *)(stream_state + 0x32AA) = 0;
    object_free_blocks(*(s32 *)(stream_state + 0x807A));
    *(s32 *)(stream_state + 0x807A) = func_80057810(D_800A14C0);
    select_clear_slots();
    func_8005BB5C();
    stream_free_all_blocks();
    func_8005EB48();
    return 0;
}
