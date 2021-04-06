/**
與換零錢題目類似
*/
#include <stdio.h>

void count_permutation(int start, int end, int sum);
int a[20];
int count;

int main(void) {
    freopen("12137_sampleIn.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    count_permutation(0, n, k);
    printf("%d\n", count);
    return 0;
}

void count_permutation(int start, int end, int sum) {
    if (start <= end) {
        if (sum == 0) { //當sum = 0時, 即找到一個解
            count++;
            return;
        } else if (sum > 0) { //當sum > 0才需繼續
            int i = 0;
            for (i = start; i < end; i++) { //從start開始往後嘗試, 嘗試到n - 1
                count_permutation(i + 1, end, sum - a[i]);
            }
        }
    }
    return;
}
