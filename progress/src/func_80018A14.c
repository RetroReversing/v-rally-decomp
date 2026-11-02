typedef struct { u8 b[8]; } Buf8;
typedef struct {
    u8 pad0[0x10];
    s32 x0, y0, x1, y1, z0, z1;
    u32 f28;
    s32 f2C;
} Ent;
typedef struct {
    Ent *ents;
    u16 n;
} Hdr;
typedef struct {
    Buf8 key;
    u32 val;
} Rec;
typedef struct {
    u8 pad0[0x20];
    u16 count;
    u16 last;
} Obj;
extern void func_80015460(s32, u32);
extern f32 D_8009CEC0[];
extern u32 D_800B56E8;
extern s32 D_800B56EC;
extern u32 D_800C7F80;
extern Hdr *D_800C6ED8;

Hdr *func_80018A14(Hdr *arg0, Obj *arg1, Buf8 *arg2)
{
    Hdr *h;
    Ent *e;
    s32 i;
    Rec *rec;

    D_800B56E8 = 0;
    func_80015460((s32)arg0, 1);
    arg1->last = arg1->count;
    rec = (Rec *)((u8 *)arg1 + (arg1->count * 0x38 + 0x3C));
    rec->key = *arg2;
    rec->val = D_800C7F80;
    arg1->count++;
    h = arg0;
    e = h->ents;
    for (i = 0; i < h->n; i++) {
        e[i].f2C += D_800B56EC;
        e[i].x0 = (s32)(e[i].x0 * D_8009CEC0[0]) - 500;
        e[i].x1 = (s32)(e[i].x1 * D_8009CEC0[0]) + 500;
        e[i].y0 = (s32)(e[i].y0 * D_8009CEC0[1]);
        e[i].y1 = (s32)(e[i].y1 * D_8009CEC0[1]);
        e[i].z0 = (s32)(e[i].z0 * D_8009CEC0[2]) - 500;
        e[i].z1 = (s32)(e[i].z1 * D_8009CEC0[2]) + 500;
        func_80015460(e[i].f2C, e[i].f28);
        {
            u32 t = e[i].f28;
            if (D_800B56E8 < t) {
                D_800B56E8 = t;
            }
        }
    }
    D_800C6ED8 = h;
    return h;
}
