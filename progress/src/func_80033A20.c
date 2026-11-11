s32 UpdateRecordTimers();
s32 func_80033724();
extern s32 D_8009F4F0;
extern s32 D_8009F4F4;
extern s32 D_8009F4F8;
extern s32 D_8009F4FC;
extern s32 D_8009F510;
extern s32 D_8009F514;
extern s32 D_8009F520;
extern s32 D_8009F524;
extern s32 D_8009F528;
extern s32 D_8009F52C;
extern s32 D_8009F540;
extern s32 D_8009F544;
extern s32 D_8009F550;
extern s32 D_8009F554;
extern s32 D_8009F558;
extern s32 D_8009F55C;
extern s32 D_8009F570;
extern s32 D_8009F574;

/* Copies the sixteen per-slot settings from the settings block into the D_8009F4xx
 * globals. Each slot is 0x4C bytes apart. Times are stored in frames (seconds * 60, or
 * seconds * 25 for the last three), and percentages are scaled from 0..100 to 0..255.
 * Then it runs the two follow-up setup steps. */
void func_80033A20(void *settings)
{
  s32 fps;

  D_8009F4F0 = *(s32 *)((u8 *)settings + 0x90) * 0x3C;
  D_8009F4F4 = *(s32 *)((u8 *)settings + 0xDC) * 0x3C;
  D_8009F4F8 = (*(s32 *)((u8 *)settings + 0x128) * 0xFF) / 100;
  D_8009F4FC = (*(s32 *)((u8 *)settings + 0x174) * 0xFF) / 100;
  D_8009F510 = *(s32 *)((u8 *)settings + 0x1C0);
  D_8009F520 = *(s32 *)((u8 *)settings + 0x20C) * 0x3C;
  D_8009F524 = *(s32 *)((u8 *)settings + 0x258) * 0x3C;
  D_8009F528 = (*(s32 *)((u8 *)settings + 0x2A4) * 0xFF) / 100;
  D_8009F52C = (*(s32 *)((u8 *)settings + 0x2F0) * 0xFF) / 100;
  D_8009F540 = *(s32 *)((u8 *)settings + 0x33C);
  D_8009F550 = *(s32 *)((u8 *)settings + 0x388) * 0x3C;
  D_8009F554 = *(s32 *)((u8 *)settings + 0x3D4) * 0x3C;
  D_8009F558 = (*(s32 *)((u8 *)settings + 0x420) * 0xFF) / 100;
  D_8009F55C = (*(s32 *)((u8 *)settings + 0x46C) * 0xFF) / 100;
  D_8009F570 = *(s32 *)((u8 *)settings + 0x4B8);
  fps = 0x19; D_8009F514 = *(s32 *)((u8 *)settings + 0x504) * fps;
  D_8009F544 = *(s32 *)((u8 *)settings + 0x504) * fps;
  D_8009F574 = *(s32 *)((u8 *)settings + 0x504) * fps;
  func_80033724();
  UpdateRecordTimers();
}
