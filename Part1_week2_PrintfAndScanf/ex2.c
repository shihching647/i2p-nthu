//
//  ex2.c
//  i2p-nthu
//
//  Created by 劉仕卿 on 2021/1/3.
//

#include <stdio.h>

int main2(void) {
    int ch;
    printf("Please enter a number in 0 ~ 127\n");
    scanf("%d", &ch);
    if(ch <= 127 && ch > 0)
        printf("%d is the ASCII code for %c\n", ch, ch);
    else
        printf("%d is not in the range 0 ~ 127.\n", ch);
    return 0;
}
