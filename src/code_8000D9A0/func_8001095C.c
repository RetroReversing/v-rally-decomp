#include "common.h"

extern f32 D_8009BB94,D_8009BB98,D_8009BB9C,D_8009BBA0;

extern u8 D_800C7926;
 extern u8 *D_800C7F84;

void func_800106F4(void *,s32,f32,f32);
 void func_800425F4(void *);

typedef struct {s32 words[80];
} Copy109;

void func_8001095C(u8 *arg0) {
u8 *p=D_800C7F84;

s32 a1v=*(s32 *)(p+0x178);

void *a0v=p+0x38;

f32 f0=0.0f,f1=0.0f;

switch(D_800C7926) {
case 0:
f1=D_8009BB94;
f0=D_8009BB9C;
break;

case 1:
f1=D_8009BB94;
f0=D_8009BBA0;
break;

case 2:case 3:
f1=D_8009BB98;
f0=D_8009BBA0;
break;

}
func_800106F4(a0v,a1v+8,f1,f0);

func_800425F4(D_800C7F84);

*(Copy109 *)(arg0+0x38)=*(Copy109 *)(D_800C7F84+0x38);

}
