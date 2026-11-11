extern f32 vtx_scale[];
void func_800562D0(void *, void *, s32, void *, s32);
void emit_model_verts(s32, void *);

/* Emits one object's vertices into the output buffer when the object is active and has a
 * model with entries: runs the entry handlers, then writes each vertex as three s16
 * coordinates scaled by vtx_scale, and advances the running vertex count *vert_index. */
void func_80019440(u8 *obj, void *ctx, s16 *out_verts, s32 *vert_index, s32 mode)
{
  void *ents;
  s32 i;
  s16 *dst;
  if ((*((s16 *) (obj + 0x8))) != (-1))
  {
    if ((*((u16 *) ((*((u8 **) (obj + 0x18))) + 0x10))) != 0)
    {
      ents = *((void **) ((*((u8 **) (obj + 0x18))) + 0x14));
      func_800562D0(ctx, ents, *vert_index, *((void **) (obj + 0x14)), *((u16 *) (obj + 0x1C)));
      emit_model_verts(mode, obj);
      for (i = 0; i < (*((s16 *) (obj + 0xA))); i++)
      {
        dst = out_verts + (((*vert_index) + i) * 3);
        dst[0] = (s16) (((f32) (*((s16 *) ((*((u8 **) ((*((u8 **) (obj + 0x18))) + 0xC))) + (i * 4))))) * vtx_scale[0]);
        dst[2] = (s16) (((f32) (*((s16 *) (((*((u8 **) ((*((u8 **) (obj + 0x18))) + 0xC))) + (i * 4)) + 2)))) * vtx_scale[2]);
        dst[1] = (s16) (((f32) (*((s16 *) ((*((u8 **) (obj + 0x10))) + (i * 2))))) * vtx_scale[1]);
      }

      *vert_index += *((s16 *) (obj + 0xA));
    }
  }
}
