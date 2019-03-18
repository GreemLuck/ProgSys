/* Bob Wightman */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // for fmod

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int my_getop(char []);
void push(double);
double pop(void);

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while((type = my_getop(s)) != EOF)
    {
        switch(type)
        {
           /* other cases snipped for brevity */
 
            case '%':
                op2 = pop();
                if(op2)
                    push(fmod(pop(), op2));
                else
                    printf("\nError: Division by zero!");
                break;
 
        }
    }
    return EXIT_SUCCESS;
}


/* my_getop: get next operator or numeric operand. */
int my_getop(char s[])
{
    #define PERIOD  '.'
    int i = 0;
    int c;
    int next;

    /* Skip whitespace */
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    /* Not a number but may contain a unary minus. */
    if(!isdigit(c) && c != PERIOD && c != '-')
        return c;               

    if(c == '-')
    {
        next = getch();
        if(!isdigit(next) && next != PERIOD)
        {
           return c;
        }
        c = next;
    }
    else
    {
        c = getch();
    }
 
    while(isdigit(s[++i] = c))
            c = getch();
    if(c == PERIOD)                     /* Collect fraction part. */
        while(isdigit(s[++i] = c = getch()))
                        ;
    s[i] = '\0';
    if(c != EOF)
        unGetch(c);
    return NUMBER;
}