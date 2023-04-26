#include "shell_general.h"
#include "shell_text.h"

/**
 * _putchar - Prints a character to STDOUT
 *
 * @c: Character to print
 *
 * Return: On success, returns 1
 *         On error, returns -1
 **/
int _putchar(char c)
{
	return (write(STDOUT, &c, 1));
}

/**
 * print - Prints a message to STDOUT
 *
 * @msg: Message to print
 *
 * Return: On success, returns the number of bytes printed
 *         On error, returns -1 and sets the error
 **/
int print(char *msg)
{
	return (print_to_fd(msg, STDOUT));
}
