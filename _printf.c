#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: the string to be printed
 *
 * Return: the length of the charcters in the output string
 */
int _printf(const char *format, ...)
{
	unsigned int i, len = 0;
	char *foutput;
	va_list args;

	i = 0;

	va_start(args, format);
	foutput = malloc(sizeof(char) * BUFFER_SIZE);
	if (!foutput || !format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[i] == '\0')
		return (0);

	len = process_format(format, foutput, args);
	return (len);
}

/**
 * process_format - Helper function to process the format string
 * @format: the string to be printed
 * @foutput: the output buffer
 * @args: the argument list
 *
 * Return: the length of the characters in the output string
 */
int process_format(const char *format, char *foutput, va_list args)
{
	unsigned int i, len = 0, findex = 0;
	int (*func_output)(va_list, char *, unsigned int);

	for (i = 0; format[i] && format; i++)
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
	writebuf(foutput, findex);
	free(foutput);
	va_end(args);
	return (len);
}
