/* Sets parameter `type` on the envelope at env. Type 1 sets the input, 3 appends the control `value`
 * to the envelope's control list, 4 and 9 reset the envelope and notify its input handler.
 * Other types go to the input handler. Always returns 0. */
s32 alEnvmixerParam(char *env, s32 type, s32 *value)
{
    char *obj = env;
    s32 *input;
    s32 *last;
    s32 (*handler)(s32 *, s32);

    switch (type) {
    case 1:
        *(s32 **)env = value;
        break;
    case 3:
        last = *(s32 **)(env + 0x40);
        if (last != NULL) {
            *last = (s32)value;
        } else {
            *(s32 **)(env + 0x3C) = value;
        }
        *(s32 **)(obj + 0x40) = value;
        break;
    case 4:
        obj = *(char **)env;
        *(s32 *)(env + 0x38) = 1;
        *(s32 *)(env + 0x48) = 0;
        *(s16 *)(env + 0x1A) = 1;
        if (obj != NULL) {
            input = (s32 *)obj;
            handler = *(s32 (**)(s32 *, s32))((char *)input + 8);
            handler(input, 4);
        }
        break;
    case 9:
        obj = *(char **)env;
        *(s32 *)(env + 0x48) = 1;
        if (obj != NULL) {
            input = (s32 *)obj;
            handler = *(s32 (**)(s32 *, s32))((char *)input + 8);
            handler(input, 9);
        }
        break;
    default:
        input = *(s32 **)env;
        if (input != NULL) {
            handler = *(s32 (**)(s32 *, s32))((char *)input + 8);
            handler(input, type);
        }
        break;
    }
    return 0;
}
