#include <stdio.h>

double power(double n, int p);

int main() {
    printf("2 ^ 10 = %0.f", power(2, 10));
}

/**
* if p is even -> power(n, p) = power(n, p/2) * power(n, p/2)
* if p is odd -> power(n, p) = n * power(n, p/2) * power(n, p/2) 因為無條件捨去
**/
double power(double n, int p) {
    if (p == 0) return 1;
    double ans = power(n, p / 2);
    if (p % 2 == 0)
        return ans * ans;
    else
        return n * ans * ans;
}
