#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#include "shell_general.h"
#include "shell_text.h"
#include "shell_error.h"
#include "shell_builtins.h"
#include "shell_memory.h"

extern char **environ;

int is_executable(char *filename);
int is_file(char *command);

/* shell_commands.c */
void analyze(char **arguments, char *buff, general_t *info);

void execute(char *commands, char **arguments, general_t *info, char *buff);
int current_directory(char *cmd, char **arguments, char *buff,
general_t *info);

char *_getenv(const char *name);
char *which(char *filename, general_t *info);
void is_current_path(char *path, general_t *info);
void get_full_env(void);

#endif
