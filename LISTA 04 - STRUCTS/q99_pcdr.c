#include <stdio.h>

struct Circle {
    int r;
    int x;
    int y;
};

int main() {
    struct Circle hunter;
    struct Circle flower;
        while (scanf("%d %d %d %d %d %d", &hunter.r, &hunter.x, &hunter.y, &flower.r, &flower.x, &flower.y)!=EOF){
            if (hunter.x>flower.x){
                if (hunter.y>flower.y){
                    if (hunter.x-hunter.r<=flower.x-flower.r&&hunter.y-hunter.r<=flower.y-flower.r){
                        printf("RICO\n");
                    }else{
                        printf("MORTO\n");
                    }
                }else{
                    if (hunter.x-hunter.r<=flower.x-flower.r&&hunter.y+hunter.r>=flower.y+flower.r){
                        printf("RICO\n");
                    }else{
                        printf("MORTO\n");
                    }
                }
            }else{
                if (hunter.y>flower.y){
                    if (hunter.x+hunter.r>=flower.x+flower.r&&hunter.y-hunter.r<=flower.y-flower.r){
                        printf("RICO\n");
                    }else{
                        printf("MORTO\n");
                    }
                }else{
                    if (hunter.x+hunter.r>=flower.x-flower.r&&hunter.y+hunter.r>=flower.y+flower.r){
                        printf("RICO\n");
                    }else{
                        printf("MORTO\n");
                    }
                }
            }
        }
    return 0;
}