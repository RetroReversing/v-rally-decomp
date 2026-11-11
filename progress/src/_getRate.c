extern double D_800A7120,D_800A7128,D_800A7130,D_800A7138,D_800A7140,D_800A7148,D_800A7150,D_800A7158,D_800A7160,D_800A7168;
extern double D_800A70E0[8];
#define FREXP(v, eptr) ({ double value = (v); double absvalue; *(eptr) = 0; if (value != 0.0) { absvalue = (value > 0.0) ? value : -value; for (; absvalue >= D_800A7130; absvalue *= D_800A7138) ++*(eptr); for (; absvalue < D_800A7140; absvalue += absvalue) --*(eptr); value = (value > 0.0) ? absvalue : -absvalue; } value; })
/* Turns a start/end pair spread over `steps` frames into a per-frame rate: the ratio
 * end/start is raised to 1/steps with a table-based log/exp approximation. The fractional
 * part of the result is written to *frac_out. With no steps, the rate is either the
 * maximum (start <= end) or zero. */
s32 _getRate(double start,double end,s32 steps,u16 *frac_out){
double tab[8],mant,y,z,rate_steps; s32 exp2; s32 power; s16 whole;
rate_steps=D_800A7120/(double)steps;
if(!steps){if(start<=end){*frac_out=-1;return 32767;}*frac_out=0;return 0;}
if(end<D_800A7120)end=D_800A7120;
if(start<=0.0)start=D_800A7120;
__builtin_memcpy(tab,D_800A70E0,64);
power=(s32)(rate_steps*D_800A7128);mant=FREXP(end/start,&exp2);
y=(tab[(s32)(mant*D_800A7148)-8]+(double)exp2)*D_800A7150/D_800A7158;z=D_800A7160;y+=z;
while(power){if(power&1)z*=y;power>>=1;y*=y;}
z*=z;z*=z;z*=z;whole=(s16)(s32)z;*frac_out=(s16)(s32)((z-(double)(float)whole)*D_800A7168);return whole;
}
