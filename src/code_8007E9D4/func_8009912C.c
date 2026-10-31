#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern char D_800A73E0[], D_800AE850[], D_800A3D50[], D_800A3D64[], D_800A3E10[], D_800A3D76, jtbl_800A72C0[];
int func_8008E118(char *);
void *func_8008E13C(void *,void *,int);
int func_800987C0(int);
char *func_80098884(u32,int);
char *func_800988C8(u64,int);
char *func_80098E88(double,int,int *,int *);
char *func_80098B7C(double,int,int *,int *);
char *func_80098F34(double,int,char *);
void func_80098290(char *,char *);
extern int D_800ADEF0; extern char *D_800ADEF8, *D_800ADF00; extern char D_800ADF04;
#define CNT D_800ADEF0
#define OUT D_800ADEF8
#define DIG D_800ADF00
#define ALT D_800ADF04
#define PUT(c) (--CNT == 0 ? func_800987C0(c) : (*OUT++=(c)))
#define ARG(t,n) (*(t *)((ap=(char *)(((u32)ap+(n)-1)&-(n))+(n))-(n)))
int func_8009912C(int unused, const char *fmt, char *ap) {
 char c; int len;
 char *str;
 int prec, flags, fprec, width, prefix, total=0;
 int issigned, base, isfloat, dec, sign, dec2, sign2, i;
char *digits, *p;
 u32 val; u64 wide; double f; double gf;
 for (;;) {
  if ((c=*fmt++)!='%') {
   if (!(signed char)c) { ALT=0; return total; }
   if (D_800A3E10[(u8)c]&0x80) { PUT(c); total++; c=*fmt++; }
   PUT(c); total++; continue;
  }
  flags=0; ALT=0;
 flag_loop:
  switch (c=*fmt++) {
   case '-': flags|=1; goto flag_loop;
   case '+': flags|=2; goto flag_loop;
   case '0': flags|=4; goto flag_loop;
   case ' ': flags|=8; goto flag_loop;
   case '#': ALT=1; goto flag_loop;
  }
  if ((signed char)c=='*') { width=ARG(int,4); if(width<0) { flags|=1; width=-width; } c=*fmt++; }
  else { width=0; while(D_800A3E10[(u8)c]&8) { width=width*10+((signed char)c-48); c=*fmt++; } }
  prec=0; fprec=6;
  if ((signed char)c=='.') {
   if ((c=*fmt++)=='*') { prec=ARG(int,4); c=*fmt++; }
   else { while(D_800A3E10[(u8)c]&8) { prec=prec*10+((signed char)c-48); c=*fmt++; } }
   fprec=prec;
  }
  isfloat=0; issigned=0; DIG=D_800A3D50; base=10;
 convert:
  switch ((signed char)c) {
  case 'd': case 'i': issigned=1; goto integer;
  case 'o': base=8; goto clearflags;
  case 'X': DIG=D_800A3D64;
  case 'x': base=16;
 clearflags: flags&=~10; goto integer;
  case 'u': goto integer;
  case 'c': str=D_800AE850+0x86A0; *str=ARG(int,4); len=1; goto emit;
  case 's': str=ARG(char *,4); if (!str) str=jtbl_800A72C0; len=func_8008E118(str); if(prec!=0 && prec<len) len=prec; goto emit;
  case 'f':
   f=ARG(double,8); digits=func_80098E88(f,fprec,&dec,&sign); if(sign) flags|=0x100;
   str=D_800AE850+0x86A1; p=str;
   if (dec==0x7fffffff) func_80098290(str,digits);
   else if(dec<=0) {
    *p++='0'; *p++='.'; i=0;
    while(dec) { *p++='0'; i++; dec++; if(i==fprec) break; }
    while(i!=fprec) { *p++=*digits++; i++; }
    *p=0;
   } else {
    if(dec+fprec<40) {
     func_8008E13C(p,digits,dec); digits+=dec; p+=dec;
     if(fprec) { *p++='.'; func_8008E13C(p,digits,fprec); }
     else if(ALT) *p++='.';
     p[fprec]=0;
    } else if(dec+fprec<255) {
     __builtin_memcpy(p,digits,40);
     if(dec<=40) p+=dec; else { p+=40; i=dec-40; do { *p++='0'; } while(--i); }
     if(fprec) { *p++='.'; i=fprec; do { *p++='0'; } while(--i); } else if(ALT) *p++='.';
     *p=0;
    } else { fprec=20; c='e'; goto exponential; }
   }
   len=func_8008E118(str); prec=0; isfloat=1; goto pad;
  case 'e': case 'E':
   f=ARG(double,8);
 exponential:
   { char *s=func_80098B7C(f,fprec,&dec2,&sign2); str=D_800AE850+0x86A1; if(sign2) flags|=0x100;
     if(dec2==0x7fffffff) func_80098290(str,s); else { D_800A3D76=c; func_80098A1C((u8 *)s,fprec,dec2-1,(s8 *)str); D_800A3D76='e'; }
   } len=func_8008E118(str); prec=0; isfloat=1; goto pad;
  case 'g': case 'G':
   gf=ARG(double,8); if(gf<0.0) { flags|=0x100; gf=-gf; }
   D_800A3D76=c-2; str=func_80098F34(gf,fprec,D_800AE850+0x86A1); D_800A3D76='e';
   len=func_8008E118(str); prec=0; isfloat=1; goto pad;
  case 'n': *ARG(int *,4)=total; continue;
  case 'p': flags=0; prec=8; DIG=D_800A3D64; base=16; goto integer;
  case 'h': flags|=0x40; c=*fmt++; goto convert;
  case 'l': if ((c=*fmt++)=='l') { flags|=0x20; c=*fmt++; } goto convert;
  case 'L': flags|=0x80; c=*fmt++; goto convert;
  default: PUT(c); total++; continue;
  }
 integer:
  if(prec) flags&=~4;
  if(flags&0x20) { wide=ARG(u64,8); if(issigned) if((s64)wide<0) { wide=-wide; flags|=0x100; } str=func_800988C8(wide,base); }
  else { val=ARG(u32,4); if(flags&0x40) { if(issigned) val=(s16)val; else val=(u16)val; }
   if(issigned) if((s32)val<0) { val=-val; flags|=0x100; } str=func_80098884(val,base);
  }
  len=(D_800AE850+0x87A0)-str;
 pad:
  prefix=0;
  if(ALT && base!=10 && !issigned && *str!='0') { prefix=1; if(base==16) prefix=2; }
  if((flags&5)==4) prec=width;
  if(prec) {
   if(flags&0x10A) {
    prec--;
    if(isfloat) {
     width--; total++;
     if(flags&0x100) { PUT('-'); }
     else if(--CNT==0) func_800987C0((flags&2)?'+':' '); else *OUT++=(flags&2)?'+':' ';
     flags&=~0x10A;
    }
   }
   prec-=prefix;
   while(len<prec) {
    if(isfloat) { PUT('0'); width--; total++; prec--; }
    else { *--str='0'; len++; }
   }
  }
  if(prefix) { if(prefix==2) *--str=DIG[16]; *--str='0'; len+=prefix; }
  if(flags&0x10A) { len++; --str; if(flags&0x100) *str='-'; else *str=(flags&2)?'+':' '; }
 emit:
  if(!(flags&1)) { while(len<width) { PUT(' '); width--; total++; } }
  width-=len; total+=len;
  while(len-- !=0) { PUT(*str++); }
  while(width>0) { PUT(' '); width--; total++; }
 }
}


