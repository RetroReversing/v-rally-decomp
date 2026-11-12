extern void copy_item_label(void *, void *);
typedef struct { u8 b[8]; } Buf8;

extern u8 *gSceneSlot0;
extern f32 D_8009BB94, D_8009BB98, D_8009BB9C, D_8009BBA0;
extern u16 D_8009FF88, D_8009FF8A, D_8009FF8C, D_8009FF8E;
extern u16 D_8009FF90, D_8009FF92, D_8009FF94, D_8009FF96;
extern u16 D_8009FF98, D_8009FF9A;
extern char D_800A4C60[], D_800A4C68[], D_800A4C74[], D_800A4C7C[], D_800A4C88[];
extern void *g_camera;

/* Creates the five menu objects for this screen. Each object takes its
 * position pair from D_8009FF88..D_8009FF9A and its label from D_800A4Cxx,
 * and gets a layout type at +12. The first object reads its rect from
 * gSceneSlot0; the second uses the 250/2000 range pair. The camera object
 * is stored in g_camera. */
void func_80041320(void) {
    s32 kind;
    void *obj;
    u16 slot;
    u16 rx, ry, rw, rh;
    u8 rect[8];

    kind = 2;
    slot = (u16)kind;
    rx = *(u16 *)(gSceneSlot0 + 0);
    ry = *(u16 *)(gSceneSlot0 + 2);
    rw = *(u16 *)(gSceneSlot0 + 4);
    rh = *(u16 *)(gSceneSlot0 + 6);
    *(u16 *)(rect + 0) = rx;
    *(u16 *)(rect + 2) = ry;
    *(u16 *)(rect + 4) = rw;
    *(u16 *)(rect + 6) = rh;
    *(Buf8 *)&rect[0] = *(Buf8 *)gSceneSlot0;

    obj = func_80042078(rect, 5, D_8009FF88, D_8009FF8A, slot);
    copy_item_label(obj, D_800A4C68);
    {
        u8 *p;
        p = gSceneSlot0;
        *(s32 *)((u8 *)obj + 12) = 0;
        *(Buf8 *)&rect[0] = *(Buf8 *)p;
    }
    obj = func_80042078(rect, 2, D_8009FF94, D_8009FF96, slot);
    copy_item_label(obj, D_800A4C74);
    *(s32 *)((u8 *)obj + 12) = 3;
    *(f32 *)((u8 *)obj + 0x18C) = 250.0f;
    *(f32 *)((u8 *)obj + 0x190) = 2000.0f;
    D_8009BB94 = 250.0f;
    D_8009BB9C = 2000.0f;
    D_8009BB98 = 250.0f;
    D_8009BBA0 = 2000.0f;

    obj = func_80042078(rect, 2, D_8009FF8C, D_8009FF8E, slot);
    copy_item_label(obj, D_800A4C7C);
    *(s32 *)((u8 *)obj + 12) = 1;

    g_camera = obj;
    obj = func_80042078(rect, 5, D_8009FF90, D_8009FF92, slot);
    copy_item_label(obj, D_800A4C88);
    *(s32 *)((u8 *)obj + 12) = kind;

    obj = func_80042078(rect, 2, D_8009FF98, D_8009FF9A, slot);
    copy_item_label(obj, D_800A4C60);
    *(s32 *)((u8 *)obj + 12) = 4;
}
