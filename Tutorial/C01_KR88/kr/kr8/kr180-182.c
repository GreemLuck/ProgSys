/* ----------------------------------------------------------------------------
Listing Directories - KR chap. 8.6

Compiled by Kathrin Meyer, University of Fribourg, July 2006
---------------------------------------------------------------------------- */


/* --- kr181 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>      /* flags for read and write */
#include <sys/types.h>  /* typedefs */
#include <sys/stat.h>   /* structure returned by stat */
#include "my_dirent.h"     /* --- kr180 */

void fsize(char *);


/* -------------*/
/* Main Program */
/* -------------*/
main(int argc, char **argv)  /* print file sizes  ---  kr181 */
{
  if (argc == 1)  /* default: current directory */
    fsize(".");
  else
    while (--argc > 0)
      fsize(*++argv);
  return 0;
}


// int stat(char *, struct stat *);
void dirwalk(char *, void (*fcn)(char *));

/* fsize:  print the name of file "name"  ---  kr182 */
void fsize(char *name)
{
  struct stat stbuf;

  if (stat(name, &stbuf) == -1) {
    fprintf(stderr, "fsize: can't access %s\n", name);
    return;
  }
  if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
    dirwalk(name, fsize);
  printf("%8ld %s\n", stbuf.st_size, name);
}

#define MAX_PATH 1024

/* dirwalk:  apply fcn to all files in dir"  ---  kr182 */
void dirwalk(char *dir, void (*fcn)(char *))
{
  char name[MAX_PATH];
  Dirent *dp;
  DIR *dfd;

  if ((dfd = opendir(dir)) == NULL) {
    fprintf(stderr, "dirwalk: can't open %s\n", dir);
    return;
  }
  while ((dp = readdir(dfd)) != NULL) {
    if (strcmp(dp->name, ".") == 0  ||  strcmp(dp->name, ".."))
      continue;    /* skip self and parent */
    if (strlen(dir)+strlen(dp->name)+2 > sizeof(name))
      fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->name);
    else {
      sprintf(name, "%s/%s", dir, dp->name);
      (*fcn)(name);
    }
  }
  closedir(dfd);
}
