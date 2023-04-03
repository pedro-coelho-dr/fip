#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    int n, count;
    char input[21000];

    scanf("%d\n",&n);
    for (int i=0;i<n;i++){
        fgets(input, 21000, stdin);
        input[strcspn(input, "\n")] = 0;
        count=1;
        int j=0;
        while (input[j]!='\n'){
            if(input[j]==' '){
                count++;
            }
            j++;
        }
        char *item[count];
        char *palavra = strtok(input, " ");
        int k = 0;
        while (palavra!=NULL){
            item[k++] = palavra;
            palavra = strtok(NULL, " ");
        }
        char *temp;
        for (int p=0; p<count; p++){
            for (int q=0; q<(count-1); q++){
                if(strcmp(item[q],item[q+1])>0){
                    temp = item[q];
                    item[q] = item[q+1];
                    item[q+1] = temp;
                }
            }
        }
        for (int l = 0; l < (count-1); l++){
            if(strcmp(item[l],item[l+1])!=0){
                printf("%s ", item[l]);
                }
            }
        printf("%s\n", item[count-1]);
        }

    return 0;
}