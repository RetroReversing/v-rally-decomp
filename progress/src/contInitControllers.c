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
extern s8 gContPort0Found;
extern u8 D_800B4288[];
extern ContCtx *gControllerInputContext;
void func_80086138(s32, u8);
void func_800862A0(s32);
s32 osContInit(void *, u8 *, ContStatus *);

/* Initialises the controllers with osContInit and registers each connected pad
   (up to want pads). Returns the number of pads registered. */
s32 contInitControllers(s32 want)
{
    u8 connected_mask;
    s32 port;

    osContInit(D_800B4288, &connected_mask, gControllerInputContext->status);
    for (port = 0; port < 4; port++)
    {
        if (((connected_mask >> port) & 1) && !(gControllerInputContext->status[port].errnum & 8))
        {
            if (port == 0)
            {
                gContPort0Found = 1;
            }
            gControllerInputContext->ptrs[gControllerInputContext->count] = &gControllerInputContext->pads[port];
            gControllerInputContext->x8[port] = 0;
            gControllerInputContext->a[port] = 0;
            gControllerInputContext->b[port] = 0xFFFF;
            gControllerInputContext->c[port] = 0;
            func_80086138(port, connected_mask);
            func_800862A0(port);
            {
                ContCtx *ctx = gControllerInputContext;
                ctx->flags |= 1;
                ctx->count++;
            }
            if (gControllerInputContext->count == want)
            {
                return gControllerInputContext->count;
            }
        }
    }
    return gControllerInputContext->count;
}
