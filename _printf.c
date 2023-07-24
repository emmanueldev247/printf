#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: the character string
 *
 * Return: the length of the charcters in the output string
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, findex = 0;
	char *foutput;
	int (*func_output)(va_list, char *, unsigned int);
	va_list args;

	va_start(args, format), foutput = malloc(sizeof(char) * BUFFER_SIZE);
	if (!foutput || !format || (format[0] == '%' && !format[1]))
		return (-1);
	if (!format[0])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				writebuf(foutput, findex), free(foutput), va_end(args);
				return (-1);
			}
			else
			{
				func_output = which_func(format, i + 1);
				if (func_output == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					manage_output(foutput, format[i], findex), len++, i--;
				}
				else
				{
					len += func_output(args, foutput, findex);
					i += amount_print(format, i + 1);
				}
			} i++;
		}
		else
			manage_output(foutput, format[i], findex), len++;
		for (findex = len; findex > BUFFER_SIZE; findex -= BUFFER_SIZE)
			;
	}
	writebuf(foutput, findex), free(foutput), va_end(args);
	return (len);
}
