extern u32 gSelectStep;
extern s32 gSelectStepHandle;
extern s32 D_800A14BC[];
s32 func_80057810();
s32 func_800578E0();
s32 slot_set_selected();

/* Steps the select state back one step while it is at least 2: selects the slot for the new step, frees the old handle and reloads it from D_800A14BC for the current step. Always returns 0. */
s32 selectStepBack(s32 slot)
{
  u32 *step;
  step = &gSelectStep;
  if (*step >= 2)
  {
    *step = *step - 1;
    slot_set_selected(slot, *step - 1);
    func_800578E0(gSelectStepHandle);
    gSelectStepHandle = func_80057810(D_800A14BC[gSelectStep]);
  }
  return 0;
}
