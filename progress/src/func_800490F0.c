extern s8 D_800B5AF0;
extern s8 D_800B5AF1;
extern s8 D_800B5AF2;
extern u8 D_800B5AF3;
extern u16 D_800C3598;
extern u16 D_800C359A;
extern u16 D_800C359C;
extern u16 D_800C359E;
extern u16 D_800B7074;
extern u16 D_800B7076;
extern u16 D_800B7078;
extern u16 D_800B707A;
extern s32 g_camera;
s32 gfx_draw_fill_rect();
s32 find_object_by_id();

/* Stores the object's four bounds (fields +8, +A, +C, +E) in two rectangle sets, one inset by 0x20,
 * clears the shade bytes, looks up the object by id and draws both fills. */
void func_800490F0(void *obj, s32 id) {
    s8 *shade;
    u16 *rectB;
    u16 *rectA;
    u16 y0;

    shade = &D_800B5AF0;
    *shade = 0;
    D_800B5AF1 = 0;
    D_800B5AF2 = 0;
    D_800B5AF3 = 0xFF;
    rectA = &D_800C3598;
    *rectA = *(u16 *)((char *)obj + 8);
    y0 = *(u16 *)((char *)obj + 0xA);
    D_800C359C = 0x20;
    D_800C359A = y0;
    D_800C359E = *(u16 *)((char *)obj + 0xE);
    rectB = &D_800B7074;
    *rectB = *(u16 *)((char *)obj + 0xC) - 0x20;
    D_800B7076 = *(u16 *)((char *)obj + 0xA);
    D_800B7078 = *(u16 *)((char *)obj + 0xC);
    D_800B707A = *(u16 *)((char *)obj + 0xE);
    g_camera = find_object_by_id(((id & 0xFFFF) * 2) | 1);
    gfx_draw_fill_rect(obj, rectA, shade);
    gfx_draw_fill_rect(obj, rectB, shade);
}
