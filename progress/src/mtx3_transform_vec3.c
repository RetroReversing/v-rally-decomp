void *mat3_mul_vec3(void *, void *, void *);
void *mtx3_transform_vec3(void *a, void *b, void *c) { return mat3_mul_vec3(a,b,c); }
