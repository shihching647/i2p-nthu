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
        for(int i = 0; i <= diff; i++){
	    for(j = 1; j <= diff - i; j++) {
	        printf(" ");
	    }
	    for(k = 'A'; k < 'A' + i; k++) {
		printf("%s", &k);
	    }
	    for(k - 1; k > 'A'; k--) {
	    	printf("%s", &k);
	    }
	    for(j - 1; j >= 0; j--) {
		 printf(" ");
	    }
	    printf("\n");
	}
    }
    return 0;
}
