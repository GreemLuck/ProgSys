#include <stdio.h>
#include <ctype.h>


/* my_atof: convert string s to double --- kr71 */
double my_atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)	/* skip with space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}


/* my_atoi: convert string s to integer using atof --- kr73 */
int my_atoi(char s[])
{
    double my_atof(char s[]);

    return (int) my_atof(s);
}


main()
{
	char s[100];
	scanf("%s", s);	
	printf("%d\n", my_atoi(s) + 1);	
}

