typedef struct { s32 x, y, z; } Vec3i;
extern int D_800AFA6C;
extern unsigned char D_800C7FA0;
extern unsigned short D_800C8202;
extern unsigned char D_800C8200;
extern unsigned char D_800C81FC;
extern unsigned short D_800C8240;
void *find_named_node();
s32 streamSetCurrent();
s32 func_80084BF0();
s32 func_80085778();
extern u16 D_8009BAA0[8][5];
extern s32 D_8009BAF0[];
extern char D_800A1814[];
extern char D_800A73E0[];
extern char gOrderState[];
extern char gStreamState[];
extern void *gRecords;
#define CAM (*((char **) (gStreamState + 0x7CD6)))
#define TRK (*((char **) (D_800A73E0 + 0x6C24)))

/* Per-frame camera follow for the car at car: when the race's lap/checkpoint
 * index has changed, updates the camera position from the car's track node,
 * refreshes the node cache (D_8009BAA0/D_8009BAF0 ring), and copies the
 * target into the camera block. */
void camera_follow_car(char *car)
{
  Vec3i vec;
  s32 pad[1];
  s32 var_s0;
  u16 temp_a1;
  s32 temp_v0;
  s32 temp_v0_2;
  u32 new_var;
  char *temp_a1_2;
  char *var_s2;
  char *var_s3;
  if (D_800AFA6C != (((u16 *) D_800A1814)[*((u16 *) (((char *) gRecords) + 0x22))] - 1))
  {
    *((s32 *) (CAM + 0x130)) = 0;
    *((f32 *) (CAM + 0x134)) = 100.0f;
    *((s32 *) (CAM + 0x138)) = 0;
    *((f32 *) (CAM + 0x114)) = 1.0f;
    if (TRK != NULL)
    {
      var_s3 = *((char **) (CAM + 0x24));
      if (D_800C7FA0 == 1)
      {
        var_s3 = *((char **) (var_s3 + 4));
      }
      var_s2 = *((char **) (car + 0x8C));
      if (var_s2 == NULL)
      {
        *((void **) (car + 0x8C)) = find_named_node(D_8009BAF0[0]);
      }
      {
        u16 *counter = &D_800C8202;
        temp_a1 = *counter;
        *counter = (u16) (temp_a1 + 1);
      }
      if (((u16) D_8009BAA0[*((u16 *) (((char *) gRecords) + 0x22))][D_800C8200]) < temp_a1)
      {
        temp_v0 = D_800C8200 + 1;
        D_800C8200 = temp_v0;
        temp_v0 &= 0xFF;
        {
          void *r = find_named_node(D_8009BAF0[temp_v0]);
          char *p = gRecords;
          *((void **) (car + 0x8C)) = r;
          temp_v0 = D_8009BAA0[*((u16 *) (p + 0x22))][D_800C8200];
        }
        if (temp_v0 == 0)
        {
          temp_v0_2 = D_800C8200 + 1;
          D_800C8200 = temp_v0_2;
          do
          {
            *((void **) (car + 0x8C)) = find_named_node(D_8009BAF0[temp_v0_2 & 0xFF]);
          }
          while (0);
        }
      }
      if (D_800C81FC == 0)
      {
        D_800C8202 = (u16) (D_800C8202 - 1);
      }
      if (D_800C8240 & 0x800)
      {
        var_s0 = func_80084BF0(0);
        func_80085778(0, var_s0);
        if (var_s0 & 8)
        {
          var_s2 += 0x34;
          temp_a1_2 = *((char **) TRK);
          new_var = (u32) (var_s2 - temp_a1_2);
          if (((u32) ((*((u16 *) (TRK + 4)) - 1) * 0x34)) < new_var)
          {
            var_s2 = temp_a1_2;
          }
          *((void **) (car + 0x8C)) = var_s2;
        }
      }
      {
        char *c = CAM;
        *((f32 *) (c + 0x118)) = (f32) (*((s32 *) ((*((char **) (car + 0x8C))) + 0xC)));
        *((f32 *) (c + 0x11C)) = (f32) (*((s32 *) ((*((char **) (car + 0x8C))) + 0x10)));
        *((f32 *) (c + 0x120)) = (f32) (*((s32 *) ((*((char **) (car + 0x8C))) + 0x14)));
        vec = *(Vec3i *) (*((char **) (var_s3 + 0x58)) + 0xC);
        *((f32 *) (c + 0x124)) = (f32) vec.x;
        *((f32 *) (c + 0x128)) = (f32) vec.y;
        *((f32 *) (c + 0x12C)) = (f32) vec.z;
        *((s32 *) (c + 0x108)) = 0;
      }
    }
    streamSetCurrent(CAM);
  }
}
