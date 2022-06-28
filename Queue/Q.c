#include<stdio.h>
#include<stdlib.h>

enum ERROR {
    Qempty =  INT32_MAX
};

typedef struct queue { 
    size_t size;
    size_t cap;
    int *array;
    unsigned long front;
    unsigned long back;
}Queue;

Queue *init (size_t cap) {

    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->size = 0;
    q->cap = cap;
    q->front = 0;
    q->back = 0; // back points to the very last item in the array

    q->array = (int *) calloc(cap, sizeof(int));

   return q; 
}

void PowerPrint (Queue *q) {

    for (int i = 0; i < q->cap; i++){

        if (q->front == q->back && q->back == i) {
            printf("FB ");
            continue;
        }

        if (i == q->front){
            printf(" F ");
            continue;
        }

        if (i == q->back) {
            printf(" B ");
            continue;
        }

        printf("   ");
    }

    puts("");

    for (int i = 0; i < q->cap; i++){
        printf("%02d ", q->array[i]);
    }
    puts("");
}

void PowerWrite (Queue *q, FILE *fn) {

    for (int i = 0; i < q->cap; i++){

        if (q->front == q->back && q->back == i) {
            fprintf(fn,"FB ");
            continue;
        }

        if (i == q->front){
            fprintf(fn, " F ");
            continue;
        }

        if (i == q->back) {
            fprintf(fn, " B ");
            continue;
        }

        fprintf(fn, "   ");
    }

    fputs("\n", fn);

    for (int i = 0; i < q->cap; i++){
        fprintf(fn, "%02d ", q->array[i]);
    }
    fputs("\n", fn);
}

void PseudoPrint (Queue *q) {
    for (int i = 0; i < q->cap; i++){
        printf("%d ", q->array[i]);
    }
    puts("");
}

int push (Queue *q, int num) { // enQueue
    
    if (q->size == q->cap) {
        puts("Queue is full");
        return -1;
    }


    if (q->back == q->cap-1) {
        
        q->back = 0;
        q->array[q->back] = num;
    }
    else if (q->size == 0) {

        q->array[q->back] = num;
    }
    else {
        q->array[q->back+1] = num;
        q->back++;
    }
    
    q->size++;
   return 0; 
}

int pop (Queue *q) { // deQueue

    // size_t front = q->front; these have to be written to so these declarations would be pointless
    // size_t back = q->back;

    size_t size = q->size;
    int *array = q->array;

    if (size == 0) {
        puts("Queue is empty");
        return Qempty; // TODO figure out how to manage error state
    }
    int num = array[q->front];
    array[q->front] = 0;

    if (size == 1) {
        q->front = 0;
        q->back = 0;
        q->size--;
        return num;
    }

    if (q->front == q->cap-1) {
        q->front = 0;
        q->size--;
        return num;
    }
    
    q->front++;
    q->size--;
    return num;
}

int main () {

    Queue *hehe = init(5);
    push(hehe, 1);
    PowerPrint(hehe); 
    push(hehe, 2);
    PowerPrint(hehe); 
    push(hehe, 3);
    PowerPrint(hehe); 
    push(hehe, 4);
    PowerPrint(hehe); 
    push(hehe, 55);

    FILE *fn;

    fn = fopen("hehe.log", "w");

    for (int i = 0; i < 200; i++){
        int tmp = rand()%10;

        if (tmp%2) {
            int pushed = push(hehe, tmp);

            if (pushed == -1 ){
                fprintf(fn, "Queue is full\n");
            }

        }
        if (!(tmp%2)){

            int popped = pop(hehe);
            
            printf("popped: %d\n", popped);

            if (popped == Qempty) {
                fprintf(fn, "Queue is empty\n");
            }
        }

        PowerWrite(hehe, fn);

    }

    fclose(fn);

    return 0;
}
