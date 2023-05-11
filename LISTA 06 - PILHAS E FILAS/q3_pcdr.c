#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototypes
struct stackNode{
    int value;
    struct stackNode *next;
};
void push(struct stackNode **head, int value);
void pop(struct stackNode **head);
int empty(struct stackNode *head);

//main
int main(){
    struct stackNode head;
    int len, i;
    char input[1001];
    while(scanf("%s\n", &input) != EOF){
        struct stackNode *head = NULL;
        len = strlen(input);
        for(i = 0; i < len; i++){
            if(input[i] == '('){
                push(&head, 1);
            }else if(input[i] == ')'){
                if(empty(head)){
                    break;
                }else{
                    pop(&head);
                }
            }
        }
        if(i==len && empty(head)){
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }
        while(!empty(head)){
        pop(&head);
        }
    }
    return 0;
}
//functions
void push(struct stackNode **head, int value){
    struct stackNode *novo = (struct stackNode *)malloc(sizeof(struct stackNode));
    if(novo!= NULL){
        novo->value = value;
        novo->next = *head;
        *head = novo;
    }
}
void pop(struct stackNode **head){
    struct stackNode *temp;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}
int empty(struct stackNode *head){
    return head == NULL;
}