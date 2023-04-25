#include "shell.h"

/**
* exit_builtin - Exits the shell
* @args: Array of arguments
*
* Return: Always returns 0, to indicate termination of the shell
*/
int exit_builtin(char **args)
{
(void)args;
exit(EXIT_SUCCESS);
}

/**
* main - Simple shell 0.3
*
* Return: Always 0.
*/
int main(void)
{
char *line;
char **args;
int status;

do {
printf("$ ");
line = read_line();
args = split_line(line);
status = execute(args);
free(line);
free(args);
} while (status);
exit_builtin(args);
return (0);
}
