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

s32 poolAlloc(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK pool_node_clear(s32);                         /* extern */

/* Allocates a 12-byte node from pool 1 and clears it. */
s32 poolAllocHeadNode(void) {
    s32 node;

    node = poolAlloc(1, 0xC);
    pool_node_clear(node);
    return node;
}
