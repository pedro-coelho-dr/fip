#include <stdio.h>

int r(int x, int y);
int b(int x, int y);
int c(int x, int y);

int main() {
    int x, y, n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &x, &y);
        if(r(x,y)>b(x,y) && r(x,y)>c(x,y)){
            printf("Rafael ganhou\n");
        }else if(b(x,y)>r(x,y) && b(x,y)>c(x,y)){
            printf("Beto ganhou\n");
        }else if(c(x,y)>r(x,y) && c(x,y)>b(x,y)){
            printf("Carlos ganhou\n");
        }
    }
}

int r(x,y){
    int r =((3*x)*(3*x))+(y*y);
    return r;
}
int b(x,y){
    int b =(2*(x*x))+((5*y)*(5*y));
    return b;
}
int c(x, y){
    int c =(-100*x)+(y*y*y);
    return c;
}