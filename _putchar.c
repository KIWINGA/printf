#include <unistd.h>
/**
 *_putchar - writes to standard output
 *@c: Character to print
 *Return: print -1 in error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
