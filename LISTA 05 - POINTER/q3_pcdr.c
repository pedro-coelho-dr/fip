#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
    char ch;
    int start_len=100;
    int current_len=0;
    char *lista1 = (char*) malloc(start_len*sizeof(char)); 
    char *lista2 = (char*) malloc(start_len*sizeof(char));
    int count1=1;
    int count2=1;
    int i;
    int j;
    char amigo[30];
// lista 1
    i=0;
    while((ch = getchar()) != '\n'){
        if(i==current_len){
            current_len=i+start_len;
            lista1 = (char*)realloc(lista1,current_len); 
        }
        lista1[i]=ch;
        i++;
    }
    lista1[i]='\0';
    current_len=0;
// lista2
    i=0;
    while((ch = getchar()) != '\n'){
        if(i==current_len){
            current_len=i+start_len;
            lista2 = (char*)realloc(lista2,current_len); 
        }
        lista2[i]=ch;
        i++;
    }
    lista2[i]='\0';

// count1
    j=0;
    while (lista1[j]!='\0'){
        if(lista1[j]==' '){
            count1++;
        }
        j++;
    }

// nome do amigo
    scanf("%s", amigo);
// matrix das listas por palavra
    char *matrix1[count1];
    char *palavra = strtok(lista1, " ");
    int k = 0;
    while (palavra!=NULL){
        matrix1[k++] = palavra;
        palavra = strtok(NULL, " ");
    }
// printar
    if (strcmp("nao",amigo)==0){
        for (int i=0;i<(count1);i++){
            printf("%s ", matrix1[i]);
        }
        printf("%s",lista2);
    }else{
        for(int i=0;i<(count1);i++){
            if(strcmp(matrix1[i],amigo)!=0){
                
                if (i==(count1-1)){
                    printf("%s", matrix1[i]);
                }else{
                    printf("%s ", matrix1[i]);
                }
            }else if(strcmp(matrix1[i],amigo)==0){
                if (i==(count1-1)){
                    printf("%s %s",lista2, matrix1[i]);
                }else{
                    printf("%s %s ",lista2, matrix1[i]);
                }
            }
    }
    }
    printf("\n");
    free(lista1);
    free(lista2);
    return 0;
}