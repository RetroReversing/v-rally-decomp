typedef struct { int m[16]; } Matrix;
typedef struct VRTransform {
    int dirty;
    struct VRTransform *parent;
    Matrix local;
    Matrix world;
} VRTransform;
void mtx_concat(char *a, char *b, char *c);

/* Brings a transform's world matrix up to date. A node with a parent first updates the parent
 * chain, then sets world = parent->world * local. A root node with its dirty flag set copies
 * local to world and clears the flag. */
void TransformUpdate(VRTransform *node) {
    if (node->parent != 0) {
        TransformUpdate(node->parent);
        mtx_concat((char *)&node->parent->world, (char *)&node->local, (char *)&node->world);
    } else if (node->dirty != 0) {
        node->dirty = 0;
        node->world = node->local;
    }
}
