#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoSacola {    
    int elementoFila[1000];    
    int comecoFila, finalFila;  

    int elementoPilha[1000];    
    int indicePilha;
    
    int elementoListaPrioridade[1000];    
    int indiceListaPrioridade;
    } tipoSacola;

void pushFila (int valor, tipoSacola *dado) {    
    dado->elementoFila[dado->finalFila++] = valor;
}

int popFila (tipoSacola*dado) {
    if (dado->comecoFila == dado->finalFila) {        
        return 1;    
        }
    return dado->elementoFila[dado->comecoFila++];
}

void pushPilha (int valor, tipoSacola *dado){    
    dado->elementoPilha[++dado->indicePilha] = valor;
}

int popPilha (tipoSacola *dado){
    if (dado->indicePilha <= 0) {
            return  1;    
    }
    return dado->elementoPilha[dado->indicePilha--];
}

void pushListaPrioridade (int valor, tipoSacola *dado){
     int aux;
    aux = ++dado->indiceListaPrioridade;
    while (aux > 1) {
        if (dado->elementoListaPrioridade[aux/2] < valor) {
            dado->elementoListaPrioridade[aux] = dado->elementoListaPrioridade[aux/2];
            aux=aux/2;
        } 
        else{
            break;
        }
    }
    dado->elementoListaPrioridade[aux] = valor;
}

int popListaPrioridade (tipoSacola *dado) {
    int temp, atual, next;
    if (dado->indiceListaPrioridade <= 0) {
        return 1;
    }
    temp = dado->elementoListaPrioridade[1];
    atual = 1;
    next = 2;
    dado->indiceListaPrioridade--;
    while (next <= dado->indiceListaPrioridade) {
        if (next < dado->indiceListaPrioridade && dado->elementoListaPrioridade[next+1] > dado->elementoListaPrioridade[next]) {
            next++;
        }
        if(dado->elementoListaPrioridade[next] > dado->elementoListaPrioridade[dado->indiceListaPrioridade+1]) {
            dado->elementoListaPrioridade[atual] = dado->elementoListaPrioridade[next];
            atual = next;
            next = atual*2;
        } else
            break;
    }
    dado->elementoListaPrioridade[atual] = dado->elementoListaPrioridade[dado->indiceListaPrioridade+1];
    return temp;
}


int main () {
    int comando, valor;
    int n, i;
    int flag[3];
    int recebido;
    tipoSacola data;
    while (scanf ("%d", &n) != EOF) {
        memset (flag, 0, sizeof(flag));
        data.comecoFila = 0;
        data.finalFila = 0;
        data.indicePilha = 0;
        data.indiceListaPrioridade = 0;
        for (i=0; i<n; i++) {
            scanf("%d %d", &comando, &valor);

            if (comando == 1) {
            pushFila (valor, &data);
            pushPilha (valor, &data);
            pushListaPrioridade (valor, &data);
            }

            else {
                recebido = popFila (&data);

                if (recebido != valor) {
                    flag[0] = 1;
                }
                recebido = popPilha (&data);
                if (recebido != valor) {
                    flag[1] = 1;
                }
                recebido = popListaPrioridade (&data);
                    if (recebido != valor) {
                        flag[2] = 1;
                   }
            }
        }

        if (flag[0] + flag[1] + flag[2] == 3){
            printf ("impossible\n");
        }
        else if (flag[0] + flag[1] + flag[2] < 2){
                printf ("not sure\n");
        }
        else {
            if (!flag[0]){
                printf ("queue\n");  
            } 
            if (!flag[1]){
                printf ("stack\n");
            } 
            if (!flag[2]){
                printf ("priority queue\n");
            } 
        }
    }
 return 0;
}




            
        /*
        if ((boolFila==1 && boolPilha==1 && boolPriori==1) 
            || (boolFila==0 && boolPilha==1 && boolPriori==1) 
            || (boolFila==1 && boolPilha==0 && boolPriori==1) 
            || (boolFila==1 && boolPilha==1 && boolPriori==0)){
            printf("not sure\n");
        }else if(boolFila==1 && boolPilha==0 && boolPriori==0){
            printf("queue\n");
        }else if(boolFila==0 && boolPilha==1 && boolPriori==0){
            printf("stack\n");
        }else if(boolFila==0 && boolPilha==0 && boolPriori==1){
            printf("priority queue\n");
        }else{
            printf("impossible\n");
        }
        */
        /*
        if(boolFila==0 && boolPilha==0 && boolPriori==0){
            printf("impossible\n");
        }else if(boolPilha==1 && boolFila==1){
            printf("not sure\n");
        }else if(boolPilha==1 && boolPriori==1){
            printf("not sure\n");
        }else if(boolFila==1 && boolPriori==1){
            printf("not sure\n");
        }else if(boolPilha==1){
            printf("stack\n");
        }else if(boolFila==1){
            printf("queue\n");
        }else if(boolPriori==1){
            printf("priority queue\n");
        }

    */