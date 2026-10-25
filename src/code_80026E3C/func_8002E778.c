#include "common.h"

typedef struct V3 { s32 x; s32 y; s32 z; } V3;
void func_8002E778(V3 *arg0, V3 *arg1)
{
    arg1->x = arg0->x * arg0->x;
    arg1->y = arg0->y * arg0->y;
    arg1->z = arg0->z * arg0->z;
}
