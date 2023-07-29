#include "main.h"

/**
 * fill_oct_arr - prints decimal in octal
 * @bin: pointer to binary storage
 * @oct: pointer to octal storage
 *
 * Return: the octal storage
 */
char *fill_oct_arr(char *bin, char *oct)
{
	int op, i, j, ioct, limit;

	oct[11] = '\0';
	for (i = 31, ioct = 10; i >= 0; i--, ioct--)
	{
		limit = (i > 1) ? 4 : 2;
		op = 0;

		for (j = 1; j <= limit; j *= 2, i--)
			op = ((bin[i] - '0') * j) + op;
		i++;
		oct[ioct] = op + '0';
	}
	return (oct);
}


/**
 * fill_long_oct_arr - finds a long octal number
 * @bin: array where we stored the binary.
 * @oct: array where we stored the octal.
 *
 * Return: binary array.
 */
char *fill_long_oct_arr(char *bin, char *oct)
{
	int op, i, j, ioct, limit;

	oct[22] = '\0';
	for (i = 63, ioct = 21; i >= 0; i--, ioct--)
	{
		limit = (i > 0) ? 4 : 1;
		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((bin[i] - '0') * j) + op;
		i++;
		oct[ioct] = op + '0';
	}
	return (oct);
}

