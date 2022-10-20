#include "main.h"
/**
 * print_c - function prints character c
 * @c: character to be printed
 * Return: 1
 */
int print_c(va_list c)
{
	char character = (char)va_arg(c, int);

	_putchar(character);
	return (1);
}
