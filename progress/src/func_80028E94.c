typedef struct {u16 x,z;} Pair10;
typedef struct { u16 x,y,z; } GridVertex;
typedef struct { char pad[0x54]; GridVertex *vertices; char pad58[0x18]; u16 *cells; char pad74[0x14]; u16 rows,cols; } Grid;
typedef struct { char pad[0x60]; u32 *indices; char pad64[0x28]; Grid **grids; } GridState;
typedef struct { u16 x,y,z; } Point;
void func_8002D75C(s32,s32,s32,int *);
int func_80028E94(GridState *,Point *,int);
s32 func_80028E94(GridState *arg0, Point *arg1, s32 arg2) {
    u32 flags10[2],flags18[2];
 Pair10 p20,p28,p30;
 struct {s32 x,y,z; char pad[4];} delta;
 s32 sp48; s32 idx; u16 *sp5C; 
  s32 sp54; s32 last_index; s32 row_tail;
    s16 sum2,sum3;
    s32 step2,step3;
    Grid *temp_s0;
    GridVertex *temp_a0_6;
    GridVertex *temp_v0;
    GridVertex *temp_v0_2;
    GridVertex *temp_v0_3;
    GridVertex *temp_v0_4;
    GridVertex *temp_v1_11;
    GridVertex *temp_v1_5;
    GridVertex *temp_v1_6;
    s16 temp_v1_10;
    short temp_v1_4;


    s32 temp_a0_2;
    
    s32 temp_a0_5;
    s32 temp_a3;
    s32 temp_v0_5;
    s32 temp_v1_3;
    s32 temp_v1_9;
    u16 var_a2;

    s32 var_a3;
    s32 var_fp;
    s32 var_s2;
    s32 var_s6;
    u16 var_t0;

    s32 var_t2;
    s32 var_t3;
    s32 var_t4;
    s32 var_v0;
    s32 var_v0_3;
    u16 temp_a0;
    u16 temp_a0_4;
    u16 temp_a1;
    
    
    u16 temp_a2_2;
    u16 temp_a2_3;
    u32 temp_v1_12;
    u16 temp_v1_2;
    u32 temp_v1_7;

    u16 var_v0_2;
    u16 var_v0_4;
    u16 var_v0_5;
    u16 var_v0_6;
    u32 *temp_v1;
    u32 *var_v1;
    u32 var_s4;
    u32 var_s5;
    u32 var_s7;

     
    idx=arg2;
    temp_s0 = arg0->grids[arg2];
    temp_v1=(u32*)(((u32)arg2*4)+(u32)arg0->indices);
    var_s4 = temp_v1[0];
    arg2 = temp_s0->cols;
    var_s5 = temp_v1[12];
    sp5C = temp_s0->cells;


    p30.x = arg1->x;
    var_s2=0;

    row_tail=arg2-1;
    p30.z = arg1->z;
    flags10[0] = 0;
    var_t2 = (arg2 * var_s4) + var_s5;
    var_fp=var_t2+1;
    var_t3=var_t2+arg2;var_s6=var_t3+1;
    flags18[0]=0;
    var_t4 = (var_s4 * row_tail) + var_s5;
for(var_s7=0;var_s2!=4;){
    switch (var_s7) {                               /* irregular */
    case 0:
        p20.x = temp_s0->vertices[var_fp].x;
        p20.z = temp_s0->vertices[var_fp].z;
        p28.x = temp_s0->vertices[var_s6].x;
        p28.z = temp_s0->vertices[var_s6].z;
        func_8002D75C((*(s32*)&p20), (*(s32*)&p28), (*(s32*)&p30), &sp48);
        if(sp48>=0)goto positive_0;
        if (var_s5 < (u32) (temp_s0->cols - 2)) {
            var_v0_2 = sp5C[(var_t4)+1];
            if (var_v0_2 == 0) {
                ((u8*)flags18)[1] = 1;
                goto block_13;
            }
            goto block_14;
        }
        var_v0_2 = 0;
        ((u8*)flags10)[1] = 1;
block_13:
        if (var_v0_2 != 0) {
block_14:
            var_t2 += 1;
            var_fp += 1;
            var_t3 += 1;
            var_s6 += 1;
            var_t4 += 1;
            var_s5 += 1;
            var_s2=0;flags10[0]=0;flags18[0]=0;goto block_146;
        }
        if (var_s2 == 3) {
            *(u32*)((char*)arg0->indices+(idx*4)) = var_s4;
            *(u32*)((char*)arg0->indices+(idx*4)+48) = var_s5;
            return (-(var_s5 < (u32) (temp_s0->cols - 2)) & ~3) | 4;
        }

if(((u8*)flags18)[1] && (((u8*)flags18)[2] || ((u8*)flags18)[3])) {
*(u32*)((char*)arg0->indices+(idx*4))=var_s4;*(u32*)((char*)arg0->indices+(idx*4)+48)=var_s5;
if(((u8*)flags18)[2])return -5;
if(((u8*)flags18)[3])return -8;
}
if(((u8*)flags10)[1] && (((u8*)flags10)[2] || ((u8*)flags10)[3] || ((u8*)flags18)[2] || ((u8*)flags18)[3])) {
*(u32*)((char*)arg0->indices+(idx*4))=var_s4;*(u32*)((char*)arg0->indices+(idx*4)+48)=var_s5;
if(((u8*)flags18)[2])return 5;
if(((u8*)flags10)[2])return 5;
if(((u8*)flags18)[3])return 8;
if(((u8*)flags10)[3])return 8;
}
var_s7=2;var_s2=0;goto block_146;

positive_0: var_s2+=1;var_s7=2;goto block_146;
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
        sum2=var_t0+var_a2;
        temp_v0 = temp_s0->vertices;
        temp_v1_4 = temp_v0[var_t3].y - temp_v0[var_s6].y;
        var_a2 = temp_v1_4;
        if ((s16)temp_v1_4 < 0) {
            var_a2 = -temp_v1_4;
        }
        if (((*(s32*)&p20) == (*(s32*)&p28)) || (((s16)sum2 * 8) < (s16)var_a2)) {
            if(var_s4<(u32)(temp_s0->rows-2))var_v0_3=var_s6+temp_s0->cols;else var_v0_3=var_s6;
            temp_v1_5 = temp_s0->vertices;
            temp_a3 = (s16) temp_v1_5[var_v0_3].x - (s16) temp_v1_5[var_fp].x;
            delta.x = temp_a3;
            temp_v1_6 = temp_s0->vertices;
            delta.y = (s16) temp_v1_6[var_v0_3].y - (s16) temp_v1_6[var_fp].y;
            temp_v0_2 = temp_s0->vertices;
            delta.z = (s16) temp_v0_2[var_v0_3].z - (s16) temp_v0_2[var_fp].z;
            p28.z = p20.z + temp_a3;

            p28.x = p20.x - delta.z;
        }
        func_8002D75C((*(s32*)&p20), (*(s32*)&p28), (*(s32*)&p30), &sp48);
        if(sp48>=0)goto positive_2;

        if (var_s4 < (u32) (temp_s0->rows - 2)) {
            var_v0_4 = sp5C[(var_t4 + temp_s0->cols)-1];
            if (var_v0_4 == 0) {
                ((u8*)flags18)[2] = 1;
                goto block_54;
            }
            goto block_55;
        }
        var_v0_4=0;
        ((u8*)flags10)[2] = 1;
block_54:
        if (var_v0_4 != 0) {
block_55:
            temp_v1_7 = temp_s0->cols;
            step2=var_t4-1;
            var_s4 += 1;
            var_s2 = 0;
            flags10[0] = 0;
            flags18[0] = 0;
            var_t2 += temp_v1_7;
            var_fp += temp_v1_7;
            var_t3 += temp_v1_7;
            var_s6 += temp_v1_7;
            var_t4 = step2+temp_v1_7;
            goto block_146;
        }
        var_s7=1;
        if (var_s2 == 3) {
            *(u32*)((char*)arg0->indices+(idx*4)) = var_s4;
            *(u32*)((char*)arg0->indices+(idx*4)+48) = var_s5;
            return (-(var_s4 < (u32) (temp_s0->rows - 2)) & ~1) | 2;
        }
        var_s2 = 0;

if(((u8*)flags18)[2] && (((u8*)flags18)[0] || ((u8*)flags18)[1])) {
*(u32*)((char*)arg0->indices+(idx*4))=var_s4;*(u32*)((char*)arg0->indices+(idx*4)+48)=var_s5;
if(((u8*)flags18)[0])return -6;
if(((u8*)flags18)[1])return -5;
}
if(((u8*)flags10)[2] && (((u8*)flags10)[0] || ((u8*)flags10)[1] || ((u8*)flags18)[0] || ((u8*)flags18)[1])) {
*(u32*)((char*)arg0->indices+(idx*4))=var_s4;*(u32*)((char*)arg0->indices+(idx*4)+48)=var_s5;
if(((u8*)flags18)[0])return 6;
if(((u8*)flags10)[0])return 6;
if(((u8*)flags18)[1])return 5;
if(((u8*)flags10)[1])return 5;
}
goto block_146;

positive_2: var_s2+=1;var_s7=1;goto block_146;
    case 1:
        p20.x = temp_s0->vertices[var_t3].x;
        p20.z = temp_s0->vertices[var_t3].z;
        p28.x = temp_s0->vertices[var_t2].x;
        p28.z = temp_s0->vertices[var_t2].z;
        func_8002D75C((*(s32*)&p20), (*(s32*)&p28), (*(s32*)&p30), &sp48);
        if(sp48>=0)goto positive_1;
        if (var_s5 != 0) {
            var_v0_5 = sp5C[(var_t4)-1];
            if (var_v0_5 == 0) {
                if(sp5C){((u8*)flags18)[0] = var_s7;
                goto block_81;}else{((u8*)flags18)[0] = var_s7;
                goto block_81;}
            }
            goto block_82;
        }
        var_v0_5 = 0;
        ((u8*)flags10)[0] = var_s7;
block_81:
        if (var_v0_5 != 0) {
block_82:
            var_t2 -= 1;
            var_fp -= 1;
            var_t3 -= 1;
            var_s6 -= 1;
            var_t4 -= 1;
            var_s5 -= 1;
block_83:
            var_s2 = 0;
            flags10[0] = 0;
            flags18[0] = 0;
            goto block_146;
        }
        if (var_s2 == 3) {
            *(u32*)((char*)arg0->indices+(idx*4)) = var_s4;
            var_v0 = 3;
            *(u32*)((char*)arg0->indices+(idx*4)+48) = var_s5;
            if (var_s5 != 0) {
                return -3;
            }
            /* Duplicate return node #150. Try simplifying control flow for better match */
            return var_v0;
        }
        var_s7=3;
        var_s2 = 0;

if(((u8*)flags18)[0] && (((u8*)flags18)[2] || ((u8*)flags18)[3])) {
*(u32*)((char*)arg0->indices+(idx*4))=var_s4;*(u32*)((char*)arg0->indices+(idx*4)+48)=var_s5;
if(((u8*)flags18)[2])return -6;
if(((u8*)flags18)[3])return -7;
}
if(((u8*)flags10)[0] && (((u8*)flags10)[2] || ((u8*)flags10)[3] || ((u8*)flags18)[2] || ((u8*)flags18)[3])) {
*(u32*)((char*)arg0->indices+(idx*4))=var_s4;*(u32*)((char*)arg0->indices+(idx*4)+48)=var_s5;
if(((u8*)flags18)[2])return 6;
if(((u8*)flags10)[2])return 6;
if(((u8*)flags18)[3])return 7;
if(((u8*)flags10)[3])return 7;
}
goto block_146;

positive_1: var_s2+=1;var_s7=3;goto block_146;
    case 3:
        temp_a0_4 = temp_s0->vertices[var_t2].x;
        p20.x = temp_a0_4;
        temp_a2_3 = temp_s0->vertices[var_t2].z;
        p20.z = temp_a2_3;
        temp_v1_3 = temp_s0->vertices[var_fp].x;
        p28.x = temp_v1_3;
        temp_a0_5 = temp_a0_4 - temp_v1_3;
        temp_a1 = temp_s0->vertices[var_fp].z;
        var_t0 = temp_a0_5;
        p28.z = temp_a1;
        if ((s16)temp_a0_5 < 0) {
            var_t0 = -temp_a0_5;
        }
        temp_v1_9 = temp_a2_3 - temp_a1;
        var_a2 = temp_v1_9;
        if ((s16)temp_v1_9 < 0) {
            var_a2 = -temp_v1_9;
        }
        sum3=var_t0+var_a2;
        temp_v0_3 = temp_s0->vertices;
        temp_v1_10 = temp_v0_3[var_t2].y - temp_v0_3[var_fp].y;
        var_a2 = temp_v1_10;
        if ((s16)temp_v1_10 < 0) {
            var_a2 = -temp_v1_10;
        }
        if(((*(s32*)&p20)==(*(s32*)&p28)) || (((s16)sum3 * 8) < (s16)var_a2)) {
            if(var_s4!=0)var_a3=var_fp-temp_s0->cols;else var_a3=var_t2;
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
            func_8002D75C((*(s32*)&p28), (*(s32*)&p20), (*(s32*)&p30), &sp48); } else {
                func_8002D75C((*(s32*)&p20), (*(s32*)&p28), (*(s32*)&p30), &sp48);
        }
        if(sp48>=0)goto positive_3;
        var_v0_6 = 0;
        if (var_s4 != 0) {
            var_v0_6 = sp5C[(var_t4 - temp_s0->cols)+1];
            if (var_v0_6 == 0) {
                ((u8*)flags18)[3] = 1;
                goto block_126;
            }
            goto block_127;
        }
        ((u8*)flags10)[3] = 1;
block_126:
        if (var_v0_6 != 0) {
block_127:
            temp_v1_12 = temp_s0->cols;
            step3=var_t4+1;
            var_s4 -= 1;
            var_s2 = 0;
            flags10[0] = 0;
            flags18[0] = 0;
            var_t2 -= temp_v1_12;
            var_fp -= temp_v1_12;
            var_t3 -= temp_v1_12;
            var_s6 -= temp_v1_12;
            var_t4 = step3-temp_v1_12;
            goto block_146;
        }
        var_s7=0;
        if (var_s2 == 3) {
            *(u32*)((char*)arg0->indices+(idx*4)) = var_s4;
            var_v1 = (u32*)((idx*4)+(u32)arg0->indices);
            var_v0 = -(var_s4 != 0) | 1;
            var_v1[12]=var_s5;return var_v0;
        }
        var_s2 = 0;

if(((u8*)flags18)[3] && (((u8*)flags18)[0] || ((u8*)flags18)[1])) {
*(u32*)((char*)arg0->indices+(idx*4))=var_s4;*(u32*)((char*)arg0->indices+(idx*4)+48)=var_s5;
if(((u8*)flags18)[0])return -7;
if(((u8*)flags18)[1])return -8;
}
if(((u8*)flags10)[3] && (((u8*)flags10)[0] || ((u8*)flags10)[1] || ((u8*)flags18)[0] || ((u8*)flags18)[1])) {
*(u32*)((char*)arg0->indices+(idx*4))=var_s4;*(u32*)((char*)arg0->indices+(idx*4)+48)=var_s5;
if(((u8*)flags18)[0])return 7;
if(((u8*)flags10)[0])return 7;
if(((u8*)flags18)[1])return 8;
if(((u8*)flags10)[1])return 8;
}
goto block_146;


positive_3: var_s2+=1;var_s7=0;goto block_146;
default:break;
}
block_146:
block_147:
}
last_index=idx;arg0->indices[last_index]=var_s4;arg0->indices[last_index+12]=var_s5;return 0;
}
