#include "snapshot31_verified.h"

extern char D_800C02AE[];
s32 func_80048268(s16 *a, s16 *b, s16 *c, s16 *d) {
 s16 *p = *(s16 **)(*(char **)(D_800C02AE + 0x7CD6) + 0x178);
 s32 x=p[4], y=p[5], right=x+p[6], bottom=y+p[7];
 if ((x<a[0] || x<b[0] || x<c[0] || x<d[0]) && (a[0]<right || b[0]<right || c[0]<right || d[0]<right) && (y<a[1] || y<b[1] || y<c[1] || y<d[1])) { goto inside; }
 return 0;
 inside: {
 if (a[1]>=bottom && b[1]>=bottom && c[1]>=bottom && d[1]>=bottom) return 0;
 return 1;
 }
 return 0;
}