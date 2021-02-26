/**
用 recursive 方式，產生下面的輸出
Input: 10
Output: ((((1+2)*3+4)*5+6)*7+8)*9+10=4555
Input: 11
Output: (((((1+2)*3+4)*5+6)*7+8)*9+10)*11=50105
**/

#include <stdio.h>
int show_parenthesis(int n);

int main(void) {
    int n;
    scanf("%d", &n);
    int ans = show_parenthesis(n);
    printf(" = %d", ans);
    return 0;
}

int show_parenthesis(int n) {
    if (n <= 1) {
        printf("1");
        return 1;
    }
    if (n % 2 == 0) {
        int temp = show_parenthesis(n - 1);
        printf("+%d", n);
        return temp + n;
    } else {
        printf("(");
        int temp = show_parenthesis(n - 1);
        printf(")");
        printf("*%d", n);
        return temp * n;
    }
}
