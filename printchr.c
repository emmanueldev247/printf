#include "main.h"
/**
 * printchr - prints the ch to stdout
 * @arguments: input character
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: On success 1.
 */
int printchr(va_list args, char *string, unsigned int findex)
{
	char ch;

	ch = va_arg(args, int);
	manage_output(string, ch, findex);

	return (1);
}
