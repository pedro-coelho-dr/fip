#include <stdio.h>
int main() {
    int item, qtd;
    float valor;

    scanf("%i", &item);
    scanf("%i", &qtd);
    
    if (item==1){
        valor = qtd*4.0;
        printf("Total: R$ %.2f", valor);
    }else if (item==2){
        valor = qtd*4.5;
        printf("Total: R$ %.2f", valor);
    }else if (item==3){
        valor = qtd*5.0;
        printf("Total: R$ %.2f", valor);
    }else if (item==4){
        valor = qtd*2.0;
        printf("Total: R$ %.2f", valor);
    }else if (item==5){
        valor = qtd*1.5;
        printf("Total: R$ %.2f", valor);
    }else{
        printf("Opção inválida");
    }
    return 0;
}