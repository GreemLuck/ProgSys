/*--------------------------------------------------------------------------------
Ben,

I thought your solution to 1-18 was really neat (it didn't occur to me
when I was doing the exercise), the way it degrades gracefully and
multiple passes can get rid of huge blocks of whitespace.

However, if there is a huge block of non-trailing whitespace (eg "A",2000
spaces, "B\n") your program returns an error when there's not a need for
it.  And if someone were to use your program till it passes it will loop
infinitely:

  $ perl -e 'print "A"," "x2000,"B\n";' > in
  $ until ./a.out < in > out; do echo failed, running another pass; cp out
     in; done
  failed, running another pass
  failed, running another pass
  failed, running another pass
  [snip]

Below I have added a variable spaceJustPrinted to your program and check
to see if the spaces printed early are trailing.  I hope you like the
minor improvement.

Chris Sidi
--------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 1001

int advance(int pointer)
{
  if (pointer < MAXQUEUE - 1)
    return pointer + 1;
  else
    return 0;
}

int main(void)
{
  char blank[MAXQUEUE];
  int head, tail;
  int nonspace;
  int retval;
  int c;
  int spaceJustPrinted; /*boolean: was the last character printed whitespace?*/

  retval = spaceJustPrinted = nonspace = head = tail = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      head = tail = 0;
      if (spaceJustPrinted == 1) /*if some trailing whitespace was printed...*/
        retval = EXIT_FAILURE;

      if (nonspace) {
        putchar('\n');
        spaceJustPrinted = 0; /* this instruction isn't really necessary since
                              spaceJustPrinted is only used to determine the
                              return value, but we'll keep this boolean
                              truthful */
        nonspace = 0;  /* moved inside conditional just to save a needless
                       assignment */
      }
    }
    else if (c == ' ' || c == '\t') {
      if (advance(head) == tail) {
        putchar(blank[tail]); /* these whitespace chars being printed early
                              are only a problem if they are trailing,
                              which we'll check when we hit a \n or EOF */
        spaceJustPrinted = 1;
        tail = advance(tail);
        nonspace = 1;
      }

      blank[head] = c;
      head = advance(head);
    }
    else {
      while (head != tail) {
        putchar(blank[tail]);
        tail = advance(tail);
      }
      putchar(c);
      spaceJustPrinted = 0;
      nonspace = 1;
    }
  }

  /* if the last line wasn't ended with a newline before the EOF,
  we'll need to figure out if trailing space was printed here */
  if (spaceJustPrinted == 1) /*if some trailing whitespace was printed...*/ 
    retval = EXIT_FAILURE;

  return retval;
}


