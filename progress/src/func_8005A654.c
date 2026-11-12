#ifdef PORT
extern u8 *gSelectState;
#else
extern s32 gSelectState;
#endif
void *textObjGet(u32 index);

/* Returns the state word for object index: its slot (byte 0xA, scaled by 4) indexes the select state table at +0xE4. */
s32 func_8005A654(u32 index) {
    #ifdef PORT
    return *(s32 *)(gSelectState + (*(s8 *)((s8 *)textObjGet(index) + 0xA) * 4) + 0xE4);
#else
    return *(s32 *)((s8 *)((*(s8 *)((s8 *)textObjGet(index) + 0xA) * 4) + gSelectState) + 0xE4);
#endif
}
