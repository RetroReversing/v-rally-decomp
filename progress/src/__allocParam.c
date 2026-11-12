extern void *D_800A2500;

/* Pops one VRALParam off the free list at +0x2C of the synth object, or returns NULL when it is empty. */
VRALParam *__allocParam(void) {
    VRALParam *head;
    VRALParam *param;

    head = *(VRALParam **)((s8 *)D_800A2500 + 0x2C);
    param = NULL;
    if (head != NULL) {
        param = head;
        *(VRALParam **)((s8 *)D_800A2500 + 0x2C) = (VRALParam *)param->next;
        param->next = NULL;
    }
    return param;
}
