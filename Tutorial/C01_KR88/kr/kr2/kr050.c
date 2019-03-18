/* bitcount: counts 1 bits in x  ---  kr50 */
int bitcount(unsigned x)
{
  int b;

  for (b = 0; x != 0 ; x >>= 1)
    if (x & 01)
	b++;
  return b;
}
