#include <stdio.h>
int main() {
    int n, m, counter;
    while (scanf("%d %d",&n, &m)!=EOF){
        int matrix[n][m];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d", &matrix[i][j]);
        }
    }
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
    return 0;
}