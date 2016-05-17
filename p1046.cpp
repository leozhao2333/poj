#include <cstdio>
#include <cstdlib>

int target[20][3];

int main(void){
    int i,j;
    int minlen, min;
    int len;
    int x, y, z;

    for (i = 0; i < 16; i++){
        scanf("%d%d%d", &target[i][0], &target[i][1], &target[i][2]);
    }
    while (scanf("%d%d%d", &x, &y, &z), x != -1 && y != -1 && z != -1){
        min = -1;
        minlen = 1000000;
        for (i = 0; i < 16; i++){
            len = (target[i][0] - x) * (target[i][0] - x) + (target[i][1] - y) * (target[i][1] - y) + (target[i][2] - z) * (target[i][2] - z);
            if (len < minlen){
                min = i;
                minlen = len;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", x, y, z, target[min][0], target[min][1], target[min][2]);
    }
    return 0;
}

