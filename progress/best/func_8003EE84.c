extern int D_800C35A0;
void func_8003EE84(void *arg0){
s32 temp_a2,temp_v1; void **new_var; s32 var_v0_2,var_v0; u8 *temp_a0; char *temp_a1;
temp_a1=arg0;
temp_a2=*(s32*)(*(s32*)(temp_a1+0xA8)+0x24);
if(temp_a2!=0){
temp_a0=(u8*)D_800C35A0;
temp_v1=(temp_a0+*(u16*)(temp_a1+0x76))[0x32];
temp_a0=temp_a0+temp_v1*0x28;
temp_a0=temp_a0+*(u16*)(temp_a1+0x78);
temp_v1=temp_a0[0x44];
var_v0_2=temp_v1;
if(temp_v1<0x41){var_v0=var_v0_2-0x16;}else{var_v0=var_v0_2-0x41;}
*(s16*)(temp_a1+0x7A)=var_v0;
new_var=(void**)((char*)temp_a2+0x6C);
if(*(s32*)((char*)*new_var+8)==1){
var_v0_2=*(u16*)((char*)*(void**)((char*)*(void**)(temp_a1+0xA8)+0x178)+0xA)+6;
}else{
var_v0_2=*(u16*)((char*)*(void**)((char*)*(void**)(temp_a1+0xA8)+0x178)+0xA)+0x10;
}
*(s16*)(temp_a1+0xE)=var_v0_2;
}}
