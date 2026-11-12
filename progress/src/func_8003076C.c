typedef struct { u8 pad00[6]; u16 x, y, z; } VRFuncTriple;
typedef struct { u8 pad00[0x1C]; VRFuncTriple *items; } VRFuncSub;

/* Copies the x, y, z words of item `index` (12-byte records) into out, if index is below the count at +0x88. */
void func_8003076C(void *arg0, s32 arg1, void *arg2)
{
    s32 temp_v1;

    if (arg1 < (s32) *(u16 *)((u8 *)arg0 + 0x88)) {
        temp_v1 = arg1 * 0xC;
#ifdef PORT
        {
            u8 *rec = (u8 *)((VRFuncSub *)*(void **)((u8 *)arg0 + 0x78))->items + temp_v1;
            *(u16 *)arg2 = (u16) *(u16 *)(rec + 6);
            *(u16 *)((u8 *)arg2 + 2) = (u16) *(u16 *)(rec + 8);
            *(u16 *)((u8 *)arg2 + 4) = (u16) *(u16 *)(rec + 0xA);
        }
#else
        *(u16 *)arg2 = (u16) *(u16 *)((temp_v1 + (s32)((VRFuncSub *)*(void **)((u8 *)arg0 + 0x78))->items) + 6);
        *(u16 *)((u8 *)arg2 + 2) = (u16) *(u16 *)((temp_v1 + (s32)((VRFuncSub *)*(void **)((u8 *)arg0 + 0x78))->items) + 8);
        *(u16 *)((u8 *)arg2 + 4) = (u16) *(u16 *)((temp_v1 + (s32)((VRFuncSub *)*(void **)((u8 *)arg0 + 0x78))->items) + 0xA);
#endif
    }
}
