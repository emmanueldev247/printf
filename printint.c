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


/**
 * printintplus - print integer with plus symbol
 * @args: input string
 * @string: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: number of chars printed
 */
int printintplus(va_list args, char *string, unsigned int findex)
{
	int int_input;
	unsigned int int_in, int_temp, i, div;

	int_input = va_arg(args, int);
	if (int_input < 0)
	{
		int_in = -1 * int_input;
		findex = manage_output(string, '-', findex);
	}
	else
	{
		int_in = int_input;
		findex = manage_output(string, '+', findex);
	}
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		findex = manage_output(string, ((int_in / div) % 10) + '0', findex);
	}
	return (i + 1);
}


/**
 * printlongint - prints a long integer
 * @args: input string
 * @string: buffer pointer
 * @findex: index for buffer pointer
 * Return: number of chars printed.
 */
int printlongint(va_list args, char *string, unsigned int findex)
{
	long int int_input;
	unsigned long int int_in, int_temp, i, div, isneg;

	int_input = va_arg(args, long int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = -1 * int_input;
		isneg = 1;
		findex = manage_output(string, '-', findex);
	}
	else
	{
		int_in = int_input;
	}

	int_temp = int_in;
	div = 1;
	for (; int_temp > 9; div *= 10, int_temp /= 10)
		;

	for (i = 0; div > 0; div /= 10, i++)
	{
		findex = manage_output(string, ((int_in / div) % 10) + '0', findex);
	}
	return (i + isneg);
}


/**
 * printlunint - prints a long unsigned integer
 * @args: number to print
 * @string: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int printlunint(va_list args, char *string, unsigned int findex)
{
	unsigned long int int_in, int_temp, i, div;

	int_in = va_arg(args, unsigned long int);
	int_temp = int_in;
	div = 1;

	for (; int_temp > 9; div *= 10, int_temp /= 10)
		;

	for (i = 0; div > 0; div /= 10, i++)
	{
		findex = manage_output(string, ((int_in / div) % 10) + '0', findex);
	}
	return (i);
}
