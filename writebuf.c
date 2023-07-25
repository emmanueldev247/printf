#include "main.h"
/**
 * writebuf - printes the string
 * @string: pointer to the string
 * @nbyte: number of bytes to be printed
 *
 * Return: number of bytes printed
 * On error, -1 is returned, and errno is set appropriately.
 */
int writebuf(char *string, unsigned int nbyte)
{
	return (write(1, string, nbyte));
}
