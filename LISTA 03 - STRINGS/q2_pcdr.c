#include <stdio.h>
#include <string.h>

int n;
void resultado(void);

void resultado(void){
    int len,maior;
    char frase[201];
    int contagem[200];
    char final[201];
    char temp;
    int ind;
    fgets(frase,201,stdin);
    len = strlen(frase);
    for (int j=0;j<len;j++){
        contagem[j]=0;
        if(frase[j] >='A' && frase[j]<='Z'){
            frase[j]=frase[j]+32;
        }
        for (int k=0;k<=j;k++){
            if(frase[j]==frase[k]){
                contagem[j]++;
            }
        }
    }
    maior=0;
    for (int j=0;j<len;j++){
        if (frase[j]>='a' && frase[j]<='z' && contagem[j]>maior){
            maior=contagem[j];
        }
    }
    ind=0;
    for(int j=0; j<len;j++){
        if(frase[j]>='a' && frase[j]<='z' && contagem[j]==maior){
            final[ind]=frase[j];
            ind++;
        }
    }
    final[ind]='\0';
    for(int j=0; j<strlen(final);j++){
        for (int k=j; k<strlen(final);k++){
            if (final[j]>final[k]){
                temp = final[k];
                final[k] = final[j];
                final[j] = temp;
            }
        }
    }
    printf("%s\n", final);
}

int main(){
    scanf("%d\n", &n);
    for (int i=0;i<n;i++){
        resultado();
    }
    return 0;
}