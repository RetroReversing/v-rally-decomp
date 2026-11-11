typedef struct { s32 x, y, z; } Vec3S32;
typedef struct { s16 x, y, z; } Vec3S16;
typedef struct { Vec3S32 v; s32 pad[2]; } Rec;
typedef struct { u8 pad[0x10]; Rec c[12]; Rec a[12]; Rec b[12]; } RecSet;
void *find_region_containing(s32, Vec3S32 *);
void func_80028E94(void *, Vec3S16 *, u32);
void func_8002C044(void *);
void mat3_mul_vec3_q12(s32, Rec *, Rec *);
extern s32 gMirrorListHead;

static inline void vec_add(Vec3S32 *a, Vec3S32 *b, Vec3S32 *d)
{
  d->x = a->x + b->x;
  d->y = a->y + b->y;
  d->z = a->z + b->z;
}

/* Per-frame update of the object's 12 record slots: transforms each slot, looks up the
   cell containing its position, and stores the cell pointer and offset from its origin. */
void func_8002BD40(u8 *obj)
{
  Vec3S32 pos;
  Vec3S16 offset;
  u32 i;
  u8 *cell;

  *(s32 *)(*(u8 **)(obj + 0x8C) + 0x334) = 0;
  *(s32 *)(*(u8 **)(obj + 0x8C) + 0x100) = 0;
  for (i = 0; i < 12; i++)
  {
    mat3_mul_vec3_q12(*(s32 *)(obj + 0x5C) + 0x40, &(*(RecSet **)(obj + 0x80))->c[i], &(*(RecSet **)(obj + 0x80))->a[i]);
    vec_add(&(*(RecSet **)(obj + 0x80))->a[i].v, (Vec3S32 *)(*(u8 **)(obj + 0x58) + 0xC), &(*(RecSet **)(obj + 0x80))->b[i].v);
    pos = *(&(*(RecSet **)(obj + 0x80))->b[i].v);
    cell = find_region_containing(gMirrorListHead, &pos);
    *(u8 **)(*(u8 **)(obj + 0x8C) + i * 4) = cell;
    offset.x = pos.x - *(s32 *)(cell + 0x24);
    offset.y = pos.y - *(s32 *)(cell + 0x28);
    offset.z = pos.z - *(s32 *)(cell + 0x2C);
    func_80028E94(obj, &offset, i);
  }
  func_8002C044(obj);
}
