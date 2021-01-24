//
//  main.c
//  i2p-nthu
//
//  Created by 劉仕卿 on 2021/1/3.
//

#include <stdio.h>

int main1(int argc, const char * argv[]) {
    float mon, tues, wend, thur, fri;
    float total;
    scanf("%f%f%f%f%f", &mon, &tues, &wend, &thur, &fri);
    total = mon + tues + wend + thur + fri;
    printf("Total = %.0f, average = %.2f\n", total, total / 5);
    return 0;
}
