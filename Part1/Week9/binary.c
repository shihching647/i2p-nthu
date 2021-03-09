/**
 10進位轉2進位兩種方法
 1.遞迴方法
 2.迴圈方法
 ex:
 10 = (5 * 2) + 0 = ((2 * 2 + 1) * 2) + 0 = (((1 * 2 + 0) * 2 + 1) * 2) + 0
   = 1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0
 */
#include <stdio.h>

void bin_recursion(int n);
void bin_while(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("二進位表示：\n");
    bin_recursion(n);
    printf("\n");
    bin_while(n);
    printf("\n");
}


void bin_recursion(int n) {
    if (n <= 0) { //商為0時停止
        return;
    } else {
        bin_recursion(n / 2);
        printf("%d", n % 2);
    }
}

void bin_while(int n) {
    char result[32]; //最大32位
    int i = 0;
    while(n >= 1) {
        result[i++] = n % 2;
        n /= 2;
    }
    //印出結果
    while (i > 0) {
        printf("%d", result[--i]);
    }
}
