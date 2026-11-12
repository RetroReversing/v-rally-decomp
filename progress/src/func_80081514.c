void func_80081260(void);
void stream_build_entry_table(int a);

/* Resets the stream state and rebuilds the entry table from the given argument. */
void func_80081514(int unused0, int unused1, int table_arg)
{
    func_80081260();
    stream_build_entry_table(table_arg);
}
