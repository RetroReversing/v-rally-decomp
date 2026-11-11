s32 text_load_and_parse();
s32 str_len();
s32 str_ncat();
extern char D_800A47AC[];

/* Appends the fixed suffix D_800A47AC to the path at +0x4C of the stat request, then loads the file. Mode 2 also passes the key at +0x98. */
void statLoadFile(char *req)
{
  char *temp_s0;
  s32 temp_v0;

  temp_s0 = req + 0x4C;
  temp_v0 = str_len(temp_s0);
  str_ncat(temp_s0, D_800A47AC, temp_v0);
  if (*((s32 *) (req + 0x44)) == 2)
  {
    text_load_and_parse(temp_s0, req + 0x98);
  }
  else
  {
    text_load_and_parse(temp_s0, NULL);
  }
}
