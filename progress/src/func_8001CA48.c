extern s32 gMainObj;
s32 obj_set_flag_slot(s32, s32);
s32 func_80023F58(s32, s32);

/* Clears flag slot 4 of the main object, then calls func_80023F58 with index and the main object. */
void func_8001CA48(s32 index) {
    obj_set_flag_slot(gMainObj, 4);
    func_80023F58(index, gMainObj);
}
