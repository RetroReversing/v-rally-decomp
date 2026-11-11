extern float __libm_qnan_f;

/* Multiplies two 4x4 float matrices: res = mf * nf. The product goes through a
 * temporary so res may alias one of the inputs. */
void guMtxCatF(float mf[4][4], float nf[4][4], float res[4][4])
{
    int i, j, k;
    float temp[4][4];

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp[i][j] = 0.0;
            for (k = 0; k < 4; k++) {
                temp[i][j] += mf[i][k] * nf[k][j];
            }
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            res[i][j] = temp[i][j];
        }
    }
}
