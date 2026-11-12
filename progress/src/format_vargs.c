extern char gGameState[], gOrderState[], digits_lower[], digits_upper[], char_class_tbl[], exp_char, null_str[];
int str_len(char *);
void *memcpy(void *,void *,int);
int print_flush_buffer(int);
char *format_uint_reverse(u32,int);
char *func_800988C8(u64,int);
char *func_80098E88(double,int,int *,int *);
char *ecvt_digits(double,int,int *,int *);
char *func_80098F34(double,int,char *);
void strCpy(char *,char *);
extern int fmt_buf_left; extern char *fmt_buf_pos, *gDigitChars; extern char fmt_alt_form;
#define CNT fmt_buf_left
#define OUT fmt_buf_pos
#define DIG gDigitChars
#define ALT fmt_alt_form
#define PUT(c) (--CNT == 0 ? print_flush_buffer(c) : (*OUT++=(c)))
#ifdef PORT
#define ARG(t,n) (*(t *)((args=(char *)(((uintptr_t)args+(n)-1)&-(uintptr_t)(n))+(n))-(n)))
#else
#define ARG(t,n) (*(t *)((args=(char *)(((u32)args+(n)-1)&-(n))+(n))-(n)))
#endif
/* printf core: walks fmt, parses flags/width/precision and conversions (%d %i %u %x %X %o %c %s %f %e %g %n %p),
 * writes each character through PUT into the output buffer, and returns the number of characters produced. */
