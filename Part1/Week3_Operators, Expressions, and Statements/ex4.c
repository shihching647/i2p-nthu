//
//  ex4.c
//  i2p-nthu
//  讓使用者輸入兩個大寫英文字母，然後程式必須輸出字母順序介於兩者之間的其他字母。
//  Created by 劉仕卿 on 2021/1/17.
//

#include <stdio.h>

int main(void) {
    char upper, lower;
    scanf("%c %c", &upper, &lower);
    if(upper >= 'A' && upper <= 'Z' && lower >= 'A' && lower <= 'Z') {
        if(upper < lower) {
            char temp = lower;
            lower = upper;
            upper= temp;
        }
        while(lower < upper - 1) {
            printf("%c\n", ++lower);
        }
    } else {
        printf("請兩個輸入A~Z中間的字母\n");
    }
    return 0;
}
