extern s32 D_800B0AE0;
typedef struct AudioConfig875 {s32 pad[4]; void *loader; s32 heap; s32 freq;} AudioConfig875;
extern s32 D_800AB964;
extern s32 D_800AB960;
extern void * D_800AB95C;
extern s32 D_800AB958;
extern s32 D_800AB954;
extern u32 D_800AB950;
extern void * D_800AB94C;
extern s8 D_800AB940;
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

s32 func_8007FB3C(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 osAiSetFrequency(s32);                             /* extern */
void *alHeapDBAlloc(M2C_UNK, M2C_UNK, s32, M2C_UNK, s32); /* extern */
M2C_UNK alInit(void *, void *);              /* extern */
M2C_UNK alLink(void *, void *);              /* extern */
extern s32 D_800A1BB0;
extern f64 D_800A6CF0;
extern f64 D_800A6CF8;
extern M2C_UNK D_800A73E0;
extern char D_800AE850[];
extern M2C_UNK initAudioDriveAndGetLoader;
extern M2C_UNK func_80087470;

void func_80087594(AudioConfig875 *arg0, M2C_UNK arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 pad[2];
    f32 temp_ft0;
    u32 var_s1;
    f64 var_fv1_2;
    s32 temp_fv0;
    s32 temp_v1;
    unsigned int temp_v0;
    s32 var_s0;
    register void **var_s0_2;
    s32 size;
    s32 rate;
    f64 var_fv1;
    s32 var_s2;
    void *temp_v0_2;
    void *temp_v1_2;

    D_800AB940 = 0;
    arg0->loader = &initAudioDriveAndGetLoader;
    rate = M2C_FIELD(arg2, s32 *, 0);
    D_800AB958 = arg4;
    arg0->freq = osAiSetFrequency(rate);
    D_800AB94C = alHeapDBAlloc(0, 0, arg0->heap, 1, arg3 * 0x14);
    temp_v0_2 = alHeapDBAlloc(0, 0, arg0->heap, 1, arg3 * 0x30);
    temp_v1 = M2C_FIELD(arg2, s32 *, 4);
    D_800AB95C = temp_v0_2;
    var_fv1 = (f64) temp_v1;
    if (temp_v1 < 0) {
        var_fv1 += D_800A6CF0;
    }
    temp_ft0 = ((f32) var_fv1 * (f32) arg0->freq) / (f32) arg5;
    temp_fv0 = (s32) temp_ft0;
    D_800AB950 = temp_fv0;
    var_fv1_2 = (f64) temp_fv0;
    if (temp_fv0 < 0) {
        var_fv1_2 += D_800A6CF8;
    }
    if ((f32) var_fv1_2 < temp_ft0) {
        D_800AB950 = (s32) (temp_fv0 + 1);
    }
    if (D_800AB950 & 0xF) {
        D_800AB950 = (s32) ((D_800AB950 & ~0xF) + 0x10);
    }
    D_800AB954 = (s32) (D_800AB950 - 0x10);
    D_800AB960 = (s32) (D_800AB950 + 0x100);
    alInit(D_800AE850 + 0x2304, arg0);
    M2C_FIELD(D_800AB94C, s32 *, 4) = 0;
    M2C_FIELD(D_800AB94C, s32 *, 0) = 0;
    temp_v0 = (unsigned short)(arg3 - 1);
    var_s1 = 0;
    if ((short)temp_v0 != 0) {
        var_s2 = 0x14;
        var_s0 = 0;
        do {
            alLink(D_800AB94C + var_s2, D_800AB94C + var_s0);
            var_s2 += 0x14;
            var_s1 += 1;
            M2C_FIELD((var_s0 + (char *)D_800AB94C), void **, 0x10) = alHeapDBAlloc(0, 0, arg0->heap, 1, arg4);
            var_s0 += 0x14;
        } while (var_s1 < temp_v0);
    }
    M2C_FIELD(((var_s1 * 0x14) + D_800AB94C), void **, 0x10) = alHeapDBAlloc(0, 0, arg0->heap, 1, arg4);
    var_s0_2 = (void **)(D_800AE850 + 0x2278);
    var_s1 = 0;
    do {
        *var_s0_2 = alHeapDBAlloc(0, 0, arg0->heap, 1, M2C_FIELD((int)arg2, s32 *, 8) * 8);
        var_s1 += 1;
        var_s0_2++;
    } while (var_s1 < 3U);
    var_s1 = 0;
    var_s0_2 = D_800AE850 + 0x2284;
    D_800AB964 = (s32) M2C_FIELD(arg2, s32 *, 8);
    do {
        register temp_v0_2 = alHeapDBAlloc(0, 0, arg0->heap, 1, 0x60);
        *var_s0_2 = temp_v0_2;
        M2C_FIELD(temp_v0_2, s16 *, 0x58) = 0;
        size = D_800AB960 * 4;
        temp_v1_2 = *var_s0_2;
        M2C_FIELD(temp_v1_2, void **, 0x5C) = temp_v1_2;
        var_s1 += 1;
        M2C_FIELD(*var_s0_2, void **, 0) = alHeapDBAlloc(0, 0, arg0->heap, 1, size);
        var_s0_2++;
    } while (var_s1 < 3U);
    if (D_800A1BB0 == 0) {
        D_800B0AE0 = func_8007FB3C(&func_80087470, 0x2000, arg1, 0);
    }
    D_800A1BB0 = 1;
}
