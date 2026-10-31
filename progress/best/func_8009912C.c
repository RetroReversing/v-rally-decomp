extern char D_800A73E0[], D_800AE850[], D_800A3D50[], D_800A3D64[], D_800A3E10[], D_800A3D76, jtbl_800A72C0[];
int func_8008E118(char *);
void *func_8008E13C(void *,void *,int);
void func_800987C0(int);
char *func_80098884(u32,int);
char *func_800988C8(u64,int);
char *func_80098E88(double,int,int *,int *);
char *func_80098B7C(double,int,int *,int *);
char *func_80098F34(double,int,char *);
void func_80098A1C(char *,int,int,char *);
void func_80098290(char *,char *);
extern int D_800ADEF0; extern char *D_800ADEF8, *D_800ADF00; extern char D_800ADF04;
#define CNT D_800ADEF0
#define OUT D_800ADEF8
#define DIG D_800ADF00
#define ALT D_800ADF04
#define PUT(c) do { if (--CNT == 0) func_800987C0(c); else *OUT++=(c); } while(0)
#define ARG(t,n) (*(t *)((ap=(char *)(((u32)ap+(n)-1)&-(n))+(n))-(n)))
int func_8009912C(int unused, char *fmt, char *ap) {
 int ch;
 char *str;
 int prec, flags, fprec, width, prefix, total=0;
 int isfloat, issigned, base, dec, sign, dec2, sign2, i;
char *digits;
 u32 val; u64 wide; double f;
 for (;;) {
  ch=(u8)*fmt;
  if (*fmt++!='%') {
   if (!(signed char)ch) { ALT=0; return total; }
   if (D_800A3E10[(u8)ch]&0x80) { total++; PUT(ch); ch=(u8)*fmt++; }
   PUT((signed char)ch); total++; continue;
  }
  flags=0; ALT=0;
  for (;;) {
   ch=(u8)*fmt++;
   switch ((signed char)ch) {
   case '-': flags|=1; continue;
   case '+': flags|=2; continue;
   case '0': flags|=4; continue;
   case ' ': flags|=8; continue;
   case '#': ALT=1; continue;
   }
   break;
  }
  if ((signed char)ch=='*') { width=ARG(int,4); if(width<0) { flags|=1; width=-width; } ch=(u8)*fmt++; }
  else { width=0; while(D_800A3E10[(u8)ch]&8) { width=width*10-48+(signed char)ch; ch=(u8)*fmt++; } }
  prec=0; fprec=6;
  if ((signed char)ch=='.') {
   ch=(u8)*fmt++;
   if ((signed char)ch=='*') { prec=ARG(int,4); ch=(u8)*fmt++; }
   else { while(D_800A3E10[(u8)ch]&8) { prec=prec*10-48+(signed char)ch; ch=(u8)*fmt++; } }
   fprec=prec;
  }
  DIG=D_800A3D50; isfloat=0; issigned=0; base=10;
 convert:
  switch ((signed char)ch) {
  case 'd': case 'i': issigned=1; goto integer;
  case 'o': base=8; flags&=~10; goto integer;
  case 'X': DIG=D_800A3D64; base=16; flags&=~10; goto integer;
  case 'x': base=16; flags&=~10; goto integer;
  case 'u': flags&=~10; goto integer;
  case 'p': flags=0; prec=8; DIG=D_800A3D64; base=16; goto integer;
  case 'h': flags|=0x40; ch=(u8)*fmt++; goto convert;
  case 'l': ch=(u8)*fmt++; if ((signed char)ch=='l') { flags|=0x20; ch=(u8)*fmt++; } goto convert;
  case 'L': flags|=0x80; ch=(u8)*fmt++; goto convert;
  case 'c': str=D_800AE850+0x86A0; *str=ARG(int,4); ch=1; goto emit;
  case 's': str=ARG(char *,4); if (!str) str=jtbl_800A72C0; ch=func_8008E118(str); if(prec!=0 && prec<ch) ch=prec; goto emit;
  case 'n': *ARG(int *,4)=total; continue;
  case 'f':
   f=ARG(double,8); digits=func_80098E88(f,fprec,&dec,&sign); if(sign) flags|=0x100;
   str=D_800AE850+0x86A1;
   if (dec==0x7fffffff) func_80098290(str,digits);
   else if(dec<=0) {
    char *p=str; i=0; *p++='0'; *p++='.';
    while(dec && i!=fprec) { *p++='0'; dec++; i++; }
    while(i!=fprec) { *p++=*digits++; i++; }
    *p=0;
   } else {
    char *p=str; char *s=digits;
    if(dec+fprec<40) {
     func_8008E13C(p,s,dec); p+=dec; s+=dec;
     if(fprec) { *p++='.'; func_8008E13C(p,s,fprec); }
     else if(ALT) *p++='.';
     p[fprec]=0;
    } else if(dec+fprec<255) {
     __builtin_memcpy(p,s,40);
     if(dec<=40) p+=dec; else { p+=40; i=dec-40; do { *p++='0'; } while(--i); }
     if(fprec) { *p++='.'; i=fprec; do { *p++='0'; } while(--i); } else if(ALT) *p++='.';
     *p=0;
    } else { fprec=20; ch='e'; goto exponential; }
   }
   goto floating;
  case 'e': case 'E':
   f=ARG(double,8);
 exponential:
   { char *s=func_80098B7C(f,fprec,&dec2,&sign2); str=D_800AE850+0x86A1; if(sign2) flags|=0x100;
     if(dec2==0x7fffffff) func_80098290(str,s); else { D_800A3D76=ch; func_80098A1C(s,fprec,dec2-1,str); D_800A3D76='e'; }
   } goto floating;
  case 'g': case 'G':
   f=ARG(double,8); if(f<0.0) { flags|=0x100; f=-f; }
   D_800A3D76=ch-2; str=func_80098F34(f,fprec,D_800AE850+0x86A1); D_800A3D76='e';
 floating:
   ch=func_8008E118(str); prec=0; isfloat=1; goto pad;
  default: PUT((signed char)ch); total++; continue;
  }
 integer:
  if(prec) flags&=~4;
  if(flags&0x20) { wide=ARG(u64,8); if(issigned && (s64)wide<0) { wide=-wide; flags|=0x100; } str=func_800988C8(wide,base); }
  else { val=ARG(u32,4); if(flags&0x40) { if(issigned) val=(s16)val; else val=(u16)val; }
   if(issigned && (s32)val<0) { val=-val; flags|=0x100; } str=func_80098884(val,base);
  }
  ch=(D_800AE850+0x87A0)-str;
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
   while(ch<prec) {
    if(isfloat) { PUT('0'); width--; total++; prec--; }
    else { *--str='0'; ch++; }
   }
  }
  if(prefix) { if(prefix==2) *--str=DIG[16]; *--str='0'; ch+=prefix; }
  if(flags&0x10A) { ch++; if(flags&0x100) *--str='-'; else *--str=(flags&2)?'+':' '; }
 emit:
  if(!(flags&1)) { while(ch<width) { PUT(' '); width--; total++; } }
  width-=ch; total+=ch;
  while(ch-- !=0) { PUT(*str++); }
  while(width>0) { PUT(' '); width--; total++; }
 }
}
