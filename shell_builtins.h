#ifndef BUILTINS_H
#define BUILTINS_H

#include "shell_general.h"
#include "shell_text.h"
#include "shell_memory.h"
#include "shell_commands.h"

int builtins(general_t *info, char **arguments);
int check_builtin(general_t *info, char **arguments);


void bin_exit(general_t *info, char **arguments);
int number_controller(general_t *info, char *number);


void bin_env(general_t *info, char **arguments);


void bin_echo(general_t *info, char **arguments);
void echo_printer(int index, char *text, char **arguments);

#endif /* BUILTINS_H */
