#include "main.h"

/**
 * main - Entry point for the shell
 *
 * Return: Always 0 (success)
 */
int main(void)
{
        char *line;
        char **args;

        while (1)
        {
                line = get_line();
                args = split_line(line);
                execute(args);
                free(line);
                free(args);
        }

        return (0);
}

/**
 * execute - Execute a command with arguments
 * @args: Array of arguments
 */
void execute(char **args)
{
        int i;
        char *path;
        struct stat st;

        if (args[0] == NULL)
                return;

        if (stat(args[0], &st) == 0)
        {
                if (execve(args[0], args, NULL) == -1)
                        perror("execve error");
        }
        else
        {
                path = find_path(args[0]);
                if (path == NULL)
                {
                        perror("command not found");
                        return;
                }

                args[0] = path;
                if (execve(path, args, NULL) == -1)
                        perror("execve error");
        }
}

/**
 * find_path - Find the path for a command
 * @command: Command to search for
 *
 * Return: Full path for command, or NULL if not found
 */
char *find_path(char *command)
{
        int i;
        char *path, *dir, *fullpath;
        struct stat st;

        path = getenv("PATH");
        dir = strtok(path, ":");

        while (dir != NULL)
        {
                fullpath = malloc(strlen(dir) + strlen(command) + 2);
                if (fullpath == NULL)
                        exit(EXIT_FAILURE);

                strcpy(fullpath, dir);
                strcat(fullpath, "/");
                strcat(fullpath, command);

                if (stat(fullpath, &st) == 0)
                        return (fullpath);

                free(fullpath);
                dir = strtok(NULL, ":");
        }

        return (NULL);
}
