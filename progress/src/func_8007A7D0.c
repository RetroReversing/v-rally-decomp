typedef struct Obj { void *next; u16 id,x,y; u8 a,b,c,d,e; u8 padf; f32 sx,sy; u8 pad18[2]; u8 active; } Obj;
typedef struct { u8 pad[0x1e4]; void *p; u8 pad2[0x4f]; u8 mode; u8 pad3[0x11]; u8 flag; } State;
typedef struct { u8 pad[6]; u16 x,y; } Dim;
typedef struct { Dim *d; } DimPtr;
typedef struct { u8 pad[4]; DimPtr *p; } World;
extern State *gSelectState; extern s32 D_800D05D8;
void *textObjGet(u32);
extern void select_load_texture_pack(void);
extern s32 func_8004CEB4(s32, void*, u16*, s32,s32,s32,s32,s32,s32);

/* Text overlay setup: makes seven text objects from the list at 0x31 active, with
 * ids 0x23E + mode*7 + i. When the flag is set, copies the mode's template object
 * into object 0x39 and draws it with the current dimension scaled by its sx/sy. */
void func_8007A7D0(void)
{
    u16 rect[4];
    Obj *obj;
    Obj *dst;
    u8 i;
    World *world;

    if (!gSelectState->p) select_load_texture_pack();
    obj = textObjGet(0x31);
    i = 0;
    do {
        obj->active = 1;
        obj->id = (u16) (i + (gSelectState->mode * 7 + 0x23e));
        obj = obj->next;
        i++;
    } while ((u8) i < 7);
    if (gSelectState->flag) {
        obj = textObjGet(gSelectState->mode + 2);
        dst = textObjGet(0x39);
        dst->x = obj->x;
        dst->y = obj->y;
        dst->b = obj->b;
        dst->c = obj->c;
        dst->d = obj->d;
        dst->e = obj->e;
        dst->sx = obj->sx;
        dst->sy = obj->sy;
        dst->a = obj->a;
        dst->id = obj->id;
        obj = textObjGet(gSelectState->mode + 0x16);
        world = (World *) gSelectState->p;
        rect[0] = obj->x;
        rect[1] = obj->y;
        rect[2] = (s16) ((f32) world->p->d->x * obj->sx);
        rect[3] = (s16) ((f32) world->p->d->y * obj->sy);
        func_8004CEB4(D_800D05D8, ((World *) gSelectState->p)->p->d, rect, 0, obj->b, obj->c, obj->d, obj->e, 0);
    }
}
