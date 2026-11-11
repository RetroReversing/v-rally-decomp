extern char D_800A73E0[];
extern char gOrderState[];
extern char gStreamState[];
void *poolAlloc(s32, s32);
void memset(void *, s32, s32);

/* Resets the game block and sets up the root record: stores arg0 and arg1 in the state,
 * allocates the buffers (arg2 selects the heap), writes a table of three records, and names
 * the root object "ROOT". Returns the state block (s3), which is also saved at D_800A73E0+0x6BC0. */
char *func_80081260(s32 arg0, s32 arg1, s32 arg2)
{
  char *game;
  char *state;
  char *bufA;
  char *root;
  unsigned char four;
  char *root_ptr;
  char *tmp;
  struct Rec
  {
    s8 x;
    s8 y;
    s8 a;
    s8 b;
    s8 z;
  } *r;
  state = gOrderState + 0x8A30;
  memset(state, 0, 0xC14C);
  *((s32 *) (gOrderState + 0x8AB0)) = arg0;
  *((s32 *) (gStreamState + 0x30A2)) = arg1;
  *((s32 *) (gOrderState + 0x8ABC)) = 0;
  game = gOrderState;
  *((s32 *) (game + 0x8AC0)) = 0;
  *((void **) (game + 0x8AC4)) = poolAlloc(arg2, 0x1B8A0);
  *((void **) (game + 0x8AC8)) = poolAlloc(arg2, 0x1ADB0);
  bufA = poolAlloc(6, 0x2000);
  *((void **) (gStreamState + 0x308A)) = bufA;
  r = (struct Rec *) (gStreamState + 0x30AA);
  r[0].x = 0x50;
  r[0].y = 0x4B;
  r[0].a = 3;
  four = 4;
  r[0].b = four;
  r[0].z = 0;
  r[2].x = 0x50;
  r[1].x = 0x50;
  r[2].y = 0x4B;
  r[1].y = 0x4B;
  r[1].a = 1;
  r[1].b = 2;
  r[1].z = 0;
  r[2].a = 5;
  r[2].b = 6;
  r[2].z = 0;
  *((s32 *) (gStreamState + 0x30A6)) = 0;
  *((void **) (gStreamState + 0x308E)) = bufA;
  root = poolAlloc(arg2, 0x468);
  *((char **) (game + 0x8AB4)) = root;
  *((s32 *) (root + 0x10)) = 0;
  *((s32 *) ((*((char * volatile *) (game + 0x8AB4))) + 0x14)) = 0;
  (*((char * volatile *) (game + 0x8AB4)))[0] = 'R';
  (*((char * volatile *) (game + 0x8AB4)))[1] = 'O';
  (*((char * volatile *) (game + 0x8AB4)))[2] = 'O';
  (*((char * volatile *) (game + 0x8AB4)))[3] = 'T';
  (*((char * volatile *) (game + 0x8AB4)))[4] = 0;
  *((s32 *) ((*((char * volatile *) (game + 0x8AB4))) + 0x7C)) = 0;
  *((s32 *) ((*((char * volatile *) (game + 0x8AB4))) + 0x80)) = 0;
  root_ptr = *((char * volatile *) (game + 0x8AB4));
  tmp = state;
  *((char **) (D_800A73E0 + 0x6BC0)) = tmp;
  *((char **) (game + 0x8AB8)) = root_ptr;
  return tmp;
}
