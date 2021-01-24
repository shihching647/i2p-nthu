//
//  ex2.c
//  i2p-nthu
//  1.小明在銀行存入 10000 元，年利率 5%，總共存了十年，利息以複利計算。請依照年度列出小明每年能夠賺到的利息。
//  2.承上題，假設小明每過一年又會再存入 10000 元，請把新的獲利表列出來。
//  Created by 劉仕卿 on 2021/1/17.
//

#include <stdio.h>

int main3_2(void) {
    double p = 10000;
    int year = 0;
    printf("year      intrest\n");
    while(year < 10) {
        year++;
        p = p * 1.05;
        printf("%2d      %9.2f\n", year, p - 10000);
    }
    printf("---------------------\n");
    p = 10000;
    year = 0;
    printf("year      intrest\n");
    while(year < 10) {
        year++;
        p = p * 1.05;
        printf("%2d      %9.2f\n", year, p - 10000 * year);
        p += 10000;
    }
    return 0;
}
