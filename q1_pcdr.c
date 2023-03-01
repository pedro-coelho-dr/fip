#include <stdio.h>
 
int main() {
    int G, A, M, C;
    
    // G (graduações) -> 1 até G =<600
    // A (atividades) -> 1 até A
    // M (total de tipos de material) -> 1 até M =< 2000
    // C (número de campi) -> 1 até C =< 100
    // 1 linha -> G A M C
    // 1 matrix -> graduação X numero de atividades
    // 2 matrix -> atividaes x tipos de material
    // 3 matrix -> tipos de material x custo do material no campi

    scanf("%d %d %d %d/n", &G, &A, &M, &C);

    int tabela1[G][A];
    int tabela2[A][M];
    int tabela3[M][C];
    int tabela4[G][C];
    int tabela12[G][M];
    int tabela123[G][C];

//tabela 1
    for(int g=0; g<G; g++) {
        for (int a=0; a<A;a++){
            scanf("%d",&tabela1[g][a]);
        }
    }

// tabela2
    for(int a=0; a<A; a++) {
        for (int m=0; m<M;m++){
            scanf("%d",&tabela1[a][m]);
        }
    }

// tabela3
    for(int m=0; m<M; m++) {
        for (int c=0; c<C;c++){
            scanf("%d",&tabela1[m][c]);
        }
    }
// multiplicação da tabela 1 pela 2
    for(int i=0; i<G;i++){
        for(int j=0; j<M;j++){
            tabela12[i][j]=0;
            for (int k = 0; k<A; k++){
                tabela12[i][j] += tabela1[i][k]*tabela2[k][j];
            }
        }
    }
// multiplicação da tabela12 pela tabela 3
    for(int i=0; i<G;i++){
        for(int j=0; j<C;j++){
            tabela123[i][j]=0;
            for (int k = 0; k<M; k++){
                tabela123[i][j] += tabela12[i][k]*tabela3[k][j];
            }
        }
    }

// printar a tabela123
    for(int i=0; i<G;i++){
        for(int j=0; j<C;j++){
            printf("%d\t", tabela123[i][j]);
        }
        printf("\n");
    }
    return 0;
}