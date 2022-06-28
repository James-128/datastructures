#include"mod.h"
#include"display.h"

struct item *create(){

	struct item *tmp;
	tmp = (struct item *)malloc(sizeof(struct item)); // pointers inside structs are hazards

    if (tmp==NULL){
        puts("Malloc error");
        return NULL;
    }    
    
    tmp->next = NULL; // identify the end of LL
    tmp->value = 0; // good practice

	return tmp;
}

void add() {

    struct item *tmp = create();

    puts("Enter a value.\n");
    scanf("%d", &tmp->value);


    if (listActive == 0) {
        first = tmp;
        current = tmp;
        listActive = 1;
        return; //super Colby move
    }
    
    current->next = tmp;
    current = tmp;

}

// void destroy (){
//     current = first;

//     while (current->next!=NULL) {
//         first = current->next;
//         free(current);
//         current = first;
//     }
//     free(first);

//     showList();
// }

void remove (int num) {

    current = first;

    while (num >= 0) {
        current = current->next;
    }

    // i want more pointers in my structtttttttttttt


}