typedef struct {
    u8 pad0[0x14];
    u16 count;
    u8 pad16[0x2C4 - 0x16];
} Obj;
typedef struct {
    u8 pad0[0x20];
    u16 id;
    s16 cur;
} St;
extern u8 D_800C352C[];
extern St *D_800C35A0;
extern Obj *D_800D0634;
void func_8005946C(s32, u16);

s32 func_80063D9C(s32 arg0)
{
    St *st;
    s8 found = -1;
    s8 bit;
    s8 tries;
    s32 mask;
    u16 id;
    s32 off;
    Obj *base = D_800D0634;

    bit = ((u8 *)D_800C35A0)[0x23];
    tries = 0;
    if (base[D_800C35A0->id].count - 1 > 0) {
        st = D_800C35A0;
        off = st->id * sizeof(Obj);
        do {
            if (bit < ((Obj *)(off + (s32)base))->count - 1) {
                bit++;
            } else {
                bit = 0;
            }
            id = st->id;
            mask = 1 << bit;
            if ((D_800C352C[id] & mask) == mask) {
                found = bit;
                break;
            }
            tries++;
            base = D_800D0634;
        } while (tries < base[id].count - 1);
    }
    if (found != -1) {
        D_800C35A0->cur = found;
        func_8005946C(arg0, found);
    }
    return 0;
}
