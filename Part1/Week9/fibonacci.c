/**
 Fibonacci number
 */
#include <stdio.h>

int fib(int n);
int fib_tail(int n, int fp, int fc);

int main() {
    int n;
    scanf("%d", &n);
    printf("fib(%d) = %d\n", n, fib(n));
    printf("fib(%d) = %d\n", n, fib_tail(n, 0, 1));
    return 0;
}

int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else return fib(n - 1) + fib(n - 2);
}

int fib_tail(int n, int fp, int fc) {
    if (n == 0) //只有在呼叫f(0,0,1)時才會進入此條件
        return fp;
    else if (n == 1)
        return fc;
    else return fib_tail(n - 1, fc, fp + fc);
}

