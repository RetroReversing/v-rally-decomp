extern double D_800A7120,D_800A7128,D_800A7130,D_800A7138,D_800A7140,D_800A7148,D_800A7150,D_800A7158,D_800A7160,D_800A7168;
extern double D_800A70E0[8];
s32 _getRate(double a,double b,s32 n,u16*out){
double tab[8],x,y,z; volatile s32 e; s32 q; s16 result;
y=D_800A7120/(double)n;
if(!n){if(a<=b){*out=-1;return 32767;}*out=0;return 0;}
if(b<D_800A7120)b=D_800A7120;
if(a<=0.0)a=D_800A7120;
__builtin_memcpy(tab,D_800A70E0,64);
x=b/a;q=(s32)(y*D_800A7128);e=0;
if(x!=0.0){if(x>0.0)z=x;else z=-x;while(z>=D_800A7130){z*=D_800A7138; e=e+1;}while(z<D_800A7140){z+=z;e=e-1;}x=x>0.0?z:-z;}
y=(tab[(s32)(x*D_800A7148)-8]+(double)e)*D_800A7150/D_800A7158;z=D_800A7160;y+=z;
while(q){if(q&1)z*=y;q>>=1;y*=y;}
z*=z;z*=z;z*=z;result=(s16)(s32)z;*out=(s16)(s32)((z-(double)(float)result)*D_800A7168);return result;
}
