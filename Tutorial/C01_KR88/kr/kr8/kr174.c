/* ----------------------------------------------------------------------------
link, unlink Illustration: A simplified version of Unix' mv

Remember: Unix' mv only moves the i-node, not the data (at least when the move
operates within the same file system). 

Beware, that the present version operates correctly only if the original file
and the newfile reside on the same file system

Beat Hirsbrunner, University of Fribourg, January 2008
---------------------------------------------------------------------------- */

#include <stdlib.h>

main(int argc, char *argv[]) /* move argv[1] to agrv[2] */
{
  if (argc != 3) return -1;

  link(argv[1], argv[2]); // hard link
  unlink(argv[1]);        // remove the link of the original file 
  return 0;
}
