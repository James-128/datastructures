#include "mod.h"

/*
Item hehe = malloc(sizeof(Item));
doesn't work because functions in C won't be executed
unless they are called within another function.
This makes it so the code within the malloc function won't run since
it isn't being called within a function.
*/

void init (LinkedList* list)
{
    list->first = create();
    list->current = create();
    list->size = 0;
}

Item* create ()
{
    // a wrapper function for malloc
    Item* tmp;
    tmp = (Item*)malloc(sizeof(Item*));

    if (tmp==NULL)
    {
        puts("Some malloc error");
        return NULL;
    }

    tmp->value = 0;
    tmp->next = NULL;
 
    return tmp;
}

void add (LinkedList* list, int value)
{
    // adds an item to the end of a linked list

    Item* tmp;
    tmp = create();

    tmp->next = NULL;
    tmp->value = value;
    
    if (list->size == 0) 
    {
        list->first = tmp;
        list->current = tmp;
        list->empty = 0;
        list->size++;
        return;
    }

    // find last element
    while (list->current->next)
        list->current = list->current->next;
    
    list->current->next = tmp;
    list->size++;
}

void removeItem (LinkedList* list, int index)
{
    list->current = list->first;

    // go to one item before the one being deleted
    for (int i = 0; i < index-1; i++)
        list->current = list->current->next;

    Item* tmp = list->current->next;

    // skip two items ahead (o->o->|o|) and assign that to the current->next
    // this cuts out the very next item which can then be freed and forgotten
    // about
    list->current->next = list->current->next->next;

    list->size--;
    free(tmp);
}