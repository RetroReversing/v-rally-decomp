typedef struct { char pad[8]; void (*cb)(s32, void *); s32 a, b; } Entry;
typedef struct {
  u8 pad[0x90];
  s32 slot;
  u8 pad94[4];
  u8 name[0x174 - 0x98];
  s32 extra;
} Obj41;
extern char D_800A0130[];
extern u8 *D_800C35A0;
extern u8 *D_800C7F84;
u8 *func_8004240C(s32);
Entry *func_8002255C(void *, void *);
s32 func_800223B4(void *, s32, s32, Entry *, s32);

s32 func_80041F24(Obj41 *arg0, u8 player)
{
  u8 idx;
  u8 *node;
  Entry *entry;
  s32 result;

  u16 mode;

  idx = arg0->slot;
  mode = *(u16 *)(D_800C35A0 + 0xE);
  if (idx == 3) {
    idx = (mode * 2) | 1;
  } else if (idx != 0) {
    idx = player * 2 - arg0->slot;
  }
  node = func_8004240C(idx);
  D_800C7F84 = node;
  entry = func_8002255C(D_800A0130, arg0->name);
  result = func_800223B4(node + 0x28, entry->a, entry->b, entry, arg0->extra);
  if (entry->cb) {
    entry->cb(result, arg0);
  }
  return result;
}
