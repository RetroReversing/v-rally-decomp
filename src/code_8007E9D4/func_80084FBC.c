#include "common.h"

typedef struct {s32 f[14];} Controls;
typedef struct {s32 f[5];} Small;
typedef union {struct {u8 pad[0xAC];Controls ctrl[4];} big; struct {u8 pad[0x68];Small ctrl[4];} small;} Sys;
extern Sys *D_800A1B70;
void func_80084FBC(u8 arg0,u32 arg1,s32 arg2){
switch(arg1){
case 1: D_800A1B70->big.ctrl[arg0].f[0]=arg2;break;
case 2: D_800A1B70->big.ctrl[arg0].f[1]=arg2;break;
case 4: D_800A1B70->big.ctrl[arg0].f[2]=arg2;break;
case 8: D_800A1B70->big.ctrl[arg0].f[3]=arg2;break;
case 16: D_800A1B70->big.ctrl[arg0].f[4]=arg2;break;
case 32: D_800A1B70->big.ctrl[arg0].f[5]=arg2;break;
case 256: D_800A1B70->big.ctrl[arg0].f[6]=arg2;break;
case 512: D_800A1B70->big.ctrl[arg0].f[7]=arg2;break;
case 1024: D_800A1B70->big.ctrl[arg0].f[8]=arg2;break;
case 2048: D_800A1B70->big.ctrl[arg0].f[9]=arg2;break;
case 4096: D_800A1B70->big.ctrl[arg0].f[10]=arg2;break;
case 8192: D_800A1B70->big.ctrl[arg0].f[11]=arg2;break;
case 16384: D_800A1B70->big.ctrl[arg0].f[12]=arg2;break;
case 32768: D_800A1B70->big.ctrl[arg0].f[13]=arg2;break;
case 0x20000: D_800A1B70->small.ctrl[arg0].f[0]=arg2;break;
case 0x10000: D_800A1B70->small.ctrl[arg0].f[1]=arg2;break;
}}
