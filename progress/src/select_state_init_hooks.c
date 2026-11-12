extern void *gSelectState;
s32 select_copy_entry_label();
extern char func_8007A29C[];
extern char func_8007A9A8[];
extern char func_8007AA94[];

/* Resets the select state: runs select_copy_entry_label, installs the three callbacks at
 * +0x288..+0x290 and clears the byte at +0x228. */
s32 select_state_init_hooks(void) {
    select_copy_entry_label();
    *(void **)((char *)gSelectState + 0x288) = func_8007A29C;
    *(void **)((char *)gSelectState + 0x28C) = func_8007A9A8;
    *(void **)((char *)gSelectState + 0x290) = func_8007AA94;
    *(s8 *)((char *)gSelectState + 0x228) = 0;
    return 0;
}
