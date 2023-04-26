#include "shell_commands.h"
#include "shell_general.h"
#include "shell_memory.h"
#include "shell_text.h"

/**
* analyze_patterns - Analyzes patterns in the arguments array
* @info: Pointer to a struct containing general information
* @arguments: Array of strings containing the command and its arguments
**/
void analyze_patterns(general_t *info, char **arguments)
{
int i;

for (i = 0; arguments[i] != NULL; i++)
arguments[i] = pattern_handler(info, arguments[i]);
}

/**
* pattern_handler - Handles patterns in a string
* @info: Pointer to a struct containing general information
* @string: The string to handle patterns in
* Return: The modified string
**/
char *pattern_handler(general_t *info, char *string)
{
int i;

for (i = 0; string[i] != '\0'; i++)
{
if (string[i] == '$' && string[i + 1] != '\0')
string = replace_value(info, &i, string);
}

return (string);
}

/**
* replace_value - Replaces a variable with its value
* @info: Pointer to a struct containing general information
* @index: Pointer to the index of the '$' character
* @string: The string containing the variable
* Return: The modified string
**/
char *replace_value(general_t *info, int *index, char *string)
{
int i, new_s, old_s;
char *value;

i = *index;
i++;

value = replacement(info, index, string + i);
if (value == NULL)
{
string = _strcpy(string, "");

return (string);
}

old_s = _strlen(string);
new_s = _strlen(value) + 1;

string = _realloc(string, old_s, new_s);
string = _strcpy(string, value);

free_memory_p(value);
*index = i;
return (string);
}
