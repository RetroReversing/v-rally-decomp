static inline s32 roundToZero(s32 a) { return a+0xFFF; }

/* Mixes three components: out[i] = (a[i]*ka + b[i]*kb) >> 12 for i = 0..2,
 * with negative sums rounded toward zero before the shift. */
void func_8002D4E0(s32 *a, s32 *b, s32 ka, s32 kb, s32 *out)
{
s32 sum;
s32 x;
sum = a[0] * ka; sum += b[0] * kb;
if(sum>=0) { x=sum; } else { x=roundToZero(sum); }
sum=x>>12;
out[0]=sum;
sum = a[1] * ka; sum += b[1] * kb;
if(sum>=0) { x=sum; } else { x=roundToZero(sum); }
sum=x>>12;
out[1]=sum;
sum = a[2] * ka; ka=sum; ka += b[2] * kb;
if(ka>=0) { x=ka; } else { x=roundToZero(ka); }
ka=x>>12;
out[2]=ka;
}
