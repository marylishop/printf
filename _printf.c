#include "main.h"
/**
 * _printf - prints a formatted string to stdout
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	convert_match m[] = {
	{"%s", printf_string}, {"%c", printf_char},
	{"%d", printf_dec}, {"%u", printf_unsigned},
	{"%%", printf_37}, {"%x", printf_hex},
	{"%b", printf_bin}, {"%X", printf_HEX},
	{"%i", printf_int}, {"%p", printf_pointer},
	{"%o", printf_oct}, {"%r", printf_srev},
	{"%R", printf_rot13}, {"%S", printf_exclusive_string},
};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
