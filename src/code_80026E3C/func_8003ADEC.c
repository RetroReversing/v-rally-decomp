#include "common.h"

void func_8003ADEC(void *arg0){s32 n;void *p;p=*(void**)((char*)*(void**)((char*)arg0+0xA8)+0x24);if(p){*(s32*)((char*)arg0+0x80)|=4;n=*(s32*)((char*)*(void**)((char*)p+0x6C)+12);if(n>0x36EE80){do{if(n<=0x36EE89){*(u8*)((char*)arg0+0x90)=10;*(u8*)((char*)arg0+0x91)=200;*(u8*)((char*)arg0+0x92)=10;*(u8*)((char*)arg0+0x93)=255;}else{*(u8*)((char*)arg0+0x90)=250;*(u8*)((char*)arg0+0x91)=50;*(u8*)((char*)arg0+0x92)=10;*(u8*)((char*)arg0+0x93)=255;}}while(0);*(s32*)((char*)arg0+0x80)&=~4;}}}
