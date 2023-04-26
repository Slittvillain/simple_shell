#include "shell_general.h"
#include "shell_text.h"
#include "shell_commands.h"

/**
* replacement - Replaces a shell environment variable with its value.
* @info: A pointer to the general information struct.
* @index: Unused integer pointer.
* @string: A string containing the environment variable name to be replaced.
*
* Return: The value of the environment variable if found, otherwise NULL.
*/
char *replacement(general_t *info, int *index, char *string)
{
char *tmp;
char symbol;

(void)index;

symbol = *string;
if (symbol != '?' && symbol != '$')
{
tmp = replace_env(info, string);
return (tmp);
}

tmp = (symbol == '$') ? to_string(info->pid) :
to_string(info->status_code);

return (tmp);
}

/**
* replace_env - Retrieves the value of an environment variable.
* @info: A pointer to the general information struct.
* @environment: The name of the environment variable.
*
* Return: The value of the environment variable if found, otherwise NULL.
*/
char *replace_env(general_t *info, char *environment)
{
char *env;

(void)info;

env = _getenv(environment);
if (env != NULL)
return (env);

return (NULL);
}
