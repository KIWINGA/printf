#include "main.h"
#include <stdarg.h>

/**
 * check_format - checls format specifier
 * @formatL format specifier
 * Return: pointer to a function
 */
int (*check_format(const char *format))(va_list)
{
	int i = 0;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"b", print_b},
		{"u", print_u},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"p", print_p},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};

	for (; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
			break;
	}
	return (p[i].f);
}
/**
 *_printf - function that format prints
 *@format: list of arguments
 *Return: number of characters
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, counter = 0;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			counter++;
			i++;
			continue;
		}
		else
		{

			if (format[i + 1] == '%');
			{
				_putchar('%');
				counter++;
				i += 2;
				continue;
			}
			else
			{
				f = check_format(&format[i + 1]);
				if (f == NULL)
					return (-1);
				i += 2;
				counter += f(ap);
				continue;
			}
		}
		i++;
	}
	va_end(ap);
	return (counter);
}
