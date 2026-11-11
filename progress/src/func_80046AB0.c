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



extern unsigned char D_800ADFA8;
extern unsigned char D_800ADFE1;
extern int D_800ADFE8;
extern unsigned char gCurCount;


s32 func_80042CC4();
s32 func_800448A4();
s32 func_80044908();
void *findEntryById();
s8 func_80084C0C();
extern s32 gPadFlags;
extern s32 (*D_800A0280[])(void *,void *);
extern s32 (*D_800A0284)(void *, void *);
extern char D_800A73E0[];
extern char gStreamState[];
extern void *gRecords;

/* Per-object update: when the object is active, runs the logic callbacks of the two
   child lists of its parent (type 1 entries use the D_800A0284 hook, others the
   D_800A0280 table), then the controller-side checks and the state update that
   keeps the parent's record in step. */
void func_80046AB0(void *obj) {
    char pad[24];
    s32 (*handler)(void *, void *);
    s32 count;
    s32 i;
    s32 cur_child;
    u16 mode;
    void *item;
    void *ctl;
    void *info;
    void *parent;
    void *cam_obj;
    void *first_list;
    void *second_list;
    void *entry;
    void *sibling;

    M2C_FIELD(*(void * *)((char *)obj + 0x9C), s32 *, 0x38) = 1;
    if (!(*(s32 *)((char *)obj + 0x14) & 0x80) && (M2C_FIELD(gRecords, u16 *, 0x1E) != 7)) {
        parent = **(void ** *)((char *)obj + 0x8C);
        first_list = *(void * *)((char *)parent + 0x5C);
        cur_child = 0;
        if (first_list != NULL) {
            cur_child = (s32) first_list & -(*(s32 *)((char *)first_list + 0x50) != 0);
        }
        second_list = *(void * *)((char *)parent + 0x58);
        sibling = 0;
        if (second_list != NULL) {
            sibling = (s32) second_list & -(*(s32 *)((char *)second_list + 0x50) != 0);
        }
        if ((sibling != 0) && (M2C_FIELD(*(void * *)((char *)obj + 0x48), s32 *, 0) < 4)) {
            count = *(s32 *)((char *)sibling + 0x50);
            entry = *(void * *)((char *)sibling + 0x68);
            i = 0;
            if (count > 0) {
                do {
                    if (*(s16 *)((char *)entry + 4) == 1) {
                        D_800A0284(entry, obj);
                    }
                    i += 1;
                    entry += 8;
                } while (i < count);
            }
        }
        entry = *(void * *)((char *)parent + 0x68);
        if (entry != NULL) {
            count = *(s32 *)((char *)parent + 0x50);
            i = 0;
            if (count > 0) {
loop_main:
                {
                    item = entry;
                    handler = D_800A0280[*(s16 *)((char *)entry + 4)];
                    handler(item, obj);
                    entry += 8;
                    i += 1;
                }
                if(i < count) goto loop_main;
            }
        }
        if ((cur_child != 0) && (M2C_FIELD(*(void * *)((char *)obj + 0x48), s32 *, 0) < 4)) {
            count = *(s32 *)((char *)cur_child + 0x50);
            entry = *(void * *)((char *)cur_child + 0x68);
            i = 0;
            if (count > 0) {
                do {
                    if (*(s16 *)((char *)entry + 4) == 1) {
                        D_800A0284(entry, obj);
                    }
                    i += 1;
                    entry += 8;
                } while (i < count);
            }
        }
        if (((!(gPadFlags & 0x800) && !(*(s32 *)((char *)obj + 0x14) & 0x100)) || (M2C_FIELD(gRecords, u16 *, 0x1E) == 0)) && (func_80044908(obj), ((M2C_FIELD(*(void * *)((char *)obj + 0x48), s32 *, 0) < 4) != 0)) && !(*(s32 *)((char *)obj + 0x14) & 0x200)) {
            func_800448A4(obj);
        } else {
            *(s32 *)((char *)obj + 0x14) = (s32) (*(s32 *)((char *)obj + 0x14) & ~0x20);
        }
        if ((D_800ADFA8 == 0) && (D_800ADFE1 != 0) && (M2C_FIELD(*(void * *)((char *)obj + 0x48), s32 *, 0) < 4) && (*(s16 *)((char *)parent + 8) == (D_800ADFE8 - 5)) && (**(s32 * *)((char *)obj + 0x70) == (gCurCount - 1))) {
            cam_obj = findEntryById(M2C_FIELD(*(void * *)(gStreamState + 0x326A), s32 *, 0x24));
            if (!(*(u16 *)((char *)cam_obj + 0xA) & 1)) {
                { s32 flags=*(s32 *)((char *)cam_obj+0x10);
                D_800ADFA8=1;
                *(s32 *)((char *)cam_obj+0x10)=(flags|2)&~1; }
            }
        }
        ctl = gRecords;
        mode = *(u16 *)((char *)ctl + 0x1E);
        if ((mode != 0) & (mode != 5)) {
            if (*(u16 *)((char *)ctl + 0x1C) != 0) {
                func_80042CC4(obj);
                ctl=gRecords;
                goto block_40;
            }
        } else {
block_40:
            if ((*(u16 *)((char *)ctl + 0x1C) != 0) && (*(u16 *)((char *)ctl + 0x1E) == 0)) {
                info = *(void * *)((char *)obj + 0x48);
                { void *rec=ctl; s32 idx=M2C_FIELD((ctl+*(s32 *)((char *)info+0x2C)),u8 *,0x32); rec+=idx*0x28;
                if (M2C_FIELD(rec,u16 *,0x4E)>=0x10U) {
                    M2C_FIELD(*(void * *)((char *)obj + 0x4C), s32 *, 0x14) = (s32) (func_80084C0C(*(u8 *)((char *)info + 3), 0x10000) + 0x10);
                }}
            }
        }
    }
}
