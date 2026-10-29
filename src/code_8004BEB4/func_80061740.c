#include "snapshot29_0433f7af8f6d.h"

typedef struct {s32 w[8];} T8; typedef struct {u8 pad[0x2E];u8 x;} Obj;
extern T8 D_800A55C4; extern Obj *D_800C35A0;
extern void func_8004D31C(); extern s32 func_800602F4(void*); extern void func_80081540(s32); extern void func_8004C7F0(void*);
typedef struct { u32 w[160]; } Args;
void func_80061740(Args arg0) {
T8 loc; u8 old; u8 n; s32 i; void *p; void *ap;
ap=(u8*)&arg0+4;
loc=D_800A55C4;
old=D_800C35A0->x; D_800C35A0->x=0;
func_8004D31C();
if (!(n = ((u8*)ap)[17])) i=0; else i=0;
if (n) do {
p = (char *)((u8*)&arg0); p += (s32)(0x24C+(i&255)*14);
func_80081540(loc.w[func_800602F4(p)&255]);
func_8004C7F0(p); i++;
} while ((u32)(i&255) < (u32)n);
D_800C35A0->x=old;
}
