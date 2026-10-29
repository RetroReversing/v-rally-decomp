#include "snapshot29_0433f7af8f6d.h"

typedef struct {void *fn;void *data;void *subs;u8 count,start,cur,extra;s32 zero;} E589;
typedef struct {void *fn;void *data;u8 count,a,b,pad;} S589;
typedef struct {s32 a;u8 b;u8 pad[3];s32 c;} R589;
typedef struct {u16 n,a,b,pad;s32 c,d;E589 *entries;u8 e;u8 padding[3];} O589;
extern u8 D_800A5254[],D_800C02AE[];
void func_80081540(void *);s32 *func_80081664(s32,void *);void func_80081B78(void *,void *,void *);void *func_8007EAA0(s32,s32);void func_80081B28(s32 *);void func_80059A60(void);void func_8005A764(void);
void func_8005891C(u8 *arg){
s32 a,b; s32 *buf,*p;u32 n; O589 *o;E589 *e;S589 *s;R589 *r;s32 count,m; s8 total;
func_80081540(D_800A5254);buf=func_80081664(1,arg+0x4c);func_80081B78(arg+0x4c,&a,&b);
o=func_8007EAA0(1,24);n=*buf;p=buf+1;
o->n=n;o->a=0;o->b=0;o->c=0;o->d=0;o->entries=0;o->e=0;
e=func_8007EAA0(1,o->n*20);o->entries=e;total=0;
if(n)do{
count=*p++;e->start=total;e->cur=total;e->zero=0;total+=count;e->count=count;e->fn=func_80059A60;e->subs=0;e->data=0;
if(count){s=func_8007EAA0(1,count*12);e->subs=s;do{
m=*p++;s->count=m;s->fn=func_8005A764;s->a=1;s->b=1;
if(m){r=func_8007EAA0(1,m*12);s->data=r;do{r->a=*p++;m--;r->b=*p++;r->c=*p++;r++;}while(m);}
count--;s++;
}while(count);}
m=*p++;e->extra=m;
if(m){r=func_8007EAA0(1,m*12);e->data=r;do{r->a=*p++;m--;r->b=*p++;r->c=*p++;r++;}while(m);}
e++;n--;
}while(n);
func_80081B28(buf);*(O589 **)(D_800C02AE+0x325a)=o;
}
