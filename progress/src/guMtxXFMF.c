typedef f32 Mtx4F[4][4];

/* Transforms the point (x, y, z) by the float matrix m (translation in row 3) and
   writes the result to *dx, *dy, *dz. */
void guMtxXFMF(Mtx4F *m, f32 x, f32 y, f32 z, f32 *dx, f32 *dy, f32 *dz) {
    *dx = ((*m)[0][0] * x) + ((*m)[1][0] * y) + ((*m)[2][0] * z) + (*m)[3][0];
    *dy = ((*m)[0][1] * x) + ((*m)[1][1] * y) + ((*m)[2][1] * z) + (*m)[3][1];
    *dz = ((*m)[0][2] * x) + ((*m)[1][2] * y) + ((*m)[2][2] * z) + (*m)[3][2];
}
