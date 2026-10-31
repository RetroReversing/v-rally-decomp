typedef struct 
{
  u8 pad[0x6C];
  void *link;
  u8 gap[0x14];
  u16 idx;
  u16 timer;
  u32 value;
} AnimObj;
extern char *D_800C7F84;
extern char D_800C02AE[];
extern char D_800A73E0[];
extern u16 D_8009BA40[];
extern u16 D_8009BA42[];
extern u16 D_8009BA44[];
extern u16 D_8009BA46[];
extern u16 D_8009BA4A[];
extern u16 D_8009BA4C[];
extern u16 D_8009BA52[];
extern u16 D_8009BA54[];
extern u16 D_8009BA5A[];
extern u16 D_8009BA5C[];
extern u16 D_8009BA62[];
extern u16 D_8009BA64[];
extern u16 D_8009BA6A[];
extern u16 D_8009BA6C[];
void *func_80022668(void *a0, s32 a1);
void func_80010F3C(void *a0, s32 a1);
void func_800122A4(AnimObj *arg0)
{
  char *ctx;
  char *obj;
  char *s1;
  char *sub;
  char *p;
  char *q;
  volatile int new_var5;
  char *new_var4;
  s32 state;
  u16 idx;
  s32 g;
  int new_var3;
  s32 a0flag;
  u16 new_var2;
  int new_var;
  void (*fn)(void *);
  ctx = *((char **) (D_800C02AE + 0x7CD6));
  *((s32 *) (ctx + 0x130)) = 0;
  *((f32 *) ((*((char **) (D_800C02AE + 0x7CD6))) + 0x134)) = 100.0f;
  *((s32 *) ((*((char **) (D_800C02AE + 0x7CD6))) + 0x138)) = 0;
  *((f32 *) ((*((char **) (D_800C02AE + 0x7CD6))) + 0x114)) = 1.0f;
  obj = *((char **) (ctx + 0x24));
  s1 = NULL;
  if (obj == NULL)
  {
    return;
  }
  sub = *((char **) (obj + 0x9C));
  state = *((s32 *) (sub + 0x34));
  switch (state)
  {
    new_var5 = D_8009BA4A[0];
    case 0:
      if (arg0->timer != 0)
    {
      arg0->timer -= 1;
    }
      idx = arg0->idx;
      s1 = func_80022668(arg0->link, D_8009BA42[arg0->idx * 4]);
      if (arg0->timer != 0)
    {
      goto end_a;
    }
      idx = arg0->idx;
      a0flag = 1;
      if (D_8009BA40[arg0->idx * 4] == 2)
    {
      a0flag = (*((u32 *) (s1 + 0x88))) >= 0x32;
    }
      if (!a0flag)
    {
      goto end_a;
    }
      arg0->idx = idx + 1;
      if (((u16) (idx + 1)) == 6)
    {
      arg0->idx = 0;
    }
      idx = arg0->idx;
      arg0->value = 0;
      arg0->timer = D_8009BA46[arg0->idx * 4];
      s1 = func_80022668(arg0->link, D_8009BA46[(arg0->idx * 4) - 2]);
      if (D_8009BA44[(arg0->idx * 4) - 2] == 2)
    {
      *((s32 *) (s1 + 0x88)) = 0x33;
      goto end_a;
    }
      p = *((char **) (D_800C7F84 + 0x24));
      p = *((char **) (p + 0x8C));
      q = *((char **) (p + 0x28));
      g = *((s32 *) (D_800A73E0 + 0x6C08));
      a0flag = 0;
      if ((*((s16 *) (q + 8))) == g)
    {
      a0flag = 1;
    }
    else
      if ((*((char **) (q + 0x5C))) != NULL)
    {
      if ((*((s16 *) ((*((char **) (q + 0x5C))) + 8))) == g)
      {
        a0flag = 1;
      }
      else
        if (((*((char **) ((*((char **) (q + 0x5C))) + 0x5C))) != NULL) && ((*((s16 *) ((*((char **) ((*((char **) (q + 0x5C))) + 0x5C))) + 8))) == g))
      {
        a0flag = 1;
      }
    }
      if (a0flag == 0)
    {
      goto end_a;
    }
      arg0->idx = 0;
      arg0->value = 0;
      arg0->timer = D_8009BA46[0] + 0xC8;
      s1 = func_80022668(arg0->link, D_8009BA42[arg0->idx * 4]);
      goto end_a;
      end_a:
    idx = arg0->idx;

      if (D_8009BA40[arg0->idx * 4] == 1)
    {
      *((s32 *) (s1 + 0x20)) = 1;
    }
    else
    {
      func_80010F3C(s1, 0);
    }
      *((s32 *) (s1 + 0x30)) = D_8009BA44[arg0->idx * 4];
      goto call;

    case 1:
      new_var2 = D_8009BA4C[0];
      s1 = func_80022668(arg0->link, new_var5);
      *((s32 *) (s1 + 0x30)) = new_var2;
      if ((*((u32 *) (s1 + 0x88))) < 0x32)
    {
      *((s32 *) (new_var4 = s1 + 0x88)) = 0x33;
    }
      goto call;

    case 2:
      s1 = func_80022668(arg0->link, D_8009BA42[0]);
      *((s32 *) (s1 + 0x30)) = D_8009BA44[0];
      goto call;

    case 3:
      s1 = func_80022668(arg0->link, D_8009BA52[0]);
      *((s32 *) (s1 + 0x30)) = D_8009BA54[0];
      goto check1;
      new_var = D_8009BA64[0];

    case 4:
      s1 = func_80022668(arg0->link, D_8009BA5A[0]);
      *((s32 *) (s1 + 0x30)) = D_8009BA5C[0];
      goto call;

    case 5:
      s1 = func_80022668(arg0->link, D_8009BA62[0]);
      *((s32 *) (s1 + 0x30)) = new_var;
      goto check1;

    case 6:
      s1 = func_80022668(arg0->link, D_8009BA6A[0]);
      *((s32 *) (s1 + 0x30)) = D_8009BA6C[0];
      arg0->timer = 0;
      goto check1;

    default:
      goto call;

  }

  check1:
  idx = arg0->idx;

  new_var3 = arg0->idx;
  if (D_8009BA40[new_var3 * 4] == 1)
  {
    *((s32 *) (s1 + 0x20)) = 1;
  }
  call:
  fn = *((void (**)(void *)) (s1 + 0xC));

  fn(s1);
}
