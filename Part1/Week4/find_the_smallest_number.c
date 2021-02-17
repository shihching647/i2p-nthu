/*
Find the smallest N that satisfies
    N % x == a
    N % y == b
    N % z == c
For example,
if x=3, y=5, z=7, and a=2, b=3, c=4,
then, N is 53 since
    53 % 3 == 2
    53 % 5 == 3
    53 % 7 == 4
and 53<=3*5*7.

Another test case:
Input:
23 29 37
10 20 30
Output:
14201
 */

#include <stdio.h>

int main(void){
    int x, y, z, a, b, c;
    
    scanf("%d%d%d%d%d%d", &x, &y, &z, &a, &b, &c);
    for (int n = 1; n <= x * y * z; n++) {
        if (n % x == a && n % y == b && n % z == c) {
            printf("%d\n", n);
            break;
        }
    }
    return 0;
}


