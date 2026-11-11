typedef struct { u8 pad[6]; u16 type; } Cmd;
typedef struct { u8 pad[0x20]; u32 count; Cmd cmds[1]; } Sub;
typedef struct { u8 pad[8]; Sub *sub; u8 pad2[0x2C]; } Entry;
typedef struct { u8 pad[0x20]; u16 n; u8 pad2[0x1A]; Entry e[1]; } Mgr;
typedef void (*CmdFn)(Entry *, s32);
void heapFreeBlock(Sub *);
s32 memset();
extern CmdFn D_8009BF88[];
extern s8 gStreamReady;
extern char D_800A73E0[];

/* Runs every command in each entry's command list (each command calls the
   handler at D_8009BF88[type], passing the entry and arg1), frees each list, then
   clears the entry count and the 0x460-byte area at D_800A73E0+0x6C0C. */
void func_80015C74(Mgr *mgr, s32 arg1)
{
  s32 idx;
  u32 k;
  Cmd *cmd;
  Entry *entry;
  for (idx = 0; idx < mgr->n; idx++) {
    entry = &mgr->e[idx];
    cmd = entry->sub->cmds;
    for (k = 0; k < entry->sub->count; k++, cmd++)
      (*(CmdFn *)((u8 *)D_8009BF88 + (cmd->type << 2)))(entry, arg1);
    heapFreeBlock(entry->sub);
  }
  mgr->n = 0;
  memset(D_800A73E0 + 0x6C0C, 0, 0x460);
  gStreamReady = 0;
}
