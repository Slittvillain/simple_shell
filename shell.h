#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <unistd.h>

/**
 * struct info_s - struct to hold shell program information
 *
 * @argv: command arguments
 * @env: environment variables
 * @buf: buffer to store user input
 * @buf_size: buffer size
 * @status: exit status
 * @err_num: error number
 */
typedef struct info_s
{
	char **argv;       /* Command arguments */
	char **env;        /* Environment variables */
	char *buf;         /* Buffer to store user input */
	int buf_size;      /* Buffer size */
	int status;        /* Exit status */
	int err_num;       /* Error number */
} info_t;

/* Function prototypes */
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);
void print_error(info_t *info, char *msg);
void _eputs(char *str);
void _eputchar(char c);
int _erratoi(char *str);
char *_getenv(info_t *info, char *name);
void _setenv(info_t *info, char *name, char *value);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
char *_strdup(char *str);

#endif /* SHELL_H */
