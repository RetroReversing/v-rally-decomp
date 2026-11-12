#ifdef PORT
extern u8 *gMainObj;
void obj_set_flag_slot(void *, s32);
void init_obj_state(void *);
#else
extern s32 gMainObj;
#endif

/* Resets the main object: sets its flag slot 9, then re-initialises its state. */
void obj_main_reset(void) {
    obj_set_flag_slot(gMainObj, 9);
    init_obj_state(gMainObj);
}
