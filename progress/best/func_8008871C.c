typedef struct 
{
  u8 b[0x100];
} Obj;
extern void *D_800A1BC0[];
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern u8 *func_80087988(void *, s32);
extern void func_80088AA4(void *, s32);
extern void func_80089298(void *);
extern void func_80089538(void *);
extern void alSynSetFXMix(void *, s32, s32);
extern void alSynSetVol(void *, s32, s32, void *);
extern void alSynStopVoice(void *, s32);
void func_8008871C(Obj *o, s32 n)
{
int __repair_literal;

  u8 *p;
  u8 kind;
  u16 len;
  s32 idx;
  void *env;
  p = *((u8 **) o->b);
  if (!p)
  {
    goto stop;
  }
  while ((double) 1)
  {
    u8 op = *p;
    if (op < 0x80)
    {
      break;
    }
    if (op >= 0xaa)
    {
      *((u8 **) o->b) = 0;
      goto end;
    }
    p = ((u8 *(*)(Obj *, u8 *)) D_800A1BC0[op & 0x7f])(o, p + 1);
    if (!p)
    {
    }
    break;
  }

  p = (*((u8 **) o->b) = p);
  if (!p)
  {
    goto stop;
  }
  *((f32 *) (o->b + 0x48)) = *((f32 *) (o->b + 0x4c));
  *((u8 **) o->b) = p + 1;
  kind = *p;
  if (o->b[0xca])
  {
    *((u8 **) o->b) = p + 2;
    o->b[0xb3] = p[1];
  }
  else
  {
    o->b[0xb3] = o->b[0xcb];
  }
  {
    u8 duration;
    len = *((u16 *) (o->b + 0xa4));
    if (len)
    {
      if (o->b[0xaf])
      {
        p = *((u8 **) o->b);
        o->b[0xaf] = 0;
        *((u8 **) o->b) = p + 1;
        duration = *p;
        if (duration < 0x80)
        {
          *((u16 *) (o->b + 0x92)) = duration;
        }
        else
        {
          *((u8 **) o->b) = p + 2;
          *((u16 *) (o->b + 0x92)) = p[1] + ((duration & 0x7f) << 8);
        }
      }
      else
      {
        *((u16 *) (o->b + 0x92)) = len;
      }
    }
    else
    {
      p = *((u8 **) o->b);
      *((u8 **) o->b) = p + 1;
      duration = *p;
      if (duration < 0x80)
      {
        *((u16 *) (o->b + 0x92)) = duration;
      }
      else
      {
        *((u8 **) o->b) = p + 2;
        *((u16 *) (o->b + 0x92)) = p[1] + ((duration & 0x7f) << 8);
      }
    }
  }
  *((s32 *) (o->b + 0x3c)) = *((s32 *) (o->b + 0x38));
  *((u16 *) (o->b + 0xa2)) = 0;
  o->b[0xc9] = 0;
  *((s32 *) (o->b + 0x38)) += (*((u16 *) (0x92 + o->b))) << 8;
  o->b[0xc8] = o->b[0xc7];
  if (kind == 0x60)
  {
    if (o->b[0xbb] < 4)
    {
      o->b[0xbb] = 4;
      o->b[0xbd] = 1;
      *((s32 *) (o->b + 0x50)) = *((s32 *) (o->b + 8));
      o->b[0xc5] = o->b[0xbc];
    }
    goto end;
  }
  env = *((void **) (o->b + 0x74));
  ;
  if (*((u8 **) (o->b + 0x7c)))
  {
    u8 *q = (*((u8 **) (o->b + 0x7c))) + (kind * 4);
    *((u16 *) (o->b + 0xa6)) = q[0];
    o->b[0xb5] = ((*((u8 **) (o->b + 0x7c))) + (kind * 4))[2] >> 1;
__repair_literal = 4;

    func_80087988(o, (*((s32 *) (((u8 *) (*((void **) (o->b + 0x70)))) + 0x10))) + (((*((u8 **) (o->b + 0x7c))) + (kind * __repair_literal))[1] * 7));
    kind = q[3];
  }
  if (!o->b[0xce])
  {
    func_80089298(o);
  }
  if (o->b[0xcc])
  {
    func_80089538(o);
  }
  if (!o->b[0xcf])
  {
    *((s32 *) (o->b + 4)) = *((s32 *) ((((u8 *) env) + 0x2c) + ((*((u16 *) (o->b + 0xa6))) * 4)));
    if (o->b[0xc1] && (*((u16 *) (o->b + 0x98))))
    {
      alSynSetVol(D_800AE850 + 0x2304, (*((s32 *) (D_800C02AE + 0x7576))) + (n * 28), 0, D_800AE850 + 0x7420);
    }
    else
    {
      func_80088AA4(o, n);
    }
  }
  *((f32 *) (o->b + 0x28)) = ((f32) kind) + (*((f32 *) ((((u8 *) env) + 0x28) + ((*((u16 *) (o->b + 0xa6))) * 4))));
  if (o->b[0xc2] != o->b[0xc4])
  {
    short a = o->b[0xc3];
    u8 v = o->b[0xc2];
    *((u16 *) (o->b + 0x98)) = 0;
    o->b[0xc4] = v;
    alSynSetFXMix(D_800AE850 + 0x2304, (*((s32 *) (D_800C02AE + 0x7576))) + (n * 28), (a + (((0x80 - a) * v) >> 7)) & 255);
  }
  goto end;
  stop:
  if (o->b[0xc1])
  {
    o->b[0xc1] = 0;
    alSynStopVoice(D_800AE850 + 0x2304, (*((s32 *) (D_800C02AE + 0x7576))) + (n * 28));
  }

  end:
  ;

  ;
  ;
  ;
  ;
  ;
  ;
  ;
}
