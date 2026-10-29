#include "snapshot29_0433f7af8f6d.h"

typedef struct { u8 pad0[4]; s32 count; u8 pad8[0x394]; u8 flags; } VRPadState;
typedef struct { u8 pad0[0xC]; u16 status; u8 type; u8 padF; } VRCont;
typedef struct { u8 pad[0x330]; s32 a; s32 b; } QQ;
extern VRPadState *D_800A1B70;
extern u8 D_800AE850[];
extern u8 D_800AFA40[];
extern u8 D_800B4288[];
#define DUMMY_UNUSED 0
s32 func_8007F4E4(s32,s32,s32); s32 func_8007F634(s32); s32 func_8007F6E0(s32); s32 func_8007F73C(s32,s32); s32 func_800863B0(s32,s32); s32 osContStartQuery(void *); s32 osContGetQuery(void *); s32 osMotorInit(void *,void *,s32);
void func_80085AE8(void) {
 s32 s0,s1,s2,s3,s4; VRCont *p; QQ *q; int z; VRPadState *state;
 if (D_800AFA40[0]) {
  D_800A1B70->flags &= 0xFE;
  s3=func_8007F4E4(4,0,8); func_8007F6E0(s3);
  osContStartQuery(D_800AE850+0x5A38);
  s0=0; func_8007F73C(0,3);
  osContGetQuery((u8*)D_800A1B70+0xC);
  z = 0;
  state=D_800A1B70;
  if (state->count>z) {
   s4=1; s1=0; s2=0x18C;
   do {
    p=(VRCont*)((u8*)state+s0*4);
    if ((p->status&4) && (p->type&1) && osMotorInit(D_800AE850+0x5A38,(u8*)state+s2,s0)==0) {
     func_800863B0(s0,0);
     q=(QQ*)((u8*)D_800A1B70+s1); q->a=s4;
    } else { q=(QQ*)((u8*)D_800A1B70+s1); q->a=0; }
    *(volatile s32 *)&q->b = 0;
    s1+=0x18; s0++; s2+=0x68;
    state=D_800A1B70;
   } while(s0<state->count);
  }
  func_8007F634(s3); D_800A1B70->flags |= 1;
 }
}
