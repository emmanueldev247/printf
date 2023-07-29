#include "main.h"

/**
 * printoct - prints octal representations of decimal number
 * @args: input number
 * @buf: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int printoct(va_list args, char *buf, unsigned int findex)
{
	int int_input, i, isneg, count, f_dig;
	char *octal, *binary;

	int_input = va_arg(args, int);
	isneg = 0;
	if (int_input == 0)
	{
		findex = manage_output(buf, '0', findex);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isneg = 1;
	}
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_bin_arr(binary, int_input, isneg, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = fill_oct_arr(binary, octal);
	for (f_dig = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && f_dig == 0)
			f_dig = 1;
		if (f_dig)
		{
			findex = manage_output(buf, octal[i], findex);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}


/**
 * printlongoct - prints long decimal number in octal notation
 * @args: input number
 * @string: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int printlongoct(va_list args, char *string, unsigned int findex)
{
	long int int_input, i, isneg, count, f_dig;
	char *oct, *bin;

	int_input = va_arg(args, long int);
	isneg = 0;
	if (int_input == 0)
	{
		findex = manage_output(string, '0', findex);
		return (1);
	}
	if (int_input < 0)
	{
		isneg = 1;
		int_input = (-1 * int_input) - 1;
	}

	bin = malloc(sizeof(char) * 65);
	bin = fill_bin_arr(bin, int_input, isneg, 64);
	oct = malloc(sizeof(char) * 23);
	oct = fill_long_oct_arr(bin, oct);
	for (f_dig = i = count = 0; oct[i]; i++)
	{
		if (oct[i] != '0' && f_dig == 0)
			f_dig = 1;
		if (f_dig)
		{
			findex = manage_output(string, oct[i], findex);
			count++;
		}
	}
	free(bin);
	free(oct);
	return (count);
}
