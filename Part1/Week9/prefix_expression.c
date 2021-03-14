/**
 prefix expression to infix expression
 prefix expression  : * + 2 3 + 4 + - 5 6 - 7 8
 infix expression : (2+3)*(4+((5-6)+(7-8)))
 */

#include <stdio.h>
#include <ctype.h>

int calculate(void);

int main(void) {
    printf(" = %d\n", calculate());
    return 0;
}

int calculate() {
    int c;
    int ans = 0;
    int op1, op2;
    
    c = getchar();
    if (isspace(c)) {
        ans = calculate();
    } else if (isdigit(c)) {
        ungetc(c, stdin);
        scanf("%d", &ans);
        printf("%d", ans);
    } else {
        if (c == '+') {
            printf("(");
            op1 = calculate();
            printf("+");
            op2 = calculate();
            printf(")");
            ans = op1 + op2;
        } else if (c == '-') {
            printf("(");
            op1 = calculate();
            printf("-");
            op2 = calculate();
            printf(")");
            ans = op1 - op2;
        } else if (c == '*') {
            op1 = calculate();
            printf("*");
            op2 = calculate();
            ans = op1 * op2;
        }
    }
    return ans;
}
