#include "config.h"
#include "mod.h"
#include "display.h"
#include "access.h"

int main () 
{
    
    LinkedList one;
    init(&one);
    add(&one, 12);
    add(&one, 13);
    add(&one, 14);
    add(&one, 15);
    add(&one, 16);
    removeItem(&one, 3);
    printl(&one);
    printf("%d", getItem(&one, 12));

    return 0;
}
