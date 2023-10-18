#include "main.h"

/**
 * print_numb - prints a number send to this function
 * @args: List of arguments
 * Return: The number of arguments printed
 */
int print_numb(va_list args)
{
	int number;
	int div;
	int length;
	unsigned int num;

	number  = va_arg(args, int);
	div = 1;
	length = 0;

	if (number < 0)
	{
		length += _type_char('-');
		num = number * -1;
	}
	else
		num = number;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		length += _type_char('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (length);
}
/**
 * print_unsgined_number - Prints an unsigned number
 * @number: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int print_unsgined_number(unsigned int number)
{
	int div;
	int length;
	unsigned int num;

	div = 1;
	length = 0;

	num = number;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		length += _type_char('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (length);
}