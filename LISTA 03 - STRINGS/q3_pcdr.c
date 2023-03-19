#include <stdio.h>
#include <string.h>

int n, k, control;
char idioma[21];

int main(){
    scanf("%d", &n);
    for (int i=0; i<n;i++){
        control=0;
        scanf("%d", &k);
        char lista[k][21];
        for (int j=0; j<k;j++){
            scanf("%s", lista[j]);
        }
        for(int l=0;l<k;l++){
            if (strcmp(lista[0],lista[l])!= 0){
                control=1;
            }
        }
        if (control==1){
            printf("ingles\n");
        }else{
            printf("%s\n",lista[0]);
        }
    }
}