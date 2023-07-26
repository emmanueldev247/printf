#include "main.h"

/**
 * printint - prints an integer
 * @args: input string
 * @buf: buffer pointer(Not used in this implementation)
 * @findex: index for buffer pointer (Not used in this implementation)
 *
 * Return: number of characters printed.
 */
int printint(va_list args, char *buf, unsigned int findex)
{
	int int_input, int_temp, i, div, isneg;
	unsigned int int_in;

	int_input = va_arg(args, int);
	isneg = (int_input < 0);
	int_in = (isneg) ? -int_input : int_input;

	if (isneg)
		findex = manage_output(buf, '-', findex);

	int_temp = int_in;
	div = 1;

	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		findex = manage_output(buf, ((int_in / div) % 10) + '0', findex);
	}
	return (i + isneg);
}
