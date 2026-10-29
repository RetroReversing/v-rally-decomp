#include "snapshot29_0433f7af8f6d.h"

typedef struct Rec { s16 x[16]; u16 key; } Rec;
extern Rec *D_800B55F0;
extern u16 *D_800AFA60;
extern Rec D_800C5E08;
s32 func_80056C94(s32 arg0,s32 arg1) {
s32 left;
s32 right;
s32 key;
left=arg0-1;
right=arg1+1;
key=D_800AFA60[D_800B55F0[arg0].key];
for(;;) {
do { right--; } while(key<D_800AFA60[D_800B55F0[right].key]);
do { left++; } while(D_800AFA60[D_800B55F0[left].key]<key);
if(left>=right) break;
D_800C5E08=D_800B55F0[left];
D_800B55F0[left]=D_800B55F0[right];
D_800B55F0[right]=D_800C5E08;
}
return right;
}
