extern s32 gShadeMode;
extern u8 g_dark_mode;
typedef struct { s8 a, b; } Pair;
typedef struct
{
  u16 x;
  u16 y;
  u16 z;
  Pair n[3];
  u16 flag;
} Rec;
typedef struct
{
  Rec *recs;
  u16 count;
} RecList;
typedef struct
{
  u8 col[16];
  u16 v[4];
  Pair n[3];
  u8 pad[2];
  u16 flag;
} Out;

/* Writes one render vertex per record in list: the offset position, a shade
 * colour per corner taken from shade[] (or a fallback when gShadeMode == 2),
 * the normals and the flag. Advances *outp past the written vertices. */
void func_80055D18(Out **outp, RecList *list, s32 offset, u8 *shade)
{
  Rec *rec;
  s32 count;
  s32 i;
  u8 fallback;
  u8 c;
  rec = list->recs;
  count = list->count;
  fallback = 0x8C;
  if (g_dark_mode == 0)
  {
    fallback = 0x32;
  }
  for (i = 0; i < count; i++)
  {
    (*outp)->v[0] = rec->x + offset;
    (*outp)->v[1] = rec->y + offset;
    (*outp)->v[2] = rec->z + offset;
    (*outp)->v[3] = 0;
    if (gShadeMode != 2)
    {
      c = shade[rec->x];
    }
    else
    {
      c = fallback;
    }
    (*outp)->col[0] = c;
    (*outp)->col[1] = c;
    (*outp)->col[2] = c;
    (*outp)->col[3] = 6;
    c = fallback;
    if (gShadeMode != 2)
    {
      c = shade[rec->y];
    }
    (*outp)->col[4] = c;
    (*outp)->col[5] = c;
    (*outp)->col[6] = c;
    (*outp)->col[7] = 0;
    c = fallback;
    if (gShadeMode != 2)
    {
      c = shade[rec->z];
    }
    (*outp)->col[8] = c;
    (*outp)->col[9] = c;
    (*outp)->col[10] = c;
    (*outp)->col[11] = 0;
    (*outp)->col[12] = 0;
    (*outp)->col[13] = 0;
    (*outp)->col[14] = 0;
    (*outp)->col[15] = 0;
    (*outp)->n[0] = rec->n[0];
    (*outp)->n[1] = rec->n[1];
    (*outp)->n[2] = rec->n[2];
    (*outp)->pad[0] = 0;
    (*outp)->pad[1] = 0;
    (*outp)->flag = rec->flag;
    rec++;
    (*outp)++;
  }
}
