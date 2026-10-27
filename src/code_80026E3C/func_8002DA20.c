#include "common.h"

static inline u32 shift12(s32 value) { return (u32)value >> 12; }
void *func_8002DA20(void *arg0, void *arg1) {
 s32 i=0; s16 *p=(s16*)arg0; s32 *m=(s32*)arg1; s32 v;
loop:
 v=p[0]; v=v*m[0]; p[0]=(s16)((u32)v>>12);
 v=p[1]; v=v*m[1]; p[1]=(s16)((u32)v>>12);
 i++;
 v=p[2]; v=v*m[2]; p[2]=(s16)((u32)v>>12);
 p+=3; if(i<3)goto loop;
 return arg0;
}
