extern char gOrderState[];
/* Clears bit 4 in the word at +0xC of the order state's attached object at +0x7920, if one is set. */
void order_clear_obj_flag4(void) { if (*(char **)(gOrderState + 0x7920) != NULL) { *(s32 *)(*(char **)(gOrderState + 0x7920) + 0xC) &= ~4; } }
