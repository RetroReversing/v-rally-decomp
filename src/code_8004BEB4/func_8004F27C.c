#include "common.h"

typedef struct { u8 pad50[0x50]; s32 count; u8 pad54[0x14]; void *items; } Obj;
typedef struct { void *obj; s16 state; u16 kind; } Item;
typedef struct { u8 pad1c[0x1c]; u16 type; } Child;
s32 func_8007EE9C(void *);
void func_8004F27C(Obj *arg0) {
u32 i; s32 count; Item *p; Item *base; u16 v; Child *obj; char pad[8];
count=arg0->count; base=arg0->items; i=0;
if(count != 0) do {
p = &base[i];
if(p->state==0) {
obj=p->obj; v=obj->type;
if((v==5)|(v==0)) func_8007EE9C(obj);
if(p->kind==1) func_8007EE9C(p);
}
i++;
} while(i<arg0->count);
}
