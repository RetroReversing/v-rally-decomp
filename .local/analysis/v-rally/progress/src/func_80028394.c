typedef struct { s16 x; s16 y; s16 z; } Vtx28394;
typedef union { s32 w; u16 v[2]; } XZ28394;
typedef struct { XZ28394 p; s32 pad; } XZ8_28394;
typedef struct VRNode {
    u8 pad00[0x4C];
    u32 unk4C;
    u8 pad50[4];
    Vtx28394 *vtx;
    u8 pad58[4];
    struct VRNode *next;
    u8 pad60[0x10];
    u16 *unk70;
    u8 pad74[0x14];
    u16 unk88;
    u16 unk8A;
} VRNode;
extern void func_8002D75C(s32, s32, s32, s32 *);

void func_80028394(VRNode *arg0)
{
    XZ8_28394 va, vb, vc, vd;
    s32 result;
    VRNode *cur;
    s32 row, col, rows, cols;
    s32 width, idx, idx1, idx2, idx3, last;
    s32 flag, gate, e;
    s32 dy, dx, dz;

    cur = arg0;
    do {
        cols = cur->unk88 - 1;
        rows = cur->unk8A - 1;
        for (row = 0; row < rows; row++) {
            for (col = 0; col < cols; col++) {
                idx = (width = cur->unk8A) * col + row;
                va.p.v[0] = cur->vtx[idx].x;
                va.p.v[1] = cur->vtx[idx].z;
                idx1 = idx + 1;
                vb.p.v[0] = cur->vtx[idx1].x;
                vb.p.v[1] = cur->vtx[idx1].z;
                idx2 = idx + width;
                vc.p.v[0] = cur->vtx[idx2].x;
                vc.p.v[1] = cur->vtx[idx2].z;
                idx3 = idx2 + 1;
                vd.p.v[0] = cur->vtx[idx3].x;
                vd.p.v[1] = cur->vtx[idx3].z;
                flag = 0;
                gate = 0;
                last = col * (width - 1) + row;
                if (row == 0) {
                    gate = 1;
                } else if (row == rows - 1) {
                    gate = 1;
                } else {
                    if (cur->unk4C < row) {
                        if (cur->unk70[last + 1] == 0) {
                            gate = 1;
                        }
                    } else if (cur->unk70[last - 1] == 0) {
                        gate = 1;
                    }
                }
                if (gate) {
                    dy = cur->vtx[idx1].y - cur->vtx[idx].y;
                    if (dy < 0) dy = -dy;
                    dx = (s16)va.p.v[0] - (s16)vb.p.v[0];
                    if (dx < 0) dx = -dx;
                    dz = (s16)va.p.v[1] - (s16)vb.p.v[1];
                    if (dz < 0) dz = -dz;
                    dx += dz;
                    if (va.p.w == vb.p.w || dx * 5 < dy) {
                        flag = 1;
                    }
                    dy = cur->vtx[idx3].y - cur->vtx[idx2].y;
                    if (dy < 0) dy = -dy;
                    dx = (s16)vc.p.v[0] - (s16)vd.p.v[0];
                    if (dx < 0) dx = -dx;
                    dz = (s16)vc.p.v[1] - (s16)vd.p.v[1];
                    if (dz < 0) dz = -dz;
                    dx += dz;
                    if (vc.p.w == vd.p.w || dx * 5 < dy) {
                        flag = 1;
                    }
                }
                func_8002D75C(va.p.w, vb.p.w, vc.p.w, &result);
                if (result < 0) flag = 1;
                func_8002D75C(vc.p.w, va.p.w, vd.p.w, &result);
                if (result < 0) flag = 1;
                func_8002D75C(vd.p.w, vc.p.w, vb.p.w, &result);
                if (result < 0) flag = 1;
                func_8002D75C(vb.p.w, vd.p.w, va.p.w, &result);
                if (result < 0) flag = 1;
                if (flag) {
                    cur->unk70[last] = 0;
                }
            }
        }
        cur = cur->next;
    } while (cur != arg0 && cur != NULL);
}
