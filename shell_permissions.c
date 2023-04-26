#include "shell_commands.h"
#include "shell_general.h"

/**
* is_executable - Check if a filename has permissions
* for execution.
*
* @filename: Filename to check.
*
* Return: On success, PERMISSIONS.
* On error, NON_PERMISSIONS.
**/
int is_executable(char *filename)
{
struct stat stats;

if (stat(filename, &stats) == 0)
{
if (stats.st_mode & X_OK)
return (PERMISSIONS);
else
return (NON_PERMISSIONS);
}

return (NON_FILE);
}

/**
* is_file - Check if it is a file or binary.
*
* Description: Look for execution permissions and
* if it is a file.
*
* @file: File to check.
*
* Return: If it is a file with the correct permissions, PERMISSIONS.
* If it is a file but does not have permissions or does not exist,
* NON_PERMISSIONS.
* If it is not a file, NON_FILE.
**/
int is_file(char *file)
{
int i, size;

size = _strlen(file);
for (i = 0; i < size; i++)
if (file[i] == '/')
return (is_executable(file));

return (NON_FILE);
}
