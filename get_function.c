#include "main.h"

typedef struct
{
	int count;
	int i;
} LoopReturn;

LoopReturn nextFuncton(const char *current, Choice choice, int i, va_list list);

LoopReturn lp;
int get_function(const char *format, va_list list, Choice choice[], int size)
{
	int i = 0, j = 0, count = 0, num = 0;

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			for (j = 0; j < size; j++)
			{
				if (choice[j].specifier)
				{
					if (format[i + 1] == choice[j].specifier[0] && !choice[j].specifier[1])
					{
						num = choice[j].f(list);
						count += num;
						i += 1;
						break;
					}
				}
				if (choice[j].specifier && choice[j].specifier[1])
				{
					lp = nextFuncton(format, choice[j], i, list);
				}
			}
		}
	}
	if (format == NULL)
		return (-1);
	return (count);
}

LoopReturn lt;
LoopReturn nextFuncton(const char *current, Choice check, int i, va_list list)
{
	if (current[i + 2] == check.specifier[1] && check.specifier[0] == '+')
	{
		lt.count = check.f(list);
	}
		lt.i = i+ 2;
	return (lt);
}
