typedef struct Ent89 { u32 mask; s8 type; u8 pad5[3]; s32 val; } Ent89;
typedef struct Node89 { u32 pad0; Ent89 *subs; u8 count; u8 active; u8 padA[2]; } Node89;
typedef struct Obj89 { u8 pad0[8]; Node89 *nodes; u8 padC; u8 base; u8 cur; } Obj89;
typedef struct Res89 { u8 pad0[0x14]; u8 f14; } Res89;

void func_80038E9C(void);
void func_80038ED4(void);
void func_80038F0C(void);

/* Walks the entry table for the events in `mask`: runs the matching callbacks,
 * follows the node chain for type-1 entries, and records the first usable value
 * in *out. Sets *flag when a result is ready. Returns the selected value, or -1. */
s16 func_80089C48(Obj89 *obj, Ent89 *e, u32 mask, u8 count, s16 *out, u8 *flag, Res89 *res, s32 arg7)
{
    u8 gotCamera = 0;
    u8 gotCameraAlt = 0;
    u8 gotValue = 0;
    u8 gotValueAlt = 0;
    s32 ret = -1;
    u8 done;
    u8 called;
    u8 c;
    u8 k;
    Ent89 *p;
    Node89 *node;
    s32 (*fn)(s32, s32);
    s32 v;
    s32 m;
    s8 type;
    s32 z;

    *out = ret;
    *flag = 0;
    res->f14 = 0;
    done = 0;
    called = 0;
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
                if (gotCamera) {
                    v = fn(-2, 0);
                } else if (gotCameraAlt) {
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
                        gotValueAlt = 1;
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
        } else if (e->type == 2 && !(z = gotValueAlt | (e->val == -1)) && !gotValue) {
            if (e->mask & 0x10000) {
                gotCameraAlt = 1;
            } else if (e->mask & 0x20) {
                gotCamera = 1;
            }
            gotValue = 1;
            *out = e->val;
        }
    }
    return ret;
}
