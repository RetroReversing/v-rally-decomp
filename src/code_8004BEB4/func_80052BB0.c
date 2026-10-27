#include "common.h"

extern u8 *D_800C35A0;
extern s32 D_800AE850[];
void func_8006E394(void);
typedef struct {s32 w[40];} Copy160;
void func_80052BB0(void){ *(Copy160 *)((u8 *)D_800AE850+0x7F28)=*(Copy160 *)(D_800C35A0+0x44); func_8006E394();
}
