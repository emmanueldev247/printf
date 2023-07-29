#include "main.h"
/**
 * printhex - prints a number in hexadecimal
 * @args: input string
 * @buf: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: number of chars printed
 */
int printhex(va_list args, char *buf, unsigned int findex)
{
	char *hex, *binary;
	int int_input, i, isneg, count, f_dig;

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
	binary = malloc(sizeof(char) * 33);
	binary = fill_bin_arr(binary, int_input, isneg, 32);
	hex = malloc(sizeof(char) * 9);
	hex = fill_hex_arr(binary, hex, 0, 8);
	for (f_dig = i = count = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && f_dig == 0)
			f_dig = 1;
		if (f_dig)
		{
			findex = manage_output(buf, hex[i], findex);
			count++;
		}
	}
	free(binary);
	free(hex);
	return (count);
}



/**
 * printhex_upper - prints a number in upper hexadecimal
 * @args: The character to print
 * @buf: buffer pointer
 * @findex: index for buffer pointer
 * Return: number of chars printed
 */
int printhex_upper(va_list args, char *buf, unsigned int findex)
{
	char *hex, *binary;
	int int_input, i, isneg, count, f_dig;

	int_input = va_arg(args, int);
	isneg = 0;
	if (int_input == 0)
	{
		findex = manage_output(buf, '0', findex);
		return (1);
	}
	if (int_input < 0)
	{
		isneg = 1;
		int_input = (int_input * -1) - 1;
	}
	binary = malloc(sizeof(char) * 33);
	binary = fill_bin_arr(binary, int_input, isneg, 32);
	hex = malloc(sizeof(char) * 9);
	hex = fill_hex_arr(binary, hex, 1, 8);
	for (f_dig = i = count = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && f_dig == 0)
			f_dig = 1;
		if (f_dig)
		{
			findex = manage_output(buf, hex[i], findex);
			count++;
		}
	}
	free(binary);
	free(hex);
	return (count);
}


/**
 * printlhex - prints the hexadecimal value of a long decimal
 * @args: input string
 * @string: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: number of chars printed
 */
int printlhex(va_list args, char *string, unsigned int findex)
{
	long int int_input, i, isneg, count, f_dig;
	char *hex, *bin;

	int_input = va_arg(args, long int);
	isneg = 0;
	if (int_input == 0)
	{
		findex = manage_output(string, '0', findex);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (-1 * int_input) - 1;
		isneg = 1;
	}

	bin = malloc(sizeof(char) * 65);
	bin = fill_bin_arr(bin, int_input, isneg, 64);
	hex = malloc(sizeof(char) * 17);
	hex = fill_hex_arr(bin, hex, 0, 16);
	for (f_dig = i = count = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && f_dig == 0)
			f_dig = 1;
		if (f_dig)
		{
			findex = manage_output(string, hex[i], findex);
			count++;
		}
	}
	free(bin);
	free(hex);
	return (count);
}

/**
 * printlhex_upper - prints a long decimal in upper hexadecimal
 * @args: The character to print
 * @string: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: number of chars printed
 */
int printlhex_upper(va_list args, char *string, unsigned int findex)
{
	long int int_input, i, isneg, count, f_dig;
	char *hex, *bin;

	int_input = va_arg(args, long int);
	isneg = 0;
	if (int_input == 0)
	{
		findex = manage_output(string, '0', findex);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (-1 * int_input) - 1;
		isneg = 1;
	}

	bin = malloc(sizeof(char) * 65);
	bin = fill_bin_arr(bin, int_input, isneg, 64);
	hex = malloc(sizeof(char) * 17);
	hex = fill_hex_arr(bin, hex, 1, 16);
	for (f_dig = i = count = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && f_dig == 0)
			f_dig = 1;
		if (f_dig)
		{
			findex = manage_output(string, hex[i], findex);
			count++;
		}
	}
	free(bin);
	free(hex);
	return (count);
}
