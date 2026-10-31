#define W(p,o) (*(s32 *)((char *)(p)+(o)))
#define P(p,o) (*(char **)((char *)(p)+(o)))
#define H(p,o) (*(u16 *)((char *)(p)+(o)))
extern s8 D_8009E270[];
extern s8 D_8009E271[];
extern s8 D_8009E278[];
extern s8 D_8009E279[];
extern s8 D_8009E284[];
extern s8 D_8009E285[];
void func_8002DA98(void *, void *);
void func_8002E530(void *, void *, void *);
void func_8002E778(void *, void *);
void func_8002D75C(int, int, int, int *);
typedef struct 
{
  u16 m[9];
  char pad[14];
} __attribute__((aligned(4))) Matrix32;
typedef union 
{
  struct 
  {
    u16 x;
    u16 z;
    u32 pad;
  } p;
  s32 word;
} Pair;
u8 func_8002C6EC(void *arg0, void *arg1)
{
  int v[3];
  int out[3];
  char *new_var3;
  s16 delta[3];
  Matrix32 face;
  Matrix32 mat;
  s16 bounds[6];
  char *new_var;
  Pair pair;
  Pair zero;
  Pair dir;
  s8 flags[8];
  u16 new_var2;
  char reserved[8];
  int test;
  int k;
  int count;
  int faceIndex;
  int otherCount;
  int oldCount;
  unsigned int i;
  int new_var4;
  unsigned int j;
  char *a;
  char *b;
  char *rot;
  char *record;
  char * volatile faces;
  char *other;
  s8 *table;
  rot = *((char **) (((char *) arg1) + 0x5c));
  a = P(arg1, 0x8c);
  b = P(arg0, 0x8c);
  faces = a + 0x104;
  other = b + 0x338;
  oldCount = W(a, 0x100);
  otherCount = W(b, 0x334);
  rot += 0x40;
  func_8002DA98(rot, &mat);
  bounds[2] = W(P(arg1, 0x80), 0xec) + 15;
  bounds[3] = W(P(arg1, 0x80), 0xf0) + 15;
  bounds[5] = W(P(arg1, 0x80), 0xf4) + 15;
  bounds[0] = W(P(arg1, 0x80), 0x88) - 15;
  bounds[1] = W(P(arg1, 0x80), 0x8c) - 15;
  bounds[4] = W(P(arg1, 0x80), 0x90) - 50;
  {
    s8 *p = flags;
    do
    {
      *(p++) = 1;
    }
    while (p < (flags + 6));
  }
  delta[0] = W(P(arg0, 0x5c), 0x54) - W(rot, 0x14);
  delta[1] = W(P(arg0, 0x5c), 0x58) - W(rot, 0x18);
  delta[2] = W(P(arg0, 0x5c), 0x5c) - W(rot, 0x1c);
  func_8002E530(&mat, delta, out);
  if (out[0] > 0)
  {
    flags[1] = 0;
  }
  else
    if (out[0] == 0)
  {
    flags[3] = (flags[1] = 0);
  }
  else
    if (out[0] < 0)
  {
    flags[3] = 0;
  }
  if (out[1] > 0)
  {
    flags[4] = 0;
  }
  else
    if (out[1] == 0)
  {
    flags[4] = 0;
    flags[5] = 0;
  }
  else
    if (out[1] < 0)
  {
    flags[5] = 0;
  }
  if (out[2] > 0)
  {
    flags[0] = 0;
  }
  else
    if (out[2] == 0)
  {
    flags[0] = 0;
    flags[2] = 0;
  }
  else
    if (out[2] < 0)
  {
    flags[2] = 0;
  }
  zero.p.x = 0;
  zero.p.z = 0;
  dir.p.x = out[0];
  dir.p.z = out[2];
  for (i = 0, table = D_8009E270; i < 4; i++, table += 2)
  {
    if (flags[i])
    {
      pair.p.x = W(P(arg1, 0x80), (table[0] * 20) + 0x60);
      pair.p.z = W(P(arg1, 0x80), (table[0] * 20) + 0x68);
      func_8002D75C(pair.word, zero.word, dir.word, &test);
      if (test > 0)
      {
        new_var4 = i * 2;
        pair.p.x = W(P(arg1, 0x80), (D_8009E271[new_var4] * 20) + 0x60);
        pair.p.z = W(P(arg1, 0x80), (D_8009E271[new_var4] * 20) + 0x68);
        func_8002D75C(pair.word, zero.word, dir.word, &test);
        if (test < 0)
        {
          break;
        }
        flags[i] = 0;
      }
    }
  }

  for (j = i + 1; j < 4; j++)
  {
    flags[j] = 0;
  }

  if ((i == 0) || (i == 2))
  {
    dir.p.x = out[1];
    record = (table += 2);
    dir.p.z = out[2];
    table = D_8009E278 + new_var4;
    for (j = i; j < 6; j++, record)
    {
      if (flags[j])
      {
        pair.p.x = W(P(arg1, 0x80), (table[0] * 20) + 0x64);
        pair.p.z = W(P(arg1, 0x80), (table[0] * 20) + 0x68);
        func_8002D75C(pair.word, zero.word, dir.word, &test);
        if (test > 0)
        {
          pair.p.x = W(P(arg1, 0x80), (D_8009E279[j * 2] * 20) + 0x64);
          pair.p.z = W(P(arg1, 0x80), (D_8009E279[j * 2] * 20) + 0x68);
          func_8002D75C(pair.word, zero.word, dir.word, &test);
          if (test < 0)
          {
            break;
          }
          flags[j] = 0;
        }
      }
    }

  }
  else
  {
    dir.p.x = out[0];
    dir.p.z = out[1];
    table = D_8009E284;
    table = table + new_var4;
    for (j = i; j < 6; j++, table += 2)
    {
      if (flags[j])
      {
        pair.p.x = W(P(arg1, 0x80), (table[0] * 20) + 0x60);
        pair.p.z = W(P(arg1, 0x80), (table[0] * 20) + 0x64);
        func_8002D75C(pair.word, zero.word, dir.word, &test);
        if (test < 0)
        {
          pair.p.x = W(P(arg1, 0x80), (D_8009E285[j * 2] * 20) + 0x60);
          pair.p.z = W(P(arg1, 0x80), (D_8009E285[j * 2] * 20) + 0x64);
          func_8002D75C(pair.word, zero.word, dir.word, &test);
          if (test > 0)
          {
            break;
          }
          flags[j] = 0;
        }
      }
    }

  }
  faceIndex = j;
  record = faces + (oldCount * 56);
  count = 0;
  for (i = 0; i < 12; i++)
  {
    v[0] = W(P(arg0, 0x80), 0x1f0 + (i * 20));
    v[1] = W(P(arg0, 0x80), 0x1f4 + (i * 20));
    do
    {
      v[2] = W(P(arg0, 0x80), 0x1f8 + (i * 20));
      v[0] -= W(rot, 0x14);
    }
    while (0);
    v[1] -= W(rot, 0x18);
    v[2] -= W(rot, 0x1c);
    func_8002E778(v, out);
    out[0] += out[1] + out[2];
    if (out[0] > 0x270ff)
    {
      continue;
    }
    delta[0] = v[0];
    delta[1] = v[1];
    delta[2] = v[2];
    func_8002E530(&mat, delta, v);
    if (!((((((v[0] < bounds[2]) && (bounds[0] < v[0])) && (v[1] < bounds[3])) && (bounds[1] < v[1])) && (v[2] < bounds[5])) && (bounds[4] < v[2])))
    {
      continue;
    }
    switch (faceIndex)
    {
      case 0:
        out[0] = bounds[4] - v[2];
        face.m[0] = H(rot, 0);
        face.m[3] = H(rot, 6);
        face.m[6] = H(rot, 12);
        face.m[1] = -H(rot, 4);
        face.m[4] = -H(rot, 10);
        face.m[7] = -H(rot, 16);
        face.m[2] = H(rot, 2);
        face.m[5] = H(rot, 8);
        face.m[8] = H(rot, 14);
        break;

      case 1:
        out[0] = v[2] - bounds[5];
        face.m[0] = -H(rot, 0);
        face.m[3] = -H(rot, 6);
        face.m[6] = -H(rot, 12);
        face.m[1] = H(rot, 4);
        face.m[4] = H(rot, 10);
        face.m[7] = H(rot, 16);
        face.m[2] = H(rot, 2);
        face.m[5] = H(rot, 8);
        face.m[8] = H(rot, 14);
        break;

      case 2:
        out[0] = bounds[0] - v[0];
        face.m[0] = -H(rot, 4);
        face.m[3] = -H(rot, 10);
        face.m[6] = -H(rot, 16);
        face.m[1] = -H(rot, 0);
        face.m[4] = -H(rot, 6);
        face.m[7] = -H(rot, 12);
        face.m[2] = H(rot, 2);
        face.m[5] = H(rot, 8);
        face.m[8] = H(rot, 14);
        break;

      case 3:
        out[0] = v[0] - bounds[2];
        face.m[0] = H(rot, 4);
        face.m[3] = H(rot, 10);
        face.m[6] = H(rot, 16);
        face.m[1] = H(rot, 0);
        face.m[4] = H(rot, 6);
        face.m[7] = H(rot, 12);
        face.m[2] = H(rot, 2);
        face.m[5] = H(rot, 8);
        face.m[8] = H(rot, 14);
        break;

      case 4:
        out[0] = bounds[1] - v[1];
        new_var = rot;
        face.m[0] = H(new_var, 4);
        face.m[3] = H(rot, 10);
        face.m[6] = H(rot, 16);
        face.m[1] = -H(rot, 2);
        face.m[4] = -H(rot, 8);
        face.m[7] = -H(rot, 14);
        face.m[2] = H(rot, 0);
        face.m[5] = H(rot, 6);
        face.m[8] = H(rot, 12);
        break;

      case 5:
        out[0] = v[1] - bounds[3];
        face.m[0] = -H(rot, 4);
        face.m[3] = -H(rot, 10);
        face.m[6] = -H(rot, 16);
        face.m[1] = H(new_var3 = rot, 2);
        face.m[4] = H(rot, 8);
        face.m[7] = H(rot, 14);
        face.m[2] = H(rot, 0);
        face.m[5] = H(rot, 6);
        face.m[8] = H(rot, 12);
        break;

    }

    if (out[0] > 0)
    {
      out[0] = 0;
    }
    else
      if (i >= 4)
    {
      char *p = other + (otherCount * 48);
      W(p, 0x28) = out[0] << 4;
      W(p, 0x24) = i;
      P(p, 0x20) = arg1;
      *((Matrix32 *) p) = face;
      W(p, 0x2c) = 1;
      W(P(arg0, 0x8c), 0x334) = otherCount + 1;
    }
    if (i < 4)
    {
      W(P(arg0, 0x80), 0x310 + (i * 4)) = out[0];
      W(P(arg0, 0x80), 0x320 + (i * 4)) = 1;
      *((Matrix32 *) ((P(arg0, 0x8c) + 0x30) + (i * 32))) = face;
    }
    if (out[0] < 0)
    {
      count++;
      W(record, 0x30) = out[0] << 4;
      W(record, 0x34) = 1;
      W(record, 0x2c) = i;
      P(record, 0x28) = arg0;
      H(record, 0) = (faceIndex) ? (v[0]) : (0);
      H(record, 2) = v[1];
      H(record, 4) = v[2];
      face.m[1] = -face.m[1];
      face.m[4] = -face.m[4];
      face.m[7] = -face.m[7];
      new_var2 = face.m[2];
      face.m[2] = -new_var2;
      face.m[5] = -face.m[5];
      face.m[8] = -face.m[8];
      *((Matrix32 *) (record + 8)) = face;
      if (oldCount < 10)
      {
        W(P(arg1, 0x8c), 0x100) = oldCount + 1;
      }
    }
  }

  return (u8) count;
}
