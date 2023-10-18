#include "main.h"

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	conver_t f_list[] = {
		{"c", print_character},
		{"s", print_str},
		{"%", print_perc},
		{"d", print_int},
		{"i", print_int},
		{"b", print_bi},
		{"r", print_rev},
		{"R", rotation},
		{"u", unsigned_int},
		{"o", print_oct},
		{"x", print_x},
		{"X", print_X},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	/*Calling parser function*/
	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}
