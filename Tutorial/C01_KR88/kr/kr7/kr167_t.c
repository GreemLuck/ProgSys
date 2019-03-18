// Beat Hirsbrunner, University of Fribourg, January 2008

#include <stdio.h>
#include <string.h>
#define MAX 100  // big enough in order to accept the full command line

main() {
  char cmd[MAX];
  char *prompt = "> ";

  printf("%s", prompt);
  while (fgets(cmd,MAX,stdin) != NULL) { // fgets reads the next input line, including the newline
    cmd[strlen(cmd)-1] = '\0';  // remove '\n'
    system(cmd);
	printf("%s", prompt);
  }
  printf("\n");
}
