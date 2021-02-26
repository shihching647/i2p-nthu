#include <stdio.h>


double power(double n, int p);

int main() {
    double n;
    int p;
    printf("2 ^ 10 = %0.f", power(2,10));
}

/**
* if p is odd -> power(n, p) = power(n, p/2) * power(n, p/2) * n
* if p is even -> power(n, p) = power(n, p/2) * power(n, p/2)
**/
double power(double n, int p) {
    if (p == 0) return 1;
    else {
        double ans = power(n, p / 2);
        if (p % 2 == 0) return ans * ans;
        else return n * ans * ans;
    }
}
