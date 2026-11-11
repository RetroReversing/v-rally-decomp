typedef struct { s32 w[61]; } Blk;
typedef struct { u8 pad0[0xE]; s16 e; u8 pad1[2]; s16 x12; u8 pad2[0xA]; u16 x1E; u8 pad3[0xC]; u16 x2C; } Obj;
extern Obj *gRecords;
extern s32 D_800A123C;
extern u8 gOrderState[];
extern u8 gStreamState[];
extern Blk D_800C8214;
extern void func_8007C694(void);
extern void func_8007EA64(void);
extern s32 func_80084BF0(s32);
extern s32 func_80084DD4(s32);

/* Once the race is in its finishing state (x1E == 7), checks whether the
 * finish condition holds for this frame. The counter D_800A123C counts the
 * frames past it. When it holds, the record is reset to its defaults and the
 * next-state fields are loaded from the saved slots. */
void race_check_finish(void)
{
  s32 p1_buttons = 0;
  s32 p0_buttons;
  s32 finished;
  s32 frames;
  if (gRecords->x1E != 7) return;
  p0_buttons = func_80084BF0(0);
  if (func_80084DD4(1) != 0) p1_buttons = func_80084BF0(1);
  func_8007C694();
  if ((gRecords->x2C & 0x20) == 0) {
    finished = 0;
    if ((p1_buttons & 0x1000) == 0 && (p0_buttons & 0x1000) == 0) {
      frames = D_800A123C++;
      if (frames != 0x8CA && *(u16 *)(gOrderState + 0x2416) - 0x64 != *(u16 *)(gOrderState + 0x2414)) goto done;
    }
    finished = 1;
  } else {
    finished = 0;
    if ((p0_buttons & 0x1000) == 0) {
      frames = D_800A123C++;
      if (frames != 0x19) goto done;
    }
    finished = 1;
  }
  done:
  if (finished == 0) return;
  D_800A123C = 0;
  *(Blk *)gRecords = D_800C8214;
  gStreamState[0x7E72] = 0;
  gRecords->e = 1;
  func_8007EA64();
  gRecords->x12 = gStreamState[0x38F2];
  finished = gStreamState[0x38F0];
  *(s32 *)(gOrderState + 0x8030) = 5;
  gRecords->x1E = 0;
  gRecords->e = finished;
}
