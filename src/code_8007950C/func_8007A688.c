#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif
void *select_get_entry(u32);
void *list_advance(u32, void *);
extern void *gSelectState;

/* Sets the select state's byte at +0x237 to byte +0x22 of the list entry picked
 * by list_advance(state+0x239, entry(state+0x238)->+0x28). */
void func_8007A688(void) {
    M2C_FIELD(gSelectState, u8 *, 0x237) = (u8) M2C_FIELD(list_advance(M2C_FIELD(gSelectState, u8 *, 0x239), (void *)(M2C_FIELD(select_get_entry((u8)(M2C_FIELD(gSelectState, u8 *, 0x238))), void **, 0x28))), u8 *, 0x22);
}

