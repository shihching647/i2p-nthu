/*
You will have three number A, B, C each represents a+b, b+c, c+a respectively.

You need to answer what a, b, c are.
*/
#include <stdio.h>

int main(void)
{
    unsigned int a, b, c;
    scanf("%u%u%u", &a, &b, &c);
    printf("%d %d %d\n", (c - b + a) / 2, (a - c + b) / 2, (b - a + c) / 2);
    return 0;
}
