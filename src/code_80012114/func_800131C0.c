#include "decompdecomp_contract_800131c0.h"
#line 1 "func.c"
static inline s32 part_y(u32 y){return y|0xF6000000;}
extern char D_800B56F0[];
extern char D_800C7420[];
extern char D_800B0120[];
extern char D_800B56F8[];
extern char D_800C7428[];
extern char D_800B0128[];
extern char D_800C8380[];
extern void *D_800C7F84;
extern void *D_800B681C;
extern unsigned int D_800C351C;
extern unsigned int D_800B55E8;
extern int D_800AFA4C;
extern int D_800C81D8;
extern int D_800ADFAC;
extern unsigned int D_800D066C;
extern int D_800C7300;
typedef struct 
{
  s32 x0;
  s32 y0;
  s32 x1;
  s32 y1;
} Rect7;
extern Rect7 D_800C6088[3];
extern int D_800B7010;
extern unsigned int D_800C6F08;
void *func_800056FC();
void *func_80006008();
s32 func_80006014();
s32 func_800061FC();
void func_8000C22C(void *, s32, s32, s32, u8);
s32 func_8000C244();
void func_800131B4(void *, s16, s32);
s32 func_8001BD1C();
s32 guMtxF2L();
s32 guMtxIdent();
void guOrthoF(void *, f32, f32, f32, f32, f32, f32, f32);
s32 func_80099DF8();
u64 func_8009A2B0(u64, u64) __attribute__((const));
u64 func_8009A310(double) __attribute__((const));
static inline s16 __normghost(s32 x){x=(u32)x<<16;x=(s32)x>>16;return x;}
static inline s32 __firstsetter(void *p,s32 h){h=(s16)h;func_800131B4(p,h,190);return h;}
extern s32 D_8009B960;
extern s32 D_8009BB28;
extern s32 D_8009BB48;
extern s32 D_8009BB68;
extern s32 D_8009CE70;
extern s32 D_8009CE74;
extern void *D_800A0384;
extern s32 D_800A1468;
extern char D_800A4120[];
extern char D_800A4128[];
extern f64 D_800A4140;
extern f64 D_800A4148;
extern char D_800A73E0[];
extern char D_800AE850[];
extern char D_800C02AE[];
void func_800131C0(void)
{
  char sp20[0x68];
  float sp88[4][4];
  u16 spCE;
  void *spD4;
  u64 ticks;
  f64 var_fv1;
  s32 temp_a1_2;
  s32 temp_a1_3;
  s16 temp_s0_3;
 s32 packed_word;
  s32 temp_s1_3;
  short var_s3;
  s32 __repair_var_s3_1;

s16 saved_height;
s32 var_s6;
  char *temp_v0_15;
  void *new_var;
  char *temp_v0_4;
  char *temp_v0_8;
  char *temp_v0_9;
  char *var_a1_2;
  char *var_a2;
  char *var_a3;
  char *var_s0;
  char *var_t0;
  char *var_t0_2;
  char *var_t1;
  char *var_t1_2;
  char *var_t2;
  char *var_t3;
  char *var_t4;
  char *var_t5;
  char *var_t6;
  s32 temp_a0;
  s32 temp_a1;
  s32 temp_a3;
  s32 temp_s0;
  s32 temp_s0_5;

  s32 temp_v0_10;
  s32 temp_v0_11;
  s32 temp_v0_12;
  s32 temp_v0_13;
  s32 temp_v0_14;
  s32 temp_v0_5;
  s32 temp_v0_6;
  s32 temp_v0_7;
  s32 temp_v1;
  s32 temp_v1_10;
  s32 temp_v1_2;
  s32 temp_v1_4;
  s32 temp_v1_5;
  s32 temp_v1_6;
  s32 var_s3_3;
  u32 temp_s7;



  u32 temp_v1_7;
  u32 var_s2;
  void *temp_a0_2;
  void *temp_a0_3;
  void *temp_a0_4;
  void *temp_a0_5;
  void *temp_a0_6;
  void *temp_a0_7;
  void *temp_a0_8;
  void *temp_s0_4;
  void *temp_s1;
  void *temp_s1_2;
  void *temp_s4;
  void *temp_s5;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v1_8;
  void *temp_v1_9;
  void *var_a0;
  void *var_a1;
  void *var_s4;
  void *var_s5;

char *rect_y0;
u32 combined_index3;
u32 loop0_fill,loop0_rect,loop0_sync,loop1_fill,loop1_rect,loop1_sync;
char *text_buffer;
  spD4 = func_800056FC();
  var_s3 = 0;
new_var=func_80006008(spD4);spCE=0;var_s6=0;saved_height=0;temp_v0=new_var;
  temp_s7 = *((u32 *) (((char *) D_800B681C) + 4));
  D_800C351C = 0U;
  var_s2 = 0;
  if (temp_s7 != 0)
  {
    temp_s1 = D_800B56F0;
    do
    {
      temp_s0 = var_s2 * 8;
      temp_v0_2 = (char *) temp_s0;
      temp_v0_2 += (s32) D_800B681C;
      temp_a0 = *((s32 *) (((char *) temp_v0_2) + 0xD0));
      temp_a1 = *((s32 *) (((char *) temp_v0_2) + 0xD4));
      var_s2 += 1;
      func_800131B4(temp_s1, (s16) (((u32) func_8009A2B0(*((u64 *) (((char *) temp_v0_2) + 0xD0)), 250)) + 0x28), 0xCC);
      new_var = temp_s1 + 8;
      var_t0 = (char *) temp_s0;
      var_t0 += (s32) D_800B681C;
      temp_s1 = new_var;
      temp_a1_2 = ((u32) func_8009A2B0(*((u64 *) (((char *) var_t0) + 0xF0)), 250)) + 0x28;
      var_s3 = temp_a1_2;
      func_800131B4(temp_s1, temp_a1_2, 0xCE);
      temp_s1 = (char *) temp_s1;
      temp_s1 += (s32) 8;
    }
    while (var_s2 < temp_s7);
  }
  temp_s7 = *((u32 *) (((char *) D_800B681C) + 0));
  if ((((u32) D_800B55E8) < ((u32) ((s16) var_s3))) & (((s16) var_s3) < 0x140))
  {
    D_800B55E8 = (u32) ((s16) var_s3);
  }
  D_800AFA4C = 0;
  D_800C81D8 = 0;
  D_800ADFAC = 0;
  var_s2 = 0;
  if (temp_s7 != 0)
  {
    var_s5 = D_800C7420;
    var_s4 = D_800B0120;
    do
    {
      var_s6 = var_s2 * 8;
      temp_s1_2 = var_s6 + (s32)D_800B681C;
      temp_s0_3 = ((u32) func_8009A2B0(*((u64 *) (((char *) temp_s1_2) + 0x10)), 250)) + 0x28;
      var_s3 = temp_s0_3;
      temp_s1_3 = ((u32) func_8009A2B0(*((u64 *) (((char *) temp_s1_2) + 0x90)), 250)) + 0x28;
      spCE = temp_s1_3;
      if (((s16) temp_s0_3) >= 0x141)
      {
        var_s3 = 0x140;
      }temp_a0=__firstsetter(var_s4,var_s3);
      var_s4 += 8;
      if(var_s2){func_800131B4(var_s4, temp_s1_3, 0xC0);}else{func_800131B4(var_s4, temp_s1_3, 0xC0);}
      func_800131B4(var_s5,temp_a0,0xC5);
      var_s4 += 8;
      var_s5 += 8;
      temp_v0_3 = var_s6 + (s32)D_800B681C;
      var_s2 += 1;
{u64 quotient=func_8009A2B0(*((u64 *) (((char *) temp_v0_3) - (-0x50))), 250);temp_a1_3=(u32)quotient+40;if((u32)(quotient>>32)){saved_height=temp_a1_3;func_800131B4(var_s5,temp_a1_3,199);}else{saved_height=temp_a1_3;func_800131B4(var_s5,temp_a1_3,199);}}
      var_s5 += 8;
    }
    while (var_s2 < temp_s7);
  }
  if ((((u32) D_800D066C) < ((u32) ((s16) ((u16) spCE)))) & (((s16) ((u16) spCE)) < 0x140))
  {
    D_800D066C = (u32) ((s16) ((u16) spCE));
  }
  if ((((u32) D_800C351C) < ((u32) ((s16) saved_height))) & (((s16) saved_height) < 0x140))
  {
    D_800C351C = (u32) ((s16) saved_height);
  }
  if (D_800D066C != 0)
  {
    D_800D066C = (u32) (D_800D066C - 1);
  }
  if (D_800C351C != 0)
  {
    D_800C351C = (u32) (D_800C351C - 1);
  }
  if (D_800C7300 != 0)
  {
    D_800C7300 = (s32) (D_800C7300 - 1);
  }
  if (D_800B55E8 != 0)
  {
    D_800B55E8 = (u32) (D_800B55E8 - 1);
  }
  var_s2 = 0;
  if (temp_s7 != 0)
  {
    if (D_800C02AE)
    {
      var_a1 = D_800B681C;
    }
    else
    {
      var_a1 = D_800B681C;
    }
    do
    {
{u64 a=*((volatile u64 *)((char *)var_a1+144));
u64 b=*((volatile u64 *)((char *)var_a1+16));
u64 c=*((volatile u64 *)((char *)var_a1+80));
u64 d=*((volatile u64 *)((char *)var_a1+16));
if(temp_s7){var_s2+=1;}else{var_s2+=1;}D_800ADFAC+=(u32)(a-b);D_800C81D8+=(u32)(c-d);
}
      var_a1 += 8;
    }
    while (var_s2 < temp_s7);
  }
  if (((u32) D_800D066C) >= 0x141U)
  {
    D_800D066C = 0x140U;
  }
  if (((u32) D_800C351C) >= 0x141U)
  {
    D_800C351C = 0x140U;
  }
  if (((u32) D_800B55E8) >= 0x141U)
  {
    D_800B55E8 = 0x140U;
  }
  D_800C6088[0].x0 = 0x28;
  D_800C6088[0].y0 = 0xBD;
  D_800C6088[0].y1 = 0xC1;
  D_800C6088[1].y0 = 0xC4;
  D_800C6088[1].y1 = 0xC8;
  D_800C6088[2].y0 = 0xCB;
  D_800C6088[2].y1 = 0xCF;
  D_800C6088[1].x0 = 0x28;
  D_800C6088[2].x0 = 0x28;
  D_800C6088[0].x1 = (u32) D_800D066C;
  D_800C6088[1].x1 = (u32) D_800C351C;
  D_800C6088[2].x1 = (u32) D_800B55E8;
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
    g[0] = 0xE7000000;
    g[1] = 0;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
    g[0] = 0xE3000A01;
    g[1] = 0x300000;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
    g[0] = 0xE200001C;
    g[1] = 0;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
    g[0] = 0xF7000000;
    g[1] = 0x84218421;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
{u32 x,y,xx,yy;y=*((volatile u32 *)&D_800C6088[0].y1);x=D_800C6088[0].x1;x&=1023;x=x*16384;yy=(y&1023)*4;yy|=0xF6000000;g[0]=x|yy;}
    g[1] = (s32) (((D_800C6088[0].x0 & 0x3FF) << 0xE) | ((D_800C6088[0].y0 & 0x3FF) * 4));
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
    g[0] = 0xE7000000;
    g[1] = 0;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
    g[0] = 0xF7000000;
    g[1] = 0x84218421;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
{s32 x,y;x=D_800C6088[1].x1;y=D_800C6088[1].y1;x&=1023;x<<=14;y&=1023;y<<=2;y|=0xF6000000;g[0]=x|y;}
    packed_word = ((D_800C6088[1].x0 & 0x3FF) << 0xE) | ((D_800C6088[1].y0 & 0x3FF) * 4);
    g[1] = (s32) packed_word;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
    g[0] = 0xE7000000;
    g[1] = 0;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
    g[0] = 0xF7000000;
    g[1] = 0x84218421;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
{s32 x,y;x=D_800C6088[2].x1;y=D_800C6088[2].y1;x&=1023;x<<=14;y&=1023;y<<=2;y|=0xF6000000;g[0]=x|y;}
    g[1] = (s32) (((D_800C6088[2].x0 & 0x3FF) << 0xE) | ((D_800C6088[2].y0 & 0x3FF) * 4));
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
    g[0] = 0xE7000000;
    g[1] = 0;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
    g[0] = 0xF7000000;
    g[1] = -1;
  }
  __repair_var_s3_1 = 8;
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += 8;
    g[0] = 0xF60A0370;
    g[1] = 0xA02D0;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += __repair_var_s3_1;
    g[0] = 0xE7000000;
    g[1] = 0;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += __repair_var_s3_1;
    g[0] = 0xF7000000;
    g[1] = -1;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += __repair_var_s3_1;
    g[0] = 0xF61E0370;
    g[1] = 0x1E02D0;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += __repair_var_s3_1;
    g[0] = 0xE7000000;
    g[1] = 0;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += __repair_var_s3_1;
    g[0] = 0xF7000000;
    g[1] = -1;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += __repair_var_s3_1;
    g[0] = 0xF6320370;
    g[1] = 0x3202D0;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += __repair_var_s3_1;
    g[0] = 0xE7000000;
    g[1] = 0;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += __repair_var_s3_1;
    g[0] = 0xF7000000;
    g[1] = -1;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += __repair_var_s3_1;
    temp_a0=0;g[temp_a0]= 0xF6460370;
    g[1] = 0x4602D0;
  }
  {
    u32 *g = (u32 *) temp_v0;
    temp_v0 += __repair_var_s3_1;
    temp_v1_6=0;g[temp_v1_6] = 0xE7000000;
    g[1] = 0;
  }
  var_a0 = D_800B681C;
  temp_s7 = *((u32 *) (((char *) var_a0) + 4));
  combined_index3 = 0;

  if (temp_s7 != 0)
  {loop0_fill=0xF7000000;loop0_rect=0xF6000000;loop0_sync=0xE7000000;

    var_t1 = &D_8009BB68;
    temp_v0_4 = D_800B56F8;
    rect_y0 = temp_v0_4 - 4;
    var_a3 = temp_v0_4 - 8;
    var_a2 = temp_v0_4 + 4;
    var_a1_2 = temp_v0_4;
    var_a0 = temp_v0 - 4;
    do
    {
      var_a0 += 8;
      temp_v0 += 0x18;
      *((s32 *) ((char *)var_a0 - 4)) = loop0_fill;
      temp_v0_5 = *((s32 *)var_t1);
      var_t1 += 4;
      combined_index3 += 1;
      *((s32 *)var_a0) = temp_v0_5;
      var_a0 += 8;
{s32 x,y;x=*((s32 *)var_a1_2);y=*((s32 *)var_a2);var_a2+=0x10;var_a1_2+=0x10;x&=1023;x<<=14;y&=1023;y<<=2;y|=loop0_rect;*((s32 *)((char *)var_a0-4))=x|y;}
      temp_v0_7 = *((s32 *)var_a3);
      temp_v1_2 = *((s32 *)rect_y0);
      rect_y0 += 0x10;
      var_a3 += 0x10;
      *((s32 *)var_a0) = ((__normghost(temp_v0_7) & 0x3FF) << 14) | ((__normghost(temp_v1_2) & 0x3FF) << 2);
      var_a0 += 8;
      *((s32 *) ((char *)var_a0 - 4)) = loop0_sync;
      *((s32 *)var_a0) = 0;
    }
    while (combined_index3 < temp_s7);
  }
  temp_s7 = *((u32 *) (((char *) D_800B681C) + 0));
  var_s2 = 0;
  if (temp_s7 != 0)
  {loop1_fill=0xF7000000;loop1_rect=0xF6000000;loop1_sync=0xE7000000;

    var_t6 = &D_8009BB48;
    var_t5 = &D_8009BB28;
    temp_v0_8 = D_800C7428;
    var_t4 = temp_v0_8 - 4;
    var_t3 = temp_v0_8 - 8;
    var_t2 = temp_v0_8 + 4;
    var_t1_2 = temp_v0_8;
    temp_v0_9 = D_800B0128;
    var_t0_2 = temp_v0_9 - 4;
    var_a3 = temp_v0_9 - 8;
    var_a2 = temp_v0_9 + 4;
    var_a1_2 = temp_v0_9;
    var_a0 = temp_v0 - 4;
    do
    {
      var_a0 += 8;
      temp_v0 += 0x30;
      *((s32 *) ((char *)var_a0 - 4)) = loop1_fill;
      temp_v0_10 = *((s32 *)var_t5);
      var_t5 += 4;
      var_s2 += 1;
      *((s32 *)var_a0) = temp_v0_10;
      var_a0 += 8;
      temp_v0_6 = *((s32 *)var_a1_2);
      temp_v0_11 = *((s32 *)var_a2);
      var_a2 += 0x10;
      var_a1_2 += 0x10;
      temp_v0_6=__normghost(temp_v0_6);temp_v0_6&=1023; temp_v0_6<<=14; temp_v0_11=__normghost(temp_v0_11);temp_v0_11&=1023; temp_v0_11<<=2; temp_v0_11|=loop1_rect; *((s32 *)((char *)var_a0-4))=temp_v0_6|temp_v0_11;
      temp_v1_4 = *((s32 *)var_t0_2);
      var_t0_2 += 0x10;
      *((s32 *)var_a0) = (((*((s32 *)var_a3)) & 0x3FF) << 14) | ((temp_v1_4 & 0x3FF) << 2);
      var_a0 += 8;
      *((s32 *) ((char *)var_a0 - 4)) = loop1_sync;
      *((s32 *)var_a0) = 0;
      var_a0 += 8;
      *((s32 *) ((char *)var_a0 - 4)) = loop1_fill;
      temp_v0_12 = *((s32 *)var_t6);
      var_a3 += 0x10;
      var_t6 += 4;
      *((s32 *)var_a0) = temp_v0_12;
      var_a0 += 8;
      temp_v1_5 = *((s32 *)var_t1_2);
      temp_v0_13 = *((s32 *)var_t2);
      var_t2 += 0x10;
      var_t1_2 += 0x10;
      temp_v1_5=__normghost(temp_v1_5);temp_v1_5&=1023; temp_v1_5<<=14; temp_v0_13=__normghost(temp_v0_13);temp_v0_13&=1023; temp_v0_13<<=2; temp_v0_13|=loop1_rect; *((s32 *)((char *)var_a0-4))=temp_v1_5|temp_v0_13;
      temp_v0_14 = *((s32 *)var_t3);
      temp_v1_6 = *((s32 *)var_t4);
      var_t4 += 0x10;
      var_t3 += 0x10;
      *((s32 *)var_a0) = ((temp_v0_14 & 0x3FF) << 14) | ((temp_v1_6 & 0x3FF) << 2);
      var_a0 += 8;
      *((s32 *) ((char *)var_a0 - 4)) = loop1_sync;
      *((s32 *)var_a0) = 0;
    }
    while (var_s2 < temp_s7);
  }
  {u32 *g=(u32*)temp_v0;u32 opcode=0xE7000000;if(temp_s7){temp_v0+=8;g[0]=opcode;g[1]=0;}else{temp_v0+=8;g[0]=opcode;g[1]=0;}}
  var_fv1 = (f64) D_800B7010;
  if (D_800B7010 < 0)
  {
    var_fv1 += D_800A4140;
  }
  ticks = func_8009A310(var_fv1 * D_800A4148);
  temp_v1_7 = (u32) ticks;
  D_800C6F08 = (u32) func_8009A2B0(ticks << 6, 3000);
  func_80006014(spD4, temp_v0);
  if (D_800A1468 == 0)
  {
    temp_s0_4 = D_800C8380;
    guMtxIdent(temp_s0_4);
    temp_v1_8 = *((void **) (((char *) spD4) + 0x14));
    *((void **) (((char *) spD4) + 0x14)) = (void *) (temp_v1_8 + 8);
    *((s32 *) (((char *) temp_v1_8) + 0)) = 0xDA380003;
    *((void **) (((char *) temp_v1_8) + 4)) = temp_s0_4;
    __repair_var_s3_1 = 0;
    ;
    temp_s0_5 = func_8001BD1C();
    guOrthoF(&sp88, (f32) (*((s16 *) (((char *) (*((void **) (((char *) D_800C7F84) + 0x178)))) + 8))), (f32) (*((s16 *) (((char *) (*((void **) (((char *) D_800C7F84) + 0x178)))) + 0xC))), (f32) (*((s16 *) (((char *) (*((void **) (((char *) D_800C7F84) + 0x178)))) + 0xE))), (f32) (*((s16 *) (((char *) (*((void **) (((char *) D_800C7F84) + 0x178)))) + 0xA))), -1.0f, 10.0f, 1.0f);
    guMtxF2L(&sp88, temp_s0_5);
    combined_index3 = 0;
    func_800061FC(spD4, temp_s0_5);
    func_8000C22C((void *)(*((s32 *) (((char *) D_800A0384) + 4))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    if (temp_s7 != 0)
    {
text_buffer=sp20;
      var_s3_3 = 0x50;
      temp_v0_15 = D_800C7428;
      temp_a0_3 = temp_v0_15 - 8;
      var_s0 = temp_v0_15;
      do
      {
        func_80099DF8(&sp20, &D_800A4120, ((*((s32 *) var_s0)) - (*((s32 *) temp_a0_3))) & 0xFFFF);
        combined_index3 += 1;
        func_8000C244(*((s32 *) (((char *) D_800A0384) + 4)), spD4, 0x14, var_s3_3, text_buffer, 0);
        var_s3_3 += 10;
        __repair_var_s3_1 += *((s32 *) var_s0) - *((s32 *) temp_a0_3);
        temp_a0_3 += 0x10;
        var_s0 += 0x10;
      }
      while (combined_index3 < temp_s7);
    }
    func_80099DF8(&sp20, &D_800A4120, __repair_var_s3_1);
    func_8000C244(*((s32 *) (((char *) D_800A0384) + 4)), spD4, 0x14, (combined_index3 * 0xA) + 0x64, &sp20, 0);
    func_80099DF8(&sp20, &D_800A4128, D_8009CE70, D_8009CE74, D_8009B960);
    func_8000C244(*((s32 *) (((char *) D_800A0384) + 4)), spD4, 0x14, 0x40, &sp20, 0);
  }
}

