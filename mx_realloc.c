#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) 
{
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL) 
    {
        return malloc(size);
    }

    void *new_ptr = malloc(size);
    if (new_ptr == NULL) 
    {
        return NULL;
    }

    size_t old_size = malloc_size(ptr);
    if (old_size > size) 
    {
        old_size = size; 
    }

    mx_memmove(new_ptr, ptr, old_size); 
    free(ptr); 

    return new_ptr; 
}

