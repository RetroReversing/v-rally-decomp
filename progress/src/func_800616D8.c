void *poolAlloc();
extern void *gSelectBuffer;
extern f64 D_800A5550;

/* Allocates a 12-byte select record from the pool and fills it from the order
 * record: +0 s16 from +0x90, +2 s16 from +0xDC, +4 f32 from +0x128 scaled by
 * D_800A5550, +8 s8 from +0x174. The record becomes gSelectBuffer. */
void func_800616D8(void *order)
{
  void *rec;
  s32 flag;
  f64 scale;
  rec = poolAlloc(1, 0xC);
  scale = D_800A5550;
  *((s16 *) (((char *) rec) + 0)) = (s16) (*((s32 *) (((char *) order) + 0x90)));
  *((s16 *) (((char *) rec) + 2)) = (s16) (*((s32 *) (((char *) order) + 0xDC)));
  *((f32 *) (((char *) rec) + 4)) = (f32) (((f64) (*((s32 *) (((char *) order) + 0x128)))) * scale);
  flag = *((s32 *) (((char *) order) + 0x174));
  gSelectBuffer = rec;
  *((s8 *) (((char *) rec) + 8)) = (s8) flag;
}
