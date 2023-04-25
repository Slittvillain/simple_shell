#ifndef GENERAL_H
#define GENERAL_H

/* Boolean constants */
#define _TRUE 1
#define _FALSE 0

/* Standard I/O file descriptors */
#define STDIN 0
#define STDOUT 1
#define STDERR 2

/* Interactive mode constants */
#define NON_INTERACTIVE 0
#define INTERACTIVE 1

/* Permissions constants */
#define PERMISSIONS 1
#define NON_PERMISSIONS -1

/* File type constants */
#define _FILE 10
#define NON_FILE -10

/* Error messages */
#define _ENOENT_MSG "No such file or directory"
#define _EACCES_MSG "Permission denied"
#define _CMD_NOT_EXISTS_MSG "not found"
#define _ILLEGAL_NUMBER_MSG "Illegal number"

/* Error codes */
#define _CODE_ENOENT 3
#define _CODE_EACCES 13
#define _CODE_CMD_NOT_EXISTS 132
#define _CODE_ILLEGAL_NUMBER 133

/**
 * Description: A struct representing general information used by the program.
 */
typedef struct general_s
{
int argc;
char **argv;
int mode;
int error_code;
char *command;
int n_commands;
char *value_path;
int is_current_path;
int status_code;
char *buffer;
char **arguments;
char *environment;
int pid;
} general_t;

/**
 * A struct representing an error message.
 */
typedef struct error_s
{
char *message;
int code;
} error_t;

/**
 * A struct representing a built-in command.
 */
typedef struct builtin_s
{
char *command;
void (*func)(general_t, char**);
} builtin_t;

#endif /* GENERAL_H */
