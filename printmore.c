#include "main.h"

/**
 * printprc - writes the character c to stdout
 * @a: input char
 * @str: buffer pointer
 * @findex: index for buffer pointer
 * Return: On success 1.
 */
int printprc(va_list a,  char *str, unsigned int findex)
{
	manage_output(str, '%', findex);
	(void)a;

	return (1);
}
