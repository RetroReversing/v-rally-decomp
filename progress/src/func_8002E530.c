s32 *mat3_transform_vec(s16 *, s16 *, s32 *);
/* Thin wrapper: transforms a vector by a 3x3 matrix via mat3_transform_vec. */ s32 *func_8002E530(s16 *matrix, s16 *vec, s32 *out) { return mat3_transform_vec(matrix,vec,out); }
