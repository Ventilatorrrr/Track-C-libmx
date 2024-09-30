#include "libmx.h"

void mx_pop_back(t_list **list) 
{
    if (list == NULL || *list == NULL) 
    {
        return;
    }

    if ((*list)->next == NULL) 
    {
        free(*list);
        *list = NULL;
        return;
    }

    t_list *prev = NULL;
    t_list *current = *list;

    while (current->next != NULL) 
    {
        prev = current;
        current = current->next;
    }

    free(current);
    prev->next = NULL;
}

