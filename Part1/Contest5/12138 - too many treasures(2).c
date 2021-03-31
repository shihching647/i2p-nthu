/**
   解法二:
   當讀到的數字開始變負的時候, sum[i] = sum[i - 1] (因為不會取負數)
 */
#include <stdio.h>
#define N_MAX (int)(1e6+1)
#define L long int

L sum[N_MAX];

int main(void) {
    freopen("12138_sampleIn.txt", "r", stdin);
    int n, q;
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        if (num > 0) sum[i] += sum[i - 1] + num;
        else sum[i] = sum[i - 1];
    }

    while(q--) {
        int l, r, m;
        scanf("%d%d%d", &l, &r, &m);
        r = l + m - 1;
        printf("%ld\n", sum[r] - sum[l - 1]);
    }
    return 0;
}
