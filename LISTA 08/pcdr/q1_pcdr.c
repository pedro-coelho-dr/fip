#include <stdio.h>

int num_calls, result;
int fib(int x){
    if (x>1){
        num_calls++;
        return fib(x-1)+fib(x-2);
    }
    else{
        if(x==0){
            num_calls++;
            return 0;
        }else{
            num_calls++;
            result++;
            return 1;
        }
    }
}

int main(){
    int n, x;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        num_calls = 0;
        result = 0;
        scanf("%d", &x);
        fib(x);
        printf("fib(%d) = %d calls = %d\n", x, num_calls-1, result);
    }

    return 0;
}