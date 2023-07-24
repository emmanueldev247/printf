#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct print_func - struct for getting the print functions
 * @argument_type: arument type
 * @function_ptr: function pointer to the function
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *argument_type;
	int (*function_ptr)(va_list, char *, unsigned int);
} print_func;


int _printf(const char *format, ...);
int (*func_output)(va_list, char *, unsigned int);
int (*which_func(const char *str, int indx))(va_list, char *, unsigned int);
int amount_print(const char *str, int indx);
unsigned int manage_output(char *str, char ch, unsigned int findex);
int writebuf(char *c, unsigned int nbyte);
int printchr(va_list args, char *string, unsigned int findex);
int printstr(va_list args, char *fout, unsigned int findex);


#endif
