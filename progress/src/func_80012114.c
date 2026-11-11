/* Voice/channel state block; offsets from func_80011058 and func_80012114. */
typedef struct VRChannelState {
    u8 pad00[16];
    s32 volume;      /* +0x10 */
    s32 pitch;       /* +0x14 */
    s32 pan;         /* +0x18 */
    u8 pad1C[0x4E];
    s16 rate;        /* +0x6A, 0x1000 = unity */
} VRChannelState;

extern s32 D_8009BA30;
void func_80011058(VRChannelState *state, s32 table, s32 index);

/* Loads table entry 'table' (entry 4) into the channel state, sets the flag D_8009BA30,
 * then writes the fixed default volume, pitch, pan and rate. */
void func_80012114(VRChannelState *state, s32 table) {
    func_80011058(state, table, 4);
    D_8009BA30 = 1;
    state->volume = 0x80;
    state->pitch = 0x14;
    state->pan = 5;
    state->rate = 0x1000;
}
