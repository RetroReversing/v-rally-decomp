typedef struct { f32 m[4][4]; } Mtx;
extern f32 D_800A1CE0;
void guNormalize(f32 *,f32 *,f32 *);
void guMtxIdentF(f32 [4][4]);
void guMtxF2L(f32 [4][4],Mtx *);
f32 __sinf(f32); f32 __cosf(f32);

/* Builds a rotation matrix of `angle` degrees about the axis (x, y, z) into m, normalising the axis first. */
void guRotate(Mtx *m, f32 angle, f32 x, f32 y, f32 z) {
 f32 mf[4][4]; f32 axis_pad[2]; f32 nx, ny, nz; f32 sine, cosine, ab, bc, ca, t; f32 (*p)[4];
 nx = x; ny = y; nz = z; guNormalize(&nx, &ny, &nz);
 angle = angle * D_800A1CE0; sine = __sinf(angle); cosine = __cosf(angle);
 t = 1.0f - cosine; ab = (nx * ny) * t; bc = (ny * nz) * t; ca = (nz * nx) * t; p = mf; guMtxIdentF(p); t = nx * nx;
 p[0][0] = t + (cosine * (1.0f - t)); p[2][1] = bc - (nx * sine); p[1][2] = bc + (nx * sine);
 t = ny * ny; p[1][1] = t + (cosine * (1.0f - t)); p[2][0] = ca + (ny * sine); p[0][2] = ca - (ny * sine);
 t = nz * nz; p[2][2] = t + (cosine * (1.0f - t)); p[1][0] = ab - (nz * sine); p[0][1] = ab + (nz * sine); guMtxF2L(p, m);
}
