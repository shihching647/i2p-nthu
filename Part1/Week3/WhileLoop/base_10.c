/* 
輸入: 13579
輸出: The number 13579 can be expressed as
     9 + 7*10+ 5*100 + 3*1000 + 1*10000.
*/
#include <stdio.h>
int main(void)
{
    int i, k;
    scanf("%d", &i);
    printf("The number %d can be expressed as\n", i);
    k = 1;
    
    while (i > 0) {
        printf("%d*%d + ", i % 10 , k);
        i = i / 10;
        k = k * 10;
    }
    printf("\b\b\b.  \n");
    
    return 0;
}
