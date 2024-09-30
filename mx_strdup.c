#include "libmx.h"

char *mx_strdup(const char *s1)  
{
   int len = mx_strlen(s1);      
   char *str1 = mx_strnew(len);  
   mx_strcpy(str1, s1);          
   return str1;                   
}

