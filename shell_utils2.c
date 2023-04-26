#include "shell_general.h"
#include "shell_text.h"

/**
 * digits - Count the number of digits of a number
 *
 * @n: Number
 *
 * Return: Digits
 **/
int digits(int n)
{
	int i;

	for (i = 0; n != 0; i++, n /= 10)
	{
		;
	}

	return (i);
}

/**
 * to_string - Convert @number to string
 *
 * @number: Number to convert
 *
 * Return: Number as string
 **/
char *to_string(int number)
{
	int n_digits, i;
	char *_number;

	n_digits = digits(number);
	_number = malloc(n_digits * sizeof(char) + 1);
	if (_number == NULL)
	{
		return (NULL);
	}

	if (number == 0)
	{
		_number[0] = '0';
		_number[1] = '\0';
		return (_number);
	}

	_number[n_digits] = '\0';
	for (i = n_digits - 1; number != 0; number /= 10, i--)
	{
		_number[i] = (number % 10) + '0';
	}

	return (_number);
}

/**
 * is_numerical - Check if is a digit
 *
 * @n: Number
 *
 * Return: If is a number, return 1 else return 0
 **/
int is_numerical(unsigned int n)
{
	return (n >= '0' && n <= '9');
}

/**
 * _atoi - Convert a string to a number
 *
 * @s: String to convert
 *
 * Return: Return the number
 **/
int _atoi(char *s)
{
	unsigned int number, i;
	int sign;

	sign = 1;
	number = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]))
		{
			number = (s[i] - '0') + number * 10;

			if (s[i + 1] == ' ')
			{
				break;
			}
		}
		else if (s[i] == '-')
		{
			sign *= -1;
		}
	}

	return (number * sign);
}

/**
 * contains_letter - Search non-digits in a string
 *
 * @s: String for search
 *
 * Return: If a non-digit was found, return _TRUE,
 * otherwise, return _FALSE
 **/
int contains_letter(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]) == _FALSE)
		{
			return (_TRUE);
		}
	}

	return (_FALSE);
}
