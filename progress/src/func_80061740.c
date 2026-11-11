typedef struct {s32 w[8];} T8; typedef struct {u8 pad[0x2E];u8 x;} Obj;
extern T8 D_800A55C4; extern Obj *gRecords;
extern void func_8004D31C(); extern s32 classifyStreamCode(void*); extern void resolve_path(s32); extern void func_8004C7F0(void*);
typedef struct { u32 w[160]; } Args;
/* Loads the entry table in block: each 14-byte entry's tag picks a path id, which is resolved
 * and pushed to the list. Clears the header lock flag while it runs. */
void func_80061740(Args block) {
T8 paths; u8 savedLock; u8 count; s32 i; void *entry; u8 *hdr;
hdr=(u8*)&block+4;
paths=D_800A55C4;
savedLock=gRecords->x; gRecords->x=0;
func_8004D31C();
if (!(count = hdr[17])) i=0; else i=0;
if (count) do {
entry = (char *)((u8*)&block); entry += (s32)(0x24C+(i&255)*14);
resolve_path(paths.w[classifyStreamCode(entry)&255]);
func_8004C7F0(entry); i++;
} while ((u32)(i&255) < (u32)count);
gRecords->x=savedLock;
}
