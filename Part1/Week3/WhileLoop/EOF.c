#include <stdio.h>

int main(void)
{
    int x;

    while (scanf("%d", &x) != EOF) { /*Ctrl Z + Enter */
        printf("x=%d\n", x);
        while (getchar() != '\n') {} //避免輸入非數字造成無窮迴圈
    }
    return 0;
}
