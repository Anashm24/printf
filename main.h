#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct convert - defines a structure for symbols and functions
*
* @sym: The operator
* @f: The function associated
*/
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

/*Main functions*/
int parser(const char *format, conver_t f_list[], va_list arg_list);
int _printf(const char *format, ...);
int _type_char(char);
int print_character(va_list);
int print_str(va_list);
int print_perc(va_list);
int print_int(va_list);
int print_numb(va_list);
int print_bi(va_list);
int print_rev(va_list arg);
int rotation(va_list);
int unsigned_int(va_list);
int print_oct(va_list list);
int print_x(va_list list);
int print_X(va_list list);

/*Helper functions*/
unsigned int base_length(unsigned int, int);
char *reverve_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsgined_number(unsigned int);


#endif
