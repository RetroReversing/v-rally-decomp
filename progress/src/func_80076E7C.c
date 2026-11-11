void *named_entry_lookup(void **, u8 *);
s32 named_entry_find_or_add(s32, s32 *, s32 *, s32 *, s32);
s32 func_80073640(s32);
s32 poolAllocNode(s32, s32);
s32 func_80084BF0(s32);
s32 func_80085778(s32, s32);
extern s32 D_800A1740;
extern void *gContCtx;
extern s32 D_800A5E2C;
extern char gOrderState[];
extern char gStreamState[];
extern s32 func_80076D94;
extern s32 stream_list_free;

/* One-time setup for the object at obj+0x28: when named_entry_lookup reports it is not yet
   set up, it resets the controller context and creates its 0x4C-byte block. If the
   stream's current record has no flag 0x1E and has flag 0x1A, it also sets bit 0x800
   on the two task-table entries at 0x2410 and 0x2454. */
void func_80076E7C(s32 obj)
{
    s32 subObj;

    subObj = obj + 0x28;
    if (named_entry_lookup((void **)(subObj), (u8 *)(&D_800A5E2C)) == 0) {
        func_80085778(0, func_80084BF0(0));
        D_800A1740 = 0;
        *(s16 *)((u8 *)gContCtx + 0x1C) = 0;
        func_80073640(poolAllocNode(named_entry_find_or_add(subObj, &func_80076D94, &stream_list_free, &D_800A5E2C, 0), 0x4C));
        if ((*(u16 *)((u8 *)*(void **)(gStreamState + 0x32F2) + 0x1E) == 0) && (*(u16 *)((u8 *)*(void **)(gStreamState + 0x32F2) + 0x1A) != 0)) {
            *(u16 *)(gOrderState + 0x2410) = (u16) (*(u16 *)(gOrderState + 0x2410) | 0x800);
            *(u16 *)(gOrderState + 0x2454) = (u16) (*(u16 *)(gOrderState + 0x2454) | 0x800);
        }
    }
}
