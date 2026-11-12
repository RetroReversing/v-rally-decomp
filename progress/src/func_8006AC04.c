typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

void *func_800051B4(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
M2C_UNK view_set_rect(void *, s32);
M2C_UNK view_get_ctx_id(void *);
M2C_UNK func_80005718(s32, void *);
M2C_UNK streamObjDestroy(void *);
M2C_UNK func_80005A54(s32, s32);
M2C_UNK view_gfx_setup(void *);
M2C_UNK func_8000E8FC(void *, s32, M2C_UNK);
M2C_UNK func_8005A790(void);
s32 taskOpen(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8007F634(s32);
M2C_UNK taskRecvMsg(s32);
extern s32 gSceneSlot0;
extern s32 gSceneSlot1;
extern u8 gSelectResetPending;
extern u8 gSelectResetFlag;
extern u8 select_reset_requested;
extern M2C_UNK stream_state;

/* Start-up step for the game screen. If any of the three flag bytes is set and
   the state at stream_state+0x32F2 (+0x1E) is not 8, it calls func_8005A790 and
   stops. Otherwise it builds the screen object and runs the setup sequence. */
void func_8006AC04(void) {
    s32 slot_a;
    s32 slot_b;
    void *obj;

    if (((gSelectResetFlag != 0) || (gSelectResetPending != 0) || (select_reset_requested != 0)) && (M2C_FIELD(M2C_FIELD(&stream_state, void **, 0x32F2), u16 *, 0x1E) != 8)) {
        func_8005A790();
        return;
    }
    slot_a = taskOpen(6, 2, 1);
    slot_b = taskOpen(9, 2, 0x10);
    obj = func_800051B4(gSceneSlot0, 0, 0xBB8, 0xBB8, 0);
    M2C_FIELD(obj, s8 *, 0x10) = 0;
    M2C_FIELD(obj, s8 *, 0x11) = 0;
    M2C_FIELD(obj, s8 *, 0x12) = 0;
    view_gfx_setup(obj);
    view_set_rect(obj, gSceneSlot0);
    view_get_ctx_id(obj);
    func_8000E8FC(obj, gSceneSlot0, 0);
    M2C_FIELD(&stream_state, s8 *, 0x5BA6) = 1;
    func_80005718(gSceneSlot0, obj);
    taskRecvMsg(slot_b);
    func_80005A54(gSceneSlot0, gSceneSlot1);
    taskRecvMsg(slot_a);
    func_80005A54(gSceneSlot0, gSceneSlot1);
    taskRecvMsg(slot_a);
    func_80005A54(gSceneSlot0, gSceneSlot1);
    taskRecvMsg(slot_a);
    streamObjDestroy(obj);
    func_8007F634(slot_b);
    func_8007F634(slot_a);
}
