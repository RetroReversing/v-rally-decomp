void add_pos_bias_words(int a, int b);

/* Applies position bias to one entry and returns the pointer. */
int func_80015508(int words)
{
    add_pos_bias_words(words, 1);
    return words;
}
