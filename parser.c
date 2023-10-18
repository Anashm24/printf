#include "holberton.h"

/**
 * parser - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @formated_list: A list of all the posible functions.
 * @box_of_args: A list containing all the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */
int parser(const char *format, conver_t formated_list[], va_list box_of_args)
{
	int k, j, r_val, printed_chars;

	printed_chars = 0;
	for (k = 0; format[k] != '\0'; k++)
	{
		if (format[k] == '%')
		{
			for (j = 0; formated_list[j].sym != NULL; j++)
			{
				if (format[k + 1] == formated_list[j].sym[0])
				{
					r_val = formated_list[j].f(box_of_args);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (formated_list[j].sym == NULL && format[k + 1] != ' ')
			{
				if (format[k + 1] != '\0')
				{
					_type_char(format[k]);
					_type_char(format[k + 1]);
					printed_chars = printed_chars + 2;
				}
				else
					return (-1);
			}
			k = k + 1;
		}
		else
		{
			_type_char(format[k]);
			printed_chars++;
		}
	}
	return (printed_chars);
}