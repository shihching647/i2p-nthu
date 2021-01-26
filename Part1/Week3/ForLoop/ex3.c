//利用雙重迴圈，輸出九九乘法表的內容。

#include <stdio.h>

int main(void) {
    for(int i = 1; i <= 9; i++) {
         for(int j = 1; j <= 9; j++) {
             printf("%d * %d = %d  ", i, j, i * j);
         }
	printf("\n");
    } 
    return 0;
}
