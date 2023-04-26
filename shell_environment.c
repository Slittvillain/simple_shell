#include "shell_commands.h"
#include "shell_general.h"
#include "shell_text.h"
#include <string.h>
#include <unistd.h>

/**
 * _getenv - Get an environment variable
 *
 * @name: Name of the environment variable to get
 *
 * Return: Value of @name on success, otherwise NULL
 **/
char *_getenv(const char *name)
{
	char **env;
	char *aux, *token, *value;
	int size;

	size = _strlen((char *)name);

	for (env = environ; *env != NULL; env++)
	{
		aux = _strdup(*env);

		token = strtok(aux, "=");
		if (token == NULL)
		{
			free(aux);
			return (NULL);
		}

		if (_strlen(token) != size)
		{
			free(aux);
			continue;
		}

		if (_strcmp((char *)name, aux) == 0)
		{
			token = strtok(NULL, "=");
			value = _strdup(token);

			free(aux);
			return (value);
		}

		free(aux);
	}

	return (NULL);
}

/**
 * which - Find the directory containing the command
 *
 * @filename: Name of the command
 * @info: General information about the shell
 *
 * Return: Pointer to the directory containing the command or NULL on failure
 **/
char *which(char *filename, general_t *info)
{
	char *path, *tmp_path, *token;
	char *slash;
	int size;

	(void)info;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");

	size = _strlen(filename) + 2;
	slash = malloc(size * sizeof(char));
	slash = _strcpy(slash, "/");
	slash = _strcat(slash, filename);

	while (token != NULL)
	{
		tmp_path = malloc(_strlen(token) + size);
		tmp_path = _strcpy(tmp_path, token);
		tmp_path = _strcat(tmp_path, slash);

		if (is_executable(tmp_path) == PERMISSIONS)
		{
			free(slash);
			free(path);
			return (tmp_path);
		}

		token = strtok(NULL, ":");

		free(tmp_path);
	}

	free(path);
	free(slash);

	return (NULL);
}

/**
 * is_current_path - Check if PATH starts with a colon
 *
 * @path: PATH to check
 * @info: General information about the shell
 **/
void is_current_path(char *path, general_t *info)
{
	info->is_current_path = _FALSE;

	if (path == NULL)
		return;

	if (path[0] == ':')
		info->is_current_path = _TRUE;
}

/**
 * get_full_env - Print all environment variables
 **/
void get_full_env(void)
{
	char **tmp;
	int i;

	for (i = 0, tmp = environ; tmp[i] != NULL; i++)
	{
		print(tmp[i]);
		_putchar('\n');
	}
}

