#include "main.h"

/**
 * amount_print - gets the number of characters matched for a format specifier
 * @str: format specifier
 * @indx: index of the format specifier in the string
 *
 * Return: return a function pointer
 */
int amount_print(const char *str, int indx)
{
	print_func format_array[] = {
		{"c", printchr},
		{"s", printstr},
		{NULL, NULL},
	};
	int i, j, arr_index;

	j = 0;
	arr_index = indx;

	while (format_array[i].argument_type)
	{
		if (str[indx] == format_array[i].argument_type[j])
		{
			if (format_array[i].argument_type[j + 1] != '\0')
				indx++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			indx = arr_index;
		}
	}
	return (j);
}
