/**
 You will have a integer n.

 Your goal is to print two composite number a, b that a-b = n.

 Note that a,b needs to be none-zero positive number and 1 <= a, b <= 10^18.
 */

//直接用 9*n - 8*n = n 就可以了, 因為9n和8n必為合數
#include <stdio.h>

int main() {
    long n;
    scanf("%ld", &n);
    printf("%ld %ld\n", 9 * n, 8 * n);
    return 0;
}
/**
 下面是錯的解法, 因為若是遇到1,3...會錯！！
 */
//#include <stdio.h>
//#include <limits.h>
//
//int is_composite_number(long);
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    //最小的合數為4
//    for (long i = 4; i < LONG_MAX; i++) {
//        if (is_composite_number(i) && is_composite_number(i + n)) {
//            printf("%ld %ld\n", i + n, i);
//            break;
//        }
//    }
//}
//
//int is_composite_number(long num) {
//    //從2開始除,檢查餘數是否為0
//    for (long i = 2; i < LONG_MAX; i++) {
//        if (num % i == 0) return 1;
//    }
//    return 0;
//}
