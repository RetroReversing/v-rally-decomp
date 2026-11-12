typedef struct Vec3 { u16 x,y,z; } Vec3;
typedef struct Vertex { u16 pad[3]; Vec3 pos; } Vertex;
typedef struct MeshAux { u8 pad[28]; Vertex *vertices; } MeshAux;
typedef struct Mesh { u8 pad[0x4c]; s32 base; u8 pad50[4]; Vec3 *src; u8 pad58[0x20]; MeshAux *aux; u8 pad7c[12]; u16 count,stride; } Mesh;
void *poolAlloc();

/* Builds the mesh's vertex buffer: allocates the aux block and count vertices of 12 bytes,
 * then copies each vertex position from the source array, starting at base and stepping
 * by stride. */
void func_800307C8(Mesh *mesh) {
s16 buf[4]; s32 i,j,off,count; Vertex *dst;
mesh->aux=poolAlloc(1,32);
mesh->aux->vertices=poolAlloc(1,mesh->count*12);
count=mesh->count;
if(count>0) {
i=0;j=0;
do {
dst=mesh->aux->vertices;
off=i*mesh->stride;
off+=mesh->base;
#ifdef PORT
((Vertex*)((u8 *)dst+j))->pos.x=mesh->src[off].x;
((Vertex*)((u8 *)mesh->aux->vertices+j))->pos.y=mesh->src[off].y;
((Vertex*)((u8 *)mesh->aux->vertices+j))->pos.z=mesh->src[off].z;
#else
((Vertex*)(j+(u32)dst))->pos.x=mesh->src[off].x;
((Vertex*)(j+(u32)mesh->aux->vertices))->pos.y=mesh->src[off].y;
((Vertex*)(j+(u32)mesh->aux->vertices))->pos.z=mesh->src[off].z;
#endif
i++; j+=12;
}while(i<mesh->count);
}
}
