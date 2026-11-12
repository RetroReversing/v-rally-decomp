/* Sets bit 0 of the flag word at flags, then stores value in a new order pool node. */
void flag_set_bit0();
void order_pool_store_value(int a);
void flag_set_then_call(int flags, int value) { flag_set_bit0(); order_pool_store_value(value); }
