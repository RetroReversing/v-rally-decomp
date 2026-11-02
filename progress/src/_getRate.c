extern double D_800A7120,D_800A7128,D_800A7130,D_800A7138,D_800A7140,D_800A7148,D_800A7150,D_800A7158,D_800A7160,D_800A7168;
extern double D_800A70E0[8];
#define FREXP(v, eptr) ({ double value = (v); double absvalue; *(eptr) = 0; if (value != 0.0) { absvalue = (value > 0.0) ? value : -value; for (; absvalue >= D_800A7130; absvalue *= D_800A7138) ++*(eptr); for (; absvalue < D_800A7140; absvalue += absvalue) --*(eptr); value = (value > 0.0) ? absvalue : -absvalue; } value; })
s32 _getRate(double a,double b,s32 n,u16*out){
double tab[8],x,y,z,r; s32 e; s32 q; s16 result;
r=D_800A7120/(double)n;
if(!n){if(a<=b){*out=-1;return 32767;}*out=0;return 0;}
if(b<D_800A7120)b=D_800A7120;
if(a<=0.0)a=D_800A7120;
__builtin_memcpy(tab,D_800A70E0,64);
q=(s32)(r*D_800A7128);x=FREXP(b/a,&e);
y=(tab[(s32)(x*D_800A7148)-8]+(double)e)*D_800A7150/D_800A7158;z=D_800A7160;y+=z;
while(q){if(q&1)z*=y;q>>=1;y*=y;}
z*=z;z*=z;z*=z;result=(s16)(s32)z;*out=(s16)(s32)((z-(double)(float)result)*D_800A7168);return result;
}
