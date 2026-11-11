typedef struct { s32 m[16]; } Matrix4;

void mtx_concat(char *a, char *b, char *c);

/* Recomputes a transform node's world matrix. A node with a parent first updates
   the parent, then world = parent->world * local. A root node just copies local
   to world once, when its dirty flag is set. */
void func_80028300(char *node) {
    if (*(char **)(node + 4) != 0) {
        func_80028300(*(char **)(node + 4));
        mtx_concat(*(char **)(node + 4) + 0x48, node + 8, node + 0x48);
    } else if (*(int *)node != 0) {
        *(int *)node = 0;
        *(Matrix4 *)(node + 0x48) = *(Matrix4 *)(node + 8);
    }
}
