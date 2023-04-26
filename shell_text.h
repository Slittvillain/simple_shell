#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "shell_general.h"
#include "shell_memory.h"

/* shell_text.c */
void start_prompt(general_t *info);
void prompt(general_t *info);
char *read_prompt();
void sigintHandler(int sig_num);

/* shell_utils1.c */
int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);

/* shell_utils2.c */
char *to_string(int number);
int is_numerical(unsigned int n);
int _atoi(char *s);
int contains_letter(char *s);

/* shell_printers.c */
int _putchar_to_fd(char l, int fd);
int print_to_fd(char *msg, int fd);

/*shell_printout.c */
int _putchar(char c);
int print(char *msg);

/* shell_printerror.c */
int print_err(char *msg);

/* shell_tokenization.c */
char **split_words(char *line, const char *sep);
char *join_words(char *word1, char *word2, char *word3, const char *sep);

/* shell_patterns.c */
void analyze_patterns(general_t *info, char **arguments);
char *pattern_handler(general_t *info, char *string);
char *replace_value(general_t *info, int *index, char *string);

/* shell_replacer.c */
char *replacement(general_t *info, int *index, char *string);
char *replace_env(general_t *info, char *environment);
#endif /* TEXT_H */
