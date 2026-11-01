typedef struct Node
{
  u32 pad;
  struct Node *next;
  u8 p[64];
  s32 *type;
} Node;
typedef struct
{
  char name[4];
  u32 time;
  s32 diff;
  u32 speed;
  u8 type;
  u8 idx;
  u8 car;
  u8 pad;
  Node *node;
} Entry;
typedef struct
{
  char name[10];
  u16 car;
  u8 pad[28];
} Driver;
typedef struct
{
  u8 pad0[0x1E];
  u16 track;
  u8 pad20[0x12];
  u8 slot[0x12];
  Driver drivers[8];
} Game;
typedef struct
{
  u32 lap[4];
  u32 dist[4];
} Rec;
extern Node **D_800B5C40;
extern Game *D_800C35A0;
extern Entry D_800C7F90[5];
extern u8 D_800C3616[];
extern u8 D_800C3654[];
extern u8 D_800C365A[];
extern u8 D_800C8002;
extern s32 D_800C7FF4;
extern s32 D_800C7FFC;
extern u8 D_800C3650[];
extern char D_800C7FF0[];
extern Rec D_800B55FC[];
extern s32 D_8009D540;
extern void func_80097E30(void *, s32, s32);
extern void func_80098290(void *, void *);
extern u8 func_80077FA8(u8);
void func_80078018(void)
{
  u8 i = 0;
  Node *node = *D_800B5C40;
  u8 k;
  s32 zz;
  s32 d;
  func_80097E30(D_800C7F90, 0, 120);
  while (node)
  {
    k = func_80077FA8(i);
    if (D_800C7F90[k].node)
      k--;
    D_800C7F90[k].node = node;
    func_80098290(D_800C7F90[k].name, D_800C35A0->drivers[D_800C35A0->slot[i]].name);
    d = D_800C35A0->drivers[D_800C35A0->slot[i]].car;
    D_800C7F90[k].idx = i;
    D_800C7F90[k].car = d;
    D_800C7F90[k].time = ((u32 (*)[8])D_800B55FC)[i][D_800C35A0->track];
    ((u32 (*)[8])D_800B55FC)[i][D_800C35A0->track + 4] /= 100;
    D_800C7F90[k].speed = (((u32 (*)[8])D_800B55FC)[i][D_800C35A0->track + 4] * D_8009D540 * 3600) /
               (((u32 (*)[8])D_800B55FC)[i][D_800C35A0->track] * 10);
    D_800C7F90[k].type = *node->type;
    node = node->next;
    i++;
  }
  for (zz = 0; (u8)zz < 4; zz++)
  {
    s32 t = D_800C7F90[(u8)zz].time;
    if (t)
    {
      s32 dd = t - (s32)D_800C7F90[0].time;
      if (dd < 0)
        dd = -dd;
      D_800C7F90[(u8)zz].diff = dd;
    }
    else
    {
      D_800C7F90[(u8)zz].diff = 0;
    }
  }
  func_80098290(D_800C7FF0, D_800C3616 + D_800C35A0->track * 64);
  {
  u8 *ev = (u8 *)D_800C35A0;
  D_800C7FF4 = *(s32 *)(D_800C3650 + ((*(u16 *)(ev + 0x1E) - 1) << 6));
  D_800C7FFC = D_800C365A[(*(u16 *)(ev + 0x1E) - 1) << 6];
  D_800C8002 = D_800C3654[(*(u16 *)(ev + 0x1E) - 1) << 6];
  }
}
