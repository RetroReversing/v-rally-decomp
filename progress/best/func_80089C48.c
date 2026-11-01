typedef struct Ent89 { u32 mask; s8 type; u8 pad5[3]; s32 val; } Ent89;
typedef struct Node89 { u32 pad0; Ent89 *subs; u8 count; u8 active; u8 padA[2]; } Node89;
typedef struct Obj89 { u8 pad0[8]; Node89 *nodes; u8 padC; u8 base; u8 cur; } Obj89;
typedef struct Res89 { u8 pad0[0x14]; u8 f14; } Res89;

void func_80038E9C(void);
void func_80038ED4(void);
void func_80038F0C(void);

s16 func_80089C48(Obj89 *obj, Ent89 *list, u32 mask, u8 count, s16 *out, u8 *flag, Res89 *res, s32 arg7)
{
    u8 x27 = 0;
    u8 x2f = 0;
    u8 x37 = 0;
    u8 x3f = 0;
    s32 ret = -1;
    u8 done;
    u8 called;
    u8 c;
    u8 k;
    Ent89 *e;
    Ent89 *p;
    Node89 *node;
    s32 (*fn)(s32, s32);
    s32 v;
    s32 m;
    s8 type;

    *out = ret;
    *flag = 0;
    res->f14 = 0;
    done = 0;
    called = 0;
    e = list;
    for (c = 0; c < count; c++, e++) {
        if (!(e->mask & mask)) {
            continue;
        }
        *flag |= 1;
        if (!called) {
            if (e->mask == 1) {
                called = 1;
                func_80038E9C();
            } else if (e->mask == 2) {
                called = 1;
                func_80038ED4();
            } else if (e->mask != 0x10000) {
                called = 1;
                func_80038F0C();
            }
        }
        type = e->type;
        if (type == 0 && !done) {
            fn = (s32 (*)(s32, s32))e->val;
            v = -1;
            if (fn != 0) {
                if (x27) {
                    v = fn(-2, 0);
                } else if (x2f) {
                    v = fn(-1, 0);
                } else {
                    v = fn(arg7, arg7 - obj->base);
                }
            }
            if (res->f14) {
                *flag = 1;
                ret = v;
            }
        } else if (type == 1) {
            m = e->mask;
            p = e;
            for (;;) {
                node = &obj->nodes[p->val - obj->base];
                if (node->active) {
                    if (node != &obj->nodes[obj->cur - obj->base]) {
                        ret = p->val;
                        x3f = 1;
                    } else {
                        done = 1;
                        *flag = 0;
                    }
                    break;
                }
                for (k = 0; k < node->count; k++) {
                    if ((node->subs[k].mask & m) && node->subs[k].type == 1) {
                        break;
                    }
                }
                if (k == node->count) {
                    done = 1;
                    *flag = 0;
                    break;
                }
                p = &node->subs[k];
            }
        } else if (e->type == 2 && !(x3f | (e->val == -1)) && !x37) {
            if (e->mask & 0x10000) {
                x2f = 1;
            } else if (e->mask & 0x20) {
                x27 = 1;
            }
            x37 = 1;
            *out = e->val;
        }
    }
    return ret;
}
