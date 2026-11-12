/* Command handler: when op == 2, appends value to the list at obj+0x1C and bumps the count at obj+0x14. */
int func_80094580(char *obj, int op, int value) {
    char *list = *(char **)(obj + 0x1C);
    if (op == 2) {
        int n = *(int *)(obj + 0x14);
        *(int *)(obj + 0x14) = n + 1;
        ((int *)list)[n] = value;
    }
    return 0;
}
