/* lower: convert c to lower case; ASCII only  ---  kr43 */
int lower(int c)
{
	if (c >= 'A' && c <='Z')
		return c + 'a' - 'A';
	else
		return c;
}
