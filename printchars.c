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


/**
 * printSTR - prints a string & values of non-printed chars
 * @args: input string
 * @string: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: number of chars printed
 */
int printSTR(va_list args, char *string, unsigned int findex)
{
	char *hex, *bin;
	unsigned char *str;
	unsigned int i, sum, op;

	str = va_arg(args, unsigned char *);
	bin = malloc(sizeof(char) * 33);
	hex = malloc(sizeof(char) * 9);
	if (bin == NULL || hex == NULL)
		return (0);
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			findex = manage_output(string, '\\', findex);
			findex = manage_output(string, 'x', findex);
			op = str[i];
			bin = fill_bin_arr(bin, op, 0, 32);
			hex = fill_hex_arr(bin, hex, 1, 8);
			findex = manage_output(string, hex[6], findex);
			findex = manage_output(string, hex[7], findex);
			sum += 3;
		}
		else
			findex = manage_output(string, str[i], findex);
	}
	free(bin);
	free(hex);
	return (i + sum);
}
