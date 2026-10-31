/* context.h for V-RALLY: shared by every function. Agents grow it with edit_context:
 * add a prototype or struct the moment you work one out, so the next function benefits. */

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile s32 vs32;
typedef int s32_bool;

#define NULL ((void *)0)
#define TRUE 1
#define FALSE 0
#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

f32 __cosf(f32);

s32 func_800898D0(u8 *arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4);

/* Audio update queue and envelope state; offsets verified in alEnvmixerPull. */
typedef struct VRALParam { struct VRALParam *next; s32 time; s16 type, reset; s32 value, value2, value3, value4; } VRALParam;
typedef struct VRALEnv { struct VRALEnv *input; s32 pad4; s32 (*handler)(struct VRALEnv *, s32, s32); u8 padc[12]; s16 pan, volume, cvolL, cvolR; u16 dry, wet, rateL; s16 ratemL, targetL; u16 rateR; s16 ratemR, targetR; s32 delta, segEnd, first; VRALParam *ctrl, *tail; } VRALEnv;

s16 func_8002D2E4(s32);
s16 func_8002D348(s32);

/* func_8001BE68 is declared locally until callers agree on its return type. */

void func_800416EC();
void func_80098A1C(u8 *arg0, s32 arg1, s32 arg2, s8 *arg3);

void *func_80042078(void *, u16, s32, s32, u16);

/* Field layout observed in func_80088D10. */
typedef struct S_func_80088D10_layout {
    u8 unk_00[8]; s32 unk_08; u8 unk_0C[0x30]; s32 unk_3C; u8 unk_40[0x10];
    s32 unk_50; f32 unk_54, unk_58, unk_5C; s32 unk_60; u8 unk_64[0x53];
    u8 unk_B7, unk_B8, unk_B9, unk_BA, unk_BB, unk_BC, unk_BD, unk_BE, unk_BF, unk_C0;
    u8 unk_C1[4]; u8 unk_C5;
} S_func_80088D10_layout;

typedef struct S_func_80027CDC_arg1 {
    s8 unk0;
    u8 unk1, unk2, unk3, unk4, unk5;
} S_func_80027CDC_arg1;

/* Timer layout verified by __osTimerServicesInit. */
typedef struct VRTimer { struct VRTimer *next, *prev; u64 interval, value; void *mq; s32 msg; } VRTimer;
void __osTimerServicesInit(void);

/* Menu object layout verified by func_80068130. */
typedef struct VRMenuObject { struct VRMenuObject *next; u8 pad04[11]; u8 red, green, blue; u8 pad12[8]; u8 enabled; } VRMenuObject;
typedef struct VRMenuItem { u8 pad00[14]; u8 value; u8 pad0F[5]; } VRMenuItem;
typedef struct VRMenuManager { u8 pad00[2]; s16 count; u8 pad04[12]; VRMenuItem *items; } VRMenuManager;
