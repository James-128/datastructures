#include "display.h"

void printl (LinkedList* list)
{

    list->current = list->first;
    Item* current = current;
    while(list->current) // go through all of them don't stop at current->next
    {
        printf("%p: %d, %p\n", list->current, list->current->value, list->current->next);
        list->current = list->current->next;
    }

}