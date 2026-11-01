#line 1 "reference.c"
u8 func_8002C6EC(void *arg0, void *arg1)
{
  Scratch frame;
  char *new_var3;
  char *new_var;
  u16 new_var2;
  int k;
  int count;
  int faceIndex;
  int otherCount;
  int oldCount;
  unsigned int i;
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
  func_8002DA98(rot, &frame.mat);
  frame.bounds[2] = W(P(arg1, 0x80), 0xec) + 15;
  frame.bounds[3] = W(P(arg1, 0x80), 0xf0) + 15;
  frame.bounds[5] = W(P(arg1, 0x80), 0xf4) + 15;
  frame.bounds[0] = W(P(arg1, 0x80), 0x88) - 15;
  frame.bounds[1] = W(P(arg1, 0x80), 0x8c) - 15;
  frame.bounds[4] = W(P(arg1, 0x80), 0x90) - 50;
  {
    s8 *p = frame.flags;
    do
    {
      *(p++) = 1;
    }
    while (p < (frame.flags + 6));
  }
  frame.delta[0] = W(P(arg0, 0x5c), 0x54) - W(rot, 0x14);
  frame.delta[1] = W(P(arg0, 0x5c), 0x58) - W(rot, 0x18);
  frame.delta[2] = W(P(arg0, 0x5c), 0x5c) - W(rot, 0x1c);
  func_8002E530(&frame.mat, frame.delta, &frame.out);
  if (frame.out.x > 0)
  {
    frame.flags[1] = 0;
  }
  else
    if (frame.out.x == 0)
  {
    frame.flags[3] = (frame.flags[1] = 0);
  }
  else
    if (frame.out.x < 0)
  {
    frame.flags[3] = 0;
  }
  if (frame.out.y > 0)
  {
    frame.flags[4] = 0;
  }
  else
    if (frame.out.y == 0)
  {
    frame.flags[4] = 0;
    frame.flags[5] = 0;
  }
  else
    if (frame.out.y < 0)
  {
    frame.flags[5] = 0;
  }
  if (frame.out.z > 0)
  {
    frame.flags[0] = 0;
  }
  else
    if (frame.out.z == 0)
  {
    frame.flags[0] = 0;
    frame.flags[2] = 0;
  }
  else
    if (frame.out.z < 0)
  {
    frame.flags[2] = 0;
  }
  frame.zero.p.x = 0;
  frame.zero.p.z = 0;
  frame.dir.p.x = frame.out.x;
  frame.dir.p.z = frame.out.z;
  for (i = 0, table = D_8009E270; i < 4; i++, table += 2)
  {
    if (frame.flags[i])
    {
      frame.pair.p.x = W(P(arg1, 0x80), (table[0] * 20) + 0x60);
      frame.pair.p.z = W(P(arg1, 0x80), (table[0] * 20) + 0x68);
      func_8002D75C(frame.pair.word, frame.zero.word, frame.dir.word, &frame.test);
      if (frame.test > 0)
      {
        frame.pair.p.x = W(P(arg1, 0x80), (D_8009E271[i * 2] * 20) + 0x60);
        frame.pair.p.z = W(P(arg1, 0x80), (D_8009E271[i * 2] * 20) + 0x68);
        func_8002D75C(frame.pair.word, frame.zero.word, frame.dir.word, &frame.test);
        if (frame.test < 0)
        {
          break;
        }
        frame.flags[i] = 0;
      }
    }
  }

  for (j = i + 1; j < 4; j++)
  {
    frame.flags[j] = 0;
  }

  if ((i == 2) || (i == 0))
  {
    frame.dir.p.x = frame.out.y;
    frame.dir.p.z = frame.out.z;
    table = D_8009E278 + i * 2;
    for (j = i; j < 6; j++, table += 2)
    {
      if (frame.flags[j])
      {
        frame.pair.p.x = W(P(arg1, 0x80), (table[0] * 20) + 0x64);
        frame.pair.p.z = W(P(arg1, 0x80), (table[0] * 20) + 0x68);
        func_8002D75C(frame.pair.word, frame.zero.word, frame.dir.word, &frame.test);
        if (frame.test > 0)
        {
          frame.pair.p.x = W(P(arg1, 0x80), (D_8009E279[j * 2] * 20) + 0x64);
          frame.pair.p.z = W(P(arg1, 0x80), (D_8009E279[j * 2] * 20) + 0x68);
          func_8002D75C(frame.pair.word, frame.zero.word, frame.dir.word, &frame.test);
          if (frame.test < 0)
          {
            break;
          }
          frame.flags[j] = 0;
        }
      }
    }

  }
  else
  {
    frame.dir.p.x = frame.out.x;
    frame.dir.p.z = frame.out.y;
    table = D_8009E284;
    table = table + i * 2;
    for (j = i; j < 6; j++, table += 2)
    {
      if (frame.flags[j])
      {
        frame.pair.p.x = W(P(arg1, 0x80), (table[0] * 20) + 0x60);
        frame.pair.p.z = W(P(arg1, 0x80), (table[0] * 20) + 0x64);
        func_8002D75C(frame.pair.word, frame.zero.word, frame.dir.word, &frame.test);
        if (frame.test < 0)
        {
          frame.pair.p.x = W(P(arg1, 0x80), (D_8009E285[j * 2] * 20) + 0x60);
          frame.pair.p.z = W(P(arg1, 0x80), (D_8009E285[j * 2] * 20) + 0x64);
          func_8002D75C(frame.pair.word, frame.zero.word, frame.dir.word, &frame.test);
          if (frame.test > 0)
          {
            break;
          }
          frame.flags[j] = 0;
        }
      }
    }

  }
  faceIndex = j;
  record = faces + (oldCount * 56);
  count = 0;
  for (i = 0; i < 12; i++)
  {
    frame.v = *((Vec3 *)(P(arg0, 0x80) + 0x1f0 + i*20));
    frame.v.x -= W(rot, 0x14);
    frame.v.y -= W(rot, 0x18);
    frame.v.z -= W(rot, 0x1c);
    func_8002E778(&frame.v, &frame.out);
    frame.out.x += frame.out.y + frame.out.z;
    if (frame.out.x > 0x270ff)
    {
      continue;
    }
    frame.delta[0] = frame.v.x;
    frame.delta[1] = frame.v.y;
    frame.delta[2] = frame.v.z;
    func_8002E530(&frame.mat, frame.delta, &frame.v);
    if (!((((((frame.v.x < frame.bounds[2]) && (frame.bounds[0] < frame.v.x)) && (frame.v.y < frame.bounds[3])) && (frame.bounds[1] < frame.v.y)) && (frame.v.z < frame.bounds[5])) && (frame.bounds[4] < frame.v.z)))
    {
      continue;
    }
    switch (faceIndex)
    {
      case 0:
        frame.out.x = frame.bounds[4] - frame.v.z;
        frame.face.m[0] = H(rot, 0);
        frame.face.m[3] = H(rot, 6);
        frame.face.m[6] = H(rot, 12);
        frame.face.m[1] = -H(rot, 4);
        frame.face.m[4] = -H(rot, 10);
        frame.face.m[7] = -H(rot, 16);
        frame.face.m[2] = H(rot, 2);
        frame.face.m[5] = H(rot, 8);
        frame.face.m[8] = H(rot, 14);
        break;

      case 1:
        frame.out.x = frame.v.z - frame.bounds[5];
        frame.face.m[0] = -H(rot, 0);
        frame.face.m[3] = -H(rot, 6);
        frame.face.m[6] = -H(rot, 12);
        frame.face.m[1] = H(rot, 4);
        frame.face.m[4] = H(rot, 10);
        frame.face.m[7] = H(rot, 16);
        frame.face.m[2] = H(rot, 2);
        frame.face.m[5] = H(rot, 8);
        frame.face.m[8] = H(rot, 14);
        break;

      case 2:
        frame.out.x = frame.bounds[0] - frame.v.x;
        frame.face.m[0] = -H(rot, 4);
        frame.face.m[3] = -H(rot, 10);
        frame.face.m[6] = -H(rot, 16);
        frame.face.m[1] = -H(rot, 0);
        frame.face.m[4] = -H(rot, 6);
        frame.face.m[7] = -H(rot, 12);
        frame.face.m[2] = H(rot, 2);
        frame.face.m[5] = H(rot, 8);
        frame.face.m[8] = H(rot, 14);
        break;

      case 3:
        frame.out.x = frame.v.x - frame.bounds[2];
        frame.face.m[0] = H(rot, 4);
        frame.face.m[3] = H(rot, 10);
        frame.face.m[6] = H(rot, 16);
        frame.face.m[1] = H(rot, 0);
        frame.face.m[4] = H(rot, 6);
        frame.face.m[7] = H(rot, 12);
        frame.face.m[2] = H(rot, 2);
        frame.face.m[5] = H(rot, 8);
        frame.face.m[8] = H(rot, 14);
        break;

      case 4:
        frame.out.x = frame.bounds[1] - frame.v.y;
        new_var = rot;
        frame.face.m[0] = H(new_var, 4);
        frame.face.m[3] = H(rot, 10);
        frame.face.m[6] = H(rot, 16);
        frame.face.m[1] = -H(rot, 2);
        frame.face.m[4] = -H(rot, 8);
        frame.face.m[7] = -H(rot, 14);
        frame.face.m[2] = H(rot, 0);
        frame.face.m[5] = H(rot, 6);
        frame.face.m[8] = H(rot, 12);
        break;

      case 5:
        frame.out.x = frame.v.y - frame.bounds[3];
        frame.face.m[0] = -H(rot, 4);
        frame.face.m[3] = -H(rot, 10);
        frame.face.m[6] = -H(rot, 16);
        frame.face.m[1] = H(new_var3 = rot, 2);
        frame.face.m[4] = H(rot, 8);
        frame.face.m[7] = H(rot, 14);
        frame.face.m[2] = H(rot, 0);
        frame.face.m[5] = H(rot, 6);
        frame.face.m[8] = H(rot, 12);
        break;

    }

    if (frame.out.x > 0)
    {
      frame.out.x = 0;
    }
    else
      if (i >= 4)
    {
      char *p = other + (otherCount * 48);
      W(p, 0x28) = frame.out.x << 4;
      W(p, 0x24) = i;
      P(p, 0x20) = arg1;
      *((Matrix32 *) p) = frame.face;
      W(p, 0x2c) = 1;
      W(P(arg0, 0x8c), 0x334) = otherCount + 1;
    }
    if (i < 4)
    {
      W(P(arg0, 0x80), 0x310 + (i * 4)) = frame.out.x;
      W(P(arg0, 0x80), 0x320 + (i * 4)) = 1;
      *((Matrix32 *) ((P(arg0, 0x8c) + 0x30) + (i * 32))) = frame.face;
    }
    if (frame.out.x < 0)
    {
      count++;
      W(record, 0x30) = frame.out.x << 4;
      W(record, 0x34) = 1;
      W(record, 0x2c) = i;
      P(record, 0x28) = arg0;
      H(record, 0) = (faceIndex) ? (frame.v.x) : (0);
      H(record, 2) = frame.v.y;
      H(record, 4) = frame.v.z;
      frame.face.m[1] = -frame.face.m[1];
      frame.face.m[4] = -frame.face.m[4];
      frame.face.m[7] = -frame.face.m[7];
      new_var2 = frame.face.m[2];
      frame.face.m[2] = -new_var2;
      frame.face.m[5] = -frame.face.m[5];
      frame.face.m[8] = -frame.face.m[8];
      *((Matrix32 *) (record + 8)) = frame.face;
      if (oldCount < 10)
      {
        W(P(arg1, 0x8c), 0x100) = oldCount + 1;
      }
    }
  }

  return (u8) count;
}
