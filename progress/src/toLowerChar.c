/* Returns the lowercase form of an ASCII capital letter; any other character is returned unchanged. */
unsigned char toLowerChar(char c)
{
  if (((unsigned char) (c - 0x41)) < 0x1B)
  {
    return c + 0x20;
  }
  return c;
}
