#include "common.h"

extern char D_800C02AE[];
void func_80086B34(s32,u8); void func_80086D90(s32,s32);
void func_80038D40(void) {
 u8 *p=(u8 *)(D_800C02AE+0x331A);
 if(*p!=0xff && *(u16 *)(*(u8 **)(D_800C02AE+0x32F2)+0x1e)!=7) {
  s32 idx=*p, off;
  *(f32 *)(D_800C02AE+0x3336)=*(f32 *)(D_800C02AE+0x3332)*112.0f;
  off=(idx<<1)+idx; off=off<<2;
  func_80086B34(*(s32 *)(D_800C02AE+0x7f26)+off,*p);
  func_80086D90(*(s32 *)(D_800C02AE+0x7f26)+*p*12,(s32)*(f32 *)(D_800C02AE+0x3336));
 }
}
