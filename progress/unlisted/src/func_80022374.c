void *named_entry_lookup(void **, u8 *);
s32 func_80022374(void **list, u8 *name, s32 value) {
void *node;
node=named_entry_lookup(list,name);
if(node!=NULL){*(s32 *)((u8 *)*(void **)((u8 *)node + 0x10) + 8) = value;return 1;}else{return 0;}
}
