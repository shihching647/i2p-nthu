/* 
使用者輸入想要顯示的長方形的高度和寬度
輸出一個由 * 構成且符合使用者輸入之大小的長方形
可以使用額外的變數 k
也可以只用到 i 和 j (利用 % 符號做求餘數的運算)
把下面程式碼 ??? 填入正確的運算式
讓程式可以達到預期的效果
*/

#include <stdio.h>
int main(void)
{
    int i, j, k; 
    scanf("%d%d", &i, &j);
    k = j; 
    for(i; i > 0; i--) {  
	for (j = k; j > 0; j--) { 
            printf("*");
        }
        printf("\n");
    }      
    return 0;
}

