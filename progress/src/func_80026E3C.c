void func_8002D740(void *arg0, s32 *arg1, s32 *arg2);

/* Adds the input step vector to the object body's +0x5C accumulator, then runs
 * func_8002D740 to convert it and adds the converted vector to the +0x70 accumulator. */
void func_80026E3C(u8 *object, void *arg1, s32 *step) {
    s32 converted[3];
    u8 *body;

    body = *(u8 **)(object + 0x58);
    *(s32 *)(body + 0x5C) += step[0];
    *(s32 *)(body + 0x60) += step[1];
    *(s32 *)(body + 0x64) += step[2];
    func_8002D740(arg1, step, converted);
    body = *(u8 **)(object + 0x58);
    *(s32 *)(body + 0x70) += converted[0];
    *(s32 *)(body + 0x74) += converted[1];
    *(s32 *)(body + 0x78) += converted[2];
}
