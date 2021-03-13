/**
 Binary Search
 */

#include <stdio.h>
#define N 10000000

int data[N];
int binarySearch(int x, int l, int r);

int main() {
    //initial
    for (int i = 0; i < N; i++) {
        data[i] = i * 2 + 1;
    }

    //Binary search
    int x;
    scanf("%d", &x);
    if (binarySearch(x, 0, N - 1)) {
        printf("%d is found!\n", x);
    } else {
        printf("%d is not found!\n", x);
    }
}

int binarySearch(int x, int l, int r) {
    if (l > r) //沒找到
        return 0;
    int mid = l + (r - l) / 2; //若l, r很大時, 才不會over flow
//    printf("current %d\n", data[mid]);
    if (x < data[mid])
        return binarySearch(x, l, mid - 1); //搜尋左半邊
    else if (x > data[mid])
        return binarySearch(x, mid + 1, r); //搜尋右半邊
    else
        return 1; //found
}
