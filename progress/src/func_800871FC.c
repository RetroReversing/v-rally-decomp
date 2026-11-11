typedef struct
{
  s32 data;
  s16 size;
} AudioReq;
typedef struct
{
  s32 buf_virt;
  s16 size;
  s16 pad6;
  s32 x8;
  s32 xC;
  s32 x10;
  s32 x14;
  s32 x18;
  s32 x1C;
  s32 x20;
  s32 x24;
  s32 x28;
  s32 x2C;
  s32 x30;
  s32 x34;
  s32 x38;
  s32 x3C;
  s32 x40;
  s32 x44;
  s32 x48;
  void *list4C;
  s16 n50;
  s16 n52;
} AudioTask;
extern u32 D_800A1BAC;
extern s32 D_800A73E0[];
extern s32 gOrderState[];
extern s32 D_800C8320;
extern s32 D_80001D10;
extern s32 D_80001DE0;
extern s32 D_8009AAB0;
void func_80087114(void);
s32 osVirtualToPhysical(s32);
void ai_dma_start(s32, s32);
u32 func_8008A590(void);
s32 alAudioFrame(s32, s32 *, s32, s16);
void taskRecvMsg(s32);
void osSetThreadPri(s32, s32);
void func_8007F798(s32, s32, void *);
static inline s32 *getSlot(void)
{
  return &gOrderState[(0x2278 / 4) + D_800A1BAC % 3];
}

/* Runs one audio frame into the task's buffer and fills in the task record.
 * The buffer size follows the DMA budget (clamped to a minimum). Returns 1
 * when a frame was produced, 0 when the audio frame had no samples. */
s32 func_800871FC(AudioTask *task, AudioReq *req)
{
  s32 *slot;
  s32 *limit;
  s32 samples[2];
  u8 *base;
  s32 phys;
  s32 wrote;
  s32 frame;
  s16 count;
  s16 req_size;

  func_80087114();
  phys = osVirtualToPhysical(task->buf_virt);
  if (req != NULL)
  {
    req_size = req->size;
    ai_dma_start(req->data, 2 * (2 * req_size));
  }
  count = (s16) (((D_800A73E0[0x4570 / 4] - (func_8008A590() >> 2)) + 0x100) & 0xFFF0);
  task->size = count;
  limit = &D_800A73E0[0x4574 / 4];
  if (((u32) count) < ((u32) (*limit)))
  {
    task->size = (s16) (*limit);
  }
  slot = &gOrderState[(0x2278 / 4) + D_800A1BAC % 3];
  wrote = alAudioFrame(*slot, samples, phys, task->size);
  if (samples[0] == 0)
  {
    return 0;
  }
  {
    task->list4C = ((u8 *) task) + 0x58;
    task->n50 = 4;
    task->n52 = 0;
    slot = getSlot();
    task->x38 = *slot;
    frame = *slot;
    base = (u8 *) (&D_80001D10);
    task->x8 = 2;
    task->x14 = (s32) (((u8 *) (&D_80001DE0)) - base);
    task->x18 = (s32) (base + 0xd0);
    task->x20 = (s32) (&D_8009AAB0);
    task->x10 = (s32) (&D_80001D10);
    task->xC = 0;
    task->x24 = 0x800;
    task->x28 = 0;
    task->x2C = 0;
    task->x30 = 0;
    task->x34 = 0;
    task->x40 = 0;
    task->x44 = 0;
    task->x3C = ((wrote - frame) >> 3) << 3;
    taskRecvMsg(*(s32 *) 0x800C8320);
    osSetThreadPri(gOrderState[0x2290 / 4], 6);
    func_8007F798(0x26, 0, ((u8 *) task) + 8);
    D_800A1BAC++;
    return 1;
  }
  return 0;
}
