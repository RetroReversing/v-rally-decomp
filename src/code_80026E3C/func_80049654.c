#include "snapshot31_verified.h"

#define W(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(u16*)((p)+(o)))
#define B(p,o) (*(u8*)((p)+(o)))
#define F(p,o) (*(float*)((p)+(o)))
typedef struct
{
  char a[28];
} Blob;
extern Blob D_800A4E90;
extern char D_800A4EAC;
extern char D_800A4EB4;
extern char *D_800A0384;
extern char *D_800C35A0;
extern s8 D_800A0389;
extern int D_800A14BC[];
extern int D_800A14C0;
extern int D_800C3558;
extern int D_800C8328;
char *func_8007EAA0(int, int);
int func_80057810(int);
int func_80057918(int, int);
int func_80081664(int, void *);
int func_8000BF2C(int);
void func_8000C200(int, float, float, float);
void func_80049654(void)
{
  int var_a1_2;
  s32 temp_v0_2;
  s32 temp_v0_3;
  s32 temp_v0_4;
  s32 var_a0;
  s32 var_a1;
  s32 var_s0;
  s32 var_s1;
  s32 row;
  u8 var_v1;
  char *temp_v0;
  s32 text;
  Blob local = D_800A4E90;
  D_800A0384 = func_8007EAA0(1, 0x3A8);
  B(D_800A0384, 0x383) = 0;
  B(D_800A0384, 0x8) = 0;
  B(D_800A0384, 0x384) = 0;
  {
    char *dest = D_800A0384;
    var_v1 = 0;
    if (U(D_800C35A0, 0xE) == 2)
    {
      var_v1 = U(D_800C35A0, 0x1A) == 0;
    }
    B(dest, 0x3A2) = var_v1;
  }
  {
    u16 mode = U(D_800C35A0, 0xE);
    D_800A0389 = 5;
    if ((mode == 2) && (U(D_800C35A0, 0x12) & 1))
    {
      F(D_800A0384, 0x3A4) = 0.9f;
    }
    else
    {
      F(D_800A0384, 0x3A4) = 1.0f;
    }
  }
  var_s1 = 0;
  var_s0 = 0;
  *((Blob *) (D_800A0384 + 0x386)) = local;
  do
  {
    var_s0 = 0;
    row = ((u8) var_s1) * 222 + 10;
    do
    {
      func_80097E30((D_800A0384 + row) + (((u8) var_s0) * 42), 0, 42);
      var_s0++;
    }
    while (((u8) var_s0) < 5);
    var_s0 = 0;
    var_s1++;
  }
  while (((u8) var_s1) < 4);
  if (D_800C3558 != 0)
  {
    var_a0 = D_800A14BC[D_800C3558];

  D_800C8328 = func_80057810(var_a0);}
  else
  {
    var_a0 = D_800A14C0;

  D_800C8328 = func_80057810(var_a0);}
  if (U(D_800C35A0, 0x1E) == 0)
  {
    B(D_800A0384, 0xE6) = (s8) (5 - B(D_800A0384, 0x3A2));
    var_a1 = func_80057918(D_800C8328, 0x1AF);
    func_80098290(D_800A0384 + 0xA, var_a1);
    if (B(D_800A0384, 0x3A2) == 0)
    {
      var_a1 = func_80057918(D_800C8328, 0x1B1);
      func_80098290(D_800A0384 + 0x34, var_a1);
    }
    var_a1 = func_80057918(D_800C8328, 0x1B2);
    func_80098290(D_800A0384 + (((2 - B(D_800A0384, 0x3A2)) * 0x2A) + 0xA), var_a1);
    var_a1 = func_80057918(D_800C8328, 0x1B5);
    func_80098290(D_800A0384 + (((3 - B(D_800A0384, 0x3A2)) * 0x2A) + 0xA), var_a1);
    text = func_80057918(D_800C8328, 6);
    temp_v0 = D_800A0384;
    func_80098290(temp_v0 + (((4 - B(temp_v0, 0x3A2)) * 0x2A) + 0xA), text);
  }
  else
  {
    B(D_800A0384, 0xE6) = 3;
    var_a1 = func_80057918(D_800C8328, 0x1AF);
    func_80098290(D_800A0384 + 0xA, var_a1);
    if (U(D_800C35A0, 0x1E) != 5)
    {
      var_a1_2 = 0x1B3;
    }
    else
    {
      var_a1_2 = 0x1B0;
    }
    if (U(D_800C35A0, 0x1E) == 5)
    {
      var_a1 = func_80057918(D_800C8328, 0x1B0);
    }
    else
    {
      var_a1 = func_80057918(D_800C8328, 0x1B3);
    }
    func_80098290(D_800A0384 + 0x34, var_a1);
    text = func_80057918(D_800C8328, 0x1B5);
    func_80098290(D_800A0384 + 0x5E, text);
  }
  B(D_800A0384, 0x380) = 2;
  var_a1 = func_80057918(D_800C8328, 0x145);
  func_80098290(D_800A0384 + 0x2A4, var_a1);
  var_a1 = func_80057918(D_800C8328, 0x143);
  func_80098290(D_800A0384 + 0x2CE, var_a1);
  B(D_800A0384, 0x1C4) = 4;
  var_a1 = func_80057918(D_800C8328, 0x19F);
  func_80098290(D_800A0384 + 0xE8, var_a1);
  var_a1 = func_80057918(D_800C8328, 0x1A0);
  func_80098290(D_800A0384 + 0x112, var_a1);
  var_a1 = func_80057918(D_800C8328, 0x1A1);
  func_80098290(D_800A0384 + 0x13C, var_a1);
  var_a1 = func_80057918(D_800C8328, 0x1B4);
  func_80098290(D_800A0384 + 0x166, var_a1);
  B(D_800A0384, 0x2A2) = 5;
  var_a1 = func_80057918(D_800C8328, 0x40);
  func_80098290(D_800A0384 + 0x1C6, var_a1);
  var_a1 = func_80057918(D_800C8328, 0x42);
  func_80098290(D_800A0384 + 0x1F0, var_a1);
  var_a1 = func_80057918(D_800C8328, 0x47);
  func_80098290(D_800A0384 + 0x21A, var_a1);
  var_a1 = func_80057918(D_800C8328, 0x4B);
  func_80098290(D_800A0384 + 0x244, var_a1);
  var_a1 = func_80057918(D_800C8328, 0x4F);
  func_80098290(D_800A0384 + 0x26E, var_a1);
  B(D_800A0384, 0x382) = 0;
  func_80081540(&D_800A4EAC);
  temp_v0_3 = func_80081664(6, &D_800A4EB4);
  W(D_800A0384, 0x0) = temp_v0_3;
  temp_v0_4 = func_8000BF2C(temp_v0_3);
  W(D_800A0384, 0x4) = temp_v0_4;
  func_8000C1EC(temp_v0_4, 0x80, 0x33);
  func_8000C200(W(D_800A0384, 0x4), F(D_800A0384, 0x3A4), 1.0f, 1.0f);
  B(D_800A0384, 0x383) = 0;
  func_80049F18();
  func_8004C794();
  func_80049534();
}
