void func_800407D0(void);                            /* extern */
void func_800595EC(void *);           /* extern */
s32 func_8005A388(s32,s32);                    /* extern */
void func_8006F0E0(u8);                  /* extern */
void func_8007A688(void);                            /* extern */
extern void *D_800A1468;
extern s32 D_800A5FB8;
extern s32 D_800A5FC4;
extern s32 D_800A5FD0;
extern u8 *D_800C35A0; extern u8 *D_800C3508;
extern void func_800635A0(void);
extern void func_80063790(void);
extern void func_8006556C(void);
extern void func_80065860(void);
extern void func_80070C34(void);
extern void func_8007159C(void);
extern void func_8007A29C(void);
extern void func_8007A9A8(void);
extern void func_8007AA94(void);

s32 func_8007AD68(s32 arg0, s32 arg1) {
    char *__repair_addr; s8 temp_v1;
    u16 temp_v1_2;
    u16 temp_v1_3;
    u8 temp_s1;

    (*(s8 *)((char *)(D_800A1468) + 0x245)) = 0;
    func_8007A688();
  __repair_addr = (char *) ((D_800C35A0 + ((D_800C35A0 + ((s8) ((u8 *)D_800A1468)[0x228]))[0x32] * 0x28)) + 0x4E);
  *((s16 *) __repair_addr) = ((u8 *)D_800A1468)[0x237];
    func_8006F0E0((u8) (*(s8 *)((char *)(D_800A1468) + 0x228)));
    temp_v1 = (*(s8 *)((char *)(D_800A1468) + 0x228));
    temp_s1 = (*(u8 *)((char *)(D_800C3508) + 3));
    if (temp_v1 >= ((*(u16 *)((char *)(D_800C35A0) + 0xE)) - 1)) {
        goto block_11;
    }
    (*(s8 *)((char *)(D_800A1468) + 0x228)) = (s8) (temp_v1 + 1);
    func_8005A388(arg0, arg1);
    { u8 *state = (u8 *)D_800A1468; u8 *record = D_800C35A0;
    *((void **)(state + 0x288)) = func_8007A29C;
    *((void **)(state + 0x28C)) = func_8007A9A8;
    *((void **)(state + 0x290)) = func_8007AA94;
    temp_v1_2 = *((u16 *)(record + 0x1E)); }
    switch (temp_v1_2) {
case 1: case 2: case 3: case 4:
    (*(s32 *)((char *)((*(void **)((char *)(((arg1 * 0xC) + (*(s32 *)((char *)(((temp_s1 * 0x14) + (*(s32 *)((char *)(D_800C3508) + 0x10)))) + 8)))) + 4))) + 0x2C)) = 5;
break;
case 0:
    (*(s32 *)((char *)((*(void **)((char *)(((arg1 * 0xC) + (*(s32 *)((char *)(((temp_s1 * 0x14) + (*(s32 *)((char *)(D_800C3508) + 0x10)))) + 8)))) + 4))) + 0x2C)) = 5;
break;
case 5:
    (*(s32 *)((char *)((*(void **)((char *)(((arg1 * 0xC) + (*(s32 *)((char *)(((temp_s1 * 0x14) + (*(s32 *)((char *)(D_800C3508) + 0x10)))) + 8)))) + 4))) + 0x2C)) = 7;
break;
default: return 0;
} goto block_22;
block_11:
    (*(s8 *)((char *)(D_800A1468) + 0x228)) = 0;
    (*(s8 *)((char *)(D_800A1468) + 0x22B)) = -1;
    temp_v1_3 = (*(u16 *)((char *)(D_800C35A0) + 0x1E));
    switch (temp_v1_3) {
case 1: case 2: case 3: case 4: goto block_19;
case 0: goto block_20;
case 5: goto block_21;
default: return 0;
}
block_19:
    (*(s32 *)((char *)((*(void **)((char *)(((arg1 * 0xC) + (*(s32 *)((char *)(((temp_s1 * 0x14) + (*(s32 *)((char *)(D_800C3508) + 0x10)))) + 8)))) + 4))) + 0x2C)) = 2;
    func_800595EC(&D_800A5FB8);
    (*(s32 **)((char *)(D_800A1468) + 0x288)) = &func_8006556C;
    (*(s32 **)((char *)(D_800A1468) + 0x28C)) = &func_80065860;
    goto block_22;
block_20:
    (*(s32 *)((char *)((*(void **)((char *)(((arg1 * 0xC) + (*(s32 *)((char *)(((temp_s1 * 0x14) + (*(s32 *)((char *)(D_800C3508) + 0x10)))) + 8)))) + 4))) + 0x2C)) = 2;
    func_800595EC(&D_800A5FC4);
    (*(s32 **)((char *)(D_800A1468) + 0x288)) = &func_800635A0;
    (*(s32 **)((char *)(D_800A1468) + 0x28C)) = &func_80063790;
    goto block_22;
block_21:
    (*(s32 *)((char *)((*(void **)((char *)(((arg1 * 0xC) + (*(s32 *)((char *)(((temp_s1 * 0x14) + (*(s32 *)((char *)(D_800C3508) + 0x10)))) + 8)))) + 4))) + 0x2C)) = 3;
    func_800595EC(&D_800A5FD0);
    (*(s32 **)((char *)(D_800A1468) + 0x288)) = &func_80070C34;
    (*(s32 **)((char *)(D_800A1468) + 0x28C)) = &func_8007159C;
    func_800407D0();
block_22:
    return 0;
}
