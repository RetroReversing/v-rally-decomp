#include "common.h"

extern void func_80098290(s8 *, s8 *);
s8 *func_800980D0(s8 *arg0, s8 *arg1) {
 s8 *p=arg0; s32 w;
 if((s32)p&3) {do {if(*p==0) goto done; p++;}while((s32)p&3);}
 w=*(s32*)p;
 if(w&0xFF000000) {
 do {
 if(!(w&0xFF0000)){p++;goto done;}
 if(!(w&0xFF00)){p+=2;goto done;}
 if(!(w&0xFF)){p+=3;goto done;}
 p+=4;
 w=*(s32*)p;
 }while(w&0xFF000000);
 }
 done: func_80098290(p,arg1); return arg0;
}
