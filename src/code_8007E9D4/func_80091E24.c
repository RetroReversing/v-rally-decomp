#include "snapshot29_0433f7af8f6d.h"

typedef struct Resample {u8 p[20];void *state;u8 p18[8];s32 delta,first;u8 tail[12];} Resample;
typedef struct Lowpass {s16 fc,fg;u8 pad[4];s16 coeff[16];void *state;s32 first;} Lowpass;
typedef struct Delay {u32 input,output;s16 ff,fb,gain,pad;f32 rsinc,rsgain;s32 delta;f32 depth;Lowpass *lp;Resample *rs;} Delay;
typedef struct Fx {u8 pad[4];void *pull;u8 pad8[12];s16 *base,*write;u32 length;Delay *delay;u8 count;u8 pad25[3];void *handler;} Fx;
typedef struct Params {u8 pad[24];s32 rate;u8 type;u8 pad1d[3];s32 *params;} Params;
extern s32 D_800A3710[],D_800A3778[],D_800A3800[],D_800A3828[],D_800A3850[],D_800A3878[];
extern void alFxPull(void),alFxParamHdl(void),func_80094F90(void),func_80093790(void*,s32,void*,s32);
extern void *alHeapDBAlloc(s32,s32,void*,s32,s32);
void func_80091E24(Fx *fx,Params *config,void *heap){
s32 *p;u16 i,j,clear;Delay *d;Lowpass *lp; s16 half; s32 k;f64 f,ratio;
func_80093790(fx,0,func_80094F90,5);fx->pull=alFxPull;fx->handler=alFxParamHdl;
switch(config->type){case 1:p=D_800A3710;break;case 2:p=D_800A3778;break;case 3:p=D_800A3800;break;case 4:p=D_800A3828;break;case 5:p=D_800A3850;break;case 6:p=config->params;break;default:p=D_800A3878;break;}
fx->count=p[0];fx->length=p[1];fx->delay=alHeapDBAlloc(0,0,heap,fx->count,40);fx->base=alHeapDBAlloc(0,0,heap,fx->length,2);fx->write=fx->base;j=2;
for(clear=0;clear<fx->length;clear++)fx->base[clear]=0;
for(i=0;i<fx->count;i++){d=&fx->delay[i];d->input=p[j++];d->output=p[j++];d->fb=p[j++];d->ff=p[j++];d->gain=p[j++];
if(p[j]){d->rsinc=((f32)p[j++]/1000.0f)*2.0/config->rate;d->depth=((f32)p[j++]/100.0)*(d->output-d->input);d->rsgain=1.0f;d->delta=0;d->rs=alHeapDBAlloc(0,0,heap,1,52);d->rs->state=alHeapDBAlloc(0,0,heap,1,32);d->rs->delta=0;d->rs->first=1;}else{d->rs=0;j+=2;}
if(p[j]){d->lp=alHeapDBAlloc(0,0,heap,1,48);d->lp->state=alHeapDBAlloc(0,0,heap,1,8);d->lp->fc=p[j++];lp=d->lp;half=(lp->fc * 65536) >> 17;lp->fg=16384-half;lp->first=1;
for(k=7;k>=0;k--)lp->coeff[k]=0;lp->coeff[8]=half;f=(s16)half/32768.0;ratio=f;for(k=9;k<16;k++){f*=ratio;lp->coeff[k]=f*32768.0;}}
else{d->lp=0;j++;}
}
}
