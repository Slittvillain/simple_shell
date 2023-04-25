#ifndef ERROR_H
#define ERROR_H

#include "general.h"
#include "text.h"

/*
 * Returns the appropriate error message based on the general_t struct.
 */
char *message_selector(general_t info);

/*
 * Displays an error message based on the general_t struct.
 */
void error(general_t *info);

/*
 * Displays an error message based on the general_t struct
 * and an additional message.
 */
void error_extra(general_t *info, char *extra);

#endif /* ERROR_H */
