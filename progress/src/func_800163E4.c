extern char gStreamState[];
extern u8 *g_rec_val;
void *func_80016204(void *);
void *poolAlloc(s32, s32);
void memset(void *, s32, s32);
s32 func_80005CB8(s32, s32, s32, s32, s32);
void func_80005D98(s32);
void func_80016354(void *, void *);
void func_800560E0(void *, s32);
typedef struct 
{
  u8 b[8];
} Chunk8;
typedef struct 
{
  u8 b[12];
} Chunk12;
typedef struct 
{
  u32 w[4];
} Chunk16;
typedef struct 
{
  u32 w[3];
} ChunkTail;
typedef struct 
{
  u32 w[5];
} Chunk20;
typedef struct 
{
  u32 w[16];
} Chunk64;
/* Adds a new entry to the table at tbl (count at 0x20, entries of 0x38 bytes):
 * copies the template header, builds the per-part list of 0x94-byte nodes with a
 * sound handle for each part, and links the five parts together. Returns the entry. */
void *func_800163E4(void *owner, u8 *tbl, u8 *initData)
{
  char *slotPtr;
  u8 *info = func_80016204(owner);
  u8 *r;
  u8 *p;
  u8 *q;
  s32 n;
  s32 i;
  s32 handle;
  s32 mode;
  *((u16 *) (tbl + 0x22)) = *((u16 *) (tbl + 0x20));
  slotPtr = gStreamState + 0x5dce;
  r = tbl + (((*((u16 *) (tbl + 0x20))) * 0x38) + 0x3c);
  *((Chunk8 *) r) = *((Chunk8 *) initData);
  {
    u8 *dst = poolAlloc(1, 0x7c);
    u8 *src = g_rec_val;
    u8 *end = src + 0x70;
    *((void **) (r + 8)) = dst;
    do
    {
      *((Chunk16 *) dst) = *((Chunk16 *) src);
      src += 16;
      dst += 16;
    }
    while (src != end);
    *((ChunkTail *) dst) = *((ChunkTail *) src);
  }
  n = *((u16 *) ((*((u8 **) (r + 8))) + 0x28));
  *((void **) ((*((u8 **) (r + 8))) + 0x24)) = poolAlloc(1, n * 20);
  for (i = 0; i < n; i++)
  {
    ((Chunk20 *) (*((void **) ((*((u8 **) (r + 8))) + 0x24))))[i] = ((Chunk20 *) (*((void **) (g_rec_val + 0x24))))[i];
  }

  *((u8 **) slotPtr) = r;
  *((Chunk12 *) (r + 0x20)) = *((Chunk12 *) (g_rec_val + 4));
  *((u16 *) (r + 0x2c)) = 1;
  r[0x2f] = 0;
  ++(*((u16 *) (tbl + 0x20)));
  *((void **) (r + 0x10)) = poolAlloc(1, (*((u16 *) (info + 4))) * 4);
  *((u32 *) (r + 0xc)) = *((u16 *) (info + 4));
  for (i = 0; ((u32) i) < (*((u32 *) (r + 0xc))); i++)
  {
    handle = 0;
    p = (*((u8 **) info)) + (i * 0x6c);
    q = poolAlloc(1, 0x94);
    memset(q, 0, 0x94);
    *((u32 *) q) = 0;
    *((Chunk64 *) (q + 8)) = *((Chunk64 *) (p + 0xc));
    *((Chunk64 *) (q + 0x48)) = *((Chunk64 *) (p + 0xc));
    (*((u8 ***) (r + 0x10)))[i] = q;
    *((u8 **) ((*((u8 ***) (r + 0x10)))[i] + 0x8c)) = p;
    mode = (u8) gStreamState[0x7678];
    if (i == 0)
    {
      switch (mode)
      {
        case 0:
          handle = func_80005CB8(1, 0x960, 0x230, 1, 6);
          break;

        case 1:
          handle = func_80005CB8(1, 0x708, 0x140, 1, 6);
          break;

        case 2:
          handle = func_80005CB8(1, 0x708, 0x140, 1, 6);
          break;

        case 3:
          handle = func_80005CB8(1, 0x12c, 0x80, 1, 6);
          break;

      }

    }
    else
    {
      switch (mode)
      {
        case 0:
          handle = func_80005CB8(1, 0x80, 0x40, 1, 6);
          break;

        case 1:
          handle = func_80005CB8(1, 0x80, 0x40, 1, 6);
          break;

        case 2:
          handle = func_80005CB8(1, 0x80, 0x40, 1, 6);
          break;

        case 3:
          handle = func_80005CB8(1, 0x80, 0x40, 1, 6);
          break;

      }

    }
    *((s32 *) ((*((u8 ***) (r + 0x10)))[i] + 0x90)) = handle;
    func_800560E0(p, handle);
    func_80005D98(handle);
  }

  func_80016354((*((void ***) (r + 0x10)))[1], (*((void ***) (r + 0x10)))[0]);
  func_80016354((*((void ***) (r + 0x10)))[2], (*((void ***) (r + 0x10)))[0]);
  func_80016354((*((void ***) (r + 0x10)))[3], (*((void ***) (r + 0x10)))[0]);
  func_80016354((*((void ***) (r + 0x10)))[4], (*((void ***) (r + 0x10)))[0]);
  *((u32 *) ((*((u8 ***) (r + 0x10)))[0] + 4)) = 0;
  *((u32 *) ((*((u8 ***) (r + 0x10)))[0] + 0x88)) = 0;
  *((void **) ((*((u8 ***) (r + 0x10)))[1] + 4)) = (*((void ***) (r + 0x10)))[0];
  *((void **) ((*((u8 ***) (r + 0x10)))[2] + 4)) = (*((void ***) (r + 0x10)))[0];
  *((void **) ((*((u8 ***) (r + 0x10)))[3] + 4)) = (*((void ***) (r + 0x10)))[0];
  *((void **) ((*((u8 ***) (r + 0x10)))[4] + 4)) = (*((void ***) (r + 0x10)))[0];
  return r;
}
