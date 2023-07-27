#include "main.h"

/**
 * fill_bin_arr - prints decimal in binary
 * @binary: pointer to binary
 * @integer_input: input number
 * @isneg: if input number is negative
 * @limit: size of the binary
 *
 * Return: number of chars printed.
 */
char *fill_bin_arr(char *binary, long int integer_input, int isneg, int limit)
{
	int i;

	for (i = 0; i < limit; i++)
		binary[i] = '0';
	binary[limit] = '\0';

	for (i = limit - 1; integer_input > 1; i--)
	{
		binary[i] = (integer_input == 2) ? '0' : ((integer_input % 2) + '0');
		integer_input /= 2;
	}
	if (integer_input != 0)
		binary[i] = '1';
	if (isneg)
	{
		for (i = 0; binary[i]; i++)
			if (binary[i] == '0')
				binary[i] = '1';
			else
				binary[i] = '0';
	}
	return (binary);
}
