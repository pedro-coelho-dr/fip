#include <stdio.h>
int main() {
    int maior=0;
    int contador=0;
    int G, A, M, C;
    scanf("%d%d%d%d", &G, &A, &M, &C);
    int tabela1[G][A];
    int tabela2[A][M];
    int tabela3[M][C];
    int tabela4[G][C];
    int tabela12[G][M];
    int tabela123[G][C];
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
    for (int i=0; i<G;i++){
        for (int j=0; j<C; j++){
            if (tabela123[j][i]>maior){
                maior=tabela123[j][i];
            }
        }
        maiores[i]=maior;
        maior=0;
    }
    for (int i=0;i<G;i++){
        do {
            maiores[i]/=10;
            contador++;
        } while (maiores[i] != 0);
        digitos[i]=contador;
        contador=0;
    }
    for(int i=0; i<G;i++){
        for(int j=0; j<C;j++){
            printf("%*d", digitos[j], tabela123[i][j]);
            if(j!=(C-1)){
                printf(" ");
            }
        }
    printf("\n");
    }
    return 0;
}