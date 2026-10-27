#include "common.h"

extern s32 D_800C782C;
extern u8 *D_800C68F0;
typedef struct { u8 pad[0x40]; s32 key; u8 pad44[100]; s16 value; u8 padB2[12]; u8 flag; u8 tail[0x79]; } Entry;
void func_80086E30(void *arg0, s16 arg1) {
 s32 pad[2]; s32 n; s32 i; Entry *base; Entry *p;
 n=D_800C782C; base=(Entry *)(*(u8 * *)0x800b68f0); i=0;
 if(n>0) { p=(Entry *)((u8 *)base); do {
  if(p->key==*(s32 *)((u8 *)arg0+4)){p->value=arg1;p->flag=0xFF;}
  n=D_800C782C; i++; p=(Entry *)((u8 *)p+0x134);
 } while(i<n); }
}
