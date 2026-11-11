/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -g3, tried by autopilot */
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

extern int D_800C7920;
s32 flag_set_then_call();
s32 poolAllocHeadNode();
extern char gOrderState[];
extern char gStreamState[];
extern s32 func_80047C78;

void func_80047564(void) {
    D_800C7920 = poolAllocHeadNode();
    flag_set_then_call(gOrderState + 0x7380, &func_80047C78);
}
