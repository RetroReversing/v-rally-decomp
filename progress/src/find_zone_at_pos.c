typedef struct {
    u8 pad0[0x34];
    s32 minX;
    u8 pad1[4];
    s32 maxX;
    u8 pad2[4];
    s32 minZ;
    s32 maxZ;
} ZoneBounds;

typedef struct {
    u8 pad[0x58];
    ZoneBounds *secondary;
    ZoneBounds *primary;
} ZoneObj;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

/* Returns the object's primary zone if pos lies inside its X/Z bounds, otherwise
   its secondary zone if pos lies inside that, otherwise 0 (the last comparison). */
s32 find_zone_at_pos(ZoneObj *obj, Vec3 *pos) {
    s32 xPos;
    s32 zPos;
    s32 cmp;
    s32 coord;
    ZoneBounds *zone;

    zone = obj->primary;
    if (((zone != NULL) && (cmp = zone->minX, coord = pos->x, cmp = cmp < coord, (cmp != 0)) && (cmp = zone->maxX, cmp = coord < cmp, (cmp != 0)) && (cmp = zone->minZ, coord = pos->z, cmp = cmp < coord, (cmp != 0)) && (cmp = zone->maxZ, cmp = coord < cmp, (cmp != 0))) || ((zone = obj->secondary, cmp = (s32) obj, (zone != NULL)) && (coord = zone->minX, xPos = pos->x, coord = coord < xPos, (coord != 0)) && (coord = zone->maxX, coord = xPos < coord, (coord != 0)) && (coord = zone->minZ, zPos = pos->z, coord = coord < zPos, (coord != 0)) && (coord = zone->maxZ, coord = zPos < coord, (coord != 0)))) {
        cmp = (s32) zone;
    }
    return cmp;
}
