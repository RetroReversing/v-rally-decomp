void *dispatch_name_handler();
s32 str_len();
s32 str_ncat();
extern char sNameSuffix[];
extern char gOrderState[];
extern char stream_state[];

/* Attaches a sprite to a record: appends the suffix in sNameSuffix to the
   record's name (at +0x4C), looks up the sprite through dispatch_name_handler, stores
   it in gOrderState+0x8A28 and sets flag 0x40 in its word at +0x80. */
void record_attach_sprite(s32 *record)
{
  s32 *src;
  s32 name_len;
  void *arg;
  s32 max;
  char *name;
  s32 flags;
  void *sprite;
  void *hdr;
  int offset;
  sprite = record;
  name = sprite + 0x4C;
  arg = name;
  name_len = str_len(arg);
  src = &sNameSuffix;
  arg = name;
  src = &sNameSuffix;
  max = name_len;
  str_ncat(arg, &sNameSuffix, max);
  hdr = stream_state + 0x5A76;
  hdr = *((void **) (stream_state + 0x5A76));
  arg = *((void **) (hdr + 0x10));
  src = sprite;
  sprite = dispatch_name_handler(arg, src);
  flags = *((s32 *) (((char *) sprite) + 0x80));
  *((void **) (gOrderState + 0x8A28)) = sprite;
  flags |= 0x40;
  offset = 0x80;
  *((s32 *) (((char *) sprite) + offset)) = flags;
}
