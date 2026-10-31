typedef struct { f32 m[4][4]; } Mtx;
extern f32 D_800A1CE0;
void guNormalize(f32 *,f32 *,f32 *);
void guMtxIdentF(f32 [4][4]);
void guMtxF2L(f32 [4][4],Mtx *);
f32 __sinf(f32); f32 __cosf(f32);
void guRotate(Mtx *m,f32 a,f32 x,f32 y,f32 z){
 f32 frame_pad[2]; f32 mf[4][4]; f32 axis_pad[1]; f32 sp58,sp5C,sp60; f32 *new_var; f32 sine,cosine,ab,bc,ca,t;
 sp58=x; sp5C=y; sp60=z; guNormalize(&sp58,&sp5C,&sp60);
 a=a*D_800A1CE0; sine=__sinf(a); cosine=__cosf(a);
 t=1.0f-cosine; ab=(sp58*sp5C)*t; bc=(sp5C*sp60)*t; ca=(sp60*sp58)*t; guMtxIdentF(mf); t=sp58*sp58;
 mf[0][0]=t+(cosine*(1.0f-t)); mf[2][1]=bc-(sp58*sine); mf[1][2]=bc+(sp58*sine);
 t=sp5C*sp5C; mf[1][1]=t+(cosine*(1.0f-t)); mf[2][0]=ca+(sp5C*sine); mf[0][2]=ca-(sp5C*sine);
 t=sp60*sp60; mf[2][2]=t+(cosine*(1.0f-t)); mf[1][0]=ab-(sp60*sine); mf[0][1]=ab+(sp60*sine); guMtxF2L(mf,m);
}
