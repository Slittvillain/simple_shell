#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>


/* shell_memory.c */
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/* shell_free.c */
void free_memory_p(void *ptr);
void free_memory_pp(void **ptr);

#endif /* MEMORY_H */
