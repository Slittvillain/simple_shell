/**
 * handle_builtin - handles builtin shell commands
 * @args: array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int handle_builtin(char **args)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
			exit(atoi(args[1]));
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	return (1);
}
