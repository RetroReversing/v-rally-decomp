typedef struct 
{
  u8 pad[0x178];
  struct 
  {
    u8 pad[12];
    s16 w;
    s16 h;
  } *view;
} Obj;
typedef struct Node
{
  u8 pad[12];
  void *p;
} Node;
typedef struct 
{
  u8 pad[6];
  u16 x;
  u16 y;
} Cam;
typedef struct Link
{
  u8 pad[4];
  struct Link *next;
} Link;
extern void *gSceneSlot2;
extern u8 *g_ent_list;
extern Node **D_800C60D4;
extern u8 *g_camera;
extern void guMtxIdentF(void *);
extern void obj_mtx_visible(s32, void *, void *);
extern f32 func_8001BE68(void *, f32, f32, f32, f32 *, f32 *, f32 *);
extern void *func_80005C48(void *);
extern void draw_sprite_obj(void *, s16, s16, void *, s32, s32, s32, s32, s32, s32);
extern void func_80036FD8(void *, void *);
extern void place_elem_on_line(void *, void *, void *);

/* Draws the marker for obj when it is on screen and in front of the camera:
 * projects obj's position to screen coordinates, checks the z-buffer, and if
 * the spot is visible emits the marker's sprite and its line-strip. */
void func_800376C8(s32 unused0, Obj *obj)
{
    f32 mtx[4][4];
    f32 ndcX;
    f32 ndcY;
    f32 ndcZ;
    f32 eyeX = *((f32 *) (g_ent_list + 0x38));
    f32 eyeY = *((f32 *) (g_ent_list + 0x3c));
    f32 eyeZ = *((f32 *) (g_ent_list + 0x40));
    u8 *nextPtr;
    u16 *zbuf;
    Node *list;
    Node *tail;
    f32 viewW;
    u8 count;
    Link *link;
    u16 sx;
    u16 sy;
    u16 ty;
    u16 zi;
    f32 depth;

    guMtxIdentF(mtx);
    obj_mtx_visible(0, ((u8 *) obj) + 0x38, mtx);
    depth = func_8001BE68(((u8 *) obj) + 0xb8, eyeX, eyeY, eyeZ, &ndcX, &ndcY, &ndcZ);
    if (((((ndcX < 1.0f) && (ndcX > (-1.0f))) && (ndcY < 1.0f)) && (ndcY > (-1.0f))) && (((f64) depth) <= 0.0))
    {
        list = *D_800C60D4;
        zbuf = func_80005C48(gSceneSlot2);
        viewW = (f32) obj->view->w;
        sx = (u32) (((ndcX + 1.0f) * ((f32) obj->view->w)) * 0.5f);
        sy = (u32) ((ndcY + 1.0f) * (((f32) obj->view->h) * 0.5f));
        ty = 160 - sy;
        zi = sx + (((u16) ty) * obj->view->w);
        if ((zbuf[zi] > 0xfffa) & (((u16) ty) < 160))
        {
            Node *shape = *((Node **) (((u8 *) list) + 12));
            Cam *camera = *((Cam **) (((u8 *) shape) + 0x1c));
            draw_sprite_obj(*((void **) (g_camera + 0x178)), (s16) (sx - camera->x), (s16) (ty - camera->y), ((u8 *) shape) + 16, 8, 100, ((u8 *) list)[0x16], ((u8 *) list)[0x17], ((u8 *) list)[0x18], 255);
            nextPtr = ((u8 *) list) + 4;
            tail = *((Node **) nextPtr);
            *((s16 *) (((u8 *) list) + 16)) = sx;
            *((s16 *) (((u8 *) list) + 18)) = ty;
            func_80036FD8(list, tail);
            link = *((Link **) (((u8 *) tail) + 4));
            count = 4;
            do
            {
                place_elem_on_line(list, tail, link);
                link = link->next;
            }
            while ((count--) & 255);
            place_elem_on_line(list, tail, link);
        }
    }
}
