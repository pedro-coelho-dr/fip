#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Camiseta {
    char nome[50];
    char cor[10];
    char tamanho;
    struct Camiseta *next;
};

void printList(struct Camiseta **head){
    struct Camiseta *n = *head;
    while(n!=NULL){
        printf("%s %c %s\n", n->cor, n->tamanho, n->nome);
        n = n->next;
    }
}

void sortCor(struct Camiseta **head){
    struct Camiseta *temp;
    struct Camiseta *n = *head;
    while (n!=NULL){
        if (strcmp(n->cor,n->next->cor)>0){
            temp->next = n->next->next;
            n->next->next = n->next;
            n->next = temp->next;
        }
        n=n->next;
}
}


void append(struct Camiseta **head, struct Camiseta *new){
    struct Camiseta *temp;
    temp = *head;

    if (*head == NULL){
        *head = new;
    }else{
        if(strcmp(temp->nome,new->nome)>0){
            new->next = *head;
            *head = new;
            return;
        }else{
            while(temp->next != NULL && strcmp(temp->next->nome,new->nome)<0){
                temp = temp->next;
            }
            new->next = temp->next;
            temp->next = new;
        }
    }
}

int main() {
    char nome[50];
    char cor[10];
    char tamanho;
    int N, control;
    struct Camiseta *head = NULL;
    struct Camiseta *head2 = NULL;
    struct Camiseta *head3 = NULL;
    control=1;
    while(scanf("%d\n", &N)){
        if (N==0){
            break;
        }
        if (control==1){
            control=0;
        }else{
            printf("\n");
        }
        for (int i=0; i<N; i++){
            scanf("%[^\n]\n", &nome);
            scanf("%s %c\n", &cor, &tamanho);
            struct Camiseta *item = (struct Camiseta *)malloc(sizeof(struct Camiseta));
            strcpy(item->nome,nome);
            strcpy(item->cor,cor);
            item->tamanho = tamanho;
            item->next = NULL;

            append(&head,item);
        }
        struct Camiseta *n = head;
        while(n!=NULL){
            
            n = n->next;
        }
        //sortTamanho(&head);
        sortCor(&head);
        printList(&head);
    }

    return 0;
}



/*
void sortNome (struct Camiseta *aluno, int N){
    struct Camiseta temp;
    for (int i=0; i<N;i++){
        for (int j=0; j<(N-1);j++){
            if(strcmp(aluno[j].nome,aluno[j+1].nome)>0){
                temp = aluno[j];
                aluno[j] = aluno[j+1];
                aluno[j+1] = temp;
            }
        }
    }
}
void sortTamanho (struct Camiseta *aluno, int N){
    struct Camiseta temp;
    for (int i=0; i<N;i++){
        for (int j=0; j<(N-1);j++){
            if(aluno[j].tamanho<aluno[j+1].tamanho){
                temp = aluno[j];
                aluno[j] = aluno[j+1];
                aluno[j+1] = temp;
            }
        }
    }
}

*/

