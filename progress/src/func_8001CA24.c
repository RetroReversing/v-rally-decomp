extern char gOrderState[];
void func_80023EF4(int obj, int ctx);
/* Copies the object's fields into the context block held in the current order state. */
void func_8001CA24(int obj) { func_80023EF4(obj, *(int *)(gOrderState + 0x23D0)); }
