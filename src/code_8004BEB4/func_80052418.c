#include "snapshot29_0433f7af8f6d.h"

typedef struct E { u8 *text; u16 count; u8 pad[14]; u16 n; s32 *vals; } E;
typedef struct R { u8 a[14]; u16 n; s32 v; } R;
extern u16 D_800ADFD0; extern u8 D_800A5028; extern s32 D_8009EB80; extern E *D_800C7F80; extern s32 *D_800B0BCC,*D_800AFA60;
extern E *func_800523EC(void); extern void func_80099DF8(u8*,u8*,u8*); extern s32 func_80034FF0(u8*,s32); extern s32 func_8001B730(u8*); extern s32 *func_8007EAA0(s32,s32);
extern void func_80052194(u16),func_80052224(u16),func_800522B0(u16),func_8005235C(u16),func_80052108(u16);
E *func_80052418(void){E *e;u8 *p;R *r;s32 i,stride;u8 buf[16];
 stride=D_800ADFD0*13; e=func_800523EC();p=e->text;r=(R*)p;
 for(i=0;i<e->count;r++,i++,p+=0x14){if((*p == '0') & (*p < ':')){func_80099DF8(buf,&D_800A5028,p+2);r->n--;}else func_80099DF8(buf,&D_800A5028,p);r->v=func_80034FF0(buf,stride);func_8001B730(p);}
 D_800B0BCC=(s32*)e->text;D_800AFA60=func_8007EAA0(1,e->count*2);
 for(i=0;i<e->count;i++)((u16*)D_800AFA60)[i]=i;
 if(D_800C7F80->n==1&&(u32)D_8009EB80<8U){switch(D_8009EB80){case 0:func_80052194(e->count);break;
case 1:func_80052224(e->count);break;
case 2:func_800522B0(e->count);break;
case 3:func_8005235C(e->count);break;
case 4:func_80052108(e->count);break;case 5:case 6:case 7:break;}}return e;}
