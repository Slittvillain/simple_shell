#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *read_line(int fd);
void print_error(char *msg);

/**
 * main - entry point for the simple shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line;

	do {
		_puts("$ ");
		line = read_line(STDIN_FILENO);
		if (line == NULL)
			break;
		_puts(line);
		free(line);
	} while (1);

	return (0);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * _strlen - returns the length of a string
 * @s: pointer to the string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}

/**
 * read_line - reads an entire line from stream
 * @fd: file descriptor to read from
 *
 * Return: pointer to the buffer containing the string, or NULL on failure
 */
char *read_line(int fd)
{
	static char buf[BUFFER_SIZE];
	static char *buf_pos;
	static int buf_len;
	char *line;
	int i, j, read_len;

	line = malloc(BUFFER_SIZE);
	if (line == NULL)
		return (NULL);

	if (buf_len > 0 && buf_pos < buf + buf_len)
	{
		for (i = 0; buf_pos[i] != '\n' && i < buf_len; i++)
			line[i] = buf_pos[i];
		if (buf_pos[i] == '\n')
		{
			line[i] = '\0';
			buf_pos += i + 1;
			return (line);
		}
	}

	while ((read_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf_pos = buf;
		buf_len = read_len;
		for (i = 0, j = 0; buf_pos[i] != '\n' && i < buf_len; i++, j++)
			line[j] = buf_pos[i];
		if (buf_pos[i] == '\n')
		{
			line[j] = '\0';
			buf_pos += i + 1;
			return (line);
		}
	}

	if (read_len == 0 && _strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}

	print_error("read");
	return (line);
}

/**
 * print_error - prints an error message to stdout
 * @msg: error message to print
 */
void print_error(char *msg)
{
	_puts(msg);
	_putchar('\n');
}
