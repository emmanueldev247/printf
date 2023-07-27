#include "main.h"

/**
 * printint - prints an integer
 * @args: input num
 * @num: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int printint(va_list args, char *num, unsigned int findex)
{
	int int_input, isneg;
	unsigned int int_in, int_temp, i, div;

	int_input = va_arg(args, int);
	isneg = (int_input < 0);
	int_in = (isneg) ? -int_input : int_input;

	if (isneg)
		findex = manage_output(num, '-', findex);

	int_temp = int_in;
	div = 1;

	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		findex = manage_output(num, ((int_in / div) % 10) + '0', findex);
	}
	return (i + isneg);
}


/**
 * print_unint - prints an unsigned integer
 * @args: input num
 * @num: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int print_unint(va_list args, char *num, unsigned int findex)
{
	unsigned int int_in, temp, i, div;

	int_in = va_arg(args, unsigned int);
	temp = int_in;
	div = 1;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		findex = manage_output(num, ((int_in / div) % 10) + '0', findex);
	}
	return (i);
}
