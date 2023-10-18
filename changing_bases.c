#include "main.h"
#include <stdio.h>
int check_hexadecimal(int, char);

/**
 * print_bin - Converts a number from base 10 to binary
 * @list: List of arguments passed to this function
 * Return: The length of the number printed
 */
int print_bi(va_list list)
{
	unsigned int number;
	int k, length;
	char *str;
	char *rev_str;

	number = va_arg(list, unsigned int);
	if (number == 0)
		return (_type_char('0'));
	if (number < 1)
		return (-1);
	length = base_length(number, 2);
	str = malloc(sizeof(char) * length + 1);
	if (str == NULL)
		return (-1);

	for (k = 0; number > 0; k++)
	{
		if (number % 2 == 0)
			str[k] = '0';
		else
			str[k] = '1';
		number = number / 2;
	}
	str[k] = '\0';
	rev_str = reverse_string(str);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (length);
}

/**
 * print_oct - Prints the numeric representation of a number in octal base
 * @list: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */
int print_oct(va_list list)
{
	unsigned int number;
	int length;
	char *octal_rep;
	char *rev_str;

	number = va_arg(list, unsigned int);

	if (number == 0)
		return (_type_char('0'));
	if (number < 1)
		return (-1);
	length = base_length(number, 8);

	octal_rep = malloc(sizeof(char) * length + 1);
	if (octal_rep == NULL)
		return (-1);
	for (length = 0; number > 0; length++)
	{
		octal_rep[length] = (number % 8) + 48;
		number = number / 8;

	}
	octal_rep[length] = '\0';
	rev_str = reverse_string(octal_rep);
	if (rev_str == NULL)
		return (-1);

	write_base(rev_str);
	free(octal_rep);
	free(rev_str);
	return (length);
}

/**
 * print_x - Prints a representation of a decimal number on base16 lowercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_x(va_list list)
{
	unsigned int number;
	int length;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	number = va_arg(list, unsigned int);

	if (number == 0)
		return (_type_char('0'));
	if (number < 1)
		return (-1);
	length = base_length(number, 16);
	hex_rep = malloc(sizeof(char) * length + 1);
	if (hex_rep == NULL)
		return (-1);
	for (length = 0; number > 0; length++)
	{
		rem_num = number % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'x');
			hex_rep[length] = rem_num;
		}
		else
			hex_rep[length] = rem_num + 48;
		number = number / 16;
	}
	hex_rep[length] = '\0';
	rev_hex = reverse_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (length);
}


/**
 * print_X - Prints a representation of a decimal number on base16 Uppercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_X(va_list list)
{
	unsigned int number;
	int length;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	number = va_arg(list, unsigned int);

	if (number == 0)
		return (_type_char('0'));
	if (number < 1)
		return (-1);
	length = base_length(number, 16);
	hex_rep = malloc(sizeof(char) * length + 1);
	if (hex_rep == NULL)
		return (-1);
	for (length = 0; number > 0; length++)
	{
		rem_num = number % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'X');
			hex_rep[length] = rem_num;
		}
		else
			hex_rep[length] = rem_num + 48;
		number = number / 16;
	}
	hex_rep[length] = '\0';
	rev_hex = reverse_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (length);
}

/**
 * check_hexadecimal - Checks which hex function is calling it
 * @number: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int check_hexadecimal(int number, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	number = number - 10;
	if (x == 'x')
		return (hex[number]);
	else
		return (Hex[number]);
	return (0);
}