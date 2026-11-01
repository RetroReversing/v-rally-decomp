#define V(p,o) (*(s32*)((char*)(p)+(o)))
#define W(p,o) (*(s32*)((char*)(p)+(o)))
#define F(p,o) (*(f32*)((char*)(p)+(o)))
#define H(p,o) (*(s16*)((char*)(p)+(o)))
#define U(p,o) (*(u16*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
typedef struct 
{
  s32 a;
  s32 b;
  s32 c;
} Triple;
extern Triple D_800A1694;
extern Triple D_800A16A0;
extern Triple D_800A16B4;
extern Triple D_800A16C0;
extern f32 D_800A16B8;
extern f32 D_800A16BC;
extern f32 D_800A16C4;
extern f32 D_800A16C8;
extern u16 D_800A16AC;
extern u16 D_800A16AE;
extern s16 D_800A16B2;
extern u8 D_800A16D5;
extern char *D_8009B5A8;
extern char *D_800AFA64;
extern char *D_800C7F84;
extern int D_800B706C;
extern int D_8009D4EC;
extern int D_8009D4E8;
extern int *D_800C8374;
extern char D_800C8380[];
extern char D_800ADFB0[];
char *func_8004240C(int);
char *func_80006008(int);
int func_800056FC(int);
int func_8001BD1C(void);
int func_80005C48(void *);
int osVirtualToPhysical(int);
void func_8006A438(void)
{
  char *cursor;
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_a2;
  s32 temp_a3;
  s32 temp_lo;
  s32 temp_s7;
  s32 temp_v0_5;
  s32 temp_v1;
  char *temp_s0;
  char *temp_s1;
  char *temp_s6;
  char *temp_s6_10;
  char *temp_s6_11;
  char *temp_s6_12;
  char *temp_s6_13;
  char *new_var;
  char *temp_s6_14;
  char *temp_s6_15;
  char *temp_s6_2;
  char *temp_s6_3;
  char *temp_s6_4;
  char *temp_s6_5;
  char *temp_s6_6;
  char *temp_s6_7;
  char *temp_s6_8;
  char *temp_s6_9;
  char *temp_v0;
  char *temp_v0_2;
  int new_var2;
  char *temp_v0_3;
  char *temp_v0_4;
  char *temp_v0_6;
  char *temp_v0_7;
  if (D_800A16D5 == 0)
  {
    return;
  }
  {
    char *a1;
    s32 a2;
    s32 v0;
    s32 a3;
    s32 t4;
    u16 *pAC = &D_800A16AC;
#define D_800A16AC (*pAC)
    a1 = D_800AFA64;
    a2 = U(a1, 0x88);
    a2 = (a2 << 1) / 3;
    v0 = a2 * U(a1, 0x8A);
    a3 = W(a1, 0x4C);
    temp_a0 = (v0 + a3) * 6;
    F(&D_800A16B4, 0x0) = (f32) (H(P(a1, 0x54) + temp_a0, 0) + W(a1, 0x24));
    D_800A16B8 = (f32) ((H(P(a1, 0x54) + temp_a0, 0x2) + W(a1, 0x28)) - 0x12C);
    D_800A16BC = (f32) (H(P(a1, 0x54) + temp_a0, 0x4) + W(a1, 0x2C));
    temp_a0 = ((a2 + 1) * U(a1, 0x8A) + a3) * 6;
    F(&D_800A16C0, 0x0) = (f32) (H(P(a1, 0x54) + temp_a0, 0) + W(a1, 0x24));
    D_800A16C4 = (f32) ((H(P(a1, 0x54) + temp_a0, 0x2) + W(a1, 0x28)) - 0x12C);
    D_800A16C8 = (f32) (H(P(a1, 0x54) + temp_a0, 0x4) + W(a1, 0x2C));
    temp_v0 = func_8004240C(3);
    temp_a3 = W(temp_v0, 0x178);
    D_800C7F84 = temp_v0;
    temp_s7 = func_800056FC(temp_a3);
    temp_v0_2 = func_8004240C(3);
    D_800C7F84 = temp_v0_2;
    *((Triple *) (temp_v0_2 + 0x118)) = D_800A1694;
    *((Triple *) (D_800C7F84 + 0x124)) = D_800A16A0;
    W(D_800C7F84, 0x130) = 0;
    F(D_800C7F84, 0x134) = 100.0f;
    W(D_800C7F84, 0x138) = 0;
    F(D_800C7F84, 0x114) = 1.0f;
    func_80005500(W(D_800C7F84, 0x178), &D_800A16AC, &D_800A16A0);
    temp_v0_3 = func_8004240C(1);
    D_800C7F84 = temp_v0_3;
    *((Triple *) (temp_v0_3 + 0x118)) = D_800A16B4;
    *((Triple *) (D_800C7F84 + 0x124)) = D_800A16C0;
    W(D_800C7F84, 0x130) = 0;
    F(D_800C7F84, 0x134) = 100.0f;
    W(D_800C7F84, 0x138) = 0;
    F(D_800C7F84, 0x10C) = 0.4f;
    F(D_800C7F84, 0x110) = 0.4f;
    F(D_800C7F84, 0x114) = 1.0f;
    cursor = func_80006008(temp_s7);
    {
      char *tex = D_8009B5A8;
#define D_8009B5A8 tex
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = 0xE7000000;
      V(cmd, 4) = 0;
    }
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = 0xE3000A01;
      V(cmd, 4) = 0x300000;
    }
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = 0xFE000000;
      V(cmd, 4) = D_800B706C - 0x80000000;
    }
    new_var2 = D_800B706C - 0x80000000;

    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = ((H(D_8009B5A8, 4) - 1) & 0xFFF) | 0xFF100000;
      V(cmd, 4) = new_var2;
    }
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = 0xF7000000;
      V(cmd, 4) = 0xFFFCFFFC;
    }
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = ((((H(D_8009B5A8, 4) - 1) & 0x3FF) << 14) | (((D_800A16B2 - 1) & 0x3FF) << 2)) | 0xF6000000;
      V(cmd, 4) = ((D_800A16AC & 0x3FF) << 14) | ((D_800A16AE & 0x3FF) << 2);
    }
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = 0xE7000000;
      V(cmd, 4) = 0;
 do { } while (0);
    }
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = ((H(D_8009B5A8, 4) - 1) & 0xFFF) | 0xFF100000;
      V(cmd, 4) = osVirtualToPhysical(func_80005C48(D_8009B5A8));
    }
    }
