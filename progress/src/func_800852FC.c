s32 ctrl_set_field();

typedef struct { s32 field; s32 value; } CtrlPair;

/* Applies each (field, value) pair in the table of `count` entries to the controller
 * context `ctx` via ctrl_set_field. */
void func_800852FC(u8 ctx, u8 *pairs, u32 count) {
    u8 i;

    i = 0;
    if (count != 0) {
        do {
            ctrl_set_field(ctx, *(s32 *)(pairs + i * 8), *(s32 *)(pairs + i * 8 + 4));
            i++;
        } while (i < count);
    }
}
