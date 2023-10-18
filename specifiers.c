#include "main.h"
/**
 * print_character - Prints character
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_character(va_list list)
{
	_type_char(va_arg(list, int));
	return (1);
}

/**
 * print_str - Prints a string
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_str(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_type_char(str[i]);
	return (i);
}

/**
 * print_perc - Prints a percent symbol
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_perc(__attribute__((unused))va_list list)
{
	_type_char('%');
	return (1);
}

/**
 * print_int - Prints an integer
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_int(va_list list)
{
	int num_length;

	num_length = print_numb(list);
	return (num_length);
}

/**
 * unsigned_int - Prints Unsigned integers
 * @list: List of all of the argumets
 * Return: a count of the numbers
 */
int unsigned_int(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (print_unsgined_number(num));

	if (num < 1)
		return (-1);
	return (print_unsgined_number(num));
}
