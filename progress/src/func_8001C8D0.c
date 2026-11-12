extern s32 gMainObj;
s32 obj_set_flag_slot(s32, s32);
s32 func_800201B0(s32, s32);

/* Clears flag slot 0 of the main object, then calls func_800201B0 with index and the main object. */
void func_8001C8D0(s32 index) {
    obj_set_flag_slot(gMainObj, 0);
    func_800201B0(index, gMainObj);
}
