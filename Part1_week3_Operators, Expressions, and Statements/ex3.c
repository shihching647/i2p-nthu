//
//  ex3.c
//  i2p-nthu
//  讓使用者輸入一個十進位的數字，程式必須印出該數字的二進位表示法。
//  Created by 劉仕卿 on 2021/1/17.
//

#include <stdio.h>

int main(void) {
    int x;
    char result[32]; //最大32位
    int i = 0;
    scanf("%d", &x);
    while(x >= 1) {
        result[i++] = x % 2;
        x /= 2;
    }
    //印出結果
    while (i > 0) {
        printf("%d", result[--i]);
    }
    printf("\n");
    return 0;
}
