#include "libmx.h"

char *mx_file_to_str(const char *filename) 
{
    if (!filename)
        return NULL;

    int file = open(filename, O_RDONLY);
    if (file < 0)
        return NULL;
    
    int len = mx_filelen(file);

    if (len < 0) {
        close(file);
        return NULL; 
    }

    char *text = mx_strnew(len);
    if (text == NULL) {
        close(file);
        return NULL; 
    }

    ssize_t bytes_read = read(file, text, len);
    if (bytes_read < 0 || bytes_read != len) {
        close(file);
        free(text); 
        return NULL;
    }

    close(file);
    return text;
}

