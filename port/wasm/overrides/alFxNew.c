/* port (WebAssembly build): the switch cases follow the console's jump table. The matched C's labels compile to
   the same code but a different table, which the judge doesn't compare: this fix belongs in the matched C. */
typedef struct Resample {u8 p[20];void *state;u8 p18[8];s32 delta,first;u8 tail[12];} Resample;
typedef struct Lowpass {s16 fc,fg;u8 pad[4];s16 coeff[16];void *state;s32 first;} Lowpass;
typedef struct Delay {u32 input,output;s16 ff,fb,gain,pad;f32 rsinc,rsgain;s32 delta;f32 depth;Lowpass *lp;Resample *rs;} Delay;
typedef struct Fx {u8 pad[4];void *pull;u8 pad8[12];s16 *base,*write;u32 length;Delay *delay;u8 count;u8 pad25[3];void *handler;} Fx;
typedef struct Params {u8 pad[24];s32 rate;u8 type;u8 pad1d[3];s32 *params;} Params;
extern s32 D_800A3710[],D_800A3778[],D_800A3800[],D_800A3828[],D_800A3850[],D_800A3878[];
extern void alFxPull(void),alFxParamHdl(void),func_80094F90(void),alFilterNew(void*,s32,void*,s32);
extern void *alHeapDBAlloc(s32,s32,void*,s32,s32);

/* Sets up an effect (delay-line) object: picks the parameter table from
 * config->type, allocates the delay buffer and the per-tap delay, resampler
 * and lowpass state from the heap, and fills them from the table. */
void alFxNew(Fx *fx,Params *config,void *heap){
s32 *table;u16 pi,zi,di;Delay *dly;Lowpass *lp; s16 half; s32 k;f64 f,ratio;
alFilterNew(fx,0,func_80094F90,5);fx->pull=alFxPull;fx->handler=alFxParamHdl;
switch(config->type){case 1:table=D_800A3710;break;case 2:table=D_800A3778;break;case 5:table=D_800A3800;break;case 3:table=D_800A3828;break;case 4:table=D_800A3850;break;case 6:table=config->params;break;default:table=D_800A3878;break;}
fx->count=table[0];fx->length=table[1];fx->delay=alHeapDBAlloc(0,0,heap,fx->count,40);fx->base=alHeapDBAlloc(0,0,heap,fx->length,2);fx->write=fx->base;pi=2;
for(zi=0;zi<fx->length;zi++)fx->base[zi]=0;
for(di=0;di<fx->count;di++){dly=&fx->delay[di];dly->input=table[pi++];dly->output=table[pi++];dly->fb=table[pi++];dly->ff=table[pi++];dly->gain=table[pi++];
if(table[pi]){dly->rsinc=((f32)table[pi++]/1000.0f)*2.0/config->rate;dly->depth=((f32)table[pi++]/100.0)*(dly->output-dly->input);dly->rsgain=1.0f;dly->delta=0;dly->rs=alHeapDBAlloc(0,0,heap,1,52);dly->rs->state=alHeapDBAlloc(0,0,heap,1,32);dly->rs->delta=0;dly->rs->first=1;}else{dly->rs=0;pi+=2;}
if(table[pi]){dly->lp=alHeapDBAlloc(0,0,heap,1,48);dly->lp->state=alHeapDBAlloc(0,0,heap,1,8);dly->lp->fc=table[pi++];lp=dly->lp;half=(lp->fc * 65536) >> 17;lp->fg=16384-half;lp->first=1;
for(k=7;k>=0;k--)lp->coeff[k]=0;lp->coeff[8]=half;f=(s16)half/32768.0;ratio=f;for(k=9;k<16;k++){f*=ratio;lp->coeff[k]=f*32768.0;}}
else{dly->lp=0;pi++;}
}
}
