#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) 
{
    const unsigned char *ptr = (const unsigned char *)s;

    ptr += n;

    for (size_t i = 0; i < n; i++) 
    {
        if (*(--ptr) == (unsigned char)c) 
        {
            return (void *)ptr; 
        }
    }
    return NULL; 
}

