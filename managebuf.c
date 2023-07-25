#include "main.h"

/**
 * manage_output - concatenates the buffer chars
 * @str: string pointer
 * @ch: character to concatenate
 * @findex: index of string pointer
 *
 * Return: index of string pointer
 */
unsigned int manage_output(char *str, char ch, unsigned int findex)
{
	if (findex == BUFFER_SIZE)
	{
		writebuf(str, findex);
		findex = 0;
	}
	str[findex] = ch;
	findex++;

	return (findex);
}
