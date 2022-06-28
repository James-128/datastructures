#ifndef CONFIG_H
#define CONFIG_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mod.h"

struct item{
	int value;
	struct item *next;
	int active;
};

extern struct item *first;
extern struct item *current;

extern int listActive; // extern makes a definition a declaration.

void init();

#endif