//
//  example4.c
//  i2p-nthu
//
//  Created by 劉仕卿 on 2021/1/16.
//

#include <stdio.h>

int main(void) {
    int x;
    printf("Please enter three integers:\n");
    scanf("%*d %*d %d", &x); //%*d -> 忽略被輸入的整數
    printf("Only the last one is stored: %d\n", x);
    return 0 ;
}
