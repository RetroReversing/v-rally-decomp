#include "common.h"

typedef struct Vec3 { u16 x,y,z; } Vec3;
typedef struct Vertex { u16 pad[3]; Vec3 pos; } Vertex;
typedef struct MeshAux { u8 pad[28]; Vertex *vertices; } MeshAux;
typedef struct Mesh { u8 pad[0x4c]; s32 base; u8 pad50[4]; Vec3 *src; u8 pad58[0x20]; MeshAux *aux; u8 pad7c[12]; u16 count,stride; } Mesh;
void *func_8007EAA0();
void func_800307C8(Mesh *self) {
s16 buf[4]; s32 i,j,off,count; Vertex *dst;
self->aux=func_8007EAA0(1,32);
self->aux->vertices=func_8007EAA0(1,self->count*12);
count=self->count;
if(count>0) {
i=0;j=0;
do {
dst=self->aux->vertices;
off=i*self->stride;
off+=self->base;
((Vertex*)(j+(u32)dst))->pos.x=self->src[off].x;
((Vertex*)(j+(u32)self->aux->vertices))->pos.y=self->src[off].y;
((Vertex*)(j+(u32)self->aux->vertices))->pos.z=self->src[off].z;
i++; j+=12;
}while(i<self->count);
}
}
