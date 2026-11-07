typedef struct {
    s32 base;
    s32 len;
    u8 type;
    u8 flags;
    u8 pad[2];
    s32 loop;
    s32 book;
} MusWave;

typedef struct {
    u8 header_name[16];
    u32 flags;
    u8 wbk_name[12];
    s32 count;
    u8 *basenote;
    u8 *detune;
    s32 wave_list;
} MusPtrBank;

extern f64 D_800A6DB8;
void func_8008989C(s32 *p, s32 a, s32 n);
void osWritebackDCacheAll(void);

#define WAVE(o) (*(MusWave **)((o) + ptr->wave_list))

void func_80089704(s32 pptr, s32 wptr) {
    MusWave *wave;
    MusPtrBank *ptr;
    s32 i;
    s32 c;
    u8 *p;
    f64 scale;
    f32 f;
    u8 unused[8];

    ptr = (MusPtrBank *)pptr;
    if (ptr->flags & 0x80000000)
        return;
    ptr->flags |= 0x80000000;
    func_8008989C((s32 *)&ptr->basenote, pptr, 3);
    func_8008989C((s32 *)ptr->wave_list, pptr, ptr->count);
    i = 0;
    if (ptr->count > 0) {
    scale = D_800A6DB8;
    do {
        p = ptr->detune + i * 4;
        {
            u8 db = *p;
            if (db & 0x80) c = db - 0x100; else c = db;
        }
        *(f32 *)p = (f = c) * scale;
        {
            u8 nb = ptr->basenote[i] - 0x30;
            if (nb & 0x80) f = nb - 0x100; else f = nb;
        }
        *(f32 *)p += f;
        p = (u8 *)WAVE(i * 4);
        if (((MusWave *)p)->flags == 0) {
            {
            s32 b = ((MusWave *)p)->base;
            if ((b & 0xFF000000) != 0xFF000000)
                ((MusWave *)p)->base = b += wptr;
            }
            WAVE(i * 4)->flags = 1;
            wave = WAVE(i * 4);
            if (wave->loop)
                wave->loop += pptr;
            wave = WAVE(i * 4);
            if (wave->type == 0)
                wave->book += pptr;
        }
        i++;
    } while (i < ptr->count);
    }
    osWritebackDCacheAll();
}
