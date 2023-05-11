#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//PROTOTYPES
//queue
struct qNode {
    int value;
    struct qNode *next;
};
struct Queue {
    struct qNode *head;
    struct qNode *tail;
};
struct qNode *newQNode(int k);
struct Queue *startQueue();
void enQueue(struct Queue *q, int k);
int deQueue(struct Queue *q);
int isQueueEmpty(struct Queue *q);
//priority queue
struct pqNode {
    int value;
    struct pqNode *next;
};
struct pQueue {
    struct pqNode *head;
};
struct pqNode *newPQNode(int k);
struct pQueue *startPQueue();
void enPQueue(struct pQueue *pq, int k);
int dePQueue(struct pQueue *pq);
int isPQueueEmpty(struct pQueue *pq);
//stack 
struct stackNode {
    int value;
    struct stackNode *next;
};
struct Stack {
    struct stackNode *head;
};
struct stackNode *newStackNode(int k);
struct Stack *startStack();
void push(struct Stack *stack, int k);
int pop(struct Stack *stack);
int isStackEmpty(struct Stack *stack);

//MAIN
int main() {
    int n, x, y;
    while (scanf("%d", &n) != EOF) {
        int boolStack = TRUE, boolQueue = TRUE, boolPriority = TRUE;

        struct Stack *stack = startStack();
        struct Queue *queue = startQueue();
        struct pQueue *pqueue = startPQueue();

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            if (x == 1) {
                push(stack, y);
                enQueue(queue, y);
                enPQueue(pqueue, y);
            } else if (x == 2) {
                if (!isStackEmpty(stack) && y != pop(stack)){
                    boolStack = FALSE;
                }if (!isQueueEmpty(queue) && y != deQueue(queue)){
                    boolQueue = FALSE;
                }if (!isPQueueEmpty(pqueue) && y != dePQueue(pqueue)){
                    boolPriority = FALSE;
                }
            }
        }
        int sum = boolStack + boolQueue + boolPriority;
        if (sum > 1){
            printf("not sure\n");
        }else if (boolQueue==TRUE){
            printf("queue\n");
        }else if (boolStack==TRUE){
            printf("stack\n");
        }else if (boolPriority==TRUE){
            printf("priority queue\n");
        }else{
            printf("impossible\n");
        }
    }

    return 0;
}

//FUNCTIONS
struct qNode *newQNode(int k) {
    struct qNode *temp = (struct qNode *)malloc(sizeof(struct qNode));
    temp->value = k;
    temp->next = NULL;
    return temp;
}

struct Queue *startQueue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->head = q->tail = NULL;
    return q;
}

void enQueue(struct Queue *q, int k) {
    struct qNode *temp = (struct qNode *)malloc(sizeof(struct qNode));
    temp->value = k;
    temp->next = NULL;
    if (q->tail == NULL) {
        q->head = temp;
        q->tail = temp;
    }

    q->tail->next = temp;
    q->tail = temp;
}

int deQueue(struct Queue *q) {
    if (q->head == NULL)
        return -1;

    int value = q->head->value;
    struct qNode *temp = q->head;

    q->head = temp->next;

    if (q->head == NULL)
        q->tail = NULL;

    free(temp);
    return value;
}


int isQueueEmpty(struct Queue *q) {
    return q->head == NULL;
}

struct pqNode *newPQNode(int k) {
    struct pqNode *temp = (struct pqNode *)malloc(sizeof(struct pqNode));
    temp->value = k;
    temp->next = NULL;
    return temp;
}

struct pQueue *startPQueue() {
    struct pQueue *pq = (struct pQueue *)malloc(sizeof(struct pQueue));
    pq->head = NULL;
    return pq;
}

void enPQueue(struct pQueue *pq, int k) {
    struct pqNode *temp = newPQNode(k);

    if (pq->head == NULL || pq->head->value < k) {
        temp->next = pq->head;
        pq->head = temp;
    } else {
        struct pqNode *current = pq->head;
        while (current->next != NULL && current->next->value > k)
            current = current->next;

        temp->next = current->next;
        current->next = temp;
    }
}

int dePQueue(struct pQueue *pq) {
    if (pq->head == NULL)
        return -1;

    int value = pq->head->value;
    struct pqNode *temp = pq->head;
    pq->head = temp->next;
    free(temp);
    return value;
}

int isPQueueEmpty(struct pQueue *pq) {
    return pq->head == NULL;
}

struct stackNode *newStackNode(int k) {
    struct stackNode *temp = (struct stackNode *)malloc(sizeof(struct stackNode));
    temp->value = k;
    temp->next = NULL;
    return temp;
}

struct Stack *startStack() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->head = NULL;
    return stack;
}

void push(struct Stack *stack, int k) {
    struct stackNode *temp = newStackNode(k);
    temp->next = stack->head;
    stack->head = temp;
}

int pop(struct Stack *stack) {
    if (stack->head == NULL){
        return -1;
    }
    int value = stack->head->value;
    struct stackNode *temp = stack->head;
    stack->head = temp->next;
    free(temp);
    return value;
}

int isStackEmpty(struct Stack *stack) {
    return stack->head == NULL;
}
