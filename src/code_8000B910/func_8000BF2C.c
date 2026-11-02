#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct {
    s16 x;
    s16 y;
    u8 w;
    u8 h;
    u8 pad[10];
} BFEnt;
typedef struct {
    s16 x[4];
    s16 y[4];
} BFQuad;
typedef struct {
    u8 unk0;
    u8 count;
    u8 pad[6];
    BFEnt ents[1];
} BFArg;
typedef struct {
    u8 pad0[8];
    void *ptr;
} BFItem;
typedef struct {
    u8 pad0[8];
    u8 flag;
    u8 pad9[7];
    BFItem *item;
    u8 pad14[4];
    BFEnt *data;
    BFQuad quads[128];
    f32 scale[3];
} BFObj;
extern s16 func_8000BF10(s32);
extern void *func_8007EAA0(s32, s32);
extern u8 *func_8008E13C(u8 *, u8 *, s32);

BFObj *func_8000BF2C(BFArg *arg0)
{
    BFObj *obj;
    BFItem *item;
    u8 count;
    u8 i;
    u32 size;
    BFQuad q;

    obj = func_8007EAA0(1, sizeof(BFObj));
    item = func_8007EAA0(1, 0x1C);
    count = arg0->count;
    
    size = count * sizeof(BFEnt);
    item->ptr = &arg0->ents[count];
    obj->item = item;
    obj->data = func_8007EAA0(1, size);
    func_8008E13C((i = 0, (u8 *)obj->data), (u8 *)arg0->ents, size);
    for (; i < count; i++) {
        obj->data[i].x = func_8000BF10(obj->data[i].x);
        obj->data[i].y = func_8000BF10(obj->data[i].y);
    }
    obj->flag = 0;
    for (i = 0; i < 3; i++) {
        obj->scale[i] = 1.0f;
    }
    for (i = 0; i < count; i++) {
        s16 x = obj->data[i].x;
        if (x != -128) {
            obj->quads[i].x[0] = x;
            obj->quads[i].y[0] = obj->data[i].y + obj->data[i].h;
            obj->quads[i].x[1] = obj->data[i].x + obj->data[i].w;
            obj->quads[i].y[1] = obj->data[i].y + obj->data[i].h;
            obj->quads[i].x[2] = obj->data[i].x + obj->data[i].w;
            obj->quads[i].y[2] = obj->data[i].y;
            obj->quads[i].x[3] = obj->data[i].x;
            obj->quads[i].y[3] = obj->data[i].y;
        }
        q = obj->quads[i];
    }
    return obj;
}

