char *func_8002B180(char *, char *);
s32 func_8002AA6C(char *, char *);
void func_8002ABC0(s32, char *, char *);

/* Parses command lines from text (CR-terminated) until a '[' section header or end.
 * Each command's name is looked up to get its id, then its arguments are parsed and run.
 * Returns the position of the section header, or end. */
char *func_8002B540(char *text, char *end) {
    char *lineEnd;
    for (;;) {
        text = func_8002B180(text, end);
        if (text >= end || *text == '[') {
            return text;
        }
        func_8002ABC0(func_8002AA6C(text, end), text, end);
        lineEnd = text;
        do {
            while (*lineEnd++ != '\r') {
                if (!(lineEnd < end)) {
                    break;
                }
            }
            if (lineEnd == end) {
                break;
            }
            lineEnd++;
        } while (*lineEnd == '\r');
        text = lineEnd;
    }
}
