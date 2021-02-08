/**
*練習：自己用 getchar() putchar() 寫出 scanf %d 和 printf %d
**/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    int x;
    char ch;
    char digits[20];
    int i = 0;

    //讀取數字轉換成int (此時 x = 1234)
    while ((ch = getchar()) != EOF && isdigit(ch)) {
        x = x * 10 + (ch - '0');
    }

    //將數字轉成digits array, 此時 digits = {4, 3, 2, 1}
    while (x > 0) {
        digits[i] = x % 10;
        x = x / 10;
        i++;
    }
    //此時 i = 4
    i--;
    while (i >= 0) {
        putchar(digits[i] + '0');
        putchar('_');
        i--;
    }
    return 0;
}
