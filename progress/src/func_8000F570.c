typedef struct { int m[16]; } Matrix;
typedef struct VRTransform {
    int dirty;
    struct VRTransform *parent;
    Matrix local;
    Matrix world;
} VRTransform;
void mtx_concat(char *a, char *b, char *c);

/* Same as TransformUpdate: brings a transform's world matrix up to date from its parent chain,
 * or copies local to world for a dirty root node. */
void func_8000F570(VRTransform *node) {
    if (node->parent != 0) {
        func_8000F570(node->parent);
        mtx_concat((char *)&node->parent->world, (char *)&node->local, (char *)&node->world);
    } else if (node->dirty != 0) {
        node->dirty = 0;
        node->world = node->local;
    }
}
