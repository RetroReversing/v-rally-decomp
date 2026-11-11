s32 formatString(s32,void*,u16,u16,u16); extern u32 gRecordTimeScale; extern u8 D_8009D544; extern char D_800A5050;
/* Formats a race time for display: ticks (arg0) become minutes, seconds and hundredths,
 * using gRecordTimeScale ticks per second, and are printed with D_800A5050 into arg1.
 * Ticks are scaled by 2/3 when D_8009D544 is 0. */
void func_80052E94(s32 ticks,s32 outBuf) {
 s32 a3=ticks; u32 perSec; u32 minutes,rem,sec,hundredths;
 if(D_8009D544==0) a3=(a3*2)/3;
 perSec=gRecordTimeScale;
 minutes=a3/(((perSec<<4)-perSec)<<2);
 rem=a3-((((minutes<<4)-minutes)<<2)*perSec);
 sec=rem/perSec;
 rem-=sec*perSec; hundredths=(rem*100)/perSec;
 formatString(outBuf,&D_800A5050,minutes&0xffff,sec&0xffff,hundredths&0xffff);
}
