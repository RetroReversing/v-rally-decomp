/* Partial candidate from function #26056 in project #57; rechecked locally. */
extern f64 D_800A6D48,D_800A6D50,D_800A6D58,D_800A6D60,D_800A6D68,D_800A6D70,D_800A6D78,D_800A6D80,D_800A6D88,D_800A6D90,D_800A6D98,D_800A6DA0,D_800A6DA8,D_800A6DB0;
f32 func_80089300(f32 x){
 f32 c,d; f64 r;
 if (x == 0.0f) return 1.0f;
 if (!(x > 0.0f)) {
  f32 y = -x; c = y*y; d = c*c;
  { f64 one = D_800A6D68; f64 sum;
  sum = (f64)y*D_800A6D48 + one + (f64)c*D_800A6D50 + (f64)(c*y)*D_800A6D58 + (f64)d*D_800A6D60 + (f64)(d*y)*D_800A6D70 + (f64)(d*c)*D_800A6D78;
  r = one / sum; }
 } else {
  c = x*x; d = c*c;
  r = (f64)x*D_800A6D80 + D_800A6DA0 + (f64)c*D_800A6D88 + (f64)(c*x)*D_800A6D90 + (f64)d*D_800A6D98 + (f64)(d*x)*D_800A6DA8 + (f64)(d*c)*D_800A6DB0;
 }
 return (f32)r;
}
