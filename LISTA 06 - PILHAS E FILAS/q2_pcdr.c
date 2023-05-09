#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct stackNode{
	struct stackNode *next;
};
void push(struct stackNode **head, int a);
int pop(struct stackNode **head);
int isEmpty(struct stackNode *head);

void push(struct stackNode **head, int a){ //push - inserindo novos elementos na pilha

  struct stackNode *novo = (struct stackNode *)malloc(sizeof(struct stackNode));
    novo->next = *head;
    *head = novo; //atualizando a cabeca da pilha
}

int pop(struct stackNode **head){ //removendo um elemento da pilha
	struct stackNode *temp;
	int var;
	temp = *head;
	var = (*head)->valor; //retornando o valor contindo na antiga pilha
	*head = (*head)->next; //atualizando a cabeça da pilha para o proximo elemento
	free(temp); //desalocando o espaco de memoria usado
		
	return var;
}

int isEmpty(struct stackNode *head){ //verifica se a pilha esta vazia
	return head == NULL;
}

void finish(struct stackNode *head){
    while(!empty(p)){
        pop(p);
    }
}


int main(){
    int i, tam;
    struct pilha p;
    char expressao[1001];

    while(scanf("%s\n", &expressao) != EOF){
        inicializa(&p);
        tam = strlen(expressao);

        for(i = 0; i < tam; ++i){
            if(expressao[i] == '('){
                push(&p, '(');
            }else if(expressao[i] == ')'){
                if(empty(&p))   break;
                else            pop(&p);
            }
        }

        if(i == tam && empty(&p))   printf("correct\n");
        else                        printf("incorrect\n");

        destroi(&p);
    }

    return 0;
}