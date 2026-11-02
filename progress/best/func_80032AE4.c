typedef struct { s16 x, y, z; } Vec3s;
typedef struct {
    s32 pad0;
    s16 val;
    Vec3s pos;
} Node12;
typedef struct {
    u8 pad0[0xE];
    u8 e;
    u8 f;
    u8 pad10[4];
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    u8 pad18[4];
    Node12 *nodes;
} Info;
typedef struct Car {
    u8 pad0[0xA];
    u16 flags;
    u8 padC[0x4C];
    struct Car *target;
    struct Car *next;
    u8 pad60[0x18];
    Info *info;
    u8 pad7C[0xC];
    u16 count;
} Car;

extern void func_8002FFA4(Car *, s32, s16, Vec3s *);
extern s16 func_8003035C(Car *, s32, Vec3s *);

void func_80032AE4(Car *arg0)
{
    Vec3s a;
    Vec3s b;
    Vec3s c;
    Car *car;
    Car *t;
    Info *g;
    s32 v;
    u8 e;
    u8 f;
    s32 i;
    s32 start;
    s32 far;
    s32 near;
    s32 near2;

    car = arg0;
    do {
        if (car->target == NULL) goto next;
        if (car->flags & 0x800) goto next;
        if (!(car->target->flags & 0x800)) goto next;
        g = car->info;
        v = g->b15 ? g->b15 : g->b16;
        if (v == 0) goto next;
        
        v = (v - (car->info)->b14) * 4;
        e = (car->info)->e;
        f = (car->info)->f;
        if (f < e) i = f; else i = e;
        if (i < 1 || i > 3) goto next;
        far = car->target->info->b17;
        near = car->target->info->b14;
        v = far - v;
        t = car->target;
        if (v < 20) v = 20;
        if (v > 80) v = 80;
        start = t->count - (i * 2 + 1);
        func_8002FFA4(t, start, v, &a);
        func_8002FFA4(t, t->count - 1, far, &b);
        for (i = start; i <= t->count - 1; i++) {
            near2 = start + 1;
            c.x = b.x - a.x;
            c.x = c.x * (i - start) / (t->count - near2) + a.x;
            c.y = b.y - a.y;
            c.y = c.y * (i - start) / (t->count - near2) + a.y;
            c.z = b.z - a.z;
            c.z = c.z * (i - start) / (t->count - near2) + a.z;
            t->info->nodes[i].pos.x = c.x;
            t->info->nodes[i].pos.y = c.y;
            t->info->nodes[i].pos.z = c.z;
            t->info->nodes[i].val = func_8003035C(t, i, &c);
        }
        b = a;
        func_8002FFA4(t, 0, near, &a);
        for (i = 0; i <= start; i++) {
            c.x = (s16)(b.x - a.x) * i / start + a.x;
            c.y = (s16)(b.y - a.y) * i / start + a.y;
            c.z = (s16)(b.z - a.z) * i / start + a.z;
            t->info->nodes[i].pos.x = c.x;
            t->info->nodes[i].pos.y = c.y;
            t->info->nodes[i].pos.z = c.z;
            t->info->nodes[i].val = func_8003035C(t, i, &c);
        }
next:
        car = car->next;
    } while (car != arg0 && car != NULL);
}
