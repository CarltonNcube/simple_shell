#include "shell.h"

/**
 * _atoi - convert a string to an integer
 * @str: the string to convert
 * Return: the inteher value of string, 0 no valid conversion
 */
int _atoi(const char *str)
{
	int sign = 1, result = 0, digit;

	/* Skip leading whitespace */
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' ||
		*str == '\f' || *str == '\v')
		str++;

	/* Check for sign */
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	/* Convert digits to integer */
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		result = result * 10 + digit;
		str++;
	}

	return (sign * result);
}
