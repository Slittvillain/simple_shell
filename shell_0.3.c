#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
* main - Entry point
* Description: Launches the shell
*
* Return: 0 on success
*/
int main(void)
{
char *line = NULL, **args = NULL, **env = NULL;
ssize_t read = 0;
size_t len = 0;
int status = 1, num_args = 0;

env = _copyenv();

while (status)
{
write(STDOUT_FILENO, "$ ", 2);
read = getline(&line, &len, stdin);

if (read == -1)
break;
num_args = _countwords(line);
args = _split(line, num_args);

status = _execute(args, env);

free(line);
free(args);
line = NULL;
len = 0;
}

free(line);
free(args);
_freeenv(env);

return (0);
}

/**
* _execute - Executes the command
* @args: Array of arguments passed
* @env: Environment variables
*
* Return: 0 on success, 1 on failure
*/
int _execute(char **args, char **env)
{
int status = 0;

if (args == NULL || args[0] == NULL)
return (1);

if (_builtin(args, env))
return (1);

status = _launch(args, env);

return (status);
}

/**
* _launch - Launches an executable program
* @args: Array of arguments passed
* @env: Environment variables
*
* Return: 0 on success, 1 on failure
*/
int _launch(char **args, char **env)
{
pid_t pid;
int status = 0;

pid = fork();

if (pid == 0)
{
if (execve(args[0], args, env) == -1)
{
perror(args[0]);
exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
perror("fork");
status = 1;
}
else
{
wait(&status);
}

return (status);
}

/**
* _builtin - Executes the built-in functions
* @args: Array of arguments passed
* @env: Environment variables
*
* Return: 0 if not a built-in function, 1 on success, -1 on failure
*/
int _builtin(char **args, char **env)
{
int i, status = 0;

if (args == NULL || args[0] == NULL)
return (status);

if (strcmp(args[0], "exit") == 0)
{
_freeenv(env);
exit(EXIT_SUCCESS);
}
else if (strcmp(args[0], "env") == 0)
{
for (i = 0; env[i] != NULL; i++)
printf("%s\n", env[i]);
status = 1;
}

return (status);
}

/**
* _countwords - Counts the number of words in a string
* @str: The string to count words in
*
* Return: Number of words in the string
*/
int _countwords(char *str)
{
int count = 0;
char *token = strtok(str, " \n\t");

while (token != NULL)
{
count++;
token = strtok(NULL, " \n\t");
}

return (count);
}
