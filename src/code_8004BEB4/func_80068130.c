#include "common.h"

typedef struct Obj Obj;

struct Obj { Obj *next;
 u8 pad0[0xB];
 u8 f;
 u8 g;
 u8 h;
 u8 pad12[8];
 u8 enabled;
 };

struct Item { u8 pad[14];
 u8 value;
 u8 tail[5];
 };

typedef struct { u8 pad0[2];
 s16 count;
 u8 pad4[0xC];
 struct Item *items;
 } Manager;

typedef struct { u8 pad0[0x228];
 u8 cur;
 u8 prev;
 u8 pad22A[0x1B];
 u8 flag;
 } State;

extern Manager *D_800C3508;
 extern u8 *D_800C35A0;
 extern State *D_800A1468;

void func_80057D5C(s32,s32,s32,s32);
 Obj *func_800592AC(s32);
 Obj *func_800592D0(s32);
 void func_8008A0D8(Manager *,s32,s32);

s32 func_80068130(void) {
 s8 count=0, chosen=-1, i=0;
 union { s32 ret;
 Obj *obj;
 } u;
 Obj *tmp;
 u8 *base=D_800C35A0+0x44;

 do { if (base[(s8)i*0x28]>=0x5b) count++;
 else if(chosen<0) chosen=i;
 i++;
 } while(i<4);

 u.obj=func_800592AC(1);

 if(!count){func_8008A0D8(D_800C3508,13,0);
u.obj->f=0x50;
u.obj->g=0x50;
u.obj->h=0x50;
 D_800C3508->items[D_800C3508->count].value=12;
 tmp=func_800592D0(7);
tmp->enabled=1;
tmp=tmp->next;
u.ret=12;
tmp->enabled=1;
}
 else {tmp=func_800592D0(7);
tmp->enabled=0;
tmp=tmp->next;
tmp->enabled=0;
func_8008A0D8(D_800C3508,13,1);
u.obj->f=0xc8;
u.obj->g=0xc8;
u.obj->h=0xc8;
func_8008A0D8(D_800C3508,12,1);
if(count==4){func_8008A0D8(D_800C3508,12,0);
u.obj=func_800592AC(0);
u.obj->f=0x50;
u.obj->g=0x50;
u.obj->h=0x50;
u.ret=13;
D_800C3508->items[D_800C3508->count].value=13;
}else {u.ret=12;
D_800C3508->items[D_800C3508->count].value=12;
}
}
 if(!D_800A1468->flag){func_80057D5C(15,16,2,5);
D_800A1468->flag=1;
} i=D_800A1468->cur;
if((u8)i<4&&base[(s8)i*0x28]<0x5b)D_800A1468->prev=i;
else {D_800A1468->cur=chosen;
D_800A1468->prev=chosen;
};
return u.ret;

}
