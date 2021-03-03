/**
  求gcd
  (此種遞迴為tail recursion, 遞迴完的結果直接回傳, 不作其他處理, 較不會發生stack overflow)
 */
#include <stdio.h>

int gcd (int a, int b) {
    if (b == 0)return a;
    /* 也可用
     if (a % b == 0) return b;
     */
    printf("a=%d, b=%d\n", a, b);
    return gcd(b, a % b);
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("The gcd = %d\n", gcd(a, b));
}
