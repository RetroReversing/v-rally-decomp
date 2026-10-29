#include "snapshot29_0433f7af8f6d.h"

s32 func_8007EE9C(void *);

typedef struct { s32 pad[3]; void *child; } ObjE2;

s32 func_8000E2B0(ObjE2 *arg0) {
    s32 *p;
    void *child;
    p = (s32 *)arg0;
    child = (void *)p[3];
    if (child) {
        func_8007EE9C(child);
        return func_8007EE9C(p);
    }
    return 0;
}
