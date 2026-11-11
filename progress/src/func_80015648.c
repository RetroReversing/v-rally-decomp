/* r180b */
extern f32 vtx_scale[];
void func_80015508();
/* Registers a vertex block (arg0: count at +4, 0x34-byte vertices from +0) in the slot of
 * object arg1 (slot index at +0x22), then scales each vertex's six fixed-point values by
 * the vtx_scale factors. */
void func_80015648(void *vtxBlock, void *obj)
{
char __repair_stack_padding[8];
  char *vert;
  s32 i;
  f32 *scale;
  char *slot;
  s32 count;
  int new_var;
  func_80015508();
  slot = ((char *) obj) + (((*((u16 *) (((char *) obj) + 0x22))) * 0x38) + 0x3C);
  *((void **) (slot + 0x18)) = vtxBlock;
  vert = *((char **) vtxBlock);
  i = 0;
  new_var = 0;
  count = *((u16 *) (((char *) vtxBlock) + 4));
  if (count <= 0)
  {
  }
  else
  {
    scale = vtx_scale;
loop_top:
    *((s32 *) (vert + 0xC)) = (s32) (((f32) (*((s32 *) (vert + 0xC)))) * scale[0]);
    *((s32 *) (vert + 0x10)) = (s32) (((f32) (*((s32 *) (vert + 0x10)))) * scale[1]);
    *((s32 *) (vert + 0x14)) = (s32) (((f32) (*((s32 *) (vert + 0x14)))) * scale[2]);
    *((s32 *) (vert + 0x18)) = (s32) (((f32) (*((s32 *) (vert + 0x18)))) * scale[0]);
    *((s32 *) (vert + 0x1C)) = (s32) (((f32) (*((s32 *) (vert + 0x1C)))) * scale[1]);
    *((s32 *) (vert + 0x20)) = (s32) (((f32) (*((s32 *) (vert + 0x20)))) * scale[2]);
    count = *((u16 *) (((char *) vtxBlock) + 4));
    i += 1;
    if (i >= count) {
      vert += 0x34;
      goto loop_done;
    }
    vert += 0x34;
    goto loop_top;
loop_done:;
  }
}
