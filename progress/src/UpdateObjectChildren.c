typedef struct Ent
{
  u8 *p0;
  u16 f4;
  u16 f6;
} Ent;
extern u8 D_8009BBBC;
extern s16 D_8009C254[][4][7];
extern s32 D_8009C2C4[];
extern u16 D_800B5B50;
extern s32 D_800B5B44;
extern u8 *g_prepared_list;
extern u8 g_dark_mode;
extern u8 *g_camera;
u8 *boxListFind(void *, void *, void *);
void func_8000DBC0(s32);
void heapFreeBlock(s32);

/* Resolves the object's current node (falling back to the default node when
 * none is found). When the node changes and the feature flag is set, it frees
 * the old node's children, then makes the new node current. Otherwise it marks
 * the object active and runs each child's handler from the D_8009C254 table. */
void UpdateObjectChildren(s32 arg0, u8 *obj, u8 *ctx, s32 arg3)
{
  int __repair_literal;
  u8 *target;
  u8 *child;
  s32 idx;
  u8 *new_var;
  s32 v;
  u8 *cur;
  target = boxListFind(g_prepared_list, g_camera + 0x38, *((void **) (obj + 0x14)));
  if (target == NULL)
  {
    cur = *((u8 **) (obj + 0x14));
    if (cur != NULL)
      target = cur;
    else
      target = *(*((u8 ***) (&g_prepared_list)));
  }
  if ((*((u8 **) (obj + 0x14))) == NULL)
  {
    *((u8 **) (obj + 0x14)) = target;
  }
  if (D_8009BBBC != 0)
  {
    if ((*((u8 **) (obj + 0x14))) != target)
    {
      idx = (*((s32 *) (*((u8 **) (obj + 0x14)) + 0x28))) - 1;
      while (idx >= 0)
      {
        child = *((u8 **) ((*((u8 **) ((*((u8 **) (obj + 0x14))) + 0x2C))) + (idx * 8)));
        if ((*((s32 *) (child + 0x38))) != 0)
        {
          heapFreeBlock(*((s32 *) (child + 0x38)));
          *((s32 *) (child + 0x38)) = 0;
        }
        idx--;
      }

      func_8000DBC0(D_800B5B44);
      *((u8 **) (obj + 0x14)) = target;
      return;
    }
  }
  if (target != NULL)
  {
    *((s16 *) (obj + 0x18)) = 1;
    *((u16 *) (obj + 0x1C)) = 0;
    idx = (*((s32 *) (target + 0x28))) + (-1);
    while (idx >= 0)
    {
      Ent *rec = (Ent *) ((*((u8 **) (target + 0x2C))) + (idx * 8));
      if ((idx != 0) && (rec->f4 == 0))
      {
        rec->f4 = 4;
      }
      v = D_8009C254[D_800B5B50][g_dark_mode][rec->f4];
      if (v >= 0)
      {
        new_var = rec->p0;
        __repair_literal = 4;
        *((u16 *) (obj + 0x1C)) |= ((s32 (*)(u8 *, s32, u8 *, s32)) (*((s32 *) ((((char *) D_8009C254) + 0x70) + (rec->f6 * __repair_literal)))))(new_var, rec->f4, ctx, arg3);
      }
      idx--;
    }

  }
  *((u8 **) (obj + 0x14)) = target;
}
