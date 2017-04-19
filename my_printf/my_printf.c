#include <stdio.h>
#include<stdarg.h>
void my_printf(const char *format, ...)
{
	va_list arg;
	va_start(arg, format);
	while (*format)
	{
		switch (*format)
		{
		case'c':
		{
			char tmp = va_arg(arg, char);
			putchar(tmp);
		}break;
		case's':
		{
			char * str = va_arg(arg, char *);
			puts(str);
		}break;
		default:
			putchar(*format);
			break;
		}
		format++;
	}
	va_end(arg);
}
int main()
{
	my_printf("sccc","hello  ", 'a', 'b', 'c');
	system("pause");
	return 0;
}