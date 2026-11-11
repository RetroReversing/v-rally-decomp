#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif
s32 MapTypeCode(s32);

/* If the record's type code (at rec+0) is below 5, stores MapTypeCode(type) in
 * the record's value field (at rec+0x20). */
void UpdateTypeValue(void *obj) {
    s32 type;

    type = M2C_FIELD(M2C_FIELD(obj, void **, 0x48), s32 *, 0);
    if (type < 5) {
        M2C_FIELD(M2C_FIELD(obj, void **, 0x48), s32 *, 0x20) = (s32) (MapTypeCode(type & 0xFFFF) & 0xFFFF);
    }
}
