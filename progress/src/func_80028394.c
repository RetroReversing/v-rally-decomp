typedef struct { s16 x; s16 y; s16 z; } Vtx28394;
typedef union { s32 w; u16 v[2]; } XZ28394;
typedef struct { XZ28394 p; s32 pad; } XZ8_28394;
typedef struct VRNode {
    u8 pad00[0x4C];
    u32 split;
    u8 pad50[4];
    Vtx28394 *vtx;
    u8 pad58[4];
    struct VRNode *next;
    u8 pad60[0x10];
    u16 *cellMask;
    u8 pad74[0x14];
    u16 vtxCountX;
    u16 vtxCountZ;
} VRNode;
extern void func_8002D75C(s32, s32, s32, s32 *);

/* Walks the ring of terrain nodes starting at `start`. For each grid cell it looks at the four
 * corners (v00, v01, v10, v11) and clears the cell's mask bit when the cell is folded (a corner
 * orientation test fails) or, on the border rows or where the neighbour cell is already off,
 * when the two triangles are too steep or degenerate. */
void func_80028394(VRNode *start)
{
    XZ8_28394 v00, v01, v10, v11;
    s32 cross;
    VRNode *node;
    s32 row, col, rows, cols;
    s32 nz, i00, i01, i10, i11, cell;
    s32 cull, checkEdge;
    s32 dy, dx, dz;

    node = start;
    do {
        cols = node->vtxCountX - 1;
        rows = node->vtxCountZ - 1;
        for (row = 0; row < rows; row++) {
            for (col = 0; col < cols; col++) {
                i00 = (nz = node->vtxCountZ) * col + row;
                v00.p.v[0] = node->vtx[i00].x;
                v00.p.v[1] = node->vtx[i00].z;
                i01 = i00 + 1;
                v01.p.v[0] = node->vtx[i01].x;
                v01.p.v[1] = node->vtx[i01].z;
                i10 = i00 + nz;
                v10.p.v[0] = node->vtx[i10].x;
                v10.p.v[1] = node->vtx[i10].z;
                i11 = i10 + 1;
                v11.p.v[0] = node->vtx[i11].x;
                v11.p.v[1] = node->vtx[i11].z;
                cull = 0;
                checkEdge = 0;
                cell = col * (nz - 1) + row;
                if (row == 0) {
                    checkEdge = 1;
                } else if (row == rows - 1) {
                    checkEdge = 1;
                } else {
                    if (node->split < row) {
                        if (node->cellMask[cell + 1] == 0) {
                            checkEdge = 1;
                        }
                    } else if (node->cellMask[cell - 1] == 0) {
                        checkEdge = 1;
                    }
                }
                if (checkEdge) {
                    dy = node->vtx[i01].y - node->vtx[i00].y;
                    if (dy < 0) dy = -dy;
                    dx = (s16)v00.p.v[0] - (s16)v01.p.v[0];
                    if (dx < 0) dx = -dx;
                    dz = (s16)v00.p.v[1] - (s16)v01.p.v[1];
                    if (dz < 0) dz = -dz;
                    dx += dz;
                    if (v00.p.w == v01.p.w || dx * 5 < dy) {
                        cull = 1;
                    }
                    dy = node->vtx[i11].y - node->vtx[i10].y;
                    if (dy < 0) dy = -dy;
                    dx = (s16)v10.p.v[0] - (s16)v11.p.v[0];
                    if (dx < 0) dx = -dx;
                    dz = (s16)v10.p.v[1] - (s16)v11.p.v[1];
                    if (dz < 0) dz = -dz;
                    dx += dz;
                    if (v10.p.w == v11.p.w || dx * 5 < dy) {
                        cull = 1;
                    }
                }
                func_8002D75C(v00.p.w, v01.p.w, v10.p.w, &cross);
                if (cross < 0) cull = 1;
                func_8002D75C(v10.p.w, v00.p.w, v11.p.w, &cross);
                if (cross < 0) cull = 1;
                func_8002D75C(v11.p.w, v10.p.w, v01.p.w, &cross);
                if (cross < 0) cull = 1;
                func_8002D75C(v01.p.w, v11.p.w, v00.p.w, &cross);
                if (cross < 0) cull = 1;
                if (cull) {
                    node->cellMask[cell] = 0;
                }
            }
        }
        node = node->next;
    } while (node != start && node != NULL);
}
