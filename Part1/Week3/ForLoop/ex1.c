/*
 * 用 for 迴圈計算 0 到 100 之間，奇數數字的平方和。
*/

#include <stdio.h>

int main(void) {
    int sum = 0;
    for(int i = 1; i <= 100; i += 2) {
        sum += i * i;
    }
    printf("%d\n", sum);
    return 0;
}
