#include "main.h"

/**
 * print_float - prints float numbers
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */
int print_float(va_list ap, params_t *params)
{
	double val = va_arg(ap, double);  // get the floating-point argument
	int precision = params->precision; // get the precision from the params_t structure

	// print the floating-point value with the specified precision
	char format[10];
	_printf(format, 10, "%%.%df", precision);
	return (_printf(format, val));
}
