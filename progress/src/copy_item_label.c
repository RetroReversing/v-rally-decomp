void strCpy();

/* Copy a label string into the item's label field at offset 0x10. */
void copy_item_label(void *item_ptr, void *src_label) {
    strCpy((unsigned char *)item_ptr + 0x10, src_label);
}
