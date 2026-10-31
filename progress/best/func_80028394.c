typedef struct VRNode { u8 pad00[0x4c]; u32 unk4c; u8 pad50[4]; u8 *unk54;u8 pad58[4]; struct VRNode *unk5c; u8 pad60[0x10]; u16 *unk70; u8 pad74[0x14]; u16 unk88; u16 unk8a; } VRNode;
extern void func_8002D75C(s32,s32,s32,s32 *);
void func_80028394(VRNode *arg0) {
 union V2 {s32 word;u16 v[2];}; struct V8 {union V2 p;s32 pad;}; struct V8 va,vb,vc,vd; s32 result,row,col,idx,next,last,flag,edge,width,rows,cols,x,y,z; u8 *p; u16 *q; VRNode *cur; cur=arg0;
 do { row=0; rows=cur->unk8a-1; cols=cur->unk88-1;
  if(rows>0) do { col=0; if(cols>0) do {
   width=cur->unk8a; idx=width*col+row; p=cur->unk54+idx*6;
   va.p.v[0]=*(u16*)(p+0); va.p.v[1]=*(u16*)(p+4); next=idx+1; p=cur->unk54+next*6;
   vb.p.v[0]=*(u16*)(p+0); vb.p.v[1]=*(u16*)(p+4); next=idx+width; p=cur->unk54+next*6;
   vc.p.v[0]=*(u16*)(p+0); vc.p.v[1]=*(u16*)(p+4); next++; p=cur->unk54+next*6;
   vd.p.v[0]=*(u16*)(p+0); vd.p.v[1]=*(u16*)(p+4); flag=0; last=col*(width-1)+row;
   if(row!=0 && row!=rows-1) { q=(u16*)((u8*)cur->unk70+last*2); if(cur->unk4c<(u32)row) edge=q[1]; else edge=q[-1]; if(edge==0) flag=1; } else flag=1;
   if(flag) {
    x=*(s16*)(cur->unk54+(idx+1)*6+2)-*(s16*)(cur->unk54+idx*6+2); if(x<0)x=-x;
    y=(s16)va.p.v[0]-(s16)vb.p.v[0]; if(y<0)y=-y; z=(s16)va.p.v[1]-(s16)vb.p.v[1]; if(z<0)z=-z;
    if(va.p.word==vb.p.word || (y+z)*5<x) flag=1;
    x=*(s16*)(cur->unk54+next*6+2)-*(s16*)(cur->unk54+(idx+width)*6+2); if(x<0)x=-x;
    y=(s16)vc.p.v[0]-(s16)vd.p.v[0]; if(y<0)y=-y; z=(s16)vc.p.v[1]-(s16)vd.p.v[1]; if(z<0)z=-z;
    if(vc.p.word==vd.p.word || (y+z)*5<x) flag=1;
   }
   func_8002D75C(va.p.word,vb.p.word,vc.p.word,&result); if(result<0)flag=1;
   func_8002D75C(vc.p.word,va.p.word,vd.p.word,&result); if(result<0)flag=1;
   func_8002D75C(vd.p.word,vc.p.word,vb.p.word,&result); if(result<0)flag=1;
   func_8002D75C(vb.p.word,vd.p.word,va.p.word,&result); if(result<0)flag=1;
   col++; if(flag)cur->unk70[last]=0;
  } while(col<cols); row++;
 } while(row<rows);
 cur=cur->unk5c;
 } while((cur!=arg0) & (cur!=NULL));
}
