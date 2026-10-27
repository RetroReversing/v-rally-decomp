#include "common.h"

#define P21 D_800C35A0
typedef struct 
{
  s32 x[10];
} Block21;
extern u8 *D_800C35A0;
void func_80021A4C(void);
void func_800804C4(s32, void (*)(void));
void func_80053A78(void);
void func_8006F0E0(s32);
void func_8006F75C(void);
static inline Block21 *inline_fn()
{
  return (Block21 *) (P21 + 0x6c);
}

void func_80021AB8(s32 arg0)
{
  Block21 a;
  Block21 b;
  Block21 c;
  Block21 d;
  Block21 *p;
  Block21 *q;
  Block21 *r;
  Block21 *new_var3;
  int new_var2;
  Block21 *new_var4;
  int new_var;
  Block21 *t;
  if ((*((u16 *) (P21 + 0x1e))) == 7)
  {
    return;
  }
  new_var = 2;
  if (arg0)
  {
    func_800804C4(arg0, func_80021A4C);
  }
  if (*((u16 *) (P21 + 0x1e)))
  {
    a = *((Block21 *) ((0, P21 + 0x44)));
    b = *inline_fn();
    c = *((Block21 *) (P21 + 0x94));
    d = *((Block21 *) (P21 + 0xbc));
    new_var2 = 0;
    func_80053A78();
    func_8006F0E0(new_var2);
    func_8006F0E0(1);
    func_8006F0E0(new_var);
    func_8006F0E0(3);
    p = (Block21 *) (P21 + 0x44);
    q = &a;
    r = q;
    t = r;
    *p = *t;
    p = inline_fn();
    q = &b;
    r = q;
    t = r;
    *p = *t;
    new_var4 = (Block21 *) (P21 + 0x94);
    new_var3 = &c;
    p = new_var4;
    q = new_var3;
    r = q;
    t = r;
    *p = *t;
    p = (Block21 *) (P21 + 0xbc);
    q = &d;
    r = q;
    t = r;
    *p = *t;
    func_8006F75C();
  }
}
