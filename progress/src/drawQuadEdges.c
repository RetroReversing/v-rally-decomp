#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 drawEdgeSegment();

/* Draws a quad outline through four corners (px0,py0) (px1,py1) (px2,py2) (px3,py3):
 * one edge segment per side, all in the same colour (0xB4). */
void drawQuadEdges(s32 ctx, s32 px0, s32 py0, s32 px1, u16 py1, u16 px2, u16 py2, u16 px3, u16 py3) {
    s32 savedX0;
    s32 x0;
    s32 x2;
    s32 y2;
    s32 x3;
    s32 y3;
    u16 y0;
    u16 x1;

    x0 = px0 & 0xFFFF;
    savedX0 = x0;
    y0 = py0 & 0xFFFF;
    x1 = px1 & 0xFFFF;
    drawEdgeSegment(ctx, x0, y0, x1, (s32) py1, 0xB4);
    x2 = px2 & 0xFFFF;
    y2 = py2 & 0xFFFF;
    drawEdgeSegment(ctx, x1, py1, x2, y2, 0xB4);
    x3 = px3 & 0xFFFF;
    y3 = py3 & 0xFFFF;
    drawEdgeSegment(ctx, (u16) x2, (u16) y2, x3, y3, 0xB4);
    drawEdgeSegment(ctx, (u16) x3, (u16) y3, savedX0, (s32) y0, 0xB4);
    return;
}
