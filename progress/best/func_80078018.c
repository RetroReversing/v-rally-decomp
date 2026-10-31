typedef struct Node
{
  u32 pad;
  struct Node *next;
  u8 p[64];
  s32 *type;
} Node;
extern Node **D_800B5C40;
extern u8 *D_800C35A0;
extern u8 D_800C7F90[];
extern u8 D_800C7FA0[];
extern u8 D_800C7FA1[];
extern u8 D_800C7FA2[];
extern u8 D_800C3616[];
extern u8 D_800C3654[];
extern u8 D_800C365A[];
extern u8 D_800C8002;
extern s32 D_800C7F94[];
extern s32 D_800C7F98[];
extern s32 D_800C7F9C[];
extern s32 D_800C7FA4[];
extern s32 D_800C7FF4;
extern s32 D_800C7FFC;
extern s32 D_800C3650[];
extern u8 D_800C7FF0[];
extern u32 D_800B55FC[];
extern s32 D_8009D540;
extern void func_80097E30(void *, s32, s32);
extern void func_80098290(void *, void *);
extern u8 func_80077FA8(s32);
void func_80078018(void)
{
  char *__repair_addr;
  u8 *event;
  s8 i = 0;
  Node *node = *D_800B5C40;
  s8 k;
  s32 off;
  s32 n;
  s32 d;
  u32 a;
  u32 b;
  u32 *new_var3;
  u8 *new_var;
  u8 *new_var2;
  u8 j;
  s32 z;
  func_80097E30(D_800C7F90, 0, 120);
  if (node)
  {
    do
    {
      j = i;
      k = func_80077FA8(j);
      __repair_addr = (char *) (((s32) D_800C7FA4) + (((u8) k) * 24));
      if (*((s32 *) __repair_addr))
      {
        k--;
      }
      off = ((u8) k) * 24;
      *((Node **) ((D_800C7FA0 + off) + 4)) = node;
      ;
      func_80098290(D_800C7F90 + off, D_800C35A0 + (((*((D_800C35A0 + j) + 50)) * 40) + 68));
      event = D_800C35A0;
      n = event[j + 50];
      b = *((u16 *) ((event + (((unsigned char) n) * 40)) + 78));
      D_800C7FA1[off] = i;
      D_800C7FA2[off] = b;
      event = D_800C35A0;
      n = *((u16 *) (event + 30));
      new_var2 = (u8 *) (D_800B55FC + n);
      new_var3 = D_800B55FC + 4;
      *((u32 *) (((u8 *) D_800C7F94) + off)) = *((u32 *) (new_var2 + (j * 32)));
      *((u32 *) (((u8 *) (new_var3 + (*((u16 *) (event + 30))))) + (j * 32))) /= 100;
      n = *((u16 *) (event + 30));
      a = (*((u32 *) (((u8 *) (new_var3 + n)) + (j * 32)))) * D_8009D540;
      new_var = (u8 *) (D_800B55FC + n);
      b = *((u32 *) (new_var + (j * 32)));
      *((u32 *) (((u8 *) D_800C7F9C) + off)) = (a * 3600) / (b * 10);
      D_800C7FA0[off] = *node->type;
      node = (*node).next;
      i++;
    }
    while (node);
  }
  for (z = 0; ((u8) z) < 4; z++)
  {
    off = ((u8) z) * 24;
    a = *((s32 *) (((u8 *) D_800C7F94) + off));
    if (a)
    {
      d = D_800C7F94[0];
      d = d;
      d = a - d;
      if (d < 0)
      {
        d = -d;
      }
      *((s32 *) (((u8 *) D_800C7F98) + off)) = d;
    }
    else
    {
      *((s32 *) (((u8 *) D_800C7F98) + off)) = 0;
    }
  }

  event = D_800C35A0;
  func_80098290(D_800C7FF0, D_800C3616 + ((*((u16 *) (event + 30))) * 64));
  event = D_800C35A0;
  D_800C7FF4 = *((s32 *) (((u8 *) D_800C3650) + (((s16) ((*((u16 *) (event + 30))) - 1)) * 64)));
  D_800C7FFC = D_800C365A[((s16) ((*((u16 *) (event + 30))) - 1)) * 64];
  D_800C8002 = D_800C3654[((s16) ((*((u16 *) (event + 30))) - 1)) * 64];
}
