#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @s: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 * Return: new pointer
*/

char *get_precision(char *s, params_t *params, va_list ap)
{
	int d = 0;

	/* Check for NULL params */
	if (params == NULL)
	{
		/* Handle error: params is NULL */
		return (NULL);
	}

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		d = va_arg(ap, int);
		if (d < 0)
		{
			/* Precision value cannot be negative */
			d = 0;
		}
		s++;
	}
	else
	{
		while (_isdigit(*s))
		{
			/* Calculate precision value from format string */
			d = d * 10 + (*s++ - '0');
		}
	}
	/* Ensure precision value does not exceed maximum value of int */
	if (d > INT_MAX)
	{
		params->error = true;
		d = INT_MAX;
	}
	params->precision = d;
	return (s);
}
