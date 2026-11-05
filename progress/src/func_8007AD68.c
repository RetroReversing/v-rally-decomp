typedef void (*Callback)(void);
typedef struct { u8 pad[0x2c]; s32 state; } Object;
typedef struct { s32 pad; Object *obj; s32 pad8; } Slot;
typedef struct { u8 pad[8]; Slot *slots; u8 pad2[8]; } Team;
typedef struct { u8 pad[3]; u8 current; u8 pad4[12]; Team *teams; } League;
void func_800407D0(void);                            /* extern */
void func_800595EC(s32);           /* extern */
s32 func_8005A388(s32,s32);                    /* extern */
void func_8006F0E0(u8);                  /* extern */
void func_8007A688(void);                            /* extern */
extern void *D_800A1468;
extern u8 D_800A5FB8[];
extern u8 D_800A5FC4[];
extern u8 D_800A5FD0[];
extern u8 *D_800C35A0; extern League *D_800C3508;
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
    temp_s1 = D_800C3508->current;
    if (temp_v1 >= ((*(u16 *)((char *)(D_800C35A0) + 0xE)) - 1)) {
        goto block_11;
    }
    ++((u8 *)D_800A1468)[0x228];
    func_8005A388(arg0, arg1);
    { u8 *state = (u8 *)D_800A1468; u8 *record = D_800C35A0;
    *((Callback *)(state + 0x288)) = func_8007A29C;
    *((Callback *)(state + 0x28C)) = func_8007A9A8;
    *((Callback *)(state + 0x290)) = func_8007AA94;
    temp_v1_2 = *((u16 *)(record + 0x1E)); }
    switch (temp_v1_2) {
case 1: case 2: case 3: case 4:
    D_800C3508->teams[temp_s1].slots[arg1].obj->state = 5;
break;
case 0:
    D_800C3508->teams[temp_s1].slots[arg1].obj->state = 5;
break;
case 5:
    D_800C3508->teams[temp_s1].slots[arg1].obj->state = 7;
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
    D_800C3508->teams[temp_s1].slots[arg1].obj->state = 2;
    func_800595EC((s32)D_800A5FB8);
    (*(Callback *)((char *)D_800A1468 + 0x288)) = &func_8006556C;
    (*(Callback *)((char *)D_800A1468 + 0x28C)) = &func_80065860;
    goto block_22;
block_20:
    D_800C3508->teams[temp_s1].slots[arg1].obj->state = 2;
    func_800595EC((s32)D_800A5FC4);
    (*(Callback *)((char *)D_800A1468 + 0x288)) = &func_800635A0;
    (*(Callback *)((char *)D_800A1468 + 0x28C)) = &func_80063790;
    goto block_22;
block_21:
    D_800C3508->teams[temp_s1].slots[arg1].obj->state = 3;
    func_800595EC((s32)D_800A5FD0);
    (*(Callback *)((char *)D_800A1468 + 0x288)) = &func_80070C34;
    (*(Callback *)((char *)D_800A1468 + 0x28C)) = &func_8007159C;
    func_800407D0();
block_22:
    return 0;
}
