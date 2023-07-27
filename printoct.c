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
	int int_input, i, isneg, count, first_digit;
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
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			findex = manage_output(buf, octal[i], findex);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}
