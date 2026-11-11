s32 mat3x3_from_euler();

/* Copies three s16 values from vec_in into a local, passes it with the object's
 * sub-block at +0x40 to mat3x3_from_euler, then stores three s32 values from
 * vals into that block at +0x14. The object's pointer at +0x5C holds the block. */
void func_80023134(void *obj, s32 *vals, s32 *vec_in) {
    s16 tmp[3];
    s32 *var_s1;
    u32 var_v1;
    void *var_s0;

    var_s0 = *(void **)((char *)obj + 0x5C);
    tmp[0] = vec_in[0];
    var_s1 = vals;
    tmp[1] = vec_in[1];
    tmp[2] = vec_in[2];
    var_s0 += 0x40;
    mat3x3_from_euler(tmp, var_s0);
    var_v1 = 0;
    do {
        *(s32 *)((char *)var_s0 + 0x14) = *var_s1;
        var_s1 += 1;
        var_v1 += 1;
        var_s0 += 4;
    } while (var_v1 < 3U);
}
