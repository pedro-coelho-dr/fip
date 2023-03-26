#include <stdio.h>
#include <string.h>

struct Camiseta {
    char nome[50];
    char cor[10];
    char tamanho;
};

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
void sortCor (struct Camiseta *aluno, int N){
    struct Camiseta temp;
    for (int i=0; i<N;i++){
        for (int j=0; j<(N-1);j++){
            if(strcmp(aluno[j].cor,aluno[j+1].cor)>0){
                temp = aluno[j];
                aluno[j] = aluno[j+1];
                aluno[j+1] = temp;
            }
        }
    }

}

int main() {
    int N, control;
    struct Camiseta aluno[60];
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
            fgets((aluno[i].nome),50,stdin);
            aluno[i].nome[strcspn(aluno[i].nome, "\n")] = 0;
            scanf("%s %c\n", &(aluno[i].cor), &(aluno[i].tamanho));
        }

        sortNome(aluno,N);
        sortTamanho(aluno,N);
        sortCor(aluno,N);

        for (int i = 0; i < N; i++)
        {
            printf("%s %c %s\n", aluno[i].cor, aluno[i].tamanho, aluno[i].nome);
        }
    }

    return 0;
}