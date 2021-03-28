/**
 The treasure room has n treasure crates, each crate has its value.
 The values are sorted in descending order.
 1<=m<=n<=10^6, 1<=q<=10^6, 1<=l<=r<=n, m<=r-l+1
 the value of every treasure crate won't larger than 10^5 or smaller than -10^5

 共有10^5  個數字,  query共有10^5次 --> 使用prefix sum
 sum in 10^11 --> sum[]型別要開long
 */
#include <stdio.h>

long sum[1000001];

int main(void) {
    freopen("12138_sampleIn.txt", "r", stdin);
    int n,q, num, reverse_index = -1;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num);
        if (reverse_index < 0 && num < 0) reverse_index = i;
        sum[i] = sum[i - 1] + num;
    }
//    printf("reserse = %d\n", reverse_index);
    long ans = 0;
    for (int i = 0; i < q; i++) {
        int l, r, m;
        scanf("%d %d %d", &l, &r, &m) ;
        if (reverse_index > 0 && l >= reverse_index) {
            ans = 0;
        } else if (reverse_index > 0 && l + m >= reverse_index) {
            ans = sum[reverse_index - 1] - sum[l - 1];
        } else {
            //這是錯的！！！！！
            //ans = sum[m] - sum[l - 1];
            ans = sum[l + m - 1] - sum[l - 1];
        }
        printf("%ld\n", ans);
    }
    return 0;
}
