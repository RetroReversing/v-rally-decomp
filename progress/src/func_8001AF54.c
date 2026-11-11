extern char D_800A73E0[];
extern char gStreamState[];
extern u8 D_8009BBBC;
extern char D_15DB10[];
extern char D_BB9470[];
void add_pos_bias_words(void *, s32);
void func_8001A19C(void *);
void func_8001AE40(void *);
void func_8004D414(s32);
void *findEntryById(s32);
void func_80081514(void *, s32, s32);
typedef struct ObjList
{
  u8 *entries;
  u16 count;
} ObjList;

/* Activates an object list `list` of 0x3C-byte entries: resets every entry,
 * makes `list` the current list and points its active-entry slot at the entry
 * chosen by the state record. Then sets the flag bits on the selected entry's
 * object, depending on the mode byte, and finishes with the list setup routine
 * (or the fallback block copy when D_8009BBBC is set). Returns `list`. */
void *func_8001AF54(ObjList *list)
{
  ObjList *self;
  u8 *cur;
  s32 i;
  s32 n;
  u8 *entry;
  s32 *obj;
  u8 *state_rec;
  u16 cur_idx;
  s32 sel_idx;
  u8 *entry2;
  s32 obj_id;
  s32 off;
  s32 pad[2];
  add_pos_bias_words(list, 1);
  cur = list->entries;
  n = list->count;
  i = 0;
  self = list;
  if (n > 0)
  {
    do
    {
      func_8001A19C(cur);
      i += 1;
      cur += 0x3C;
    }
    while (i < self->count);
  }
  state_rec = *((u8 **) (gStreamState + 0x7CD2));
  cur_idx = *((u16 *) (state_rec + 0x10));
  off = cur_idx * 0x3C;
  sel_idx = *((s32 *) (gStreamState + 0x3262));
  *((void **) (gStreamState + 0x7CDE)) = list;
  ((ObjList *) (gStreamState + 0x326A))->entries = self->entries + off;
  entry = self->entries + (sel_idx * 0x3C);
  if ((*((u8 *) (D_800A73E0 + 0x6C01))) == 1)
  {
    func_8004D414(*((s32 *) (entry + 0x24)));
  }
  obj = findEntryById(*((s32 *) (entry + 0x24)));
  if ((*((u8 *) (D_800A73E0 + 0x6C01))) == 1)
  {
    obj[4] &= ~2;
    obj[4] &= ~1;
    obj[4] &= ~0x10;
  }
  else
  {
    obj[4] = (obj[4] | 2) & (~1);
    *((s32 *) ((*((u8 **) (gStreamState + 0x326A))) + 0x10)) |= 4;
  }
  state_rec = *((u8 **) (gStreamState + 0x7CD2));
  cur_idx = *((u16 *) (state_rec + 0x10));
  entry2 = self->entries;
  entry2 += ((s32) cur_idx) * 0x3C;
  obj_id = *((s32 *) (entry2 + 0x24));
  *((u8 **) (gStreamState + 0x326A)) = entry2;
  obj = findEntryById(obj_id);
  if ((*((u8 *) (D_800A73E0 + 0x6C01))) == 1)
  {
    obj[4] = (obj[4] & (~2)) | 0x11;
  }
  else
  {
    obj[4] = (obj[4] & (~2)) | 1;
  }
  if (D_8009BBBC == 0)
  {
    func_8001AE40(self);
  }
  else
  {
    func_80081514(D_15DB10, D_BB9470 - D_15DB10, 1);
  }
  return list;
}
