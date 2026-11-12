void *list_find_node(void **, u8 *);
s32 named_entry_find_or_add(void *, s32 *, s32 *, s32 *, s32);
s32 func_80073640(s32);
s32 poolAllocNode(s32, s32);
s32 input_get_buttons(s32);
s32 input_clear_flags(s32, s32);
extern s32 overlay_frames;
extern void *gControllerInputContext;
extern s32 D_800A5E2C;
extern char gOrderState[];
extern char stream_state[];
extern s32 advanceCarCounters;
extern s32 stream_list_free;

/* One-time setup for the object at obj+0x28: when list_find_node reports it is not yet
   set up, it resets the controller context and creates its 0x4C-byte block. If the
   stream's current record has no flag 0x1E and has flag 0x1A, it also sets bit 0x800
   on the two task-table entries at 0x2410 and 0x2454. */
void func_80076E7C(u8 *obj)
{
    u8 *subObj;

    subObj = obj + 0x28;
    if (list_find_node((void **)(subObj), (u8 *)(&D_800A5E2C)) == 0) {
        input_clear_flags(0, input_get_buttons(0));
        overlay_frames = 0;
        *(s16 *)((u8 *)gControllerInputContext + 0x1C) = 0;
        func_80073640(poolAllocNode(named_entry_find_or_add(subObj, &advanceCarCounters, &stream_list_free, &D_800A5E2C, 0), 0x4C));
        if ((*(u16 *)((u8 *)*(void **)(stream_state + 0x32F2) + 0x1E) == 0) && (*(u16 *)((u8 *)*(void **)(stream_state + 0x32F2) + 0x1A) != 0)) {
            *(u16 *)(gOrderState + 0x2410) = (u16) (*(u16 *)(gOrderState + 0x2410) | 0x800);
            *(u16 *)(gOrderState + 0x2454) = (u16) (*(u16 *)(gOrderState + 0x2454) | 0x800);
        }
    }
}
