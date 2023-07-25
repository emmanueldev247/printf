#include "main.h"
/**
 * printchr - prints the chr
 * @args: passed va_list macro
 * @string: string pointer
 * @findex: index of string pointer
 *
 * Return: On success 1
 */
int printchr(va_list args, char *string, unsigned int findex)
{
	char chr;

	chr = va_arg(args, int);
	manage_output(string, chr, findex);

	return (1);
}

/**
 * printstr - prints the str
 * @args: passed va_list macro
 * @string: string pointer
 * @findex: index of the string pointer
 *
 * Return: On success 1
 */
int printstr(va_list args, char *string, unsigned int findex)
{
	char *str;
	unsigned int x;
	char null[] = "(null)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (x = 0; null[x]; x++)
			findex = manage_output(string, null[x], findex);
		return (6);
	}
	for (x = 0; str[x]; x++)
		findex = manage_output(string, str[x], findex);
	return (x);
}
