#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#include "general.h"
#include "text.h"
#include "error.h"
#include "builtins.h"
#include "memory.h"

/* Declare global variable */
extern char **environ;

/* Declare functions */
void analyze_commands(char **arguments, general_t *info, char *buff);
int is_executable_file(char *filename);
int is_regular_file(char *filename);
char *get_environment_variable(const char *name);
char *search_for_executable_file(char *filename, general_t *info);
void check_if_current_directory_is_in_path(char *path, general_t *info);
void get_full_environment_variables();

void execute_command(char *command, char **arguments, general_t *info, char *buff);
int execute_command_in_current_directory(char *command, char **arguments, char *buff,
        general_t *info);

#endif /* COMMANDS_H */
