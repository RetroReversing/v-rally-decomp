#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u16 type; u8 status; u8 errnum; } ContStatus;
typedef struct { u16 button; s8 x; s8 y; u8 errnum; } ContPad;
typedef struct {
    u8 pad0[4];
    s32 count;
    u8 x8[4];
    ContStatus status[4];
    ContPad pads[4];
    ContPad *ptrs[4];
    s16 a[4];
    u16 b[4];
    s16 c[4];
    u8 pad5C[0x39C - 0x5C];
    u8 flags;
} ContCtx;
extern s8 D_800AFA40;
extern u8 D_800B4288[];
extern ContCtx *D_800A1B70;
void func_80086138(s32, u8);
void func_800862A0(s32);
s32 osContInit(void *, u8 *, ContStatus *);

s32 func_800859A0(s32 n)
{
    u8 pattern;
    s32 i;

    osContInit(D_800B4288, &pattern, D_800A1B70->status);
    for (i = 0; i < 4; i++)
    {
        if (((pattern >> i) & 1) && !(D_800A1B70->status[i].errnum & 8))
        {
            if (i == 0)
            {
                D_800AFA40 = 1;
            }
            D_800A1B70->ptrs[D_800A1B70->count] = &D_800A1B70->pads[i];
            D_800A1B70->x8[i] = 0;
            D_800A1B70->a[i] = 0;
            D_800A1B70->b[i] = 0xFFFF;
            D_800A1B70->c[i] = 0;
            func_80086138(i, pattern);
            func_800862A0(i);
            {
                ContCtx *p = D_800A1B70;
                p->flags |= 1;
                p->count++;
            }
            if (D_800A1B70->count == n)
            {
                return D_800A1B70->count;
            }
        }
    }
    return D_800A1B70->count;
}

