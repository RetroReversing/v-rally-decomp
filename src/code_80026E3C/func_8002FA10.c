#include "common.h"

s32 func_8002F9C8(s32,u16);

s32 func_8002F9EC(s32,u16);

void func_8002FA10(void *arg0) {
s32 a,b;
 u32 i;
 u8 *p,*q;
 s32 off;

a=*(s32 *)((u8 *)arg0+0x10);

b=*(s32 *)arg0;

i=0;
off=0x16;
p=arg0;

do {*(s16 *)(p+0x18)=0;
i++;
p+=2;
}while(i<2);

i=0;
q=arg0;

do {q=(u8 *)arg0+i;
q[6]=0;
i++;
}while(i<4);

func_8002F9C8(a,((u16 *)arg0)[11]);

func_8002F9EC(b,*(u16 *)((u8 *)arg0+0x14));

}
