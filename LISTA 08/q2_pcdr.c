#include <stdio.h>


unsigned long long hanoi(unsigned long long n) {
    if (n == 1) {
        return 1;
    }else{
        return 2 * hanoi(n - 1) + 1;
    }
}

int main() {
    unsigned long long n;
    scanf("%d", &n);
    printf("O número mínimo de movimentos é: %llu\n", hanoi(n));
    return 0;
}