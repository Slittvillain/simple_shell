#include "shell_builtins.h"

/**
 * bin_env - Implementation for the env builtin
 *
 * @info: General information about the shell
 * @arguments: Command
 *
 * Return: None
 **/
void bin_env(general_t *info, char **arguments)
{
	(void)info;
	(void)arguments;

	get_full_env();
}
