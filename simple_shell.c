/**
 * prompt - Print the prompt
 *
 * @info: Struct of general information
 **/
void prompt(general_t *info)
{
	if (info->mode == NON_INTERACTIVE)
		return;

	print_string("$ ");
}

/**
 * read_prompt - Read lines in the prompt
 *
 * Return: Buffer read or NULL if EOF was found
 **/
char *read_prompt()
{
	char *buffer;
	int res;
	size_t size;

	buffer = NULL;

	res = getline(&buffer, &size, stdin);

	if (res == EOF)
	{
		free_memory_p((void *) buffer);
		return (NULL);
	}

	return (buffer);
}

/**
 * start_prompt - Loop reading text
 *
 * @info: Struct of general information
 *
 * Return: Buffer read or NULL if EOF was found
 **/
void start_prompt(general_t *info)
{
	char *buffer;
	char **arguments;
	char *path;

	signal(SIGINT, handle_sigint);
	while (1)
	{
		prompt(info);

		path = _getenv("PATH");
		is_current_path(path, info);

		info->environment = path;
		buffer = read_prompt();
		if (buffer == NULL)
		{
			print_string(info->mode == INTERACTIVE ? "exit\n" : "");
			free_memory_p((void *) path);
			break;
		}

		info->n_commands++;
		if (buffer[0] != '\n')
		{
			arguments = split_words(buffer, " \t\n");

			info->arguments = arguments;
			info->buffer = buffer;
			analyze_patterns(info, arguments);
			analyze(arguments, info, buffer);

			free_memory_pp((void *) arguments);
		}

		free_memory_p((void *) buffer);
		free_memory_p((void *) path);
	}

}

/**
 * handle_sigint - Handler for SIGINT
 *
 * @signal_number: Unused parameter
 **/
void handle_sigint(int signal_number)
{
	(void) signal_number;

	signal(SIGINT, handle_sigint);
	print_string("\n$ ");
	fflush(stdout);
}
