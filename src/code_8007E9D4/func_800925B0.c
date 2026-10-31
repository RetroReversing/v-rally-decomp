#include "snapshot31_manual_verified.h"

typedef struct Param {struct Param *next;s32 time;s16 type,reset;s32 value,value2,value3,value4;} Param;
typedef struct Env {struct Env *input;s32 pad4;s32 (*handler)(struct Env *,s32,s32);u8 padc[12];s16 pan,volume,cvolL,cvolR;u16 dry,wet,rateL;s16 ratemL,targetL;u16 rateR;s16 ratemR,targetR;s32 delta,segEnd,first;Param *ctrl,*tail;} Env;
#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
extern s16 D_800A38A0[];extern u8 D_800A7070[],D_800A7074[];extern void *D_800A2500;
extern void func_800914E0(void *,void *,s32);extern void func_8008EC18(void *);extern void _freePVoice(void *,void *);
extern void *_pullSubFrame(Env *,s16 *,s16 *,s32,s32,void *);extern f32 _getVol(f32,s32,s16,u16);
void *func_800925B0(Env *env, s16 *out,s32 count,s32 time,void *cmd){
s16 left,right;s32 last=time,delta;Param *p,*freeParam,*done;Env *state;
right=0;left=0;
while(env->ctrl){
{s32 previous=last;last=env->ctrl->time;delta=last-previous;}if(count<delta)break;
if(delta<0)func_800914E0(D_800A7070,D_800A7074,104);
if(delta>160)func_800914E0(D_800A7070,D_800A7074,105);
switch(env->ctrl->type){
case 13:
p=env->ctrl;state=env;
if(p->reset)env->handler(env,8,0);
env->handler(env,5,p->value4);env->handler(env,9,0);
env->first=1;env->delta=0;env->segEnd=p->value3;
env->volume=(F(p,s16,16)*F(p,s16,16))>>15;env->pan=F(p,u8,18);
env->dry=D_800A38A0[F(p,u8,19)];env->wet=D_800A38A0[127-F(p,u8,19)];
if(p->value3){env->cvolL=1;env->cvolR=1;}
else {env->cvolL=(env->volume*D_800A38A0[env->pan])>>15;env->cvolR=(env->volume*D_800A38A0[127-env->pan])>>15;}
if(state->input)state->input->handler(state->input,7,p->value);
break;
case 11:case 12:case 16:
cmd=_pullSubFrame(env,&left,&right,delta,time,cmd);
if(env->delta>=env->segEnd){
env->targetL=(env->volume*D_800A38A0[env->pan])>>15;
env->targetR=(env->volume*D_800A38A0[127-env->pan])>>15;
env->delta=env->segEnd;env->cvolL=env->targetL;env->cvolR=env->targetR;
}else {
env->cvolL=_getVol(env->cvolL,env->delta,env->ratemL,env->rateL);
env->cvolR=_getVol(env->cvolR,env->delta,env->ratemR,env->rateR);
}
if(env->cvolL==0)env->cvolL=1;if(env->cvolR==0)env->cvolR=1;
if(env->ctrl->type==12)env->pan=env->ctrl->value;
if(env->ctrl->type==11){env->delta=0;env->volume=(env->ctrl->value*env->ctrl->value)>>15;env->segEnd=env->ctrl->value2;}
if(env->ctrl->type==16){env->dry=D_800A38A0[env->ctrl->value];env->wet=D_800A38A0[127-env->ctrl->value];}
env->first=1;break;
case 14:
p=env->ctrl;if(p->reset)env->handler(env,8,0);env->handler(env,5,p->value);env->handler(env,9,0);break;
case 15:cmd=_pullSubFrame(env,&left,&right,delta,time,cmd);env->handler(env,4,0);break;
case 0:{struct Voice {u8 pad[0xd8];s32 offset;};void *synth=D_800A2500;freeParam=env->ctrl;((struct Voice *)freeParam->value)->offset=0;_freePVoice(synth,(void *)freeParam->value);}break;
default:cmd=_pullSubFrame(env,&left,&right,delta,time,cmd);env->handler(env,env->ctrl->type,env->ctrl->value);break;
}
done=env->ctrl;count-=delta;right+=delta*2;env->ctrl=done->next;if(!env->ctrl)env->tail=0;func_8008EC18(done);
}
cmd=_pullSubFrame(env,&left,&right,count,time,cmd);if(env->delta>env->segEnd)env->delta=env->segEnd;return cmd;
}
