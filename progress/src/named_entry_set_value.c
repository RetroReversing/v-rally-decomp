/* Looks up the named entry and sets the value in its record at offset 0x10; returns 1 if found, 0 otherwise. */ void *list_find_node(void **, u8 *);
s32 named_entry_set_value(void **list, u8 *name, s32 value) {
void *node;
node=list_find_node(list,name);
if(node!=NULL){*(s32 *)((u8 *)*(void **)((u8 *)node + 0x10) + 8) = value;return 1;}else{return 0;}
}
