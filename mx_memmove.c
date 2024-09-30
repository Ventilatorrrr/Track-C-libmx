#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) 
{
    if (dst == src || len == 0) 
    {
        return dst;
    }

    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    if (d < s || d >= s + len) 
    {
        for (size_t i = 0; i < len; i++) 
        {
            d[i] = s[i];
        }
    } else {
        for (size_t i = len; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    }

    return dst; 
}

