#include <stdio.h>
#include <string.h>

int n;
void resultado(void);

void resultado(void){
    int len;
    char texto[1001];
    char temp;
    fgets(texto,1001,stdin);
    len = strlen(texto);
    texto[len-1]='\0';
    for (int i=0;i<len;i++){
        if(texto[i]>='A' && texto[i]<='Z' || texto[i]>='a' && texto[i]<='z'){
            texto[i]=texto[i]+3;
        }
    }
    for(int j=0; j<(len/2);j++){
        temp=texto[j];
        texto[j]=texto[len-1-j];
        texto[len-1-j]=temp;
    }
    for(int k=((len+1)/2); k<len;k++){
        texto[k]=texto[k]-1;
    }
    printf("%s\n", texto);
}
int main(){
    scanf("%d\n", &n);
    for (int i=0;i<n;i++){
        resultado();
    }
    return 0;
}