//讓使用者輸入一個大寫英文字母，譬如 'E'，然後輸出像範例輸出一樣排列的形狀。

/*

    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA

*/


#include <stdio.h>

int main(void) {
    char ch;
    scanf("%c", &ch);
    int diff = ch - 'A';
    char k;
    int j;

    if(ch >= 'A' || ch <= 'Z') {
        //下面以第2列當作例子
        for(int i = 0; i <= diff; i++){
            //分三段印 -> 1.空白 2.AB 3.A
            for(j = 0; j <= diff - i; j++) {
                printf(" ");
            }
            for(k = 'A'; k <= 'A' + i; k++) {
                printf("%c", k);
            }
            //此時印到AB, 且k = 'C'
            for(k -= 2; k >= 'A' ; k--) {
                printf("%c", k);
            }
            printf("\n");
        }
    }
    return 0;
}
