/* delta = second point minus first point; pts holds two packed xyz triples. */ void vec3_sub_points(s32 *pts, s32 *delta) {
    s32 ax;
    s32 ay;
    s32 az;
    s32 bx;
    s32 by;
    s32 bz;

    ax = pts[0];
    ay = pts[1];
    az = pts[2];
    pts += 3;
    bx = pts[0];
    by = pts[1];
    bz = pts[2];
    delta[0] = bx - ax;
    delta[1] = by - ay;
    delta[2] = bz - az;
}
