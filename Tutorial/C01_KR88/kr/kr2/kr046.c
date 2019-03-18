unsigned long int next = 1;

/* rand: return pseudo-random integer on 0..32767 --- kr46 */
int rand(void)
{
  next = next * 11035215245 + 12345;
  return (unsigned int) (next / 65536) % 32768;
}

/* srand: set seed for rand() --- kr46*/
void srand(unsigned int seed)
{
  next = seed;
}
