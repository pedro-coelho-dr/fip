#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

//Prototypes
struct node{
	char *id;
	struct node *next;
};
struct queue{
    struct node *head;
    struct node *tail;
};
void start(struct queue *q);
int isEmpty(struct queue *q);
void enqueue(struct queue *q, char *id);
char *dequeue(struct queue *q);

//Main
int main() {
    int choice;
    char id[6];
    struct queue L,N,S,O;
    start(&L),start(&N),start(&S),start(&O);
    while(TRUE){
        scanf("%d",&choice);
        if(choice == 0){
            break;
        }
        scanf("%s",id);
        char *id2 = (char*)malloc(sizeof(char)*6);
        strcpy(id2,id);
        switch(choice){
            case -4:
                enqueue(&L,id2);
                break;
            case -3:
                enqueue(&N,id2);
                break;
            case -2:
                enqueue(&S,id2);
                break;
            case -1:
                enqueue(&O,id2);
                break;
            default:
                break;
        }
    }
    int first=TRUE;
    while (!isEmpty(&O) || !isEmpty(&N) || !isEmpty(&S) || !isEmpty(&L)) {
        if (!isEmpty(&O)) {
            if (first) {
                printf("%s", dequeue(&O));
                first = FALSE;
            } else {
                printf(" %s", dequeue(&O));
            }
        }
        if (!isEmpty(&N)) {
            if (first) {
                printf("%s", dequeue(&N));
                first = FALSE;
            } else {
                printf(" %s", dequeue(&N));
            }
        }
        if (!isEmpty(&S)) {
            if (first) {
                printf("%s", dequeue(&S));
                first = FALSE;
            } else {
                printf(" %s", dequeue(&S));
            }
        }
        if (!isEmpty(&L)) {
            if (first) {
                printf("%s", dequeue(&L));
                first = FALSE;
            } else {
                printf(" %s", dequeue(&L));
            }
        }
    }
    printf("\n");
    return 0;
}

//Functions
void start(struct queue *q){
    q->head = NULL;
    q->tail = NULL;
}
int isEmpty(struct queue *q){
    return (q->head == NULL);
}
void enqueue(struct queue *q, char *id){
    struct node *novo = (struct node*)malloc(sizeof(struct node));
    novo->id = id;
    novo->next = NULL;
    if (isEmpty(q)) {
        q->head = novo;
        q->tail = novo;
    }else{
        q->tail->next = novo;
        q->tail = novo;
    }
}
char *dequeue(struct queue *q){
    if (isEmpty(q)) {
        return NULL;
    }
    struct node *temp = q->head;
    char *id = temp->id;
    q->head = q->head->next;
    free(temp);
    return id;
}