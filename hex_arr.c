#include "main.h"

/**
 * fill_hex_arr - helper function to print hex
 * @bin: array where to store the binary.
 * @hex: array where to store the hexadecimal.
 * @isupp: integer that determines if the hexadecimal array is
 * in uppercase or lowercase letter.
 * @size: size of hex
 *
 * Return: binary array.
 */
char *fill_hex_arr(char *bin, char *hex, int isupp, int size)
{
	int op, i, j, toletter;

	hex[size] = '\0';
	if (isupp)
		toletter = 55;
	else
		toletter = 87;
	for (i = (size * 4) - 1; i >= 0; i--)
	{
		for (op = 0, j = 1; j <= 8; j *= 2, i--)
			op = ((bin[i] - '0') * j) + op;
		i++;
		if (op < 10)
			hex[i / 4] = op + 48;
		else
			hex[i / 4] = op + toletter;
	}
	return (hex);
}