/* printf core: parses flags, width, precision and length, then conversions (%d %i %u %x %X %o %c %s %f %e %g %n %p), writing each character through PUT into the output buffer; returns the character count. */ int format_vargs(int unused, const char *fmt, char *args) {
 char ch; int len;
 char *out_str;
 int prec, flags, frac_prec, width, prefix, count=0;
 int is_signed, radix, is_float, dec_pos, is_neg, exp_pos, exp_neg, n;
char *digits, *out;
 u32 val32; u64 val64; double fval; double gval;
 for (;;) {
  if ((ch=*fmt++)!='%') {
   if (!(signed char)ch) { ALT=0; return count; }
   if (char_class_tbl[(u8)ch]&0x80) { PUT(ch); count++; ch=*fmt++; }
   PUT(ch); count++; continue;
  }
  flags=0; ALT=0;
 flag_loop:
  switch (ch=*fmt++) {
   case '-': flags|=1; goto flag_loop;
   case '+': flags|=2; goto flag_loop;
   case '0': flags|=4; goto flag_loop;
   case ' ': flags|=8; goto flag_loop;
   case '#': ALT=1; goto flag_loop;
  }
  if ((signed char)ch=='*') { width=ARG(int,4); if(width<0) { flags|=1; width=-width; } ch=*fmt++; }
  else { width=0; while(char_class_tbl[(u8)ch]&8) { width=width*10+((signed char)ch-48); ch=*fmt++; } }
  prec=0; frac_prec=6;
  if ((signed char)ch=='.') {
   if ((ch=*fmt++)=='*') { prec=ARG(int,4); ch=*fmt++; }
   else { while(char_class_tbl[(u8)ch]&8) { prec=prec*10+((signed char)ch-48); ch=*fmt++; } }
   frac_prec=prec;
  }
  is_float=0; is_signed=0; DIG=digits_lower; radix=10;
 convert:
  switch ((signed char)ch) {
  case 'd': case 'i': is_signed=1; goto integer;
  case 'o': radix=8; goto clearflags;
  case 'X': DIG=digits_upper;
  case 'x': radix=16;
 clearflags: flags&=~10; goto integer;
  case 'u': goto integer;
  case 'c': out_str=gOrderState+0x86A0; *out_str=ARG(int,4); len=1; goto emit;
  case 's': out_str=ARG(char *,4); if (!out_str) out_str=null_str; len=str_len(out_str); if(prec!=0 && prec<len) len=prec; goto emit;
  case 'f':
   fval=ARG(double,8); digits=func_80098E88(fval,frac_prec,&dec_pos,&is_neg); if(is_neg) flags|=0x100;
   out_str=gOrderState+0x86A1; out=out_str;
   if (dec_pos==0x7fffffff) strCpy(out_str,digits);
   else if(dec_pos<=0) {
    *out++='0'; *out++='.'; n=0;
    while(dec_pos) { *out++='0'; n++; dec_pos++; if(n==frac_prec) break; }
    while(n!=frac_prec) { *out++=*digits++; n++; }
    *out=0;
   } else {
    if(dec_pos+frac_prec<40) {
     memcpy(out,digits,dec_pos); digits+=dec_pos; out+=dec_pos;
     if(frac_prec) { *out++='.'; memcpy(out,digits,frac_prec); }
     else if(ALT) *out++='.';
     out[frac_prec]=0;
    } else if(dec_pos+frac_prec<255) {
     __builtin_memcpy(out,digits,40);
     if(dec_pos<=40) out+=dec_pos; else { out+=40; n=dec_pos-40; do { *out++='0'; } while(--n); }
     if(frac_prec) { *out++='.'; n=frac_prec; do { *out++='0'; } while(--n); } else if(ALT) *out++='.';
     *out=0;
    } else { frac_prec=20; ch='e'; goto exponential; }
   }
   len=str_len(out_str); prec=0; is_float=1; goto pad;
  case 'e': case 'E':
   fval=ARG(double,8);
 exponential:
   { char *s=ecvt_digits(fval,frac_prec,&exp_pos,&exp_neg); out_str=gOrderState+0x86A1; if(exp_neg) flags|=0x100;
     if(exp_pos==0x7fffffff) strCpy(out_str,s); else { exp_char=ch; func_80098A1C((u8 *)s,frac_prec,exp_pos-1,(s8 *)out_str); exp_char='e'; }
   } len=str_len(out_str); prec=0; is_float=1; goto pad;
  case 'g': case 'G':
   gval=ARG(double,8); if(gval<0.0) { flags|=0x100; gval=-gval; }
   exp_char=ch-2; out_str=func_80098F34(gval,frac_prec,gOrderState+0x86A1); exp_char='e';
   len=str_len(out_str); prec=0; is_float=1; goto pad;
  case 'n': *ARG(int *,4)=count; continue;
  case 'p': flags=0; prec=8; DIG=digits_upper; radix=16; goto integer;
  case 'h': flags|=0x40; ch=*fmt++; goto convert;
  case 'l': if ((ch=*fmt++)=='l') { flags|=0x20; ch=*fmt++; } goto convert;
  case 'L': flags|=0x80; ch=*fmt++; goto convert;
  default: PUT(ch); count++; continue;
  }
 integer:
  if(prec) flags&=~4;
  if(flags&0x20) { val64=ARG(u64,8); if(is_signed) if((s64)val64<0) { val64=-val64; flags|=0x100; } out_str=func_800988C8(val64,radix); }
  else { val32=ARG(u32,4); if(flags&0x40) { if(is_signed) val32=(s16)val32; else val32=(u16)val32; }
   if(is_signed) if((s32)val32<0) { val32=-val32; flags|=0x100; } out_str=format_uint_reverse(val32,radix);
  }
  len=(gOrderState+0x87A0)-out_str;
 pad:
  prefix=0;
  if(ALT && radix!=10 && !is_signed && *out_str!='0') { prefix=1; if(radix==16) prefix=2; }
  if((flags&5)==4) prec=width;
  if(prec) {
   if(flags&0x10A) {
    prec--;
    if(is_float) {
     width--; count++;
     if(flags&0x100) { PUT('-'); }
     else if(--CNT==0) print_flush_buffer((flags&2)?'+':' '); else *OUT++=(flags&2)?'+':' ';
     flags&=~0x10A;
    }
   }
   prec-=prefix;
   while(len<prec) {
    if(is_float) { PUT('0'); width--; count++; prec--; }
    else { *--out_str='0'; len++; }
   }
  }
  if(prefix) { if(prefix==2) *--out_str=DIG[16]; *--out_str='0'; len+=prefix; }
  if(flags&0x10A) { len++; --out_str; if(flags&0x100) *out_str='-'; else *out_str=(flags&2)?'+':' '; }
 emit:
  if(!(flags&1)) { while(len<width) { PUT(' '); width--; count++; } }
  width-=len; count+=len;
  while(len-- !=0) { PUT(*out_str++); }
  while(width>0) { PUT(' '); width--; count++; }
 }
}
