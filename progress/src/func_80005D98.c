s32 func_8007EBF4(s32, s32);
typedef struct VRALPoolObj { u8 pad00[0x10]; s32 start; s32 end; u8 pad18[0x58]; s32 array; u8 pad74[6]; u16 count; } VRALPoolObj;
/* Sets up a pool object's two regions: the block range start..end (sized in 8-byte units) and the array at +0x70 (count * 16 bytes). */
void func_80005D98(void *pool) {
    s32 start;
    s32 array_bytes;
    start = ((VRALPoolObj *)pool)->start;
    array_bytes = ((VRALPoolObj *)pool)->count * 0x10;
    func_8007EBF4(start, ((s32)(((VRALPoolObj *)pool)->end - start) >> 3) * 8);
    func_8007EBF4(((VRALPoolObj *)pool)->array, array_bytes);
}
