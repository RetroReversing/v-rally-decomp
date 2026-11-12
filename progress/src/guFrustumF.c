void guMtxIdentF(float mf[4][4]);

/* Builds a perspective frustum matrix in float form (left/right/bottom/top/near/far), then
 * scales every entry by scale. The result is still float; guMtxF2L converts it to a Mtx. */
void guFrustumF(float mf[4][4], float left, float right, float bottom, float top, float near, float far, float scale)
{
	int	i, j;

	guMtxIdentF(mf);

	mf[0][0] = 2*near/(right-left);
	mf[1][1] = 2*near/(top-bottom);
	mf[2][0] = (right+left)/(right-left);
	mf[2][1] = (top+bottom)/(top-bottom);
	mf[2][2] = -(far+near)/(far-near);
	mf[2][3] = -1;
	mf[3][2] = -2*far*near/(far-near);
	mf[3][3] = 0;

	for (i=0; i<4; i++)
	    for (j=0; j<4; j++)
		mf[i][j] *= scale;
}
