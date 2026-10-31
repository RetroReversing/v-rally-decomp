typedef struct {u32 w0,w1;} Gfx;
Gfx *func_80007F18(Gfx *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, u32 arg12, s32 arg13, s32 arg14, s32 arg15, s32 arg16){
Gfx *p,*q,*r,*t; s32 line,dxt,count;u32 tileword,sizeword;
s32 base = arg1;
arg1 = base;
switch(arg3){
case 1:
p=arg0++;q=arg0++;r=arg0++;t=arg0++;
p->w0=0xFD000000|((arg2&7)<<21)|0x100000;
p->w1=arg1+arg7*arg4;
q->w0=0xF5000000|((arg2&7)<<21)|0x100000;
q->w1=((arg12&3)<<18)|(((arg14&15)<<14)|0x07000000)|((arg16&15)<<10)|((arg11&3)<<8)|((arg13&15)<<4)|(arg15&15);
r->w0=0xE6000000;r->w1=0;
t->w0=0xF3000000; line=arg4/8;dxt=line>0?line+2047:2048;count=((arg4*arg9+1)>>1)-1;if(count>=2048)count=2047;
t->w1=((count&4095)<<12)|0x07000000|((line>0?dxt/line:dxt)&4095);
p=arg0++;q=arg0++;r=arg0++;
p->w0=0xE7000000;p->w1=0; tileword=((arg2&7)<<21);sizeword=(((arg4+7)>>3)&511)<<9;sizeword|=0xF5000000|0x80000;
goto tail;
case 2:
p=arg0++;q=arg0++;r=arg0++;t=arg0++;
p->w0=0xFD000000|((arg2&7)<<21)|0x100000;
p->w1=arg1+arg7*arg4*2;
q->w0=0xF5000000|((arg2&7)<<21)|0x100000;
q->w1=((arg12&3)<<18)|(((arg14&15)<<14)|0x07000000)|((arg16&15)<<10)|((arg11&3)<<8)|((arg13&15)<<4)|(arg15&15);
r->w0=0xE6000000;r->w1=0;
t->w0=0xF3000000;
line=arg4/4;dxt=line>0?line+2047:2048;count=arg4*arg9-1;if(count>=2048)count=2047;
t->w1=((count&4095)<<12)|0x07000000|((line>0?dxt/line:dxt)&4095);
p=arg0++;q=arg0++;r=arg0++;
p->w0=0xE7000000;p->w1=0;
tileword=((arg2&7)<<21);sizeword=(((arg4*2+7)>>3)&511)<<9;sizeword|=0xF5000000|0x100000;
goto tail;
case 3:
p=arg0++;q=arg0++;r=arg0++;t=arg0++;
p->w0=0xFD000000|((arg2&7)<<21)|0x180000;
p->w1=arg1+arg7*arg4*4;
q->w0=0xF5000000|((arg2&7)<<21)|0x180000;
q->w1=((arg12&3)<<18)|(((arg14&15)<<14)|0x07000000)|((arg16&15)<<10)|((arg11&3)<<8)|((arg13&15)<<4)|(arg15&15);
r->w0=0xE6000000;r->w1=0;
t->w0=0xF3000000;
line=arg4>>1;dxt=line>0?line+2047:2048;count=arg4*arg9-1;if(count>=2048)count=2047;
t->w1=((count&4095)<<12)|0x07000000|((line>0?dxt/line:dxt)&4095);
p=arg0++;q=arg0++;r=arg0++;
p->w0=0xE7000000;p->w1=0;
tileword=((arg2&7)<<21);sizeword=(((arg4*2+7)>>3)&511)<<9;sizeword|=0xF5000000|0x180000;
goto tail;
default:return arg0;
}
tail:
q->w1=((arg10&15)<<20)|((arg12&3)<<18)|((arg14&15)<<14)|((arg16&15)<<10)|((arg11&3)<<8)|((arg13&15)<<4)|(arg15&15);
q->w0=tileword|sizeword;r->w0=0xF2000000;r->w1=((((arg4-1)*4)&4095)<<12)|(((arg9-1)*4)&4095);return arg0;
}
