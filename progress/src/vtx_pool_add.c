typedef struct 
{
  u8 p[0x14];
  u32 *cmd;
  u32 *old;
  u8 p1c[0x54];
  s16 *items;
  u8 p74[6];
  u16 count;
} VtxPool;
typedef struct 
{
  s16 a;
  s16 b;
  s16 c;
} VtxIn;
extern s32 osVirtualToPhysical(void *);
extern void vtx_pool_set_flags(void *, s32);

/* Maps n input vertices (verts) to slots in the pool's vertex buffer: an
 * existing slot is reused when the same vertex is already present, otherwise
 * the vertex is appended. Writes each slot index to indices (0xFFFF = none
 * yet), and emits a G_VTX load into the pool's display list when a 32-vertex
 * block is started. */
void vtx_pool_add(VtxPool *pool, VtxIn *verts, s32 n, u16 *indices)
{
  VtxPool *o = pool;
  s32 remaining = n;
  s32 i;
  s32 j;
  u16 start;
  volatile char pad[8];
#define new_var n
  j = 0;
  if (new_var > 0)
  {
    do
    {
      indices[j] = 0xffff;
      j++;
    }
    while (j < new_var);
  }
  start = o->count >> 5;
  for (i = 0; i < new_var; i++)
  {
    VtxIn *src;
    u16 *dst;
    j = start * 32;
    if (j < o->count)
    {
      do
      {
        #ifdef PORT
        VtxIn *p = (VtxIn *)((u8 *)o->items + ((j << 2) << 2));
#else
        VtxIn *p = (VtxIn *) (((j << 2) << 2) + ((s32) o->items));
#endif
        if (((p->a == (verts + i)->a) && (p->b == (verts + i)->b)) && (p->c == (verts + i)->c))
        {
          *(indices + i) = j;
          remaining--;
        }
        j++;
      }
      while (j < o->count);
    }
  }

  if ((o->count & 31) == 0)
  {
    u32 *cmd;
    o->old = o->cmd;
    cmd = o->cmd;
    o->cmd = cmd + 2;
    cmd[0] = 0x01020040;
    cmd[1] = osVirtualToPhysical(((u8 *) o->items) + (o->count << 4));
    vtx_pool_set_flags(((u8 *) o->items) + (o->count << 4), 32);
  }
  {
    u16 count = o->count;
    s32 end = count + remaining;
    if (!(((end - 1) / 32) != (count >> 5)))
    {
      for (i = 0; i < new_var; i++)
      {
        if (indices[i] == 0xffff)
        {
          unsigned int k = o->count++;
#ifdef PORT
          VtxIn *dv = (VtxIn *)((u8 *)o->items + (k << 4));
          dv->a = verts[i].a;
          dv->b = verts[i].b;
          dv->c = verts[i].c;
#else
          ((VtxIn *) ((k << 4) + ((s32) o->items)))->a = verts[i].a;
          ((VtxIn *) ((k << 4) + ((s32) o->items)))->b = verts[i].b;
          ((VtxIn *) ((k << 4) + ((s32) o->items)))->c = verts[i].c;
#endif
          indices[i] = k;
        }
      }

    }
    else
    {
      u32 *cmd;
      o->old = o->cmd;
      cmd = o->cmd;
      o->cmd = cmd + 2;
      cmd[0] = 0x01020040;
      count = (count >> 5) + 1;
      cmd[1] = osVirtualToPhysical(((u8 *) o->items) + (count << 9));
      count <<= 5;
      o->count = count;
      vtx_pool_set_flags(((u8 *) o->items) + ((count & 0xffe0) << 4), 32);
      for (i = 0; i < new_var; i++)
      {
        unsigned int k = o->count++;
#ifdef PORT
        VtxIn *dv = (VtxIn *)((u8 *)o->items + (k << 4));
        dv->a = verts[i].a;
        dv->b = verts[i].b;
        dv->c = verts[i].c;
#else
        ((VtxIn *) ((k << 4) + ((s32) o->items)))->a = verts[i].a;
        ((VtxIn *) ((k << 4) + ((s32) o->items)))->b = verts[i].b;
        ((VtxIn *) ((k << 4) + ((s32) o->items)))->c = verts[i].c;
#endif
        indices[i] = k;
      }

    }
  }
}