#undef D_8009B5A8
    {
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = 0xE3000A01;
      V(cmd, 4) = 0;
    }
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = 0xF7000000;
      V(cmd, 4) = 0x10001;
    }
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = ((((H(D_8009B5A8, 4) - 1) & 0x3FF) << 14) | (((D_800A16B2 - 1) & 0x3FF) << 2)) | 0xF6000000;
      V(cmd, 4) = ((D_800A16AC & 0x3FF) << 14) | ((D_800A16AE & 0x3FF) << 2);
    }
    }
#undef D_8009B5A8
#undef D_800A16AC
    func_80006014(temp_s7);
    temp_s0 = func_8004240C(3);
    func_80010A6C(func_8004240C(3), &D_800A16AC);
    temp_v0_5 = func_800056FC(W(temp_s0, 0x178));
    cursor = func_80006008(temp_v0_5);
    guMtxF2L(new_var = temp_s0 + 0x38, func_8001BD1C());
    ;
    guMtxIdent(D_800C8380);
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = 0xDB0E0000;
      V(cmd, 4) = U(temp_s0, 0x104);
    }
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = 0xDA380003;
      V(cmd, 4) = (s32) D_800C8380;
    }
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = 0xDC08000A;
      V(cmd, 4) = (s32) (temp_s0 + 0x158);
    }
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = 0xDC08030A;
      V(cmd, 4) = (s32) (temp_s0 + 0x168);
    }
    {
      char *cmd = cursor;
      cursor += 8;
      V(cmd, 0) = 0xE7000000;
      V(cmd, 4) = 0;
    }
    func_80006014(temp_v0_5, cursor);
    temp_v0_6 = func_8004240C(3);
    temp_a3 = W(temp_v0_6, 0x178);
    D_800C7F84 = temp_v0_6;
    temp_s7 = func_800056FC(temp_a3);
    temp_v0_7 = func_8004240C(1);
    D_800C7F84 = temp_v0_7;
    D_800C7F84 = func_8004240C(3);
    func_80015F3C(temp_s7);
    func_80015D68(D_800ADFB0, *D_800C8374, temp_s7, temp_s7, temp_v0_7 + 0x38);
    if (D_8009D4EC != 0)
    {
      func_80081B28(D_8009D4EC);
      D_8009D4EC = 0;
      func_80081B28(D_8009D4E8);
      D_8009D4E8 = 0;
    }
  }
}
