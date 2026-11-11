extern void guNormalize(float *x, float *y, float *z);
extern void guMtxIdentF(float mf[4][4]);
extern float __sinf(float angle);
extern float __cosf(float angle);

/* Builds a 4x4 float matrix that rotates by angle (degrees) about the axis (x, y, z).
   The axis is normalised first; the result is written into mf. */
void guRotateF(float mf[4][4], float angle, float x, float y, float z)
{
	static float	dtor = 3.1415926 / 180.0;
	float	sine;
	float	cosine;
	float	ab, bc, ca, t;

	guNormalize(&x, &y, &z);
	angle *= dtor;
	sine = __sinf(angle);
	cosine = __cosf(angle);
	t = (1 - cosine);
	ab = x * y * t;
	bc = y * z * t;
	ca = z * x * t;

	guMtxIdentF(mf);

	t = x * x;
	mf[0][0] = t + cosine * (1 - t);
	mf[2][1] = bc - (x * sine);
	mf[1][2] = bc + (x * sine);

	t = y * y;
	mf[1][1] = t + cosine * (1 - t);
	mf[2][0] = ca + (y * sine);
	mf[0][2] = ca - (y * sine);

	t = z * z;
	mf[2][2] = t + cosine * (1 - t);
	mf[1][0] = ab - (z * sine);
	mf[0][1] = ab + (z * sine);
}
