void guMtxIdentF(void *);
void guMtxF2L(void *, void *);

/* Builds an orthographic projection (left/right, bottom/top, near/far) into the
   Mtx m, scaled by scale. */
void guOrtho(void *m, float left, float right, float bottom, float top, float near, float far, float scale) {
    float ortho[4][4];
    float *cell = &ortho[0][0];
    int row, col;
    guMtxIdentF(cell);
    ortho[0][0] = 2/(right-left);
    ortho[1][1] = 2/(top-bottom);
    ortho[2][2] = -2/(far-near);
    ortho[3][0] = -(right+left)/(right-left);
    ortho[3][1] = -(top+bottom)/(top-bottom);
    ortho[3][2] = -(far+near)/(far-near);
    ortho[3][3] = 1;
    for (row=0; row<4; row++, cell+=4) {
        col = 0;
        while (col < 4) {
            cell[col] *= scale;
            col++;
        }
    }
    guMtxF2L(ortho, m);
}
