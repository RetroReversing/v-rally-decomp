/* Transforms the vector (x, y, z) by the upper 3x3 of the 4x4 float matrix at mtx (row-major,
   rows 16 bytes apart) and writes the result to out_x, out_y and out_z. */
void vec3_transform_mtx3(void *mtx, f32 x, f32 y, f32 z, f32 *out_x, f32 *out_y, f32 *out_z) {
    f32 *m = (f32 *)mtx;

    *out_x = (m[0] * x) + (m[4] * y) + (m[8] * z);
    *out_y = (m[1] * x) + (m[5] * y) + (m[9] * z);
    *out_z = (m[2] * x) + (m[6] * y) + (m[10] * z);
}
