#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

#define S_RESET_PENDING 0x2BE  /* set: run the reset in stream_free_all_blocks */
#define S_ITEM_DIRTY    0x29F  /* set: refresh the current item's entry */
#define S_TIMER_ACTIVE  0x29A  /* countdown in S_TIMER is running */
#define S_TIMER         0x2BA  /* countdown; 0 ends the timer */
#define S_PANEL_SHOW    0x29B  /* set: show the panel (func_800591E4) */
#define S_PANEL_READY   0x299  /* panel is open */
#define S_BUSY          0x298  /* a panel transition is in progress */
#define S_ITEM_NEXT     0x29D  /* set: open the next item */
#define S_ITEM_CHANGE   0x29E  /* set: item selection changed */
#define S_START_REQ     0x29C  /* set: start a panel from the menu */
#define S_STARTED       0x246  /* panel start was requested */
#define S_HOLD          0x2BC  /* countdown before the hold ends */
#define S_HOLD_TICK     0x2BB  /* countdown; 0 sets S_DONE */
#define S_DONE          0x2A0  /* set: the menu sequence has finished */

M2C_UNK fade_start(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK stream_free_all_blocks();
M2C_UNK func_800588E0(void *);
M2C_UNK func_800591E4(void *);
M2C_UNK select_reset_state(void *);
M2C_UNK func_8005A100();
M2C_UNK func_8005A2D0(M2C_UNK);
M2C_UNK func_80089B8C(void *);
M2C_UNK workSlotInit(void *, M2C_UNK *, M2C_UNK *);
M2C_UNK copyWorkSlotEntry(void *, void *);
M2C_UNK func_80089FD4(void *, void *);
extern u8 gWorkSlots;
extern u8 D_800A13B6;
extern M2C_UNK D_800A13D0;
extern u8 *gSelectState;
extern M2C_UNK gOrderState;
extern M2C_UNK stream_state;
extern M2C_UNK func_80058E28;
extern M2C_UNK func_8005914C;
extern u8 D_800C6004, D_800AFA5C;
extern void *gLeague;

/* Per-frame update of the menu sequence state in gSelectState. Each block
 * handles one request flag, in order: reset, item refresh, timer countdown,
 * panel show, next item, start and the hold countdown. */
void func_8005B6A8(void)
{
    M2C_UNK (*temp_v0)();
    u8 temp_v0_2;
    u8 temp_v0_3;
    void *temp_v1;
    void *temp_v1_2;

    if (gSelectState[S_RESET_PENDING] != 0) {
        stream_free_all_blocks();
        gSelectState[S_RESET_PENDING] = 0U;
    }
    temp_v1 = gSelectState;
    if (gSelectState[S_ITEM_DIRTY] != 0) {
        gSelectState[S_ITEM_DIRTY] = 0U;
        func_80089FD4((D_800C6004 * 0x24) + &gWorkSlots, gLeague);
        #ifdef PORT
        *(&D_800A13B6 + (D_800C6004 * 0x24)) = *((u8 *)M2C_FIELD(gLeague, void **, 0x10) + (M2C_FIELD(gLeague, s16 *, 2) * 0x14) + 0xD);
#else
        *(&D_800A13B6 + (D_800C6004 * 0x24)) = M2C_FIELD(((M2C_FIELD(gLeague, s16 *, 2) * 0x14) + M2C_FIELD(gLeague, s32 *, 0x10)), u8 *, 0xD);
#endif
    }
    if (gSelectState[S_TIMER_ACTIVE] != 0) {
        gSelectState[S_TIMER] = (u8) (gSelectState[S_TIMER] - 1);
        if (gSelectState[S_TIMER] == 0) {
            gSelectState[S_TIMER_ACTIVE] = 0;
            gSelectState[S_BUSY] = 0U;
            func_8005A100();
        }
    }
    if ((gSelectState[S_PANEL_SHOW] != 0) && (gSelectState[S_BUSY] == 0)) {
        gSelectState[S_PANEL_SHOW] = 0U;
        gSelectState[S_PANEL_READY] = 0U;
        func_800591E4(gLeague);
    }
    temp_v1_2 = gSelectState;
    if ((gSelectState[S_ITEM_NEXT] != 0) && (gSelectState[S_PANEL_READY] == 0)) {
        gSelectState[S_ITEM_NEXT] = 0U;
        gSelectState[S_PANEL_READY] = 1U;
        func_800588E0(gSelectState + 0x2AD);
        if ((gSelectState[S_ITEM_CHANGE] != 0) && (gSelectState[S_PANEL_READY] != 0)) {
            gSelectState[S_ITEM_CHANGE] = 0U;
            workSlotInit((D_800AFA5C * 0x24) + &gWorkSlots, &func_80058E28, &func_8005914C);
        }
        copyWorkSlotEntry((D_800AFA5C * 0x24) + &gWorkSlots, gLeague);
        temp_v0 = *(M2C_UNK (**)())((u8*)&D_800A13D0 + (D_800AFA5C * 0x24));
        if (temp_v0 != NULL) {
            temp_v0();
        }
    }
    if ((gSelectState[S_START_REQ] != 0) && (gSelectState[S_PANEL_READY] != 0) && (gSelectState[S_TIMER] == 0)) {
        if (M2C_FIELD(&gOrderState, s32 *, 0x7410) == 0) {
            fade_start(0, 3, 1);
        }
        gSelectState[S_START_REQ] = 0;
        gSelectState[S_BUSY] = 1U;
        select_reset_state(gSelectState + 0x2A1);
        gSelectState[S_STARTED] = 1U;
        gSelectState[S_HOLD] = 3U;
    }
    temp_v0_2 = gSelectState[S_HOLD_TICK];
    if (temp_v0_2 != 0) {
        gSelectState[S_HOLD_TICK] = (u8) (temp_v0_2 - 1);
        if (gSelectState[S_HOLD_TICK] == 0) {
            gSelectState[S_DONE] = 1U;
        }
    }
    if ((gSelectState[S_BUSY] != 0) && (gSelectState[S_TIMER] == 0)) {
        if (gSelectState[S_STARTED] == 0) {
            func_80089B8C(gLeague);
        } else {
            gSelectState[S_STARTED] = 0U;
        }
    }
    if ((*(u16 *)(gSelectState + S_TIMER) == 0) && (gSelectState[S_DONE] == 0) && (gSelectState[S_BUSY] != 0)) {
        temp_v0_3 = gSelectState[S_HOLD];
        if (temp_v0_3 == 0) {
            func_8005A2D0(1);
            return;
        }
        gSelectState[S_HOLD] = (u8) (temp_v0_3 - 1);
    }
}
