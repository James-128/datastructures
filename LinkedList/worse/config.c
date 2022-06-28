#include"config.h"

int listActive = 0;

struct item *first = NULL;
struct item *current = NULL;


void init() { 
    first = create();
    current = create();
}