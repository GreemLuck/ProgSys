/* ex 5-3, p107 */
/* Richard Heathfield */

#include <stdio.h>

void my_strcpy(char *s, char *t)
{
  while(*s++ = *t++);
}

void my_strcat(char *s, char *t)
{
  while(*s)
  {
    ++s;
  }
  my_strcpy(s, t);
}

int main(void)
{
  char testbuff[128];

  char *test[] =
  {
    "",
    "1",
    "12",
    "123",
    "1234"
  };

  size_t numtests = sizeof test / sizeof test[0];
  size_t thistest;
  size_t inner;

  for(thistest = 0; thistest < numtests; thistest++)
  {
    for(inner = 0; inner < numtests; inner++)
    {
      my_strcpy(testbuff, test[thistest]);
      my_strcat(testbuff, test[inner]);

      printf("[%s] + [%s] = [%s]\n", test[thistest], test[inner], testbuff);
    }
  }

  return 0;
}

