void swap1(int i, int j)
{
  int temp;
  temp = i;
  i = j;
  j = temp;
}

void swap2(int *i, int *j)
{
  int temp;
  temp = *i;
  *i = *j;
  *j = temp;
}

main()
{
  int i, j;
  i = 1; j = 2;
  swap1(i,j);
  swap2(&i,&j);
}

/*--------------------------------------------------------------------------------
Simple program to use with the GNU debugger gdb
Author: B. Hirsbrunner, University of Fribourg, 10 June 2005
--------------------------------------------------------------------------------*/