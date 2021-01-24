//
//  12134 - The Big Hammer Rise.c
//  i2p-nthu
//
//  Created by 劉仕卿 on 2021/1/3.
//

#include <stdio.h>

int main_c1(void) {
    int integer1, decimal1, integer2, decimal2;
    scanf("%d.%d %d.%d", &integer1, &decimal1, &integer2, &decimal2);
    int ans = (integer1 * 100 + decimal1) * (integer2 * 100 + decimal2); //小數最多兩位->*100轉成整數
    printf("%d.%04d\n", ans / 10000, ans % 10000); //10000以前是整數部分, 10000以後是小數部分, 最多8位,對int來說不會overflow
    return 0;
}
