#include <stdarg.h>
#include "main.h"
/**
 * print_handler - determines type of printing to do
 * @format: character to analyse
 * @args: list of arguments
 * Return: int
 */
int print_handler(const char *format, va_list args)
{
int state = 0;
int count = 0;

if (!format)
return (0);
while (*format)
{
if (state == 0)
{
if (*format == '%')
state = 1;
else
count += write_char(*format);
}
else if (state == 1)
{
switch (*format)
{
case 's':
{
const char *s = va_arg(args, const char *);

while (*s)
count += write_char(*s++);
break;
}
case '%':
count += write_char('%');
break;
case 'c':
count += write_char(va_arg(args, int));
break;
default:
break;
}
state = 0;
}
format++;
}
return (count);
}
/**
 * _printf - custoom print function.
 * @format: charater stream.
 * Return: int;
 */
int _printf(const char *format, ...)
{
int printed = 0;
va_list args;

va_start(args, format);
printed += print_handler(format, args);
va_end(args);
return (printed);
}
