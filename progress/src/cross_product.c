void vec3_cross(s32 *, s32 *, s32 *);
/* Computes cross product of two 3‑component integer vectors, storing result in third argument */ void cross_product(s32 *v1, s32 *v2, s32 *result) { vec3_cross(v1,v2,result); }
