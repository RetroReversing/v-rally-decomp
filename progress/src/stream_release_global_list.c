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

void stream_release_list(void **list_head);
extern M2C_UNK D_8009B8BC;

/* Releases the global stream list (gStreamList, at D_8009B8BC + 0x58F4). */
void stream_release_global_list(void) {
    stream_release_list(M2C_FIELD(&D_8009B8BC, void **, 0x58F4));
}
