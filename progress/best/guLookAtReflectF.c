typedef struct { f32 a[16]; } MtxObj;
typedef struct { s8 b[32]; } LookObj;
extern f64 D_800A6E90; extern f64 D_800A6E98; extern s32 D_800A6E9C;
void guMtxIdentF(void); f32 sqrtf(f32);
void guLookAtReflectF(MtxObj *m, LookObj *l, f32 ex, f32 ey, f32 ez, f32 cx, f32 cy, f32 cz, f32 ux, f32 uy, f32 uz) {
 f32 x,y,z,a,b,c,d,e,f,g,h,i,n,t; f64 one;
 guMtxIdentF(); x=cx-ex; y=cy-ey; z=cz-ez; n=__builtin_sqrtf(x*x+y*y+z*z);
 t=(f32)(D_800A6E90/(f64)n); x*=t;y*=t;z*=t; a=uy*z-uz*y;b=uz*x-ux*z;c=ux*y-uy*x;n=__builtin_sqrtf(a*a+b*b+c*c);
 one=D_800A6E98;t=(f32)(one/(f64)n);a*=t;b*=t;c*=t;
 d=y*c-z*b;e=z*a-x*c;f=x*b-y*a;n=__builtin_sqrtf(d*d+e*e+f*f);
 t=(f32)(one/(f64)n);d*=t;e*=t;f*=t;
 l->b[8]=(s8)(a*128.0f<127.0f?a*128.0f:127);l->b[9]=(s8)(b*128.0f<127.0f?b*128.0f:127);l->b[10]=(s8)(c*128.0f<127.0f?c*128.0f:127);
 l->b[24]=(s8)(d*128.0f<127.0f?d*128.0f:127);l->b[25]=(s8)(e*128.0f<127.0f?e*128.0f:127);l->b[26]=(s8)(f*128.0f<127.0f?f*128.0f:127);
 l->b[0]=l->b[1]=l->b[2]=l->b[3]=l->b[4]=l->b[5]=l->b[6]=l->b[7]=0;l->b[16]=0;l->b[17]=-128;l->b[18]=l->b[19]=l->b[20]=0;l->b[21]=-128;l->b[22]=l->b[23]=0;
 m->a[0]=a;m->a[4]=b;m->a[8]=c;m->a[1]=d;m->a[5]=e;m->a[9]=f;m->a[2]=x;m->a[6]=y;m->a[10]=z;m->a[3]=m->a[7]=m->a[11]=0;m->a[15]=1.0f;
 m->a[12]=-(ex*a+ey*b+ez*c);m->a[13]=-(ex*d+ey*e+ez*f);m->a[14]=-(ex*x+ey*y+ez*z);
}
