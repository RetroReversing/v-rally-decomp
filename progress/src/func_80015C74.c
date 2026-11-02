typedef struct { u8 pad[6]; u16 type; } Cmd;
typedef struct { u8 pad[0x20]; u32 count; Cmd cmds[1]; } Sub;
typedef struct { u8 pad[8]; Sub *sub; u8 pad2[0x2C]; } Entry;
typedef struct { u8 pad[0x20]; u16 n; u8 pad2[0x1A]; Entry e[1]; } Mgr;
typedef void (*CmdFn)(Entry *, s32);
void func_8007EE9C(Sub *);
s32 memset();
extern CmdFn D_8009BF88[];
extern s8 D_800A16D5;
extern char D_800A73E0[];
void func_80015C74(Mgr *m, s32 arg1)
{
  s32 i;
  u32 j;
  Cmd *c;
  Entry *e;
  for (i = 0; i < m->n; i++) {
    e = &m->e[i];
    c = e->sub->cmds;
    for (j = 0; j < e->sub->count; j++, c++)
      (*(CmdFn *)((u8 *)D_8009BF88 + (c->type << 2)))(e, arg1);
    func_8007EE9C(e->sub);
  }
  m->n = 0;
  memset(D_800A73E0 + 0x6C0C, 0, 0x460);
  D_800A16D5 = 0;
}
