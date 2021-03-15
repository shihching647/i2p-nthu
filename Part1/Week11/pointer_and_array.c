/**
 Pointer and array
 */

#include <stdio.h>

//function參數也可這樣宣告(是int p[], 不是int[] p)
//int sum(int p[], int n) {
int sum(int* p, int n) {
    int sum = 0;
    //寫法1
    for (int i = 0; i < n; i++) {
        sum += p[i];
    }
    //寫法2
    for (int i = 0; i < n; i++, p++) { //p為指標變數,可以改變裡面的值
        sum += *p;
    }
    return sum;
}

//p為開始位置, q為終點位置的下一個
int sum2(int* p, int* q) {
    int sum = 0;
    while (p < q) {
        sum += *p++;
    }
    return sum;
}

int main(void) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //不可使用 a++, a就代表第一個值的記憶體位置,並非指標變數
    printf("%d\n", sum(a, 10));
    printf("%d\n", sum2(a, a + 10));
    printf("%p %p\n", &a[1], a + 1); //兩者是等價的
    printf("%d %d\n", a[1], *(a + 1)); //兩者是等價的
    printf("%d %d\n", a[2], 2[a]); //兩者是等價的
    return 0;
}
