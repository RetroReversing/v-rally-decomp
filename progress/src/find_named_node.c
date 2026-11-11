s32 strCmp(); extern void *gMirrorListHead; extern char D_800A40EC[],D_800A40F4[],D_800A73E0[];
/* Finds the node with the given name. Two fixed names resolve through the scene tree at gMirrorListHead; any other name is searched for in the table of 0x34-byte entries at D_800A73E0+0x6c24 (entry count is the u16 at +4). Returns the matching node, or the last entry examined. */
s32 *find_named_node(char *name) {
s32 *node; s32 *table_start; s32 found=0;
if(strCmp(D_800A40F4,name)==0 || strCmp(D_800A40EC,name)==0){
node=gMirrorListHead; node=*(s32 **)((char*)node+0x5c);
if(strCmp(D_800A40F4,name)==0) node=*(s32 **)((char*)node+0x7c);
else node=*(s32 **)((char*)*(s32 **)((char*)node+0x7c)+0x24);
}else{
node=*(s32 **)(*(char **)(D_800A73E0+0x6c24)); table_start=node;
do { if(strCmp(node,name)==0) found=1; else {node=(s32*)((char*)node+0x34);
if((u32)((*(u16*)(*(char **)(D_800A73E0+0x6c24)+4)-1)*0x34)<(u32)(((s32)((char*)node-(char*)table_start)*(s32)0xC4EC4EC5)>>2)) found=1; }
}while((found&255)==0);
}return node;}
