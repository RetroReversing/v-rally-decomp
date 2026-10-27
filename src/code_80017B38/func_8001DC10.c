#include "common.h"

/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

M2C_UNK func_80041A04(M2C_UNK, u16);                /* extern */
u64 osGetTime(void);                             /* extern */
M2C_UNK func_800980C4(u32);                         /* extern */
extern s32 D_8009D4F0;
extern void *D_800A1234;
extern M2C_UNK D_800AE850;
extern void *D_800C35A0;

void func_8001DC10(void) {
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_hi;
    s32 temp_hi_2;
    s32 temp_s0_2;
    s32 temp_v1;
    u8 var_s1;
    s32 var_t0;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_a0;
    u8 temp_a1_2;
    u16 temp_a1_3;
    u8 temp_s0;
    u16 temp_s0_3;
    s32 var_s0;
    s32 var_v1;
    void *temp_a3;
    void *temp_s1;
    void *var_a1;

    temp_a0 = M2C_FIELD(D_800C35A0, u16 *, 0x1E);
    temp_s1 = D_800C35A0 + 0x44;
    if (temp_a0 == 7) {
        if (M2C_FIELD(D_800C35A0, u16 *, 0x2C) & 0x10) {
            func_80041A04(6, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x32) * 0x28) + temp_s1), u16 *, 0xA));
            if (M2C_FIELD(D_800A1234, u16 *, 0x110) == 2) {
                func_80041A04(6, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x33) * 0x28) + temp_s1), u16 *, 0xA));
            }
        } else {
            u8 current, first, remaining;
            remaining = 3;
            func_800980C4((u32)osGetTime());
            current = D_8009D4F0++ % 9;
            func_80041A04(5,current);
            first = current;
            do {
                current = D_8009D4F0++ % 9;
                if (current != first) {
                    func_80041A04(5,current);
                    { void *base; s32 off;
off=remaining;
remaining--;
base=D_800C35A0;
off=(3-off)*0x28;
base+=off;
M2C_FIELD(base,u16 *,0x4E)=current; }
                }
            } while (remaining);

        }
    } else if (temp_a0 == 8) {
        func_80041A04(8, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x32) * 0x28) + temp_s1), u16 *, 0xA));
        func_80041A04(8, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x33) * 0x28) + temp_s1), u16 *, 0xA));
        func_80041A04(8, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x34) * 0x28) + temp_s1), u16 *, 0xA));
        func_80041A04(8, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x35) * 0x28) + temp_s1), u16 *, 0xA));
    } else {
        temp_s0_3 = M2C_FIELD(D_800C35A0, u16 *, 0xE);
        switch (temp_s0_3) {
case 1:
func_80041A04(0, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x32) * 0x28) + temp_s1), u16 *, 0xA));
if(M2C_FIELD(D_800C35A0,u16 *,0x1E)!=0) goto block_50;
if(M2C_FIELD(D_800C35A0,u16 *,0x1A)!=temp_s0_3) goto block_49;
var_v1=M2C_FIELD(D_800C35A0,u8 *,0x32);
var_v0_2=var_v1*4;
goto block_48;
case 2:
func_80041A04(0, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x32) * 0x28) + temp_s1), u16 *, 0xA));
if (M2C_FIELD(D_800C35A0,u16 *,0x1E)==0 && M2C_FIELD(D_800C35A0,u16 *,0x1A)==1) func_80041A04(7,M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x32) * 0x28) + temp_s1), u16 *, 0xA));
func_80041A04(1, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x33) * 0x28) + temp_s1), u16 *, 0xA));
if(M2C_FIELD(D_800C35A0,u16 *,0x1E)!=0) goto block_50;
if(M2C_FIELD(D_800C35A0,u16 *,0x1A)!=1) goto block_49;
var_v1=M2C_FIELD(D_800C35A0,u8 *,0x33);
var_v0_2=var_v1*4;
goto block_48;
case 3:
func_80041A04(0, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x32) * 0x28) + temp_s1), u16 *, 0xA));
if (M2C_FIELD(D_800C35A0,u16 *,0x1E)==0 && M2C_FIELD(D_800C35A0,u16 *,0x1A)==1) func_80041A04(7,M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x32) * 0x28) + temp_s1), u16 *, 0xA));
func_80041A04(1, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x33) * 0x28) + temp_s1), u16 *, 0xA));
if (M2C_FIELD(D_800C35A0,u16 *,0x1E)==0 && M2C_FIELD(D_800C35A0,u16 *,0x1A)==1) func_80041A04(7,M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x33) * 0x28) + temp_s1), u16 *, 0xA));
func_80041A04(2, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x34) * 0x28) + temp_s1), u16 *, 0xA));
if(M2C_FIELD(D_800C35A0,u16 *,0x1E)!=0) goto block_50;
if(M2C_FIELD(D_800C35A0,u16 *,0x1A)!=1) goto block_49;
var_v1=M2C_FIELD(D_800C35A0,u8 *,0x34);
var_v0_2=var_v1*4;
goto block_48;
case 4:
func_80041A04(0, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x32) * 0x28) + temp_s1), u16 *, 0xA));
if (M2C_FIELD(D_800C35A0,u16 *,0x1E)==0 && M2C_FIELD(D_800C35A0,u16 *,0x1A)==1) func_80041A04(7,M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x32) * 0x28) + temp_s1), u16 *, 0xA));
func_80041A04(1, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x33) * 0x28) + temp_s1), u16 *, 0xA));
if (M2C_FIELD(D_800C35A0,u16 *,0x1E)==0 && M2C_FIELD(D_800C35A0,u16 *,0x1A)==1) func_80041A04(7,M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x33) * 0x28) + temp_s1), u16 *, 0xA));
func_80041A04(2, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x34) * 0x28) + temp_s1), u16 *, 0xA));
if (M2C_FIELD(D_800C35A0,u16 *,0x1E)==0 && M2C_FIELD(D_800C35A0,u16 *,0x1A)==1) func_80041A04(7,M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x34) * 0x28) + temp_s1), u16 *, 0xA));
func_80041A04(3, M2C_FIELD(((M2C_FIELD(D_800C35A0, u8 *, 0x35) * 0x28) + temp_s1), u16 *, 0xA));
if(M2C_FIELD(D_800C35A0,u16 *,0x1E)!=0) goto block_50;
if(M2C_FIELD(D_800C35A0,u16 *,0x1A)!=1) goto block_49;
var_v1=M2C_FIELD(D_800C35A0,u8 *,0x35);
var_v0_2=var_v1*4;
goto block_48;
}
goto block_49;
block_48:
func_80041A04(7,M2C_FIELD((((var_v0_2+var_v1)*8)+temp_s1),u16 *,0xA));
block_49:
if(M2C_FIELD(D_800C35A0,u16 *,0x1E)!=0) {
block_50:
var_s0=M2C_FIELD(D_800C35A0,u16 *,0xE);
if(var_s0<4) do {
temp_a1_3=M2C_FIELD(((M2C_FIELD((D_800C35A0+var_s0),u8 *,0x32)*0x28)+temp_s1),u16 *,0xA);
var_s0+=1;
func_80041A04(5,temp_a1_3);
} while(var_s0<4);
}
}
    var_a1 = *M2C_FIELD(&D_800AE850, void ***, 0x73F0);
    var_t0 = 0;
    if (var_a1 != NULL) {
        void *base; s32 one;
        base=D_800C35A0;
        one=1;
        do {
            temp_a3 = base + (var_t0 & 0xFF);
            { u32 idx=M2C_FIELD(temp_a3,u8 *,0x32); void *dst=M2C_FIELD(var_a1,void **,0x28); void *rec=base; rec+=idx*0x28; M2C_FIELD(dst,s32 *,0x50)=M2C_FIELD(rec,u16 *,0x4E); }
            { u32 idx=M2C_FIELD(temp_a3,u8 *,0x32); void *dst=M2C_FIELD(var_a1,void **,0x54); void *rec=base; rec+=idx*0x28; M2C_FIELD(dst,s32 *,0x50)=M2C_FIELD(rec,u16 *,0x4E); }
            if ((M2C_FIELD(base, u16 *, 0x1E) == 0) && (M2C_FIELD(base, u16 *, 0x1A) == one)) {
                var_a1 = M2C_FIELD(var_a1, void **, 4);
                { u32 idx=M2C_FIELD(temp_a3,u8 *,0x32); void *dst=M2C_FIELD(var_a1,void **,0x28); void *rec=base; rec+=idx*0x28; M2C_FIELD(dst,s32 *,0x50)=M2C_FIELD(rec,u16 *,0x4E); }
                { u32 idx=M2C_FIELD(temp_a3,u8 *,0x32); void *dst=M2C_FIELD(var_a1,void **,0x54); void *rec=base; rec+=idx*0x28; M2C_FIELD(dst,s32 *,0x50)=M2C_FIELD(rec,u16 *,0x4E); }
            }
            var_a1 = M2C_FIELD(var_a1, void **, 4);
            var_t0 += 1;
        } while (var_a1 != NULL);
    }
}
