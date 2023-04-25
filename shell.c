#include "shell.h"

/**
 * main - Main entry point for the shell program
 *
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;

	while (1)
	{
		/* Print prompt and read command line input */
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		/* Parse command line input into arguments */
		args = parse_input(line);
		if (args == NULL)
			continue;

		/* Exit if "exit" command is entered */
		if (_strcmp(args[0], "exit") == 0)
		{
			free_args(args);
			break;
		}

		/* Execute command */
		if (execute_command(args) == -1)
			perror("Error executing command");

		/* Free memory used by args array */
		free_args(args);
	}

	free(line);
	return (0);
}

/**
 * parse_input - Parse a command line input into an array of arguments
 *
 * @line: The command line input string
 *
 * Return: An array of arguments, or NULL if an error occurred
 */
char **parse_input(char *line)
{
	char **args = NULL;
	char *token;
	int i, token_count = 0;

	/* Count number of tokens in input line */
	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ')
			token_count++;
	}

	/* Allocate memory for args array */
	args = malloc(sizeof(char *) * (token_count + 2));
	if (args == NULL)
	{
		perror("Error allocating memory");
		return (NULL);
	}

	/* Parse input line into arguments */
	token = strtok(line, " \n");
	for (i = 0; token != NULL; i++)
	{
		args[i] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;

	return (args);
}

/**
 * execute_command - Execute a command with the given arguments
 *
 * @args: An array of arguments for the command
 *
 * Return: 0 on success, -1 on error
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	/* Fork a child process */
	pid = fork();
	if (pid < 0)
	{
		perror("Error forking process");
		return (-1);
	}
	else if (pid == 0)
	{
		/* Child process: execute command */
		if (execvp(args[0], args) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process: wait for child process to complete */
		waitpid(pid, &status, 0);
	}

	return (0);
}

/**
 * free_args - Free memory used by args array
 *
 * @args: The args array to free
 */
void free_args(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
	{
		free(args[i]);
	}
	free(args);
}
