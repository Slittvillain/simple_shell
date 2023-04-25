#include "shell.h"

/**
 * _getline - Reads a line of input from stdin
 *
 * Return: A string containing the input read from stdin, or NULL on failure
 */
char *_getline(void)
{
	static char buffer[1024];
	static int pos;
	int c;

	/* Read input one char at a time */
	while ((c = read(STDIN_FILENO, &buffer[pos], 1)) != -1)
	{
		/* If we reached end of line, return the input */
		if (buffer[pos] == '\n')
		{
			buffer[pos] = '\0';
			pos = 0;
			return (buffer);
		}

		pos++;

		/* If buffer is full, return the input */
		if (pos == 1024)
		{
			buffer[pos] = '\0';
			pos = 0;
			return (buffer);
		}
	}

	/* If we got here, there was an error */
	return (NULL);
}
