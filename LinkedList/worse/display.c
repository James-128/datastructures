#include"display.h"

char menu() {
	char input;

	printf("A)dd R)emove S)how\n");
	input = getchar();

	int c = 0;
	while (getchar()!='\n')
        ;

	return input;
}

void showNode(struct item *node) {
	printf("mem: %p value: %d next: %p\n", node, node->value, node->next);
}

void showList() {
	current = first;
 	while (current->next!=NULL){
        	showNode(current);
        	current = current->next;
    	}
	showNode(current);
    current = current->next;
	puts("");
}