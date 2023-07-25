#include "main.h"

/************************* PRINTING UNSIGNED NUMBERS IN C*************************/
/**
 * print_unsigned - This is a function that Prints an unsigned number
 * @types: Lists various arguments
 * @buffer: Buffer array that will handle print
 * functions
 * @flags:  Calculates active flags in the function
 * @width: calculates the width in the function
 * @precision: gets the Precision specificationof the 
 * function
 * @size: Size specifieies the size of the input or
 * output
 * Return: Numbers of characters printedin the function.
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINTING AN  UNSIGNED NUMBER IN OCTAL IN C ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * as an output
 * @types: Lists various arguments
 * @buffer: Buffer array that will handle print
 * functions
 * @flags:  Calculates active flags in the function
 * @width: calculates the width in the function
 * @precision: gets the Precision specificationof the
 * function
 * @size: Size specifieies the size of the input or
 * output
 * Return: Numbers of characters printedin the function.
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINTS AN UNSIGNED NUMBER IN HEXADECIMAL IN C **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lists various arguments
 * @buffer: Buffer array that will handle print
 * functions
 * @flags:  Calculates active flags in the function
 * @width: calculates the width in the function
 * @precision: gets the Precision specificationof the
 * function
 * @size: Size specifieies the size of the input or
 * output
 * Return: Numbers of characters printedin the function.
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/************* PRINTS AN UNSIGNED NUMBER IN UPPER HEXADECIMAL IN THE FUNCTION **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lists various arguments
 * @buffer: Buffer array that will handle print
 * functions
 * @flags:  Calculates active flags in the function
 * @width: calculates the width in the function
 * @precision: gets the Precision specificationof the
 * function
 * @size: Size specifieies the size of the input or
 * output
 * Return: Numbers of characters printedin the function.
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/************** PRINTS HEX NUMBERS IN LOWER OR UPPER CASES **************/
/**
 * * print_hexa - Prints a hexadecimal number in lower or upper cases
 * @types: Lists various arguments
 * @map_to: Array of values to map the number to map
 * @buffer: Buffer array that will handle print
 * fuctions
 * @flags:  Calculates active flags in the function
 * @width: calculates the width in the function
 * @precision: gets the Precision specificationof the
 * function
 * @size: Size specifieies the size of the input or
 * output
 * @size: Size specification gives size specification
 * Return: Numbers of characters printedin the function.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
