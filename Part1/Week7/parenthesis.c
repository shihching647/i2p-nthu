#include <stdio.h>

int show_parenthesis(int);

int main() {
    int n;
    scanf("%d", &n);
    int total = show_parenthesis(n);
    printf(" = %d", total);
    return 0;
}

int show_parenthesis(int n) {
    if (n <= 1) {
        printf("%d", n);
        return n;
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

