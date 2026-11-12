void *mat3_mul_vec3(void *, void *, void *);

void *mtx3_transform_vec3(void *mat, void *vec, void *dst)
{
    /* Thin wrapper: applies a 3x3 matrix to a 3-vector and returns dst. */
    return mat3_mul_vec3(mat, vec, dst);
}
