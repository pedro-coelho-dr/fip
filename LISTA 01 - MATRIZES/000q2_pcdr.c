#include <stdio.h>
 
int main() {
 
    int P, N, c=1, j=0;
    scanf("%d %d", &P, &N);

    int array[N];
    for (int i=0; i<N; i++){
        scanf("%d", &array[i]);
    }

    while (c==1 && j<(N-1)){
        if ((array[j]+P)<array[j+1] || (array[j]-P)>array[j+1]){
            c=0;
        }
        j++;
    }
    if (c==1){
        printf("YOU WIN\n");
    }else if (c==0){
        printf("GAME OVER\n");
    }
    return 0;
}