typedef struct SceneMtx { s32 m[16]; } SceneMtx;
typedef struct SceneNode { s32 dirty; struct SceneNode *parent; SceneMtx local; SceneMtx world; } SceneNode;
void mtx_concat(char *a, char *b, char *c);

/* Same as scene_node_update: refreshes the world matrix from the parent chain, or copies
 * the local matrix when a root node is dirty. Kept as a separate copy in the ROM. */
void scene_node_update_d(SceneNode *node) {
    if (node->parent != 0) {
        scene_node_update_d(node->parent);
        mtx_concat((char *)&node->parent->world, (char *)&node->local, (char *)&node->world);
    } else if (node->dirty != 0) {
        node->dirty = 0;
        node->world = node->local;
    }
}
