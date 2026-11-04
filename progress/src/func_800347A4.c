extern char *D_800C35A0,*D_800B615C;extern int D_800C81D0;
int func_8001FEDC(void *);int func_8002D2C8(int,int);int func_80033DB8(void *,int,int,void *);void func_80033E34(void *,int,void *);
void func_80034134(void *,void *);void func_800344F0(void *,void *);void func_80033F20(void *,void *,void *);void func_80033C30(void *,void *);
#define W(p,o) (((struct { char pad[o]; int v; } *)(p))->v)
#define P(p,o) (((struct { char pad[o]; char *v; } *)(p))->v)
#define H(p,o) (((struct { char pad[o]; s16 v; } *)(p))->v)
#define U(p,o) (((struct { char pad[o]; u16 v; } *)(p))->v)
void func_800347A4(void *obj,s8 *out) {
 struct { int data[56]; int plan[8]; } workspace;
#define data workspace.data
#define plan workspace.plan
 int angle,raw,forced,limit,progress,speed,state,timer,phase,steer,target,step;
 int i,nearest,index,delta,denom,other,heading;
 out[4]=0; out[5]=0; out[1]=0; out[0]=0;
 angle=func_8002D2C8(H(P(obj,0x5c),0x50),H(P(obj,0x5c),0x44));
 data[0]=W(P(obj,0x58),12);data[1]=W(P(obj,0x58),16);data[2]=W(P(obj,0x58),20);
 progress=W(P(obj,0x8c),0x2c);D_800B615C=obj;D_800C81D0=progress;raw=W(P(obj,0x60),0x2c);
 speed=func_8001FEDC(obj);state=W(P(obj,0x60),0x160);timer=W(P(obj,0x60),0x158);phase=W(P(obj,0x60),0x164);steer=W(P(obj,0x60),0x168);
target=W(P(obj,0x60),0x16c);forced=W(P(obj,0x6c),0x34);
 if(state!=3) {
  if((u32)(speed+199)<399 && !(W(obj,0x14)&16)) {
  timer++;if((u32)timer>=51){timer=0;phase=0;state=3;}
  } else timer=0;
 }
 state_done:
 progress=func_80033DB8(obj,progress,raw,&data[4]);
 limit=W(P(obj,0x60),0x17c)*10;if(forced)steer=limit-progress;
 func_80034134(&data[8],obj);func_800344F0(plan,obj);{int scan_nearest,scan_index;step=3;scan_nearest=65000;scan_index=0;
 for(i=0;i<data[41];i++){other=data[29+data[42+i]];if(other<scan_nearest){scan_index=i;scan_nearest=other;}}
 progress+=(((unsigned)scan_nearest<<16)<<16);if(plan[6]>=2) {
  if(data[41]) {delta=data[33+data[42+scan_index]]*10;if(scan_nearest<3000){if(delta>=501)steer=delta-progress-390;else steer=delta-progress+390;step=2;}}
 }else if(data[41]) {
  delta=data[33+data[42+scan_index]]*10;other=data[29+data[42+scan_index]];step=speed-data[25+data[42+scan_index]];
 if(step>1000){step=step/150;if(other<step*100)if(delta>=501)steer=delta-progress-300;else steer=delta-progress+300;}
  else step=3;
 }
 if(step>8)step=8;}
 nearest=65000;
 if(data[41] && U(D_800C35A0,0x16)!=2) {
  index=0;
  for(i=0;i<data[41];i++){if(W(P(*(char **)&data[37+data[42+i]],0x48),0)<4){other=data[29+data[42+i]];if(other<nearest){index=i;nearest=other;}}}
  index+=(((unsigned)index<<16)<<16);delta=data[25+data[42+index]];other=speed-delta;{int saved_divisor=nearest;nearest=0;if(saved_divisor<0)saved_divisor+=127;saved_divisor>>=7;denom=(saved_divisor==0);saved_divisor+=denom;denom=delta<1800;other=other/saved_divisor;
 if(denom)delta=1800;}if(other>=56){plan[4]=delta;plan[7]=60;}
 }
 if(data[46]) {
  if(limit<progress){for(i=0;i<data[46];i++)if(data[51+i]==0){delta=data[33+data[47+i]]*10;steer=delta-progress-250;break;}}
  else if(progress<limit){for(i=0;i<data[46];i++)if(data[51+i]==1){delta=data[33+data[47+i]]*10;steer=delta-progress+250;break;}}
 }else {steer+=(u32)steer>>31;steer-=(steer>0);}
 if(plan[6]>=2) {
  if(steer< -350)steer=-350;if(steer>350)steer=350;

  denom=progress+steer;if(target<denom)target+=step;if(denom<target)target-=step; }else {
  other=progress+steer;if(other<200){if(other<progress){other=progress;steer=0;}}
  if(other>800){if(progress<other){other=progress;steer=0;}}target=other;
 }
 func_80033E34(obj,target,&data[4]);heading=func_8002D2C8(data[6]-data[2],data[4]-data[0]);
 if(heading< -1024 && angle>1024)heading+=4096;if((angle< -1024)&(heading>1024))angle+=4096;
 delta=angle-heading;
 if((u32)(delta+1024)>2048) {if(state==1)state=(limit>=501)?5:4;}
 else if((u32)(state-4)<2)state=1;
 if(state==4)delta=-127;if(state==5)delta=127;
 if(delta>=128)delta=127;else if(delta< -127)delta=-127;
 denom=speed;if(speed<4096)denom=4096;nearest=(speed>=3000)?5096:4096;denom=(((unsigned)denom<<16)<<16)|nearest;
 {int scaled=delta<<12;delta=scaled/denom;
}
if(delta>=128)delta=127;else if(delta< -127)delta=-127;out[0]=delta;
 phase+=(((unsigned)phase<<16)<<16);if(state==3)switch((u32)phase) {
 case 0:out[1]=64;phase++;break;
 case 1:out[1]=64;phase++;if(W(P(obj,0x50),0)!=1)phase=1;break;
 case 2:out[0]=-out[0];phase+=(u32)(angle-heading+299)<599;
  if((u32)(speed+199)<399){timer++;if((u32)timer>=51){timer=0;phase=5;}}else timer=0;break;
 case 3:phase+=(u32)(speed+49)<99;break;
 case 4:out[1]=32;phase_tail:phase++;break;case 5:out[1]=0;goto phase_tail;
 case 6:out[1]=32;delta=W(P(obj,0x50),0);phase++;if(delta<2)phase=6;break;
 case 7:state=1;phase=0;break;
 case 8:state=1;phase=0;break;
 }
 W(P(obj,0x60),0x160)=state;W(P(obj,0x60),0x158)=timer;W(P(obj,0x60),0x164)=phase;W(P(obj,0x60),0x168)=steer;W(P(obj,0x60),0x16c)=target;
 func_80033F20(obj,plan,out);if(forced)out[0]=0;func_80033C30(obj,out);
}
