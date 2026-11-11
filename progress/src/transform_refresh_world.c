/* Transform node: +0 dirty flag, +4 parent, +8 local matrix, +0x48 world matrix. */
typedef struct Mat4 { s32 m[16]; } Mat4;

typedef struct Transform {
    s32 dirty;
    struct Transform *parent;
    Mat4 local;
    Mat4 world;
} Transform;

void mtx_concat(char *a, char *b, char *c);

/* Same as transform_update_world: refreshes the parent chain, then the world matrix is
 * parent->world * local, or a copy of local for a dirty root. */
void transform_refresh_world(Transform *node) {
    if (node->parent != 0) {
        transform_refresh_world(node->parent);
        mtx_concat((char *)node->parent->world.m, (char *)node->local.m, (char *)node->world.m);
    } else if (node->dirty != 0) {
        node->dirty = 0;
        node->world = node->local;
    }
}
