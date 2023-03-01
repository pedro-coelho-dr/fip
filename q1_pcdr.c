#include <stdio.h>
 
int main() {
    int G, A, M, C;
    
    // G (graduações) -> 1 até G =<600
    // A (atividades) -> 1 até A
    // M (total de tipos de material) -> 1 até M =< 2000
    // C (número de campi) -> 1 até C =< 100
    // 1 linha -> G A M C
    // 1 matrix -> gxa
    // 2 matrix -> axm
    // 3 matrix -> mxc

    scanf("%d %d %d %d/n", &G, &A, &M, &C);

    int tabela1[G][A];
    int tabela2[A][M];
    int tabela3[M][C];
    int tabela4[G][C];
    int tabela12[G][M];
    int tabela123[G][C];

    //tabela1
    for(int g=0; g<G; g++) {
        for (int a=0; a<A;a++){
            scanf("%d",&tabela1[g][a]);
        }
    }


    // tabela2
    for(int a=0; a<A; a++) {
        for (int m=0; m<M;m++){
            scanf("%d",&tabela2[a][m]);
        }
    }

    // tabela3
    for(int m=0; m<M; m++) {
        for (int c=0; c<C;c++){
            scanf("%d",&tabela3[m][c]);
        }
    }
    // tabela12 = tabela1*2
    for(int i=0; i<G;i++){
        for(int j=0; j<M;j++){
            tabela12[i][j]=0;
            for (int k = 0; k<A; k++){
                tabela12[i][j] += tabela1[i][k]*tabela2[k][j];
            }
        }
    }
    // tabela123=tabela12*tabela3
    for(int i=0; i<G;i++){
        for(int j=0; j<C;j++){
            tabela123[i][j]=0;
            for (int k = 0; k<M; k++){
                tabela123[i][j] += tabela12[i][k]*tabela3[k][j];
            }
        }
    }

    // acha o maior número da coluna

    int maior=0;
    int maiores[G];
        for (int i=0; i<G;i++){
            for (int j=0; j<C; j++){
                if (tabela123[j][i]>maior){
                    maior=tabela123[j][i];
                }
            }
            maiores[i]=maior;
            maior=0;
        }

    //contar os digitos dos maiores número.

    int digitos[G];
    int contador=0;
        for (int i=0;i<G;i++){
            do {
                maiores[i]/=10;
                contador++;
            } while (maiores[i] != 0);
            digitos[i]=contador;
            contador=0;
        }

    // print tabela123
    for(int i=0; i<G;i++){
        for(int j=0; j<C;j++){
            if (j==(C-1) && i!=(G-1)){
                printf("%*d\n", digitos[j], tabela123[i][j]);
            }else if(j==(C-1) && i==(G-1)){
                printf("%*d", digitos[j], tabela123[i][j]);
            }else{
                printf("%*d ", digitos[j], tabela123[i][j]);
            }
        }
    }
    return 0;
}