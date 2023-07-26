#include "main.h"

/**
 * printbnr - prints binary numbers
 * @args: input string
 * @value: pointer where binary representation will be stored
 * @findex: curent position of the value
 *
 * Return: number of chars printed.
 */
int printbnr(va_list args, char *value, unsigned int findex)
{
	int integer_passed, count, i, first_one, isneg;
	char *binary_value;

	integer_passed = va_arg(args, int);
	isneg = 0;
	if (integer_passed == 0)
	{
		findex = manage_output(value, '0', findex);
		return (1);
	}
	if (integer_passed < 0)
	{
		isneg = 1;
		integer_passed = (integer_passed * -1) - 1;
	}
	binary_value = malloc(sizeof(char) * (32 + 1));
	binary_value = fill_bin_arr(binary_value, integer_passed, isneg, 32);
	first_one = 0;
	for (count = i = 0; binary_value[i]; i++)
	{
		if (first_one == 0 && binary_value[i] == '1')
			first_one = 1;
		if (first_one == 1)
		{
			findex = manage_output(value, binary_value[i], findex);
			count++;
		}
	}
	free(binary_value);
	return (count);
}
