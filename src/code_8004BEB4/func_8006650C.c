#include "snapshot29_0433f7af8f6d.h"

typedef struct { s32 a,b; s8 c; } Rec;
extern Rec D_800A56E0;
extern u8 *D_800A1468;
extern s8 D_800A16D4;
void func_800580D0(s32,s32); void func_80053A78(void); void func_8005E0D0(s32,s32); void func_80047F94(void);
s32 func_8006650C(void) {
 Rec *src=&D_800A56E0, *dst;
 D_800A1468[0x2BD]=1;
 func_800580D0(0,0);
 D_800A1468[0x24D]=0;
 func_80053A78();
 dst=(Rec *)(D_800A1468+0x204);
 __builtin_memcpy(dst,src,9);
 func_8005E0D0(0,0);
 D_800A16D4=2;
 func_80047F94();
 return 0;
}
