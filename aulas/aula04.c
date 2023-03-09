#include <stdio.h>
#include <stdlib.h>
 
int maiorab(int a, int b);

int main() {
    int x, y, z, result;
    scanf("%d%d%d",&x,&y,&z);
    result = maiorab(x,y);
    result = maiorab(z, result);
    printf("%d eh o maior\n", result);
    return 0;
}

int maiorab(a,b) {
    return (a+b+abs(a-b))/2;
}