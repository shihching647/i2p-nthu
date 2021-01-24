//
//  ex4.c
//  i2p-nthu
//
//  Created by 劉仕卿 on 2021/1/3.
//

#include <stdio.h>

int main(void) {
    int allowance;
    printf("Please enter weekly allowance? $");
    scanf("%d", &allowance);
    int week = allowance / 8;
    int weekend = (allowance / 8) * 1.5;
    printf("Mon: $%d, Tues: $%d, Wed: $%d, Thu: $%d, Fri: $%d, Sat: $%d, Sun: $%d\n",
           week, week, week, week, week, weekend, weekend);
    return 0;
}
