#include "snapshot31_manual_verified.h"

f32 func_8001C2E4(f32 *a,f32 *b) {f32 x,t,y,z,q; x=a[0]; y=a[1];z=a[2];t = (x*x+y*y); t+=z*z; z=__builtin_sqrtf(t);if(z==0.0f)z=1.0f;t=x/z;b[0]=t;q=z;b[1]=a[1]/q;b[2]=a[2]/z;return z;}
