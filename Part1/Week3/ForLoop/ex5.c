//利用雙重迴圈，輸出下列範例輸出的內容。

#include <stdio.h>

int main(void) {
    for(int i = 1; i <= 7; i++) {
        for(int j = 1; j <= 7; j++) {
            if(j < i) printf(" ");
	    else printf("*");
        }
	printf("\n");
    }
    return 0;
}
