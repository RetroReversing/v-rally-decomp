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

extern u32 gShadeMode;

/* Reads the shade mode from the object at +0x90 and stores it in gShadeMode when it is a valid mode (below 6). */ void objLoadShadeMode(void *obj) {
    u32 shade_mode;

    shade_mode = M2C_FIELD(obj, u32 *, 0x90);
    if (shade_mode < 6U) {
        gShadeMode = shade_mode;
    }
}
