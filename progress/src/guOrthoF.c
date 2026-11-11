extern void guMtxIdentF(float mf[4][4]);

/* Builds an orthographic projection matrix in float form for the box [l,r]x[b,t]x[n,f], then scales every entry by scale. */
void guOrthoF(float mf[4][4], float l, float r, float b, float t, float n, float f, float scale)
{
	int	row, col;

	guMtxIdentF(mf);

	mf[0][0] = 2/(r-l);
	mf[1][1] = 2/(t-b);
	mf[2][2] = -2/(f-n);
	mf[3][0] = -(r+l)/(r-l);
	mf[3][1] = -(t+b)/(t-b);
	mf[3][2] = -(f+n)/(f-n);
	mf[3][3] = 1;

	for (row=0; row<4; row++)
	    for (col=0; col<4; col++)
		mf[row][col] *= scale;
}
