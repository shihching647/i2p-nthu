/**
 n(1 <= n <= 10^6)
 q(1 <= q <= 10^5)
 a1 ~ an (0 <= ai <= 10^9)
 -->
 1.合有可能是 10^6 * 10^9 = 10^15 ,所以sum陣列要開long long int
 2.若每次都重新計算al~ar則時間複雜度為O(n*q) = 10^11會TLE (OJ上超過10^8就會TLE) --> 用prefix sum處理
 */
#include <stdio.h>
//#define ONLINE_JUDGE

long long int prefix_sum[1000001]; //main最多只能~x*10^5個, 超過10^6要開在global

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("12125_sampleIn.txt", "r", stdin);
#endif
    int n, q, num;
    scanf("%d %d\n", &n, &q);
    for (int i = 1; i < n + 1; i++) {
        scanf("%d(/`A`)/ ~I__I ", &num); //sacnf可直接讀, 因為a~10^9所以int是夠的(int max~2*10^9)
        prefix_sum[i] = prefix_sum[i - 1] + num;
    }
    int l, r;
    for (int j = 0; j < q; j++) {
        scanf("%d %d", &l, &r);
        printf("%lld\n", prefix_sum[r] - prefix_sum[l - 1]);
    }
    return 0;
}
