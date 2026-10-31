#include "common.h"
void func_8002DB18();
s16 *func_8002E148(s16 *arg0,s16 *arg1) {
 s16 sp10[16],sp30[16],sp50[16],sp70[16];
 s16 s0,s1,s2,s3,s4,last;
 s3=func_8002D2E4(arg0[0]);
 s1=func_8002D348(arg0[0]);
 s4=func_8002D2E4(arg0[1]);
 s2=func_8002D348(arg0[1]);
 s0=func_8002D2E4(arg0[2]);
 last=func_8002D348(arg0[2]);
 sp30[0]=0x1000;sp30[1]=0;sp30[2]=0;sp30[3]=0;sp30[4]=s3;sp30[5]=-s1;sp30[6]=0;sp30[7]=s1;sp30[8]=s3;
 sp10[0]=s4;sp10[1]=0;sp10[2]=s2;sp10[3]=0;sp10[4]=0x1000;sp10[5]=0;sp10[6]=-s2;sp10[7]=0;sp10[8]=s4;
 sp50[0]=s0;sp50[1]=-last;sp50[2]=0;sp50[3]=last;sp50[4]=s0;sp50[5]=0;sp50[6]=0;sp50[7]=0;sp50[8]=0x1000;
 func_8002DB18(sp30,sp10,sp70);func_8002DB18(sp70,sp50,arg1);return arg1;
}

