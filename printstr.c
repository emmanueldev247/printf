#include "main.h"
/**
 * printstr - writes the str to output
 * @args: string
 * @fout: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: On success 1.
 */
int printstr(va_list args, char *fout, unsigned int findex)
{
	char *s;
	char null[] = "(null)";
	unsigned int x;

	s = va_arg(args, char *);
	if (s == NULL)
	{
		for (x = 0; null[x]; x++)
			findex = manage_output(fout, null[x], findex);
		return (6);
	}
	for (x = 0; s[x]; x++)
		findex = manage_output(fout, s[x], findex);
	return (x);
}
