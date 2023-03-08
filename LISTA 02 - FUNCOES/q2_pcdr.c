#include <stdio.h>

float media(int s, int n);
float acimadamedia(int count, int n);

int main(){
    int c, n, nota, s, count;
    scanf("%d", &c);
    for(int i=0;i<c;i++){
        s=0;
        count=0;
        scanf("%d", &n);
        int array[n];
        for(int j=0;j<n;j++){
            scanf("%d", &nota);
            array[j]=nota;
            s+=nota;
        }
        for (int k=0;k<n;k++){
            if ((float)array[k]>media(s,n)){
                count+=1;
            }
        }
        printf("%.3f%\n", acimadamedia(count,n));
    }
}

float media(s,n){
    float m =(float)s/n;
    return m;
}

float acimadamedia(count,n){
    return (float)(count*100)/n;
}