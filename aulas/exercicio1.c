#include <stdio.h>

int main(){
    int x, y, sum=0;

    scanf("%i", &x);
    scanf("%i", &y);

    if (x>y){
        for (int i=(x-1); i>y; i--){
            if (i%2!=0){
                sum+=i;
            }
    }
    }else if(y>x){
        for (int i=(y-1); i>x; i--){
            if (i%2!=0){
                sum+=i;
            }
        }
    }else{
        sum=0;
    }

    printf("%i\n", sum);
    return 0;
    
}