#define F(p,t,o) (*(t *)((char *)(p)+(o)))
void func_8002FFA4(void *, s32, s16, u16 *);
s16 func_8003035C(void *, s32, u16 *);

void func_800317D4(void *arg0) {
    s32 base0,base1,base2,quot2;
    u16 sp10[3];
    u16 sp18[3];
    u16 sp20[3];
    s32 var_t1_2;
    s32 temp_s0_2;
    register s32 var_s2;
    s32 temp_v0_4;
    u32 var_s4_2;
    s32 temp_v1;
    s32 var_s3;
    s32 temp_a1;
    s32 temp_v1_2;
    u16 temp_a3;
    s32 temp_a0;
    s32 temp_s3;
    s32 temp_a0_2;
    s32 temp_s0_4;
    s32 temp_v0_2;
    register short temp_v1_4;
    long var_s4;
    u16 temp_v1_3;
    register u16 temp_a1_3;
    u16 temp_v0_6;
    register u16 temp_v0_5;
    s32 temp_s0_3;
    s32 temp_a1_2;
    register u8 temp_s7;
    s32 temp_s2;
    u8 temp_a2;
    s16 temp_v0_7;
    s32 var_t1;
    long var_s5;
    s32 var_s6;
    void *temp_v0;
    s32 temp_s0;
    register s16 temp_v0_3;

    temp_v0 = F(arg0,void *,0x78);
    var_s2 = F(temp_v0,u8,0xF);
    var_s5 = F(temp_v0,u8,0xE);
    var_s3 = F(temp_v0,u8,0x15);
    var_s6 = F(temp_v0,u8,0x16);
    temp_a2 = F(temp_v0,u8,0x14);
    temp_s7 = F(temp_v0,u8,0x17);
    var_s4 = 0;
    if ((s32) var_s5 < var_s2) {
        register temp_v0_2 = var_s2;
        var_s2 = var_s5;
        var_s5 = temp_v0_2;
        var_s4 = var_s3;
        var_s3 = var_s6;
        var_s6 = var_s4 & 0xFFFF;
    }
    if (var_s2 != 0) {
        func_8002FFA4(arg0, 0, temp_a2, sp10);
        func_8002FFA4(arg0, var_s2, var_s3, sp18);
        var_s4 = 0;
        if (var_s2) {
loop_4:
            temp_a1 = var_s4 & 0xFFFF;
                base0=sp18[0]-sp10[0];
                temp_a0 = ((s32) ((s16)base0 * temp_a1) / var_s2);
                base1=sp10[1];
                temp_v1 = ((s32) ((s16) (sp18[1] - base1) * temp_a1) / (s32) var_s2);
                base2=sp10[2];
                quot2 = ((s32) ((s16) (sp18[2] - base2) * temp_a1) / (s32) var_s2);
                temp_v1+=base1; sp20[1]=temp_v1;
                temp_a0 += sp10[0]; sp20[0]=temp_a0;
                sp20[2]=quot2+base2;
                temp_s0 = temp_a1 * 0xC;
                F((temp_s0 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0x6) = temp_a0;
                F((temp_s0 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0x8) = temp_v1;
                F((temp_s0 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0xA) = sp20[2];
                var_s4 += 1;
                F((temp_s0 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0x4) = func_8003035C(arg0, temp_a1, sp20);
            if ((var_s4 & 0xFFFF) < var_s2) {
                goto loop_4;
            }
        }
    } else {
        var_s3 = temp_a2;
    }
    if (var_s5) {
        func_8002FFA4(arg0, (s32) var_s2, var_s3, sp10);
        func_8002FFA4(arg0, var_s5, (s16) var_s6, sp18);
        if (var_s2 == var_s5) {
            register temp_s0_3 = (var_s4 & 0xFFFF) * 0xC;
            F((temp_s0_3 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0x6) = sp18[0];
            F((temp_s0_3 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0x8) = sp18[1];
            F((temp_s0_3 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0xA) = sp18[2];
            F((temp_s0_3 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0x4) = func_8003035C(arg0, var_s5, sp18);
        } else {
            var_s4 = var_s2;
            var_t1 = var_s4 & 0xFFFF;
            temp_s3 = var_s5 - var_s2;
            if (var_t1 < var_s5) {
                do {
                    temp_a1_2 = var_t1 - var_s2;
                    base0=sp10[0];
                    temp_a0_2 = ((s32) ((s16) (sp18[0] - base0) * temp_a1_2) / temp_s3);
                    base1=sp10[1];
                    temp_v1_2 = ((s32) ((s16) (sp18[1] - base1) * temp_a1_2) / temp_s3);
                    base2=sp10[2];
                    quot2 = ((s32) ((s16) (sp18[2] - base2) * temp_a1_2) / temp_s3);
                    temp_v1_2+=base1; sp20[1]=temp_v1_2;
                    temp_a0_2+=base0; sp20[0]=(u32)temp_a0_2;
                    sp20[2]=(unsigned)quot2+base2;
                    temp_s0_2 = var_t1 * 0xC;
                    F((temp_s0_2 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0x6) = temp_a0_2;
                    F((temp_s0_2 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0x8) = temp_v1_2;
                    F((temp_s0_2 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0xA) = sp20[2];
                    temp_v0_3 = func_8003035C(arg0, var_t1, sp20);
                    var_s4 += 1;
                    var_t1 = var_s4 & 0xFFFF;
                    F((temp_s0_2 + F(F(arg0,void *,0x78),void *,0x1C)),u16,(short)0x4) = temp_v0_3;
                } while (var_s5 > var_t1);
            }
        }
    } else {
        var_s6 = var_s3;
        var_s5 = var_s2;
    }
    func_8002FFA4(arg0, var_s5, (s16) var_s6, sp10);
    func_8002FFA4(arg0, F(arg0,u16,0x88) - 1, temp_s7, sp18);
    temp_v0_4 = F(arg0,u16,0x88) - 1;
    if (var_s5 != temp_v0_4) {
        var_s4_2 = var_s5;
        var_t1_2 = var_s4_2 & 0xFFFF;
        temp_s2 = var_s5 + 1;
        if (temp_v0_4 >= var_t1_2) {
            do {
                register temp_a3 = var_t1_2 - var_s5;
                temp_v0_5 = sp18[0] - sp10[0];
                sp20[0] = temp_v0_5;
                temp_v0_6 = sp18[1] - sp10[1];
                temp_a1_3 = ((s32) (temp_v0_5 * temp_a3) / (s32) (F(arg0,u16,0x88) - temp_s2)) + sp10[0];
                sp20[1] = temp_v0_6;
                sp20[0] = temp_a1_3;
                temp_v0_7 = sp18[2] - sp10[2];
                sp20[1] = ((s32) (temp_v0_6 * temp_a3) / (s32) (F(arg0,u16,0x88) - temp_s2)) + sp10[1];
                sp20[2] = temp_v0_7;
                temp_v1_3 = ((s32) (temp_v0_7 * temp_a3) / (s32) (F(arg0,u16,0x88) - temp_s2)) + sp10[2];
                sp20[2] = temp_v1_3;
                temp_s0_4 = var_t1_2 * 0xC;
                F((temp_s0_4 + F(F((unsigned short)arg0,void *,0x78),void *,0x1C)),u16,0x6) = temp_a1_3;
                F((temp_s0_4 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0x8) = sp20[1];
                F(((unsigned)temp_s0_4 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0xA) = temp_v1_3;
                F((temp_s0_4 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0x4) = func_8003035C(arg0, var_t1_2, sp20);
                var_s4_2 += 1;
                var_t1_2 = var_s4_2 & 0xFFFF;
            } while ((F((int)arg0,u16,0x88) - 1) >= (unsigned short)var_t1_2);
        }
        return;
    }
    temp_v1_4 = (var_s4 & 0xFFFF) * 0xC;
    F(((unsigned)temp_v1_4 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0x8) = sp18[1];
    F(((short)temp_v1_4 + F(F(arg0,void *,(short)0x78),void *,0x1C)),u16,0x6) = sp18[0];
    F(((unsigned short)temp_v1_4 + F(F(arg0,void *,0x78),void *,0x1C)),u16,0xA) = sp18[2];
    F((temp_v1_4 + F(F(arg0,void *,0x78),void *,0x1C)),u16,(unsigned short)0x4) = (s16) (temp_s7 * 0xA);
}
