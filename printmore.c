#include "main.h"

/**
 * printprc - writes the character c to stdout
 * @a: input char
 * @str: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: On success 1.
 */
int printprc(va_list a,  char *str, unsigned int findex)
{
	manage_output(str, '%', findex);
	(void)a;

	return (1);
}


/**
 * print_reverse - prints string in reverse order
 * @args: input string
 * @string: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: number of characters printed
 */
int print_reverse(va_list args, char *string, unsigned int findex)
{
	char *str;
	unsigned int i;
	int j;
	char null[] = "(llun)";

	j = 0;
	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; null[i]; i++)
			findex = manage_output(string, null[i], findex);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;

	j = i - 1;
	for (j = j; j >= 0; j--)
	{
		findex = manage_output(string, str[j], findex);
	}
	return (i);
}


/**
 * printrot - prints the ROT13'ed string
 * @args: input string
 * @string: buffer pointer
 * @findex: index for buffer pointer
 *
 * Return: number of chars printed.
 */

int printrot(va_list args, char *string, unsigned int findex)
{
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char null[] = "(avyy)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; null[i]; i++)
			findex = manage_output(string, null[i], findex);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alpha[j]; j++)
		{
			if (str[i] == alpha[j])
			{
				k = 1;
				findex = manage_output(string, rot[j], findex);
				break;
			}
		}
		if (k == 0)
			findex = manage_output(string, str[i], findex);
	}
	return (i);
}



/**
 * printaddr - prints the address of a variable
 * @args: input address.
 * @string: buffer pointer.
 * @findex: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int printaddr(va_list args, char *string, unsigned int findex)
{
	void *addr;
	long int int_input;
	int i, count, f_dig, isneg;
	char *hex, *bin;
	char nill[] = "(nil)";

	addr = (va_arg(args, void *));
	if (addr == NULL)
	{
		for (i = 0; nill[i]; i++)
			findex = manage_output(string, nill[i], findex);
		return (5);
	}
	int_input = (intptr_t)addr;
	isneg = 0;
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isneg = 1;
	}
	bin = malloc(sizeof(char) * 65);
	bin = fill_bin_arr(bin, int_input, isneg, 64);
	hex = malloc(sizeof(char) * 17);
	hex = fill_hex_arr(bin, hex, 0, 16);
	findex = manage_output(string, '0', findex);
	findex = manage_output(string, 'x', findex);
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
	return (count + 2);
}
