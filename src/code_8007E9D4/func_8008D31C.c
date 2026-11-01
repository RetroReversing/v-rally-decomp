#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { f32 m[4][4]; } Mtx;
extern f32 D_800A1CE0;
void guNormalize(f32 *,f32 *,f32 *);
void guMtxIdentF(f32 [4][4]);
void guMtxF2L(f32 [4][4],Mtx *);
f32 __sinf(f32); f32 __cosf(f32);
void func_8008D31C(Mtx *m,f32 a,f32 x,f32 y,f32 z){
 f32 mf[4][4]; f32 axis_pad[2]; f32 sp58,sp5C,sp60; f32 sine,cosine,ab,bc,ca,t; f32 (*p)[4];
 sp58=x; sp5C=y; sp60=z; guNormalize(&sp58,&sp5C,&sp60);
 a=a*D_800A1CE0; sine=__sinf(a); cosine=__cosf(a);
 t=1.0f-cosine; ab=(sp58*sp5C)*t; bc=(sp5C*sp60)*t; ca=(sp60*sp58)*t; p = mf; guMtxIdentF(p); t=sp58*sp58;
 p[0][0]=t+(cosine*(1.0f-t)); p[2][1]=bc-(sp58*sine); p[1][2]=bc+(sp58*sine);
 t=sp5C*sp5C; p[1][1]=t+(cosine*(1.0f-t)); p[2][0]=ca+(sp5C*sine); p[0][2]=ca-(sp5C*sine);
 t=sp60*sp60; p[2][2]=t+(cosine*(1.0f-t)); p[1][0]=ab-(sp60*sine); p[0][1]=ab+(sp60*sine); guMtxF2L(p,m);
}

