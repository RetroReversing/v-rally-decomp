typedef struct { u8 v[6]; } Bytes6;
typedef struct { u8 v[6][3]; } Bytes18;
extern Bytes6 D_800A4A98;
extern Bytes6 D_800A4AA0;
extern Bytes18 D_800A4AA8;
extern void *D_800C60D4;
typedef struct { u8 pad[4]; void **data; } Res;
typedef struct { u8 pad[0x10]; u8 obj[0x94]; Res *res; } Obj;
typedef struct { u8 pad[0xC]; Obj *obj; s16 x; s16 y; u8 a; u8 b; u8 r; u8 g; u8 bl; } Spr;
extern void *func_80080440(void);
extern Spr *func_800801D0(void *, s32);
extern Res *func_80034FF0(void *, s32);
extern Obj *func_8007EAA0(s32, s32);
extern void func_8000A5EC(void *, void *, s32, s32, s32, s32, s32);

void func_80036C48(u8 *p)
{
    Bytes6 a;
    Bytes6 b;
    Bytes18 c;
    u8 j;

    a = D_800A4A98;
    b = D_800A4AA0;
    c = D_800A4AA8;
    j = 0;
    D_800C60D4 = func_80080440();

    {
        Spr *n;
        Res *q;
        Obj *t;
        n = func_800801D0(D_800C60D4, 28);
        q = func_80034FF0(p + 0x2AC, 0);
        t = func_8007EAA0(6, 176);
        n->obj = t;
        t->res = q;
        func_8000A5EC(n->obj->obj, *q->data, 1, 0, 0, 0, 0);
        n->a = 100;
        n->b = 0;
        n->r = 255;
        n->g = 255;
        n->bl = 255;
        n->x = 128;
        n->y = 128;
    }
    {
        Spr *n;
        Res *q;
        Obj *t;
        n = func_800801D0(D_800C60D4, 28);
        q = func_80034FF0(p + 0x390, 0);
        t = func_8007EAA0(6, 176);
        n->obj = t;
        t->res = q;
        func_8000A5EC(n->obj->obj, *q->data, 1, 0, 0, 0, 0);
        n->x = 0;
        n->y = 0;
        n->a = 100;
        n->b = 0;
        n->r = 255;
        n->g = 255;
        n->bl = 255;
    }
    do {
        Spr *n;
        Res *q;
        Obj *t;
        q = func_80034FF0(p + 0x2F8, 0);
        n = func_800801D0(D_800C60D4, 28);
        t = func_8007EAA0(6, 176);
        n->obj = t;
        t->res = q;
        func_8000A5EC(n->obj->obj, *q->data, 1, 0, 0, 0, 0);
        n->x = 0;
        n->y = 0;
        n->a = b.v[j];
        n->b = a.v[j];
        n->r = c.v[j][0];
        n->g = c.v[j][1];
        n->bl = c.v[j][2];
        j++;
    } while (j < 5);
    {
        Spr *n;
        Res *q;
        Obj *t;
        n = func_800801D0(D_800C60D4, 28);
        q = func_80034FF0(p + 0x344, 0);
        t = func_8007EAA0(6, 176);
        n->obj = t;
        t->res = q;
        func_8000A5EC(n->obj->obj, *q->data, 1, 0, 0, 0, 0);
        n->x = 0;
        n->y = 0;
        n->a = b.v[j];
        n->b = a.v[j];
        n->r = c.v[j][0];
        n->g = c.v[j][1];
        n->bl = c.v[j][2];
    }
}
