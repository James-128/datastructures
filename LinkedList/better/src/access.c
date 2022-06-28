#include "access.h"

int getItem (LinkedList* list, int index)
{
    if (index>list->size)
    {
        printf("Index out of bounds. List size is %zu\n", list->size);
        return -1;
    }
    list->current = list->first;
    for (int i = 0; i < index; i++)
        list->current = list->current->next;
    return list->current->value;
}