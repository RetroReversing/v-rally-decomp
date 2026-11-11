typedef struct { s32 x, y, z, pad[2]; } VRFuncRec;
typedef struct { u8 pad00[8]; void *src[4]; VRFuncRec dst[4]; } VRFuncTable;
typedef struct { u8 pad00[0x38]; f32 x, y, z; } VRFuncSrc;

/* Copies the x, y, z position of each of the four source records at obj+0x88 into its dst record, truncated to integers. */
void func_800208DC(u8 *arg0)
{
    VRFuncTable *table;
    VRFuncSrc *src;
    VRFuncRec *dst;
    u32 i;

    i = 0;
    do {
        table = *(VRFuncTable **)(arg0 + 0x88);
        src = (VRFuncSrc *)table->src[i];
        dst = &table->dst[i];
        dst->x = src->x;
        dst->y = src->y;
        i++;
        dst->z = src->z;
    } while (i < 4);
}
