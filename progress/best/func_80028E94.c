typedef struct {u16 x,z;} Pair10;
typedef struct { u16 x,y,z; } GridVertex;
typedef struct { char pad[0x54]; GridVertex *vertices; char pad58[0x18]; u16 *cells; char pad74[0x14]; u16 rows,cols; } Grid;
typedef struct { char pad[0x60]; u32 *indices; char pad64[0x28]; Grid **grids; } GridState;
typedef struct { u16 x,y,z; } Point;
void func_8002D75C(s32,s32,s32,int *);
int func_80028E94(GridState *,Point *,int);
s32 func_80028E94(GridState *arg0, Point *arg1, s32 arg2) {
    volatile union { u32 word; u8 bytes[8]; } flags10;                                       /* compiler-managed */
    volatile union { u32 word; u8 bytes[8]; } flags18;                                       /* compiler-managed */
    Pair10 p20;
    
    Pair10 p28;
    
    Pair10 p30;
    
    struct {s32 x,y,z; char pad[8];} delta;
    s32 sp48;
    s32 sp54;
    u16 *sp5C;
    volatile s32 sp60;
    volatile s32 sp64;
    volatile s32 sp68;
    Grid *temp_s0;
    GridVertex *temp_a0_6;
    GridVertex *temp_v0;
    GridVertex *temp_v0_2;
    GridVertex *temp_v0_3;
    GridVertex *temp_v0_4;
    GridVertex *temp_v1_11;
    GridVertex *temp_v1_5;
    GridVertex *temp_v1_6;
    s32 temp_v1_10;
    s32 temp_v1_4;
    s32 var_a2_2;
    s32 var_a2_4;
    s32 temp_a0_2;
    
    s32 temp_a0_5;
    s32 temp_a3;
    s32 temp_v0_5;
    s32 temp_v1_3;
    s32 temp_v1_9;
    s32 var_a2;
    s32 var_a2_3;
    s32 var_a3;
    s32 var_fp;
    s32 var_s2;
    s32 var_s6;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t2;
    s32 var_t3;
    s32 var_t4;
    s32 var_v0;
    s32 var_v0_3;
    u16 temp_a0;
    u16 temp_a0_4;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 temp_a2_3;
    u16 temp_v1_12;
    u16 temp_v1_2;
    u16 temp_v1_7;
    u16 temp_v1_8;
    u16 var_v0_2;
    u16 var_v0_4;
    u16 var_v0_5;
    u16 var_v0_6;
    u32 *temp_v1;
    u32 *var_v1;
    u32 var_s4;
    u32 var_s5;
    s32 var_s7;

    sp54 = arg2;
    temp_s0 = arg0->grids[arg2];
    temp_v1 = &arg0->indices[arg2];
    var_s4 = temp_v1[0];
    temp_a2 = temp_s0->cols;
    var_s5 = temp_v1[12];
    sp5C = temp_s0->cells;
    var_s2 = 0;
    p30.x = arg1->x;
    var_s7 = 0;
    flags10.word = 0;
    flags18.word = 0;
    p30.z = arg1->z;
    var_t2 = (temp_a2 * var_s4) + var_s5;
    var_fp = var_t2 + 1;
    var_t3 = var_t2 + temp_a2;
    var_s6 = var_t3 + 1;
    var_t4 = (var_s4 * (temp_a2 - 1)) + var_s5;
loop_1:
    switch (var_s7) {                               /* irregular */
    case 0:
        p20.x = temp_s0->vertices[var_fp].x;
        p20.z = temp_s0->vertices[var_fp].z;
        p28.x = temp_s0->vertices[var_s6].x;
        p28.z = temp_s0->vertices[var_s6].z;
        sp60 = var_t2;
        sp64 = var_t3;
        sp68 = var_t4;
        func_8002D75C((*(s32*)&p20), (*(s32*)&p28), (*(s32*)&p30), &sp48);
        var_t2 = sp60;
        var_t3 = sp64;
        var_t4 = sp68;
        if (sp48 >= 0) {
            var_s2 += 1;
            var_s7 = 2;
            goto block_146;
        }
        if (var_s5 < (u32) (temp_s0->cols - 2)) {
            var_v0_2 = sp5C[(var_t4)+1];
            if (var_v0_2 == 0) {
                flags18.bytes[1] = 1;
                goto block_13;
            }
            goto block_14;
        }
        var_v0_2 = 0;
        flags10.bytes[1] = 1;
block_13:
        if (var_v0_2 != 0) {
block_14:
            var_t2 += 1;
            var_fp += 1;
            var_t3 += 1;
            var_s6 += 1;
            var_t4 += 1;
            var_s5 += 1;
block_83:
            var_s2 = 0;
            flags10.word = 0;
            flags18.word = 0;
            goto block_146;
        }
        if (var_s2 == 3) {
            arg0->indices[arg2] = var_s4;
            arg0->indices[arg2+12] = var_s5;
            return (-(var_s5 < (u32) (temp_s0->cols - 2)) & ~3) | 4;
        }

if(flags18.bytes[1] && (flags18.bytes[2] || flags18.bytes[3])) {
arg0->indices[arg2]=var_s4;arg0->indices[arg2+12]=var_s5;
if(flags18.bytes[2])return -5;
if(flags18.bytes[3])return -8;
}
if(flags10.bytes[1] && (flags10.bytes[2] || flags10.bytes[3] || flags18.bytes[2] || flags18.bytes[3])) {
arg0->indices[arg2]=var_s4;arg0->indices[arg2+12]=var_s5;
if(flags18.bytes[2])return 5;
if(flags10.bytes[2])return 5;
if(flags18.bytes[3])return 8;
if(flags10.bytes[3])return 8;
}
var_s7=2;var_s2=0;goto block_146;
    case 2:
        temp_a0 = temp_s0->vertices[var_s6].x;
        p20.x = temp_a0;
        temp_a2_2 = temp_s0->vertices[var_s6].z;
        p20.z = temp_a2_2;
        temp_v1_2 = temp_s0->vertices[var_t3].x;
        p28.x = temp_v1_2;
        temp_a0_2 = temp_a0 - temp_v1_2;
        temp_a1 = temp_s0->vertices[var_t3].z;
        var_t0 = temp_a0_2;
        p28.z = temp_a1;
        if ((s16)temp_a0_2 < 0) {
            var_t0 = -temp_a0_2;
        }
        temp_v1_3 = temp_a2_2 - temp_a1;
        var_a2 = temp_v1_3;
        if ((s16)temp_v1_3 < 0) {
            var_a2 = -temp_v1_3;
        }
        temp_v0 = temp_s0->vertices;
        temp_v1_4 = temp_v0[var_t3].y - temp_v0[var_s6].y;
        var_a2_2 = temp_v1_4;
        if ((s16)temp_v1_4 < 0) {
            var_a2_2 = -temp_v1_4;
        }
        if (((*(s32*)&p20) == (*(s32*)&p28)) || (((s32) ((var_t0 + var_a2) << 0x10) >> 0xD) < (s16)var_a2_2)) {
            if (var_s4 >= (u32) (temp_s0->rows - 2)) {
                var_v0_3 = var_s6;
            } else {
                var_v0_3 = var_s6 + temp_s0->cols;
            }
            temp_v1_5 = temp_s0->vertices;
            temp_a3 = (s16) temp_v1_5[var_v0_3].x - (s16) temp_v1_5[var_fp].x;
            delta.x = temp_a3;
            temp_v1_6 = temp_s0->vertices;
            delta.y = (s16) temp_v1_6[var_v0_3].y - (s16) temp_v1_6[var_fp].y;
            temp_v0_2 = temp_s0->vertices;
            temp_a0_2 = (s16) temp_v0_2[var_v0_3].z - (s16) temp_v0_2[var_fp].z;
            p28.z = p20.z + temp_a3;
            delta.z = temp_a0_2;
            p28.x = p20.x - temp_a0_2;
        }
        sp60 = var_t2;
        sp64 = var_t3;
        sp68 = var_t4;
        func_8002D75C((*(s32*)&p20), (*(s32*)&p28), (*(s32*)&p30), &sp48);
        var_t2 = sp60;
        var_t3 = sp64;
        var_t4 = sp68;
        if (sp48 >= 0) {
            var_s2 += 1;
            var_s7 = 1;
            goto block_146;
        }
        var_v0_4 = 0;
        if (var_s4 < (u32) (temp_s0->rows - 2)) {
            var_v0_4 = sp5C[(var_t4 + temp_s0->cols)-1];
            if (var_v0_4 == 0) {
                flags18.bytes[2] = 1;
                goto block_54;
            }
            goto block_55;
        }
        flags10.bytes[2] = 1;
block_54:
        if (var_v0_4 != 0) {
block_55:
            temp_v1_7 = temp_s0->cols;
            var_s4 += 1;
            var_s2 = 0;
            flags10.word = 0;
            flags18.word = 0;
            var_t2 += temp_v1_7;
            var_fp += temp_v1_7;
            var_t3 += temp_v1_7;
            var_s6 += temp_v1_7;
            var_t4 = var_t4 - 1 + temp_v1_7;
            goto block_146;
        }
        var_s7 = 1;
        if (var_s2 == 3) {
            arg0->indices[arg2] = var_s4;
            arg0->indices[arg2+12] = var_s5;
            return (-(var_s4 < (u32) (temp_s0->rows - 2)) & ~1) | 2;
        }
        var_s2 = 0;

if(flags18.bytes[2] && (flags18.bytes[0] || flags18.bytes[1])) {
arg0->indices[arg2]=var_s4;arg0->indices[arg2+12]=var_s5;
if(flags18.bytes[0])return -6;
if(flags18.bytes[1])return -5;
}
if(flags10.bytes[2] && (flags10.bytes[0] || flags10.bytes[1] || flags18.bytes[0] || flags18.bytes[1])) {
arg0->indices[arg2]=var_s4;arg0->indices[arg2+12]=var_s5;
if(flags18.bytes[0])return 6;
if(flags10.bytes[0])return 6;
if(flags18.bytes[1])return 5;
if(flags10.bytes[1])return 5;
}
var_s7=1;var_s2=0;goto block_146;
    case 1:
        p20.x = temp_s0->vertices[var_t3].x;
        p20.z = temp_s0->vertices[var_t3].z;
        p28.x = temp_s0->vertices[var_t2].x;
        p28.z = temp_s0->vertices[var_t2].z;
        sp60 = var_t2;
        sp64 = var_t3;
        sp68 = var_t4;
        func_8002D75C((*(s32*)&p20), (*(s32*)&p28), (*(s32*)&p30), &sp48);
        var_t2 = sp60;
        var_t3 = sp64;
        var_t4 = sp68;
        if (sp48 >= 0) {
            var_s2 += 1;
            var_s7 = 3;
            goto block_146;
        }
        if (var_s5 != 0) {
            var_v0_5 = sp5C[(var_t4)-1];
            if (var_v0_5 == 0) {
                flags18.bytes[0] = var_s7;
                goto block_81;
            }
            goto block_82;
        }
        var_v0_5 = 0;
        flags10.bytes[0] = var_s7;
block_81:
        if (var_v0_5 != 0) {
block_82:
            var_t2 -= 1;
            var_fp -= 1;
            var_t3 -= 1;
            var_s6 -= 1;
            var_t4 -= 1;
            var_s5 -= 1;
            goto block_83;
        }
        var_s7 = 3;
        if (var_s2 == 3) {
            arg0->indices[arg2] = var_s4;
            var_v0 = 3;
            arg0->indices[arg2+12] = var_s5;
            if (var_s5 != 0) {
                return -3;
            }
            /* Duplicate return node #150. Try simplifying control flow for better match */
            return var_v0;
        }
        var_s2 = 0;

if(flags18.bytes[0] && (flags18.bytes[2] || flags18.bytes[3])) {
arg0->indices[arg2]=var_s4;arg0->indices[arg2+12]=var_s5;
if(flags18.bytes[2])return -6;
if(flags18.bytes[3])return -7;
}
if(flags10.bytes[0] && (flags10.bytes[2] || flags10.bytes[3] || flags18.bytes[2] || flags18.bytes[3])) {
arg0->indices[arg2]=var_s4;arg0->indices[arg2+12]=var_s5;
if(flags18.bytes[2])return 6;
if(flags10.bytes[2])return 6;
if(flags18.bytes[3])return 7;
if(flags10.bytes[3])return 7;
}
var_s7=3;var_s2=0;goto block_146;
    case 3:
        temp_a0_4 = temp_s0->vertices[var_t2].x;
        p20.x = temp_a0_4;
        temp_a2_3 = temp_s0->vertices[var_t2].z;
        p20.z = temp_a2_3;
        temp_v1_8 = temp_s0->vertices[var_fp].x;
        p28.x = temp_v1_8;
        temp_a0_5 = temp_a0_4 - temp_v1_8;
        temp_a1_2 = temp_s0->vertices[var_fp].z;
        var_t0_2 = temp_a0_5;
        p28.z = temp_a1_2;
        if ((s16)temp_a0_5 < 0) {
            var_t0_2 = -temp_a0_5;
        }
        temp_v1_9 = temp_a2_3 - temp_a1_2;
        var_a2_3 = temp_v1_9;
        if ((s16)temp_v1_9 < 0) {
            var_a2_3 = -temp_v1_9;
        }
        temp_v0_3 = temp_s0->vertices;
        temp_v1_10 = temp_v0_3[var_t2].y - temp_v0_3[var_fp].y;
        var_a2_4 = temp_v1_10;
        if ((s16)temp_v1_10 < 0) {
            var_a2_4 = -temp_v1_10;
        }
        if ((*(s32*)&p20) != (*(s32*)&p28)) {
            if (((s32) ((var_t0_2 + var_a2_3) << 0x10) >> 0xD) >= (s16)var_a2_4) {
                sp60 = var_t2;
                sp64 = var_t3;
                sp68 = var_t4;
                func_8002D75C((*(s32*)&p20), (*(s32*)&p28), (*(s32*)&p30), &sp48);
                var_t4 = sp68;
                var_t3 = sp64;
                var_t2 = sp60;
            } else {
                goto block_113;
            }
        } else {
block_113:
            if (var_s4 == 0) {
                var_a3 = var_t2;
            } else {
                var_a3 = var_fp - temp_s0->cols;
            }
            temp_a0_6 = temp_s0->vertices;
            delta.x = (s16) temp_a0_6[var_s6].x - (s16) temp_a0_6[var_a3].x;
            temp_v1_11 = temp_s0->vertices;
            delta.y = (s16) temp_v1_11[var_s6].y - (s16) temp_v1_11[var_a3].y;
            temp_v0_4 = temp_s0->vertices;
            delta.z = (s16) temp_v0_4[var_s6].z - (s16) temp_v0_4[var_a3].z;
            temp_v0_5 = (*(s32*)&p28);
            p20 = p28;
            p28.x = p20.x - delta.z;
            p28.z = p20.z + delta.x;
            sp60 = var_t2;
            sp64 = var_t3;
            sp68 = var_t4;
            func_8002D75C((*(s32*)&p28), (*(s32*)&p20), (*(s32*)&p30), &sp48);
            var_t2 = sp60;
            var_t3 = sp64;
            var_t4 = sp68;
        }
        if (sp48 >= 0) {
            var_s2 += 1;
            var_s7 = 0;
            goto block_146;
        }
        var_v0_6 = 0;
        if (var_s4 != 0) {
            var_v0_6 = sp5C[(var_t4 - temp_s0->cols)+1];
            if (var_v0_6 == 0) {
                flags18.bytes[3] = 1;
                goto block_126;
            }
            goto block_127;
        }
        flags10.bytes[3] = 1;
block_126:
        if (var_v0_6 != 0) {
block_127:
            temp_v1_12 = temp_s0->cols;
            var_s4 -= 1;
            var_s2 = 0;
            flags10.word = 0;
            flags18.word = 0;
            var_t2 -= temp_v1_12;
            var_fp -= temp_v1_12;
            var_t3 -= temp_v1_12;
            var_s6 -= temp_v1_12;
            var_t4 = (var_t4 + 1) - temp_v1_12;
            goto block_146;
        }
        var_s7 = 0;
        if (var_s2 == 3) {
            arg0->indices[arg2] = var_s4;
            var_v0 = -(var_s4 != 0) | 1;
            var_v1 = &arg0->indices[arg2];
            goto block_149;
        }
        var_s2 = 0;

if(flags18.bytes[3] && (flags18.bytes[0] || flags18.bytes[1])) {
arg0->indices[arg2]=var_s4;arg0->indices[arg2+12]=var_s5;
if(flags18.bytes[0])return -7;
if(flags18.bytes[1])return -8;
}
if(flags10.bytes[3] && (flags10.bytes[0] || flags10.bytes[1] || flags18.bytes[0] || flags18.bytes[1])) {
arg0->indices[arg2]=var_s4;arg0->indices[arg2+12]=var_s5;
if(flags18.bytes[0])return 7;
if(flags10.bytes[0])return 7;
if(flags18.bytes[1])return 8;
if(flags10.bytes[1])return 8;
}
var_s7=0;var_s2=0;goto block_146;

default:break;
}
block_146:
block_147:
if(var_s2!=4)goto loop_1;
arg0->indices[sp54]=var_s4;
var_v0=0;var_v1=&arg0->indices[sp54];
block_149:
var_v1[12]=var_s5;return var_v0;
}
