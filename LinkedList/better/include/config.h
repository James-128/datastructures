#ifndef CONFIG_H
#define CONFIG_H

#include<stdlib.h>
#include<stdio.h>

typedef struct item {
    int value;
    struct item* next;
}Item;

typedef struct linkedList {
    Item* first;
    Item* current;
    size_t size;
    int empty;
} LinkedList;

/*
if extern is used here:
Undefined symbols for architecture arm64:
  "_hehe", referenced from:
      _main in main-186ab5.o
      _init in config-199d7c.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
*/

#endif