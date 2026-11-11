typedef struct VertRec
{
  s16 v[17];
} VertRec;
typedef struct MeshOut
{
  void *dl[12];
  void *verts[12];
  s32 time[12];
  s16 dur[12];
  u16 nverts[12];
} MeshOut;
typedef struct MeshSrc
{
  u8 pad[16];
  s32 flags;
  u8 pad14[20];
  u8 lists_a[8];
  u8 lists_b[8];
  MeshOut *out;
} MeshSrc;
typedef struct VertPacket
{
  VertRec *ptr;
  s16 count;
  s16 zero;
} VertPacket;
extern s32 D_800B5B44;
extern void *poolAlloc(s32, s32);
extern void *gfx_get_dl(s32);
extern void gfx_set_dl(s32, void *);
extern void dl_emit_texture_chunk(s32);
extern void gfx_sync_render_state(s32, s32);
extern s32 func_80006060(s32);
extern void slot_update_list(void *, s32 *, s32 *, s32 *, s32);
extern void func_800197A4(void *, VertRec **, void *, s32 *, s32, void **);
extern void func_80056FE4(VertPacket *);
extern void func_80057270(void *, u16);
extern void gfx_draw_item_list(s32, VertPacket *, void *);
extern void heapFreeBlock(void *);

/* Builds the per-slot vertex and display-list data for one mesh. The two source
   lists are counted, one scratch block is allocated for all their records, then
   each of the 12 slots gets its records and a DL that loads them. */
void func_8001AAB4(MeshSrc *mesh)
{
  s32 count[12];
  s32 extra[12];
  VertRec *start[12];
  VertRec *end[12];
  void *sub[12];
  VertPacket packet;
  s32 total;
  s32 used;
  void *buf;
  s32 i;
  s32 h;
  u32 *dl;

  used = 0;
  mesh->out = poolAlloc(1, sizeof(MeshOut));
  total = 0;
  for (i = 0; i < 12; i++)
  {
    count[i] = 0;
    extra[i] = 0;
  }
  slot_update_list(mesh->lists_a, count, extra, &total, mesh->flags);
  slot_update_list(mesh->lists_b, count, extra, &total, mesh->flags);
  buf = poolAlloc(1, total * 6);
  for (i = 0; i < 12; i++)
  {
    if (count[i])
    {
      start[i] = poolAlloc(1, count[i] * sizeof(VertRec));
      end[i] = start[i];
    }
    else
    {
      start[i] = 0;
      end[i] = 0;
    }
    if (extra[i])
    {
      mesh->out->verts[i] = poolAlloc(1, extra[i] * 24);
      sub[i] = mesh->out->verts[i];
      mesh->out->nverts[i] = extra[i];
    }
    else
    {
      mesh->out->verts[i] = 0;
      mesh->out->nverts[i] = 0;
      sub[i] = 0;
    }
  }
  func_800197A4(mesh->lists_a, end, buf, &used, mesh->flags, sub);
  func_800197A4(mesh->lists_b, end, buf, &used, mesh->flags, sub);
  h = D_800B5B44;
  for (i = 0; i < 12; i++)
  {
    if (end[i] - start[i])
    {
      mesh->out->dl[i] = gfx_get_dl(h);
      mesh->out->time[i] = func_80006060(h);
      packet.ptr = start[i];
      packet.count = end[i] - start[i];
      packet.zero = 0;
      func_80056FE4(&packet);
      func_80057270(mesh->out->verts[i], mesh->out->nverts[i]);
      gfx_sync_render_state(h, 1);
      gfx_draw_item_list(h, &packet, buf);
      mesh->out->dur[i] = (func_80006060(h) - mesh->out->time[i]) >> 4;
      dl_emit_texture_chunk(h);
      dl = gfx_get_dl(h);
      dl[0] = 0xDF000000;
      dl[1] = 0;
      gfx_set_dl(h, dl + 2);
    }
    else
    {
      mesh->out->dl[i] = 0;
      mesh->out->time[i] = 0;
      mesh->out->dur[i] = 0;
    }
    if (start[i])
    {
      heapFreeBlock(start[i]);
    }
  }
  heapFreeBlock(buf);
}
