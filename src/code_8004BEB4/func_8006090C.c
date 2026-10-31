#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern s32 D_800A159C[16];
typedef struct { u32 w0,w1; } Command;
typedef struct { char pad[20]; void *cursor; } Packet;
typedef struct { char pad[0x178]; s32 model; } Actor;
extern s32 D_800D05D8;
extern s32 D_800C8328;
extern s32 D_800B6718[][4];
void *memcpy(void*, const void*, unsigned int);
typedef struct { char pad[0x1e]; u16 track,course,slot; char gap[0x2c]; u16 units; } Manager;
typedef struct { s32 time; char pad[2]; char name[10]; } Record;
typedef struct { char pad[0x2c]; Record times[8][4]; s32 speed[38]; } Course;
extern Course *D_800D0634[];
extern char D_800C8380[];
#define MULTU_HI(a,b) ((u32)(((u64)(u32)(a)*(u32)(b))>>32))
#define sp20 (*(s16 *)buf20)
#define sp22 (buf20[2])
#define sp30 (*(s16 *)buf30)
#define sp38 (*(s16 *)buf38)
extern char *D_800C7F84;
extern char *D_800C3508;
extern char *D_800C35A0;
typedef struct 
{
  s32 x;
  s32 y;
  s32 z;
} Vec3Word;
s32 func_80005500(s32, u16 *);
void *func_800056FC(s32);
void *func_80006008(void *);
s32 func_80006014();
s32 func_800061FC(void *, s32);
s32 func_8000EF0C(s32, s32 *, s32 *);
s32 func_80010A6C();
s32 func_80010BFC(s32, void *, s32 *);
s32 func_8001BD1C();
s32 func_8001C1A8(s32 *, s32 *);
Actor *func_8004240C(s32);
s32 func_8004CF7C(s32, s32, s32, s32, f32, s32, s32);
s32 func_8004D1A8(s32, s32, f32, s32, s32);
s32 func_80052E94(s32, s16 *);
s16 *func_80057918(s32, s32);
void *func_800592D0(s32);
s32 func_80059618(void *, u8, u8, u8, s32);
s32 func_800596F4(void *, s16, s16, s16 *);
s32 func_8005A6BC(s32);
s32 func_8005A6E0(s32);
s32 func_8005D4A4(s32);
s32 func_80060820(s32);
s32 func_80097E30();
s32 func_800980D0(s16 *, s32 *);
s32 func_80099DF8();
s32 guMtxIdent(void *);
extern s32 D_8009D540;
extern u16 D_800A0370;
extern u16 D_800A0372;
extern u16 D_800A0374;
extern u16 D_800A0376;
extern void *D_800A1468;
extern u8 D_800A14D5;
extern s32 D_800A14DC;
extern u16 D_800A155C;
extern u16 D_800A155E;
extern u16 D_800A1560;
extern u16 D_800A1562;
extern s32 D_800A1564;
extern s32 D_800A156C;
extern s32 D_800A1578;
extern s32 D_800A1584;
extern s32 D_800A1588;
extern f32 D_800A158C;
extern s32 D_800A15D0;
extern s32 D_800A15DC;
extern s32 D_800A161C;
extern s32 D_800A5418;
extern s32 D_800A541C;
extern s32 D_800A5428;
extern s32 D_800A5434;
extern s32 D_800A54FC;
extern const char D_800A5504[4] __attribute__((aligned(2)));
extern s8 D_800A5506;
extern s32 D_800A5508;
extern s32 D_800A5524;
extern s32 D_800A552C;
extern f64 D_800A5538;
extern f64 D_800A5540;
extern f64 D_800A5548;
extern char D_800AE850[];
extern char D_800C02AE[];
void func_8006090C(void)
{
  char buf20[16];
  s32 loop4;
  s16 *textbuf;
  char buf30[8];
  char buf38[24];
  char *manager;
  u32 track;
  u32 course;
  u16 units;
  
  char *table;
  s32 *var_a1;
  s32 *var_a1_2;
  f64 temp_fv1;
  f32 angle_z;
  f64 var_fv1;
  s32 *temp_s0_8;
  s32 *zeroat;
  s32 *basevec;
  s32 temp_a3;
  s16 temp_s0;
  s32 temp_s1;
  s32 temp_v0_2;
  s32 var_a2;
  s32 var_s0;
  s32 var_s0_2;

  s32 var_s3;
  u32 var_s6;
  s32 var_s7;
  s16 var_a2_3;
  u32 var_hi;
  s32 temp_a2;
  u8 var_a2_2;
  void *temp_s0_4;
  void *temp_s0_5;
  void *temp_s0_6;
  void *temp_s0_7;
  void *temp_s2_7;
  void *temp_s4;
  void *temp_s4_2;
  void *temp_s5;
  void *temp_s5_2;
  void *temp_s2;


  void *temp_v0_5;
  void *temp_v0_6;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  void *temp_v1_4;
  char *actor;
  func_80097E30(&sp20, 0, 0x10);
  var_s7 = 0;
  if ((*((u8 *) (((char *) D_800A1468) + 0x249))) != 0)
  {
    func_80097E30(buf38, 0, 0xA);
    temp_s2 = func_800592D0(1);
    {
    manager = D_800C35A0;
track=*((u16*)(manager+0x1e)); course=*((u16*)(manager+0x20)); var_s6=D_800D0634[track][course].speed[*((u16*)(manager+0x22))];
 units=*((u16*)(manager+0x50));
    }
 if (units == 0) { var_a2 = var_s6 / 1000; var_hi = ((u32) (var_s6 % 1000)) / 100; func_80099DF8(buf38, &D_800A541C, var_a2 & 0xFFFF, var_hi & 0xFFFF); } else { temp_fv1 = (f64) ((s32) var_s6); if (((s32) var_s6) < 0) { temp_fv1 += D_800A5538; } temp_fv1 *= D_800A5540; if (!(temp_fv1 >= D_800A5548)) { var_s6 = (s32) temp_fv1; } else { var_s6 = (s32) (temp_fv1 - D_800A5548); var_s6 |= 0x80000000; } var_a2 = var_s6 / 1000; var_hi = ((u32) (var_s6 % 1000)) / 100; func_80099DF8(buf38, &D_800A5428, var_a2 & 0xFFFF, var_hi & 0xFFFF); } func_80059618(temp_s2, *((u8 *) (((char *) temp_s2) + 0xB)), *((u8 *) (((char *) temp_s2) + 0xC)), *((u8 *) (((char *) temp_s2) + 0xD)), (s32) (*((u8 *) (((char *) temp_s2) + 0xE)))); func_800596F4(temp_s2, *((s16 *) (((char *) temp_s2) + 0x6)), *((s16 *) (((char *) temp_s2) + 0x8)), buf38); if (D_800A14D5 != 0) { func_8005A6BC(0xE); temp_s2 = func_800592D0(0xF); func_80059618(temp_s2, *((u8 *) (((char *) temp_s2) + 0xB)), *((u8 *) (((char *) temp_s2) + 0xC)), *((u8 *) (((char *) temp_s2) + 0xD)), (s32) (*((u8 *) (((char *) temp_s2) + 0xE)))); func_80097E30(&sp30, 0, 2); if ((*((u16 *) (((char *) D_800C35A0) + 0x1E))) == 0) { var_a2_2 = *((u8 *) (((char *) D_800C35A0) + 0x30)); if (var_a2_2 == 0) { func_800596F4(temp_s2, *((s16 *) (((char *) temp_s2) + 0x6)), *((s16 *) (((char *) temp_s2) + 0x8)), func_80057918(D_800C8328, 0x174)); } else { func_80099DF8(&sp30, &D_800A5434, var_a2_2); func_800596F4(temp_s2, *((s16 *) (((char *) temp_s2) + 6)), *((s16 *) (((char *) temp_s2) + 8)), &sp30); } } else { var_a2_2 = 3; func_80099DF8(&sp30, &D_800A5434, var_a2_2); func_800596F4(temp_s2, *((s16 *) (((char *) temp_s2) + 0x6)), *((s16 *) (((char *) temp_s2) + 0x8)), &sp30); } } else { func_8005A6E0(0xE); } if ((*((s16 *) (((char *) D_800C3508) + 0x2))) != 4) { temp_s2 = func_800592D0(0x10); var_s3 = 0; do { temp_s0 = var_s3 & 0xFF; temp_a2 = temp_s0 + 1; func_80099DF8(&sp20, &D_800A54FC, temp_a2, D_800D0634[((Manager*)D_800C35A0)->track][((Manager*)D_800C35A0)->course].times[((Manager*)D_800C35A0)->slot][temp_s0].name); var_s3 += 1; func_800596F4(temp_s2, *((s16 *) (((char *) temp_s2) + 0x6)), (s16) ((*((s16 *) (((char *) temp_s2) + 0x8))) + (temp_s0 * 0x16)), &sp20); } while (((u32) (var_s3 & 0xFF)) < 3U); temp_s2 = func_800592D0(0x12); temp_s4 = func_800592D0(0x11); var_s3 = 0;
 do { temp_s0 = var_s3 & 0xFF;
 temp_s1 = D_800D0634[((Manager*)D_800C35A0)->track][((Manager*)D_800C35A0)->course].times[((Manager*)D_800C35A0)->slot][temp_s0].time; func_80097E30(&sp20, 0, 0xF);
 func_80052E94(temp_s1, &sp20);
 func_800596F4(temp_s2, *((s16 *) (((char *) temp_s2) + 0x6)), (s16) ((*((s16 *) (((char *) temp_s2) + 0x8))) + (temp_s0 * 0x16)), &sp20);
 if (temp_s0 == 0) { var_s7 = temp_s1;
 } else { func_80097E30(&sp20, 0, 0xF);
 __builtin_memcpy(&sp20, &D_800A5504, 3);
 func_80052E94(temp_s1 - var_s7, (s16 *) (&sp22));
 func_800980D0(&sp20, &D_800A5508);
 func_800596F4(temp_s4, *((s16 *) (((char *) temp_s4) + 0x6)), (s16) ((*((s16 *) (((char *) temp_s4) + 0x8))) + ((temp_s0 - 1) * 0x16)), &sp20);
 } var_s3 += 1;
 } while (((u32) (var_s3 & 0xFF)) < 3U);
 } else if ((*((u16 *) (((char *) D_800C35A0) + 0x22))) != 0) { func_8005A6BC(0x14); func_8005A6BC(0x18); func_8005A6BC(0x19); func_8005A6BC(0x1A); temp_s2 = func_800592D0(0x10); func_80097E30(&sp20, 0, 0x10); var_s3 = 0;  do { var_s0 = var_s3 & 0xFF; func_80099DF8(&sp20, &D_800A54FC, var_s0 + 1, (s32) (D_800C35A0 + (((*((u8 *) (((char *) (D_800C35A0 + (func_80060820(var_s0) & 0xFF))) + 0x32))) * 0x28) + 0x44))); func_800596F4(temp_s2, *((s16 *) (((char *) temp_s2) + 0x6)), (s16) ((*((s16 *) (((char *) temp_s2) + 0x8))) + (var_s0 * 0x16)), &sp20); var_s3 += 1;  } while (((u32) (var_s3 & 0xFF)) < 4U); temp_s2 = func_800592D0(0x12); temp_s4_2 = func_800592D0(0x11);

  loop4 = 0;

 do { var_s0_2 = 0;

 temp_s1 = 0;

 if ((*((u16 *) (((char *) D_800C35A0) + 0x22))) != 0) { do { temp_v0_2 = D_800B6718[(var_s0_2 & 0xFF)][(func_80060820(loop4 & 0xFF)&0xff)];

 var_s0_2 += 1;

 temp_s1 += temp_v0_2;

 } while (((u32) (var_s0_2 & 0xFF)) < ((u16) (*((u16 *) (((char *) D_800C35A0) + 0x22)))));

 } func_80097E30(&sp20, 0, 0x10);

 func_80052E94(temp_s1, &sp20);

 temp_s0 = loop4 & 0xFF;

 func_800596F4(temp_s2, *((s16 *) (((char *) temp_s2) + 0x6)), (s16) ((*((s16 *) (((char *) temp_s2) + 0x8))) + (temp_s0 * 0x16)), &sp20);

 if (temp_s0 == 0) { var_s7 = temp_s1;

 } else { func_80097E30(&sp20, 0, 0x10);

 __builtin_memcpy(&sp20, &D_800A5504, 3);

 func_80052E94(temp_s1 - var_s7, (s16 *) (&sp22));

 func_800980D0(&sp20, &D_800A5508);

 func_800596F4(temp_s4_2, *((s16 *) (((char *) temp_s4_2) + 0x6)), (s16) ((*((s16 *) (((char *) temp_s4_2) + 0x8))) + ((temp_s0 - 1) * 0x16)), &sp20);

 } loop4 += 1;

 } while (((u32) (loop4 & 0xFF)) < 4U);

 } else { func_8005A6E0(0x18); func_8005A6E0(0x14); func_8005A6E0(0x19); func_8005A6E0(0x1A); } func_80097E30(buf38, 0, 0xA); temp_s2 = func_800592D0(3); if ((*((u16 *) (((char *) D_800C35A0) + 0x50))) == 0) { var_a2_3 = ((u32) ((var_s6 * D_8009D540) * 0xE10)) / ((u32) (D_800A14DC * 0x3E8)); func_80099DF8(buf38, &D_800A5524, var_a2_3 & 0xFFFF); } else { var_a2_3 = ((u32) ((var_s6 * D_8009D540) * 0xE10)) / ((u32) (D_800A14DC * 0x3E8)); func_80099DF8(buf38, &D_800A552C, var_a2_3 & 0xFFFF); } func_80059618(temp_s2, *((u8 *) (((char *) temp_s2) + 0xB)), *((u8 *) (((char *) temp_s2) + 0xC)), *((u8 *) (((char *) temp_s2) + 0xD)), (s32) (*((u8 *) (((char *) temp_s2) + 0xE)))); func_800596F4(temp_s2, *((s16 *) (((char *) temp_s2) + 0x6)), *((s16 *) (((char *) temp_s2) + 0x8)), buf38); temp_s2 = func_800592D0(0x15); func_80059618(temp_s2, *((u8 *) (((char *) temp_s2) + 0xB)), *((u8 *) (((char *) temp_s2) + 0xC)), *((u8 *) (((char *) temp_s2) + 0xD)), (s32) (*((u8 *) (((char *) temp_s2) + 0xE)))); 
    func_800596F4(temp_s2, *((s16 *) (((char *) temp_s2) + 0x6)), *((s16 *) (((char *) temp_s2) + 0x8)), func_80057918(D_800C8328, (*((u16 *) (((char *) D_800C35A0) + 0x22))) + 0x21A));
    temp_s2 = func_800592D0(0x16);
    func_80059618(temp_s2, *((u8 *) (((char *) temp_s2) + 0xB)), *((u8 *) (((char *) temp_s2) + 0xC)), *((u8 *) (((char *) temp_s2) + 0xD)), (s32) (*((u8 *) (((char *) temp_s2) + 0xE))));
    func_80099DF8(&sp20, &D_800A5418, func_80057918(D_800C8328, (u8)D_800D0634[((Manager*)D_800C35A0)->track][((Manager*)D_800C35A0)->course].times[((Manager*)D_800C35A0)->slot][0].name[5] + 0x1E4));
    func_800596F4(temp_s2, *((s16 *) (((char *) temp_s2) + 0x6)), *((s16 *) (((char *) temp_s2) + 0x8)), &sp20);
  }
  if ((*((u8 *) (((char *) D_800A1468) + 0x249))) == 1)
  {
    D_800A0370 = D_800A155C;
    D_800A0372 = D_800A155E;
    D_800A0374 = D_800A1560;
    D_800A0376 = D_800A1562;
  }
  D_800C7F84 = func_8004240C(3);
  func_80005500(((Actor*)D_800C7F84)->model, &D_800A155C);
  *((Vec3Word *) (D_800C7F84 + 0x118)) = *((Vec3Word *) (&D_800A156C));
  *((Vec3Word *) (D_800C7F84 + 0x124)) = *((Vec3Word *) (&D_800A1578));
  *((s32 *) (((char *) D_800C7F84) + 0x130)) = 0;
  *((f32 *) (((char *) D_800C7F84) + 0x134)) = 100.0f;
  *((s32 *) (((char *) D_800C7F84) + 0x138)) = 0;
  *((f32 *) (((char *) D_800C7F84) + 0x10C)) = 0.4f;
  *((f32 *) (((char *) D_800C7F84) + 0x110)) = 0.4f;
  *((f32 *) (((char *) D_800C7F84) + 0x114)) = 1.0f;
  func_80010A6C(D_800C7F84, &D_800A155C);
  temp_v0_6 = func_800056FC(((Actor*)D_800C7F84)->model);
  temp_s0_4 = func_80006008(temp_v0_6);
  temp_s2_7 = D_800C8380;
  temp_s5 = D_800C7F84;
  guMtxIdent(temp_s2_7);
{ void *p=temp_s0_4; temp_s0_4+=8; *(s32*)p=0xDB0E0000; *(s32*)((char*)p+4)=(u32)(*((u16 *) ((char*)temp_s5+0x104))); }
{ void *p=temp_s0_4; temp_s0_4+=8; *(s32*)p=0xDA380003; *(s32*)((char*)p+4)=(u32)temp_s2_7; }
{ void *p=temp_s0_4; temp_s0_4+=8; *(s32*)p=0xE7000000; *(s32*)((char*)p+4)=0; }
{ void *p=temp_s0_4; temp_s0_4+=8; *(s32*)p=0xD9FFF9FF; *(s32*)((char*)p+4)=0; }
func_80006014(temp_v0_6,temp_s0_4);
  temp_s5_2 = temp_s5 + 0x38;
  func_8000EF0C(((Actor*)D_800C7F84)->model, &D_800A1564, &D_800A161C);
  var_s6 = func_8001BD1C();
  basevec=&D_800A1584;
  ((f32*)basevec)[2] += 1.0f;
  zeroat=&D_800A159C[13];
  temp_s0_8=zeroat-13;
  basevec[0] = 0;
  basevec[1] = 0;
  *zeroat=0;

  func_8001C1A8(basevec, temp_s0_8);
  func_80010BFC(var_s6, temp_s5_2, temp_s0_8);
  func_800061FC(temp_v0_6, var_s6);
 {
  void *command_ptr;
  command_ptr = ((Packet*)temp_v0_6)->cursor;

  ((Packet*)temp_v0_6)->cursor = (void *) (command_ptr + 8);
  ((Command*)command_ptr)->w0 = 0xFB000000;
  ((Command*)command_ptr)->w1 = -1;

 }
  func_8004D1A8(((Actor*)D_800C7F84)->model, 2, 1.6f, 0, 0xFF);
  actor=D_800C7F84;
  temp_v1_3 = ((Packet*)temp_v0_6)->cursor;

  ((Packet*)temp_v0_6)->cursor = (void *) (temp_v1_3 + 8);
  ((Command*)temp_v1_3)->w0 = 0xFB000000;
  ((Command*)temp_v1_3)->w1 = 0xFF;
  func_8004D1A8(((Actor*)actor)->model, 0, 1.4f, 0, 0xFF);
  var_s6 = func_8001BD1C();
  func_8001C1A8(basevec, &D_800A15DC);
  func_80010BFC(var_s6, temp_s5_2, &D_800A15DC);
  func_800061FC(temp_v0_6, var_s6);
  temp_v1_4 = ((Packet*)temp_v0_6)->cursor;

  ((Packet*)temp_v0_6)->cursor = (void *) (temp_v1_4 + 8);
  ((Command*)temp_v1_4)->w0 = 0xFB000000;
  ((Command*)temp_v1_4)->w1 = 0xC4C4C4FF;
  func_8004D1A8(((Actor*)D_800C7F84)->model, 0, 1.4f, 0, 0xFF);
  if ((*((u8 *) (((char *) D_800A1468) + 0x249))) != 0)
  {
    func_8005D4A4(0);
    func_8004CF7C(D_800D05D8, 1, 0x1E, 0x28, 3.0f, 0, 0x80);
  }
}

