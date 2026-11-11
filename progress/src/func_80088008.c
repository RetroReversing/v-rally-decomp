typedef struct S88008 {
    u8 pad00[0x30];
    s32 pos_z;
    s32 pos_y;
    u8 pad38[0x40];
    s32 base_x;
    u8 pad7C[4];
    s32 base_z;
    s32 base_y;
    u8 pad88[0x12];
    s16 dirty_y;
    s16 dirty_z;
} S88008;

/* Decodes three big-endian 16-bit values from the stream at data. Y and Z are stored
 * as offsets from base_y and base_z (with dirty flags set); the X value is added to base_x
 * and returned. */
s32 func_80088008(S88008 *obj, u8 *data)
{
    s32 x, y, hi_x, lo_x, hi_y, lo_y, hi_z, lo_z;

    x = *data++;
    hi_x = *data++;
    hi_y = *data++;
    lo_y = *data++;
    obj->dirty_y = 1;
    y = hi_y << 8;
    y += lo_y;
    obj->pos_y = obj->base_y + y;
    hi_z = *data++;
    lo_z = *data++;
    y = hi_z << 8;
    y += lo_z;
    obj->dirty_z = 1;
    obj->pos_z = obj->base_z + y;
    x <<= 8;
    x += hi_x;
    return obj->base_x + x;
}
