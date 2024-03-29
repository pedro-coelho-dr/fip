#include <stdio.h>
 
int main() {
    int G, A, M, C;
    
    scanf("%d %d %d %d", &G, &A, &M, &C);

    int tabela1[G][A];
    int tabela2[A][M];
    int tabela3[M][C];
    int tabela4[G][C];
    int tabela12[G][M];
    int tabela123[G][C];
    int maior;
    int maiores[G];
    int digitos[G];

    for(int g=0; g<G; g++) {
        for (int a=0; a<A;a++){
            scanf("%d",&tabela1[g][a]);
        }
    }

    for(int a=0; a<A; a++) {
        for (int m=0; m<M;m++){
            scanf("%d",&tabela2[a][m]);
        }
    }

    for(int m=0; m<M; m++) {
        for (int c=0; c<C;c++){
            scanf("%d",&tabela3[m][c]);
        }
    }

    for(int i=0; i<G;i++){
        for(int j=0; j<M;j++){
            tabela12[i][j]=0;
            for (int k = 0; k<A; k++){
                tabela12[i][j] += tabela1[i][k]*tabela2[k][j];
            }
        }
    }

    for(int i=0; i<G;i++){
        for(int j=0; j<C;j++){
            tabela123[i][j]=0;
            for (int k = 0; k<M; k++){
                tabela123[i][j] += tabela12[i][k]*tabela3[k][j];
            }
        }
    }

    for (int i=0; i<C;i++){
        maiores[i]=tabela123[0][i];
        for (int j=1; j<G; j++){
            if(tabela123[i][j]>maiores[i]){
                maiores[i]=tabela123[i][j];
            }
        }
        int contador=1;
        while (maiores[i] / 10 >0){
            contador++;
            maiores[i]=maiores[i]/10;
            }
        digitos[i]=contador;
    }

    for(int i=0; i<G;i++){
        for(int j=0; j<C;j++){
            printf("%*d", digitos[j], tabela123[i][j]);
            if(j != C-1){
                printf(" ");
            }
        }
    printf("\n");
    }
    return 0;
}