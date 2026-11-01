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
 int angle,raw,limit,forced,progress,target,state,timer,phase,steer,speed,step;
 int i,index,nearest,delta,denom,other,heading;
 out[4]=0; out[5]=0; out[1]=0; out[0]=0;
 angle=func_8002D2C8(H(P(obj,0x5c),0x50),H(P(obj,0x5c),0x44));
 data[0]=W(P(obj,0x58),12);data[1]=W(P(obj,0x58),16);data[2]=W(P(obj,0x58),20);
 progress=W(P(obj,0x8c),0x2c);D_800B615C=obj;D_800C81D0=progress;raw=W(P(obj,0x60),0x2c);
 speed=func_8001FEDC(obj);state=W(P(obj,0x60),0x160);timer=W(P(obj,0x60),0x158);steer=W(P(obj,0x60),0x168);phase=W(P(obj,0x60),0x164);
target=W(P(obj,0x60),0x16c);forced=W(P(obj,0x6c),0x34);
 if(state!=3) {
  if((u32)(speed+199)<399 && !(W(obj,0x14)&16)) {
  timer++;if((u32)timer>=51){timer=0;phase=0;state=3;}
  } else timer=0;
 }
 state_done:
 progress=func_80033DB8(obj,progress,raw,&data[4]);
 limit=W(P(obj,0x60),0x17c)*10;if(forced)steer=limit-progress;
 func_80034134(&data[8],obj);func_800344F0(plan,obj);step=3;index=0;nearest=65000;
 for(i=0;i<data[41];i++)if(data[29+data[42+i]]<nearest){index=i;nearest=data[29+data[42+i]];}
 if(plan[6]>=2) {
  if(data[41]) {other=data[33+data[42+index]]*10;if(nearest<3000){steer=other-progress+(other>=501?-390:390);step=2;}}
 }else if(data[41]) {
  other=data[33+data[42+index]]*10;delta=speed-data[25+data[42+index]];
  if(delta>1000){step=delta/150;if(data[29+data[42+index]]<step*100)if(other>=501)steer=other-progress-300;else steer=other-progress+300;}
  else step=3;
 }
 if(step>8)step=8;
 if(data[41] && U(D_800C35A0,0x16)!=2) {
  nearest=65000;index=0;
  for(i=0;i<data[41];i++)if(W(P(*(char **)&data[37+data[42+i]],0x48),0)<4 && data[29+data[42+i]]<nearest){index=i;nearest=data[29+data[42+i]];}
  other=data[25+data[42+index]];denom=nearest/128;denom+=(denom==0);delta=(speed-other)/denom;
  if(other>=1800)other=1800;if(delta>=56){plan[4]=other;plan[7]=60;}
 }
 if(data[46]) {
  if(limit<progress){for(i=0;i<data[46];i++)if(data[51+i]==0){steer=data[33+data[47+i]]*10-progress-250;break;}}
  else if(progress<limit){for(i=0;i<data[46];i++)if(data[51+i]==1){steer=data[33+data[47+i]]*10-progress+250;break;}}
 }else {steer+=(u32)steer>>31;steer-=(steer>0);}
 if(plan[6]>=2) {
  if(steer< -350)steer=-350;if(steer>350)steer=350;

  if(target<progress+steer)target+=step;if(progress+steer<target)target-=step; }else {
  other=progress+steer;if(other<200){if(other<progress){other=progress;steer=0;}}
  if(other>800){if(progress<other){other=progress;steer=0;}}target=other;
 }
 func_80033E34(obj,target,&data[4]);heading=func_8002D2C8(data[6]-data[2],data[4]-data[0]);
 if(heading< -1024 && angle>1024)heading+=4096;if(heading>1024 && angle< -1024)angle+=4096;
 delta=angle-heading;
 if((u32)(delta+1024)>2048) {if(state==1)state=(limit>=501)?5:4;}
 else if((u32)(state-4)<2)state=1;
 if(state==4)delta=-127;if(state==5)delta=127;
 if(delta>=128)delta=127;else if(delta< -127)delta=-127;
 denom=speed;if(speed<4096)denom=4096;if(speed>=3000)denom=5096;else denom=4096;
 delta=(delta<<12)/denom;if(delta>=128)delta=127;else if(delta< -127)delta=-127;out[0]=delta;
 if(state==3)switch((u32)phase) {
 case 0:out[1]=64;phase++;break;
 case 1:out[1]=64;phase++;if(W(P(obj,0x50),0)!=1)phase=1;break;
 case 2:out[0]=-out[0];phase+=(u32)(angle-heading+299)<599;
  if((u32)(speed+199)<399){timer++;if((u32)timer>=51){timer=0;phase=5;}}else timer=0;break;
 case 3:phase+=(u32)(speed+49)<99;break;
 case 4:out[1]=32;phase++;break;
 case 5:out[1]=0;phase++;break;
 case 6:out[1]=32;phase++;if(W(P(obj,0x50),0)<2)phase=6;break;
 case 7:state=1;phase=0;break;
 case 8:state=1;phase=0;break;
 }
 W(P(obj,0x60),0x160)=state;W(P(obj,0x60),0x158)=timer;W(P(obj,0x60),0x164)=phase;W(P(obj,0x60),0x168)=steer;W(P(obj,0x60),0x16c)=target;
 func_80033F20(obj,plan,out);if(forced)out[0]=0;func_80033C30(obj,out);
}
