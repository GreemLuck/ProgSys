/* Beat Hirsbrunner and Fulvio Frapolli, University of Fribourg, January 2008 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *f;
  unsigned long pos; /* position to read from */
  
  if (argc != 2) {
    printf("Usage: %s input_file\n", argv[0]);
    return -1;
  }
	    
  f = fopen(argv[1], "r");  
  printf("\n%s\n\n", "loop forever (quit with ctrl-C)");
  while (1) {
    printf("> Insert pos: ");
    scanf("%lu", &pos);
    
    fseek(f, pos, 0);  // new seek position
    
    // printf("%lu ", ftell(f));   // current value of the file position
    printf("%c", fgetc(f));  // value pointed by the current file position
    // printf(" %lu", ftell(f));
    printf("\n");
  }
  fclose(f);
}
