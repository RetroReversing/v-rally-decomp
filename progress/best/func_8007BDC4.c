extern char D_800C8380[];
extern char *D_800C35A0;
extern char *D_800C7F84;
extern u32 D_800C34DC[1];
#define D_800C34DC D_800C34DC[0]
extern u8 D_800C34F0;
extern u32 D_800C34E0;
extern u32 D_800C34D8;
extern u32 D_800C34E8;
extern u8 D_800C34F2[1];
#define D_800C34F2 D_800C34F2[0]
extern u32 D_800C34EC;
extern u8 D_800C34F3;
extern u32 D_800C34E4;
extern u8 D_800C34F1;
extern u16 D_800C34EE;
extern u16 D_800C34E6;
#define W(p,o) (*(s32*)((char*)(p)+(o)))
#define H(p,o) (*(s16*)((char*)(p)+(o)))
#define B(p,o) (*(u8*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern char D_800C02AE[],D_800A5FDC[],D_800A5FE8[],D_800A5FF8[],D_800A6008[];extern char *D_800A0384,*D_800B5C40;extern int D_800AFA6C,D_800A18D0;
int func_800056FC(int);char *func_80006008(int);int func_8001BD1C(void);void func_8000C200(int,float,float,float);
void guOrthoF(void*,float,float,float,float,float,float,float);
void func_8007BDC4(void) {
    float sp20[16];s16 ypos;int xpos;
    char sp60[120];
    char spD8[24];
    int var_a1;
    int var_a1_2;
    int var_a1_3;
    int var_a2;
    int var_a2_2;
    int var_a2_3;
    int var_a3;
    int var_a3_2;
    
    s32 temp_s0_2;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_v0;
    s32 var_v1;
    char *temp_s0;
    char *temp_s1;
    char *temp_v0_2;
    char *temp_v1;
    char *temp_v1_2;

    if ((u32) D_800AFA6C >= 0xAU) {
        temp_s1 = P(D_800B5C40,0);
        if (((*(u16 *)(D_800C35A0+0xE)) == 1) && (W(P(temp_s1,0x48),0) == 0) && (D_800A18D0 & 1) && ((*(u16 *)(D_800C35A0+0x1E)) == 0)) {
            temp_s0 = D_800C8380;
            guMtxIdent(temp_s0);
            temp_v0 = func_800056FC(W(D_800C7F84,0x178));
            temp_v0_2 = func_80006008(temp_v0);
            W(temp_v0_2,0x0) = 0xDA380003;
            W(temp_v0_2,0x4) = temp_s0;
            func_80006014(temp_v0, temp_v0_2 + 8);
            temp_s0_2 = func_8001BD1C();
            guOrthoF(sp20, 0.0f, 320.0f, 240.0f, 0.0f, -1.0f, 10.0f, 1.0f);
            guMtxF2L(&sp20, temp_s0_2);
            func_800061FC(temp_v0, temp_s0_2);
            func_8000C200(W(D_800A0384,0x4), 0.7f, 0.7f, 0.7f);
            func_8000C22C(W(D_800A0384,0x4), 0xFF, 0xFF, 0xFF, 0xFF);
            temp_v1 = P(temp_s1,0x80);
            if ((W(temp_v1,0x310) >= 0) && (W(temp_v1,0x314) >= 0) && (W(temp_v1,0x318) >= 0) && (W(temp_v1,0x31C) >= 0)) {
                D_800C34DC++;
                if (D_800C34F0 == 0) {
                    D_800C34E0 = (s32) W(P(temp_s1,0x88),0x84);
                    D_800C34D8 = (s32) W(P(temp_s1,0x5C),0x58);
                }
                D_800C34F0 = 1U;
            } else if (*(volatile u8 *)&D_800C34F0 != 0) {
                *(volatile u8 *)&D_800C34F0 = 0U;
                if ((u32) D_800C34E8 < (u32) D_800C34DC) {
                    D_800C34E8 = (u32) D_800C34DC;
                    D_800C34F2 = 0x32U;
                }
                D_800C34DC = 0U;
                var_v0 = -D_800C34E0 + W(P(temp_s1,0x88),0x84);
                if (var_v0 < 0) {
                    var_v0 = -var_v0;
                }
                if ((u32) D_800C34EC < (u32) var_v0) {
                    D_800C34EC = (u32) var_v0;
                    D_800C34F3 = 0x32U;
                }
                D_800C34E0 = 0;
                temp_v1_2 = P(temp_s1,0x8C);
                var_v1 = (s32) (((((f32) H(temp_v1_2,0xB6) + (f32) H(temp_v1_2,0xCA) + (f32) H(temp_v1_2,0xDE) + (f32) H(temp_v1_2,0xF2)) * 0.25f) - (f32) W(P(temp_s1,0x80),0x4)) - (f32) W(P(temp_s1,0x5C),0x58));
                if (var_v1 < 0) {
                    var_v1 = -var_v1;
                }
                if ((u32) D_800C34E4 < (u32) var_v1) {
                    D_800C34E4 = (u32) var_v1;
                    D_800C34F1 = 0x32U;
                }
            }
            xpos=22; ypos=32;
            func_8000C244(W(D_800A0384,0x4), temp_v0, 0x16, 0x16, &D_800A5FDC, 0);
            if (D_800C34F2 != 0) {
                var_a1 = 0xDC;
                D_800C34F2 = (u8)(D_800C34F2-1);
                var_a0 = W(D_800A0384,0x4);
                var_a2 = 0xDC;
                var_a3 = 0x10;
            
            func_8000C22C(var_a0,var_a1,var_a2,var_a3);} else {
                var_a1 = 0xFF;
                var_a0 = W(D_800A0384,0x4);
                var_a2 = 0xFF;
                var_a3 = 0xFF;
            
            func_8000C22C(var_a0,var_a1,var_a2,var_a3);}
            func_80052E94(D_800C34E8, &spD8);
            func_80099DF8(&sp60, &D_800A5FE8, &spD8);
            if (!(((u8) D_800C34F3 >> 3) & 1)) {
                func_8000C244(W(D_800A0384,0x4), temp_v0, xpos, ypos, &sp60, 0);
            }
            ypos+=10;
            if (D_800C34F3 != 0) {
                var_a1_2 = 0xDC;
                D_800C34F3 = (u8)(D_800C34F3 - 1);
                var_a0_2 = W(D_800A0384,0x4);
                var_a2_2 = 0xDC;
                var_a3_2 = 0x10;
            
            func_8000C22C(var_a0_2,var_a1_2,var_a2_2,var_a3_2,255);} else {
                var_a1_2 = 0xFF;
                var_a0_2 = W(D_800A0384,0x4);
                var_a2_2 = 0xFF;
                var_a3_2 = 0xFF;
            
            func_8000C22C(var_a0_2,var_a1_2,var_a2_2,var_a3_2,255);}
            func_80099DF8(&sp60, &D_800A5FF8,  D_800C34EE);
            if (!(((u8) D_800C34F3 >> 3) & 1)) {
                func_8000C244(W(D_800A0384,0x4), temp_v0, xpos, ypos, &sp60, 0);
            }
            ypos+=10;
            if (D_800C34F1 != 0) {
                var_a1_3 = 0xDC;
                D_800C34F1 = (u8)(D_800C34F1 - 1);
                var_a0_3 = W(D_800A0384,0x4);
                var_a2_3 = 0xDC;
                var_a3_2 = 0x10;
            
            func_8000C22C(var_a0_3,var_a1_3,var_a2_3,var_a3_2,255);} else {
                var_a1_3 = 0xFF;
                var_a0_3 = W(D_800A0384,0x4);
                var_a2_3 = 0xFF;
                var_a3_2 = 0xFF;
            
            func_8000C22C(var_a0_3,var_a1_3,var_a2_3,var_a3_2,255);}
            func_80099DF8(&sp60, &D_800A6008,  D_800C34E6);
            if (!(((u8) D_800C34F1 >> 3) & 1)) {
                func_8000C244(W(D_800A0384,0x4), temp_v0, xpos, ypos, &sp60, 0);
            }
            func_8000C200(W(D_800A0384,0x4), 0.8f, 0.8f, 0.8f);
        }
    }
}
