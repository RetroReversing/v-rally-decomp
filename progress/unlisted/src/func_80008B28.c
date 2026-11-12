/* Stores the eight 16-bit coordinates (each shifted left 6) into the 0x10-byte entry at index `index` of the
 * table at obj+0x70. Arguments 2-3 are passed in registers, 4-9 come from the stack (their high halves are used). */
void func_80008B28(void *obj, s32 index, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    s32 temp_a2;
    s32 temp_a3;

    *(s16 *)((char *)*(s32 *)((char *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x8) = (s16) ((temp_a2 = arg2 & 0xFFFF) << 6);
    temp_a3 = arg3 & 0xFFFF;
    *(s16 *)((char *)*(s32 *)((char *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0xA) = (s16) (temp_a3 << 6);
    *(s16 *)((char *)*(s32 *)((char *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x18) = (s16) (((u16 *)&arg4)[1] << 6);
    *(s16 *)((char *)*(s32 *)((char *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x1A) = (s16) (((u16 *)&arg5)[1] << 6);
    *(s16 *)((char *)*(s32 *)((char *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x28) = (s16) (((u16 *)&arg6)[1] << 6);
    *(s16 *)((char *)*(s32 *)((char *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x2A) = (s16) (((u16 *)&arg7)[1] << 6);
    *(s16 *)((char *)*(s32 *)((char *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x38) = (s16) (((u16 *)&arg8)[1] << 6);
    *(s16 *)((char *)*(s32 *)((char *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x3A) = (s16) (((u16 *)&arg9)[1] << 6);
}
