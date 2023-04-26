#ifndef ERROR_H
#define ERROR_H

#include "shell_general.h"
#include "shell_text.h"

/*shell_ error.c */
char *message_selector(general_t info);
void error(general_t *info);
void error_extra(general_t *info, char *extra);

#endif /* ERROR_H */
