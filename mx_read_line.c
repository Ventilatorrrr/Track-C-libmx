#include "libmx.h"
#include <unistd.h>
#include <stdlib.h>

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0 || !lineptr || buf_size == 0) return -2;

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    size_t total_len = 0;
    size_t line_len = 0;
    bool found_delim = false;

    *lineptr = mx_strnew(buf_size);
    if (!*lineptr) return -2;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[bytes_read] = '\0'; 
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (buffer[i] == delim) {
                found_delim = true;
                break;
            }
            if (total_len >= buf_size - 1) {
                // Збільшуємо розмір пам'яті для рядка
                char *new_lineptr = mx_realloc(*lineptr, buf_size + BUFFER_SIZE);
                if (!new_lineptr) return -2;
                *lineptr = new_lineptr;
                buf_size += BUFFER_SIZE;
            }
            (*lineptr)[total_len++] = buffer[i];
        }
        if (found_delim) break;
    }

    if (bytes_read == -1) return -2; 
    if (total_len == 0 && bytes_read == 0) return -1; // EOF без даних

    (*lineptr)[total_len] = '\0'; 

    return total_len;
}

