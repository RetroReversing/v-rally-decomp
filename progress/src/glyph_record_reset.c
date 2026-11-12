typedef struct {
    u16 enable : 1;
    u16 a : 5;
    u16 b : 5;
    u16 id : 5;
    u16 mode : 4;
    u16 param : 12;
    u16 on : 1;
    u16 level : 7;
    u16 c : 8;
    u8 d;
    u8 e;
    u16 w8;
    u16 wA;
    u16 wC;
} GlyphRecord;

extern u8 gRecordTier[];
extern GlyphRecord gRecordGlyphs[];

/* Resets glyph record slot `slot` to its default settings. The mode depends on the slot index. */
void glyph_record_reset(u8 slot) {
    GlyphRecord *r;

    gRecordTier[slot] = 2;
    r = &gRecordGlyphs[slot];
    r->on = 1;
    r->a = 0xF;
    r->b = 0xB;
    r->id = slot;
    r->level = 0x7F;
    r->c = 0x55;
    r->param = 0x492;
    switch (slot) {
    case 0:
        r->mode = 4;
        break;
    case 1:
        r->mode = 7;
        break;
    case 2:
        r->mode = 6;
        break;
    case 3:
        r->mode = 5;
        break;
    }
    r->wA = 0x4210;
    r->wC = 0x7583;
    r->w8 = 0;
    r->d = 0x55;
    r->e = 0x55;
    r->enable = 0;
}
