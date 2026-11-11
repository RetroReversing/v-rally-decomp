extern s32 gShadeMode;
extern u8 g_dark_mode;
typedef struct 
{
  s8 u;
  s8 v;
} UV;
typedef struct 
{
  u16 idx[4];
  UV uv[4];
  u16 last;
} Rec;
typedef struct 
{
  u8 color[16];
  u16 pos[4];
  UV uv[4];
  u16 last;
} Out;
typedef struct 
{
  Rec *records;
  u16 count;
} Info;

/* Expands each input record (four vertex indices, UVs and a tail word) into an
 * output vertex record: positions are the indices offset by off, and each
 * vertex colour comes from tbl, or from a fixed fallback colour when gShadeMode
 * is 2. Advances the output pointer once per record. */
void func_80055EE8(Out **dst, Info *in, s32 off, u8 *tbl)
{
  Rec *rec = in->records;
  s32 count = in->count;
  s32 k;
  u8 fallback_col;
  u8 vcol;
  fallback_col = 0x8C;
  if (g_dark_mode == 0)
  {
    fallback_col = 0x32;
  }
  for (k = 0; k < count; rec++, k++)
  {
    (*dst)->pos[0] = ((int) rec->idx[0]) + off;
    (*dst)->pos[1] = rec->idx[1] + off;
    (*dst)->pos[2] = rec->idx[2] + off;
    (*dst)->pos[3] = rec->idx[3] + off;
    if (gShadeMode != 2)
    {
      vcol = tbl[rec->idx[0]];
    }
    else
    {
      vcol = fallback_col;
    }
    (*dst)->color[0] = vcol;
    (*dst)->color[1] = vcol;
    (*dst)->color[2] = vcol;
    (*dst)->color[3] = 10;
    if (gShadeMode != 2)
    {
      vcol = tbl[rec->idx[1]];
    }
    else
    {
      vcol = fallback_col;
    }
    (*dst)->color[4] = vcol;
    (*dst)->color[5] = vcol;
    (*dst)->color[6] = vcol;
    (*dst)->color[7] = 0;
    if (gShadeMode != 2)
    {
      vcol = tbl[rec->idx[2]];
    }
    else
    {
      vcol = fallback_col;
    }
    (*dst)->color[8] = vcol;
    (*dst)->color[9] = vcol;
    (*dst)->color[10] = vcol;
    (*dst)->color[11] = 0;
    if (gShadeMode != 2)
    {
      vcol = tbl[rec->idx[3]];
    }
    else
    {
      vcol = fallback_col;
    }
    (*dst)->color[12] = vcol;
    (*dst)->color[13] = vcol;
    (*dst)->color[14] = vcol;
    (*dst)->color[15] = 0;
    (*dst)->uv[0] = rec->uv[0];
    (*dst)->uv[1] = rec->uv[1];
    (*dst)->uv[2] = rec->uv[2];
    (*dst)->uv[3] = rec->uv[3];
    (*dst)->last = rec->last;
    (*dst)++;
  }

}
