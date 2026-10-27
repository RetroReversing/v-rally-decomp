#include "common.h"

extern u8 D_800A2590[],D_800AE850[],D_800C02AE[];

typedef struct {s32 w0,w1,w2,w3;
} S16Bytes;

s32 func_8000E2F0(s32);
void osViBlack(s32);
void osViSetMode(void*);
void osViSetSpecialFeatures(s32);
void osViSetYScale(f32);

void func_8000DB14(u8 *arg0){
s32 idx,temp_a1;
u8 *base;
S16Bytes *src,*dst,*end;

base=D_800A2590;
idx=func_8000E2F0(*(s32*)(arg0+24));
dst=(S16Bytes*)(D_800AE850+0x1298);
src=(S16Bytes*)(base+idx*80);
end=src+5;

do {
*dst=*src;
temp_a1=src->w3;
src++;
dst++;
}
while(src!=end);

osViSetMode(D_800AE850+0x1298);
osViBlack(1);

D_800C02AE[0x5BA6]=4;
osViSetYScale(1.0f);
osViSetSpecialFeatures(0x4A);

}
