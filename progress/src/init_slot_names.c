typedef struct {
    u8 b[13];
} Buf13;

typedef struct {
    u8 b[14];
} Buf14;

typedef struct {
    Buf13 name_a;
    u8 pad_c[3];
    Buf14 name_d;
    u8 pad_e[2];
} SlotNames;

extern Buf13 D_800A4E60;
extern Buf14 D_800A4E70;
extern char D_800A4E80[];
void memset(void *, s32, s32);
void func_8004C7F0(void *);
void resolve_path(void *);

/* Copies two slot name templates into local buffers, zeroes their padding and
   resolves the base path. Then stamps slot numbers 1..8 into each name (at
   byte 7 of name_a, byte 8 of name_d) and calls func_8004C7F0 for each. */
void init_slot_names(void) {
    SlotNames names;
    s32 slot;

    names.name_a = D_800A4E60;
    memset(names.pad_c, 0, 3);
    names.name_d = D_800A4E70;
    memset(names.pad_e, 0, 2);
    resolve_path(D_800A4E80);
    slot = 1;
    do {
        names.name_a.b[7] = slot + 0x30;
        func_8004C7F0(&names.name_a);
        slot++;
    } while ((u8)slot < 9);
    slot = 1;
    do {
        names.name_d.b[8] = slot + 0x30;
        func_8004C7F0(&names.name_d);
        slot++;
    } while ((u8)slot < 9);
}
