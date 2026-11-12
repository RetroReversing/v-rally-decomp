/* Looks up the keyframe/track sample at `index` in a track object and writes three
 * s32 values (x, y, z) to `out`. Indices past the object's count wrap into the
 * owner's table. Returns the s16 entry at the sample's +4 slot. */
s16 track_sample_lookup(void *obj, s32 index, void *out)
{
  s32 i;
  s32 baseX;
#ifdef PORT
  char *data;
#else
  s32 data;
#endif
  s32 byteOff;
  s32 unit;
  int xOffset;
  void *table;
#ifdef PORT
  void *first;
#else
  s32 first;
#endif
  u16 count;
  void *owner;
  void *parent;
  i = index;
  count = *(u16*)((char*)obj+0x88);
  if (i < (s32)count) {
    owner = obj;
#ifdef PORT
    first = *(void**)((char*)obj+0x78);
#else
    first = *(s32*)((char*)obj+0x78);
#endif
    do {
      unit = (i<<1);
#ifdef PORT
      data = *(char**)((char*)first+0x1C);
#else
      data = *(s32*)((char*)first+0x1C);
#endif
      unit = (s32)unit+i;
    } while(0);
  } else {
    if (i || obj) {
      parent = *(void**)((char*)obj+0x5C);
      owner = obj;
    } else {
      parent = *(void**)((char*)obj+0x5C);
      owner = obj;
    }
    if (parent != NULL) owner = parent;
    table = *(void**)((char*)owner+0x78);
    do {
      i = (i-count)+1;
      unit = (i<<1);
      unit = (s32)unit+i;
#ifdef PORT
      data = *(char**)((char*)table+0x1C);
#else
      data = *(s32*)((char*)table+0x1C);
#endif
    } while(0);
  }
  byteOff = (s32)unit*4;
  xOffset = 6;
  baseX = *(s32*)((char*)owner+0x24);
  *(s32*)((char*)out) = *(s16*)(byteOff+data+xOffset)+baseX;
#ifdef PORT
  *(s32*)((char*)out+4) = *(s16*)(byteOff+*(char**)((char*)*(void**)((char*)owner+0x78)+0x1c)+8)+*(s32*)((char*)owner+0x28);
  *(s32*)((char*)out+8) = *(s16*)(byteOff+*(char**)((char*)*(void**)((char*)owner+0x78)+0x1c)+10)+*(s32*)((char*)owner+0x2c);
  return *(s16*)(i*12+*(char**)((char*)*(void**)((char*)owner+0x78)+0x1c)+4);
#else
  *(s32*)((char*)out+4) = *(s16*)(byteOff+*(s32*)((char*)*(void**)((char*)owner+0x78)+0x1c)+8)+*(s32*)((char*)owner+0x28);
  *(s32*)((char*)out+8) = *(s16*)(byteOff+*(s32*)((char*)*(void**)((char*)owner+0x78)+0x1c)+10)+*(s32*)((char*)owner+0x2c);
  return *(s16*)(i*12+*(s32*)((char*)*(void**)((char*)owner+0x78)+0x1c)+4);
#endif
}
