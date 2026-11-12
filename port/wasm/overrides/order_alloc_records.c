/* port (WebAssembly build): returns poolAlloc's result. The matched C is void and leaves it in $v0, where its caller
 * (func_8001BDA0, the matrix pool's setup) takes it on the console; here the caller got 0 and every matrix went to
 * address 0. The same C with `return` should still match: it belongs in the matched C. */
s32 poolAlloc(s32, s32);

/* Allocates count order records of 64 bytes each from pool 6. */
s32 order_alloc_records(s32 count) {
    return poolAlloc(6, count << 6);
}
