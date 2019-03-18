/* my_strcpy: copy t to s: array subscript version --- kr105 */
void my_strcpy(char *s, char *t)
{
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')
	    i++;
}

/* my_strcpy1: copy t to s: pointer version --- kr105 */
void my_strcpy1(char *s, char *t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

/* my_strcpy2: copy t to s: pointer version 2 --- kr105 */
void my_strcpy2(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		;
}

/* my_strcpy3: copy t to s: pointer version 3 -- kr106 */
void my_strcpy3(char *s, char *t)
{
	while (*s++ = *t++)
		;
}
