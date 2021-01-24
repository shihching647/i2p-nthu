//
//  ex1.c
//  i2p-nthu
//  在螢幕上顯示一個簡單的對照表，列出數字 1 到 30 以及它們對應的平方值。
//  Created by 劉仕卿 on 2021/1/17.
//

#include <stdio.h>

int main3_1(void) {
    int i = 1;
    printf("number  squre\n");
    while(i <= 30) {
        printf("%4d   %5d\n", i, i * i);
        i++;
    }
    return 0;
}
