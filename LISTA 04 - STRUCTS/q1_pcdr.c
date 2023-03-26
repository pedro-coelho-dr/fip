#include <stdio.h>
#include <math.h>

struct Circle {
    int r;
    int x;
    int y;
};

float dist;

int main() {
    struct Circle hunter;
    struct Circle flower;
        while (scanf("%d %d %d %d %d %d", &hunter.r, &hunter.x, &hunter.y, &flower.r, &flower.x, &flower.y)!=EOF){
            dist=sqrt(pow((hunter.x-flower.x), 2)+pow((hunter.y-flower.y),2));
            if (dist + flower.r <= hunter.r){
                printf("RICO\n");
            }else{
                printf("MORTO\n");
            }
        }
    return 0;
}