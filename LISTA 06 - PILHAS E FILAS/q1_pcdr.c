#include <stdio.h>
#include <stdlib.h>
 
int main() {
 
    int n, x, y;
    while(scanf("%d", &n) != EOF){
        int boolPilha=1, boolFila=1, boolPriori=1;
        int array1[n];
        int array2[n];
        int j=0;
        int k=0;
        for (int i=0; i<n; i++){
            scanf("%d %d", &x, &y);
            if (x==1){
                array1[j]=y;
                j++;
            }else if(x==2){
                array2[k]=y;
                k++;
            }
        }
        // PILHA
        for (int i=0; i<k;i++){
            if (array1[j-1-i]!=array2[i]){
                boolPilha=0;
            }
        }
        // FILA
        for (int i=0; i<k;i++){
            if (array1[i]!=array2[i]){
                boolFila=0;
            }
        }
        // FILA PRIORITARIA
        int temp;
        for (int m=0;m<j;m++){
            for (int n=m+1;n<j;n++){
                if(array1[m]<array1[n]){
                    temp = array1[m];
                    array1[m]=array1[n];
                    array1[n]=temp;
                }
            }
        }
        for (int i=0; i<k; i++){
            if (array1[i]!=array2[i]){
                boolPriori=0;
            }
        }
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
    }

    return 0;
}