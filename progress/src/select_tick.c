extern void *gSelectState;
void *find_object_by_id(s32);
s32 func_80047C2C(s32, u8);
void stream_obj_attach_texture_pack();

/* Runs the per-tick select step: the object's field at 0x178 is passed to func_80047C2C
 * along with the select state's counter at 0x232, which is then incremented. */
void select_tick(void) {
    stream_obj_attach_texture_pack();
    func_80047C2C(*(s32 *) ((u8 *) find_object_by_id(0) + 0x178), *(u8 *) ((u8 *) gSelectState + 0x232));
    *(u8 *) ((u8 *) gSelectState + 0x232) = (u8) (*(u8 *) ((u8 *) gSelectState + 0x232) + 1);
}
