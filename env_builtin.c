#include "builtins.h"

/**
 * bin_env - Implementation for the env builtin command
 *
 * @info: Pointer to general information about the shell
 * @arguments: Array of arguments passed to the env command
 *
 * Description:
 * This function executes the env command, which retrieves and prints
 * the environment variables of the shell.
 */
void bin_env(general_t *info, char **arguments)
{
	/*
	 * Cast unused parameters to void to prevent compiler warnings
	 */
	(void)info;
	(void)arguments;

	/*
	 * Call the get_full_env function to retrieve and print the
	 * environment variables
	 */
	get_full_env();
}
