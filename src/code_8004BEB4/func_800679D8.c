#include "common.h"

typedef struct {u8 pad0[2]; s16 index; u8 pad4[12]; u8 *items;} Table;
typedef struct {u8 pad0[13]; u8 a,b; u8 pad15[5];} Item;
typedef struct {u8 pad0[0x228]; s8 idx; u8 pad229[2]; u8 flag; u8 pad22c[0x54]; u8 clear0, clear1, clear2, copy[4];} Obj;
extern u8 D_800B5C6C; extern s16 D_800C6F12; extern Obj *D_800A1468; extern u8 *D_800C35A0; extern Table *D_800C3508; extern void func_80057D5C(s32,s32,s32,s32);
void func_800679D8(void){u8 x; u8 *src; u8 i; Table *p; Item *item; x=D_800B5C6C&3; D_800C6F12=0; D_800B5C6C=x; D_800A1468->flag=x; { s8 idx=D_800A1468->idx; u8 *base=D_800C35A0; src=base+(idx*40+0x44); } D_800A1468->clear2=0; D_800A1468->clear1=0; D_800A1468->clear0=0; i=0; do { D_800A1468->copy[i]=src[i]; i++; } while(i<4); p=D_800C3508; item=(Item *)((u8 *)p->items+p->index*20); item->b=item->a; func_80057D5C(10,11,2,6); }
