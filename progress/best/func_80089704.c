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
    u8 *wave_list;
} MusPtrBank;

extern f64 D_800A6DB8;
void func_8008989C(s32 *p, s32 a, s32 n);
void osWritebackDCacheAll(void);

void func_80089704(s32 pptr, s32 wptr) {
    MusPtrBank *ptr;
    s32 i;
    s32 off;
    s32 c;
    s32 b;
    u8 *p;
    f64 scale;
    u8 unused[8];
    MusWave *wave;

    ptr = (MusPtrBank *)pptr;
    if (ptr->flags & 0x80000000)
        return;
    ptr->flags |= 0x80000000;
    func_8008989C((s32 *)&ptr->basenote, pptr, 3);
    func_8008989C((s32 *)ptr->wave_list, pptr, ptr->count);
    i = 0;
    if (ptr->count > 0) {
    scale = D_800A6DB8;
    off = 0;
    do {
        p = ptr->detune + off;
        b = *p;
        if (b & 0x80) c = (b & 0xFF) - 0x100; else c = b & 0xFF;
        *(f32 *)p = (f32)c * scale;
        b = ptr->basenote[i] - 0x30;
        if (b & 0x80) c = (b & 0xFF) - 0x100; else c = b & 0xFF;
        *(f32 *)p += (f32)c;
        wave = *(MusWave **)(off + ptr->wave_list);
        if (wave->flags == 0) {
            if ((wave->base & 0xFF000000) != 0xFF000000)
                wave->base += wptr;
            (*(MusWave **)(off + ptr->wave_list))->flags = 1;
            wave = *(MusWave **)(off + ptr->wave_list);
            if (wave->loop)
                wave->loop += pptr;
            wave = *(MusWave **)(off + ptr->wave_list);
            if (wave->type == 0)
                wave->book += pptr;
        }
        i++;
        off += 4;
    } while (i < ptr->count);
    }
    osWritebackDCacheAll();
}
