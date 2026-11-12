/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

/* Calls the handler stored at +0xC of entry index arg0 in the 0x1C-byte table at obj+0xD0, passing (arg1, obj). */
void func_80022988(s32 index, M2C_UNK arg1, void *obj) {
#ifdef PORT
    {
        void *tbl = *(void **)((u8 *)obj + 0xD0);
        M2C_UNK (*fn)(M2C_UNK, void *) = *(M2C_UNK (**)(M2C_UNK, void *))((u8 *)tbl + index * 0x1C + 0xC);
        fn(arg1, obj);
    }
#else
    M2C_FIELD(((index * 0x1C) + M2C_FIELD(obj, s32 *, 0xD0)), M2C_UNK (**)(M2C_UNK, void *), 0xC)(arg1, obj);
#endif
}
