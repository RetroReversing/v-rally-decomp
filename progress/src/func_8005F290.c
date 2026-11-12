extern u32 gSelectStep;
extern s32 gSelectStepHandle;
extern s32 D_800A14BC[];
s32 func_80057810();
s32 object_free_blocks();
s32 slotSetSelected();

/* Advances the select step counter (1..3) for slot `slot`: selects it, releases the previous step
 * handle and stores the handle for the new step, looked up in D_800A14BC. Does nothing after step 3. */
s32 func_8005F290(s32 slot)
{
    u32 *stepPtr;
    u32 step;

    stepPtr = &gSelectStep;
    if (*stepPtr < 3) {
        if (*stepPtr == 0) {
            *stepPtr = 1;
        }
        step = *stepPtr;
        *stepPtr = step + 1;
        slotSetSelected(slot, step);
        object_free_blocks(gSelectStepHandle);
        gSelectStepHandle = func_80057810(D_800A14BC[gSelectStep]);
    }
    return 0;
}
