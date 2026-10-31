extern signed char D_800C34D0;
extern unsigned char D_800C7926;
s32 func_80034FF0();
s32 func_80035B04();
s32 func_80036260();
s32 func_80036C48();
void *func_8004240C();
void *func_8007EAA0();
extern s32 D_8009FF30;
extern char D_800C02AE[];
typedef struct Obj356
{
  s32 x;
  u16 mode;
  s8 b6;
  s8 b7;
  u32 n;
  s32 c;
  void *p;
  void *q;
  f32 f18;
  f32 f1c;
  f32 f20;
  f32 f24;
  f32 f28;
  f32 f2c;
  s32 *cb;
  s32 *cb2;
  f32 x38;
  f32 x3c;
  f32 x40;
} Obj356;
extern Obj356 *D_800C811C;
extern void *D_800C7F84;
extern void *D_800C35A0;
extern s32 func_80035C4C;
extern s32 func_80035F24;
extern s32 func_8003647C;
extern s32 func_8003678C;
void func_80035684(void *arg0)
{
  s32 temp_v1;
  u32 temp_v1_2;
  u32 temp_v1_3;
  u32 var_v0;
  void *temp_v0;
  void *temp_v0_2;
  temp_v0 = func_8007EAA0(1, 0x44);
  temp_v1_2 = D_8009FF30;
  D_800C811C = temp_v0;
  *((s16 *) (((char *) temp_v0) + 4)) = (s16) temp_v1_2;
  temp_v0_2 = func_8004240C(1);
  D_800C811C->f18 = (f32) (*((f32 *) (((char *) temp_v0_2) + 0x118)));
  temp_v1 = D_800C811C->mode;
  D_800C811C->f18 = (f32) (*((f32 *) (((char *) temp_v0_2) + 0x11C)));
  D_800C811C->f20 = (f32) (*((f32 *) (((char *) temp_v0_2) + 0x120)));
  D_800C811C->f24 = (f32) (*((f32 *) (((char *) temp_v0_2) + 0x118)));
  D_800C811C->f24 = (f32) (*((f32 *) (((char *) temp_v0_2) + 0x11C)));
  D_800C811C->f2c = (f32) (*((f32 *) (((char *) temp_v0_2) + 0x120)));
  D_800C7F84 = temp_v0_2;
  D_800C34D0 = 0;
  switch (temp_v1)
  {
    case 0:
      D_800C811C->x = 0;
      D_800C811C->p = NULL;
      D_800C811C->q = NULL;
      if ((*((volatile u8 *) (&D_800C7926))) == 0)
    {
      D_800C811C->x38 = (f32) (*((s32 *) (((char *) arg0) + 0x420)));
      D_800C811C->x3c = (f32) (((f32) (-(*((s32 *) (((char *) arg0) + 0x46C))))) * 0.1f);
      D_800C811C->x40 = (f32) (*((s32 *) (((char *) arg0) + 0x4B8)));
      func_80036C48(arg0, D_800C811C);
      return;
    }
      return;

    case 3:
      temp_v1_2 = 0x32;
      temp_v1_2 = (*((s32 *) (((char *) arg0) + 0xDC))) - temp_v1_2;
      D_800C811C->n = temp_v1_2;
      if (((((u32) (D_800C7926 - 1)) < 2U) || ((temp_v1_2 = *((u16 *) (((char *) D_800C35A0) + 0x1E)), temp_v1_2 == 5))) || ((temp_v1_2 != 0) & (temp_v1_2 < 5U)))
    {
      D_800C811C->n = (u32) (D_800C811C->n / 3);
    }
    else
      if (D_800C7926 == 3)
    {
      D_800C811C->n = (u32) (temp_v1_2 >> 2);
    }
      D_800C811C->b7 = (s8) (*((s32 *) (((char *) arg0) + 0x128)));
      temp_v1_3 = D_800C811C->n;
      D_800C811C->cb = &func_8003647C;
      D_800C811C->x = 0;
      D_800C811C->cb2 = &func_8003678C;
      D_800C811C->p = func_8007EAA0(1, 5 * (4 * temp_v1_3));
      if ((*((u16 *) (((char *) D_800C35A0) + 0xE))) == 2)
    {
      D_800C811C->q = func_8007EAA0(1, D_800C811C->n * 0x14);
      func_80036260(D_800C811C->p);
      func_80036260(D_800C811C->q);
      return;
    }
      D_800C811C->q = NULL;
      func_80036260(D_800C811C->p, D_800C811C);
      return;

    case 4:
      temp_v1_3 = *((u32 *) (((char *) arg0) + 0x174));
      D_800C811C->n = temp_v1_3;
      var_v0 = temp_v1_3 >> 1;
 do { } while (0);
      if ((((u32) (D_800C7926 - 1)) < 2U) || ((var_v0 = temp_v1_3 >> 2, D_800C7926 == 3)))
    {
      D_800C811C->n = var_v0;
    }
      D_800C811C->c = (s32) (*((s32 *) (((char *) arg0) + 0x1C0)));
      D_800C811C->b6 = (s8) (*((s32 *) (((char *) arg0) + 0x20C)));
      D_800C811C->b7 = (s8) (*((s32 *) (((char *) arg0) + 0x258)));
      D_800C811C->x = func_80034FF0(arg0 + 0x260, 0);
      D_800C811C->cb = &func_80035C4C;
      D_800C811C->cb2 = &func_80035F24;
      D_800C811C->p = func_8007EAA0(1, D_800C811C->n * 8);
      if ((*((u16 *) (((char *) D_800C35A0) + 0xE))) == 2)
    {
      D_800C811C->q = func_8007EAA0(1, D_800C811C->n * 8);
      func_80035B04(D_800C811C->p);
      func_80035B04(D_800C811C->q);
      return;
    }
      D_800C811C->q = NULL;
      func_80035B04(D_800C811C->p, D_800C811C);
      return;

    default:
      D_800C811C->x = 0;
      D_800C811C->p = NULL;
      D_800C811C->q = NULL;
      break;

  }

}
