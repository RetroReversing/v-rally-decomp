#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { char name[4]; u32 first, second, third; u8 flag, pad17, icon, pad19[5]; } ScoreRow;
extern ScoreRow D_800C7F90[5];
extern s32 D_800C8328;
void *func_80006008();
void func_80006014();
void func_80006298();
void func_800068C0();
int func_80006CF8();
void func_800072F4();
void func_8000C22C(void *, s32, s32, s32, u8);
void func_8000C244(s32,s32,s32,s16,void*,s32);
s32 func_8000C9B0(void *, void *, u8, f32, u8);
u16 func_8000CC04(void *, void *, s16, s16, void *, u8, f32, f32, u16, u8);
void func_80052E94();
char *func_80057918();
void func_80073108(s32,s16,s16,s32,u8);
void func_8007347C();
int func_80099DF8(void *, void *, ...);
extern char D_800A1798[];
extern u8 D_800A17E9;
extern u8 D_800A17EA;
extern char D_800A5EB8[];
extern char D_800A5ED8[];
extern char D_800A5EE0[];
extern char D_800A5EEC[];
extern char D_800A5EF4[];
extern char D_800A5EFC[];
extern char D_800A5F04[];
extern char D_800A5F0C[];
extern char D_800A5F14[];
extern char D_800A5F18[];
extern char D_800A5F2C[];
extern char D_800A5F44[];
extern char D_800A5F54[];
extern char D_800C02AE[];
void func_8007950C(s32 arg0)
{
  char sp40[0x78];
  char spB8[0x18];
  char spD0[0x18];
  char spE8[0x18];
  struct { char text[0x18];    } tail;
  s32 *var_a1_3;
  s32 *var_a1_4;
  s32 *var_a2_2;
  s32 *var_a3_2 ; int new_var6 ;
  u16 left_local;
  s32  * new_var4 ; s32 var_a1_2 ; int new_var3 ; s32 special_x;
  s32 var_a2;
  s32 right_local ; int new_var5 ;
  s32 var_a3;
  s32 temp_s0_4;
  s32 temp_s0_5;
  s32 temp_s1;
  s32 temp_s2_2;
  s32 temp_s2_3;
  s32 temp_s4;
  s32 var_s7;
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_s0;
  u32 *new_var;
  s32 temp_s0_2;
  int new_var2;
  s32 temp_s1_2;
  s32 temp_s1_3;
  s32 temp_s2;
  u16 temp_s3;
  s32 temp_v1_2;
  s16 var_fp;
  s32 var_s4;
  u32 temp_s0_3;
  u32 temp_v0_2;
  void *temp_s1_4;
  void *temp_v0;
  u32 identity_zero;
  temp_v0 = func_80006008(arg0);
  *((u32 *) temp_v0) = 0xDE000000;
  *((void **) (((char *) temp_v0) + 4)) = &D_800A1798;
  func_80006014(arg0, temp_v0 + 8);
  temp_s0 = func_80006CF8(arg0, 0) & 0xFFFF;
  func_800068C0(arg0, temp_s0, 0, 0, 0, 0x140, 0, 0, 0x140, 0xF0, 0, 0, 0xF0, 0);
  func_800072F4(arg0, temp_s0, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0xAA);
  func_80006298(arg0);
  {
  char *nm;
  if ((*((u8 *) (D_800C02AE + 0x7F4F))) == 2)
    nm = func_80057918(D_800C8328, 0x1CD);
  else if ((*((u8 *) (D_800C02AE + 0x7F4F))) == 3)
    nm = func_80057918(D_800C8328, 0x1CE);
  else if ((*((u8 *) (D_800C02AE + 0x7F4F))) == 4)
    nm = func_80057918(D_800C8328, 0x1CF);
  else
    nm = func_80057918(D_800C8328, 0x1D0);
  var_s7 = 0x5A;
  func_80099DF8(&tail.text, &D_800A5F14, nm);
  }
  func_8000C22C((void *)(*((s32 *) (D_800C02AE + 0x7F5E))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
  func_80099DF8(&sp40, &D_800A5EB8);
  temp_s0_2 = (D_800A17EA + D_800A17E9) + func_8000C9B0((void *)(D_800C02AE + 0x7F5E), (void *)(&sp40), (u8)(1), (f32)(1.0f), (u8)(1));
  temp_v0_2 = ((u32)(temp_s0_2 & 0xFFFF)) >> 1;
  temp_s2 = temp_v0_2 + 0xA0;
  temp_s1 = 0xA0 - temp_v0_2;
  func_8000C22C((void *)(*((s32 *) (D_800C02AE + 0x7F5E))), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
  func_8007347C(arg0, (temp_s1 - 7) & 0xFFFF, 0x46, (temp_s0_2 + 0xD) & 0xFFFF, 0x11);
  var_fp = 0;
  left_local = temp_s1;
  func_8000C244(*((s32 *) (D_800C02AE + 0x7F5E)), arg0, (s16)temp_s1, 0x48, func_80057918(D_800C8328, 0xCF), 1);
   new_var6 = 0x12 ; func_8000C22C((void *)(*((s32 *) (D_800C02AE + 0x7F5E))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
  right_local = (u32)(-temp_s2) << 16;
  do
  {
    var_s4 = (u16) left_local ; new_var3 = 1 ;

    if ((var_fp & 0xFFFF) == 4)
    {
      
        
      func_80099DF8(&sp40, &D_800A5F44, &tail.text, func_80057918(D_800C8328, 0xD2)) ; var_s4 = 0x25; temp_s2_2 = var_s7 ; temp_s2_2 += 0x19 ; var_s7 = temp_s2_2 +  new_var6  ;
      temp_s1_2 = func_8000C9B0((void *)(D_800C02AE + 0x7F5E), (void *)(&sp40), (u8)(1), (f32)(1.0f), (u8)(1));
      temp_s3 = temp_s1_2;
      func_8000C22C((void *)(*((s32 *) (D_800C02AE + 0x7F5E))), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
      temp_s0_3 = ((u32) (temp_s3 & 0xFFFF)) >> 1;
       new_var5 = 0xFFFF ; new_var2 = 0x7F5E;
      func_8007347C(arg0, (0x97 - temp_s0_3) &  new_var5 , (temp_s2_2 + (-2)) &  new_var5 , (temp_s1_2 + 0xF) &  new_var5 , 0x11);
       new_var4 = (s32 *) (D_800C02AE + new_var2) ; func_8000C244 ( * new_var4 , arg0, 0xA0 - temp_s0_3, temp_s2_2, sp40, 1);
      func_8000C22C((void *)(*((s32 *) (D_800C02AE + 0x7F5E))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));

      goto row_color_done;
    }
    new_var = &D_800C7F90[(var_fp & 0xFFFF)].first;

    if ((*new_var) == D_800C7F90[4].first)
    {
      func_8000C22C((void *)(*((s32 *) (D_800C02AE + 0x7F5E))), (s32)(0xDC), (s32)(0xDC), (s32)(0x10), (u8)(0xFF));

    }
row_color_done:
    temp_a0 = D_800C7F90[(var_fp & 0xFFFF)].first;
    if (temp_a0 != 0)
    {
      func_80052E94(temp_a0, &spB8);

    }
    else
    {
      func_80099DF8(&spB8, &D_800A5EE0);

    }
    temp_a0_2 = D_800C7F90[(var_fp & 0xFFFF)].second;
    if (D_800C7F90[( 0xFFFF & var_fp   )].second != 0)
    {
      func_80052E94(temp_a0_2, &spD0);

    }
    else
    {
      func_80099DF8(&spD0, &D_800A5EE0);

    }
    temp_v1_2 = D_800C7F90[(var_fp & 0xFFFF)].third;
    if (temp_v1_2 != 0)
    {
      if ((*((u16 *) (D_800C02AE + 0x7FB6))) != 0)
      {
        func_80099DF8(&spE8, &D_800A5EEC, (s32 *) (((u32) (temp_v1_2 * 0x9F00)) >> 0x10));

      }
      else
      {
        func_80099DF8(&spE8, &D_800A5EF4, (s32 *) (temp_v1_2 & 0xFFFF));

      }
    }
    else
    {
      if ((*((u16 *) (D_800C02AE + 0x7FB6))) != 0)
      {
        var_a1_3 = &D_800A5EFC;
        func_80099DF8(&spE8, var_a1_3); }
      else
      {
        var_a1_3 = &D_800A5F04;
        func_80099DF8(&spE8, var_a1_3);
      }

    }
    if ((var_fp & 0xFFFF) != 4)
    {
      func_80099DF8(&sp40, &D_800A5F0C, (var_fp & 0xFFFF) + 1, D_800C7F90[(var_fp & 0xFFFF)].name);

    }
    else
    {
      func_80099DF8(&sp40, &D_800A5F14, D_800C7F90[4].name);

    }
    if ((var_fp & 0xFFFF) != 4)
    {
       do { func_8000C244(*((s32 *) (D_800C02AE + 0x7F5E)), arg0, (s16) var_s4, var_s7, sp40, 1 ) ; } while ( 0 );
    }
    temp_s0_4 = var_s4 + D_800A17E9;
    temp_s4 = var_s7 -  new_var3 ;
    if ((((u32) (temp_s0_4 & 0xFFFF)) < 0x141U) & ((var_fp & 0xFFFF) != 4))
    {
      func_80073108(arg0, temp_s0_4, temp_s4, *((s32 *) (D_800C02AE - (-0x103B2))), (s32) D_800C7F90[(var_fp & 0xFFFF)].icon);
    }
    temp_s2_3 = temp_s4; ++temp_s2_3;
    temp_s0_5 = temp_s0_4 + D_800A17EA; temp_s0_5 ^= arg0; temp_s0_5 ^= arg0; 
    var_s7 = temp_s2_3 ^ arg0; var_s7 ^= arg0;
    arg0 ^= temp_s4; arg0 ^= temp_s4;

    if ((var_fp & 0xFFFF) == 0) goto zero_row;
    if ((var_fp & 0xFFFF) != 4) goto normal_row;
    {
        temp_s3 = ((D_800A17E9 + 0xFFF1) + D_800A17EA) + func_8000C9B0((void *)(D_800C02AE + 0x7F5E), (void *)(&D_800A5F18), (u8)(1), (f32)(1.0f), (u8)(1));
        temp_s1_3 = (s32)(0x140 - (temp_s3 & 0xFFFF)) / 2;
        temp_s3 = temp_s1_3;
        temp_s3 = temp_s3 & 0xFFFF;
        func_8000C244(*((s32 *) (D_800C02AE + 0x7F5E)), arg0, temp_s3, temp_s2_3, sp40, 1);



        if (((u32) (temp_s0_5 & 0xFFFF)) < 0x141U)
        {
          func_80073108(arg0, (s16) (temp_s1_3 + (D_800A17E9 + 0xFFF1)), temp_s4, *((s32 *) (D_800C02AE + 0x103B2)), (s32) D_800C7F90[4].icon);
        }
        var_s7 = temp_s2_3 ^ arg0; var_s7 ^= arg0;
        func_80099DF8(sp40, &D_800A5ED8, &spB8, &spE8);
        
        func_8000C244(*((s32 *) (D_800C02AE + 0x7F5E)), arg0, temp_s3 + (D_800A17E9 - 0xF) + D_800A17EA, temp_s2_3, sp40, 1);
        identity_zero = (u32)temp_s0_5 ^ (u32)arg0; identity_zero ^= (u32)arg0; identity_zero ^= (u32)temp_s0_5;
        arg0 = (u32)arg0 + (u32)(s16)temp_s2_3 * identity_zero;
        do { var_s7 += 0xF; } while (0);
      goto row_done;
    }
zero_row:
  {
    s16 local_y;
      ;
    func_8000C244(*((s32 *) (D_800C02AE + 0x7F5E)), arg0, (s16)temp_s0_5,  ( s16 ) temp_s2_3 , spB8, 1);
    func_8000CC04((void *)(D_800C02AE + 0x7F5E), (void *)(arg0), (s16)(right_local >> 0x10),  (s16)(( s16 ) temp_s2_3) , (void *)(&spE8), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1)); 
    goto normal_row_done;
  }
normal_row:
  {
    s16 local_y;
    func_80099DF8(&sp40, &D_800A5F2C, &spB8, &spD0);
    local_y = (s16)temp_s2_3;
    func_8000C244(*((s32 *) (D_800C02AE + 0x7F5E)), arg0, (s16)temp_s0_5, local_y, sp40, 1);
    func_8000CC04((void *)(D_800C02AE + 0x7F5E), (void *)(arg0), (s16)(right_local >> 0x10), (s16)(local_y), (void *)(&spE8), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1)); 
    goto normal_row_done;
  }
normal_row_done:
    var_s7 ^= temp_s2_3; var_s7 ^= temp_s2_3;
    var_s7 += 0xF;
row_done:
    func_8000C22C((void *)(*((s32 *) (D_800C02AE + 0x7F5E))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    var_fp += 1;
  }
  while ((u16)var_fp < 5U);
  temp_s1_4 = D_800C02AE + 0x7F62;
  func_8000C22C((void *)(*((s32 *) (D_800C02AE + 0x7F62))), (s32)(0xDC), (s32)(0xDC), (s32)(0x10), (u8)(0xFF));
  if (D_800C7F90[0].flag < 4U)
  {
    func_80099DF8(&sp40, &D_800A5ED8, func_80057918(D_800C8328, 0xD8), D_800C7F90[0].name);
    func_8000C244(*((s32 *) (D_800C02AE + 0x7F62)), arg0, 0xA0 - (((u32) (func_8000C9B0((void *)(temp_s1_4), (void *)(&sp40), (u8)(1), (f32)(1.0f), (u8)(0)) & 0xFFFF)) >> 1), 0x14, &sp40, 0);
  }
  
  var_s7 = 0x28;
  if ((*((s32 *) (D_800C02AE + 0x32AA))) == 2)
  {
    if ((*((u8 *) (D_800C02AE + 0x7F4F))) == 8)
      { func_80099DF8(&sp40, &D_800A5ED8, func_80057918(D_800C8328, 0xD9), &tail.text); temp_s3 = func_8000C9B0((void *)(temp_s1_4), (void *)(&sp40), (u8)(1), (f32)(1.0f), (u8)(0)); }
    else
      { func_80099DF8(&sp40, &D_800A5F54, func_80057918(D_800C8328, 0xD9), &tail.text); temp_s3 = func_8000C9B0((void *)(temp_s1_4), (void *)(&sp40), (u8)(1), (f32)(1.0f), (u8)(0)); }
  }
  else
      { func_80099DF8(&sp40, &D_800A5F44, &tail.text, func_80057918(D_800C8328, 0xD9)); temp_s3 = func_8000C9B0((void *)(temp_s1_4), (void *)(&sp40), (u8)(1), (f32)(1.0f), (u8)(0)); }
  func_8000C244(*((s32 *) (D_800C02AE + 0x7F62)), arg0, (temp_s2_3 = 0xA0 - (((u32) (temp_s3 & 0xFFFF)) >> 1)), var_s7, &sp40, 0);
  func_8000C22C((void *)(*((s32 *) (D_800C02AE + 0x7F62))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
}
