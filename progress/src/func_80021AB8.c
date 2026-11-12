#define P21 gRecords
typedef struct 
{
  s32 x[10];
} Block21;
extern u8 *gRecords;
void func_80021A4C(void);
void list_for_each(s32, void (*)(void));
void records_restore_from_order(void);
void glyph_record_pack(s32);
void save_race_to_pak(void);
static inline Block21 *inline_fn()
{
  return (Block21 *) (P21 + 0x6c);
}

/* Restores the four 40-byte record blocks (at +0x44, +0x6c, +0x94, +0xbc) from
 * the copies taken before the last change, then rebuilds the glyphs for the
 * first four records. Does nothing once the state is 7. */
void func_80021AB8(s32 arg0)
{
  Block21 a;
  Block21 b;
  Block21 c;
  Block21 d;
  Block21 *p;
  Block21 *q;
  Block21 *r;
  Block21 *savedC;
  int slot0;
  Block21 *dstC;
  int slot2;
  Block21 *t;
  if ((*((u16 *) (P21 + 0x1e))) == 7)
  {
    return;
  }
  slot2 = 2;
  if (arg0)
  {
    list_for_each(arg0, func_80021A4C);
  }
  if (*((u16 *) (P21 + 0x1e)))
  {
    a = *((Block21 *) ((0, P21 + 0x44)));
    b = *inline_fn();
    c = *((Block21 *) (P21 + 0x94));
    d = *((Block21 *) (P21 + 0xbc));
    slot0 = 0;
    records_restore_from_order();
    glyph_record_pack(slot0);
    glyph_record_pack(1);
    glyph_record_pack(slot2);
    glyph_record_pack(3);
    p = (Block21 *) (P21 + 0x44);
    q = &a;
    r = q;
    t = r;
    *p = *t;
    p = inline_fn();
    q = &b;
    r = q;
    t = r;
    *p = *t;
    dstC = (Block21 *) (P21 + 0x94);
    savedC = &c;
    p = dstC;
    q = savedC;
    r = q;
    t = r;
    *p = *t;
    p = (Block21 *) (P21 + 0xbc);
    q = &d;
    r = q;
    t = r;
    *p = *t;
    save_race_to_pak();
  }
}
