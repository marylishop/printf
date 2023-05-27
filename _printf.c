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
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
	{
		for (j = 0; m[j].id != NULL; j++)
	{
		if (format[i + 1] == m[j].id[1])
	{
		len += m[j].f(args);
		i++;
		break;
	}
	}
		if (m[j].id == NULL)
		{
		write(1, &format[i], 1);
		len++;
		}
	}
	else
	{
		write(1, &format[i], 1);
		len++;
	}
	}
	va_end(args);
	return (len);
}
