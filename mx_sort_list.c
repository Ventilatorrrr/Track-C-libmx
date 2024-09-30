#include "libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) 
{
    if (list == NULL || list->next == NULL) 
    {
        return list;
    }

    t_list *sorted = NULL;
    t_list *current = list;

    while (current != NULL) 
    {
        t_list *next = current->next;
        if (sorted == NULL || cmp(current->data, sorted->data)) 
        {
            current->next = sorted;
            sorted = current;
        } else 
        {
            t_list *temp = sorted;
            while (temp->next != NULL && cmp(temp->next->data, current->data)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    return sorted;
}

