/**
*�m�ߡG�ۤv�� getchar() putchar() �g�X scanf %d �M printf %d
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

    //Ū���Ʀr�ഫ��int (���� x = 1234)
    while ((ch = getchar()) != EOF && isdigit(ch)) {
        x = x * 10 + (ch - '0');
    }

    //�N�Ʀr�নdigits array, ���� digits = {4, 3, 2, 1}
    while (x > 0) {
        digits[i] = x % 10;
        x = x / 10;
        i++;
    }
    //���� i = 4
    i--;
    while (i >= 0) {
        putchar(digits[i] + '0');
        putchar('_');
        i--;
    }
    return 0;
}
