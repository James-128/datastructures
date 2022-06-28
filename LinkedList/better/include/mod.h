#ifndef MOD_H
#define MOD_H

#include "config.h"

Item* create();
void init (LinkedList* list);
void add (LinkedList* list, int value);
void removeItem (LinkedList* list, int index);
#endif