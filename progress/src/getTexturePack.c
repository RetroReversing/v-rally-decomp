typedef struct Tex3 {u16 h0,h2,type,width,height;u8 a,b;u32 c;u8 **pal,**image;u32 x,y;} Tex3;
typedef struct {u8 count,pad[3];Tex3 **tex;} Pack3;
void order_lookup_info(s32,s32*,s32*);
Pack3 *func_800555A0(s32,u16);
void func_800556C4(Pack3*);
Pack3 *func_80081664(s32,s32);
void func_80055424(s32,u16,Pack3*);

/* Gets the texture pack for pack_id, creating it if needed. A new pack is
 * laid out in memory: a header with one Tex3 pointer per texture, then each
 * texture's descriptor, palette pointers and image pointers, with 8-byte
 * alignment where the hardware needs it. Returns the pack. */
Pack3 *getTexturePack(s32 pack_id,s32 extra_size){
s32 size,other;
Pack3 *pack;
u8 *p;
u8 i,j;
u8 n1,n2;
u32 bcount;
order_lookup_info(pack_id,&size,&other);
pack=func_800555A0(pack_id,(u16)(size+extra_size));
if(pack){func_800556C4(pack);return pack;}
pack=func_80081664(6,pack_id);
pack->count=*((u8*)pack+size-1);
func_80055424(pack_id,(u16)(size+extra_size),pack);
pack->tex=(Tex3**)((u8*)pack+8);
p=(u8*)pack+(pack->count*4+8);
for(i=0;i<pack->count;i++){
while((u32)p&7)p++;
pack->tex[i]=(Tex3*)p;
p+=32;
pack->tex[i]->pal=(u8**)p;
p+=pack->tex[i]->a*4;
pack->tex[i]->image=(u8**)p;
{Tex3 *t=pack->tex[i]; t->x=0;
bcount=t->b;}
pack->tex[i]->y=0;
p+=bcount*4;
if(*(u16*)&pack->tex[i]->a==0x101) {
if(pack->tex[i]->type==0xa0){
pack->tex[i]->pal[0]=p;
pack->tex[i]->image[0]=p;
}else{
pack->tex[i]->pal[0]=p;
p+=pack->tex[i]->type*2;
pack->tex[i]->image[0]=p;
}
if(pack->tex[i]->type==16)p+=(pack->tex[i]->width*pack->tex[i]->height)/2;
else if(pack->tex[i]->type==256)p+=pack->tex[i]->width*pack->tex[i]->height;
else p+=(pack->tex[i]->width*pack->tex[i]->height)*4;
}else if(pack->tex[i]->a==1 && (n1=pack->tex[i]->b)>1){
pack->tex[i]->pal[0]=p;
p+=pack->tex[i]->type*2;
for(j=0;j<n1;j++){
while((u32)p&7)p++;
pack->tex[i]->image[j]=p;
if(pack->tex[i]->type==16)p+=(pack->tex[i]->width*pack->tex[i]->height)/2;
else if(pack->tex[i]->type==0x109)p+=pack->tex[i]->width*pack->tex[i]->height;
}
}else if((n2=pack->tex[i]->a)>1 && pack->tex[i]->b==1){
u8 a1;
a1=n2;
for(j=0;j<a1;j++){
pack->tex[i]->pal[j]=p;
p+=pack->tex[i]->type*2;
}
while((u32)p&7)p++;
pack->tex[i]->image[0]=p;
if(pack->tex[i]->type==16)p+=(pack->tex[i]->width*pack->tex[i]->height)/2;
else if(pack->tex[i]->type==256)p+=pack->tex[i]->width*pack->tex[i]->height;
}
}
return pack;
}
