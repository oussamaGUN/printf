#include "main.h"
/**
 * _hexaup - Converts an integer to a hexadecimal number and prints it.
 * @args: A variable argument list containing the integer to convert.
 * Return: The number of characters printed to stdout.
**/
int _hexaup(va_list args)
{
	unsigned int n = va_arg(args, int);
	char arr[20];
	int i = 0;
	int j;

	while (n != 0)
	{
		int tmp = 0;

		tmp = n % 16;
		if (tmp < 10)
			arr[i++] = tmp + '0';
		else
			arr[i++] = tmp + 55;
		n /= 16;
	}
	j = i - 1;
	while (j >= 0)
		_putchar(arr[j--]);
	return (i);
}