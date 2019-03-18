/* strlen: return length of string s --- kr103 */
int strlen(char *s)
{
	char *p = s;
	
	while (*p != '\0')
		p++;
	return p - s;
}
