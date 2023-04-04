#include <stdio.h>
#include <stdlib.h>

void sweeper(int **matrix, int n, int m){
    int counter;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (matrix[i][j] == 1) {
                printf("9");
            }else{
                counter=0;
                if(i!=0){
                    counter+=matrix[i-1][j];
                }
                if(j!=0){
                    counter+=matrix[i][j-1];
                }
                if(i!=n-1){
                    counter+=matrix[i+1][j];
                }
                if(j!=m-1){
                    counter+=matrix[i][j+1];
                }
                printf("%d", counter);
            } 
            }
            printf("\n");
        }
}
int main() {
    int n, m;
    while (scanf("%d %d",&n, &m)!=EOF){
        int **matrix = (int **)malloc(n*sizeof(int*));
        for(int i=0;i<m;i++){
            matrix[i] = (int *)malloc(m*sizeof(int));
        }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    sweeper(matrix,n,m);
   // if (n>1){
   //     for(int i=0; i<n; i++){
  //          free(matrix[i]);
  //      }
  //      free(matrix);
  //  }else{
  //      free(matrix[0]);
  //  }
    }
    return 0;
}