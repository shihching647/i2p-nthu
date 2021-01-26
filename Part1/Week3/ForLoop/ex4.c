//利用雙重迴圈，輸出九九乘法表左上半部的內容。

#include <stdio.h>

int main(void) {
    for(int i = 1; i <= 9; i++) {
         for(int j = i; j <= 9; j++) {
             printf("%3d ", i * j);
         }
	printf("\n");
    } 
    return 0;
}
