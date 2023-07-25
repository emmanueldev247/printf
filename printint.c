#include "main.h"

/**
 * print_int - prints an integer
 * @arguments: input string
 * @buf: buffer pointer (Not used in this implementation)
 * @ibuf: index for buffer pointer (Not used in this implementation)
 * Return: number of chars printed.
 */
int printint(va_list arguments, char *buf, unsigned int ibuf)
{
    int int_input, int_temp, i, div, isneg;
	unsigned int int_in;

    int_input = va_arg(arguments, int);
    isneg = (int_input < 0);
    int_in = (isneg) ? -int_input : int_input;

	if (isneg)
		ibuf = manage_output(buf, '-', ibuf);

    int_temp = int_in;
    div = 1;

    while (int_temp > 9)
    {
        div *= 10;
        int_temp /= 10;
    }

    for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = manage_output(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + isneg);
}
