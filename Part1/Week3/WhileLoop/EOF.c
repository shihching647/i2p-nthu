#include <stdio.h>

int main(void)
{
    int x;

    while (scanf("%d", &x) != EOF) { /*Ctrl Z + Enter */
        printf("x=%d\n", x);
        while (getchar() != '\n') {} //�קK��J�D�Ʀr�y���L�a�j��
    }
    return 0;
}
