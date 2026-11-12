void *find_object_by_id(s32);
s32 set_object_field_by_id(void *, s32);
extern void **gCarList;
extern s32 stream_state;

/* Walks the car list gCarList. For each car whose word at +0x48 (dereferenced) is below 4, calls
 * set_object_field_by_id with the next odd and even ids. Then clears word +0x24 of object 0 and of the object
 * whose id is (stream byte +0xF) * 2 + 1. */
void func_800422C8(void) {
    s32 temp_a1;
    s32 var_s1;
    s32 var_s2;
    u8 temp_s0;
    void *var_s0;

    var_s0 = *gCarList;
    if (var_s0 != NULL) {
        var_s2 = 0;
        var_s1 = 1;
        do {
            if (**((s32 **) ((s8 *) var_s0 + 0x48)) < 4) {
                var_s2 += 2;
                temp_a1 = var_s1;
                var_s1 += 2;
                set_object_field_by_id(var_s0, temp_a1);
                set_object_field_by_id(var_s0, var_s2);
            }
            var_s0 = *((void **) ((s8 *) var_s0 + 4));
        } while (var_s0 != NULL);
    }
    temp_s0 = *((u8 *) ((s8 *) (*((void **) ((s8 *) &stream_state + 0x32F2))) + 0xF));
    *((s32 *) ((s8 *) find_object_by_id(0) + 0x24)) = 0;
    *((s32 *) ((s8 *) find_object_by_id((temp_s0 * 2) | 1) + 0x24)) = 0;
}
