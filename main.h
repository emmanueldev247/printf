#ifndef _MAIN_H
#define _MAIN_H

#define BUFFER_SIZE 1024

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct function_struct - struct for storing the print functions
 * @argument_type: arument type
 * @function_ptr: function pointer to the function
 *
 * Description: struct that stores pointers to a printer function
 */
typedef struct function_struct
{
	char *argument_type;
	int (*function_ptr)(va_list, char *, unsigned int);
} print_func;


int _printf(const char *format, ...);
int process_format(const char *format, char *foutput, va_list args);
int writebuf(char *string, unsigned int nbyte);
int (*func_output)(va_list, char *, unsigned int);
int (*which_func(const char *str, int indx))(va_list, char *, unsigned int);
int amount_print(const char *str, int indx);
unsigned int manage_output(char *str, char ch, unsigned int findex);
int printchr(va_list args, char *string, unsigned int findex);
int printstr(va_list args, char *string, unsigned int findex);
int printint(va_list arguments, char *buf, unsigned int ibuf);
char *fill_bin_arr(char *binary, long int integer_input, int isneg, int limit);
int printint(va_list arguments, char *buf, unsigned int ibuf);
int printbnr(va_list args, char *value, unsigned int findex);
int printunint(va_list arguments, char *buf, unsigned int ibuf);
int printprc(va_list a,  char *str, unsigned int findex);
int print_unint(va_list args, char *num, unsigned int findex);
int printoct(va_list args, char *buf, unsigned int findex);
char *fill_oct_arr(char *bin, char *oct);
int printhex(va_list args, char *buf, unsigned int findex);
char *fill_hex_arr(char *bin, char *hex, int isupp, int size);
int print_reverse(va_list args, char *buf, unsigned int findex);
int printhex_upper(va_list args, char *buf, unsigned int findex);
int printrot(va_list args, char *string, unsigned int findex);
int printSTR(va_list args, char *string, unsigned int findex);
int printaddr(va_list args, char *string, unsigned int findex);
int printintplus(va_list args, char *string, unsigned int findex);
int printlongint(va_list args, char *string, unsigned int findex);
int printlongoct(va_list args, char *string, unsigned int findex);
int printlunint(va_list args, char *string, unsigned int findex);
char *fill_long_oct_arr(char *bin, char *oct);
int printlhex(va_list args, char *string, unsigned int findex);
int printlhex_upper(va_list args, char *string, unsigned int findex);

#endif
