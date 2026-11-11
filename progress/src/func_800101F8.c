extern f32 gCamTiltOffset;
extern f32 gCamPanOffset;

/* Nudges the camera offsets from the C-button bits in buttons: C-up and
 * C-down change the tilt by 2, C-left and C-right change the pan by 1. */
void func_800101F8(s32 buttons)
{
  f32 *temp_v0;

  if (buttons & 0x800)
  {
    temp_v0 = &gCamTiltOffset;
    *temp_v0 = *temp_v0 + 2.0f;
  }
  if (buttons & 0x400)
  {
    temp_v0 = &gCamTiltOffset;
    *temp_v0 = *temp_v0 - 2.0f;
  }
  if (buttons & 0x200)
  {
    temp_v0 = &gCamPanOffset;
    *temp_v0 = *temp_v0 + 1.0f;
  }
  if (buttons & 0x100)
  {
    temp_v0 = &gCamPanOffset;
    *temp_v0 = *temp_v0 - 1.0f;
  }
}
