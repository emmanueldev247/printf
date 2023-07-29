#include "main.h"
/**
 * which_func - gets the correct function for the operation
 * @str: format specifier
 * @indx: index of the format specifier in the string
 *
 * Return: return a function pointer
 */
int (*which_func(const char *str, int indx))(va_list, char *, unsigned int)
{
	print_func format_array[] = {
		{"c", printchr}, {"s", printstr},
		{"d", printint}, {"i", printint},
		{"+d", printintplus}, {"+i", printintplus},
		{" d", printintplus}, {" i", printintplus},
		{" +d", printintplus}, {" +i", printintplus},
		{"+ d", printintplus}, {"+ i", printintplus},
		{"ld", printlongint}, {"li", printlongint},
		{"hd", printint}, {"hi", printint},
		{"b", printbnr}, {"%", printprc},
		{" %", printprc}, {"u", print_unint},
		{"o", printoct}, {" u", print_unint},
		{" o", printoct}, {" x", printhex},
		{"lo", printlongoct}, {"lu", printlunint},
		{"ho", printlongoct}, {"hu", printlunint},
		{"x", printhex}, {"+x", printhex},
		{"lx", printlhex}, {"lX", printlhex_upper},
		{"hx", printlhex}, {"hX", printlhex_upper},
		{"l", printprc}, {"h", printprc},
		{"X", printhex_upper}, {"+u", print_unint}, {" X", printhex_upper},
		{"R", printrot}, {"r", print_reverse},
		{"S", printSTR}, {"#u", print_unint},
		{"p", printaddr}, {NULL, NULL},
	};

	int i, j, arr_index;

	j = 0, i = 0;
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
	return (format_array[i].function_ptr);
}

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
		{"c", printchr}, {"s", printstr}, {"d", printint},
		{"i", printint}, {"+d", printintplus}, {"+i", printintplus},
		{" d", printintplus}, {" i", printintplus},	{" +d", printintplus},
		{" +i", printintplus}, {"+ d", printintplus}, {"+ i", printintplus},
		{"ld", printlongint}, {"li", printlongint},
		{"hd", printint}, {"hi", printint}, {"b", printbnr}, {"%", printprc},
		{" %", printprc}, {"u", print_unint}, {"o", printoct}, {" u", print_unint},
		{" o", printoct}, {" x", printhex},
		{"lo", printlongoct}, {"lu", printlunint}, {"ho", printlongoct},
		{"hu", printlunint}, {"x", printhex}, {"+x", printhex},
		{"lx", printlhex}, {"lX", printlhex_upper}, {"hx", printlhex},
		{"hX", printlhex_upper}, {"l", printprc}, {"h", printprc},
		{"X", printhex_upper}, {"+u", print_unint}, {" X", printhex_upper},
		{"R", printrot}, {"r", print_reverse}, {"S", printSTR}, {"#u", print_unint},
		{"p", printaddr}, {NULL, NULL},
	};

	int i, j, arr_index;

	i = 0, j = 0;
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
