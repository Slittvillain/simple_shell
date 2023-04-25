#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdlib.h>

/* Returns the length of the input string */
size_t my_strlen(const char *str);

/* Concatenates two strings */
char *my_strcat(const char *str1, const char *str2);

/* Copies a string to another */
char *my_strcpy(char *dest, const char *src);

/* Duplicates a string */
char *my_strdup(const char *str);

/* Compares two strings */
int my_strcmp(const char *str1, const char *str2);

#endif /* STRING_UTILS_H */


#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

#include <stdio.h>

/* Returns a string representation of an integer */
char *int_to_str(int num);

/* Determines if a string contains only digits */
int is_numeric(const char *str);

/* Converts a string to an integer */
int my_atoi(const char *str);

/* Determines if a string contains letters */
int contains_letters(const char *str);

#endif /* TEXT_UTILS_H */


#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

/* Prints a string to stdout */
void my_print(const char *str);

/* Prints a string to stderr */
void my_error(const char *str);

#endif /* PRINT_UTILS_H */


#ifndef TOKEN_UTILS_H
#define TOKEN_UTILS_H

#include <stdlib.h>

/* Splits a string into an array of substrings using the specified delimiter */
char **split_string(const char *str, char delimiter);

/* Joins an array of strings into a single string using the specified delimiter */
char *join_strings(const char **strings, size_t n, const char *delimiter);

#endif /* TOKEN_UTILS_H */


#ifndef PATTERN_UTILS_H
#define PATTERN_UTILS_H

/* Replaces a pattern in a string with a value */
char *replace_pattern(const char *str, const char *pattern, const char *value);

#endif
