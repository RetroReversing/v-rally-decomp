/* For the m2c drafts of the functions the split left as data (port only, not matching C). */
#ifndef M2C_UNK
#define M2C_UNK s32
#endif
#ifndef M2C_FIELD
#define M2C_FIELD(expr, type, offset) (*(type)((s8 *)(expr) + (offset)))
#endif
